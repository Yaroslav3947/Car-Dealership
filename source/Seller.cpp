#include <iostream>

#include <Seller.hpp>

Seller::Seller(int id, std::string name, int age, int wage, int number_of_sold_cars) 
    :I_Person{id, name, age}, wage{wage}, number_of_sold_cars{number_of_sold_cars} {
}
int Seller::get_code_of_seller() const {
    return code_of_seller;
}
int Seller::get_number_of_sold_cars() const {
    return number_of_sold_cars;
}
void Seller::printInfo(std::ostream &os) const {
    os << "[Seller: " <<  name << ": " << age << "y.o: $" << wage << ": " << number_of_sold_cars << " cars sold]";
}
