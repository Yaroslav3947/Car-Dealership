#include <UtilChecking.hpp>

bool isNormalWage(const int &wage) {
    const int minimunWage = 20;
    const int maximumWage = 100;
    return wage > minimunWage && wage < maximumWage;
}
bool isNormalAge(const int &age) {
    const int acceptedAge = 18;
    return age >= acceptedAge;
}
bool isPositiveNumber(const double &num) {
    const double bound = 0.0;
    return num >= bound;
}
bool isNormalYearForCar(const int &num) {
    const int yearOfFirstCar = 1886;
    const int ceilOfCarYear = 2023;
    return yearOfFirstCar <= num &&  num <= ceilOfCarYear;
}
template <typename T>
void display(const std::list<T*> list) {
    for(const auto x: list) {
        std::cout << *x << std::endl;
    }
}
void get_list_of_cars(std::list<I_Transport *> &list) {
    const std::string path_to_car_file{"Car.txt"};
    bool is_new, is_need_repair;
    double fuel_comsumption, price;
    int number_of_doors, year_of_manufacture;
    std::string brand, model, color, country, car_body_styles, configuration, type_of_fuel;
    std::ifstream in_file;
    in_file.open(path_to_car_file);
    if (!in_file) {
        throw FileOpenIssue();
    }
    while (in_file >> brand >> model >> color >> country >> year_of_manufacture 
            >> fuel_comsumption >> price >> is_new >> car_body_styles >> number_of_doors
            >> configuration >> is_need_repair >> type_of_fuel) {
        list.emplace_back(
            (new Car{brand, model, color, country, year_of_manufacture, fuel_comsumption,
                     price, is_new, car_body_styles, number_of_doors, is_need_repair, type_of_fuel}));
    }
    in_file.close();
}