# Grupo-06

## Integrantes

* Renata De Los Ángeles Arévalo Urra / <https://github.com/arevalourra/dis9079-2026-1/tree/main/06-arevalourra>
* Isidora Andrea Pérez Maulén / <https://github.com/arevalourra/dis9079-2026-1/tree/main/21-isipm08>
* Nicolás Elías Valdés Greve / <https://github.com/arevalourra/dis9079-2026-1/tree/main/29-nicolasvaldesgreve>

## Descripción del proyecto

## Sistema Enviar

Primero iniciamos probando el conectar el Arduino UNO R4 WiFi a un potenciómetro y que éste mande información a Adafruit, por lo que conectamos la placa Arduino al potenciómetro mediante cables Dupont, teniendo las siguientes conexiones:

+ GND - Pata izquierda del potenciómetro (conexión hecha con cable de color negro)
+ A0 - Pata del medio del potenciómetro (conexión hecha con cable de color morado)
+ 5V - Para derecha del potenciómetro (conexión hecha con cable de color roja)

Luego de conectar el potenciómetro al Arduino, así se veía nuestra protoboard:

![Arduino con potenciómetro](./imagenes/armadosistemaenviar.jpeg)

Como ya teníamos la placa y el potenciómetro listos, solo nos faltaba lograr enviar la información del movimiento del potenciómetro al Adafruit IO, por lo que fuimos a Feeds y creamos un feed llamado ``brillo-led`` ya que en ese momento estabamos pensando en hacer que el movimiento del potenciómetro afecte el brillo de un LED. Luego de crear el feed, fuimos a crear una nueva Dashboard en donde presionamos en Add Block y generamos un block de ``Gauge``, el cual va de 0 a 100. A éste block le asignamos el feed ``brillo-led`` y cuando subimos el código en Arduino IDE logramos ver como éste se conectaba a Adafruit IO y nos mostraba el cambio de valor al mover el potenciómetro que estaba conectado a la placa Arduino.

![Adafruit respondiendo a potenciómetro](./imagenes/primerapruebapotenciometro.gif)

Luego, si presionábamos en el feed de ``brillo-led``, nos permitía ver un gráfico que representaba toda la información que le enviábamos desde el potenciómetro, lo cual se veía así:

![Gráfico de información que recibió Adafruit](./imagenes/pruebabrilloledadafruitio.png)

## Sistema Recibir

![Raspberry con LED](./imagenes/armadosistemarecibir.jpeg)

![Pins Raspberry Pi Pico 2 W](./imagenes/Raspberry-Pi-Pico-2-W-Pinout.webp)

![Instalando bibliotecas para la placa Raspberry Pi Pico 2 W en Arduino IDE](./imagenes/instalación-raspberrypiboards.jpeg)

![Error de puerto en Raspberry Pi Pico 2 W](./imagenes/error-arduinoide.jpeg)


## Aarón nos ayuda en el Lid

![titulo](./imagenes/ayudadeaaronenlid.jpeg)


## Prueba sin potenciómetro

![titulo](./imagenes/pruebaledsinpotenciometro.jpeg)

![titulo](./imagenes/pruebalederror.gif)

![titulo](./imagenes/lednodeclarado.jpeg)

![titulo](./imagenes/leddeclarado.jpeg)

El proyecto que realizaremos consiste en la comunicación entre dos placas (Arduino Uno R4 Wifi - Raspberry Pi Pico 2W) conectadas a distintos computadores mediante internet (llamado "si"), utilizando Adafruit IO como intermediario. La idea principal de nuestro proyecto es enviar información desde un dispositivo físico y representarla en otro en tiempo real. 

En este caso, los componentes que utilizamos son:
+ Potenciómetro conectado a Arduino Uno R4 Wifi, el cual envía valores a la nube.
+ 

Utilizamos esta imagen como referencia para guiarnos a través del Raspberry Pi PICO 2W 
![Identificación de pins Raspberry Pi Pico 2 W](./imagenes/pins-raspberry.jpeg) 
## Materiales usados en Solemne-01

| Componente | Cantidad | Valor Unidad | Link |
| --- | --- | --- | --- |
| Protoboard 400 puntos | 2 | $2.100 | <https://prodelab.cl/productos/didacticos/nivel-superior-y-ensenanza-media/robotica-y-programacion/accesorios-robotica-y-programacion/protoboard-breadboard-400-pines/?utm_source=Google%20Shopping&utm_campaign=Google%20Shopping&utm_medium=cpc&utm_term=adtribes&srsltid=AfmBOooQXrc0i240CS5O9AUC5AUSqcPz3Hrk2lJyRK-PgMDmejZeipjTcFg>
| Potenciómetro Lineal B100k | 1 | $495 | <https://altronics.cl/potenciometro-lineal-100k-b100k> |
| Diodo LED | 1 | $70 | <https://afel.cl/products/diodo-led-5mm-ultrabrillante-rojo?srsltid=AfmBOoqRs9WauSkvkWECyOR_iyVpwsim5QBZGM6EE1L0-aXGRZKD_1eJ> |
| Resistencia 220 | 1 | $413 | <https://altronics.cl/pack-10-resistencias-220ohm-025watt-1porciento> |
| Cables Dupont (Pack 40 uni.) | 1 | $2.590 | <https://mcielectronics.cl/shop/product/cable-dupont-macho-macho-20cm-pack-40-unidades/?srsltid=AfmBOooI8-36HQsjC83sDGqLy-uZ_ht-tuw0nwyKZnloJfamdRdmCWYI> |
| Arduino UNO R4 WiFi | 1 | $38.990 | <https://arduino.cl/producto/arduino-uno-r4-wifi/?srsltid=AfmBOopJcCsivMRX00i4ZKVCJATlhSM2Bc6SCRhEdXzw6r1x08Ui9740> |
| Raspberry Pi Pico 2 W | 1 | $14.990 | <https://raspberrypi.cl/products/raspberry-pi-pico-2-w-con-headers> |

## Código usado con Adafruit IO

### Código para enviar

```cpp
// rellenar
```

### Código para recibir

```cpp
// rellenar
```

## Investigaciones Individuales

[persona-01.md](./persona-01.md)  - Renata Arévalo Urra

[persona-02.md](./persona-02.md) - Isidora Pérez Maulén

[persona-03.md](./persona-03.md) - Nicolás Valdés Greve

## bibliografía

Lista de enlaces, libros, clases, tutoriales, etc

* <https://mkelectronica.com/aprende-a-utilizar-la-plataforma-adafruit-io-para-tus-dispositivos-iot-parte-1/>, en donde se explica cómo funciona la plataforma de Adafruit IO incluyendo imagenes para que sea más fácil de entender.
