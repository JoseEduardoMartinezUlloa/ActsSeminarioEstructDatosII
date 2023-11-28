#include <iostream>
#include "Pasajero.cpp" // Asegúrate de incluir el archivo que contiene la clase Pasajero
#include "ListaDoble.cpp"   // Asegúrate de incluir el archivo que contiene la clase LDLDE


void Insertar(LDLDE<Pasajero>&);
void Eliminar(LDLDE<Pasajero>&);
void BusquedaIndividual(LDLDE<Pasajero>&);



int main() {
    LDLDE<Pasajero> listaPasajeros;

    int opcion;
    do {
        std::cout << "\nMENU - LISTA DE PASAJEROS\n";
        std::cout << "1. Insertar un pasajero\n";
        std::cout << "2. Eliminar un pasajero\n";
        std::cout << "3. Visualizar un pasajero (nombre del pasajero)\n";
        std::cout << "4. Visualizar toda la lista\n";
        std::cout << "5. Salir\n";
        std::cout << "Elige una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                Insertar(listaPasajeros);
                break;
            }
            case 2: {
                Eliminar(listaPasajeros);
                break;
            }
            case 3: {
                BusquedaIndividual(listaPasajeros);
                break;
            }
            case 4:
                std::cout << "\nLista de Pasajeros:\n";
                listaPasajeros.imprimir();
                break;
            case 5:
                std::cout << "Saliendo del programa.\n";
                listaPasajeros.GuardarInformacion();
                break;
            default:
                std::cout << "Opcion no valida. Intentalo de nuevo.\n";
                break;
        }

    } while (opcion != 5);

    return 0;
}





void Insertar(LDLDE<Pasajero>& myLista){
    Pasajero nuevoPasajero;
    std::cin >> nuevoPasajero;
    myLista.insertar(nuevoPasajero);
    std::cout << "Pasajero insertado correctamente.\n";
}


void Eliminar(LDLDE<Pasajero>& myLista){
    std::string nombreEliminar;
    if(myLista.vacia()){
        std::cout<<"Lista vacia... Nada por eliminar..."<<std::endl;
    
    }else{
        std::cout<<"Ingresa el nombre del pasajero a eliminar: ";
        std::getline(std::cin, nombreEliminar);
        Pasajero pasajeorEliminar;
        pasajeorEliminar.setNombre(nombreEliminar);
        node<Pasajero>* pos = myLista.Localiza(pasajeorEliminar);
        if(myLista.eliminar(pos)){
            std::cout<<"Pasajero eliminado correctamente..."<<std::endl;
        }else{
            std::cout<<"No se logro eliminar..."<<std::endl;
        }
    }
}


void BusquedaIndividual(LDLDE<Pasajero>& myLista){
    std::string  pasajeroBuscar; 
    if(myLista.vacia()){
            std::cout<<"Lista vacia... nada por buscar..."<<std::endl;
    }else{
        std::cout<<"Ingrese el nombre del pasajero a buscar: "<<std::endl;
        std::getline(std::cin, pasajeroBuscar);
        Pasajero pasajeroBusqueda;
        pasajeroBusqueda.setNombre(pasajeroBuscar);
        
        Pasajero pasajeorEncontrado = myLista.Busqueda(pasajeroBusqueda);
        if(pasajeorEncontrado.getDestino() == " "){
            std::cout<<"Pasajero no encontrado..."<<std::endl;
        }else{
            std::cout<<"Pasajeor localizado..."<<std::endl;
            std::cout<<"Informacion de Pasajero: "<<std::endl;
            std::cout<<pasajeorEncontrado;
        }
    }
}