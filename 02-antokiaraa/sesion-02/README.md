# sesion-02

lunes 16 marzo 2026

hacer grupos de a 3 para la solemne 1 

Grupo:

- Antonella Aguilar
- Tomás Catrileo
- Angel Sabogal

## apuntes clase

- Instalar Arduino IDE
- Instalar biblioteca ArduinoMQTTClient
- Visual studio code (opcional) 
- Utilizaremos Arduino Uno R4 WIFI

usaremos la palabra Arduino para referirnos a 3 cosas:

1. la placa: microcontrolador Arduino Uno R4 WiFi.
2. el software Arduino IDE, donde se escribe el código que se envía a la placa
3. el lenguaje de programación, un dialecto del lenguaje C++, con funciones y bibliotecas diseñadas para facilitar la programación.


### Estructura de un codigo de arduino

```cpp
void setup() {

}

void loop() {

}
```
### Ejemplo usado en clase para la pantalla que incluye el Arduino

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

void setup()
{

  // iniciar puerto serial
  Serial.begin(115200);

  // inicializar pantalla
  pantalla.begin();
}

void loop()
{

  // definir nuevo dibujo
  pantalla.beginDraw();

  // definir trazo
  pantalla.stroke(0xFFFFFFFF);

  // definir velocidad de deslizamiento
  pantalla.textScrollSpeed(100);

  // definir texto
  const char texto[] = "    diseno udp dis9079 interacciones inalambricas    ";

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
Mosquitto

- Es un "broker" intermediario de MQTT
- En puerto 1883
- Puede ecibr y enviar mensajes entre dispositivos




