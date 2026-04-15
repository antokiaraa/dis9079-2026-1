# sesion-03

lunes 23 marzo 2026

# Idea general

En esta clase empezamos a entrar más directamente al trabajo con microcontroladores y microcomputadores, especialmente con Raspberry Pi Pico 2 W. La diferencia principal que apareció fue que no todos estos dispositivos funcionan igual ni tienen la misma capacidad: algunos son más simples y acotados, y otros permiten hacer proyectos más complejos.

## Raspberry Pi Pico 2 W 
  
**Arduino**: mini controlador = lento   
Arduino se entiende más como un microcontrolador. Es pequeño, útil para tareas específicas y directas, como leer sensores, activar luces o controlar elementos simples. En comparación con otros sistemas, funciona de manera más limitada.
 
**Rasperry Pi**: Computadores = brutal propio chip  
Raspberry Pi, en cambio, se acerca más a la lógica de un microcomputador. Tiene más potencia, más posibilidades de procesamiento y permite trabajar proyectos más amplios. La idea general es que Raspberry Pi no solo ejecuta una acción puntual, sino que puede sostener sistemas más complejos. 
En el caso de la Raspberry Pi Pico 2 W, se trabaja con una placa pequeña, pero con mayores capacidades que un microcontrolador muy básico, además de incorporar posibilidades de conectividad inalámbrica.

<ins> **Ref Rasperry pi** </ins>  

**Monome**: Aparece como referente dentro de instrumentos y dispositivos digitales experimentales, muy ligado a interacción, música y control en tiempo real. 
 
**Critter and guitari**: También se mencionó como referencia de dispositivos orientados a exploración sonora, instrumentos digitales y experiencias audiovisuales. 

**otros microcontroladdores y microcomputadores**   
 
**BeagleBoard**: Otra plataforma de hardware. La idea es entender que existen otras alternativas además de Arduino y Raspberry Pi, con distintos enfoques y comunidades. 
 
**Bela Platform**: Se nombró como una plataforma especialmente orientada al audio y a proyectos donde importa mucho la respuesta en tiempo real. O sea, no es solo una placa “general”, sino una tecnología muy pensada para sonido e interacción. 

**NIME**: es una referencia importante para investigar. Es un espacio donde hay papers, proyectos y desarrollos sobre nuevas interfaces para expresión musical. Sirve como fuente para entender investigaciones y experimentos relacionados con sonido, interacción y tecnología. 

**Electro-Smith**: Otra referencia vinculada a hardware para proyectos sonoros y experimentales. 

**Daisy / Daisy Seed**: Se mencionó como un microcontrolador muy usado en proyectos de audio, síntesis y experimentación sonora. La idea general es que funciona como una base potente para construir instrumentos, efectos y dispositivos de sonido. 
 
### prefijos del Sistema Internacional (SI) 

nombrar cantidades muy grandes o muy pequeñas sin escribir tantos ceros  
ej: 
10⁻⁶ = micro 
significa una millonésima parte
1 μm = 0,000001 m

Esto es importante porque en computación, electrónica y señales se usan mucho escalas de tiempo, voltaje, memoria o distancia que necesitan este tipo de abreviaciones.

<ins> **Visual Code Studio y Raspberry Pi** </ins>

**Versión a usar**: 2.2.0 (puede cambiar durante el semestre)  
**studio support**: pedirle console over usb para que funcione  
**pico wireless options**: pico w onboard led 

## Lenguajes y herramientas que aparecieron

**C++**
Se entiende como uno de los lenguajes principales para trabajar con la Raspberry Pi Pico desde este entorno.

**Rust**
Se comentó como un lenguaje que algunas personas impulsan como alternativa a C++, especialmente porque se considera más seguro en ciertos aspectos.

**Python**
Apareció como lenguaje ampliamente usado en computación.

**MicroPython**
Se mencionó como una versión más simple o más amigable para trabajar en microcontroladores. Puede ser útil para entrar más fácil al trabajo con placas y prototipos.

**Claude Code**
Se nombró como una IA pensada para generar código, o por lo menos ayudar en procesos de programación.

**Extensions**
En Visual Studio Code, las extensions son el espacio donde se descargan herramientas adicionales para ampliar funciones del programa.

## Comenzando Raspberry Pi 

Apareció la idea de que en Raspberry Pi gran parte del programa ocurre dentro de main.
O sea, lo que está dentro de main es lo que efectivamente va ocurriendo en la ejecución principal del código.  

stdio_init_all();
Sirve para inicializar la entrada y salida estándar. habilitar la comunicación básica del sistema.

while (true) { }
Es un bucle infinito. Mientras la condición sea verdadera, el programa sigue ejecutando lo que esté dentro.

Raspberry Pi Pico 2 W no solo como una placa, sino como parte de un ecosistema más grande de hardware, programación y comunicación entre dispositivos. También sirvió para distinguir entre microcontroladores y microcomputadores, conocer otras plataformas relacionadas con sonido e interacción, y empezar a familiarizarse con la configuración técnica en Visual Studio Code.


**Archivos**

Se mencionó que es importante trabajar con archivos tipo .cpp, ya que corresponden al lenguaje C++ en este entorno.

