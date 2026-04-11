# persona-01

investigaciones individuales

## sobre Adafruit IO

Conceptos básicos de Adafruit IO: Fuentes de datos

1. Adafruit IO: Feeds

Los feeds son el componente central del ecosistema Adafruit IO. Funcionan como el repositorio donde se almacenan y organizan tanto los datos enviados por los dispositivos como sus metadatos asociados.

Conceptos Fundamentales: Datos

Es la información técnica que se desea almacenar. Puede representar objetos físicos o variables lógicas

- Valores de sensores (temperatura, humedad, presión).
- Estados de actuadores (encendido/apagado).
- Variables de control (velocidad de motores).

2. Metadatos

Configuraciones que definen el comportamiento y contexto del feed

- **Privacidad:** Determina si los datos son públicos o privados.
- **Licencia:** Especifica los derechos de uso de los datos almacenados.
- **Descripción:** Información legible por personas para documentar el propósito del feed.

3. Modos de Implementación

La gestión de los feeds depende del método de interacción con la plataforma

`Interacción mediante API (MQTT / REST)`

Para usuarios que desarrollan su propio código, la gestión es manual y granular.

- **Regla:** Se debe crear un feed por cada origen de datos único.
- **Ejemplo:** Un proyecto con un sensor de temperatura y dos de humedad requiere la creación de **tres feeds** distintos.

`Uso con WipperSnapper (No-Code)`

Para usuarios que utilizan la plataforma de configuración sin código, la gestión es automatizada.

- **Funcionamiento:** Los feeds se crean automáticamente al momento de añadir un nuevo componente a la placa desde el panel de control de Adafruit IO.

*información sacada de: <https://learn.adafruit.com/adafruit-io-basics-dashboards>*

### Dashboards

Los paneles de control son la interfaz visual de Adafruit IO que permite visualizar datos y controlar dispositivos en tiempo real.

`Proceso de Creación`

Pasos a seguir:

1.  **Acceso:** Inicia sesión en [io.adafruit.com](https://io.adafruit.com) y selecciona el enlace "Dashboards" en el encabezado principal.
2.  **Inicialización:** En la lista de paneles, hacer clic en el botón "New Dashboard".
3.  **Configuración:** Introducir un nombre y una descripción para el panel. Finaliza el proceso haciendo clic en el botón "Create".
4.  **Visualización:** Seleccionar el nombre del panel recién creado para acceder a la interfaz de edición.

*Al crear un panel por primera vez, este se presentará en blanco. Los bloques de visualización y control deben añadirse manualmente vinculándolos a los feeds correspondientes creados previamente.*

*información sacada de: <https://learn.adafruit.com/adafruit-io-basics-dashboards>*

Así se ve como pagina principal

<img src="./imagenes/sofiacartes_imagenes/instalaciónAdaIO.jpg" alt="install" width="700">

### Llave para colocar en el código en arduino

```cpp
#define IO_USERNAME  "sofiacartess"
#define IO_KEY       "sdfgh"
```

Siempre hay que colocar esa línea, para que el arduino no olvide el adafruit IO

```cpp
io.run();
```

Es para ver lo que manda el otro arduino en adafruit 

```cpp
io.feed();
```

Código que si funciona + el `config.h` es donde se guarda la clave de Adafruit IO y la clave de wifi

```cpp
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
AdafruitIO_Feed *nombreFeed = io.feed("grupo01");

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

*Este fue parte del trabajo en clases en grupo* 

### Conexión con Adafruit IO

```cpp
AdafruitIO_Feed *grupo01 = io.feed("grupo01");
```

Se define un feed llamado "grupo01".

Este feed funciona como canal de comunicación, envío/recepción.

### Recepción de datos desde Adafruit IO

```cpp
void handleMessage(AdafruitIO_Data *data)
```

Esta función se realiza cada vez que llega un dato desde el feed.

```cpp
String valor = data->value();
```

Obtiene el valor enviado, en este caso ON/OFF.

```cpp
if(valor == "ON") {
  oledEncendida = true;
} else {
  oledEncendida = false;
}
```

Controla el estado de la pantalla según el mensaje recibido.

*Estas son partes del código final, el cual se buscó para lograr los ON/OFF con la pantalla.*

### Wokwi Animator

*Investigación a parte*

#### ¿Qué es Wokwi Animator?

Wokwi Animator es una herramienta web que permite convertir imágenes o animaciones en código compatible con pantallas OLED utilizadas en Arduino o ESP32.

Funciona dentro del ecosistema de Wokwi, un simulador online de circuitos electrónicos donde se puede probar proyectos sin hardware físico.

Su principal función es generar automáticamente los frames en formato bitmap, listos para ser usados en código.

*Logra que se vea así en la pantalla OLED* 

<img src="./imagenes/sofiacartes_imagenes/imagenFinal.jpg" alt="install" width="600">

## sobre artista, diseñadora o producto que usa electrónica o computación inalámbricas

### Suhayya Abu-Hakima

<img src="./imagenes/sofiacartes_imagenes/SuhayyaAbu-Hakima.jpg" alt="install" width="300">

#### ¿Quién es Suhayya Abu-Hakima?

Suhayya Abu-Hakima es una científica, emprendedora y experta en tecnología inalámbrica nacida en Jordania y radicada en Canadá. Es reconocida por su trabajo en el desarrollo de sistemas de comunicación móvil y plataformas de alerta masiva.
Es cofundadora de la empresa Amika Mobile, donde desarrolló soluciones que permiten enviar mensajes de emergencia a múltiples dispositivos móviles en situaciones críticas. Su trabajo se enfoca en el uso de redes inalámbricas para mejorar la comunicación en contextos de riesgo, como desastres naturales o emergencias públicas.
Además, ha sido una figura importante en el desarrollo de tecnologías de redes móviles y ha contribuido a la investigación en áreas como redes distribuidas y sistemas de comunicación en tiempo real.

#### ¿Qué desarrolló Suhayya Abu-Hakima?

Desarrolló tecnologías de comunicación inalámbrica enfocadas en la transmisión de alertas masivas en tiempo real.
Uno de sus principales aportes fue el desarrollo del Amika Mobility Server, un sistema capaz de conectarse automáticamente con teléfonos móviles y computadores cercanos para enviar notificaciones críticas sin necesidad de intervención manual.

#### ¿Cómo funciona su tecnología de comunicación?

- Su sistema se basa en redes inalámbricas que permiten establecer conexiones automáticas con dispositivos dentro de un área determinada.
- Detecta dispositivos móviles disponibles en la red.
- Establece conexiones de forma automática.
- Envía mensajes de alerta en tiempo real a múltiples usuarios simultáneamente.
- Esto permite una comunicación rápida, directa y eficiente, especialmente en situaciones donde los canales tradicionales pueden fallar o colapsar.
- Su enfoque prioriza la inmediatez y la cobertura, asegurando que la información llegue a la mayor cantidad de personas posible en el menor tiempo.

#### ¿Qué aplicaciones actuales tiene su tecnología?

- Sistemas de alerta de emergencia en universidades, ciudades y edificios corporativos.
- Notificaciones masivas en caso de desastres naturales o evacuaciones.
- Plataformas de comunicación en crisis para gobiernos y organizaciones.
- Sistemas de seguridad pública que requieren difusión rápida de información.
- Infraestructura de ciudades inteligentes (smart cities) para gestión de riesgos.

Es genial :)

## dificultades y aprendizajes 

`Dificultades`

- Concretar qué queríamos realizar para la solemne, qué componentes agregar para que se nos hiciera curioso y didactico el aprendizaje.
- Juntar la pantalla OLED en el código, para que se encienda y apague con las señales emitidas.

`Aprendizajes`

- Las funciones de Adafruit IO y cómo implementarlas en el código.
- Llave para colocar en el código en arduino
- Interacciones inalámbricas mediante una red de wifi
- Uso con WipperSnapper (No-Code) (para usuarios que utilizan la plataforma de configuración sin código, la gestión es automatizada(.
