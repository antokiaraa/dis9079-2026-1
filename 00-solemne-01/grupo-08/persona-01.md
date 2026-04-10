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
   
## sobre artista, diseñadora o producto que usa electrónica o computación inalámbricas

**DonkeyCar**

- Quise explorar en un ámbito que me llamase la atención de forma más personal, como algún sueño o fantasía que haya tenido cuando chico, descubrir cómo funcionan las cosas por dentro o cómo es que las cosas "viajan" por el aire. Es por ello que escogí un auto/vehículo que se pudiera manejar desde lejos

- Cuando chico siempre jugaba con autos a control remoto con mi hermano, me llamaban mucho la atención, sobretodo cuando juntábamos 2 del mismo modelo y hacían interferencia. Podías controlar el otro auto con otro control, se bugeaban harto y nunca entendí bien por qué pasaba. Busqué si los autos a control remoto comerciales de los años 90-2000 revelaban sus PCB para entender mejor el funcionamiento de ellos,pero en general no encontré mucho, tampoco encontré algún modelo específico que haya tenido cuando chico porque no me acuerdo de ningún nombre o modelo y lo más probable es que los hayan comprado mis papás en el líder o alguna tienda de un mall

- Lo que sí hallé fue un proyecto OpenSource que mezcla computación + electrónica + inalámbrico y lo bueno es que hay mucha información sobre este mismo

- Donkeycar es una biblioteca minimalista y modular de conducción autónoma para Python. Está desarrollada para aficionados y estudiantes, con un enfoque en permitir una experimentación rápida y facilitar las contribuciones de la comunidad. Se utiliza activamente a nivel de enseñanza media y universitaria para aprendizaje e investigación. Ofrece una interfaz gráfica completa e incluye un simulador para que puedas experimentar con conducción autónoma incluso antes de construir un robot.

- Con esta plataforma es posible conducir tu coche con tu teléfono o un portátil, grabar imágenes, ángulos de dirección y aceleraciones, y lo más interesante, entrenar a pilotos de redes neuronales para que conduzcan tu coche en diferentes pistas.

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

-  Python: No necesitas programar para usar Donkeycar. El archivo que editas para configurar tu auto, myconfig.py, es un archivo de Python. En la mayoría de los casos, solo tienes que descomentar las secciones que quieres modificar y editarlas. Puedes evitar errores comunes si entiendes cómo funcionan los comentarios y la indentación en Python

-  Raspberry PI: La Raspberry Pi es el computador principal recomendado para un Donkeycar. Es útil haberla configurado y utilizado antes, pero no es obligatorio. La documentación de Donkeycar explica cómo instalar el software en Raspberry Pi OS, pero los detalles específicos —como instalar el sistema usando Raspberry Pi Imager o configurar la Raspberry Pi con raspi-config— se dejan a la documentación oficial de Raspberry Pi, que es bastante completa y de buena calidad.

Se recomienda configurar tu Raspberry Pi usando esa documentación y luego experimentar un poco con ella

**Hardware**

- Lo primero es elegir un auto para poder desarrollar nuestro donkeycar, hay distintos modelos que nos recomiendan en la página. Está la opción de comprar uno que ya esté montado o montar uno nosotros mismos

- Un Donkeycar se puede construir a partir de casi cualquier auto a control remoto, sin embargo, si quieres seguir un camino más fácil, compra cualquiera de los autos WL Toys que se indican en la página, en este caso mostraré la documentación DIY del auto

- nos muestran que se pueden pedir las piezas impresas en 3d PLA y nosotros mismos las afinamos

![armado](./imagenes/donkeyArmado.JPG)

fuente: [donkey](https://docs.donkeycar.com/guide/build_hardware/)

- otro paso importantes es el uso de un servoShield que lo debemos conectar a la raspberry pi

- El controlador de servos PCA9685 puede controlar hasta 16 dispositivos PWM como servos, controladores de motor, LEDs o casi cualquier cosa que utilice una señal PWM. Se conecta a la Raspberry Pi (o Jetson Nano) mediante el bus GPIO de 40 pines a través de los pines I2C.

- no conocía este controlador en verdad, me sorprende harto que pueda mover tantos dispositivos pwm, brígido

![i2c](./imagenes/I2CPCA.jpg)

fuente: [digipart](https://www.digipart.com/part/PCA9685PW118?kw=PCA9685PW118&utm_source=bing&utm_medium=cpc&utm_campaign=Tier_F&utm_term=PCA9685PW118&utm_content=Tier_F_1)



**Software**
- debemos seguir una serie de pasos, lo primero es setear nuestra configuración según nuestro sistema operativo, en mi caso sería Windows
