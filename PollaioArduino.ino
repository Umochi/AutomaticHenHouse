#include <Ethernet.h>

const byte mac[] = { 0xAA, 0xAA, 0xBE, 0xDF, 0xDE, 0xAB };
const IPAddress ipMio(192, 168, 1, 52);
EthernetServer server(80);

String statoMotore = "Spento";
String comandoMotore = "Nulla";

const int potenzaMotoreZero = 0;
int potenzaMotore = 100;
const int potenzaMotoreMax = 255;

const int DIN_PULSANTE_CHIUSURA = 3;
const int DIN_PULSANTE_APERTURA= 4;

const int DIN_MOTORE_PWD= 5;
const int DIN_MOTORE_DIREZIONE= 6;
const int DIN_MOTORE_STOP= 7;

const int DIN_SENSORE_CHIUSO= 8;
const int DIN_SENSORE_APERTO= 9;


void setup()
{
  //Serial.begin(9600);
  //Serial.print("setup() START");
  
  pinMode(DIN_PULSANTE_CHIUSURA, INPUT);//pulsante chiusura
  pinMode(DIN_PULSANTE_APERTURA, INPUT);//pulsante apertura
  delay(100);
  
  pinMode(DIN_MOTORE_PWD, OUTPUT);//driver motore pwr
  analogWrite(DIN_MOTORE_PWD, 0);
  delay(100);
  
  pinMode(DIN_MOTORE_DIREZIONE, OUTPUT);//driver motore direzione
  digitalWrite(DIN_MOTORE_DIREZIONE, LOW);
  delay(100);
  
  pinMode(DIN_MOTORE_STOP, OUTPUT);//driver motore stop
  digitalWrite(DIN_MOTORE_STOP, HIGH);
  delay(100);
  
  pinMode(DIN_SENSORE_CHIUSO, INPUT);//sensore chiuso
  pinMode(9, INPUT);//sensore aperto

  Ethernet.begin(mac, ipMio);
  delay(100);
  //Serial.print("setup() Connecting...");
  
  if (Ethernet.hardwareStatus() == EthernetNoHardware) {
    //Serial.print("setup() Ethernet shield non trovata.");
  }
  if (Ethernet.linkStatus() == LinkOFF) {
    //Serial.print("setup() Ethernet cavo non connesso.");
  }

  server.begin();
  //Serial.print("setup() server indirizzo: ");
  //Serial.println(Ethernet.localIP());
  //Serial.println("setup() end");
  //Serial.println();
  delay(100);
}


void loop() {
  
  //Serial.println("loop() start");
  //---------------------- Parte WEB-------------------------------
  EthernetClient client = server.available();
  if (client) {
    //Serial.println("loop() if client. char:");
    String messaggio = "";
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        if (messaggio.length()<100){
          messaggio.concat(c);
        }
        //Serial.print(c);
        if (c == '\n' && currentLineIsBlank) {
          
          if(messaggio.indexOf("Apri") > 0){
            
            comandoMotore = "Apri";
          }
          else if(messaggio.indexOf("Chiudi") > 0){
            
            comandoMotore = "Chiudi";
          }
          else if(messaggio.indexOf("Stop") > 0){
            
            motorStop();
            comandoMotore = "Nulla";
          }
          else if(messaggio.indexOf("PotenzaMotore=50") > 0){
              
            potenzaMotore = 50;
          }
          else if(messaggio.indexOf("PotenzaMotore=75") > 0){
            
            potenzaMotore = 75;
          }
          else if(messaggio.indexOf("PotenzaMotore=150") > 0){
            
            potenzaMotore = 150;
          }
          else if(messaggio.indexOf("PotenzaMotore=255") > 0){
            
            potenzaMotore = 255;
          }
          else if(messaggio.indexOf("PotenzaMotore") > 0){
            
            potenzaMotore = 100;
          }
          
          generaMessaggio(client);
          break;
        }
        if (c == '\n') {
          
          currentLineIsBlank = true;
        } 
        else if (c != '\r') {
          
          currentLineIsBlank = false;
        }
      }
    }
    //Serial.println();
    client.stop();
    //Serial.println("client disconnected");
  }
  else{
    //--------------------------Bottoni-----------------------------
    if (digitalRead(DIN_PULSANTE_CHIUSURA) == HIGH){
      
      //Serial.println("loop() bottone giu");
      comandoMotore = "Chiudi";
    }
    if (digitalRead(DIN_PULSANTE_APERTURA) == HIGH){
      
      //Serial.println("loop() bottone su");
      comandoMotore = "Apri";
    }
    
    //--------------------------Esecuzione--------------------------
    //Serial.print("loop() comandoMotore:");
    //Serial.println(comandoMotore);
    //Serial.print("loop() statoMotore:");
    //Serial.println(statoMotore);
    //Serial.print("loop() sensore chiuso:");
    //Serial.println(digitalRead(8));
    //Serial.print("loop() sensore aperto:");
    //Serial.println(digitalRead(9));
    if (comandoMotore.compareTo("Chiudi") == 0 && digitalRead(DIN_SENSORE_CHIUSO) == LOW ){
      
      motorGiu();
    }
    else if (comandoMotore.compareTo("Apri") == 0 && digitalRead(DIN_SENSORE_APERTO) == LOW ){
      
      motorSu();
    }
    if (statoMotore.compareTo("Discesa") == 0 && digitalRead(DIN_SENSORE_CHIUSO) == HIGH ){
      
      motorStop();
    }
    else if (statoMotore.compareTo("Salita") == 0 && digitalRead(DIN_SENSORE_APERTO) == HIGH ){
      
      motorStop();
    }
    
    //--------------------------Fine loop--------------------------
    //Serial.println("loop() end");
    if(comandoMotore.compareTo("Nulla") == 0){
      
      delay(500);
    }
    comandoMotore = "Nulla";
    //Serial.println();
  }
}

void motorSu (){
  
  statoMotore = "Salita";
  analogWrite(DIN_MOTORE_PWD,potenzaMotoreMax);
  digitalWrite(DIN_MOTORE_DIREZIONE,HIGH);
  digitalWrite(DIN_MOTORE_STOP,LOW);
  delay(1000);
  analogWrite(DIN_MOTORE_PWD,potenzaMotore);
}
void motorGiu (){
  
  statoMotore = "Discesa";
  analogWrite(DIN_MOTORE_PWD,potenzaMotoreMax);
  digitalWrite(DIN_MOTORE_DIREZIONE,LOW);
  digitalWrite(DIN_MOTORE_STOP,LOW);
  delay(1000);
  analogWrite(DIN_MOTORE_PWD,potenzaMotore);
}
void motorStop(){
  
  analogWrite(DIN_MOTORE_PWD, potenzaMotoreZero);
  digitalWrite(DIN_MOTORE_DIREZIONE, LOW);
  digitalWrite(DIN_MOTORE_STOP, HIGH);
  statoMotore = "Spento";
}


void generaMessaggio(EthernetClient client) {
  
  //Serial.println("generaMessaggio()");
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/json");
  client.println("Connection: close");
  client.println();
  
  client.print("{");
  
  client.print("\"sensorChiuso\":\"");
  int sensorChiuso = digitalRead(DIN_SENSORE_CHIUSO);
  client.print(sensorChiuso);
  client.print("\",");
  
  client.print("\"sensorAperto\":\"");
  int sensorAperto = digitalRead(DIN_SENSORE_APERTO);
  client.print(sensorAperto);
  client.print("\",");
  
  client.print("\"statoMotore\":\"");
  client.print(statoMotore);
  client.print("\"");
  
  client.print("}");
}
