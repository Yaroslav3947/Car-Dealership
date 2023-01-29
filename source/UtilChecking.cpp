#include "UtilChecking.hpp"

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
    print_headline();
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
    double fuel_consumption, price;
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
            >> fuel_consumption >> price >> is_new >> car_body_styles >> number_of_doors
            >> configuration >> is_need_repair >> type_of_fuel) {
        list.emplace_back(
            (new Car{id, brand, model, color, country, year_of_manufacture, fuel_consumption,
                     price, is_new, car_body_styles, number_of_doors, is_need_repair, type_of_fuel}));
    }
    in_file.close();
    return list;
}
std::vector<int> get_all_ids() {
    const std::string path_to_ids = "Id.txt";
    std::vector<int> ids;
    std::ifstream in_file;
    in_file.open(path_to_ids);
    if (!in_file) {
        throw FileOpenIssue();
    }
    int id;
    while(in_file >> id) {
        ids.push_back(id);
    }
    in_file.close();
    return ids;
}
void write_to_id_file(const int &free_id) {
    const std::string path_to_ids = "Id.txt";
    std::ofstream out_file;
    out_file.open(path_to_ids, std::fstream::app);
    if(!out_file) {
        throw FileOpenIssue();
    }
    out_file << free_id << std::endl;
}
int generate_id(const std::vector<int> &ids) {
    if(ids.size() == 0) {
        return 0;
    }
    const int max_value_of_id = 1000;
    int free_id {0};
    for(int i = 0;i < max_value_of_id;i++) {
        if(i != ids[i]) {
            free_id = i;
            write_to_id_file(free_id);
            break;
        }
    }
    if(free_id != 0)
        return free_id;

    throw NoFreeIdException();
}
void print_headline() {
 std::cout << std::setw(6) << std::left << "ID"
           << std::setw(12) << std::left << "BRAND"
           << std::setw(15) << std::left << "MODEL"
           << std::setw(23) << std::left << "COLOR"
           << std::setw(11) << std::left << "COUNTRY"
           << std::setw(10) << std::left << "YEAR"
           << std::setw(8) << std::left << "FUEL"
           << std::setw(13) << std::left << "PRICE"
           << std::setw(7) << std::left << "IS NEW"
           << std::setw(10) << std::left << "STYLE"
           << std::setw(7) << std::left << "DOORS" 
           << std::setw(11) << std::left << "CONFIG"
           << std::setw(15) << std::left << "REPAIR"
           << std::setw(7) << std::left << "FUEL" << std::endl;
}
void print_half_line(const int &size_of_line, const std::string &line) {
    for (size_t i{0}; i < (size_of_line / 2) - (line.size() / 2); i++) {
        std::cout << "=";
    }
}
void print_headline_for_greetings(const std::string &line) {
    const int size_of_line = 156;
    print_half_line(size_of_line, line);
    std::cout << line;
    print_half_line(size_of_line, line);
    std::cout << std::endl;
}
std::string hash_passwordSHA256(const std::string& password) {
    // Create a SHA-256 context
    SHA256_CTX sha256;
    // Initialize the context
    SHA256_Init(&sha256);
    // Hash the password
    SHA256_Update(&sha256, password.c_str(), password.size());
    // Store the hashed password in hash variable
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_Final(hash, &sha256);

    std::string hashed_password;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        hashed_password += hash[i];
    }

    return hashed_password;
}
void print_half_line() {
    std::cout << "===================================\n";
}
void ask_for_sorting() {
    print_half_line();
    std::cout << "Do you want to sort cars?\n1 - show way of sorting\n2 - continue buying without sorting\n";
    print_half_line();
    return;
}
char getChoice() {
    char choice;
    std::cout << "Input choice:";
    std::cin >> choice;
    return choice;
} 
void show_way_of_sorting() {
    print_half_line();
    std::cout << "Which way do you want to sort cars?\n1 - by brand\n2 - by color\n3 - by country\n4 - by model\n5 - by price\n6 - by fuel consumption\n7 - continue buying\n";
    print_half_line();
}
size_t get_id_of_wanted_car() {
    size_t wanted_car_id;
    std::cout << "Input id of wanted car:";
    std::cin >> wanted_car_id;
    return wanted_car_id;
}
void show_posibilities(std::shared_ptr<I_Person> client) {
    std::cout << client->get_name() << ", choose one variant below:\n1 - buy new car from salon\n2 - buy custom car\n3 - show my cars\n4 - repair car\n5 - quit program\n";
}
size_t get_id_of_car_to_repair() {
    size_t id;
    std::cout << "Choose car you want to repair by id\nEnter id:";
    std::cin >> id;
    return id;
}
