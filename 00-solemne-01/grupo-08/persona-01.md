# persona-01

investigaciones individuales

## sobre adafruit i/o

- Instalación adafruit io 4 de abril (sacado de mi bitácora clase 4)

![instalacion](./imagenes/instalacionIndividual1.JPG)

- Primero descargamos la biblioteca de adafruit io en arduino

![instalacion](./imagenes/instalacionIndividual2.JPG)

- Nos aparece que incluye todas estas opciones, debemos aceptar

![instalacion](./imagenes/instalacionIndividual3.JPG)

- Así termina la instalación, luego creamos nuestra cuenta en Adafruit

![cuenta](./imagenes/creandoCuentabraulio.JPG)

- Creamos cuenta con nuestro correo, debiera aparecer un ícono amarillo arriba a la derecha, con mis credenciales, no me aparece nada

- Descargar los archivos .ino y .h que dejo aarón en mi respectivo grupo 08 en github

- Lo hice mal al principio, me dio este error

![error](./imagenes/error1config.JPG)

- Después me acordé que el archivo .h debía estar al lado del .ino en pestañas, es decir, tenían que estar en la misma carpeta lol. Esto lo aprendí el año pasado pero se me había olvidado, si no estaban de esta forma el arduino no iba a encontrar el .h por más que lo tuviera descargado

![solucionerror](./imagenes/solucionErrorbraulio1.jpg)

- Los puse en una misma carpeta, cerré arduino y lo abrí, ahora si me incluyó el .h

- Antes de esto había abierto el .h en vscode y se veía así

![vscode](./imagenes/configBraulio.JPG)

- Después caché que se abría en arduino e hice lo que mencioné anteriormente, reemplacé los enunciados IO USERNAME y IO KEY por VALORES SECRETOS

- Probé el código y compiló, no me apareció el error de conectando a Adafruit IOFirmware version 0.3.0 is outdated. Latest version is 0.5.2 21:24:06.104 -> Please upgrade the WiFiS3 firmware, CORREGIR QUE SÍ ME APARECIÓ ESTE ERROR PERO LO SOLUCIONAMOS CON AARÓN LA MAÑANA DEL 6 DE ABRIL

**investigación individual 6 de abril 11 am**

- Adafruit IO es un servicio en la nube, lo que significa que ellos lo gestionan por ti. puede ser utilizado estando conectado a Internet y usado principalmente para guardar y recuperar datos, pero también permite otras cosas

- Mostrar datos en tiempo real en línea
- Compartir datos con otras personas
- Conectar proyectos electrónicos a Internet
- Controlar motores o leer sensores
- Integrarse con servicios como Slack, Discord, RSS o clima
- Conectar dispositivos entre sí
- Crear proyectos sin código (no-code)

- Adafruit IO nos permite hacer proyectos con uso de código o sin uso de código, en este último caso, se utiliza un FirmWare llamado "WipperSnapper"

¿Cómo utilizar WipperSnapper? (no código)

- Se debe cargar el firmware WipperSnapper en la placa, agregar las credenciales y conectarla la alimentación. La placa se registrará automáticamente en la cuenta de Adafruit IO.

Código con adafruit IO

- Adafruit IO también se puede utilizar con código, tienen librerías de CircuitPython, Arduino, Python y más, en nuestro caso utilizaremos las librerías para arduino, específicamente Adafruit IO Arduino

- Información sacada de la página de adafruit io y traducida con IA

 **Proceso con Aarón 6 de abril a las 12 pm en LID**

- En la mañana aarón me dijo que revisara bien las credenciales porque vió mi clave y efectivamente no eran las credenciales exactas, la password era la que me da la página, no la que yo le asigno a mi cuenta

- Por obvios motivos no colocaré mis credenciales lol

- Al colocar correctamente las credenciales y el nombre y la clave del wifi también tuve que actualizar el firmware, ya que, al colocar las credenciales bien, el código funcionó entonces ahora daba el error de actualizar firmware, que era lo que precisamente tenía que suceder, actualizamos la placa y salió "mal" al principio

- La actualización decía que el proceso había fallado, aarón dijo que lo habíamos logrado de igual modo, presionamos el botón de reiniciar el arduino, seguían saliendo puntos, borramos los mensajes del monitor serial y apareció un nuevo mensaje

![falloylogro](./imagenes/falloylogroBraulio.JPG)

- Nos estábamos conectando a Adafruit IO, poco a poco comenzaron a aparecer estos mensajes

![enviandoada](./imagenes/enviandoAdafruitbraulio.JPG)

 *SENTIMOS LOS ESCALOFRÍOS*

- Luego aarón me dijo que abriera la página de adafruit io, nos fuimos a la parte de io, luego feeds y se había creado solo un feed llamado "grupo08", esto es porque en una parte del código asignamos ese nombre al grupo, por lo que, adafruit io lo detecta y lo crea solo

![adafruit](./imagenes/servidorAdafruitbraulio2.JPG)

- Esto muestra un gráfico con datos en tiempo real que están siendo enviados desde nuestro arduino hacia adafruit IO

![adafruit2](./imagenes/servidorAdafruitbraulio.JPG)

- Aquí vemos en detalle los datos que nos está enviando arduino, estos pueden aparecer por un largo periodo de tiempo, en este caso lo dejé toda la hora de almuerzo enviando datos y cuando volví, el proceso había llegado aprox hasta el dato 2600. Después de eso se detuvo, las cosas se crashean

- En clases lunes 6: anotar todos los errores y aciertos, cada paso específico que hicimos, prendimos el botón no se cuántas veces? reiniciamos, desconectamos, cerramos arduino, desconectamos la placa

**avance lid 8 de abril**

- Junto con Luisa pensábamos en las siguientes opciones:

- Ver si se puede enviar un mensaje de monitor serial desde un arduino a otro en distinto computador, después, el que recibió ese mensaje lo envía a adafruit IO

- Opción 2, prender un led desde un arduino al led de otro arduino en computadores distintos, cada vez que reciba un número el led parpadea

- Opción 3 enviar números desde un arduino hacia la otra pantalla del otro arduino, que se dibujen los números cada vez que lo reciba, un contador

- Para enviar y recibir en distintos arduinos, ambos deberían estar utilizando las mismas credenciales, no sé si es necesario que estén en el mismo wifi

- Dashboard es como la forma en la que eliges el cómo manejar el dato, feed es a dónde llegan esos datos, algo así le entendí a Vania cuando me explicó

- Descargar el archivo de recibir desde la página de adafruit, vania me ayudó, tengo dudas sobre cómo encontrar el config.h que debiera venir

- Vania puso el mismo config.h que mandó aarón, al final incluye los seteos para el wifi y usuarios, más que nada es para eso

- Al final el archivo config.h sí estaba en la librería de adafruit en github, tenía unos ajustes pequeños entonces se descargó ese para ponerlo en la carpeta del archivo recibir

- Comunicar entre arduinos, uno envía, el otro recibe, el mensaje se traduce y se transforma en algo, cómo???

## sobre artista, diseñadora o producto que usa electrónica o computación inalámbricas

**DonkeyCar**

- Quise explorar en un ámbito que me llamase la atención de forma más personal, como algún sueño o fantasía que haya tenido cuando chico, descubrir cómo funcionan las cosas por dentro o cómo es que las cosas "viajan" por el aire. Es por ello que escogí un auto/vehículo que se pudiera manejar desde lejos

- Cuando chico siempre jugaba con autos a control remoto con mi hermano, me llamaban mucho la atención, sobretodo cuando juntábamos 2 del mismo modelo y hacían interferencia. Podías controlar el otro auto con otro control, se bugeaban harto y nunca entendí bien por qué pasaba. Busqué si los autos a control remoto comerciales de los años 90-2000 revelaban sus PCB para entender mejor el funcionamiento de ellos,pero en general no encontré mucho, tampoco encontré algún modelo específico que haya tenido cuando chico porque no me acuerdo de ningún nombre o modelo y lo más probable es que los hayan comprado mis papás en el líder o alguna tienda de un mall

- Lo que sí hallé fue un proyecto OpenSource que mezcla computación + electrónica + inalámbrico y lo bueno es que hay mucha información sobre este mismo

- La información a continuación está sacada directamente de la página y traducida con ChatGPT, también hay parafraseos de mi parte y reflexiones

- Fue desarrollado por Will Roscoe y Adam Conway entre 2016-2017, luego se fueron sumando más personas al equipo como Tawn Kramer y Dirk Prange

- Donkeycar es una biblioteca minimalista y modular de conducción autónoma para Python. Está desarrollada para aficionados y estudiantes, con un enfoque en permitir una experimentación rápida y facilitar las contribuciones de la comunidad. Se utiliza activamente a nivel de enseñanza media y universitaria para aprendizaje e investigación. Ofrece una interfaz gráfica completa e incluye un simulador para que puedas experimentar con conducción autónoma incluso antes de construir un robot

- Con esta plataforma es posible conducir tu coche con tu teléfono o un portátil, grabar imágenes, ángulos de dirección y aceleraciones, y lo más interesante, entrenar a pilotos de redes neuronales para que conduzcan tu coche en diferentes pistas

![donkeycar](./imagenes/donkeycar2.png)

fuente: [donkeycar](https://github.com/autorope/donkeycar?tab=readme-ov-file)

![donkeycargif](./imagenes/donkeycargif.gif)

fuente: [donkeycarniubit](https://niubit.es/proyectos/97-open-source/106-donkey-car)

- La página de [donkeycar](https://docs.donkeycar.com/) es muy completa porque nos ofrece el paso a paso sobre cómo construir nuestro propio vehículo tanto en ámbito de hardware como software

- Incluyen una lista de cosas que necesitamos, igual es medio caro si

![donkey3](./imagenes/donkey3.JPG)

fuente: [docs.donkeycar](https://docs.donkeycar.com/)

- Subiré documentación sobre cómo armar nuestro propio donkeycar y parte de su funcionamiento

¿Qué se necesita para empezar?

- Donkeycar está diseñado como el “Hola Mundo” de la conducción autónoma; es simple, pero a la vez flexible y potente. No se requiere ningún conocimiento previo específico, aunque ayuda tener nociones de:

- Python: No necesitas programar para usar Donkeycar. El archivo que editas para configurar tu auto, myconfig.py, es un archivo de Python. En la mayoría de los casos, solo tienes que descomentar las secciones que quieres modificar y editarlas. Puedes evitar errores comunes si entiendes cómo funcionan los comentarios y la indentación en Python

- Raspberry PI: La Raspberry Pi es el computador principal recomendado para un Donkeycar. Es útil haberla configurado y utilizado antes, pero no es obligatorio. La documentación de Donkeycar explica cómo instalar el software en Raspberry Pi OS, pero los detalles específicos —como instalar el sistema usando Raspberry Pi Imager o configurar la Raspberry Pi con raspi-config— se dejan a la documentación oficial de Raspberry Pi, que es bastante completa y de buena calidad

Se recomienda configurar tu Raspberry Pi usando esa documentación y luego experimentar un poco con ella

### Hardware

- Lo primero es elegir un auto para poder desarrollar nuestro donkeycar, hay distintos modelos que nos recomiendan en la página. Está la opción de comprar uno que ya esté montado o montar uno nosotros mismos

- Un Donkeycar se puede construir a partir de casi cualquier auto a control remoto, sin embargo, si quieres seguir un camino más fácil, compra cualquiera de los autos WL Toys que se indican en la página, en este caso mostraré la documentación DIY del auto

- Nos muestran que se pueden pedir las piezas impresas en 3d PLA y nosotros mismos las afinamos

![armado](./imagenes/donkeyArmado.JPG)

fuente: [donkey](https://docs.donkeycar.com/guide/build_hardware/)

- Otro paso importantes es el uso de un servoShield que lo debemos conectar a la raspberry pi

- El controlador de servos PCA9685 puede controlar hasta 16 dispositivos PWM como servos, controladores de motor, LEDs o casi cualquier cosa que utilice una señal PWM. Se conecta a la Raspberry Pi (o Jetson Nano) mediante el bus GPIO de 40 pines a través de los pines I2C

- No conocía este controlador en verdad, me sorprende harto que pueda mover tantos dispositivos pwm, brígido

![i2c](./imagenes/I2CPCA.jpg)

fuente: [digipart](https://www.digipart.com/part/PCA9685PW118?kw=PCA9685PW118&utm_source=bing&utm_medium=cpc&utm_campaign=Tier_F&utm_term=PCA9685PW118&utm_content=Tier_F_1)

- Este es el pinout sobre cómo debemos conectar el I2CPCA a la Raspberry Pi

![pinout](./imagenes/pinoutRaspiI2CP.png)

- Después de tener esto listo, debemos montar sobre la carcasa del auto, nos dan la opción de agregar una cámara, la Raspberry PI debe quedar conectada cerca del controlador de servos

**Software**

- Debemos seguir una serie de pasos, lo primero es setear nuestra configuración según nuestro sistema operativo, en mi caso sería Windows

![software](./imagenes/softwareInstalacion.JPG)

- Debemos seguir estos 2 pasos que nos indican

- Estableceremos una serie de pasos en Raspi pero sólo dejaré el primero porque la documentación es demasiado extensa

 ![raspi](./imagenes/raspiSetup.JPG)

- Los componentes de software de Donkeycar deben instalarse en la plataforma robótica que elijas. Raspberry Pi y Jetson Nano cuentan con documentación de instalación, pero también se sabe que funciona en Jetson TX2, Friendly Arm SBC o casi cualquier SBC (computador de placa única) basado en Debian

- Después de la instalación, crearás la aplicación de Donkeycar a partir de una plantilla. Esta contiene código diseñado para que lo personalices según tu caso particular. No te preocupes, comenzaremos con configuraciones predeterminadas útiles

**Crear la aplicación del auto**

- Hay dos formas de configurar Donkeycar, ambas crean un archivo personalizado myconfig.py que tendrás en tu directorio mycar

- La primera es la más fácil: utiliza el configurador web y simplemente recorre las pestañas seleccionando las opciones necesarias según tu configuración

- Para la mayoría de las personas, la primera pestaña (Hardware) es suficiente para confirmar qué tipo de tren de tracción y qué joystick/control estás usando

- Luego guarda el archivo myconfig.py generado en tu computador y transfiérelo a tu Raspberry Pi usando tu aplicación de transferencia FTP favorita, como FileZilla

- Si está utilizando una placa controladora de servos PCA9685, asegúrese de poder verla en I2C

- Existe una serie larga de pasos adicionales que no añadiremos para ir a explicar cómo se maneja el auto

**Manejar el auto**

- Coloca tu auto en un lugar seguro donde las ruedas no toquen el suelo

- Este es el momento en que el auto puede salir disparado

- Abre la carpeta de tu auto e inícialo:

- cd ~/mycar
- python manage.py drive

- Este script iniciará el ciclo de conducción de tu auto, que incluye un componente que actúa como servidor web para que puedas controlarlo

- Ahora puedes controlar tu auto desde un navegador web en la dirección:
- <nombre-de-tu-auto.local>:8887

- Lo que entiendo, con mis palabras, es que dentro de la raspi que está conectada a wifi, existe un servidor web en el que tenemos iniciado nuestro código de python,en el cuál podríamos cambiar ciertos parámetros, al conectarnos a este servidor web y abrir la carpeta del auto en python, podemos manejarlo, la verdad es muy complejo de entender. Se parece a cuando intentamos establecer conexión con el mqtt de raspi, conectábamos raspi a wifi, dentro de ese raspi estaba el servidor mqtt con un cierto seteo, es algo parecido lo que imagino

![seteo](./imagenes/manejarDonkey.JPG)

- nos muestran esta aplicación, que por lo que entiendo, es la que creamos y está dentro del servidor en la Raspi

- nos dan opciones para manejar nuestro auto, el foro dice que hay 3 formas de mover el vehículo en el controlador web que tenemos:

- Inclinación del dispositivo (Device Tilt)

- Selecciona Device Tilt en la sección Control Mode del controlador web. Luego selecciona User en la sección Mode

Después puedes inclinar tu teléfono:

- hacia adelante → aumenta la aceleración
- de lado a lado → gira la dirección

  Joystick

- Selecciona Joystick en la sección Control Mode del controlador web. Luego selecciona User en la sección Mode

- Aparecerá un joystick virtual que puedes usar tocando y arrastrando:

- hacia arriba → acelera
- hacia abajo → disminuye o retrocede
- hacia la izquierda → gira a la izquierda
- hacia la derecha → gira a la derecha

- Al soltar el dedo, el auto se detiene.

 Control (Gamepad)

- Si tienes un control conectado (por cable o Bluetooth) al dispositivo desde el que estás viendo la interfaz web, y es compatible con la API de Gamepad de HTML5, puedes seleccionarlo

- Selecciona Gamepad en Control Mode y luego User en Mode.

- Después podrás manejar el Donkeycar usando el control.

- Por lo que entiendo y leo, todas estas opciones de manejo están dentro del controlador web que creamos anteriormente. Creo que el proyecto es muuuy complejo, de lo que leí entendí poco y me faltaron hartos pasos por documentar porque es demasiada información, es el proyecto más extenso que he visto en verdad, me gustaría en algún momento poder hacer algo así

links utilizados:

- [donkeycar](https://docs.donkeycar.com/)
- [niubit](https://niubit.es/proyectos/97-open-source/106-donkey-car)
- [github](https://github.com/autorope/donkeycar?tab=readme-ov-file)
