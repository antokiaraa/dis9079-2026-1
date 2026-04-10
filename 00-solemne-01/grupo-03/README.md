# grupo-03

## integrantes

* Antonella Aguilar
* Tomás Catrileo
* Angel Sabogal

## descripción del proyecto

Para llegar a la conexión del LED RGB primero tuvimos que tener una cuenta de Adafruit que en este caso nos proporcionó una mejora el profesor para tener la cuenta de pago y esta la hicimos cada uno para testear individualmente con nuestros correos UDP.

Habiendo iniciado sesión vamos a configuraciones para darle al botón que nos da la clave AIO que necesitaremos más tarde.

Procedimos a la creación del flujo del color creando una Feed llamada específicamente "color".

A continuación en la sección de "Dashboards" agregamos un bloque de color ingresando a la pestaña de Dashboards y haciendo clic adentro del apartado color que también hay que crear manualmente en esta misma sección lo que nos daría como resultado el bloque en el panel de control de esta manera:

![Ejemplo de Bloque de color](./imagenes/bloquecolorgrupo.png)

**Configuración de arduino**

En nuestro caso usaremos Arduino UNO R4 WIFI, por ende tiene una configuración correspondiente al hardware y, como dice el nombre, sí tiene "wifi", que también usaremos, y antes de continuar asegurarnos de tener instalada al menos la versión 2.4.0 de la biblioteca Adafruit IO Arduino.

Y como nos indicaba la instrucción, descargamos adafruitio_13_rgb en la biblioteca Adafruit IO Arduino, que es el que tiene el código RGB para el LED.

![Código del RGB](./imagenes/adafruito13rgb.png)

Ahora pocedemos a hacer

**La configuración de red arduino**

Primero vamos a la App de Arduino IDE y presionamos config.h, ahí tenemos que poner nombre de usuario de Adafruit IO en la sección de IO_USERNAME y la clave de Adafruit IO en la sección IO_KEY.

Ya que usamos unas placas de WIFI compatibles, aparece para modificar las opciones WIFI_SSID y WIFI_PASS en config.h. "Existen más opciones de conexión, pero como solo usaremos WIFI, esta es la que necesitamos".

Acá ejemplos de dónde debería ir lo que mencionamos:

![username ejemplo](./imagenes/usernameandkey.png)

![wifi contraseña ejemplo](./imagenes/wifipassword.png)

Los valores aparecen tanto en el monitor serial como en la sección de Feeds mientras que se cambia el color en el dashboard de Adafruit.

![valores serial monitor](./imagenes/serialmonitorrgb.png)

![valores feeds](./imagenes/valoresfeeds2.png)

## materiales usados en solemne-01

- 1x Arduino UNO R4 WiFi
- 1x LED RGB
- 1x Protoboard
- 3x Resistencias 220Ω
- 4x Cables dupont (m-m)

## código usado con Adafruit IO

### código para enviar

```cpp
// rellenar
```

### código para recibir

```cpp
// rellenar
```

## imágenes

![led a tiempo real](./imagenes/ledenclase.gif)

## investigaciones individuales

rellenar en el mismo orden que los integrantes del grupo

[persona-01.md](./persona-01.md)
[persona-02.md](./persona-02.md)
[persona-03.md](./persona-03.md)

## bibliografía

Adafruit. (s. f.). Adafruit IO. https://io.adafruit.com/

Surbyte. (2017). Arduino Forum. https://forum.arduino.cc/t/solucionado-ayuda-monitor-serial-con-caracteres-ilegibles/473044/5

MK Electrónica. (s. f.). Aprende a utilizar la plataforma Adafruit IO para tus dispositivos IoT. https://mkelectronica.com/aprende-a-utilizar-la-plataforma-adafruit-io-para-tus-dispositivos-iot-parte-1/

Adafruit. (s. f.). Adafruit IO Basics: Color. Adafruit Learning System. https://learn.adafruit.com/adafruit-io-basics-color
