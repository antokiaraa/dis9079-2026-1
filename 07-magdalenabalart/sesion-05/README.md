# sesion-05

lunes 06 abril 2026

# Idea general
En esta sesión vimos Adafruit IO como una forma simple de conectar hardware con internet y visualizar datos sin tener que construir toda la infraestructura desde cero. La lógica principal es que un dispositivo manda datos, Adafruit IO los recibe en la nube, y luego esos datos se pueden ver o usar desde un panel visual.

### Qué es Adafruit

Adafruit es una empresa y comunidad enfocada en electrónica DIY, aprendizaje y creación de proyectos con placas, sensores y componentes. Fue fundada en 2005 por la ingeniera del MIT Limor “Ladyada” Fried, con la idea de ser un muy buen lugar para aprender electrónica y ofrecer productos bien diseñados para personas de distintos niveles de experiencia.

### Qué es Adafruit IO

Adafruit IO es la plataforma en la nube de Adafruit para proyectos de IoT. Permite conectar dispositivos, enviar y recibir datos, guardarlos y luego interactuar con ellos desde internet. Adafruit la presenta como una plataforma pensada para mostrar, responder e interactuar con los datos de un proyecto de forma accesible.

### Feed

El feed es una de las partes más importantes del sistema. En Adafruit IO, los feeds son el núcleo: ahí se guarda la información que envía un proyecto, junto con ciertos metadatos. En otras palabras, un feed funciona como el canal o contenedor de una variable. Por ejemplo, si un sensor de pulso manda valores BPM, esos datos podrían ir a un feed llamado pulsometro.

**el Arduino detecta algo, toma ese valor y lo manda a internet;
Adafruit IO lo recibe y lo guarda en un feed;
después el dashboard lee ese feed y muestra lo que está pasando.**

### Dashboard

El dashboard es la parte visual. Adafruit lo describe como una página web editable a la que se le pueden agregar bloques o widgets. Esos bloques pueden mostrar o controlar información del proyecto. Por eso el dashboard funciona como una interfaz para observar lo que entra a los feeds o para interactuar con ellos.

**Dentro de un dashboard se pueden usar bloques como:
gráficos
botones
medidores
indicadores
sliders**

Arduino = quien detecta o manda el dato 
Adafruit IO = la nube que lo recibe y guarda 
Feed = el canal donde queda guardado ese dato 
Dashboard = la pantalla donde se ve 

**Ejemplo:**

**el sensor de pulso detecta un latido 
el Arduino manda ese valor  
Adafruit IO lo guarda en un feed  
el dashboard toma ese feed y lo muestra en tiempo real  
Relación con MQTT** 

Adafruit IO puede trabajar con MQTT, que es uno de los protocolos que soporta para publicar y suscribirse a feeds. En su documentación, Adafruit explica que por MQTT se puede publicar un valor a un feed o suscribirse a un feed para recibir actualizaciones.

**archivo principal .ino: hace funcionar el sensor, manda datos y contiene la lógica del proyecto  
archivo config.h: guarda usuario, claves, nombre de red Wi-Fi y otros datos de conexión**

## codigo visto:

```
#include <WiFiS3.h>
#include "AdafruitIO_WiFi.h"

#define WIFI_SSID ""
#define WIFI_PASS ""

#define IO_USERNAME  ""
#define IO_KEY       ""

AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);
AdafruitIO_Feed *brillo = io.feed("nicolasvaldesgreve-potenciometro");

int potPin = A0;

void setup() {
  Serial.begin(9600);
  io.connect();

  while(io.status() < AIO_CONNECTED) {
    delay(500);
  }
}

void loop() {
  io.run();

  int valor = analogRead(potPin);
  int valorMap = map(valor, 0, 1023, 0, 100);

  brillo->save(valorMap);

  delay(1000);
}
```


## Código de contador visto en clases

En clases vimos un ejemplo base para entender cómo conectar Arduino con Adafruit IO y publicar datos de forma simple. Antes de trabajar con sensores, usamos un contador que iba aumentando y enviando ese valor a un feed.

Este ejercicio fue importante porque permitió comprobar que:

la conexión a Wi-Fi estaba funcionando
la conexión con Adafruit IO también
el feed recibía datos correctamente
el dashboard podía mostrar información en tiempo real 

Qué hacía este código
usa config.h para guardar la configuración
crea una variable contador
define un feed llamado grupoXX
se conecta a Adafruit IO
en cada vuelta del loop() manda el valor del contador
después aumenta ese valor
espera 3 segundos para no enviar datos demasiado rápido  

```
 // Adafruit IO Publish Example
//
// Adafruit invests time and resources providing this open source code.
// Please support Adafruit and open source hardware by purchasing
// products from Adafruit!
//
// Written by Todd Treece for Adafruit Industries
// Copyright (c) 2016 Adafruit Industries
// Licensed under the MIT license.
//
// All text above must be included in any redistribution.

// ejemplo para enviar / publish
// por montoyamoraga
// para disenoUDP
// basado en
// Adafruit IO Publish Example

// incluir archivo config.h
// hacer las modificaciones de este archivo
// NO subir a github
#include "config.h"

// esta variable entera
// sera un contador que aumenta
// durante el funcionamiento del software
int contador = 0;

// definir una variable que se llame nombreFeed
// que tenga un cierto valor
// mantener las doble comillas, cambiar grupoXX segun tu nombre de grupo
AdafruitIO_Feed *nombreFeed = io.feed("grupoXX");

void setup()
{

  // prender la conexion serial
  // ojo con la velocidad de 115200 baud
  // cuando abras el monitor serial debes configurarlo
  // a este numero, porque el standard de fabrica es 9600 baud
  Serial.begin(115200);

  // estas lineas pausan el codigo
  // hasta que prendas el monitor serial
  // la lupita arriba a la derecha en Arduino IDE
  while (!Serial)
    ;

  // imprimir en consola
  Serial.print("conectando a Adafruit IO");

  // conectarse a io.adafruit.com
  io.connect();

  // esperar la conexion
  while (io.status() < AIO_CONNECTED)
  {
    // imprimir un punto cada medio segundo
    // mientras se conecta
    Serial.print(".");
    delay(500);
  }

  // demostrar que logramos conexion
  Serial.println();
  Serial.println(io.statusText());
}

void loop()
{

  // esta linea es necesaria
  // al principio de loop()
  // para mantener la conexion
  // y procesar datos que lleguen
  io.run();

  // enviar el contador a Adafruit IO
  // primero mostrar en monitor serial
  Serial.println("enviando -> " + String(contador));
  // despues enviar a la nube
  nombreFeed->save(contador);

  // incrementar el contador en 1
  contador = contador + 1;

  // Adafruit IO tiene una velocidad limitada
  // de escritura / publishing
  // usamos delay para pausar el codigo 3 segundos
  delay(3000);
}
```

**Idea importante del ejemplo**

Este contador sirvió como una prueba básica de publicación. En vez de mandar un dato desde un sensor, el Arduino generaba su propia información y la subía a la nube. Eso ayudó a entender mejor la estructura completa del sistema:

**Arduino → feed en Adafruit IO → dashboard**

También dejó claro por qué io.run(); es necesaria dentro de loop(): mantiene viva la conexión con Adafruit IO mientras el programa sigue funcionando.










