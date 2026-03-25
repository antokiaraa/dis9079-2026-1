# sesion-03

lunes 23 marzo 2026

- Comunicación inalambrica entre distintos dispositivos
- Somos el grupo 1

## Microcontrolador: Raspberry Pi Pico 2 W

Fundación inglesa Raspberry Pi partió lanzando computadores en el 2009. No tiene periféricos (no mouse, etc).

Raspberry Pi lanzó su propio chip microcontrolador, el RP2040 y la sucesora RP2050, que son el corazón de las placas Raspberry Pi Pico y Raspberry Pi Pico 2 respectivamente.

personal computer -> pc

- `Harvard Mark 1:` computador del año de la pera que con suerte sumaba (jajaja)
- `Computer mainframe:` unidad central
- `Atari 2600:` computador para jugar
- `Commodore 64`
- `Spectrum ZX`
- Microcontrolador (Arduino): cosas cumas y lentas
- Computadores (Raspberry): cosas sostificadas y bacanes
- interconectividad con un computador 
- korkg
- monome
- critter and guitari
- rp350 chip
  
 ### Tabla  si prefixes
 
 ![tablaSiPerifixes](./imagenes/siPeriferixes.jpg)
 
- `Beagleboard.org:` hizo una alianza con un arte en inglaterra.
- `Bela.io:` es un be adaptado pero solo para audios.
- `NIME.org:` donde hay papers (como entender hacer audios extraños, investigar)
- `Meet Daisy:` es un microcontrolador para audios (un mega microcontrolador)
- Electro-smith
- `Chompi sampler:` hay un electro-smith de 20 lucas

#### Visual Studio Code

`Descargar`

Claude code: Ia para generar códigos

- Extensions: lugar para descargar
- Rust: lenguaje por el cual quieren cambiar C++, es más seguro
- Python: lenguaje para computadores
- micropython: es más sencillo
- Board type: seleccionar la placa
- Select Pico SDK version: seleccionar la veersion
- SPI:  para concencar un microconrtrolador a una pantalla
- I2C: menos conexiones, es mas simple
- Stdio support: input / ouptup
- SDK: (Software Development Kit o Kit de Desarrollo de Software) conjunto de herramientas, bibliotecas, documentación y ejemplos de código, lenguaje de programación.
- Main ocurre en ese orden
- `stdio_init_all()` : prendete
- `while (true) {`: es verdad
- Pico W onboard LED
- Build: es como el subproducto del final, donde hago cambios y ahí quedan
- Lo importante es que tenga el: `nombre.cpp` (apretar el botón de hacerlo con c++)
- Raspberry Pi, tiene un Main, todo lo que esta adentro de main ocurre.

##### ejemplo visto en clases y exploración grupal

  Prendió una lucecita permanente

```cpp
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "pico/cyw43_arch.h"

// SPI Defines
// We are going to use SPI 0, and allocate it to the following GPIO pins
// Pins can be changed, see the GPIO function select table in the datasheet for information on GPIO assignments
#define SPI_PORT spi0
#define PIN_MISO 16
#define PIN_CS   17
#define PIN_SCK  18
#define PIN_MOSI 19




int main()
{
    stdio_init_all();

    // Initialise the Wi-Fi chip
    if (cyw43_arch_init()) {
        printf("Wi-Fi init failed\n");
        return -1;
    }

    // SPI initialisation. This example will use SPI at 1MHz.
    spi_init(SPI_PORT, 1000*1000);
    gpio_set_function(PIN_MISO, GPIO_FUNC_SPI);
    gpio_set_function(PIN_CS,   GPIO_FUNC_SIO);
    gpio_set_function(PIN_SCK,  GPIO_FUNC_SPI);
    gpio_set_function(PIN_MOSI, GPIO_FUNC_SPI);
    
    // Chip select is active-low, so we'll initialise it to a driven-high state
    gpio_set_dir(PIN_CS, GPIO_OUT);
    gpio_put(PIN_CS, 1);
    // For more examples of SPI use see https://github.com/raspberrypi/pico-examples/tree/master/spi

    // Example to turn on the Pico W LED
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
```

Prender la lucecita 3 veces y que qued encendida :)

```cpp
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "pico/cyw43_arch.h"

// SPI Defines
// We are going to use SPI 0, and allocate it to the following GPIO pins
// Pins can be changed, see the GPIO function select table in the datasheet for information on GPIO assignments
#define SPI_PORT spi0
#define PIN_MISO 16
#define PIN_CS   17
#define PIN_SCK  18
#define PIN_MOSI 19




int main()
{
    stdio_init_all();

    // Initialise the Wi-Fi chip
    if (cyw43_arch_init()) {
        printf("Wi-Fi init failed\n");
        return -1;
    }

    // SPI initialisation. This example will use SPI at 1MHz.
    spi_init(SPI_PORT, 1000*1000);
    gpio_set_function(PIN_MISO, GPIO_FUNC_SPI);
    gpio_set_function(PIN_CS,   GPIO_FUNC_SIO);
    gpio_set_function(PIN_SCK,  GPIO_FUNC_SPI);
    gpio_set_function(PIN_MOSI, GPIO_FUNC_SPI);
    
    // Chip select is active-low, so we'll initialise it to a driven-high state
    gpio_set_dir(PIN_CS, GPIO_OUT);
    gpio_put(PIN_CS, 1);
    // For more examples of SPI use see https://github.com/raspberrypi/pico-examples/tree/master/spi

    // Example: turn on the Pico W LED and blink it 3 times
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
    printf("LED encendida. Parpadeo 3 veces...\n");

    for (int i = 0; i < 3; i++) {
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0); // LED off
        sleep_ms(250);
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1); // LED on
        sleep_ms(250);
    }

    printf("Listo: parpadeo completado. LED queda encendida.\n");

    while (true) {
        tight_loop_contents();
    }
}
```

![tablaSiPerifixes](./imagenes/exploracion1.gif)
 
Que la luz parpadee constantemente

```cpp
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "pico/cyw43_arch.h"

// SPI Defines
// We are going to use SPI 0, and allocate it to the following GPIO pins
// Pins can be changed, see the GPIO function select table in the datasheet for information on GPIO assignments
#define SPI_PORT spi0
#define PIN_MISO 16
#define PIN_CS   17
#define PIN_SCK  18
#define PIN_MOSI 19




int main()
{
    stdio_init_all();

    // Initialise the Wi-Fi chip
    if (cyw43_arch_init()) {
        printf("Wi-Fi init failed\n");
        return -1;
    }

    // SPI initialisation. This example will use SPI at 1MHz.
    spi_init(SPI_PORT, 1000*1000);
    gpio_set_function(PIN_MISO, GPIO_FUNC_SPI);
    gpio_set_function(PIN_CS,   GPIO_FUNC_SIO);
    gpio_set_function(PIN_SCK,  GPIO_FUNC_SPI);
    gpio_set_function(PIN_MOSI, GPIO_FUNC_SPI);
    
    // Chip select is active-low, so we'll initialise it to a driven-high state
    gpio_set_dir(PIN_CS, GPIO_OUT);
    gpio_put(PIN_CS, 1);
    // For more examples of SPI use see https://github.com/raspberrypi/pico-examples/tree/master/spi

    // Example: turn on the Pico W LED and blink it continuously
    printf("LED parpadeando constantemente...\n");

    while (true) {
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0); // LED off
        sleep_ms(250);
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1); // LED on
        sleep_ms(250);
    }
}
```

![tablaSiPerifixes](./imagenes/exploracion2.gif)
