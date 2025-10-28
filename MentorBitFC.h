
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

#ifndef MentorBitFC_h
#define MentorBitFC_h

#include <arduino.h>
#include <MentorPort.h>

class MentorBitFC : public MentorPort
{

    public: 

        MentorBitFC(uint8_t no_pin = 0, uint8_t nc_pin = 0);
        void configPort(const Port& port) override;
        bool estadoActualNO();
        bool estadoActualNC();
        void update();
        bool getFlanco();
        unsigned long getVecesInteractuado();

    private: 
        unsigned long vecesInteractuado;
        bool flanco;
        bool ultimoEstado;

        Port _port;

};

#endif


