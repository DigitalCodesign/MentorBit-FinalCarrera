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
