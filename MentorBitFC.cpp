/*


            ██████╗    ██╗    ██████╗    ██╗   ████████╗    █████╗    ██╗               
            ██╔══██╗   ██║   ██╔════╝    ██║   ╚══██╔══╝   ██╔══██╗   ██║               
            ██║  ██║   ██║   ██║  ███╗   ██║      ██║      ███████║   ██║               
            ██║  ██║   ██║   ██║   ██║   ██║      ██║      ██╔══██║   ██║               
            ██████╔╝   ██║   ╚██████╔╝   ██║      ██║      ██║  ██║   ███████╗          
            ╚═════╝    ╚═╝    ╚═════╝    ╚═╝      ╚═╝      ╚═╝  ╚═╝   ╚══════╝          
                                                                                        
     ██████╗    ██████╗    ██████╗    ███████╗   ███████╗   ██╗    ██████╗    ███╗   ██╗
    ██╔════╝   ██╔═══██╗   ██╔══██╗   ██╔════╝   ██╔════╝   ██║   ██╔════╝    ████╗  ██║
    ██║        ██║   ██║   ██║  ██║   █████╗     ███████╗   ██║   ██║  ███╗   ██╔██╗ ██║
    ██║        ██║   ██║   ██║  ██║   ██╔══╝     ╚════██║   ██║   ██║   ██║   ██║╚██╗██║
    ╚██████╗   ╚██████╔╝   ██████╔╝   ███████╗   ███████║   ██║   ╚██████╔╝   ██║ ╚████║
     ╚═════╝    ╚═════╝    ╚═════╝    ╚══════╝   ╚══════╝   ╚═╝    ╚═════╝    ╚═╝  ╚═══╝ 
        

    Autor: Digital Codesign
    Version: 1.0.0
    Fecha de creación: Octubre de 2025
    Fecha de version: Octubre de 2025
    Repositorio: 
    Descripcion: 
        Esta libreria esta especificamente diseñada para ser utilizada junto con 
        el modulo MentorBit Final de Carrera
    Metodos principales:
        MentorBitFC -> constructor de la clase
        estadoActualNO -> obtiene un valor de true o false en funcion de en que
        estado se encuentre el pin NO 
        estadoActualNC -> obtiene un valor de true o false en funcion de en que
        estado se encuentre el pin NC 
        update -> actualiza el estado del final de carrera, detectando flancos y
        contando las veces que se ha activado
        getFlanco -> devuelve true si se ha detectado un flanco en la ultima
        actualizacion
        getVecesInteractuado -> devuelve el numero de veces que se ha activado el
        final de carrera
*/

#include <MentorBitFC.h>


/*
    Constructor, se le debe indicar el pin al cual se ha conectado el modulo
*/
MentorBitFC::MentorBitFC(uint8_t no_pin = 0, uint8_t nc_pin = 0) {
    _port.gpios[0] = no_pin;
    _port.gpios[1] = nc_pin;
    pinMode(_port.gpios[0], INPUT);
    pinMode(_port.gpios[1], INPUT);
    MentorBitFC::ultimoEstado = digitalRead(_port.gpios[0]);
    MentorBitFC::vecesInteractuado = 0;
}

/*
    Obtiene el estado actual del pin NO
*/
bool MentorBitFC::estadoActualNO() {
    bool NO;
    NO = digitalRead(_port.gpios[0]);
    return NO;
}

/*
    Obtiene el estado actual del pin NC
*/
bool MentorBitFC::estadoActualNC(){
    bool NC;
    NC = digitalRead(_port.gpios[1]);
    return NC;
}

/*
    Actualiza el estado del final de carrera, detectando flancos y contando
    las veces que se ha interactuado con el
*/
void MentorBitFC::update(){
    if(digitalRead(_port.gpios[0]) != MentorBitFC::ultimoEstado){
        MentorBitFC::ultimoEstado = digitalRead(_port.gpios[0]);
        MentorBitFC::flanco = true;
        MentorBitFC::vecesInteractuado++;
    } else {
        MentorBitFC::flanco = false;
    }
}

/*
    Devuelve true si se ha detectado un flanco en la ultima actualizacion
*/
bool MentorBitFC::getFlanco(){
    return MentorBitFC::flanco;
}

/*
    Devuelve el numero de veces que se ha interactuado con el final de carrera
*/
unsigned long MentorBitFC::getVecesInteractuado(){
    return MentorBitFC::vecesInteractuado;
}

void MentorBitFC::configPort(const Port& port) {

    _port.type = port.type;
    _port.location = port.location;
    _port.gpios[0] = port.gpios[0];
    _port.gpios[1] = port.gpios[1];

}