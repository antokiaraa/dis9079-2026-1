# sesion-02

lunes 16 marzo 2026

## Apuntes en clases
Grupo para solemne: Martina Alegría, Antonella Lavalle, Catalina Salinas

Durante la clase se introdujo el uso de GitHub como plataforma para documentar proyectos y registrar apuntes. Para esto se utiliza Markdown, un lenguaje de escritura que permite estructurar, formatear y jerarquizar contenido de manera clara

Markdown facilita la integración de texto, código y enlaces en un mismo documento

## Arduino IDE

+ Para comenzar, se debe instalar el Arduino IDE luego dentro del programa es necesario agregar el soporte para la placa Arduino Uno R4 WiFi y algunas bibliotecas como ArduinoMQTTClient y ArduinoGraphics. Esto permite programar la placa, trabajar con la pantalla LED y establecer comunicación mediante MQTT

+ La estructura básica

setup: se ejecuta una vez al iniciar, para configuraciones iniciales
loop: se ejecuta de forma continua
void: función sin retorno
setup: configuración
loop: repetición constante

## Comunicación con MQTT

Se introdujo el protocolo MQTT para la comunicación entre dispositivos mediante un broker como Mosquitto, que opera en el puerto 1883

Su funcionamiento se basa en:

+ publicación de mensajes en un topic
+ suscripción de otros dispositivos a ese mismo topic

## Ejemplos en clases

Para la pantalla del Arduino

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
