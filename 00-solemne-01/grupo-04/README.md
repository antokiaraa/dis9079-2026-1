# grupo-04

## integrantes

* antonella lavalle
* catalina salinas <https://github.com/catasal/dis9079-2026-1>
* martina alegria

## descripción del proyecto

## materiales usados en solemne-01

## código usado con Adafruit IO

### código para enviar

<img width="1900" height="940" alt="Captura de pantalla 2026-04-06 160014" src="https://github.com/user-attachments/assets/a316168d-0b0f-4ed2-9a27-c916991a1805" />

<img width="1920" height="1008" alt="image" src="https://github.com/user-attachments/assets/5ee5e857-3a3e-42a0-8ace-0b8725b25f91" />

Nos estuvo saliendo solo puntitos durante toda la clase, tratamos con 3 hotspot diferentes y usuarios de adafruit, creemos que falló por el uso de mayúsculas y minúsculas mal puestas, los nombres de los hotspot, además de que las contraseñas eran solo de 8 caracteres. Pero luego cambiamos la contraseña de internet a una mas larga (mas de 8 caracteres y solo con minúsculas y números)
con ese cambio resulto al enviar datos.

<img width="1920" height="1008" alt="imagen1" src="https://github.com/user-attachments/assets/634f3f8f-8182-4513-914b-58559216b30c" />

## config.h

```cpp
// rellenar
// reemplazar por las credenciales de aaron
// o por las de tu cuenta
#define IO_USERNAME  "udpmontoyamoraga"
#define IO_KEY       "clave"


// reemplazar por nombre y clave de la wifi
#define WIFI_SSID "cata"
#define WIFI_PASS "clave"

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

### código para recibir

```cpp
// rellenar
```

## investigaciones individuales

* martina alegria-persona 03

* antonella lavalle-persona 01
* catalina salinas-persona 02
* martina alegria-persona 03

rellenar en el mismo orden que los integrantes del grupo

[persona-01.md](./persona-01.md)
[persona-02.md](./persona-02.md)
[persona-03.md](./persona-03.md)

## bibliografía
