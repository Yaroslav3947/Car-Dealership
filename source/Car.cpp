#include <string>
#include <vector>
#include <iostream>

#include <Car.hpp>


Car::Car(std::string brand, std::string model, std::string color, std::string country, int year_of_manufacture, double fuel_comsumption, double price, bool is_new, std::string car_body_styles, int number_of_doors, bool is_need_repair, std::string type_of_fuel)
    : I_Transport{brand, model, color, country, year_of_manufacture, fuel_comsumption, price, is_new}, car_body_styles{car_body_styles}, number_of_doors{number_of_doors}, is_need_repair{is_need_repair}, type_of_fuel{type_of_fuel} {
        set_configuration();
}
void Car::printInfo(std::ostream &os) const {
    os << "[Car: " << brand << ": " << model << ": " << color << ": " << country << ": " << year_of_manufacture << " year: " << fuel_comsumption << "lit/100km: $" << price << ": ";
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
enum Car_colors {
    Long_Beach_Blue = 1,Arrow_Gray = 2,
        Purple_Sector = 3,Mint_Green = 4,
        Thundernight_Metallic = 5,Electric_Blue = 6,
        Amplify_Orange = 7,Stryker_Red = 8,
        Bianco_Courmayeur = 9,Blue_Ember = 10
};
enum Car_body_style {
    SEDAN = 1, COUPE = 2, VAN = 3, JEEP = 4, HATCHBACK = 5
};
enum Type_of_fuel {
    Gas = 1, Diesel = 2
};
enum Is_need_repair {
    YES = 1, NO = 2
};
void print_preferences_of(const std::vector <std::string> &vec) {
    for(size_t i{0};i<vec.size();i++) {
        std::cout << i + 1 << " - " << vec[i] << std::endl;
    }
    std::cout << ": ";
}
void input_car_body_style(std::string &car_body_styles) {
    std::vector<std::string> styles {
        "Sedan","Coupe","Van","Jeep","hatchback"
    };
    std::cout << "Choose one of the styles below:\n";
    print_preferences_of(styles);
    Car_body_style style;
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
void input_type_of_fuel(std::string &type_of_fuel) {
    Type_of_fuel fuel_type;
    std::cout << "Input type of fuel:\n1 - Gas\n2 - Diesel: ";
    int choice{};
    std::cin >> choice;
    switch(choice) {
        case Gas: type_of_fuel = "Gas";break;
        case Diesel: type_of_fuel = "Diesel";break;
        default: type_of_fuel = "no type of fuel";break;
    }
}
void input_is_need_repair(bool &is_need_repair) {
    Type_of_fuel need_repair;
    std::cout << "Input if car need repair:\n1 - yes\n2 - no: ";
    int choice{};
    std::cin >> choice;
    switch(choice) {
        case YES: is_need_repair = true;break;
        case NO: is_need_repair = false;break;
        default: is_need_repair = true;break;
    }
}
void set_number_of_doors(const std::string &car_body_styles, int &number_of_doors) {
    if(car_body_styles == "Coupe") 
        number_of_doors = 3;
    else
        number_of_doors = 5;
}

void input_color(std::string &color) {
    Car_colors car_clr;
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
void Car::inputInfo() {
    std::cout << "Input brand:"; 
    std::cin >> brand;
    std::cout << "Input model:";
    std::cin >> model;
    std::cout << "Input country:";
    std::cin >> country;
    input_color(color);
    std::cout << "Input year of manufacture:";
    std::cin >> year_of_manufacture;
    std::cout << "Input fuel comsumption lit. per 100 km:";
    std::cin >> fuel_comsumption;
    std::cout << "Input price: $";
    std::cin >> price;
    input_car_body_style(car_body_styles);
    set_number_of_doors(car_body_styles, number_of_doors);
    input_type_of_fuel(type_of_fuel);
    input_is_need_repair(is_need_repair);
    set_configuration();
    
    Car(brand, model, color, country, year_of_manufacture, fuel_comsumption, price, is_new,
        car_body_styles, number_of_doors, is_need_repair, type_of_fuel);
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