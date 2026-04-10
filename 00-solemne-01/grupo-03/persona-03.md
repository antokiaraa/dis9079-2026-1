# persona-03

- angel-udp

investigaciones individuales

## sobre adafruit i/o

Buenas Profesor, el día de hoy falté a clase por temas personales y de salud, estoy leyendo la carpeta de solemne 01 y poniendome al dia con mis compañeros de grupo

Por lo que veo usaremos Adafruit IO para realizar la solemne 01

Adafruit es una plataforma en la nube para el internet de las cosas en donde se pueden enviar datos con Arduino, entre otros. Donde permite guardarlos, visualizarlos y controlar cosas remotamente.

Los feeds son el núcleo del sistema donde se almacenan y transmiten los datos entre el dispositivo y la nube. En este se pueden poner paneles visuales para mostrar datos y usar bloques como gráficos, botones, medidores.

Es compatible con Arduino y Raspberry Pi, lo que es adecuado para lo que estamos usando ahora mismo en el curso.

Contiene botones remotos bidireccionales donde se pueden apagar, encender cosas y enviar comandos.

Guarda el historial de datos, pueden descargarse y también compartirse.

**Siguiendo los pasos dados en la carpeta Solemne-01**

- Arduino IDE ya estaba instalado previamente en mi computadora por las clases anteriores asi que pase directamente con la instalación de Adafruit IO para Arduino

![instalación 1](./imagenes/instalacion1.png)

- Y luego se terminaron de instalar todas las bibliotecas que nesecitaba

- en lo que se descargaban las bibliotecas me cree la cuenta en Adafruit https://io.adafruit.com/ con mi correo UDP
 
![instalación 2](./imagenes/instalacion2.png)

y al terminar la instalación revise las anotaciones de mis compañeros de grupo para ponerme al día con lo que no alcancé a ver hoy en clases y les preguntaré en persona para incorporar mejor los aprendizajes como por ejemplo: el código de arduino en las líneas donde debe ir el username, la active key, mi WiFi y la contraseña del código.

---

Como el arduino y la raspberry las tienen mis compañeros decidí preguntarles y hechar un vistazo a los avances que hicieron en clase para cambiar el Led RGB por medio de la página de Adafruit, por ende tambien daré mi punto de vista y entendimiento del proyecto con la ayuda de la página donde se siguieron los pasos: [en esta página](https://learn.adafruit.com/adafruit-io-basics-color/adafruit-io-setup)

Lo primero que dice es que se debe iniciar seción en Adafruit y guardar la llave de activación

a continuacón se comienza con la **Creación del flujo de color**

Empezamos creando la Feed llamandola color y para eso vi como crear feeds como verán en las siguientes imágenes

![feed1](./imagenes/crearfeed1.png)

![feed2](./imagenes/crearfeed2.png)

![feed3](./imagenes/crearfeed3.png)

Luego procedemos a crear el bloque de color y es importante saber como es el funcionamiento de la págino osino puede ser algo confuso llegar hasta el lugar deseado, lo bueno es que tiene un tutorial y es facil de seguir paso a paso

![bloque de color](./imagenes/bloquecolor.png)

a continuación se nos muestra como proceder con el alambrado con las siguientes piezas:

- 1x Feather compatible con Adafruit IO 
- 1 LED RGB difuso - ánodo común 
- 3 resistencias de 560 ohmios 
- 4 cables de puente

Y los nuestros en realidad son:

- 1x Arduino UNO R4 WiFi
- 1x LED RGB
- 1x Protoboard
- 3x Resistencias 220Ω
- 4x Cables dupont (m-m)

![imágen led rgb](./imagenes/ledrgb.png)

y se pasa al cableado del Arduino, como tengo la protoboard y jumpers pero no los resistores o el led RGB pondré la imágen de referencia del turorial que es con otra placa diferente a la de arduino y la imagen en físico de mi compañera antonella de como se ve conectado:

![Ejemplo de placa Feather ESP8266](./imagenes/placafeatheresp8266.png)

![LED morado físico](./imagenes/ledmorado.jpg)

Es importante lueg tener conexión a wifi con arduino además de asegurarse de tener instalada al menos la versión 2.4.0 de la biblioteca Adafruit IO Arduino.

como no me apareceran las opciones al no tener el arduino sigo dejando las indicaciones del tutoriasl para conectar devidamente

![Ejemplo de tutorial](./imagenes/configarduino.png)

**Código Arduino**

Y para finalizar te presentan los códigos de Arduino, recordar que para esta caso de mi investigación el circuito está hecho con una placa distinta aunque funciona de igual manera con la que tenemos:

En este caso el ejemplo adafruitio_13_rgb utiliza los pines 4, 5 y 2 para los colores rojo, verde y azul por defecto. Estos pines se pueden modificar cambiando las definiciones RED_PIN , GREEN_PIN y BLUE_PIN . Deberá seleccionar pines de su placa que admitan salida PWM.

```
<font dir="auto" style="vertical-align: inherit;"><font dir="auto" style="vertical-align: inherit;">/************************ El ejemplo comienza aquí *******************************/ </font></font>
<font dir="auto" style="vertical-align: inherit;"><font dir="auto" style="vertical-align: inherit;">
// Pines PWM predeterminados para ESP8266. </font></font><font dir="auto" style="vertical-align: inherit;"><font dir="auto" style="vertical-align: inherit;">
// Debes cambiarlos para que coincidan con los pines PWM de otras plataformas. </font></font><font dir="auto" style="vertical-align: inherit;"><font dir="auto" style="vertical-align: inherit;">
#define RED_PIN 4 </font></font><font dir="auto" style="vertical-align: inherit;"><font dir="auto" style="vertical-align: inherit;">
#define GREEN_PIN 5 </font></font><font dir="auto" style="vertical-align: inherit;"><font dir="auto" style="vertical-align: inherit;">
#define BLUE_PIN 2</font></font>
```

El siguiente fragmento de código configura una instancia del flujo de color .

```
<font dir="auto" style="vertical-align: inherit;"><font dir="auto" style="vertical-align: inherit;">// Configurar el feed 'color' </font></font><font dir="auto" style="vertical-align: inherit;"><font dir="auto" style="vertical-align: inherit;">
AdafruitIO_Feed *color = io.feed("color");</font></font>
```

En la función de configuración, nos conectamos a Adafruit IO y adjuntamos una función llamada handleMessage al flujo de color . Esta función se llamará cada vez que su dispositivo reciba mensajes para ese flujo.

El código esperará hasta que tengas una conexión válida a Adafruit IO antes de continuar con el programa. Si tienes algún problema de conexión, revisa el archivo config.h para comprobar si hay algún error tipográfico en tu nombre de usuario o clave.

```
void setup() {

  // start the serial connection
  Serial.begin(115200);

  // wait for serial monitor to open
  while(! Serial);

  // connect to io.adafruit.com
  Serial.print("Connecting to Adafruit IO");
  io.connect();

  // set up a message handler for the 'color' feed.
  // the handleMessage function (defined below)
  // will be called whenever a message is
  // received from adafruit io.
  color->onMessage(handleMessage);

  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());

  // set analogWrite range for ESP8266
  #ifdef ESP8266
    analogWriteRange(255);
  #endif

}
```

A continuación, tenemos la función principal. La primera línea de la función de bucle debe estar presente al principio de cada bucle. Ayuda a mantener el dispositivo conectado a Adafruit IO y procesa los datos entrantes.loop()io.run();

```
void loop() {

  // io.run(); is required for all sketches.
  // it should always be present at the top of your loop
  // function. it keeps the client connected to
  // io.adafruit.com, and processes any incoming data.
  io.run();
  
}
```

El último fragmento de código es la función handleMessage . Esta función se llama cada vez que la fuente de color recibe un mensaje.

Utilizamos las funciones data->toRed() , data->toGreen() y data->toBlue() para convertir los valores de color hexadecimales entrantes a enteros que serán compatibles con analogWrite .

```
// this function is called whenever a 'color' message
// is received from Adafruit IO. it was attached to
// the color feed in the setup() function above.
void handleMessage(AdafruitIO_Data *data) {

  // print RGB values and hex value
  Serial.println("Received:");
  Serial.print("  - R: ");
  Serial.println(data->toRed());
  Serial.print("  - G: ");
  Serial.println(data->toGreen());
  Serial.print("  - B: ");
  Serial.println(data->toBlue());
  Serial.print("  - HEX: ");
  Serial.println(data->value());

  // invert RGB values for common anode LEDs
  analogWrite(RED_PIN, 255 - data->toRed());
  analogWrite(GREEN_PIN, 255 - data->toGreen());
  analogWrite(BLUE_PIN, 255 - data->toBlue());

}
```

Se sube el código a la placa y se abre el monitor serie arduino

```
Connecting to Adafruit IO....

Adafruit IO connected.
```

Ahora se puede ver el bloque de color y debería verse el bloque en el monitor serie de Arduino

```
Received:
  - R: 0
  - G: 0
  - B: 0
  - HEX: #000000
Received:
  - R: 210
  - G: 31
  - B: 31
  - HEX: #d21f1f
```

Y listo cambiandolo desde el bloque de color tambien debería verse en el led como cambia segun el color selecionado.

## sobre artista, diseñadora o producto que usa electrónica o computación inalámbricas

Para esta bitácora quise investigar el trabajo de Rafael Lozano-Hemmer, porque me llamó la atención cómo mezcla el arte con la tecnología, especialmente con sistemas electrónicos y redes inalámbricas.

Al principio pensé que iba a ser más técnico, pero su enfoque va por el lado de la interacción con las personas.

Lo que hace este artista es crear instalaciones donde el público participa directamente, y muchas veces esas obras funcionan gracias a sensores, cámaras, luces y conexiones a internet, conexiones como las que hacemos con

- arduino

- raspberry pi.

Por ejemplo, en varias de sus obras usa dispositivos que captan señales del cuerpo, como el pulso o la presencia de una persona, y eso se transforma en algo visual o sonoro, algo tipo visualización de datos.

También trabaja mucho con datos en tiempo real, lo que implica el uso de redes inalámbricas para enviar y recibir información constantemente del entorno.

Mostrando luces, proyecciones o algo que tenga una estructura digital pensada de fondo, dependiendo de lo que conviva con el proyecto se muestra uno o otro resultado, haciendolo más interesante para el público. 

Sus obras cambian dependiendo de quién las use o cuántas personas participen, y al final me quedo con esta idea de que no solo se usan redes inalámbricas o Arduino para proyectos técnicos, sino que también, visto desde una forma artística, se pueden usar para interactuar con las personas, tal y como se hace con el diseño.

![Foto Rafael Lozano](./imagenes/rafael.png)

**Bibliografía**

- Ars Electronica. (s.f.). Rafael Lozano-Hemmer y arte interactivo. Recuperado de: https://ars.electronica.art

- Museum of Modern Art (MoMA). (s.f.). Rafael Lozano-Hemmer. Recuperado de: https://www.moma.org

- Rafael Lozano-Hemmer. (s.f.). Sitio oficial. Recuperado de: https://www.lozano-hemmer.com

- Tate. (s.f.). Artistas: Rafael Lozano-Hemmer. Recuperado de: https://www.tate.org.uk
