# sesion-06

lunes 13 abril 2026

## Componentes

resistencia: limita cuánta electricidad pasa por un cable para que no se quemen otros componentes
condensador: almacena energía temporalmente en un campo eléctrico.
capacitor: lo que varia es la capacitancia, es la medida de cuánta energía puede guardar.

Sensor capacitivo:
Un sensor capacitivo es un dispositivo electrónico que puede detectar la presencia de objetos conductores (como tu dedo) o materiales con propiedades eléctricas distintas al aire, sin necesidad de contacto físico directo.
A diferencia de un interruptor común que necesita que algo se mueva mecánicamente, el sensor capacitivo utiliza la electricidad estática para "sentir" lo que hay a su alrededor.

## ¿Cómo funciona? 

Para entenderlo, imagina que el sensor es como un globo con electricidad estática.

- El sensor genera un campo eléctrico invisible.

- Cuando un objeto (como tu mano) entra en ese campo, actúa como un "almacén" extra de energía.

- Ese cambio en la capacidad de almacenar carga eléctrica se llama capacitancia.

- El sensor mide ese cambio y, si es lo suficientemente grande, envía una señal: ¡Alguien me tocó!

## Capacitive touch

Es una tecnología de detección que reconoce el contacto (o la proximidad) de un objeto conductor, como el dedo humano, midiendo cambios en la capacitancia eléctrica.

A diferencia de los botones mecánicos que requieren presión física para cerrar un circuito, estos sensores funcionan detectando alteraciones en un campo eléctrico.


## ¿Cómo funciona técnicamente?
Imagina que el sensor es una pequeña placa metálica cargada de electricidad. Esta placa genera un campo electrostático a su alrededor.

1. El Condensador Humano: El cuerpo humano almacena carga eléctrica de forma natural.

2. La Interrupción: Cuando acercas tu dedo al sensor, actúas como una "segunda placa" de un condensador. Esto altera el campo eléctrico del sensor y cambia su capacitancia (la capacidad de almacenar carga).

3. La Detección: Un microcontrolador (como un Arduino o el chip de un smartphone) mide constantemente ese valor. Si el valor cambia bruscamente, el software lo interpreta como un "toque".



![capacitive](https://github.com/user-attachments/assets/df8edfcd-0519-4f9d-aea3-89b268aff358)



Info fotográfica: https://butlertechnologies.com/blog/capacitive-touch-screen-types-benefits

  


## Utilizar: Arduino_CapacitiveTouchdocumentación de la biblioteca.

CapacitiveTouch(uint8_t pin): Sirve para crear el sensor táctil capacitivo y decirle en qué pin está conectado.

bool begin(): Configura internamente el pin y deja listo el hardware para empezar a leer.

Vuleve a truesi todo funciona bien, vuelve a falsesi hubo un problema.

int read(): Lee el valor crudo del sensor.

bool isTouched(): Detecta si el sensor está siendo tocado.

void setThreshold(int threshold): Defina el nivel mínimo para considerar que hay un toque.

int getThreshold(): Obtiene el umbral actual.

D0 -> digital 0

Love button: Botón de amor sensible al tacto, convierte el pin del amor en la parte posterior del UNO-R4 Minima en un sensor táctil capacitivo.


## Distribución de pines 


![r4wifi](https://github.com/user-attachments/assets/1ab5e4e6-a7d6-418d-9b37-a5ec4c4a0ea5)



info: https://docs.sunfounder.com/projects/elite-explorer-kit/es/latest/components/component_uno.html 
https://docs.arduino.cc/tutorials/uno-r4-wifi/r4-wifi-getting-started/#software--hardware-needed



## Tutorial de UNO R4 Capacitive-Touch, comentado en clases por Aarón.

Ejemplo en clases:  codigo arduino, sensor tactil


```cpp
#include <Arduino_CapacitiveTouch.h>


// referencia
// https://docs.arduino.cc/tutorials/uno-r4-wifi/touch/
// por montoyamoraga para disenoUDP
// dis9079
// abril 2026
// funciona con Arduino Uno R4
// wifi o minima
// usar biblioteca Capacitive_Touch

// importar biblioteca
#include "Arduino_CapacitiveTouch.h"

// existe un constructo
// del tipo CapacitiveTouch
// que se llama touchButton, ese nombre es de fantasia
// esta conectada a la patita D0
CapacitiveTouch touchButton = CapacitiveTouch(D0);

// valor de lectura
int valorLectura = 0;

// setup() ocurre al principio una vez
void setup() {
  // prende el puerto serial
  // la velocidad es importante
  Serial.begin(9600);

  // touchButton
  // despues viene un punto
  // ese punto es como hacer doble click
  // es como entrar
  // dentro hace begin() que lo inicializa
  // el if hace que si lo logra pase algo
  // y si no, pase otra cosa
  if(touchButton.begin()){
    Serial.println(":) yay");
  } else {
    Serial.println("oh no :'( snif");
    // quedarse pegado ante el fracaso
    while(true);
  }
  
  // define el umbral o threshold
  // en 2000
  // lo que de inmediato me hace preguntarme
  // oh no
  // cuanto es el valor minimo posible
  // cuanto es el valor maximo posible
  // cuando terminara este calvario
  // por que 2000?
  // en california funciona?
  // y en este frio otono de santiago
  // que hago
  // quien soy
  // etc
  touchButton.setThreshold(2000);
}

// loop() ocurre en bucle
// despues de setup()
// hasta el fin de los tiempos
void loop() {

  // asignar a valorLectura
  // el resultado de preguntarle a touchButton
  // cuanto vale
  // read() me da el valor crudo
  valorLectura = touchButton.read();
  Serial.print("Valor crudo: ");
  // imprime valor lectura
  Serial.println(valorLectura);


  // se pregunta con if
  // si el boton esta siendo tocado
  if (touchButton.isTouched()) {
    // si lo esta, imprime
    Serial.println("hubo contacto");
  }
  
  // deja tu vida atras
  // suspendela, en pausa
  // cierra los ojos por 100 ms = 0.1 s
  // ignora todo lo que esta pasando
  // para que no ocurra tan rapido todo
  delay(100);
}
```


## Ejemplo calibrado


```cpp

#include <Arduino_CapacitiveTouch.h>


// referencia
// https://docs.arduino.cc/tutorials/uno-r4-wifi/touch/
// por montoyamoraga para disenoUDP
// dis9079
// abril 2026
// funciona con Arduino Uno R4
// wifi o minima
// usar biblioteca Capacitive_Touch

// importar biblioteca
#include "Arduino_CapacitiveTouch.h"

// existe un constructo
// del tipo CapacitiveTouch
// que se llama touchButton, ese nombre es de fantasia
// esta conectada a la patita D0
CapacitiveTouch touchButton = CapacitiveTouch(D0);

// valor de lectura
int valorLectura = 0;

// valores min y max
// que partan en el peor caso posible
int minLectura = 100000;
int maxLectura = 0;


// setup() ocurre al principio una vez
void setup() {
  // prende el puerto serial
  // la velocidad es importante
  Serial.begin(9600);

  // touchButton
  // despues viene un punto
  // ese punto es como hacer doble click
  // es como entrar
  // dentro hace begin() que lo inicializa
  // el if hace que si lo logra pase algo
  // y si no, pase otra cosa
  if (touchButton.begin()) {
    Serial.println(":) yay");
  } else {
    Serial.println("oh no :'( snif");
    // quedarse pegado ante el fracaso
    while (true)
      ;
  }

  // define el umbral o threshold
  // en 2000
  // lo que de inmediato me hace preguntarme
  // oh no
  // cuanto es el valor minimo posible
  // cuanto es el valor maximo posible
  // cuando terminara este calvario
  // por que 2000?
  // en california funciona?
  // y en este frio otono de santiago
  // que hago
  // quien soy
  // etc
  touchButton.setThreshold(2000);
}

// loop() ocurre en bucle
// despues de setup()
// hasta el fin de los tiempos
void loop() {

  // asignar a valorLectura
  // el resultado de preguntarle a touchButton
  // cuanto vale
  // read() me da el valor crudo
  valorLectura = touchButton.read();

  // actualizar valores min y max
  if (valorLectura < minLectura) {
    // actualiza el minimo con uno mejor
    minLectura = valorLectura;
  }

  if (valorLectura > maxLectura) {
    // actualizar el maximo con uno mejor
    maxLectura = valorLectura;
  }



  Serial.print("Valor crudo: ");
  // imprime valor lectura
  Serial.println(valorLectura);

  Serial.print("min: ");
  Serial.print(minLectura);
  Serial.print(", max: ");
  Serial.println(maxLectura);


  // se pregunta con if
  // si el boton esta siendo tocado
  if (touchButton.isTouched()) {
    // si lo esta, imprime
    Serial.println("hubo contacto");
  }

  // usar mi min y max para tomar conclusiones
  // tomo el valor promedio entre min y max
  // y si mi valor actual es mayor que eso
  // digo oh estoy por sobre el promedio
  if (valorLectura > (minLectura + maxLectura)/2) {
    Serial.println("sobre el promedio, dab");
  }

  // deja tu vida atras
  // suspendela, en pausa
  // cierra los ojos por 100 ms = 0.1 s
  // ignora todo lo que esta pasando
  // para que no ocurra tan rapido todo
  delay(100);
}
```


## Documentación en clases


![ejemplo1](https://github.com/user-attachments/assets/c2cf72f7-bbae-4097-bb73-99ceba46df67)
