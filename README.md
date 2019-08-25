<h1>#AutomaticHenHouse</h1>
<h2>Progetto per automazione della porta di un pollaio.</h2>
<p>L'hardware che si occupa dell'apertura e chiusura della porta &egrave; costituito da una scheda <strong>Arduino Uno</strong>, collegata alla rete tramite un <strong>ethernet-shield</strong>.</p>
<p><img src="https://raw.githubusercontent.com/Umochi/AutomaticHenHouse/master/images/arduino_uno_main_board.jpg" alt="" width="200" height="200" /><img src="https://raw.githubusercontent.com/Umochi/AutomaticHenHouse/master/images/ethernet-shield.jpg" alt="Ethernet-Shield" width="200" /></p>
<hr />
<p>Il motore che esegue l'apertura della porta tramite una barra filettata &egrave; un semplice motore a 12v che monta un mandrino.</p>
<p><img src="https://raw.githubusercontent.com/Umochi/AutomaticHenHouse/master/images/IMG_4037.JPG" alt="" width="290" height="435" />&nbsp;&nbsp; <img src="https://raw.githubusercontent.com/Umochi/AutomaticHenHouse/master/images/IMG_4039.JPG" alt="" width="290" height="435" /><img src="https://raw.githubusercontent.com/Umochi/AutomaticHenHouse/master/images/IMG_4036.JPG" alt="" width="592" height="816" /></p>
<hr />
<p>Per interfacciarsi con il motore &egrave; stato utilizzato un <strong>diver lmd18200</strong>, ma potevano essere utilizzati anche 4 semplici relais. L'utilizzo di questo diver permette di comandare oltre alla direzione e all'attivit&agrave; del motore anche il voltaggio in uscita per regolare la velocit&agrave; di salita e discesa.</p>
<p><img src="https://raw.githubusercontent.com/Umochi/AutomaticHenHouse/master/images/IMG_4026.JPG" alt="" width="286" height="235" />&nbsp;&nbsp; <img src="https://raw.githubusercontent.com/Umochi/AutomaticHenHouse/master/images/IMG_4034.JPG" alt="" width="200" height="235" /></p>
<hr />
<p>Due semplici bottoni (PCB Switch) costituiscono il fine corsa per lo sportello in apertura e chiusura. Altri due bottoni dello stesso tipo costituiscono una tastiera aggiuntiva per forzare la chiusura e l'apertura senza dover utilizzare l'interfaccia web service.</p>
<p><img src="https://raw.githubusercontent.com/Umochi/AutomaticHenHouse/master/images/Push-Button.jpg" width="230" height="230" />&nbsp;&nbsp; <img src="https://raw.githubusercontent.com/Umochi/AutomaticHenHouse/master/images/IMG_4038.JPG" alt="" width="260" height="301" /></p>
<hr />
<p>L'interfaccia grafica e la gestione dell'automatizzazione della chiusura e apertura sono costituite da un applicazione <strong>Node-Red</strong>. In particolare la libreria <strong>node-red-dashboard</strong> fornisce i nodi necessari alla creazione dell'interfaccia grafica.</p>
<p>&nbsp;</p>
<p>&nbsp;<img src="https://raw.githubusercontent.com/Umochi/AutomaticHenHouse/master/images/IMG_4054.PNG" alt="" width="200" height="356" />&nbsp;&nbsp; <img src="https://raw.githubusercontent.com/Umochi/AutomaticHenHouse/master/images/IMG_4055.PNG" alt="" width="200" height="356" />&nbsp;&nbsp; <img src="https://raw.githubusercontent.com/Umochi/AutomaticHenHouse/master/images/IMG_4056.PNG" alt="" width="200" height="356" /></p>
<hr />
<p>La libreria: <strong>node-red-contrib-sun-position</strong> fornisce le funzionait&agrave; di schedulazioni con l'evento di alba e tramonto, relativo alla zona impostata.</p>
<p><img src="https://raw.githubusercontent.com/Umochi/AutomaticHenHouse/master/images/SchermataNodeRed.jpg" alt="" width="600" height="237" /></p>
<hr />
