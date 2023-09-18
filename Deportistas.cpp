#include"Deportistas.h"
#include<string.h>




//setters
void Deportista::establecerNumeroDeSocio(int num){this->numeroDeSocio = num;}


void Deportista::establecerNombre(std::string cadenaNombre){  const char* valorNombre = cadenaNombre.data();
 int longitud = cadenaNombre.size();
 longitud = (longitud <15 ? longitud : 14);
 strncpy(nombre, valorNombre, longitud );
 nombre[longitud] = '\0';
}
void Deportista::establecerEdad(int ed){edad = ed;}

void Deportista::establecerDeporte(std::string cadenaDeporte){  const char* valorDeporte = cadenaDeporte.data();
 int longitud = cadenaDeporte.size();
 longitud = (longitud <15 ? longitud : 14);
 strncpy(deporte, valorDeporte, longitud );
 deporte[longitud] = '\0';
}

void Deportista::establecerSexo(std::string cadenaSexo){
const char* valorSexo =  cadenaSexo.data();
int longitud = cadenaSexo.size();
longitud = (longitud <10 ? longitud : 14);
strncpy(sexo, valorSexo,longitud);
sexo[longitud] = '\0';
}



//getters
int Deportista::obtenerNumeroDeSocio()const{return numeroDeSocio;}
std::string Deportista::obtenerNombre()const{return nombre;}

int Deportista::obtenerEdad()const{return edad;}

std::string Deportista::obtenerDeporte()const{return deporte;}

std::string Deportista::obtenerSexo()const{return sexo;}


Deportista::Deportista(int num,std::string name, int edd,std::string sex, std::string  dep){
 establecerNumeroDeSocio(num);
 establecerNombre(name);
 establecerEdad(edd);
 establecerSexo(sex);
 establecerDeporte(dep);
}