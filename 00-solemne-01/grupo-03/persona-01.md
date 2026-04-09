# persona-01

- antokiaraa

investigaciones individuales

## sobre adafruit i/o

Instalación y configuración:

Paso 1: en Arduino IDE busqué la biblioteca Adafruit IO Arduino y la instalé junto con sus dependencias

![instalar biblioteca](./imagenes/biblioteca_adafruit.png)

Paso 2: descargué el código subido en la carpeta de mi grupo "enviarGrupo03" y su .h

Paso 3: me creé una cuenta en <https://io.adafruit.com/> con mi correo UDP y desde ahí copié mi username y la active key

Paso 4: en el código de arduino modifiqué las líneas donde debe ir el username, la active key, mi WiFi y la contraseña, verificando que el arduino esté conectado mandé el código

Error 1: compiló pero en el serial monitor me daba un cáracter raro, lo busqué y encontré [en esta página](https://forum.arduino.cc/t/solucionado-ayuda-monitor-serial-con-caracteres-ilegibles/473044/5) que el número del serial begin debe coincidir con la cantidad de baudios (bits por segundo) en el serial monitor

![error por baudios](./imagenes/error1_baud.png)

Aquí lo edité: 

![baudios solucionado](./imagenes/solucionado_baud.png)

Teniendo eso solucionado lo volví a enviar el código

Error 2: acá me estanqué un rato porque el serial monitor solo me tiraba "............" pero ningún mensaje, hasta que luego de un rato probando me apareció este mensaje y efectivamente como dijo Aaron me daba el error por el firmware del arduino, también me costó actualizarlo porque daba error y se quedaba pegada la aplicación, pero lo terminé solucionando solamente intentando de nuevo actualizarlo

![error por firmware](./imagenes/error2.png)

![actualizando firmware](./imagenes/actualizarfirmware.png)

Error 3: luego de solucionar esto volví a intentarlo pero me seguía dando los puntitos "....." por lo que averigüé es que el arduino está tratando de entrar al WiFi pero no lo logra, por lo que utilicé el hotspot de mi celular porque el iPhone tiene una opción de "máxima compatibilidad" para que pueda conectarse ya que sin eso estaria en 5Ghz y el arduino opera en 2.4GHz

Con esto solucionado vuelvo a tirar el código al arduino y funciona!

![valores en serial monitor](./imagenes/serialmonitor1.png)

Empezaron a aparecer los números en la sección "Feeds" en la página de Adafruit IO y viendo cómo funciona el dashboard creé uno con un block de "streams" para que ahi se puedan ir viendo los valores que envía el arduino, como la página de Adafruit estaba en inglés me guié de [esta página](https://mkelectronica.com/aprende-a-utilizar-la-plataforma-adafruit-io-para-tus-dispositivos-iot-parte-1/) para ir entendiendo cómo funcionaban 

![valores en feeds](./imagenes/valorfeed.png)

Así se ve en el Dashboard que creé: 

![streams en dashboard](./imagenes/dashboardstreams.png)

Como fue tan increíble decidí probar [este tutorial](https://learn.adafruit.com/adafruit-io-basics-color) que estába en la página de Adafruit que enviaron , que es sobre cómo controlar un LED RGB!

Seguí paso a paso las instrucciones, busqué en los ejemplos de la biblioteca de Adafruit el número 13 que es el que tiene el código para el RGB:

![ejemplo 13 rgb](./imagenes/example13.png)

Luego vi cómo se debian hacer las conecciones entre el LED y el arduino, fue fácil porque ya lo había hecho antes y tenía los materiales, así se veía conectado y tocaba probarlo

![LED conectado a arduino](./imagenes/circuitoled.jpg)

Como seguí el tutorial acá ya tenia hecho el dashboard con la rueda de color, al tirar el código al arduino todo funcionó correctamente y desde la página podia controlar el color del LED, lo puse morado que lindo me encantó

![rueda de color en dashboard](./imagenes/dashboardrgb.png)

Así se veía el LED en físico ya con el color:

![LED morado físico](./imagenes/ledmorado.jpg)

Los valores se muestran en el serial monitor y en la sección de Feeds según se vaya modificando el color en el dashboard

![valores serial monitor](./imagenes/serialmonitorrgb.png)

![valores feeds](./imagenes/valoresfeeds2.png)

## sobre artista, diseñadora o producto que usa electrónica o computación inalámbricas

Elegí investigar a Rafael Lozano-Hemmer, nacido en México en 1967, es un artista electrónico reconocido por sus instalaciones interactivas a gran escala. Se graduó en Química Física en la Universidad de Concordia en Montreal, Canadá. Desde finales de la década de 1990, ha desarrollado el concepto de "arquitectura relacional", que se centra en el uso de la tecnología para transformar espacios públicos y fomentar la interacción entre las personas y su entorno. 

A lo largo de su carrera ha representado a México en eventos internacionales como la Bienal de Venecia (2007) y sus obras forman parte de colecciones en museos como el MoMA en Nueva York, la Tate en Londres y el Museo Reina Sofía en Madrid. Su trabajo se caracteriza por el uso de robótica, proyecciones digitales, sensores biométricos y redes de comunicación para crear experiencias en conjunto con el espectador mediante sus datos o movimientos.

Me llamó la atención su proyecto "Cloud Display", es una instalación que lo que hace es unir la mecánica de el vapor del agua con el procesamiento de datos en tiempo real. Se trata de una pantalla efímera compuesta por una matriz de 1600 boquillas de ultrasonido que generan una fina niebla de agua. Cuenta con un sistema de reconocimiento de voz y cuando el participante habla frente a un micrófono, utiliza una forma de machine learning para convertir esa voz en texto y este se envía inalámbricamente a un controlador que activa las boquillas de vapor para "escribir" la palabra en el aire.

Es muy interesante la sincronía lograda, el código no solo procesa la voz humana en tiempo real, sino que coordina a 1600 actuadores físicos para que el vapor de agua se comporte como una pantalla de texto legible y logra dar a entender que las máquinas dejen de ser simples herramientas para convertirse en extensiones de nuestra propia presencia en el espacio.

![obra cloud display](./imagenes/clouddisplay.jpg)

### Bibliografía

Lozano-Hemmer, R. (2019). Cloud Display. https://www.lozano-hemmer.com/cloud_display.php

Lozano-Hemmer, R. (s. f.). Biography. https://www.lozano-hemmer.com/bio.php

Wikipedia. (2026). Rafael Lozano-Hemmer. https://es.wikipedia.org/wiki/Rafael_Lozano-Hemmer

Roulx, O. (2019). Atmospheric Memory by Rafael Lozano-Hemmer: Cloud Display. Enki Magazine. https://enkimagazine.com/atmospheric-memory-hybrid-exhibition-merging-art-and-science/atmospheric-memory-by-rafael-lozano-hemmer-cloud-display-10-2019-at-unc2021-photo-by-olivier-groulx/
