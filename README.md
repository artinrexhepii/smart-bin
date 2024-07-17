# Smart Bin

## Përshkrimi
"Smart Bin" synon të adresojë çështjet mjedisore të shkaktuara nga kontenierët e mbeturinave të mbushura në zonat urbane. Zgjidhja jonë përdor teknologjinë IoT për të monitoruar nivelet e mbushjes së kontenierëve të mbeturinave dhe për të raportuar këto të dhëna në një platformë qendrore të softuerit. Ky sistem ndihmon në optimizimin e orareve të mbledhjes së mbeturinave, redukton incidentet e mbingarkesës dhe përmirëson pastërtinë dhe standardet e shëndetit në qytete.

## Karakteristika
- **Monitorim Dinamik**: Përdor një sensor ultrasonik për të matur nivelet e mbushjes së kontenierëve dhe një sensor PIR për të aktivizuar matjet bazuar në zbulimin e lëvizjes.
- **Transmetim Efikas i të Dhënave**: Përdor mikrocontrollerin ESP8266 për transmetimin me valë të të dhënave.
- **Perdorimi**: I projektuar për të zbatuar nëpër komuna të ndryshme në Ballkanin Perëndimor.

## Paisjet e nevojshme
- Sensor Ultransonik
- Sensor PIR
- Mikrocontroller ESP8266

## Si Funksionon
1. Sensori PIR zbulon lëvizjen pranë kontenierit.
2. 30 sekonda pas zbulimit të lëvizjes, sensori ultrasonik mat nivelin e mbushjes së kontenierit.
3. Mikrocontrolleri ESP8266 dërgon të dhënat e mbledhura me valë në platformën qendrore të softuerit.

## Kodi
Kodi i konfigurimit për mikrocontrollerin me sensorët, si dhe kodi për transmetimin e të dhënave, është i disponueshëm si open source. Mund ta gjeni kodin e plotë në file `bin_sensor.ino`.

## Përmbajtja 
- `bin_sensor.ino`: Kodi i konfigurimit dhe transmetimit të të dhënave për projektin Smart Bin.
- `Smart_Bin_Report.docx`: Raporti përfundimtar i detajuar i projektit.

## Si të Përdorni
1. Lidhni sensorin ultrasonik, sensorin PIR dhe mikrocontrollerin ESP8266.
2. Ngarkoni kodin `bin_sensor.ino` në mikrocontrollerin ESP8266.
3. Monitoroni transmetimin e të dhënave dhe rregulloni cilësimet e sistemit sipas nevojës.

## Falenderime
Ne shprehim mirënjohjen tonë ndaj Free Libre Open Source Software Kosova dhe IPKO Telecommunications për mbështetjen dhe financimin e tyre përmes IoT for Green Transition Hackathon.

## Licenca
Të drejtat autoriale i takojnë ekipit tonë, ndërsa kodi është i hapur për përdorim.


## Kontakti
Për çdo pyetje ose informacione të mëtejshme, ju lutem kontaktoni:
- Artin Rexhepi: artinrexhepi03@gmail.com
- Daris Dragusha: darisdragusha@gmail.com
- Art Jashari: artjashari300@gmail.com
