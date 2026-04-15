# grupo 8

## Integrantes

* Braulio Figueroa  **Github:** brauliofigueroa2001
* Luisa Toro        **Github:** Luisaatoro9

## Descripción del proyecto -  Primer ejercicio en clases

Este proyecto nació como un ejercicio práctico preestablecido por nuestro profesor para la primera etapa de la solemne. El objetivo real era súper directo: aprender a preparar todo el entorno de trabajo, instalar las aplicaciones necesarias en el PC y lograr que el Arduino UNO R4 WiFi se conectara a internet para enviar datos a la nube.

## Materiales usados en la solemne-01

| Cantidad | Componente / Recurso | Función en esta Etapa |
| --- | --- | --- |
| 1 | Arduino UNO R4 WiFi | Placa principal para testear la conexión a internet. |
| 1 | Cable USB-C | Conexión física para cargar el código desde el PC. |
| 1 | Arduino IDE (Software) | Entorno instalado en el PC para programar la placa. |
| 1 | Biblioteca Adafruit IO | Software necesario para que el Arduino hable con la nube. |
| 1 | Cuenta Adafruit IO | Registro en la plataforma para recibir los primeros datos. |
| 1 | Hotspot Móvil / WiFi | Red de 2.4 GHz necesaria para la salida a internet. |

## Código usado con Adafruit IO

### Código para enviar - Ejercicio en clases

```cpp
#include "AdafruitIO_WiFi.h"

#define IO_USERNAME  "bla"
#define IO_KEY       "bla"

#define WIFI_SSID "bla"
#define WIFI_PASS "bla"

// comment out the following lines if you are using fona or ethernet
#include "AdafruitIO_WiFi.h"

#if defined(USE_AIRLIFT) || defined(ADAFRUIT_METRO_M4_AIRLIFT_LITE) ||         \
    defined(ADAFRUIT_PYPORTAL)
// Configure the pins used for the ESP32 connection
#if !defined(SPIWIFI_SS) // if the wifi definition isnt in the board variant
// Don't change the names of these #define's! they match the variant ones
#define SPIWIFI SPI
#define SPIWIFI_SS 10 // Chip select pin
#define NINA_ACK 9    // a.k.a BUSY or READY pin
#define NINA_RESETN 6 // Reset pin
#define NINA_GPIO0 -1 // Not connected
#endif
AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS, SPIWIFI_SS,
                   NINA_ACK, NINA_RESETN, NINA_GPIO0, &SPIWIFI);
#else
AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);
#endif
```

## Desarrollo Experimentación - Primer ejercicio en clases

Primer Acercamiento: Conexión a Adafruit IO

Para ser súper honestos, cuando empezamos el lunes no teníamos mucho manejo del Arduino UNO R4 WiFi ni de cómo funcionaba Adafruit IO. Estábamos recién instalando las bibliotecas en los PC (como se puede evidenciar en nuestras bitacoras personales) y siguiendo el ejercicio base que nos dejó el profesor para el grupo08.

<p align="center"> <img src="https://github.com/user-attachments/assets/9e2fa931-7cbc-4c0f-bc64-3fa5687f1c78" width="20%" style="margin-right: 5px;" alt="Carpeta Grupo"> <img src="https://github.com/user-attachments/assets/fe301c25-7a45-4092-a962-fceebd42ce7b" width="32%" style="margin-right: 5px;" alt="Archivos Código"> <img src="https://github.com/user-attachments/assets/8491ad76-1784-4c08-a075-0df2c04c6964" width="38%" alt="Código Base"> </p> <p align="center"> <i><b>Imagen 01, 02 y 03:</b> Proceso inicial de búsqueda y descarga del código base compartido por el profesor para la configuración del grupo08.</i> </p>

Esta primera etapa fue nuestro "bautismo" con el hardware y nos sirvió para darnos cuenta de detalles técnicos que hoy ya manejamos mejor:

* **El enredo de las credenciales:** Al principio no conectaba y nos quebramos la cabeza un rato hasta que cachamos que el nombre de la red tenía que ser idéntico (mayúsculas y minúsculas). Fue nuestro primer aprendizaje sobre la sensibilidad de los datos en redes.
* **El error de los "rombos" en el monitor:** No entendíamos por qué nos salían símbolos raros en vez de texto. Ahí aprendimos la importancia de los baudios; estábamos en 9600 y el código pedía 115200. Al sincronizarlos, por fin vimos los puntos de conexión.

<p align="center"> <img src="https://github.com/user-attachments/assets/75482ae2-dd1f-4560-9f46-5396952344c2" width="100%" style="margin-right: 10px;" alt="Error de Baudios"> <img src="https://github.com/user-attachments/assets/0dc795cd-8731-45f7-bc43-550a6639ee8f"> </p> <p align="center"> <i><b>Imagen 04 y 05:</b> Evidencia del error de sincronización por baudios incorrectos (rombos) y la posterior conexión exitosa tras el ajuste a 115200 baud.</i> </p>

<p align="center"> <video src="https://github.com/user-attachments/assets/83381775-c25e-414b-ba51-91658d6d1461" width="70%" controls> Tu navegador no soporta el elemento de video. </video> </p> <p align="center"> <i><b>Video de Referencia:</b> Registro del proceso de inicialización y sincronización del Arduino UNO R4 WiFi intentando establecer el handshake con la plataforma Adafruit IO.</i> </p>

* **Resultados en la nube:** Aunque era un ejercicio simple de enviar números, nos sirvió para ver cómo se comporta la plataforma de Adafruit. Vimos en vivo cómo se armaba la tabla con la fecha y hora de cada envío, lo que nos dio la base para después hacer nuestro experimento mucho más complejo.

<p align="center"> <img src="https://github.com/user-attachments/assets/72e73257-906b-4cdc-aefc-7580b6cc23f6" width="100%" style="margin-right: 10px;" alt="Error de Baudios"> <img src="https://github.com/user-attachments/assets/39688e8a-2868-401e-8f03-7d6e76945b2f"> </p> <p align="center"> <i><b>Imagen 06 y 07:</b> Resultados finales en la nube de Adafruit IO. Visualización de la data mediante gráficas en tiempo real y tabla de registros históricos con marcas de tiempo (timestamp).</i> </p>

## Descripción del proyecto - Segundo ejercicio en clases

Este ejercicio práctico consiste en la implementación de un sistema de control IoT bidireccional, utilizando la placa Arduino UNO R4 WiFi y la plataforma Adafruit IO. El objetivo principal es lograr el control remoto de un componente físico (un LED) desde un panel de control digital (Dashboard) en la nube.

## Materiales usados en la solemne-01

| Cantidad | Componente | Descripción |
| --- | --- | --- |
| 1 | Arduino UNO R4 WiFi | Microcontrolador principal con ESP32-S3 para conexión a internet. |
| 1 | Cable USB-C | Para programar y alimentar la placa Arduino. |
| 1 | Protoboard | Tablilla de pruebas para el armado del circuito. |
| 1 | LED | Actuador para la prueba de control desde el dashboard. |
| 1 | Resistencia (220Ω / 330Ω) | Para proteger el LED y evitar que se queme (¡importante!). |
| Pack | Cables Jumper | Para realizar las conexiones entre el Arduino y la protoboard. |
| 1 | Multímetro Digital | Herramienta utilizada para medir resistencia y voltaje en el circuito. |
| 1 | Cuenta Adafruit IO | Plataforma en la nube para el dashboard y control del feed. |

## Código usado con Adafruit IO

### Código para enviar - Ejercicio en clases

```cpp
#include "AdafruitIO_WiFi.h"

/*************** CREDENCIALES ************************/
#define IO_USERNAME "TU_USUARIO_AQUÍ"
#define IO_KEY "TU_KEY_AQUÍ"

#define WIFI_SSID "TU_WIFI_AQUÍ"
#define WIFI_PASS "TU_CLAVE_AQUÍ"

AdafruitIO_Feed *controlLed = io.feed("nombre-de-tu-feed");

void setup() {
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(115200); 
  while(!Serial);

  Serial.print("Conectando a Adafruit IO");

  io.connect();

 
  controlLed->onMessage(handleMessage);

  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println();
  Serial.println(io.statusText());
}

void loop() {
  io.run(); // Mantiene la conexión viva con la nube
}


void handleMessage(AdafruitIO_Data *data) {
  Serial.print("Dato recibido: ");
  Serial.println(data->toChar());

  if(data->toChar() == "1") {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("LED Encendido ");
  } else {
    digitalWrite(LED_PIN, LOW);
    Serial.println("LED Apagado ");
  }
}
```

## Desarrollo proyecto - El drama del LED y la conexión a Adafruit

Después de que logramos conectar el Arduino a internet, nos pusimos una meta más pro: prender un LED con un botón desde la página de Adafruit IO. La idea era que, al apretar un interruptor en el dashboard del computador, el LED en nuestra protoboard reaccionara, apagándose o encendiéndose.

Pero no todo fue perfecto a la primera. Al armar el circuito en la protoboard, tuvimos nuestro primer "fail" técnico: ¡se nos quemó un LED! 😅 Entre el enredo de cables y las resistencias, pusimos una que no era o la conectamos mal, y el pobre LED no sobrevivió.

Dato aparte: Si ven una Raspberry Pi Pico W en las fotos, es porque estaba pegada en la protoboard y no la podíamos sacar, pero no la estábamos ocupando para nada en este ejercicio.

<p align="center"> <img src="https://github.com/user-attachments/assets/45636396-f579-44b3-bd37-a29e11553b11" width="40%"> <br> <i><b>Imagen 08:</b> Setup inicial en la protoboard. (Nota: La Raspberry Pi Pico W estaba fija y no se pudo retirar, pero no es parte del circuito).</i> </p>

Para no seguir quemando componentes, tuvimos que usar el multímetro para revisar bien la resistencia y el voltaje hasta que por fin el LED prendió como correspondía.
<p align="center"> <img src="https://github.com/user-attachments/assets/8b468127-12e1-47de-90de-967b6eebcfcd" width="40%" style="margin-right: 10px;" alt="Uso del multímetro"> <img src="https://github.com/user-attachments/assets/9fefaa40-e1d1-4093-9cd9-8f2fb6b09cc0" width="40%" alt="LED encendido"> </p> <p align="center"> <i><b>Imágenes 09 y 10:</b> Uso del multímetro para corregir la resistencia tras el error del LED quemado y prueba final de encendido con el Arduino UNO R4 WiFi.</i> </p>

<p align="center"> <img src="https://github.com/user-attachments/assets/f2171bea-05c9-43c3-928c-3a00009d471f" width="40%" alt="LED encendido"> </p><p align="center"> <i><b>Imagen 11:</b> Este es el botón que armamos en Adafruit para prender y apagar el LED desde el computador. Teníamos todo listo en la nube, pero al final nos pilló el tiempo; entre que arreglamos el tema del LED quemado y las vueltas con el código, se nos acabó la clase y no alcanzamos a ver el LED prendiendo desde este switch.</i> </p>

## Descripción del proyecto - Experimentación

El objetivo de esta experimentación fue establecer una comunicación robusta entre dos nodos de hardware independientes (Arduino UNO R4 WiFi). Implementamos un sistema donde un Arduino Emisor envía datos numéricos a la nube, y un Arduino Receptor captura esa información en tiempo real para procesarla y dibujarla físicamente en su matriz de LEDs de 12x8. Este proyecto integra conceptos de redes, protocolos de internet, actualización de firmware y programación.

## Materiales usados en la solemne-01

| Cantidad | Componente / Herramienta | Especificaciones Técnicas |
| --- | --- | --- |
| 2 | Placas Arduino UNO R4 WiFi | Procesador Renesas RA4M1 y coprocesador ESP32-S3. |
| 2 | Matrices LED (12x8) | Integradas en el hardware para visualización de datos. |
| 2 | Cables USB-C | Conexión para programación y alimentación de las placas. |
| 2 | Estaciones de Trabajo | Computadores con Arduino IDE y bibliotecas instaladas. |
| 1 | Plataforma Adafruit IO | Servicio en la nube para gestión de feeds y dashboard. |
| 1 | Red Local (Hotspot) | Punto de acceso WiFi dedicado en banda 2.4 GHz. |

- **Red Local (Hotspot 2.4 GHz):** Punto de acceso dedicado para la conexión entre nodos.

## Código usado con Adafruit IO

### Código para enviar - Experimentación

```cpp
#include "AdafruitIO_WiFi.h"

/*************** CREDENCIALES ************************/
#define IO_USERNAME "TU_USUARIO_AQUÍ"
#define IO_KEY "TU_KEY_AQUÍ"

#define WIFI_SSID "TU_WIFI_AQUÍ"
#define WIFI_PASS "TU_CLAVE_AQUÍ"

// Configuración automática (incluye soporte tipo AirLift / UNO R4 WiFi)
#if defined(USE_AIRLIFT) || defined(ADAFRUIT_METRO_M4_AIRLIFT_LITE) || \
    defined(ADAFRUIT_PYPORTAL)

  #define SPIWIFI SPI
  #define SPIWIFI_SS 10
  #define NINA_ACK 9
  #define NINA_RESETN 6
  #define NINA_GPIO0 -1

  AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS,
                     SPIWIFI_SS, NINA_ACK, NINA_RESETN, NINA_GPIO0, &SPIWIFI);

#else

  AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);

#endif

/*************** PROGRAMA PRINCIPAL ************************/

// Conexión al feed
AdafruitIO_Feed *nombreFeed = io.feed("grupo08");

int contador = 0;

void setup() {
  Serial.begin(115200);
  while(!Serial);

  Serial.print("Conectando con Adafruit IO...");

  io.connect();

  // Esperar conexión
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println();
  Serial.println(io.statusText()); // Debería decir "Connected!"
}

void loop() {

  io.run();  // Mantiene la conexión activa

  // PRENDER el LED (pin 13)
  digitalWrite(LED_BUILTIN, HIGH);

  Serial.print("Enviando número -> ");
  Serial.println(contador);

  // Enviar dato a la nube
  nombreFeed->save(contador);

  // APAGAR el LED después de enviar
  delay(200);
  digitalWrite(LED_BUILTIN, LOW);

  contador = contador + 2;

  // Completa los 5 segundos
  delay(4800);
}
```

### Código para recibir - Experimentación

```cpp

#include "ArduinoGraphics.h" 
#include "Arduino_LED_Matrix.h"   // Pantalla LED integrada
#include "AdafruitIO_WiFi.h"

/*************** CREDENCIALES ************************/
#define IO_USERNAME "TU_USUARIO_AQUÍ"
#define IO_KEY "TU_KEY_AQUÍ"

#define WIFI_SSID "TU_WIFI_AQUÍ"
#define WIFI_PASS "TU_CLAVE_AQUÍ"

/*************** OBJETOS ************************/

AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);

ArduinoLEDMatrix matrix;

// Feed desde donde se va a LEER
AdafruitIO_Feed *nombreFeed = io.feed("grupo08");

/*************** SETUP ************************/

void setup() {
  Serial.begin(115200);

  matrix.begin();  // Iniciar pantalla LED

  Serial.print("Conectando a Adafruit IO...");
  io.connect();

  // Cuando llegue un dato → ejecutar leerMensaje
  nombreFeed->onMessage(leerMensaje);

  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println();
  Serial.println(io.statusText());
}

/*************** LOOP ************************/

void loop() {
  io.run();  // Mantiene conexión y recibe datos
}

/***************** FUNCIÓN DE RECEPCIÓN *****************/
void leerMensaje(AdafruitIO_Data *data) {
   matrix.beginDraw();
   matrix.stroke(0xFFFFFFFF);
  matrix.textFont(Font_5x7);
  matrix.beginText(2.9, 1, 0xFFFFFFFF);
   matrix.print(data->value());
  matrix.endText();
   matrix.endDraw(); 
}
```

⚠️ Nota: Para ejecutar este código, tienes que sustituir los valores en la sección CREDENCIALES con sus propios datos de Adafruit IO y red Wi-Fi.

## Desarrollo Experimentación

**1. Configuración de Hardware y "Capa Física" (Networking)**

Antes de escribir una sola línea de código, tuvimos que resolver desafíos de compatibilidad física:

* **Frecuencia de Red (2.4 GHz vs 5 GHz):** Aprendimos que el chip ESP32-S3 del Arduino R4 solo es compatible con redes de 2.4 GHz. Para asegurar una conexión estable y evitar las interferencias de redes universitarias o domésticas de 5 GHz, configuramos un Hotspot móvil (Punto de Acceso) dedicado a 2.4 GHz. Esto garantizó que ambas placas obtuvieran una IP estática local y pudieran realizar el Handshake (saludo de conexión) con el servidor de forma instantánea.
* **Conectividad USB-C y Alimentación:** Utilizamos el estándar USB-C para la carga del código y el monitoreo serial, asegurándonos de que la tasa de transferencia (Baud Rate) estuviera configurada en 115200. Entendimos que si la velocidad del código y la del monitor serie no coinciden, la sincronización de bits se rompe y los datos se vuelven ilegibles.

<p align="center"> <img src="https://github.com/user-attachments/assets/e122d6a9-9a39-4175-9682-1d5659ad8e9c" width="300"><br> <i><b>Imagen 12:</b> Configuración del Punto de Acceso (Hotspot) en la banda de 2.4 GHz.</i> </p>

**2. El Desafío Crítico: Actualización de Firmware**

Uno de los mayores obstáculos técnicos fue la incompatibilidad del software base de las placas.

<p align="center"> <img src="https://github.com/user-attachments/assets/63048c7a-2b44-414e-8133-9d5d6b4dff5e" width="45%" style="margin-right: 10px;" alt="Firmware Updater Paso 1"> <img src="https://github.com/user-attachments/assets/0e4267f4-2c7c-4343-af64-6a46be168165" width="47%" alt="Firmware Updater Paso 2"> </p> <p align="center"> <i><b>Imagen 13 y 14:</b> Proceso de actualización del firmware ESP32-S3 a la versión 0.6.0 para habilitar la conexión segura con la nube.</i> </p>

* **El Problema:** Ambas placas venían con la versión 0.5.2, la cual presentaba errores en la gestión de certificados SSL/TLS, impidiendo que el Receptor se conectara de forma segura a Adafruit IO.
* **La Solución:** Nos dimos cuenta de que las placas no venían listas de fábrica, así que tuvimos que flashearlas por nuestra cuenta. Usamos la herramienta ESP32-S3 Firmware Updater para actualizar ambas unidades a la versión 0.6.0. Sin este paso, era imposible que el código de internet funcionara bien.

💡¿Por qué se dice "flashear"? El término viene de cuando se usaba un haz de luz ultravioleta (un flash) para borrar los chips antiguos. Hoy es solo software.

* **Aprendizaje:** En informática, el hardware y el software deben estar sincronizados. Sin un firmware actualizado, los protocolos de seguridad modernos de la nube rechazan la conexión de los microcontroladores.

Microcontrolador: Es un sistema de computación diseñado para realizar una función específica dentro de un producto más grande (como el chip que controla tu lavadora o el sistema de frenos de un auto). A diferencia de una PC, no es para uso general.

**3. Arquitectura de Software y Bibliotecas**

Para que el código compilara sin errores, aplicamos una jerarquía estricta de bibliotecas. Aprendimos que C++ procesa las instrucciones en orden, por lo que la estructura fue:

1. AdafruitIO_WiFi.h: Gestiona la pila de protocolos TCP/IP y la conexión al servidor.
2. ArduinoGraphics.h: Carga el motor lógico de dibujo en la memoria RAM.
3. Arduino_LED_Matrix.h: Define el controlador físico de los 96 LEDs.

<p align="center"> <img src="https://github.com/user-attachments/assets/e44e209b-2b5b-4035-88bc-4abd47e1fdfb" width="51%" style="margin-right: 10px;" alt="Código de ejemplo oficial"> <img src="https://github.com/user-attachments/assets/6b000717-ca2f-432e-b802-e2e4ef6b8fd8" width="34%" alt="Menú de ejemplos en el IDE"> </p> <p align="center"> <i><b>Imagen 15 y 16:</b> Análisis del ejemplo oficial "TextWithArduinoGraphics" y la ruta de acceso a las bibliotecas de la matriz LED en el Arduino IDE.</i> </p>

❗Punto Clave: Invertir este orden causaba errores de compilación, ya que la matriz intentaba usar funciones gráficas que aún no habían sido declaradas en la memoria volátil del Arduino.

**4. Lógica del Código: ¿Cómo convertimos un número en luces?**

Esta es la parte central de nuestro trabajo. lo explicamos así:

A. El viaje del dato (De placa a placa)

Para que los dos Arduinos se hablen sin cables, usamos un sistema de "aviso" constante:

* **La función io.run() (en el Loop):** Es como si el Arduino Receptor estuviera todo el tiempo preguntando por WiFi: "¿Escribieron algo nuevo en Adafruit?". Sin esta instrucción, la placa se quedaría "dormida" y no recibiría los números del Emisor.
* **La función leerMensaje:** Esta es una función especial que nosotros creamos. Solo se activa cuando llega un dato nuevo. Es como un "repartidor" que trae el sobre con el número y se lo entrega al Arduino para que empiece a trabajar.

B. Dibujando en la pantalla (Matriz de 12x8)

En lugar de prender luces al azar, el Arduino trabaja como un diseñador gráfico:

* **matrix.beginDraw() (El Lienzo):** Le decimos al Arduino: "Saca una hoja en blanco en tu memoria y prepárate para dibujar".
* **matrix.stroke(0xFFFFFFFF) (El Color):** Aquí elegimos el "color" de nuestro lápiz. En código hexadecimal, esto significa blanco puro (máximo brillo de los LEDs).
* **matrix.textFont(Font_5x7) (El Tamaño):** Elegimos una letra que quepa bien en los 12x8 puntitos de la pantalla.
* **matrix.beginText(2.9, 1, ...) (La Ubicación):** ¡Esto es clave! Le estamos diciendo al Arduino: "Empieza a escribir el número un poquito más a la derecha (2.9) y un poquito más abajo (1)". Esto sirve para que el número quede centrado y no se vea cortado.
* **matrix.print(data->value()) (El Contenido):** Aquí el Arduino toma el valor que llegó desde internet y lo escribe en su lienzo virtual.
* **matrix.endText() y matrix.endDraw() (La Obra Final):** Cerramos el lápiz y mandamos el dibujo terminado a los 96 LEDs físicos.

<br> <img src="https://github.com/user-attachments/assets/79306622-afa2-4a82-b555-350f6262ebb5" align="left" width="610" style="margin-right: 20px;"> **Imagen 17:** En esta captura de nuestro código final, se puede observar cómo organizamos las instrucciones para que el Arduino reciba el dato y lo ubique exactamente en el centro de la matriz (coordenadas 2.9, 1). Es el "cerebro" de la visualización, gestiona la entrada de datos y su representación en la pantalla LED. <br clear="left"/> <br>

**5. Organización y Seguridad: ¿Cómo estructuramos el proyecto?**

Al principio no sabíamos que el Arduino IDE permitía usar varias pestañas, pero decidimos investigar para no dejar nuestras claves expuestas en el código principal.

* **El archivo config.h:** Para mantener la seguridad y el orden, separamos las credenciales (SSID, Password y API Key) en una pestaña independiente. Esto permite que el archivo principal .ino se enfoque exclusivamente en la lógica de la matriz LED.

  💡 Nota técnica: Creamos este archivo directamente en el IDE de Arduino usando la opción "New Tab" del menú lateral derecho (tres puntos verticales), lo que facilita la escalabilidad del proyecto.

 <p align="center"> <img src="https://github.com/user-attachments/assets/9e6645d1-e042-4ac2-b563-41d6c5243395" width="45%" alt="Integración config.h"> <br> <i><b>Imagen 18:</b> Integración de la pestaña config.h en el Arduino IDE mostrando la protección de credenciales.</i> </p>

B. La importancia de la Estructura Local

Descubrimos por las malas que el Arduino IDE es muy estricto con el orden de archivos.

* **Regla de Oro:** El archivo .ino debe estar dentro de una carpeta con su mismo nombre. Además, el config.h debe vivir en esa misma carpeta para que el compilador lo encuentre.

<p align="center"> <img src="https://github.com/user-attachments/assets/dd2de606-acfc-4056-9e0d-515d641057cd" width="36%" style="margin-right: 5px;" alt="Carpeta del proyecto"> <img src="https://github.com/user-attachments/assets/d1a21068-71f0-40e9-802f-0a3c5448c0ba" width="31%" style="margin-right: 5px;" alt="Archivos ino y config"> <img src="https://github.com/user-attachments/assets/53021149-9bf4-4318-999a-872dfb5c34fc" width="31%" alt="IDE con pestañas"> </p> <p align="center"> <i><b>Imagen 19, 20 y 21:</b> Evidencia de la estructura de archivos local y la integración de la pestaña config.h en el Arduino IDE.</i> </p>

**6. Resultados Finales: Demostración del sistema funcionando**

En estos clips mostramos cómo el sistema reacciona en tiempo real. Al cambiar el número en nuestro Dashboard de Adafruit, la placa recibe el dato por WiFi y lo dibuja automáticamente en la matriz. Fue genial ver que, después de configurar todo, la respuesta es casi instantánea.

<table border="0"> <td width="45%" style="border: none; vertical-align: top;"> <p align="center"></p> <video src="https://github.com/user-attachments/assets/ff3b8657-e86f-4fdb-aae0-ed10e34156e5" width="100%" controls></video> </td> <td width="54%" style="border: none; vertical-align: top;"> <p align="center"></p> <video src="https://github.com/user-attachments/assets/7c8131af-6485-4b59-a244-490a2112a15b" width="50%" controls></video> </td> </tr> </table> <p align="center"> <i><b>Grabaciones de pantalla:</b> Demostración del flujo del programa.</i> </p>
<table border="0"> <td width="60%" style="border: none; vertical-align: top;"> <p align="center"></p> <video src="https://github.com/user-attachments/assets/f0258dea-b035-4439-9752-2616746d6365" width="100%" controls></video> </td> <td width="50%" style="border: none; vertical-align: top;"> <p align="center"></p> <video src="https://github.com/user-attachments/assets/8137d971-f737-4541-b7f0-2836553962c1" width="100%" controls></video> </td> </tr> </table> <p align="center"> <i><b>Videos pruebas:</b> Demostración de la comunicación en tiempo real.</i> </p>
<div align="center"> <img src="https://github.com/user-attachments/assets/b726ee7b-c2ba-4e0b-8bb0-10ed85315eb7" width="1000px"> <p><b>Imagen 22:</b> Visualización de la actividad de datos en el dashboard de Adafruit IO (7-10 de abril).</p> </div>

1. Conclusiones del Grupo

* **La resiliencia es clave:** fallar en el firmware o en la frecuencia del WiFi nos obligó a investigar a fondo el hardware.
* **La documentación importa:** entender el orden de las bibliotecas y los baudios nos ahorró horas de errores inexplicables.
* **El IoT es un ecosistema:** logramos que dos dispositivos distantes actúen como una sola unidad funcional gracias a una lógica de programación bien estructurada.
  
## Definiciones

1. **ESP32-S3:** Es un microcontrolador de alto rendimiento integrado en el Arduino UNO R4 WiFi que actúa como coprocesador de comunicaciones. Su función principal es gestionar la conectividad inalámbrica (Wi-Fi y Bluetooth) y garantizar la seguridad de las transmisiones mediante el soporte de protocolos avanzados.
2. **Firmware:** Es un tipo de software específico que actúa como el "sistema operativo" interno de un componente de hardware. Proporciona las instrucciones básicas para que el chip sepa cómo comunicarse con otros programas o redes. (Es lo que ustedes actualizaron a la v0.6.0).
3. **Certificados SSL/TLS:** Protocolos de seguridad que cifran la conexión entre el Arduino y los servidores (como Adafruit IO). Garantizan que los datos viajen de forma privada y que el dispositivo se comunique con un servidor auténtico.
4. **Microcontrolador:** Circuito integrado de alta escala de integración que contiene todos los elementos de una computadora (CPU, memoria y periféricos de entrada/salida) en un solo chip, diseñado para ejecutar tareas de control específicas en sistemas embebidos.
5. **Hardware:** Se refiere a todos los componentes físicos y tangibles de un sistema informático. En su proyecto, el hardware incluye las placas Arduino UNO R4 WiFi, los cables USB-C, el chip ESP32-S3 y la matriz de 96 LEDs integrada.
6. **C++:** Lenguaje de programación de alto nivel y alto rendimiento utilizado para programar microcontroladores. Permite una gestión eficiente de la memoria y control directo sobre el hardware del Arduino.
7. **Baudios (Baud Rate):** Es la unidad de medida que indica la velocidad de transmisión de datos en una comunicación serie. Representa el número de símbolos o bits enviados por segundo entre dos dispositivos (como tu PC y el Arduino). Si ambos no están configurados a los mismos baudios (ej. 115200), la información se vuelve ilegible.
8. **Controlador Físico (Matriz 12x8):** Componente integrado en el Arduino UNO R4 que gestiona una cuadrícula de 96 LEDs (12x8). Utiliza técnicas de multiplexación para encender cada LED individualmente y formar gráficos o texto mediante código.
9. **Hardware IoT:** Conjunto de dispositivos físicos (sensores, actuadores y microcontroladores) equipados con conectividad que permiten recolectar y transmitir datos a través de internet para interactuar con el mundo físico.

## 📚 Bibliografía

* Ardumania. (2025, 21 de noviembre). *Qué es el ESP32: características, funcionamiento y cómo aprovecharlo*.  
  <https://ardumania.es/que-es-el-esp32/>

* F5. (s. f.). *¿Qué es el cifrado SSL/TLS?*  
  <https://www.f5.com/es_es/glossary/ssl-tls-encryption>  

* Fortinet. (s. f.). *¿Qué es el firmware?*  
  <https://www.fortinet.com/lat/resources/cyberglossary/what-is-firmware>  

* IBM. (s. f.). *¿Qué es un microcontrolador?* IBM Think.  
  <https://www.ibm.com/mx-es/think/topics/microcontroller>  

* Lenovo. (s. f.). *¿Qué es el hardware?*  
  <https://www.lenovo.com/cl/es/glosario/hardware/>  

* OpenWebinars. (s. f.). *¿Qué es C++?*  
  <https://openwebinars.net/blog/que-es-cpp/>  

* Riverdi. (s. f.). *Comprender la velocidad en baudios: una guía completa*.  
  <https://riverdi.com/es/blog/comprender-la-velocidad-en-baudios-una-guia-completa>  

* SunFounder. (s. f.). *Led matrix*. SunFounder Documentation.  
  <https://docs.sunfounder.com/projects/elite-explorer-kit/es/latest/new_feature_projects/04_led_matrix.html>  

* TechVidvan. (s. f.). *IoT hardware - sensors, wearables and devices*.  
  <https://techvidvan.com/tutorials/iot-hardware/>  
