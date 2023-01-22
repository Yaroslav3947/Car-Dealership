#include <list>
#include <ctime>
#include <memory>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

#include "Car.hpp"
#include "Login.hpp"
#include "Client.hpp"
#include "Worker.hpp"
#include "Seller.hpp"
#include "I_Person.hpp"
#include "I_Transport.hpp"
#include "UtilChecking.hpp"

enum Sorting_cars {
    BY_BRAND = '1',
    BY_COLOR = '2',
    BY_COUNTRY = '3',
    BY_MODEL = '4',
    BY_PRICE = '5',
    BY_FUEL = '6',
    CONTINUE = '7',
};
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
void sorting_cars(std::list <I_Transport::PtrT> cars) {
    char choice;
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
void car_purchase(std::shared_ptr<Client> client, const std::list <I_Transport::PtrT> &cars) {
    std::shared_ptr<Seller> seller = std::make_shared<Seller>(-1,"Petro", 34, 54);
    int wanted_car_id = get_id_of_wanted_car();
    bool is_bought = false;
        for(auto car: cars) {
            if(wanted_car_id == car->get_id()) {
                is_bought = true;
                client->add_car(car);
                seller->sell_car(car, client);
            }
        }
        if(is_bought == false) {
            std::cout << "We do not have car with this id\n";
        }
}
void display_info_about_client(std::shared_ptr<Client> client) {
    print_headline_for_greetings("MY_CARS"); 
    const int singular_car = 1;
    std::list<I_Transport::PtrT> clients_cars = client->get_cars();
    if(clients_cars.size() == singular_car) {
        std::cout << client->get_name() << ", you have " << clients_cars.size() << " car " << std::endl;
    }
    else {
        std::cout << client->get_name() << ", you have " << clients_cars.size() << " cars" << std::endl;
    }
    display(clients_cars);
    print_headline_for_greetings("MY_CARS"); 
}
enum Sorting_option {
    SORT = '1',
    CONTINUE_BUYING = '2',
};
void purchasing_car_from_database(std::shared_ptr<Client> client, const std::list <I_Transport::PtrT> &cars) {
    print_headline_for_greetings("CARS");
    display(cars);
    print_headline_for_greetings("CARS");
    ask_for_sorting();
    char choice;
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
void purchasing_custom_car(std::shared_ptr<Client> client, std::list <I_Transport::PtrT> &cars) {
    I_Transport::PtrT custom_car = std::make_shared<Car>();
    custom_car->inputInfo(cars);
    client->add_car(custom_car);
    display_info_about_client(client);
}
enum TypeOfPurchasing {
    DATABASE = '1',
    CUSTOM = '2',
    MY_CARS = '3',
    REPAIR = '4',
    QUIT = '5',
};
void show_posibilities(std::shared_ptr<I_Person> client) {
    std::cout << client->get_name() << ", choose one variant below:\n1 - buy new car from salon\n2 - buy custom car\n3 - show my cars\n4 - repair car\n5 - quit program\n";
}
void show_clients_cars(std::shared_ptr<Client> client) {
    std::list<I_Transport::PtrT> clients_cars = client->get_cars();
    if(clients_cars.size() == 0) { 
        ////TODO: magic number
        std::cout << client->get_name() << ", you do not have any cars, go to the shop and buy one!!!\n"; 
        display_info_about_client(client);
    }
    else {
        display_info_about_client(client);
    }
}
size_t get_id_of_car_to_repair() {
    size_t id;
    std::cout << "Choose car you want to repair by id\nEnter id:";
    std::cin >> id;
    return id;
}
void display_message_of_no_cars() {
    print_headline_for_greetings();
    std::cout << "You do not have any car to repair, go to the salon and buy one" << std::endl;
    print_headline_for_greetings();
}
void repair_car_by_id(const std::list<I_Transport::PtrT> &cars, std::shared_ptr<Worker> worker, std::shared_ptr<Client> client) {
    int id = get_id_of_car_to_repair();
    bool is_repaired = false;
    for(const auto car: cars) {
        if(id == car->get_id()) {
            is_repaired = true;
            worker->repair_car(car,client);
        }
    }
    if(is_repaired == false) {
        std::cout << "You do not have car with this id\n";
    }
}
void display_info_about_worker(std::shared_ptr<Worker> worker) {
    print_headline_for_greetings("WORKER");
    std::cout << worker->get_name() << " has been repairing your car, here is info about worker:" << std::endl;
    std::cout << *worker << std::endl;
    print_headline_for_greetings();
}
void repair_clients_car(std::shared_ptr<Client> client) {
    const int zero_cars = 0;
    std::list<I_Transport::PtrT> clients_cars = client->get_cars();
    if(clients_cars.size() == zero_cars) { 
        display_message_of_no_cars();
        return;
    }

    std::vector <int> all_ids = get_all_ids();
    int id = generate_id(all_ids);
    std::shared_ptr<Worker> worker = std::make_shared<Worker>(id, "Steve", 24);
    display_info_about_client(client);
    repair_car_by_id(clients_cars, worker,client);
    display_info_about_worker(worker);
    return;
}
void main_drive(std::shared_ptr<Client> client, std::list <I_Transport::PtrT> &cars) {
    char choice;
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
            case MY_CARS: {
                show_clients_cars(client);
                break;
            }
            case REPAIR: {
                repair_clients_car(client);
                ////TODO: worker repair_car solve it
                break;
            }
            case QUIT: {
                break;
            }
            default: {
                std::cout << "We have only 5 options" << std::endl;
            }
        }
    } while(choice != QUIT);
}
void mainProblem() {
    std::list <I_Transport::PtrT> cars = get_list_of_cars();
    Login login;
    login.startToLogin();
    std::shared_ptr<Client> client = std::make_shared<Client>(login.get_id(), login.get_username(), login.get_age()); 
    main_drive(client, cars);    
    return; 
}
int main() {    
    try {
        mainProblem();
        // std::cout << "Hello, world\n";
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