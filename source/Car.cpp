#include <memory>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <iostream>

#include "Car.hpp"

Car::Car(int id, std::string brand, std::string model, std::string color, std::string country, int year_of_manufacture, double fuel_consumption, double price, bool is_new, std::string car_body_styles, int number_of_doors, bool is_need_repair, std::string type_of_fuel)
    : I_Transport{id, brand, model, color, country, year_of_manufacture, fuel_consumption, price, is_new}, car_body_styles{car_body_styles}, number_of_doors{number_of_doors}, is_need_repair{is_need_repair}, type_of_fuel{type_of_fuel} {
        set_number_of_doors(car_body_styles, number_of_doors);
        set_configuration();
}
void Car::printInfo(std::ostream &os) const {
        os << "["  << std::setw(5) << std::left << id
           << std::setw(12) << std::left << brand
           << std::setw(15) << std::left << model
           << std::setw(23) << std::left << color
           << std::setw(11) << std::left << country
           << std::setw(10) << std::left << year_of_manufacture
           << std::setw(8) << std::left << fuel_consumption
           << std::setw(13) << std::left << price;
        if (is_new)
            os << std::setw(7) << std::left << "new";
        else
            os << std::setw(7) << std::left << "used";
        os << std::setw(10) << std::left << car_body_styles
           << std::setw(7) << std::left << number_of_doors 
           << std::setw(11) << std::left << configuration;
        if (is_need_repair)
            os << std::setw(15) << std::left << "need";
        else
            os << std::setw(15) << std::left << "doesn't_need";
        os << std::setw(7) << std::left << type_of_fuel << "]";
}

void Car::write_info_to_file(const std::string &path) {
    const int field_size1 = 15;
    const int field_size2 = 20;
    const int field_size3 = 25;
    std::ofstream out_file;
    out_file.open(path, std::fstream::app);
    if(!out_file.is_open()) {
        throw FileOpenIssue();
    }
    out_file << std::setw(field_size1) << std::left << this->id << std::setw(field_size1) << std::left <<  this->brand << std::setw(field_size1) 
             << std::left <<  this->model <<  std::setw(field_size3) << std::left << this->color << std::setw(field_size2) << std::left << this->country
             << std::setw(field_size1) <<std::left << this->year_of_manufacture << std::setw(field_size1) << std::left << this->fuel_consumption
             << std::setw(field_size1) << std::left << this->price << std::setw(field_size1) << std::left << this->is_new << std::setw(field_size1) 
             << std::left << this->car_body_styles << std::setw(field_size1) << std::left << this->number_of_doors << std::setw(field_size1) 
             << std::left << this->configuration << std::setw(field_size1)  << std::left << this->is_need_repair
             << std::setw(field_size1) << std::left << this->type_of_fuel << std::endl;
    out_file.close();
}
void print_preferences_of(const std::vector <std::string> &vec) {
    for(size_t i{0};i<vec.size();i++) {
        std::cout << i + 1 << " - " << vec[i] << std::endl;
    }
    std::cout << ": ";
}
enum Car_body_style {
    SEDAN = 1, COUPE = 2, VAN = 3, JEEP = 4, HATCHBACK = 5
};
void input_car_body_style(std::string &car_body_styles) {
    std::vector<std::string> styles {
        "Sedan","Coupe","Van","Jeep","hatchback"
    };
    std::cout << "Choose one of the styles below:\n";
    print_preferences_of(styles);
    int choice{};
    std::cin >> choice;
    switch(choice) {
        case SEDAN: car_body_styles = styles[0];break;
        case COUPE: car_body_styles = styles[1];break;
        case VAN: car_body_styles = styles[2];break;
        case JEEP: car_body_styles = styles[3];break;
        case HATCHBACK: car_body_styles = styles[4];break;
        default: car_body_styles = "no car body style";break;
    }
}
enum Type_of_fuel {
    Gas = 1, Diesel = 2
};
void input_type_of_fuel(std::string &type_of_fuel) {
    std::cout << "Input type of fuel:\n1 - Gas\n2 - Diesel: ";
    int choice{};
    std::cin >> choice;
    switch(choice) {
        case Gas: type_of_fuel = "Gas";break;
        case Diesel: type_of_fuel = "Diesel";break;
        default: type_of_fuel = "no_fuel";break;
    }
}
enum Is_need_repair {
    YES = 1, NO = 2
};
void input_is_need_repair(bool &is_need_repair) {
    std::cout << "Input if car need repair:\n1 - yes\n2 - no: ";
    int choice{};
    std::cin >> choice;
    switch(choice) {
        case YES: is_need_repair = true;break;
        case NO: is_need_repair = false;break;
        default: is_need_repair = true;break;
    }
}
void Car::set_number_of_doors(const std::string &car_body_styles, int &number_of_doors) {
    if(car_body_styles == "Coupe") 
        number_of_doors = 3;
    else
        number_of_doors = 5;
}
enum Car_colors {
    Long_Beach_Blue = 1,Arrow_Gray = 2,
        Purple_Sector = 3,Mint_Green = 4,
        Thundernight_Metallic = 5,Electric_Blue = 6,
        Amplify_Orange = 7,Stryker_Red = 8,
        Bianco_Courmayeur = 9,Blue_Ember = 10
};
void input_color(std::string &color) {
    std::vector<std::string> car_colors {
        "Long_Beach_Blue","Arrow_Gray",
        "Purple_Sector","Mint_Green",
        "Thundernight_Metallic","Electric_Blue",
        "Amplify_Orange","Stryker_Red",
        "Bianco_Courmayeur","Blue_Ember"
    };
    std::cout << "Choose one of the color below:\n";
    print_preferences_of(car_colors);
    int choice{};
    std::cin >> choice;
    switch(choice) {
        case Long_Beach_Blue: color = car_colors[0];break;
        case Arrow_Gray: color = car_colors[1];break;
        case Purple_Sector: color = car_colors[2];break;
        case Mint_Green: color = car_colors[3];break;
        case Thundernight_Metallic: color = car_colors[4];break;
        case Electric_Blue: color = car_colors[5];break;
        case Amplify_Orange: color = car_colors[6];break;
        case Stryker_Red: color = car_colors[7];break;
        case Bianco_Courmayeur: color = car_colors[8];break;
        case Blue_Ember: color = car_colors[9];break;
        default: color = "no color";break;
    }
}
void input_price(double &price) {
    std::cout << "Input price: $";
    std::cin >> price;
    if(!isPositiveNumber(price)) {
        throw IllegalPriceException();
    }
}
void input_fuel_consumption(double &fuel_consumption) {
    std::cout << "Input fuel comsumption lit. per 100 km:";
    std::cin >> fuel_consumption;
    if(!isPositiveNumber(fuel_consumption)) {
        throw IllegalFuelComsumptionException();
    }
}
void input_year_of_manufacture(int &year_of_manufacture) {
    std::cout << "Input year of manufacture:";
    std::cin >> year_of_manufacture;
    if(!isNormalYearForCar(year_of_manufacture)) {
        throw IllegalYearOfManufactureException();
    }
}
void input_country(std::string &country) {
    std::cout << "Input country:";
    std::cin >> country;
}
void input_model(std::string &model) {
    std::cout << "Input model:";
    std::cin >> model;
}
void input_brand(std::string &brand) {
    std::cout << "Input brand:"; 
    std::cin >> brand;
}
void Car::inputInfo(std::list <PtrT> &cars) {
    input_brand(brand);
    input_model(model);
    input_country(country);
    input_color(color);
    input_year_of_manufacture(year_of_manufacture);
    input_fuel_consumption(fuel_consumption);
    input_price(price);
    input_car_body_style(car_body_styles);
    set_number_of_doors(car_body_styles, number_of_doors);
    input_type_of_fuel(type_of_fuel);
    input_is_need_repair(is_need_repair);
    set_configuration();
    set_number_of_doors(car_body_styles, number_of_doors);
    std::vector<int> all_ids = get_all_ids();
    this->id = generate_id(all_ids);
    this->write_info_to_file(path_to_car_file);
    cars.push_back(shared_from_this());
}
void Car::set_configuration() {
    const double floor_price = 0.0;
    const double ceil_price_for_econom = 5000.0;
    const double ceil_price_for_vip = INT64_MAX;
    const double ceil_price_for_standart = 25000.0;
    if(floor_price < price && price <= ceil_price_for_econom ) { 
        configuration = "econom";
    }
    else if(ceil_price_for_econom < price && price <= ceil_price_for_standart) {  
        configuration = "standart";
    } else if( ceil_price_for_standart < price && price < ceil_price_for_vip) { 
        configuration = "vip";
    }
    else {
        configuration = "no_config";
    }
}
void Car::set_is_need_repair(const bool &is_need_repair) {
    this->is_need_repair = is_need_repair;
}
void Car::set_id(const size_t &id) {
    I_Transport::set_id(id);
}
