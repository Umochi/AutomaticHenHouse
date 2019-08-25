<h1 style="color: #5e9ca0;">#AutomaticHenHouse</h1>
<h2 style="color: #2e6c80;">Progetto per automazione della porta di un pollaio.</h2>
<p>L'hardware che si occupa dell'apertura e chiusura della porta &egrave; costituito da una scheda Arduino Uno, collegata alla rete tramite un ethernet-shield.</p>
<p><img src="https://raw.githubusercontent.com/Umochi/AutomaticHenHouse/master/images/arduino_uno_main_board.jpg" alt="" width="200" height="200" /><img src="https://raw.githubusercontent.com/Umochi/AutomaticHenHouse/master/images/ethernet-shield.jpg" alt="Ethernet-Shield" width="200" /></p>
<hr />
<p>Il motore che esegue l'apertura della porta tramite una barra filettata &egrave; un semplice motore a 12v che monta un mandrino.</p>
<p>&nbsp;</p>
<p><img src="https://raw.githubusercontent.com/Umochi/AutomaticHenHouse/master/images/IMG_4039.JPG" alt="" width="300" height="225" /><img  src="https://raw.githubusercontent.com/Umochi/AutomaticHenHouse/master/images/IMG_4037.JPG" alt="" width="300" height="225" /></p>
<p><img  src="https://raw.githubusercontent.com/Umochi/AutomaticHenHouse/master/images/IMG_4036.JPG" alt="" width="300" height="225" /></p>
<p>&nbsp;</p>
<p>&nbsp;</p>
<hr />
<p>Per interfacciarsi con il motore &egrave; stato utilizzato un diver lmd18200, ma potevano essere utilizzati anche 4 semplici relais. L'utilizzo di questo diver permette di comandare oltre alla direzione e all'attivit&agrave; del motore anche il voltaggio in uscita per regolare la velocit&agrave; di salita e discesa.</p>
<p>Due semplici bottoni (PCB&nbsp; Switch) costituiscono il fine corsa per lo sportello in apertura e chiusura. Altri due bottoni dello stesso tipo costituiscono una tastiera aggiuntiva per forzare la chiusura e l'apertura senza dover utilizzare l'interfaccia web service.</p>
<p>L'interfaccia grafica e la gestione dell'automatizzazione della chiusura e apertura sono costituite da un applicazione Node-Red.</p>
<p>La libreria: node-red-contrib-sun-position fornisce le funzionait&agrave; di schedulazioni con l'evento di alba e tramonto, relativo alla zona impostata.</p>
<p>La libreia node-red-dashboard fornisce invece i nodi necessari alla creazione dell'interfaccia grafica.</p>
