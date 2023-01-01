#include <iostream>

#include <Client.hpp>

Client::Client(std::string name, int age) 
    : I_Person{name, age} {
}
int Client::get_number_of_cars() const {
    return number_of_cars;
}
void Client::printInfo(std::ostream &os) const {
    os << "[Client: id :" <<  id << ": " << name << ": " << age << "y.o: "  << number_of_cars << " cars]";
}
std::vector<I_Transport::PtrT> Client::get_cars() {
    return cars;
}
void Client::add_car(I_Transport::PtrT car) {
    this->cars.push_back(car);
    number_of_cars++;
}
void Client::set_id(const size_t &id) {
    I_Person::set_id(id);
}
