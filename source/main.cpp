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
    std::cout << "Do you want to sort cars?\n1 - show way of sorting\n2 - continue buying without sorting\n";
    return;
}
size_t getChoice() {
    size_t choice;
    std::cout << "Input choice:";
    std::cin >> choice;
    return choice;
} 
void show_way_of_sorting() {
    std::cout << "===================================\n";
    std::cout << "Which way do you want to sort cars?\n1 - by brand\n2 - by color\n3 - by country\n4 - by model\n5 - by price\n6 - by fuel consumption\n7 - continue buying\n";
    std::cout << "===================================\n";
}
void sorting_cars(std::list <I_Transport::PtrT> cars) {
    size_t choice;
    do {
        show_way_of_sorting();
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
                break;
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
void car_purchase(std::shared_ptr<I_Person> client,const std::list <I_Transport::PtrT> &cars) {
    size_t wanted_car_id = get_id_of_wanted_car();
        for(auto car: cars) {
            if(wanted_car_id == car->get_id()) {
                client->add_car(car);
            }
        }
}
void display_info_about_client(std::shared_ptr<I_Person> client) {
    const int singular_car = 1;
    std::cout << "=====================================================================MY_CARS=====================================================================\n";
    if(client->get_number_of_cars() == singular_car) {
        std::cout << client->get_name() << ", you have " << client->get_number_of_cars() << " car " << std::endl;
    }
    else {
        std::cout << client->get_name() << ", you have " << client->get_number_of_cars() << " cars" << std::endl;
    }
    std::list<I_Transport::PtrT> clients_cars = client->get_cars();
    display(clients_cars); 
    std::cout << "=====================================================================MY_CARS=====================================================================\n";
}
enum Sorting_option {
    SORT = 1,
    CONTINUE_BUYING = 2,
};
void print_cars_headline() {
    std::cout << "=======================================================CARS==============================================================================\n";
}
void purchasing_car_from_database(std::shared_ptr<I_Person> client, const std::list <I_Transport::PtrT> &cars) {
    print_cars_headline();
    display(cars);
    print_cars_headline();
    ask_for_sorting();
    size_t choice;
    do {
        choice = getChoice();
        switch (choice) {
            case SORT: {
                sorting_cars(cars);
                break;
            }
            case CONTINUE_BUYING: {
                continue;
            }
            default : {
                std::cout << "We have only 2 option, you did something wrong" << std::endl;
            }
        }
    } while(choice != CONTINUE_BUYING && choice != SORT);
    car_purchase(client,cars);
    display_info_about_client(client);
}
void purchasing_custom_car(std::shared_ptr<I_Person> client, std::list <I_Transport::PtrT> &cars) {
    I_Transport::PtrT custom_car = std::make_shared<Car>();
    custom_car->inputInfo(cars);
    client->add_car(custom_car);
    display_info_about_client(client);
}
enum TypeOfPurchasing {
    DATABASE = 1,
    CUSTOM = 2,
    MY_CARS = 3,
    QUIT = 4,
};
void show_posibilities(std::shared_ptr<I_Person> client) {
    std::cout << client->get_name() << ", choose one variant below:\n1 - buy new car from database\n2 - buy custom car\n3 - show my cars\n4 - quit program\n";
}
void show_clients_cars(std::shared_ptr<I_Person> client) {
    if(client->get_number_of_cars() == 0) { ////TODO: magic number
        std::cout << client->get_name() << ", you do not have any cars, go to the shop and buy one!!!\n"; 
    }
    else {
        display_info_about_client(client);
    }
}
void main_drive(std::shared_ptr<I_Person> client, std::list <I_Transport::PtrT> &cars) {
    size_t choice;
    do {
        show_posibilities(client);
        choice = getChoice();
        switch (choice) {
            case DATABASE: {
                purchasing_car_from_database(client,cars);
                break;
            }
            case CUSTOM: {
                purchasing_custom_car(client, cars);
                break;
            }
            case MY_CARS : {
                show_clients_cars(client);
            }
            case QUIT: {
                break;
            }
            default: {
                std::cout << "We have only 4 options" << std::endl;
            }
        }
    } while(choice != QUIT);
}
std::string get_name() {
    std::string name;
    std::cout << "Enter your name:";
    std::cin >> name;
    return name;
}
size_t get_age() {
    size_t age;
    std::cout << "How old are you:";
    std::cin >> age;
    return age;    
}
void greetings(std::string &name, size_t &age) {
    std::cout << "=====================================================================================================================================\n";
    std::cout << "Hello\nWelome to our company\n";
    name = get_name();
    age = get_age();
    return;
}
auto input_info_about_client() {
    size_t age{};
    std::string name{};
    greetings(name, age);
    return std::make_shared<Client>(name, age);
}
void mainProblem() {
    std::list <I_Transport::PtrT> cars = get_list_of_cars();
    // Login login;
    // login.startToLogin();
    std::shared_ptr<I_Person> client = input_info_about_client();    
    main_drive(client, cars);

    return; 
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