#include <iostream>
#include <fstream>

template<class T>
class LDLDE; 

template<class T>
class node {
private:
    T data;
    node<T>* next;
    node<T>* prev;

public:
    node();
    node(const T&);

    void setData(const T&);
    void setNext(node<T>*);
    void setPrev(node<T>*);

    T getData();
    node<T>* getNext();
    node<T>* getPrev();
};

template<class T>
node<T>::node() : next(nullptr), prev(nullptr) {}

template<class T>
node<T>::node(const T& dat) : data(dat), next(nullptr), prev(nullptr) {}

template<class T>
void node<T>::setData(const T& dat) {
    data = dat;
}

template<class T>
void node<T>::setNext(node<T>* nxt) {
    next = nxt;
}

template<class T>
void node<T>::setPrev(node<T>* prv) {
    prev = prv;
}

template<class T>
T node<T>::getData() {
    return data;
}

template<class T>
node<T>* node<T>::getNext() {
    return next;
}

template<class T>
node<T>* node<T>::getPrev() {
    return prev;
}

template<class T>
class LDLDE {
private:
    node<T>* header;
public:
    LDLDE() : header(nullptr) {};
    bool vacia() const;
    node<T>* ultimo() const;
    node<T>* primero() const;
    node<T>* anterior(node<T>* pos) const;
    void insertar(T elem);
    bool eliminar(node<T>* pos);
    void imprimir() const;
    void Ordenamiento();
    node<T>* Localiza(T);
    T Busqueda(T);

    void GuardarInformacion();
    void CargarInformacion();
};

template<class T>
void LDLDE<T>::imprimir() const {
    node<T>* aux = header;
    while (aux != nullptr) {
        std::cout << aux->getData() << std::endl;
        aux = aux->getNext();
    }
}

template<class T>
bool LDLDE<T>::eliminar(node<T>* pos) {
    if (vacia() || pos == nullptr) {
        return false;
    }
    if (pos == header) {
        header = header->getNext();
        if (header != nullptr) {
            header->setPrev(nullptr);
        }
    }
    else {
        node<T>* prevNode = pos->getPrev();
        if (pos->getNext() != nullptr) {
            pos->getNext()->setPrev(prevNode);
        }
        prevNode->setNext(pos->getNext());
    }
    delete pos;
    return true;
}

template<class T>
void LDLDE<T>::insertar(T elem) {
    node<T>* aux = new node<T>(elem);

    if (aux == nullptr) {
        std::cout << "Memoria insuficiente\n";
        return;
    }

    if (header == nullptr || elem < header->getData()) {
        aux->setNext(header);
        if (header != nullptr) {
            header->setPrev(aux);
        }
        header = aux;
    }
    else {
        node<T>* ant(header);
        while (ant->getNext() != nullptr && ant->getNext()->getData() < elem) {
            ant = ant->getNext();
        }
        aux->setNext(ant->getNext());
        aux->setPrev(ant);
        if (ant->getNext() != nullptr) {
            ant->getNext()->setPrev(aux);
        }
        ant->setNext(aux);
    }
}

template<class T>
node<T>* LDLDE<T>::anterior(node<T>* pos) const {
    if (vacia() || pos == nullptr) {
        return nullptr;
    }
    return pos->getPrev();
}

template<class T>
node<T>* LDLDE<T>::primero() const {
    return header;
}

template<class T>
node<T>* LDLDE<T>::ultimo() const {
    if (vacia()) {
        return nullptr;
    }
    node<T>* aux = header;
    while (aux->getNext() != nullptr) {
        aux = aux->getNext();
    }
    return aux;
}

template<class T>
bool LDLDE<T>::vacia() const {
    return (header == nullptr);
}



template<class T>
node<T>* LDLDE<T>::Localiza(T elm) {
    node<T>* aux = header;
    while (aux != nullptr && aux->getData() != elm) {
        aux = aux->getNext();
    }
    return aux;
}


template<class T>
T LDLDE<T>::Busqueda(T elm){
    node<T>* aux = header;
    while (aux != nullptr && aux->getData() != elm) {
        aux = aux->getNext();
    }
    return aux->getData();
    
}


template<class T>
void LDLDE<T>::GuardarInformacion() {
    std::ofstream archivo("Pasajeros.txt");

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo para guardar información.\n";
        return;
    }

    node<T>* aux = header;
    while (aux != nullptr) {
        archivo << aux->getData();  
        aux = aux->getNext();
    }

    archivo.close();
}

template<class T>
void LDLDE<T>::CargarInformacion() {
    std::ifstream archivo("Pasajeros.txt");

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo para cargar información.\n";
        return;
    }

    
    while (header != nullptr) {
        node<T>* temp = header;
        header = header->getNext();
        delete temp;
    }

    T tempData;
    while (archivo >> tempData) {  
        insertar(tempData);
    }

    archivo.close();
}
