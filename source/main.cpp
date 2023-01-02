#include <list>
#include <ctime>
#include <memory>
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
#include <UtilChecking.hpp>

enum Sorting_cars {
    BY_BRAND = 1,
    BY_COLOR = 2,
    BY_COUNTRY = 3,
    BY_MODEL = 4,
    BY_PRICE = 5,
    BY_FUEL = 6,
    CONTINUE = 7,
};
void ask_for_sorting() {
    std::cout << "Which way do you want to sort cars?\n1 - by brand\n2 - by color\n3 - by country\n4 - by model\n5 - by price\n6 - by fuel consumption\n7 - continue buying\n";
    return;
}
size_t getChoice() {
    size_t choice;
    std::cout << "Input choice:";
    std::cin >> choice;
    return choice;
}
void sorting_cars(std::list <I_Transport::PtrT> cars) {
    size_t choice;
    do {
        ask_for_sorting();
        choice = getChoice();
        switch(choice) {
            case BY_BRAND: {
                cars.sort([]( I_Transport::PtrT a,  I_Transport::PtrT b){ return a->get_brand() < b->get_brand();});
                break;
            }
            case BY_COLOR: {
                cars.sort([]( I_Transport::PtrT a,  I_Transport::PtrT b){ return a->get_color() < b->get_color();});
                break;
            }
            case BY_COUNTRY: {
                cars.sort([]( I_Transport::PtrT a,  I_Transport::PtrT b){ return a->get_country() < b->get_country();});
                break;
            }
            case BY_MODEL: {
                cars.sort([]( I_Transport::PtrT a,  I_Transport::PtrT b){ return a->get_model() < b->get_model();});
                break;
            }
            case BY_PRICE: {
                cars.sort([]( I_Transport::PtrT a,  I_Transport::PtrT b){ return a->get_price() < b->get_price();});
                break;
            }
            case BY_FUEL: {
                cars.sort([]( I_Transport::PtrT a,  I_Transport::PtrT b){ return a->get_fuel_consumption() < b->get_fuel_consumption();});
                break;
            }
            case CONTINUE:{
                continue;
            }
            default: {
                cars.sort([]( I_Transport::PtrT a,  I_Transport::PtrT b){ return a->get_brand() < b->get_brand();});
                break;
            }
        }
        display(cars);
    } while(choice != CONTINUE);
}
size_t get_id_of_wanted_car() {
    size_t wanted_car_id;
    std::cout << "Input id of wanted car:";
    std::cin >> wanted_car_id;
    return wanted_car_id;
}
void car_purchase(std::shared_ptr<I_Person> client, std::list <I_Transport::PtrT> cars ) {
    size_t wanted_car_id = get_id_of_wanted_car();
        for(auto car: cars) {
            if(wanted_car_id == car->get_id()) {
                client->add_car(car);
            }
        }
}
void display_info_about_client(std::shared_ptr<I_Person> client) {
    std::cout << "You have " << client->get_number_of_cars() << " car (s)" << std::endl;
    std::list<I_Transport::PtrT> clients_cars = client->get_cars();
    display(clients_cars); 
}
void purchasing_car_from_database(std::shared_ptr<I_Person> client, std::list <I_Transport::PtrT> cars) {
    sorting_cars(cars);
    car_purchase(client,cars);
    display_info_about_client(client);
}
void mainProblem() {
    std::list <I_Transport::PtrT> cars = get_list_of_cars();
    
    std::shared_ptr<I_Person> client = std::make_shared<Client>("Andrew", 20);
    
    // I_Transport::PtrT car1 = std::make_shared<Car>();
    // car1->inputInfo(cars);

    // frist (from database)
    purchasing_car_from_database(client,cars);
    // second (custom car)

    

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