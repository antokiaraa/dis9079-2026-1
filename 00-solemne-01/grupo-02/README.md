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
## materiales usados en solemne-01

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
// rellenar
```

## investigaciones individuales

rellenar en el mismo orden que los integrantes del grupo

[persona-01.md](./persona-01.md) 
[persona-02.md](./persona-02.md)
[persona-03.md](./persona-03.md)

## bibliografía
