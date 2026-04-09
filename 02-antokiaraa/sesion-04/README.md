# sesion-04

lunes 30 marzo 2026

- Tplink wifi
- TigerVNC
  - ssid : nombre
  - pass: contraseña router

luego crea un cliente de wifi capaz de conectarse al wifi y dice que usa el estilo de vida MQTT

- broker: ip de la raspberry pi
- port: puerto standard 1883, comunicaciones MQTT
- topic: debe enviarse en un cierto tema, y cada persona que recibe debe suscribirse a este tema

WiFi:

según Gemini:

> Es un sistema de transmisión de datos mediante ondas de radiofrecuencia que permite el intercambio de información por el aire, eliminando la necesidad de vínculos físicos. A través de este enlace invisible, un hardware puede:
> - Acceder al nodo global: Navegar por la red mundial (Internet).
> - Sincronizar un ecosistema interno: Establecer comunicación dentro de una red de área local (LAN).
> - Gestionar tráfico bidireccional: Actuar como emisor y receptor de paquetes de datos en tiempo real entre distintos puntos de la red.

IP: identificador único de un equipo dentro de una red

### en código de Arduino

MODIFICAR: 

aquí se deben modificar cosas

veremos como agregar claves, ponerle la misma todos para que sea más fácil

SETUP:

intentando conectar y espera 5 segundos para intentar nuevamente

si logra conectarse envía mensaje

LOOP:

voy a enviar un mensaje al tópico

### Referente

Claude Shannon <https://www.bbc.com/mundo/articles/cn0yxddw9dwo>



