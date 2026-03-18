# sesion-02

lunes 16 marzo 2026

Grupo: Benjamin Alvarez, Anays Cornejo.

# Arduino UNO R4 – Apuntes

## Instalación
Para usar Arduino, primero hay que descargar **Arduino IDE** y elegir la versión según el computador. Luego, dentro del programa, se debe instalar la placa **Arduino UNO R4** en **Boards Manager** y agregar bibliotecas como **MQTT** en **Library Manager**.  

El **Arduino UNO R4 WiFi** permite enviar datos o mensajes por **WiFi**, mostrar palabras en la **pantalla LED** o comunicarse con **otro Arduino conectado a la misma red**.

---

## Apuntes

- El código de **Arduino** se convierte en **0 y 1**.  
- Esto permite que la **placa entienda y ejecute el programa**.

---

## Código

- `setup()` → se ejecuta **una vez** al iniciar.  
- `loop()` → se **repite infinitamente**.

---

## MQTT

- Protocolo **ligero** para enviar mensajes entre dispositivos.  
- Funciona sobre **WiFi / TCP-IP**.

---

## Mosquitto

- **Broker (intermediario)** de MQTT.  
- **Recibe y distribuye mensajes** entre dispositivos.  
- **Puerto:** 1883.  
- En **Mac** se instala con **Homebrew** usando **Terminal**.
