#include <iostream>
#include <iomanip>

class Pasajero {

private:
    std::string nombre_pasajero, origen, destino, fecha_salida, hora_salida, fecha_llegada, hora_llegada;

public:
    Pasajero();
    void setNombre(const std::string&);
    void setOrigen(const std::string&);
    void setDestino(const std::string&);
    void setFechaLlegada(const std::string&);
    void setFechaSalida(const std::string&);
    void setHoraLlegada(const std::string&);
    void setHoraSalida(const std::string&);

    std::string getNombre() const;
    std::string getOrigen() const;
    std::string getDestino() const;
    std::string getFechaLlegada() const;
    std::string getFechaSalida() const;
    std::string getHoraLlegada() const;
    std::string getHoraSalida() const;

    friend std::ostream& operator<<(std::ostream& os, const Pasajero& pasajero);
    friend std::istream& operator>>(std::istream& is, Pasajero& pasajero);
    friend bool operator<(const Pasajero& lhs, const Pasajero& rhs);
    friend bool operator>(const Pasajero& lhs, const Pasajero& rhs);
    friend bool operator==(const Pasajero& lhs, const Pasajero& rhs);
    friend bool operator!=(const Pasajero& lhs, const Pasajero& rhs);
};

void Pasajero::setNombre(const std::string& name) { nombre_pasajero = name; }
void Pasajero::setOrigen(const std::string& org) { origen = org; }
void Pasajero::setDestino(const std::string& dest) { destino = dest; }
void Pasajero::setFechaLlegada(const std::string& fechll) { fecha_llegada = fechll; }
void Pasajero::setFechaSalida(const std::string& fechSal) { fecha_salida = fechSal; }
void Pasajero::setHoraLlegada(const std::string& horall) { hora_llegada = horall; }
void Pasajero::setHoraSalida(const std::string& horaSal) { hora_salida = horaSal; }

std::string Pasajero::getNombre() const { return nombre_pasajero; }
std::string Pasajero::getDestino() const { return destino; }
std::string Pasajero::getOrigen() const { return origen; }
std::string Pasajero::getFechaLlegada() const { return fecha_llegada; }
std::string Pasajero::getFechaSalida() const { return fecha_salida; }
std::string Pasajero::getHoraLlegada() const { return hora_llegada; }
std::string Pasajero::getHoraSalida() const { return hora_salida; }

Pasajero::Pasajero() {
    std::cin.ignore();
    nombre_pasajero = " ";
    destino = " ";
    origen = " ";
    fecha_llegada = " ";
    fecha_salida = " ";
    hora_llegada = " ";
    hora_salida = "  ";
}

std::ostream& operator<<(std::ostream& os, const Pasajero& pasajero) {
    os << std::setw(15) << pasajero.getNombre()
       << std::setw(15) << pasajero.getOrigen()
       << std::setw(15) << pasajero.getDestino()
       << std::setw(15) << pasajero.getFechaSalida()
       << std::setw(15) << pasajero.getHoraSalida()
       << std::setw(15) << pasajero.getFechaLlegada()
       << std::setw(15) << pasajero.getHoraLlegada();
    return os;
}

std::istream& operator>>(std::istream& is, Pasajero& pasajero) {
    std::cout << "Nombre: ";
    std::getline(is, pasajero.nombre_pasajero);

    std::cout << "Origen: ";
    std::getline(is, pasajero.origen);

    std::cout << "Destino: ";
    std::getline(is, pasajero.destino);

    std::cout << "Fecha de salida: ";
    std::getline(is, pasajero.fecha_salida);

    std::cout << "Hora de salida: ";
    std::getline(is, pasajero.hora_salida);

    std::cout << "Fecha de llegada: ";
    std::getline(is, pasajero.fecha_llegada);

    std::cout << "Hora de llegada: ";
    std::getline(is, pasajero.hora_llegada);

    return is;
}

bool operator<(const Pasajero& lhs, const Pasajero& rhs) {
    return lhs.nombre_pasajero < rhs.nombre_pasajero;
}

bool operator>(const Pasajero& lhs, const Pasajero& rhs) {
    return rhs.nombre_pasajero < lhs.nombre_pasajero;
}

bool operator==(const Pasajero& lhs, const Pasajero& rhs) {
    return lhs.nombre_pasajero == rhs.nombre_pasajero;

}

bool operator!=(const Pasajero& lhs, const Pasajero& rhs) {
    return !(lhs == rhs);
}
