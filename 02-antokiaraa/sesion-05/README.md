# sesion-05

lunes 06 abril 2026

solemne 1

## en clase

- Actualizar el firmware del Arduino para que funcione el WiFi
- En base al código de "Publish" de Adafruit IO
- Modificar el nombre del feed (grupoXX-tópico)
- En el archivo .h se debe modificar:

   - IO_USERNAME y IO_KEY (podemos usar nuestra cuenta para pequeñas pruebas, es limitada)
   -  WIFI_SSID y WIFI_PASS con los datos de la red que vamos a usar
- Que en el serial monitor los BAUD coincidan con lo escrito en el código
- Si aparece "...." es porque la placa está intentando conectar, puede demorar un poco hasta que se conecte y diga "Connected to Adafruit IO"
- Luego para confirmar se debe revisar en los feeds
- Pedir compartir el link para poder recibir en tiempo real

### avance solemne en clase

primero probamos el ejemplo de enviar un contador, suele dar problemas porque demora la conección o porque hay muchas personas conectadas, pero se logró

probé hacer lo que ya había hecho pero ahora a la cuenta de Aaron para que pueda cambiar el color del LED desde su dispositivo

para el método que se muestra en el tutorial de Adafruit es necesario antes crear el feed y también el dashboard, y en este seleccionar el feed ya creado y que en nuestro código coincida el nombre del feed para que llegue ahí

ya con esto logrado podemos definir el código para la solemne y tenemos las pruebas hechas

![led a tiempo real](./imagenes/ledenclase.gif)


