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
