# sesion-04

lunes 30 marzo 2026

## Concepto base

La comunicación entre dispositivos se basa en las ideas de Claude Shannon, quien desarrolló la teoría de la información. Esta explica cómo los datos pueden transmitirse, codificarse y recibirse sin perder información.

![teoria de la comunicación](./imagenes/teoria-de-la-comunicacion.png)

Gracias a esto, hoy dispositivos como Arduino y Raspberry Pi pueden comunicarse mediante redes WiFi y protocolos como MQTT.

## Redes WiFi

El WiFi funciona como una carretera por donde circulan los datos. Puede tener o no acceso a internet, pero permite la comunicación entre dispositivos dentro de una misma red.

#### Datos de la red utilizada

SSID: dis9079

Clave: 75288273

#### Frecuencias

2.4 GHz -> mayor alcance, menor velocidad

5 GHz -> mayor velocidad, menor alcance

Se recomienda usar un router en lugar de compartir internet desde el celular, ya que soporta más dispositivos conectados.

## Estructura de la red

La Raspberry Pi tiene una IP fija y actúa como el punto central del sistema.

## Flujo de conexión

Arduino -> WiFi -> Router -> Broker -> Otros dispositivos

La red gestiona internamente las direcciones IP, simplificando la conexión entre dispositivos.

## Acceso remoto

Se puede acceder a la Raspberry Pi de forma remota mediante

SSH -> control por terminal

TigerVNC -> acceso gráfico

## Comandos importantes

- `sudo`
  Ejecuta comandos como administrador. Es potente pero riesgoso si se usa mal.

- `rm -rf`
  Elimina archivos de forma permanente. Puede borrar todo el sistema si se utiliza incorrectamente.
  
## Protocolos de comunicación

### MQTT

Protocolo ligero basado en TCP que funciona bajo el modelo *publish/subscribe*.

- Usa un broker como por ejemplo Mosquitto en Raspberry Pi

- Puerto 1883

- Requiere identificador, contraseña y topic común

#### Características

- Alta fiabilidad

- Mantiene el orden de los mensajes

- Ideal para IoT

### UDP

Protocolo rápido y sin conexión.

- No garantiza entrega ni orden

- Baja latencia

#### Usos

- Streaming

- Juegos online

- Comunicación en tiempo real

## Modelo de red

El modelo OSI divide la comunicación en capas, permitiendo entender cómo viajan los datos dentro de una red.

![osi](./imagenes/osi-model.png)

## Arduino en red

Para conectar un Arduino se necesita

- Conexión a WiFi

- IP de la red

- Broker MQTT

- Configuración de envío y recepción de datos

Todos los dispositivos deben compartir

- Nombre de grupo

- Clave

- Topic

Parte de esta configuración se realiza directamente en el código.

## Funcionamiento

La función `loop()` en Arduino se ejecuta continuamente y permite

- Enviar datos

- Recibir mensajes

- Reaccionar en tiempo real

Los dispositivos pueden publicar información, suscribirse a canales y actuar según los datos recibidos.

## Plataformas

HiveMQ es una plataforma de mensajería basada en MQTT orientada a IoT a gran escala. Permite comunicación segura, gestión de datos en tiempo real y alta escalabilidad.

## Conceptos adicionales

- IoT (Internet of Things) -> dispositivos conectados que intercambian datos

- 5G -> alta velocidad, bajo alcance

- Rosetta -> emulador de Apple para ejecutar apps Intel en Apple Silicon

- Bug -> error en sistema (origen en un caso real con un insecto)
