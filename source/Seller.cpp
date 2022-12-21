#include <iostream>

#include <Seller.hpp>

Seller::Seller(std::string name, int age, int wage_per_day, int number_of_sold_cars) 
    : I_Person{name, age}, wage_per_day{wage_per_day}, number_of_sold_cars{number_of_sold_cars} {
        if(!isNormalWage(wage_per_day)) {
            throw IllegalWageException();
        }
        if(!isNormalAge(age)) {
            throw IllegalAgeException();
        }
        if(!isNormalNumberOfRepairedOrSoldCars(number_of_sold_cars)) {
            throw IllegalNumberOfRepairedOrSoldCarsException();
        }
}
int Seller::get_code_of_seller() const {
    return code_of_seller;
}
int Seller::get_wage_per_day() const {
    return wage_per_day;
}
int Seller::get_number_of_sold_cars() const {
    return number_of_sold_cars;
}
////TODO: workout what's wrong
int Seller::get_age() const {
    return age;
}
std::string Seller::get_name() const {
    return name;
}
void Seller::printInfo(std::ostream &os) const {
    os << "[Seller: " <<  name << ": " << age << "y.o: $" << wage_per_day << ": " << number_of_sold_cars << " cars sold]";
}