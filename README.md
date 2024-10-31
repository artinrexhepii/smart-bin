# SmartBin

## Përshkrimi / Description
"Smart Bin" synon të adresojë çështjet mjedisore të shkaktuara nga kontenierët e mbeturinave të mbushura në zonat urbane. Zgjidhja jonë përdor teknologjinë IoT për të monitoruar nivelet e mbushjes së kontenierëve të mbeturinave dhe për të raportuar këto të dhëna në një platformë qendrore të softuerit. Ky sistem ndihmon në optimizimin e orareve të mbledhjes së mbeturinave, redukton incidentet e mbingarkesës dhe përmirëson pastërtinë dhe standardet e shëndetit në qytete.

"SmartBin" aims to address environmental issues caused by overfilled waste containers in urban areas. Our solution uses IoT technology to monitor the fill levels of waste containers and report this data to a central software platform. This system helps optimize waste collection schedules, reduce overflow incidents, and improve cleanliness and health standards in cities.

## Karakteristika / Features
- **Monitorim Dinamik / Dynamic Monitoring**: Përdor një sensor ultrasonik për të matur nivelet e mbushjes së kontenierëve dhe një sensor PIR për të aktivizuar matjet bazuar në zbulimin e lëvizjes.
  
  Uses an ultrasonic sensor to measure container fill levels and a PIR sensor to trigger measurements based on motion detection.

- **Transmetim Efikas i të Dhënave / Efficient Data Transmission**: Përdor mikrocontrollerin ESP8266 për transmetimin me valë të të dhënave.
  
  Utilizes the ESP8266 microcontroller for wireless data transmission.

- **Përdorimi / Usage**: I projektuar për të zbatuar nëpër komuna të ndryshme në Ballkanin Perëndimor.
  
  Designed for implementation in various municipalities across the Western Balkans.

## Paisjet e nevojshme / Required Devices
- Sensor Ultrasonik / Ultrasonic Sensor
- Sensor PIR / PIR Sensor
- Mikrocontroller ESP8266 / ESP8266 Microcontroller

## Si Funksionon / How It Works
1. Sensori PIR zbulon lëvizjen pranë kontenierit.  
   The PIR sensor detects movement near the container.
2. 30 sekonda pas zbulimit të lëvizjes, sensori ultrasonik mat nivelin e mbushjes së kontenierit.  
   30 seconds after detecting movement, the ultrasonic sensor measures the container's fill level.
3. Mikrocontrolleri ESP8266 dërgon të dhënat e mbledhura me valë në platformën qendrore të softuerit.  
   The ESP8266 microcontroller wirelessly transmits the collected data to the central software platform.

## Kodi / Code
Kodi i konfigurimit për mikrocontrollerin me sensorët, si dhe kodi për transmetimin e të dhënave, është i disponueshëm si open source. Mund ta gjeni kodin e plotë në file `bin_sensor.ino`.

The configuration code for the microcontroller and sensors, as well as the code for data transmission, is available as open source. You can find the full code in the `bin_sensor.ino` file.

## Përmbajtja / Contents
- `bin_sensor.ino`: Kodi i konfigurimit dhe transmetimit të të dhënave për projektin Smart Bin.  
  Code for configuration and data transmission for the Smart Bin project.
- `Smart_Bin_Report.docx`: Raporti përfundimtar i detajuar i projektit.  
  The final detailed report of the project.

## Si të Përdorni / How to Use
1. Lidhni sensorin ultrasonik, sensorin PIR dhe mikrocontrollerin ESP8266.  
   Connect the ultrasonic sensor, PIR sensor, and ESP8266 microcontroller.
2. Ngarkoni kodin `bin_sensor.ino` në mikrocontrollerin ESP8266.  
   Upload the `bin_sensor.ino` code to the ESP8266 microcontroller.
3. Monitoroni transmetimin e të dhënave dhe rregulloni cilësimet e sistemit sipas nevojës.  
   Monitor the data transmission and adjust system settings as needed.

## Falenderime / Acknowledgments
Ne shprehim mirënjohjen tonë ndaj Free Libre Open Source Software Kosova dhe IPKO Telecommunications për mbështetjen dhe financimin e tyre përmes IoT for Green Transition Hackathon.

We express our gratitude to Free Libre Open Source Software Kosova and IPKO Telecommunications for their support and funding through the IoT for Green Transition Hackathon.

## Licenca / License
Të drejtat autoriale i takojnë ekipit tonë, ndërsa kodi është i hapur për përdorim.  
The copyright belongs to our team, while the code is open for use.

## Kontakti / Contact
Për çdo pyetje ose informacione të mëtejshme, ju lutem kontaktoni:
For any questions or further information, please contact:
- Artin Rexhepi: artinrexhepi03@gmail.com
- Daris Dragusha: darisdragusha@gmail.com
- Art Jashari: artjashari300@gmail.com
