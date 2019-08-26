<h1>#AutomaticHenHouse</h1>
<h2>Progetto per automazione della porta di un pollaio.</h2>
<p>L'hardware che si occupa dell'apertura e chiusura della porta &egrave; costituito da una scheda <strong>Arduino Uno</strong>, collegata alla rete tramite <strong>Ethernet-Shield</strong>.</p>
<p><img src="https://raw.githubusercontent.com/Umochi/AutomaticHenHouse/master/images/arduino_uno_main_board.jpg" alt="" width="200" height="200" /><img src="https://raw.githubusercontent.com/Umochi/AutomaticHenHouse/master/images/ethernet-shield.jpg" alt="Ethernet-Shield" width="200" />&nbsp; <img src="https://raw.githubusercontent.com/Umochi/AutomaticHenHouse/master/images/Schema.jpg" alt="" width="416" height="190" /></p>
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
<h3>Il comportamento del sistema &egrave; il seguente:</h3>
<ul>
<li>Arduino esegue il loop, nel quale controlla se sono presenti invocazioni sul servizio web esposto o pressione dei tasti.</li>
<li>Il servizio web, restituisce un <strong>json</strong> che riporta lo stato dei sensori di apertura e chiura e l'attivit&agrave; del motore.</li>
<li>Inoltre vengono recuperati i comandi inviati come url parameters, questi possono essere il comando di <strong>Chiusura</strong>, <strong>Apertura</strong> e di <strong>Stop</strong>. Ogni parametro non previsto verr&agrave; ignorato.</li>
<li>Il comando di <strong>Stop</strong> non viene per&ograve; utilizzato all'interno della user interface esposta.</li>
<li>Viene anche data possibilit&agrave; di tarare l'energia utilizzata dal mototore in caso di necessit&agrave;. <strong>L'attivazione del motore viene eseguita al 100% del voltaggio disponibile</strong>, e viene ridotta al 50% dopo un secondo.</li>
<li>L'intera operazione di <strong>Apertura</strong>/<strong>Chiusura</strong> dura all'incirca 4 secondi.</li>
<li><strong>La riduzione di potenza &egrave; importate, non solo per ridurre la velocit&agrave; e la possibil&agrave; di incidenti, ma per ridurre l'inerzia sul fine corsa, e la possibilit&agrave; di bloccare il meccanismo e non avare uno spunto sufficiente a avviare l'operazione successiva. </strong></li>
<li>Alcuni ritardi condizionati nel ciclo sono stati introdotti per non sovracaricare Arduino.</li>
<li>Il <strong>Flow</strong> creato in <strong>Node-Red</strong> si occupa di generare l'interfaccia grafica, e attivare le schedulazioni.</li>
<li>La user interface mostra lo stato della porta, <strong>Chiusa</strong>, <strong>Aperta</strong> o in <strong>Stato Intermedio</strong> e lo stato di attivit&agrave; del motore.</li>
<li>Viene poi data lo possibilit&agrave; di attivare o disattivare l'esecuzione automatica.</li>
<li>Due bottoni invece rendono possibile forzare <strong>Chiusura</strong> e <strong>Apertura</strong>.</li>
<li>Quando lo switch &egrave; impostato su <strong>Automatico</strong>, la schedulazione condizionata dalla posizione del sole nello stato di <strong>"Alba"</strong> e <strong>"Fine Tramonto"</strong> scatenano le operazioni di apertura e chiusura.</li>
</ul>
