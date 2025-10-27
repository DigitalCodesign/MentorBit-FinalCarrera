# MentorBit-╠══██████████████══╣

╠══██████   DESCRIPCION   ████████══╣.

Si estás empezando en el mundo de la electrónica, ¡no te preocupes! MentorBit está pensado para que aprender sea fácil y divertido. Esta placa ya incluye un montón de componentes (LEDs, pulsadores, pantallas, etc.) y utiliza conectores especiales (JST) para que puedas añadir nuevos sensores y módulos sin tener que pelearte con un montón de cables. Pásate por nuestra web para saber más de MentorBit y nuestros productos [pinchando aquí](https://digitalcodesign.com/).

![Render del MentorBit módulo matriz de pulsadores.](╠══██████████████══╣)

╠══███████   DESCRIPCION DE QUE SE PUEDE HACER (PEQUEÑA)   ███████══╣

---

## Descripción

### ¿Qué es ╠══██████████████══╣ ?

╠══███████   DESCRIPCION DEL MODULO AL CUAL VA DIRIGIDA LA LIBRERIA███████══╣

Este tipo de módulo es ideal para:

- ╠══██████████████══╣.
- ╠══██████████████══╣.
- ╠══██████████████══╣.

---

### ¿Qué hace esta librería?

La librería **╠══██████████████══╣** permite:

- ╠══██████████████══╣.
- ╠══██████████████══╣.
- ╠══██████████████══╣.

---

### ¿Qué puedes construir con este módulo?

- ╠══██████████████══╣.
- ╠══██████████████══╣.
- ╠══██████████████══╣.

---

## Cómo empezar

### 1. **Conexión del Módulo**

╠══███████   EXPLICAR LA CONEXION DEL MODULO CON MENTORBIT   ███████══╣.


### 2. **Instalación de la Librería**

- Abre tu entorno de programación IDE de Arduino.
- Ve al menú *Programa -> Incluir Librería -> Administrar Librerías...*
- En el buscador, escribe ***MentorBit-╠══██████████████══╣*** y haz clic en "Instalar".

![Ejemplo de búsqueda en el gestor de librerías del IDE de Arduino.](https://github.com/DigitalCodesign/MentorBit-╠══██████████████══╣/blob/main/assets/library_instalation_example.png)

---

## Ejemplo Básico: ╠══██████████████══╣

╠══███████   CAMBIAR EJEMPLO   ███████══╣

Este ejemplo lee el estado de uno de los 16 pulsadores y lo imprime por el monitor serie.

```cpp
// Se incluye la libreria MentorBitMatrizPulsadores
#include <MentorBitMatrizPulsadores.h>

// Se define la dirección I2c en la cual se encuentra la matriz de pulsadores
// y tambien se define que pin de la matriz se quiere utilizar
#define DireccionI2c 0x26
#define Pulsador 2

// Se crea el objeto Matriz
MentorBitMatrizPulsadores matriz;


void setup() {
    // Inicializamos el bus serial a una velocidad de 9600 baudios
    Serial.begin(9600);
    // Inicializamos la Matriz de pulsadores
    matriz.begin(DireccionI2c);
}

void loop() {
    if(matriz.leerPulsador(Pulsador) == LOW){ // Se lee el estado del pulsador de la matriz
        // Imprimir por serial que se ha presionado el pulsador
        Serial.println("Se ha presionado el pulsador numero " + String(Pulsador));
        // Pequeño delay para evitar que lea dos o más veces una unica pulsación
        delay(1000);
    }
}
```

---

## Funciones Principales

╠══███████   RELLENAR   ███████══╣

- `bool leerPulsador(uint8_t Pin)`  
  Lee el estado de un determinado pulsador.

---

## Atributos Principales (clase matriz)

╠══███████   RELLENAR   ███████══╣

- `matriz.PUERTO_A`  
  Atributo para seleccionar el puerto A en varios métodos.

---

## Recursos Adicionales

╠══███████   CAMBIRAR ENLACES   ███████══╣

- [Web del fabricante](https://digitalcodesign.com/)
- [Tienda Online de Canarias](https://canarias.digitalcodesign.com/shop)
- [Tienda Online de Península](https://digitalcodesign.com/shop)
- [Web Oficial de MentorBit](https://digitalcodesign.com/mentorbit)
- [Web Oficial del Módulo Matriz de Pulsadores](https://canarias.digitalcodesign.com/shop/00038775-mentorbit-modulo-matriz-de-pulsadores-i2c-8105?page=2&category=226&order=create_date+desc#attr=)
- [Manual de usuario del Módulo](https://drive.google.com/file/d/1r-NqhV3tNsIOfbVwdaLwVG5oWKHT8m4R/view?usp=drive_link)
- [Modelo 3D del Módulo en formato .STEP](https://drive.google.com/file/d/1VcCUQ8EQWMD2fs43Jvh-ibaW29CgUGun/view?usp=drive_link)
