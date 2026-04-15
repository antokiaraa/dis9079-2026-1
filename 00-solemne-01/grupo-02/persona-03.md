# persona-03 (carlita)

investigaciones individuales

## sobre adafruit i/o

¿what exactly is adafruit IO?

+ Adafruit IO es un servicio en la nube de Adafruit para crear proyectos de Internet de las cosas (IoT). Permite a los usuarios conectar, monitorear y controlar dispositivos y sensores IoT en línea sin escribir una sola línea de código.
+ Adafruit IO también ofrece recursos y tutoriales para ayudar a los usuarios a iniciar sus proyectos de IoT. Incluyendo bibliotecas para lenguajes como CircuitPython, Arduino, Python y más, lo que simplifica la integración de dispositivos.
+ Con su interfaz fácil de usar y su extensa documentación, Adafruit IO es la forma más sencilla de transmitir, registrar e interactuar con sus datos.

---

+ dashboard: es la parte visual, puedes arrastrar y soltar bloques (gráficas, botones, mapas, deslizadores) para crear tu propia interfaz de control sin saber programar diseño web
+ feed: es donde se guarda la información, el "feed" es como una pequeña base de datos para un solo sensor
+ nube: servidor de adafruit que gestiona los feeds que son canales de datos
+ hardware: arduino r4 wifi se conecta al router local para escuchar los cambios en la nube
+ algunas librerias importantes: Adafruit IO Arduino, Adafruit MQTT, ArduinoHttpClient

## sobre artista, diseñadora o producto que usa electrónica o computación inalámbricas

## Studio Drift

studio drift fue fundado en 2007 en ámsterdam por lonneke gordijin y ralph nauta, el estudio nacio desde una obsesión compartida por estos dos, la relación entre humanos, naturaleza y tecnología.

+ se conocieron en la academia de diseño de Eindhoven, mientras el mundo del diseño se enfocaba en muebles funcionales, ellos querían crear objetos que de cierta manera reaccionaran.
+ el nombre Drift refleja su intención de dejarse llevar por los procesos naturales. dicen que la tecnología ha avanzado tanto que ya no debería ser algo que usamos, sino algo con lo que coexistimos
+ empezaron con piezas pequeñas como Fragile Future (luces con dientes de leon reales), pero su ambición los llevó a querer intervenir el espacio público a escala masiva, lo que dio paso a sus proyectos de enjambres de drones

![imagenes](./imagenes/franchise-freedom.jpeg)

## Franchise Freedom

esta obra es el mejor ejemplo de computación inalámbrica, no hay una computadora central que le diga a cada dron exactamente dónde estar en cada segundo, lo que sería muy rigido.

en cuanto a software utilizan esta inteligencia de enjambre, se basan en un algoritmo desarrollado originalmente por craig reynolds llamado Boids. cada dron tiene instalado un software que procesa tres vectores constantemente:

+ el chip calcula el centro de masa de los drones vecinos y trata de moverse hacia allá para no quedarse solo `:(`
+ el sensor inalámbrivo detecta hacia dónde miran los demas y ajusta su propia orientación
+ si un vecino se acerca demasiado (detectado por sensores de proximidad), la resistencia de los motores aumenta o disminuye para corregir la posición y evitar el choque

encontré piezas clave para esta magia:

+ primero está  el módulo de radio de baja latencia, usan frecuencias específicas (varias veces fuera del wifi común para evitar interferencias) que permiten que los drones hablen entre sí iles de veces por segundo
+ la unidad de medición inercial, un chip que combina acelerómetros y giroscopios. es lo que permite que el dron sepa si está inclinado, asegurando que el movimiento sea fluido y no tiemble
+ el microcontrolador de alta velocidad es el encargado de recibir los datos inalámbricos de los otros drones y deidir qué potencia enviarle a cada motor en tiempo real

en el franchise freedom los drones no solo vuelan, tienen una firma lumínica. los condensadores de la placa led están diseñados para que la luz no se apague de golpe, si no que tenga un fade suave, imitando cómo la luz del sol rebota en las alas de un pájaro real
