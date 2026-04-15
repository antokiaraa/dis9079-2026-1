# sesion-04 

Lunes 30 Marzo:

# Tema central:
La clase giró en torno a cómo hacer que distintos dispositivos se comuniquen entre sí de forma inalámbrica. El foco estuvo en MQTT, en el uso de Wi-Fi como medio de conexión, y en la idea de que los mensajes viajan dentro de una red siguiendo ciertas reglas.

### Topic MQTT: ###

MQTT es un protocolo de comunicación muy liviano, pensado para que dispositivos se manden mensajes entre sí por red sin exigir demasiados recursos. Es muy útil en proyectos con microcontroladores, sensores y sistemas IoT.

### 3 partes claves ### 

Publisher: el dispositivo que publica o envía un mensaje
Subscriber: el dispositivo que recibe o está suscrito a ese mensaje
Broker: el intermediario que organiza y distribuye los mensajes

 ### WI FI ###
conexión inalámbrica que permite que un dispositivo se comunique con una red sin cable
Con Wi-Fi, un dispositivo puede:

-conectarse a internet 
-conectarse a una red local 
-mandar datos a otro dispositivo  
-recibir mensajes desde otro dispositivo 

### IP ### 
un dispositivo tiene una dirección IP para que los datos sepan a dónde ir. 
 
Ejemplo:

Raspberry Pico: 192.168.1.35
Arduino manda un mensaje a esa IP
la Raspberry lo recibe y muestra algo en la OLED

<ins>En clase probamos: Wifi Web Server Led Blink</ins>


### Referente ###

**Claude shannon theory of communication**

Se nombró a Claude Shannon como referente importante para entender la comunicación. Es una figura clave porque sentó bases de la teoría de la información, que ayuda a pensar cómo un mensaje se transmite desde una fuente hacia un destino, pasando por un canal y enfrentándose incluso a posibles interferencias o “ruido”.
 
una fuente que genera información
un medio por donde viaja
un receptor
y posibles problemas o ruido en el proceso

## Conceptos y herramientas que aparecieron

**Mosquitto** 
También apareció la idea de tener el broker en Mosquitto, que es otra herramienta asociada a MQTT. En términos simples, sirve para levantar o alojar el broker que ordena la comunicación.

**UDP**
UDP (User Datagram Protocol) es otro protocolo, más centrado en enviar datos rápido y sin tanta verificación. Prioriza velocidad y baja latencia antes que seguridad total en la entrega. Por eso sirve en contextos donde importa mucho la rapidez. 

**TigerVNC**
TigerVNC apareció como sistema de escritorio gráfico remoto para poder visualizar o controlar la Raspberry Pi desde otro computador. 

**Rosetta** 
Se nombró Rosetta en el contexto de Apple. Me queda como una herramienta de compatibilidad que permite correr programas pensados para otra arquitectura, especialmente en computadores Mac con Apple Silicon. 
 
**5 GHz**
Se mencionó que la red de 5 GHz puede ser más rápida, pero tiene menor alcance. Entonces no siempre conviene según la distancia o el espacio.


## OJITOOOOOOO

**sudo**
Quedó anotado que sudo es una palabra delicada porque da permisos de superusuario o administrador. La idea fue tener cuidado con usarla.

**rm -rf**
También apareció como comando peligroso, porque puede borrar archivos o directorios de manera muy agresiva. Queda como advertencia importante.

**son apuntes para no perder ideas**

Proyecto solemne 01 grupo Amistad es Amigo  

idea general del proyecto
1. sensor de pulso va conectado a arduino
2. el arduino capta señal del sensor
3. cuando detecta pulso válido, envía un mensaje inalámbrico
4. la pico 2w está escuchando y conectada a pantalla
5. cuando recibe mensaje actualiza pantalla y muestra  mensaje.

Flujo de proyecto:
Sensor de pulso -> Arduino -> MQTT x wifi -> Broker MQTT -> Raspberry -> pantalla Oled 

Lista de útiles : 
-Arduino   
-1 sensor pulso cardíaco  
-1 pantalla Oled I2c 128x64 
-1 LED 
-Cables Dupont  
-Protoboard 
-2 cables usb  
-1 red wifi  

negativo gnd
sacadito en palito luz led es igual a negativo


1. Conectar Arduino a Sensor pulso.

   -Sensor pulso a cable rojo 5v, cable negro gnd, amarillo a0 
   -Led (mejor en protoboard con una resistencia)
   -Tener cuidado luz sensor es muy sensible
   -Leer codigo si no funciona
   -codigo corazón LEDMATRIX_HEART_BIG y LEDMATRIX_HEART_SMALL
    

