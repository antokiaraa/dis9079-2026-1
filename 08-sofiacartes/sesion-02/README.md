# sesion-02

lunes 16 marzo 2026

## Apuntes clase 

- Formamos grupos de trabajos para la entrega n°1, el cual es:
  
Monserrat Paredes [Monserrat-Paredes](https://github.com/Monserrat-Paredes) y Valentina Ruz [vxlentiinaa](https://github.com/vxlentiinaa)

- Después se enseñó cómo utilizar github con Markdown para la documentación de los proyectos y los apuntes del curso. Ya que, es un lenguaje diseñado para escribir, formatear y jerarquizar.
  
```bash
bash sirve para copiar directamente lo que escribo / agregarle un botoncito para copiar y pegar
```

- [Guia de Markdown](https://github.com/adam-p/markdown-here/wiki/markdown-cheatsheet)

### Arduinoo IDE

En la clase nos hicieron descargar el software Arduino IDE, en la versión 2.3.8 <https://www.arduino.cc/en/software/#ide>

Dentro de esta había que descargar estas herramientas:

- Boards Manager -> Arduino Uno R4 Boards (v1.5.3 o más reciente)
- Library Manager -> ArduinoMQTTClient (v0.1.8 o más reciente)
- Library Manager -> ArduinoGraphics (v1.1.4 o más reciente)

**Recordatorio**

- Void: vacío
- Loop: repetir
- Setup: se configura
- Todo lo que escribimos en Arduino es en lenguaje c++
- MQTT: los arduino se conectaran a traves de mosquitto y se enviaran cosas desde mosquitto [Mosquitto](https://mosquitto.org/) 

[Homebrew](https://brew.sh/)

#### Ejemplos vistos en clases

**Ejemplo 01**

- Código para escribir textos en la pantalla de Arduino

- 
```cpp
// ejemplo01
// imprime la sigla del curso en la pantalla led
// de la Arduino Uno R4 WiFi
// basado en
// https://docs.arduino.cc/tutorials/uno-r4-wifi/led-matrix/#scrolling-text-example
// marzo 2026
// por montoyamoraga para disenoUDP

// incluir bibliotecas
#include <ArduinoGraphics.h>
#include "Arduino_LED_Matrix.h"

// declarar instancia de ArduinoLEDMatrix
// con nombre pantalla
ArduinoLEDMatrix pantalla;

void setup() {

  // iniciar puerto serial
  Serial.begin(115200);

  // inicializar pantalla
  pantalla.begin();

}

void loop() {

  // definir nuevo dibujo
  pantalla.beginDraw();

  // definir trazo
  pantalla.stroke(0xFFFFFFFF);

  // definir velocidad de deslizamiento
  pantalla.textScrollSpeed(100);

  // definir texto
  const char texto[] = "    diseno udp dis9704 interacciones inalambricas    ";
  
  // definir tipo
  pantalla.textFont(Font_5x7);

  // definir inicio del texto
  pantalla.beginText(0, 1, 0xFFFFFF);

  // imprimir el texto
  pantalla.println(texto);

  // deslizar hacia la izquierda
  pantalla.endText(SCROLL_LEFT);

  // fin del dibujo
  pantalla.endDraw();
}
```

---

## Ejemplo 02-recibir

Biblioteca: ArduinoMqttClient.h

Haremos cambios en Mqtt

- Este código sirve para que el Arduino que recibe, reciba un mensaje.
- Debemos tomar esta base de intercomunicación y hacer que funcionen entre sí.

---

- `const char birker[] = "ip"` es capaz de encontrar donde está mosquitto

```cpp
const char broker[] = "10.174.124.28";
int port = 1883;
const char topic[] = "asistencia/20260316";
```

## Código Recibir

`arduino_secrets.h`

```cpp
#define SECRET_SSID "pixel9"
#define SECRET_PASS "mateo123"
```

`ejemplo02Recibir.ino`

```cpp
// ejemplo02Recibir
// placa se conecta a un servidor mosquitto
// y recibe mensajes del topic asistencia/20260316
// basado en ejemplo de la biblioteca
// ArduinoMqttClient - WiFi Simple Receive
// marzo 2026
// por montoyamoraga para disenoUDP


/*
  ArduinoMqttClient - WiFi Simple Sender

  This example connects to a MQTT broker and publishes a message to
  a topic once a second.
*/

// importar bibliotecas
#include <ArduinoMqttClient.h>
#include <WiFiS3.h>

// importar archivo .h con claves
#include "arduino_secrets.h"

char ssid[] = SECRET_SSID;
char pass[] = SECRET_PASS;

WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);

const char broker[] = "10.174.124.28";
int port = 1883;
const char topic[] = "asistencia/20260316";

const long intervalo = 10000;
unsigned long previousMillis = 0;

int count = 0;

void setup() {
  // inicializar el puerto serial
  Serial.begin(9600);
  // si no se ha inicializado, esperar
  while (!Serial) {
    ;
  }

  // conectarse a wifi
  Serial.print("conectandose a red ");
  Serial.println(ssid);

  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    // si falla, reintentar
    Serial.print(".");
    delay(5000);
  }

  Serial.println("te conectaste a la red!");

  // ID del cliente
  // cada cliente debe tener una ID unica
  mqttClient.setId("montoyamoraga");

  // autenticacion con username y clave
  mqttClient.setUsernamePassword("montoyamoraga", "dis9079");

  Serial.print("tratando de conectarse al MQTT broker ");
  Serial.println(broker);

  if (!mqttClient.connect(broker, port)) {
    Serial.print("conexion a MQTT fallida! codigo del error = ");
    Serial.println(mqttClient.connectError());

    while (1)
      ;
  }

  Serial.println("te conectaste al MQTT broker!");
  Serial.println();

  Serial.print("subscribiendose al topic: ");
  Serial.println(topic);
  Serial.println();

  // subscribe to a topic
  mqttClient.subscribe(topic);

  // topics can be unsubscribed using:
  // mqttClient.unsubscribe(topic);

  Serial.print("esperando mensajes en el topic: ");
  Serial.println(topic);
  Serial.println();
}


void loop() {
  int messageSize = mqttClient.parseMessage();
  if (messageSize) {
    // we received a message, print out the topic and contents
    Serial.print("recibi un mensaje con el topic '");
    Serial.print(mqttClient.messageTopic());
    Serial.print("', length ");
    Serial.print(messageSize);
    Serial.println(" bytes:");

    // use the Stream interface to print the contents
    while (mqttClient.available()) {
      Serial.print((char)mqttClient.read());
    }
    Serial.println();

    Serial.println();
  }
}
```

##### Páginas vistas en clases:

- [pandoc](https://pandoc.org/)
- [oshwa](https://oshwa.org/)
- [semver](https://semver.org/lang/es/)
- [CodeVisualStudio](https://code.visualstudio.com/)
