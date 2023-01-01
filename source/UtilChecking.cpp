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
void display(std::list <I_Transport::PtrT> list) {
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

std::list<I_Transport::PtrT> get_list_of_cars() {
    const std::string path_to_car_file{"Car.txt"};
    bool is_new, is_need_repair;
    double fuel_comsumption, price;
    int number_of_doors, year_of_manufacture;
    int id;
    std::list<I_Transport::PtrT> list;
    std::string brand, model, color, country, car_body_styles, configuration, type_of_fuel;
    std::ifstream in_file;
    in_file.open(path_to_car_file);
    if (!in_file) {
        throw FileOpenIssue();
    }
    while (in_file >> id >> brand >> model >> color >> country >> year_of_manufacture 
            >> fuel_comsumption >> price >> is_new >> car_body_styles >> number_of_doors
            >> configuration >> is_need_repair >> type_of_fuel) {
        list.emplace_back(
            (new Car{id, brand, model, color, country, year_of_manufacture, fuel_comsumption,
                     price, is_new, car_body_styles, number_of_doors, is_need_repair, type_of_fuel}));
    }
    in_file.close();
    return list;
}
std::vector<int> get_ids_from_cars(std::list<I_Transport::PtrT> &cars) {
    std::vector <int> ids;
    for(auto x: cars) {
        std::cout << x->get_id() << std::endl;
        ids.push_back(x->get_id());
    }
    return ids;
}
int generate_id(const std::vector<int> &ids) {
    if(ids.size() == 0) {
        return 0;
    }
    const size_t max_value_of_id = 1000;
    int free_id {0};
    for(size_t i = 0;i<max_value_of_id;i++) {
        if(i != ids[i]) {
            free_id = i; break;
        }
    }
    if(free_id != 0)
        return free_id;

    // throw NoFreeIdException();
}

