#include <string>
#include <iostream>

#include <I_Transport.hpp>
#include <IllegalPriceException.hpp>


I_Transport::I_Transport(std::string brand, std::string model, std::string color, std::string country, int year_of_manufacture, double fuel_comsumption, double price, bool is_new)
    : model{model}, country{country}, brand{brand},color{color}, year_of_manufacture{year_of_manufacture}, fuel_comsumption{fuel_comsumption}, price{price}, is_new{is_new} {
        if(price < floor_for_price) {
            throw IllegalPriceException();
        }
}
void I_Transport::printInfo(std::ostream &os) const {
    os << "[Transport: " << brand << ": " << model << ": " << color << ": " << country << ": " << year_of_manufacture << " year: " << fuel_comsumption << "lit/100km: $" << price << ": ";
    if (is_new)
        os << "new]";
    else
        os << "used]";
}
void I_Transport::inputInfo(std::istream &is) {
    std::cout << "Input brand:";
    is >> brand;
    std::cout << "Input model:";
    is >> model;
    std::cout << "Input color:";
    is >> color;
    std::cout << "Input country:\n1 - Germany/2 - Italy";
    is >> country;
    std::cout << "Input year of manufacture:";
    is >> year_of_manufacture;
    std::cout << "Input fuel comsumption:";
    is >> fuel_comsumption;
    std::cout << "Input price:";
    is >> price;
    std::cout << "Input if car is new:";
    is >> is_new;
    I_Transport(brand, model, color, country, year_of_manufacture, fuel_comsumption, price, is_new);
}
bool I_Transport::get_is_new() const {
    return is_new;
}
double I_Transport::get_price() const {
    return price;
}
std::string I_Transport::get_brand() const {
    return brand;
}
std::string I_Transport::get_color() const {
    return color;
}
std::string I_Transport::get_model() const {
    return model;
}
std::string I_Transport::get_country() const {
    return country;
}
int I_Transport::get_year_of_manufacture() const {
    return year_of_manufacture;
}
double I_Transport::get_fuel_comsumption() const {
    return fuel_comsumption;
}
