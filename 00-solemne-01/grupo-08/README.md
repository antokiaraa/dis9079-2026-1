# grupo 8

## Integrantes

* Braulio Figueroa  **Github:** brauliofigueroa2001
* Luisa Toro        **Github:** Luisaatoro9

## Descripción del proyecto
El objetivo de esta experimentación fue establecer una comunicación robusta entre dos nodos de hardware independientes (Arduino UNO R4 WiFi). Implementamos un sistema donde un Arduino Emisor envía datos numéricos a la nube, y un Arduino Receptor captura esa información en tiempo real para procesarla y dibujarla físicamente en su matriz de LEDs de 12x8. Este proyecto integra conceptos de redes, protocolos de internet, actualización de firmware y programación.
## Materiales usados en la solemne-01

- **2 Placas Arduino UNO R4 WiFi:** Con procesador Renesas RA4M1 y coprocesador de comunicaciones ESP32-S3.

- **2 Matrices LED de 12x8:** Integradas en el hardware del Arduino UNO R4 para la visualización de datos y estados.

- **2 Cables USB-C a USB-C:** Para la programación y alimentación de las placas.

- **2 Computadores (PC/Laptop):** Estaciones de trabajo con Arduino IDE instalado.

- **Plataforma IoT Adafruit IO:** Servicio en la nube para el dashboard de visualización.

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
<p align="center"> <img src="https://github.com/user-attachments/assets/e122d6a9-9a39-4175-9682-1d5659ad8e9c" width="300"><br> <i><b>Imagen 1:</b> Configuración del Punto de Acceso (Hotspot) en la banda de 2.4 GHz.</i> </p> 

**2. El Desafío Crítico: Actualización de Firmware**

Uno de los mayores obstáculos técnicos fue la incompatibilidad del software base de las placas.

<p align="center"> <img src="https://github.com/user-attachments/assets/63048c7a-2b44-414e-8133-9d5d6b4dff5e" width="45%" style="margin-right: 10px;" alt="Firmware Updater Paso 1"> <img src="https://github.com/user-attachments/assets/0e4267f4-2c7c-4343-af64-6a46be168165" width="47%" alt="Firmware Updater Paso 2"> </p> <p align="center"> <i><b>Imagen 02 y 03:</b> Proceso de actualización del firmware ESP32-S3 a la versión 0.6.0 para habilitar la conexión segura con la nube.</i> </p> 

* **El Problema:** Ambas placas venían con la versión 0.5.2, la cual presentaba errores en la gestión de certificados SSL/TLS, impidiendo que el Receptor se conectara de forma segura a Adafruit IO.
* **La Solución:** Nos dimos cuenta de que las placas no venían listas de fábrica, así que tuvimos que flashearlas por nuestra cuenta. Usamos la herramienta ESP32-S3 Firmware Updater para actualizar ambas unidades a la versión 0.6.0. Sin este paso, era imposible que el código de internet funcionara bien.

💡¿Por qué se dice "flashear"? El término viene de cuando se usaba un haz de luz ultravioleta (un flash) para borrar los chips antiguos. Hoy es solo software.
* **Aprendizaje:** En informática, el hardware y el software deben estar sincronizados. Sin un firmware actualizado, los protocolos de seguridad modernos de la nube rechazan la conexión de los microcontroladores.

Microcontrolador: Es un sistema de computación diseñado para realizar una función específica dentro de un producto más grande (como el chip que controla tu lavadora o el sistema de frenos de un auto). A diferencia de una PC, no es para uso general.

**3. Arquitectura de Software y Librerías**

Para que el código compilara sin errores, aplicamos una jerarquía estricta de librerías. Aprendimos que C++ procesa las instrucciones en orden, por lo que la estructura fue:

1. AdafruitIO_WiFi.h: Gestiona la pila de protocolos TCP/IP y la conexión al servidor.
2. ArduinoGraphics.h: Carga el motor lógico de dibujo en la memoria RAM.
3. Arduino_LED_Matrix.h: Define el controlador físico de los 96 LEDs.

<p align="center"> <img src="https://github.com/user-attachments/assets/e44e209b-2b5b-4035-88bc-4abd47e1fdfb" width="51%" style="margin-right: 10px;" alt="Código de ejemplo oficial"> <img src="https://github.com/user-attachments/assets/6b000717-ca2f-432e-b802-e2e4ef6b8fd8" width="34%" alt="Menú de ejemplos en el IDE"> </p> <p align="center"> <i><b>Imagen 04 y 05:</b> Análisis del ejemplo oficial "TextWithArduinoGraphics" y la ruta de acceso a las librerías de la matriz LED en el Arduino IDE.</i> </p>

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

<br> <img src="https://github.com/user-attachments/assets/79306622-afa2-4a82-b555-350f6262ebb5" align="left" width="610" style="margin-right: 20px;"> **Imagen 06:** En esta captura de nuestro código final, se puede observar cómo organizamos las instrucciones para que el Arduino reciba el dato y lo ubique exactamente en el centro de la matriz (coordenadas 2.9, 1). Es el "cerebro" de la visualización, gestiona la entrada de datos y su representación en la pantalla LED. <br clear="left"/> <br> 


**5. Organización y Seguridad: ¿Cómo estructuramos el proyecto?**

Al principio no sabíamos que el Arduino IDE permitía usar varias pestañas, pero decidimos investigar para no dejar nuestras claves expuestas en el código principal.

* **El archivo config.h:** Para mantener la seguridad y el orden, separamos las credenciales (SSID, Password y API Key) en una pestaña independiente. Esto permite que el archivo principal .ino se enfoque exclusivamente en la lógica de la matriz LED.

  💡 Nota técnica: Creamos este archivo directamente en el IDE de Arduino usando la opción "New Tab" del menú lateral derecho (tres puntos verticales), lo que facilita la escalabilidad del proyecto.
 <p align="center"> <img src="https://github.com/user-attachments/assets/9e6645d1-e042-4ac2-b563-41d6c5243395" width="45%" alt="Integración config.h"> <br> <i><b>Imagen 07:</b> Integración de la pestaña config.h en el Arduino IDE mostrando la protección de credenciales.</i> </p>

B. La importancia de la Estructura Local

Descubrimos por las malas que el Arduino IDE es muy estricto con el orden de archivos.

* **Regla de Oro:** El archivo .ino debe estar dentro de una carpeta con su mismo nombre. Además, el config.h debe vivir en esa misma carpeta para que el compilador lo encuentre.

<p align="center"> <img src="https://github.com/user-attachments/assets/dd2de606-acfc-4056-9e0d-515d641057cd" width="36%" style="margin-right: 5px;" alt="Carpeta del proyecto"> <img src="https://github.com/user-attachments/assets/d1a21068-71f0-40e9-802f-0a3c5448c0ba" width="31%" style="margin-right: 5px;" alt="Archivos ino y config"> <img src="https://github.com/user-attachments/assets/53021149-9bf4-4318-999a-872dfb5c34fc" width="31%" alt="IDE con pestañas"> </p> <p align="center"> <i><b>Imagen 08, 09 y 10:</b> Evidencia de la estructura de archivos local y la integración de la pestaña config.h en el Arduino IDE.</i> </p> 



**6. Resultados Finales: Demostración del sistema funcionando**

En estos clips mostramos cómo el sistema reacciona en tiempo real. Al cambiar el número en nuestro Dashboard de Adafruit, la placa recibe el dato por WiFi y lo dibuja automáticamente en la matriz. Fue genial ver que, después de configurar todo, la respuesta es casi instantánea.


<table border="0"> <td width="45%" style="border: none; vertical-align: top;"> <p align="center"></p> <video src="https://github.com/user-attachments/assets/ff3b8657-e86f-4fdb-aae0-ed10e34156e5" width="100%" controls></video> </td> <td width="54%" style="border: none; vertical-align: top;"> <p align="center"></p> <video src="https://github.com/user-attachments/assets/7c8131af-6485-4b59-a244-490a2112a15b" width="50%" controls></video> </td> </tr> </table> <p align="center"> <i><b>Grabaciones de pantalla:</b> Demostración del flujo del programa.</i> </p>
<table border="0"> <td width="60%" style="border: none; vertical-align: top;"> <p align="center"></p> <video src="https://github.com/user-attachments/assets/f0258dea-b035-4439-9752-2616746d6365" width="100%" controls></video> </td> <td width="50%" style="border: none; vertical-align: top;"> <p align="center"></p> <video src="https://github.com/user-attachments/assets/8137d971-f737-4541-b7f0-2836553962c1" width="100%" controls></video> </td> </tr> </table> <p align="center"> <i><b>Videos pruebas:</b> Demostración de la comunicación en tiempo real.</i> </p>
<div align="center"> <img src="https://github.com/user-attachments/assets/b726ee7b-c2ba-4e0b-8bb0-10ed85315eb7" width="1000px"> <p><b>Imagen 11:</b> Visualización de la actividad de datos en el dashboard de Adafruit IO (7-10 de abril).</p> </div>


8. Conclusiones del Grupo

* **La resiliencia es clave:** fallar en el firmware o en la frecuencia del WiFi nos obligó a investigar a fondo el hardware.
* **La documentación importa:** entender el orden de las librerías y los baudios nos ahorró horas de errores inexplicables.
* **El IoT es un ecosistema:** logramos que dos dispositivos distantes actúen como una sola unidad funcional gracias a una lógica de programación bien estructurada.
  
## Definiciones:
1. **ESP32-S3:** Es un microcontrolador de alto rendimiento integrado en el Arduino UNO R4 WiFi que actúa como coprocesador de comunicaciones. Su función principal es gestionar la conectividad inalámbrica (Wi-Fi y Bluetooth) y garantizar la seguridad de las transmisiones mediante el soporte de protocolos avanzados.
2.  **Firmware:** Es un tipo de software específico que actúa como el "sistema operativo" interno de un componente de hardware. Proporciona las instrucciones básicas para que el chip sepa cómo comunicarse con otros programas o redes. (Es lo que ustedes actualizaron a la v0.6.0).
3. **Certificados SSL/TLS:** Protocolos de seguridad que cifran la conexión entre el Arduino y los servidores (como Adafruit IO). Garantizan que los datos viajen de forma privada y que el dispositivo se comunique con un servidor auténtico.
4. **Microcontrolador:** Circuito integrado de alta escala de integración que contiene todos los elementos de una computadora (CPU, memoria y periféricos de entrada/salida) en un solo chip, diseñado para ejecutar tareas de control específicas en sistemas embebidos.
5. **Hardware:** Se refiere a todos los componentes físicos y tangibles de un sistema informático. En su proyecto, el hardware incluye las placas Arduino UNO R4 WiFi, los cables USB-C, el chip ESP32-S3 y la matriz de 96 LEDs integrada.
8. **C++:** Lenguaje de programación de alto nivel y alto rendimiento utilizado para programar microcontroladores. Permite una gestión eficiente de la memoria y control directo sobre el hardware del Arduino.
6. **Baudios (Baud Rate):** Es la unidad de medida que indica la velocidad de transmisión de datos en una comunicación serie. Representa el número de símbolos o bits enviados por segundo entre dos dispositivos (como tu PC y el Arduino). Si ambos no están configurados a los mismos baudios (ej. 115200), la información se vuelve ilegible.
7. **Controlador Físico (Matriz 12x8):** Componente integrado en el Arduino UNO R4 que gestiona una cuadrícula de 96 LEDs (12x8). Utiliza técnicas de multiplexación para encender cada LED individualmente y formar gráficos o texto mediante código.
9. **Hardware IoT:** Conjunto de dispositivos físicos (sensores, actuadores y microcontroladores) equipados con conectividad que permiten recolectar y transmitir datos a través de internet para interactuar con el mundo físico.

## 📚 Bibliografía

- Ardumania. (2025, 21 de noviembre). *Qué es el ESP32: características, funcionamiento y cómo aprovecharlo*.  
  https://ardumania.es/que-es-el-esp32/

- F5. (s. f.). *¿Qué es el cifrado SSL/TLS?*  
  https://www.f5.com/es_es/glossary/ssl-tls-encryption  

- Fortinet. (s. f.). *¿Qué es el firmware?*  
  https://www.fortinet.com/lat/resources/cyberglossary/what-is-firmware  

- IBM. (s. f.). *¿Qué es un microcontrolador?* IBM Think.  
  https://www.ibm.com/mx-es/think/topics/microcontroller  

- Lenovo. (s. f.). *¿Qué es el hardware?*  
  https://www.lenovo.com/cl/es/glosario/hardware/  

- OpenWebinars. (s. f.). *¿Qué es C++?*  
  https://openwebinars.net/blog/que-es-cpp/  

- Riverdi. (s. f.). *Comprender la velocidad en baudios: una guía completa*.  
  https://riverdi.com/es/blog/comprender-la-velocidad-en-baudios-una-guia-completa  

- SunFounder. (s. f.). *Led matrix*. SunFounder Documentation.  
  https://docs.sunfounder.com/projects/elite-explorer-kit/es/latest/new_feature_projects/04_led_matrix.html  

- TechVidvan. (s. f.). *IoT hardware - sensors, wearables and devices*.  
  https://techvidvan.com/tutorials/iot-hardware/  
