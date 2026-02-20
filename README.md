# Smart-Solar
Un solar inteligent cu elemente de "smart gardening" care se trimit direct pe telofon.
---
## Hardware
 - ESP32(E-WROOM-32)
 - DHT22
 - HW-080

## Transmiterea informatiilor

Transmiterea informatiilor se face pe baza platformei **ArduinoCloud**, prin urmare placuta ESP32 trebuie sa aiba o conectivitatea continua la internet pentru a putea transminte informatii primite de la senzori in timp real.
Codul publicat mai sus este cel specific introdus in "things-ul" din arduino cloud, insa nu contine date precum: initializarea variabilelor Cloud, Netul, Parola netului, etc
