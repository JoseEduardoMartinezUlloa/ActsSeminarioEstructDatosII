#include <iostream>
#include <string>

class Deportista
{
    private:
        int numeroDeSocio;
        char nombre[15];
        int edad;
        char sexo[10];
        char deporte[15];
    public:
        Deportista(int = 0, std::string = "", int = 0, std::string = "",std::string = "");
        //setters
        void establecerSexo(std::string);
        void establecerNumeroDeSocio(int);
        void establecerNombre(std::string);
        void establecerEdad(int);
        void establecerDeporte(std::string);
        //getters


        std::string obtenerSexo()const;
        int obtenerNumeroDeSocio()const ;
        std::string obtenerNombre()const;
        int obtenerEdad()const;
        std::string obtenerDeporte()const;
};
