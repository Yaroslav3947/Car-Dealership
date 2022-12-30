#include <iostream>

#include <Client.hpp>

Client::Client(std::string name, int age) 
    : I_Person{name, age} {
}
int Client::get_number_of_cars() const {
    return number_of_cars;
}
void Client::printInfo(std::ostream &os) const {
    os << "[Client: " <<  name << ": " << age << "y.o: "  << number_of_cars << " cars]";
}
std::vector<I_Transport *> Client::get_cars() {
    return cars;
}
void Client::add_car( I_Transport *car) {
    this->cars.push_back(car);
    number_of_cars++;
}