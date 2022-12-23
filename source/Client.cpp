#include <iostream>

#include <Client.hpp>

Client::Client(std::string name, int age) 
    : I_Person{name, age} {
        if(!isNormalAge(age)) {
            throw IllegalAgeException();
        }
}
int Client::get_number_of_cars() const {
    return number_of_cars;
}
void Client::printInfo(std::ostream &os) const {
    os << "[Client: " <<  name << ": " << age << "y.o: "  << number_of_cars << " cars]";
}