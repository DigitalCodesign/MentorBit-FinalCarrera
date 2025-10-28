# MentorBitIR

Esta librería está diseñada para que puedas detectar la presencia de objetos de una forma muy sencilla usando tu placa MentorBit y el módulo de final de carrera (FC).

Si estás empezando en el mundo de la electrónica, ¡no te preocupes! MentorBit está pensado para que aprender sea fácil y divertido. Esta placa ya incluye un montón de componentes (LEDs, pulsadores, pantallas, etc.) y utiliza conectores especiales (JST) para que puedas añadir nuevos sensores y módulos sin tener que pelearte con un montón de cables. Pásate por nuestra web para saber más de MentorBit y nuestros productos [pinchando aquí](https://digitalcodesign.com/).

![Render del Módulo MentorBit de final de carrera.](https://github.com/DigitalCodesign/MentorBit-FinalCarrera/blob/main/assets/Mod_MentorBit_FC.png)

Con esta librería, podrás saber cuando algo llega a una posición determinada y usar esa información para crear proyectos interactivos.

## Descripción
### ¿Qué es un sensor final de carrera?

Imagina los sensores que detienen cintas transportadoras industriales o permiten para los ascensores en una planta concreta. ¡Funcionan de forma muy parecida!

Un sensor de final de carrera cuenta con un interruptor con dos salidas: una normalmente cerrada (NC), es decir, mientras ningún objeto presione el sensor su salida será alta y otra normalmente abierta (NO), que su salida solo será alta cuando haya un objeto presionándolo.

### ¿Qué hace esta librería?

La librería MentorBitFC facilita aprovechar al máximo el uso del sensor. Se encarga de leer la señal de cada pin (NC y NO) y devolver su estado de cada uno permitiéndonos saber si está presionado o no, además permite saber las veces que ha sido pulsado el sensor y ver si se produce un flanco (se presiona o deja de estarlo).

Gracias a ella, podrás centrarte en lo más importante: ¡qué hará tu proyecto cuando detecte algo!

### ¿Qué puedes construir con este sensor?

- Un sistema que permita controlar cintas transportadoras, incluso por tamaño.
- Un contador de veces que se abre una puerta.
- La implementación de plantas en un sistema de ascensores.

## Cómo empezar
Usar la librería es muy sencillo. Solo sigue estos pasos para tener tu sensor detectando objetos en pocos minutos.

1. **Conexión del Módulo**

Antes que nada, conecta tu módulo de sensor DHT11 a uno de los puertos ***Digitales de Entrada/Salida*** dentro de la zona de ***Puertos para Módulos*** en tu placa MentorBit. ¡Y listo! No necesitas más cables.

2. **Instalación de las Librerías**

Para que tu placa MentorBit pueda comunicarse con el sensor, solo necesitas instalar una librería. El gestor del IDE de Arduino se encargará del resto.

- Abre tu entorno de programación IDE de Arduino.
- Ve al menú *Programa -> Incluir Librería -> Administrar Librerías...*
- En el buscador, escribe ***MentorBitFC*** y haz clic en "Instalar".
- El IDE detectará que esta librería necesita otra para funcionar y te preguntará si quieres instalarla también. Haz clic en "Install all" o "Instalar todo".

![Ejemplo de búsqueda en el gestor de librerías del IDE de Arduino.]()

¡Y ya está! Con eso tienes todo lo necesario para empezar a programar.

## Ejemplo Básico: Detectar un Objeto
El siguiente código simula que un objeto acciona y se separa constantemente el final de carrera, pudiendo ver por el monitor serial las salidas de las distintas funciones, con pequeñas modificaciones podrás leer las salidas de los pines en los que conectes tu módulo final de carrera.

### Copia y pega este código en tu IDE:

```c++
//Incluimos la librería que acabamos de instalar
#include <MentorBitFC.h>
//Declaramos los pines NO y NC
int NO_PIN = 4;
int NC_PIN = 5;

// Creamos un objeto fc y le indicamos los pines que vamos a usar
MentorBitFC fc(NO_PIN, NC_PIN);

//Declaramos un función que muestra todos los datos invocando todas las funciones de la librería
void imprimirDatos(){
   // Leer estados de los pines
    bool estadoNO = fc.estadoActualNO();
    bool estadoNC = fc.estadoActualNC();

    // Detectar flanco de cambio
    bool flancoDetectado = fc.getFlanco();

    // Obtener cuántas veces se ha interactuado
    unsigned long veces = fc.getVecesInteractuado();

    // Mostrar todo por Serial
    Serial.print("NO: ");
    Serial.println(estadoNO ? "Cerrado" : "Abierto");
    Serial.print("NC: ");
    Serial.println(estadoNC ? "Cerrado" : "Abierto");
    Serial.print("Flanco detectado: ");
    Serial.println(flancoDetectado ? "Sí" : "No");
    Serial.print(" Veces interactuado: ");
    Serial.println(veces);

    delay(200); // Esperar medio segundo entre lecturas
}


void setup() {
//Inicializamos el serial y los pines en su estado de output para que podamos modificar su salida y simular el comportamiento del módulo
Serial.begin(9600);
pinMode(NO_PIN, OUTPUT);
pinMode(NC_PIN, OUTPUT);

} 

void loop() {
  Serial.println("=== Test de MentorBitFC ===");

  //Ponemos los pines en estado incial como si el final de carrera estuviese sin pulsar
  digitalWrite(NO_PIN,LOW);
  digitalWrite(NC_PIN,HIGH);
  fc.update();
  imprimirDatos();
  fc.update();
  delay(2000);


  //Comprobamos que sigan igual los datos
  fc.update();
  imprimirDatos();
  delay(2000);

  //Simulamos que el final de carrera se pulsa
  digitalWrite(NO_PIN,HIGH);
  digitalWrite(NC_PIN,LOW);
  fc.update();
  imprimirDatos();
  fc.update();
  delay(2000);
  
  //Comprobamos que sigan igual los datos
  fc.update();
  imprimirDatos();
  delay(2000);

}
```
### Para ver el resultado:

1. Carga el código en tu placa MentorBit.
2. Abre el **Monitor Serie** del IDE de Arduino.
3. ¡Verás cómo cambia la salida cuando simulamos su activación y desactivación!

## Funciones Principales

- <code>MentorBitFC(uint8_t no_pin = 0, uint8_t nc_pin = 0)</code>
   - **¿Qué hace?** Es el constructor. Crea el objeto que te permitirá controlar el sensor. Debes indicarle a qué pines digitales de tu MentorBit has conectado el módulo.
   - **¿Cuándo se usa?** Al principio de tu código, antes del <code>setup()</code>, para declarar tu sensor.

- <code>bool estadoActualNO()</code>
   - **¿Qué hace?** Devuelve el estado actual de la salida normalmente abierta.
   - **¿Cuándo se usa?** Cada vez que quieras comprobar el estado de dicha salida, normalmente dentro de la función <code>loop()</code>. Devuelve <code>true</code> si el final de carrera está presionado y <code>false</code> si no lo está.

- <code>bool estadoActualNC()</code>
   - **¿Qué hace?** Devuelve el estado actual de la salida normalmente cerrada.
   - **¿Cuándo se usa?** Cada vez que quieras comprobar el estado de dicha salida, normalmente dentro de la función <code>loop()</code>. Devuelve <code>false</code> si el final de carrera está presionado y <code>true</code> si no lo está. Normalmente se usa para lo mismo que estadoActualNO(), dependerá de tu aplicación que resulte más cómodo usar uno u otro.

- <code>void update()</code>
   - **¿Qué hace?** Actualiza comprueba si el estado del final de carrera a cambiado y guardando que se ha producido un flanco hasta que se vuelva a comprobar que sigue igual que la última vez que se comprobó. Además cuando detecta estos cambios cuenta cuantas veces se ha interactuado con el final de carrera.
   - **¿Cuándo se usa?** Cuando sepas que se va ha producir un cambio en el final de carrera o en bucle durante tu código en todo momento, siempre se usa dentro de la función <code>loop()</code>. No devuelve nada, para obtener los atributos modificados se utilizan otras funciones.

- <code>bool getFlanco()</code>
   - **¿Qué hace?** Devuelve el estado actual del atributo flanco.
   - **¿Cuándo se usa?** Cuando se quiere comprobar si se produjo un flanco, normalmente entre llamada y llamada a la función update, normalmente dentro de la función <code>loop()</code>. Devuelve <code>false</code> si desde la última vez que se llamó a update el estado no ha cambiado y <code>true</code> si la útima vez que se llamó a update el final de carrera había cambiado de estado.

- <code>unsigned long getVecesInteractuado()</code>
   - **¿Qué hace?** Devuelve cuantas veces se ha activado el final de carrera.
   - **¿Cuándo se usa?** Cuando se quiere conocer cuantas veces se interactuado con el final de carrera, normalmente dentro de la función <code>loop()</code>. Devuelve un <code>unsigned long</code> con el número de veces que se ha interactuado con el final de carrera.

## Recursos Adicionales

¿Quieres saber más sobre el módulo o necesitas comprar uno? Aquí tienes algunos enlaces que te serán de utilidad:

- [Web del fabricante](https://digitalcodesign.com/)
- [Tienda Online de Canarias](https://canarias.digitalcodesign.com/shop)
- [Tienda Online de Península](https://digitalcodesign.com/shop)
- [Web Oficial de MentorBit](https://digitalcodesign.com/mentorbit)
- [Web Oficial de MentorBit módulo de final de carrera (FC)]()
- [Manual de usuario del MentorBit módulo de final de carrera (FC)](https://drive.google.com/file/d/1KmkXIWV7oo9hBjp3SClwlqGIk9dDEwZW/view?usp=drive_link)
- [Modelo 3D de MentorBit módulo final de carrera en formato .STEP](https://drive.google.com/file/d/1FmJWV0iJiAq3dIAgedz9OdMTpRAXOz2d/view?usp=drive_link)
