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