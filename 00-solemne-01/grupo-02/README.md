# friendshipisfriend-02

## integrantes

* Magdalena Balart
* Jesus Miranda
* Carla Nuñez

## descripción del proyecto

friendshipisfriend nace desde una idea muy especial, usar la tecnologia no solo para conectar maquinas, sino para conectar personas. queriamos demostrar que el internet de las cosas puede tener sentimientos, y para lograrlo nuestro objetivo fue que con un clic se pudiera mandar un "abrazo digital". todo esto cobra vida al combinar el Arduino UNO R4 Wifi y Adafruit IO que nos sirvio como puente de comunicacion!!.

configuramos un rinconcito en la web adafruit llamado dashboard lo que vendria siendo la cara visible de esto. usamos un feed, que funciona como una cajita de mensajes donde guardamos la señal de activacion. para que nuestro arduino supiera exactamente donde conectarse sin exponer todo, utilizamos el archivo config.h que nos entregaron en clases. en este archivo guardamos nuestro wifi y key de adafruit, permitiendo que el proyecto esté seguro y organizado.

lo más bonito es lo que pasa cuando el arduino recibe la señal desde esta nube, el proceso de utilizar los codigos que fuimos recolectando mediante tutoriales, los que fueron entregados por aaron, por busqueda propia e importando librerias necesarias de adafruit fueron parte fundamental para que la comunicaion resultara. fue emocionante ver como todo cobraba sentido a medida que la programacion era detectada desde adafruit al arduino. en este proceso su LED se enciende y en la pantalla aparece el mensaje "amistad es amigo", momento de felicidad que dura 5 segundos, despues de este tiempo el led se apaga y el sistema regala un ultimo mensaje "te extraño amigo". es nuestra forma de decir que aunque la luz se apague, el cariño permanece.:)

en conclusion friendshipisfriend nos enseñó que todo esto tambien es una forma de expresion. logramos que herramientas muy desconocidas para nosotros como el protocolo mqtt y el procesador de arduino trabajen juntos para enviar un mensaje de afecto a traves de codigos. este proyecto es la prueba de que con un poco de programación, de imaginación podemos acortar cualquier distancia y recordarles a nuestros amigos que siempre estamos ahí para ellos.

![imagenes](./imagenes/completo-amistad-es-amigo.jpeg)

bajoncito para celebrar nuestro logro!1!1!!1

## materiales usados en solemne-01

* 2 Arduinos
* Dupont
* USB c
* Protoboard
* Led
* Cable
* Pantalla oled
* Pulsómetro

## proceso

Primero probamos usando el codigo.ino que mandó Aáron de contador, ya que nos había funcionado en la clase, pero con el dashboard de Aáron. No habíamos probado con nuestra cuenta, entonces nos creamos un dashboard llamado prueba1, con un feed mensaje, y ese feed fue lo único que cambiamos del código de Aáron. Al inicio no funcionó; creemos que algo se nos desordenó, entonces borramos el dashboard y el feed, lo rehímos, pusimos un bloque de texto y fue increíble porque funcionó. Eso sí, al inicio pensábamos que no funcionaba porque decía que estaba desconectado de Adafruit, pero después nos dimos cuenta de que era falta de paciencia, ya que se demoraba entre 2 a 3 min en conectar.

Ya con eso listo, probamos con el pulsómetro. Vimos un código de un tutorial de YouTube; también tuvimos que descargar otra librería, pero queríamos intentar que, cuando el pulsómetro recibiera actividad, en vez de mostrar los BPM, mostrara nuestro mensaje amistad es amigo. En esta parte del proceso aprendimos que, al conectarle elementos externos, al código se le debe sumar la librería; en este caso: #include <PulseSensorPlayground.h>. También quisimos probar tener dos bloques, o sea, dos feed distintos: uno que detectara el mensaje y otro que pudiera detectar el BPM. Vimos hartos tutoriales, pero no había algo tan específico, entonces intentamos mezclar el código del include + el del tutorial del pulsómetro + el de imprimir mensaje: Serial.println, pero probablemente nos faltaban códigos entremedio y aplicamos pedir ayuda a ChatGPT, quien nos unió esos códigos y funcionó. El problema era que el pulsómetro era demasiado sensible y estaba mandando demasiados mensajes en muy poco tiempo a Adafruit, y eso lo colapsó. Cambiamos el código para que ignorara los BPM y que fuera que, al detectar actividad (el dedo puesto) y al sacarlo, si después de 3 sg no había actividad, se mandaba el mensaje (const unsigned long tiempoSinLatido = 3000;). Esta idea tampoco funcionó inmediatamente, pero también porque la sintaxis que encontrábamos estaba mala, y también ChatGPT nos ayudó a unir todo. Al final logramos que el mensaje se enviara más limpio al dashboard, pero para visualizarlo mejor agregamos una caja de stream y funcionó.

Después queríamos probar con la pantalla OLED que compramos. Primero tuvimos que ver un tutorial para ver cómo se conectaba. A diferencia del pulsómetro, que venía con el cable conectado al sensor (?), tuvimos que conectar la pantalla a cables Dupont hembra-macho; no sé si se llama así. También tuvimos que descargar librerías nuevas y usamos el código de un tutorial de YouTube. Entonces aquí queríamos probar algo similar al pulsómetro: darle una variable de tiempo y que cada cierto tiempo pasara algo, o sea, que cada 4 segundos apareciera un corazón y que, cuando apareciera el corazón, enviara un mensaje al dashboard, al bloque stream: amistad es amigo. Aquí ya fue difícil porque no sabíamos dónde encontrar un corazón, y en un tutorial habían corazones con bitmap, pero quedaba cortado. Luego encontramos un código que era un corazón con dos círculos y un triángulo dado vuelta. Este proceso fue engorroso porque teníamos el corazón, pero no teníamos bien las variables del tamaño ni si se iba a hacer pequeño o no, y al buscar en Google, la inteligencia artificial de Google mandaba ciertos códigos que al inicio, en las primeras pruebas, no funcionaron. Pero luego, cuando leímos el código bien, entendimos que estaba fallando porque la velocidad de refresco visual era más alta que el ciclo de animación del corazón, 5 sg, y del ciclo de espera, 10 sg.

Después quisimos probar a la distancia con el otro Arduino que estaba en otra casa. Queríamos que funcionara similar a la lógica de variables del corazón en pantalla: que cada cierto segundo apareciera el mensaje amistad es amigo y se encendiera un LED, y que cuando el LED se apagara, el mensaje fuera te extraño amigo. Aquí recordamos las variables que se hablaron la primera clase: false y true. El primer estado iba a ser false, LED apagado y mensaje te extraño amigo. Entonces, nuevamente con ayuda de ChatGPT, ordenamos los códigos de variables que queríamos, y se basaban en Serial.println("LED encendido -> amistad es amigo"); y Serial.println("LED apagado -> te extraño amigo");.

Ya con estas pruebas decidimos que el proyecto final se iba a concretar en que, desde el Arduino 01 que estaba en casa 01 (Arduino con LED que manda el mensaje amistad es amigo, te extraño amigo), se iba a conectar a un dashboard de computador que estaba en otra casa, 02, y que iba a mostrar el mensaje en un bloque stream y de texto, para luego hacer que nuestro Arduino 02 recibiera este mensaje y lo imprimiera en la pantalla OLED. Este fue el proceso más larguísimo de todos. El primer paso lo intentamos al revés, o sea, el Arduino 02 conectando al dashboard de la casa 01. Intentamos de todo: cambiar feed, abrir el feed porque aparecía ese candado bloqueado, dejar el Arduino quieto por varios minutos para ver si quizás se demoraba por la distancia, pero nada. Lo bueno es que sí buscaba información en Adafruit, pero nunca conectó. Entonces probamos al revés, que es la primera opción que se mencionó: hicimos que el Arduino 01 se conectara a un dashboard a través del feed mensaje2, y logró mostrar el mensaje en el dashboard. Una vez completado eso, conectamos la pantalla OLED. Ambos Arduinos estaban conectados al mismo usuario y key de Adafruit. En tutoriales vimos que sí o sí debía dar el mensaje de recibido. La primera parte de este código era sobre la pantalla OLED, su configuración de tamaño tipográfico, y el código principal para recibir el mensaje era este: Serial.println(io.statusText());. Así, ChatGPT nuevamente nos ayudó con la sintaxis y lo logramos. Fue maravilloso, mejor aprendizaje jjj, muchas gracias Aáron y Mateooo.

<https://drive.google.com/drive/folders/1T4yQb4QH4CQgEXnvzLIhV1lHX_TUkoPy?usp=sharing>

(drive con archivos de proceso)

## código usado con Adafruit IO

### código para enviar

```cpp
#include "config.h"

const int LED_PIN = LED_BUILTIN;   // si usas un LED externo, cambia este pin
const unsigned long INTERVALO = 5000;  // 5 segundos

AdafruitIO_Feed *mensajeFeed = io.feed("mensaje");

bool estadoLed = false;  // empieza apagado
unsigned long ultimoCambio = 0;

void setup() {
  Serial.begin(115200);
  while (!Serial);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  Serial.println("Conectando a Adafruit IO...");
  io.connect();

  while (io.status() < AIO_CONNECTED) {
    Serial.println(io.statusText());
    delay(1000);
  }

  Serial.println("Adafruit IO connected.");

  // mandar estado inicial
  if (mensajeFeed->save("te extraño amigo")) {
    Serial.println("Mensaje inicial enviado: te extraño amigo");
  } else {
    Serial.println("Error al enviar mensaje inicial");
  }

  ultimoCambio = millis();
}

void loop() {
  io.run();

  unsigned long ahora = millis();

  if (ahora - ultimoCambio >= INTERVALO) {
    ultimoCambio = ahora;

    // cambiar estado del LED
    estadoLed = !estadoLed;
    digitalWrite(LED_PIN, estadoLed ? HIGH : LOW);

    // enviar mensaje segun estado
    if (estadoLed) {
      if (mensajeFeed->save("amistad es amigo")) {
        Serial.println("LED encendido -> amistad es amigo");
      } else {
        Serial.println("Error al enviar: amistad es amigo");
      }
    } else {
      if (mensajeFeed->save("te extraño amigo")) {
        Serial.println("LED apagado -> te extraño amigo");
      } else {
        Serial.println("Error al enviar: te extraño amigo");
      }
    }
  }
}
```

### código para recibir

```cpp
#include "config.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C   // este depende de la pantalla parece

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

//feed
AdafruitIO_Feed *mensajeFeed = io.feed("mensaje");

// funcion que escribe texto en la pantalla
void mostrarMensaje(String texto) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Mensaje:");
  display.println();
  display.println(texto);
  display.display();
}

// callback: se ejecuta cuando llega un mensaje nuevo
void handleMessage(AdafruitIO_Data *data) {
  String texto = data->toString();

  Serial.print("recibido <- ");
  Serial.println(texto);

  mostrarMensaje(texto);
}

void setup() {
  Serial.begin(115200);
  while (!Serial);

  Wire.begin();

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println("No se pudo iniciar la OLED");
    while (true);
  }

  display.clearDisplay();
  display.display();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Conectando a");
  display.println("Adafruit IO...");
  display.display();

  // este para conectar a adafruit se enoja
  io.connect();

  // suscribirse al feed
  mensajeFeed->onMessage(handleMessage);

  while (io.status() < AIO_CONNECTED) {
    Serial.println(io.statusText());
    delay(1000);
  }

  Serial.println("Adafruit IO connected.");

  // pedir el valor actual del feed al conectarse
  mensajeFeed->get();
}

void loop() {
  io.run();
}
```

## investigaciones individuales

rellenar en el mismo orden que los integrantes del grupo

[persona-01.md](./persona-01.md)
[persona-02.md](./persona-02.md)
[persona-03.md](./persona-03.md)

## bibliografía

**Arduino. UNO R4 WiFi Cheat Sheet / User Manual.** <https://docs.arduino.cc/tutorials/uno-r4-wifi/cheat-sheet/?utm_source=chatgpt.com>
**Adafruit. Adafruit IO Basics: Feeds.** <https://learn.adafruit.com/adafruit-io-basics-feeds?view=all&utm_source=chatgpt.com>
**Adafruit GitHub. Adafruit_SSD1306.** <https://github.com/adafruit/adafruit_ssd1306?utm_source=chatgpt.com>
**Adafruit. Animated Flying Toaster OLED Jewelry – Code.** <https://learn.adafruit.com/animated-flying-toaster-oled-jewelry/code?utm_source=chatgpt.com>
**Arduino: Pantalla Oled de 0.96"** Mostrar Datos Analógicos <https://www.youtube.com/watch?v=GjI0_4ed4JE>
**Arduino oled mostrar datos.txt**  <https://drive.google.com/file/d/1JUANNHpeVcxEBgpdv9FMDBNIgAdSIzLL/view>
**Sensor pulso cardiaco y arduino** <https://m.youtube.com/watch?v=Pu6Ks_O12S8>
**Arduino Documentation. Using Variables in Sketches.** <https://docs.arduino.cc/learn/programming/variables/?utm_source=chatgpt.com>
**Microsoft Learn. Declarations and definitions (C++).** <https://learn.microsoft.com/en-us/cpp/cpp/declarations-and-definitions-cpp?view=msvc-170&utm_source=chatgpt.com>
**Variables en Arduino: Qué Son y Cómo Usarlas Correctamente.** youtube.com/watch?v=GajOQXb1lYw&utm_source=chatgpt.com
**Arduino Tutorial 4: Understanding Arduino Variables.** <https://www.youtube.com/watch?v=nPOKOi1jIK0>
