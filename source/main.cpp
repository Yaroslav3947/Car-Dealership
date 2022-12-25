#include <iostream>
#include <vector>

#include <Car.hpp>
#include <Login.hpp>
#include <Client.hpp>
#include <Worker.hpp>
#include <Seller.hpp>
#include <I_Person.hpp>
#include <I_Transport.hpp>

int main() {
    try {
        I_Transport *c1 = new Car();
        // I_Transport *c2 = new Car();
        c1->inputInfo();
        // std::vector<I_Transport*> cars{c1};
        // for(auto x : cars) {
        //     x->inputInfo();
        // }
        // for(const auto x : cars) {
        //     std::cout << *x << std::endl;
        // }
        std::cout << *c1 << std::endl;
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

    // I_Transport *c1 = new Car();
    // // std::cin >> *c1;
    // I_Person *w1 = new Worker("And", 18,12,1);
    // std::cout << *c1 << std::endl;
    // std::cout << w1->get_name();
    


    
    return 0;
}