#include <iostream>

#include <Seller.hpp>

Seller::Seller(std::string name, int age, int wage, int number_of_sold_cars) 
    : I_Person{name, age}, wage{wage}, number_of_sold_cars{number_of_sold_cars} {
        if(!isNormalWage(wage)) {
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
    return wage;
}
int Seller::get_number_of_sold_cars() const {
    return number_of_sold_cars;
}
void Seller::printInfo(std::ostream &os) const {
    os << "[Seller: " <<  name << ": " << age << "y.o: $" << wage << ": " << number_of_sold_cars << " cars sold]";
}
void Seller::inputInfo(std::istream &is) {
    std::cout << "Input name:";
    is >> name;
    std::cout << "Input age:";
    is >> age;
    std::cout << "Input wage per day:";
    is >> wage;
    std::cout << "Input number of sold cars:";
    is >> number_of_sold_cars;    
    Seller(name, age, wage, number_of_sold_cars);
}