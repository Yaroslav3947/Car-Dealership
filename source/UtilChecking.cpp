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
void display(const std::list<I_Transport*> list) {
    for(const auto x: list) {
        std::cout << *x << std::endl;
    }
}
void print_headline_in_file() {
    const std::string path_to_car_file{"Car.txt"};
    std::ofstream out_file;
    size_t field_size1 = 15;
    size_t field_size2 = 20;
    size_t field_size3 = 25;
    out_file.open(path_to_car_file, std::fstream::app);
    if(!out_file.is_open()) {
        throw FileOpenIssue();
    }
    out_file << std::setw(field_size1) << std::left << "Brand" << std::setw(field_size1) << std::left << "Model" << std::setw(field_size3) << std::left << "Color" << std::setw(field_size2) << std::left << "Country" << std::setw(field_size1) << std::left << "Year" << std::setw(field_size1)  << std::left << "Fuel_comps." << std::setw(field_size1) << std::left << "Price" << std::setw(field_size1) << std::left
                << "Is_new" << std::setw(field_size1) << std::left << "Style" << std::setw(field_size1)  << std::left << "Doors" << std::setw(field_size1) << std::left << "Config." << std::setw(field_size1) << std::left << "Need_Repair" << std::setw(field_size1) << std::left << "Fuel" << std::endl;
    out_file.close();
}