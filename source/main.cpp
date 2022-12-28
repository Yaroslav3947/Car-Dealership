#include <list>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

#include <Car.hpp>
#include <Login.hpp>
#include <Client.hpp>
#include <Worker.hpp>
#include <Seller.hpp>
#include <I_Person.hpp>
#include <I_Transport.hpp>

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

void mainProblem() {
    std::list <I_Transport *> cars;
    get_list_of_cars(cars);
    // I_Transport *c1 = new Car("BMW", "M3", "Arrow_Gray", "Germany", 2022, 12.1, 50000, 1, "Coupe", 0, "Diesel");
    // I_Transport *c2 = new Car("AUDI", "M3", "Arrow_Gray", "Germany", 2021, 12.1, 50000, 1, "Coupe", 0, "Diesel");
    // I_Transport *c3 = new Car();
    // cars.push_back(c1);
    // cars.push_back(c2);
    // cars.push_back(c3);
    
    // cars.sort([](I_Transport *a, I_Transport *b){ return a->get_fuel_comsumption() < b->get_fuel_comsumption();});
    display(cars);
}
int main() {
    
    try {
        mainProblem();
    }
    catch(const FileOpenIssue& e) {
        std::cerr << e.what() << '\n';
    }
    catch(const IllegalAgeException& e) {
        std::cerr << e.what() << '\n';
    }
    catch(const IllegalWageException& e) {
        std::cerr << e.what() << '\n';
    }
    catch(const IllegalPriceException& e) {
        std::cerr << e.what() << '\n';
    }    
    catch(const IllegalFuelComsumptionException& e) {
        std::cerr << e.what() << '\n';
    }
    catch(const IllegalYearOfManufactureException& e) {
        std::cerr << e.what() << '\n';
    }
    catch(const IllegalNumberOfRepairedOrSoldCarsException& e) {
        std::cerr << e.what() << '\n';
    }
    return 0;
}