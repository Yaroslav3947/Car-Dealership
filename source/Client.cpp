#include <iostream>

#include "Client.hpp"

Client::Client(int id, std::string name, int age) 
    : I_Person{id, name, age} {
        this->cars = get_cars();
}
int Client::get_number_of_cars() const {
    return number_of_cars;
}
void Client::printInfo(std::ostream &os) const {
    os << "[Client: id: " <<  id << ": " << name << ": " << age << "y.o: "  << number_of_cars << " cars]";
}
void Client::add_car(I_Transport::PtrT car) {
    const std::string path_to_clients_file = "D:\\" + std::to_string(this->get_id()) + ".txt";
    std::cout << path_to_clients_file << std::endl;
    car->write_info_to_file(path_to_clients_file);
    number_of_cars++;
}
void Client::set_id(const size_t &id) {
    I_Person::set_id(id);
}
std::list<I_Transport::PtrT> Client::get_cars() {
    const std::string path_to_clients_file = "D:\\" + std::to_string(this->get_id()) + ".txt";
    bool is_new, is_need_repair;
    double fuel_consumption, price;
    int number_of_doors, year_of_manufacture;
    int id;
    std::list<I_Transport::PtrT> list;
    std::string brand, model, color, country, car_body_styles, configuration, type_of_fuel;
    std::ifstream in_file;
    in_file.open(path_to_clients_file, std::ios::app);
    if (!in_file) {
        throw FileOpenIssue();
    }
    while (in_file >> id >> brand >> model >> color >> country >> year_of_manufacture 
            >> fuel_consumption >> price >> is_new >> car_body_styles >> number_of_doors
            >> configuration >> is_need_repair >> type_of_fuel) {
        list.emplace_back(
            (new Car{id, brand, model, color, country, year_of_manufacture, fuel_consumption,
                     price, is_new, car_body_styles, number_of_doors, is_need_repair, type_of_fuel}));
    }
    in_file.close();
    return list;
}