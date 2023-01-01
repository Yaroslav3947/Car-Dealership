#include <string>
#include <iostream>

#include <I_Transport.hpp>
#include <IllegalPriceException.hpp>


I_Transport::I_Transport(int id, std::string brand, std::string model, std::string color, std::string country, int year_of_manufacture, double fuel_comsumption, double price, bool is_new)
    : id{id}, model{model}, country{country}, brand{brand},color{color}, year_of_manufacture{year_of_manufacture}, fuel_comsumption{fuel_comsumption}, price{price}, is_new{is_new} {
        if(price < floor_price) {
            throw IllegalPriceException();
        }
}
void I_Transport::set_id(const size_t &id) {
    this->id = id;
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
int I_Transport::get_id() const {
    return id;
}
