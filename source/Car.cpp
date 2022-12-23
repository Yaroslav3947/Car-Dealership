#include <string>
#include <iostream>

#include <Car.hpp>

const int floor_for_price = 0;

Car::Car(std::string brand, std::string model, std::string country, int year_of_manufacture, double fuel_comsumption, double price, bool is_new, std::string car_body_styles, int number_of_doors, bool is_need_repair, std::string type_of_fuel)
    : I_Transport{brand, model, country, year_of_manufacture, fuel_comsumption, price, is_new}, car_body_styles{car_body_styles}, number_of_doors{number_of_doors}, is_need_repair{is_need_repair}, type_of_fuel{type_of_fuel} {
        set_configuration();
        
}
void Car::printInfo(std::ostream &os) const {
    os << "[Car: " << brand << ": " << model << ": " << country << ": " << year_of_manufacture << " year: " << fuel_comsumption << "lit/100km: $" << price << ": ";
    if (is_new)
        os << "new: ";
    else
        os << "used: ";
    os << car_body_styles << ": " << number_of_doors << " doors: " << configuration << ": ";
    if (is_need_repair)
        os << "need repair: ";
    else
        os << "doesn't need repair: ";
    os << type_of_fuel << "]";
}
void Car::set_configuration() {
    const double floor_for_price = 0.0;
    const double price_for_vip = 50000.0;
    const double price_for_econom = 5000.0;
    const double price_for_standart = 25000.0;
    if(price > floor_for_price && price < price_for_econom ) {
        configuration = "econom";
    }
    else if(price >= price_for_standart && price < price_for_vip) {
        configuration = "standart";
    } else if( price >= price_for_vip && price < INT64_MAX) {
        configuration = "vip";
    }
    else {
        configuration = "no configuration";
    }
}
int Car::get_number_of_doors() const {
    return number_of_doors;
}
bool Car::get_is_need_repair() const {
    return is_need_repair;
}
std::string Car::get_type_of_fuel() const {
    return type_of_fuel;
}
std::string Car::get_configuration() const {
    return configuration;
}
std::string Car::get_car_body_styles() const {
    return car_body_styles;
}