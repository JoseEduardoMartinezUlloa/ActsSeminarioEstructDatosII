/*
Huerta Diaz Fabian Aljandro
Lopez Garcia Alberto de jesús
Martinez Ulloa Jose Eduardo
Mercado Guerra Gerardo Gabriel
*/
#include<iostream>
#include<fstream>
#include<iomanip>
#include"Deportistas.cpp"

void Altas(std::fstream&);
void Bajas(std::fstream&);
void Cambios(std::fstream&);
void ConsultaIndividual(std::fstream&);
void ConsultaGeneral(std::fstream&);

void MostrarLinea(int, std::string, int , std::string, std::string);


int main() {

    int opc;

    std::fstream ArchivoDeporistasEntSal;
    ArchivoDeporistasEntSal.open("Deportistas.dat", std::ios::in | std::ios::binary | std::ios::out);


    if(!ArchivoDeporistasEntSal){
        std::cerr<<"Error ... No se pudo abrir el archivo"<<std::endl;
    }

    do{
        ArchivoDeporistasEntSal.clear();
        std::cout<<"\n === Menu === \n\n"
        <<"[1] - Altas \n"
        <<"[2] - Bajas \n"
        <<"[3] - Cambios \n"
        <<"[4] - Consulta Individual\n"
        <<"[5] - Consulta Genetral \n"
        <<"[6] - Salir \n"
        <<"Seleccione una opcion: ";
        std::cin>>opc;

        switch (opc)
        {
            ArchivoDeporistasEntSal.clear();
            case 1:
               
                Altas(ArchivoDeporistasEntSal);
                ArchivoDeporistasEntSal.clear();
                break;
            case 2:
                
                Bajas(ArchivoDeporistasEntSal);
                ArchivoDeporistasEntSal.clear();
                break;
            case 3:
                
                Cambios(ArchivoDeporistasEntSal);
                ArchivoDeporistasEntSal.clear();
                break;
            case 4:
               
                ConsultaIndividual(ArchivoDeporistasEntSal);
                ArchivoDeporistasEntSal.clear();
                break;
            case 5:
               
                ConsultaGeneral(ArchivoDeporistasEntSal);
                ArchivoDeporistasEntSal.clear();
                break;
            case 6:
                std::cout<<"Saliendo del programa...";
                break;
            default:
                std::cout<<"Seleccione una opcion valida..."<<std::endl;
            break;
        }
        ArchivoDeporistasEntSal.seekg(0);
    } while(opc != 6);


}



void Altas(std::fstream& archivoDeportistasEntSal){
    int numero;
    char nombre[15];
    int edad;
    char sexo[15];
    char deporte[15];

    Deportista d;

    std::cout<<"Escriba el  numero de socio (1 a 100, 0 para terminar la entrada )"<<std::endl;
    std::cin>>numero;

    d.establecerNumeroDeSocio(numero);

    archivoDeportistasEntSal.seekg((d.obtenerNumeroDeSocio()-1)* sizeof(Deportista));
    archivoDeportistasEntSal.read(reinterpret_cast<char *>(&d),sizeof(Deportista));

    if(d.obtenerNombre() != ""){
        std::cout<<"Ya existe ese registro"<<std::endl;
    }else{

        while(d.obtenerNumeroDeSocio() >= 1 && d.obtenerNumeroDeSocio() <= 100){
            std::cout<<"Teclea  el nombre , edad, sexo  y deporte\n?";
            std::cin>>std::setw(15)>>nombre;
            std::cin>>edad;
            std::cin>>std::setw(16)>>sexo;
            std::cin>>std::setw(15)>>deporte;
            
            d.establecerNombre(nombre);
            d.establecerEdad(edad);
            d.establecerSexo(sexo);
            d.establecerDeporte(deporte);

            archivoDeportistasEntSal.seekp((d.obtenerNumeroDeSocio() - 1 )* sizeof(Deportista));
            archivoDeportistasEntSal.write(reinterpret_cast<const char* >(&d),sizeof(Deportista));
            std::cout<<"Escriba el numero del socio(1 a 100 para terminar la entrada )\n?";
            std::cin>>numero;
            d.establecerNumeroDeSocio(numero);
        }
        archivoDeportistasEntSal.clear();
    }
}



void Bajas(std::fstream& archivoDeportistasEntSal){
    int num; 
    Deportista DeportistaEnBlanco;
    Deportista c;
    int confirm; 
    do{
    std::cout<<"introduzca un numero de cuenta: ";
    std::cin>>num;
    DeportistaEnBlanco.establecerNumeroDeSocio(num);
    archivoDeportistasEntSal.seekg(( DeportistaEnBlanco.obtenerNumeroDeSocio()-1) * sizeof(Deportista));
    archivoDeportistasEntSal.read(reinterpret_cast<char*>(&c),sizeof(Deportista));
    if(c.obtenerNombre() == ""){
        std::cout<<"NO EXISTE EL REGISTRO...\n";
    }else{
        archivoDeportistasEntSal.seekp(( DeportistaEnBlanco.obtenerNumeroDeSocio()-1) * sizeof(Deportista));
        archivoDeportistasEntSal.write(reinterpret_cast<char*>(&DeportistaEnBlanco),sizeof(Deportista));
        std::cout<<"CONFIRMAR [1] - SI / [2] - NO ";
        std::cin>>confirm;
        } 
    }while (confirm == 1 );
    archivoDeportistasEntSal.seekg(0); 
}


void Cambios(std::fstream& archivoDeportistasEntSal){
    int num, edad;
    char nombre[15];
    char sexo[15];
    char deporte[15];
    Deportista d;

   std::cout<<"Introduzca un numero de socio: ";
   std::cin>>num;
    d.establecerNumeroDeSocio(num);
    archivoDeportistasEntSal.seekg((d.obtenerNumeroDeSocio()-1)*sizeof(Deportista));
    archivoDeportistasEntSal.read(reinterpret_cast<char*>(&d),sizeof(Deportista));
    
    if(d.obtenerNombre() == ""){
        std::cout<<"No existe el registro...\n";
    }else{
        if(d.obtenerNumeroDeSocio() != 0){
            std::cout<<std::left<<std::setw(10)<<"NUMERO"<<std::setw(13)<<" NOMBRE  "<<std::setw(13)<<" EDAD "<<std::setw(13)<<" SEXO "<<std::setw(8)<<" DEPORTE "<<std::endl;
            MostrarLinea(d.obtenerNumeroDeSocio(),d.obtenerNombre(),d.obtenerEdad(),d.obtenerSexo(),d.obtenerDeporte());
            std::cout<<"Teclea el nombre, edad, sexo y deporte\n?";
            std::cin>>std::setw(8)>>nombre;
            std::cin>>edad;
            std::cin>>std::setw(8)>>sexo;
            std::cin>>std::setw(8)>>deporte;
            d.establecerNombre(nombre);
            d.establecerEdad(edad);
            d.establecerSexo(sexo);
            d.establecerDeporte(deporte);
            std::cout<<std::left<<std::setw(10)<<"NUMERO"<<std::setw(13)<<" NOMBRE  "<<std::setw(13)<<" EDAD "<<std::setw(13)<<" SEXO "<<std::setw(8)<<" DEPORTE "<<std::endl;
            MostrarLinea(d.obtenerNumeroDeSocio(),d.obtenerNombre(),d.obtenerEdad(),d.obtenerSexo(),d.obtenerDeporte());
            archivoDeportistasEntSal.seekp((d.obtenerNumeroDeSocio()-1)*sizeof(Deportista));
            archivoDeportistasEntSal.write(reinterpret_cast<char*>(&d),sizeof(Deportista));
        }
    }
    archivoDeportistasEntSal.clear();
}



void ConsultaIndividual(std::fstream& archivoDeportistasEntSal){
    int num;
    Deportista d;
                
    std::cout<<"introduzca un numero de cuenta: ";
    std::cin>>num;
    d.establecerNumeroDeSocio(num);
    archivoDeportistasEntSal.seekg((d.obtenerNumeroDeSocio()-1)*sizeof(Deportista));
    archivoDeportistasEntSal.read(reinterpret_cast<char*>(&d),sizeof(Deportista));
    
    if(d.obtenerNombre() == ""){
        std::cout<<"No existe ese registro...\n";
    }else{

        archivoDeportistasEntSal.seekg(( d.obtenerNumeroDeSocio()-1) * sizeof(Deportista));
        archivoDeportistasEntSal.read(reinterpret_cast<char*>(&d),sizeof(Deportista));
        std::cout<<std::left<<std::setw(10)<<"NUMERO"<<std::setw(13)<<" NOMBRE  "<<std::setw(13)<<" EDAD "<<std::setw(13)<<" SEXO "<<std::setw(8)<<" DEPORTE "<<std::endl;
        MostrarLinea(d.obtenerNumeroDeSocio(),d.obtenerNombre(),d.obtenerEdad(),d.obtenerSexo(),d.obtenerDeporte());
    }
    archivoDeportistasEntSal.clear();
}


void ConsultaGeneral(std::fstream& archivoDeportistasEntSal){
    Deportista d;
    archivoDeportistasEntSal.read(reinterpret_cast<char*>(&d),sizeof(Deportista));
    std::cout<<std::left<<std::setw(10)<<"NUMERO"<<std::setw(13)<<" NOMBRE  "<<std::setw(13)<<" EDAD "<<std::setw(13)<<" SEXO "<<std::setw(8)<<" DEPORTE "<<std::endl;
    while(archivoDeportistasEntSal && !archivoDeportistasEntSal.eof()){
        if(d.obtenerNumeroDeSocio() != 0){
            MostrarLinea(d.obtenerNumeroDeSocio(),d.obtenerNombre(),d.obtenerEdad(),d.obtenerSexo(),d.obtenerDeporte());
        }
        archivoDeportistasEntSal.read(reinterpret_cast<char*>(&d),sizeof(Deportista));
    }
    archivoDeportistasEntSal.clear();
}



void MostrarLinea(int num, std::string nombre, int edad, std::string sexo ,std::string deporte){
    std::cout<<std::left<<std::setw(10)<<num<<std::setw(13)<<nombre<<std::setw(13)<<edad<<std::setw(13)<<sexo <<std::setw(8)<< deporte<<std::endl;

}