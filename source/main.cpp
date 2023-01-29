#include "Car.hpp"
#include "Login.hpp"
#include "Client.hpp"
#include "Worker.hpp"
#include "Seller.hpp"
#include "I_Person.hpp"
#include "I_Transport.hpp"
#include "UtilChecking.hpp"

void show_posibilities(std::shared_ptr<I_Person> client) {
    std::cout << client->get_name() << ", choose one variant below:\n1 - buy new car from salon\n2 - buy custom car\n3 - show my cars\n4 - repair car\n5 - quit program\n";
}
void sorting_cars(std::list<I_Transport::PtrT> cars) {
    enum class Sorting_cars {
        BY_BRAND = '1',
        BY_COLOR = '2',
        BY_COUNTRY = '3',
        BY_MODEL = '4',
        BY_PRICE = '5',
        BY_FUEL = '6',
        CONTINUE = '7',
    };
    std::map<Sorting_cars, std::function<bool(I_Transport::PtrT, I_Transport::PtrT)>> sorting_methods = {
        {Sorting_cars::BY_BRAND, [](I_Transport::PtrT a, I_Transport::PtrT b) { return a->get_brand() < b->get_brand(); }},
        {Sorting_cars::BY_COLOR, [](I_Transport::PtrT a, I_Transport::PtrT b) { return a->get_color() < b->get_color(); }},
        {Sorting_cars::BY_COUNTRY, [](I_Transport::PtrT a, I_Transport::PtrT b) { return a->get_country() < b->get_country(); }},
        {Sorting_cars::BY_MODEL, [](I_Transport::PtrT a, I_Transport::PtrT b) { return a->get_model() < b->get_model(); }},
        {Sorting_cars::BY_PRICE, [](I_Transport::PtrT a, I_Transport::PtrT b) { return a->get_price() < b->get_price(); }},
        {Sorting_cars::BY_FUEL, [](I_Transport::PtrT a, I_Transport::PtrT b) { return a->get_fuel_consumption() < b->get_fuel_consumption(); }}
    };

    Sorting_cars choice;
    do {
        show_way_of_sorting();
        choice = static_cast<Sorting_cars>(getChoice());
        auto sorting_func = sorting_methods.find(choice);
        if (sorting_func != sorting_methods.end()) {
            cars.sort(sorting_func->second);
            display(cars);
        }
    } while (choice != Sorting_cars::CONTINUE);
}

void purchase_car(std::shared_ptr<Client> client, const std::list<I_Transport::PtrT> &cars) {
    auto seller = std::make_shared<Seller>(-1, "Petro", 34, 54);
    int id = get_id_of_wanted_car();
    auto it = std::find_if(cars.begin(), cars.end(), [id](const I_Transport::PtrT &car)
                            { return car->get_id() == id; });
    if (it == cars.end()) {
        std::cout << "No car with id " << id << " found.\n";
        return;
    }
    auto car = *it;
    client->add_car(car);
    seller->sell_car(car, client);
    std::cout << "Car purchased.\n";
}
void display_info_about_client(std::shared_ptr<Client> client) {
    print_headline_for_greetings("MY_CARS"); 
    const auto &clients_cars = client->get_cars();
    std::cout << client->get_name() << ", you have " << clients_cars.size() << " car" << (clients_cars.size() > 1 ? "s" : "") << std::endl;
    display(clients_cars);
    print_headline_for_greetings("MY_CARS"); 
}

void purchasing_car_from_database(std::shared_ptr<Client> client, const std::list <I_Transport::PtrT> &cars) {
    enum class Sorting_option {
        SORT = '1',
        CONTINUE_BUYING = '2',
    };
    print_headline_for_greetings("CARS");
    display(cars);
    print_headline_for_greetings("CARS");
    ask_for_sorting();
    Sorting_option choice;
    do {
        choice = static_cast<Sorting_option>(getChoice());
        switch (choice) {
            case Sorting_option::SORT: {
                sorting_cars(cars);
                break;
            }
            case Sorting_option::CONTINUE_BUYING: {
                continue;
            }
            default : {
                std::cout << "We have only 2 option, you did something wrong" << std::endl;
            }
        }
    } while(choice != Sorting_option::CONTINUE_BUYING && choice != Sorting_option::SORT);
    purchase_car(client,cars);
    display_info_about_client(client);
}
void purchasing_custom_car(std::shared_ptr<Client> client, std::list <I_Transport::PtrT> &cars) {
    auto custom_car = std::make_shared<Car>();
    custom_car->inputInfo(cars);
    client->add_car(custom_car);
    display_info_about_client(client);
}
void show_clients_cars(std::shared_ptr<Client> client) {
    const auto &clients_cars = client->get_cars();
    if(clients_cars.empty()) { 
        std::cout << client->get_name() << ", you do not have any cars, go to the shop and buy one!!!\n"; 
        display_info_about_client(client);
    }
    else {
        display_info_about_client(client);
    }
}
void display_message_of_no_cars() {
    print_headline_for_greetings();
    std::cout << "You do not have any car to repair, go to the salon and buy one" << std::endl;
    print_headline_for_greetings();
}
void display_info_about_worker(std::shared_ptr<Worker> worker) {
    print_headline_for_greetings("WORKER");
    std::cout << worker->get_name() << " has been repairing your car, here is info about worker:" << std::endl;
    std::cout << *worker << std::endl;
    print_headline_for_greetings();
}
void repair_car_by_id(const std::list<I_Transport::PtrT> &cars, std::shared_ptr<Worker> worker, std::shared_ptr<Client> client) {
    int id = get_id_of_car_to_repair();
    auto it = std::find_if(cars.begin(), cars.end(), [id](const I_Transport::PtrT& car) {
        return id == car->get_id();
    });
    if (it == cars.end()) {
        std::cout << "You do not have car with this id\n";
    } else if (!(*it)->get_is_need_repair()) {
        std::cout << "This car doesn't need repair\n";
    } else {
        worker->repair_car(*it, client);
        display_info_about_worker(worker);
    }
}
void repair_clients_car(std::shared_ptr<Client> client) {
    auto clients_cars = client->get_cars();
    if(clients_cars.empty()) { 
        display_message_of_no_cars();
        return;
    }

    auto worker = std::make_shared<Worker>(generate_id(get_all_ids()), "Steve", 24);
    display_info_about_client(client);
    repair_car_by_id(clients_cars, worker,client);
    return;
}
void main_drive(std::shared_ptr<Client> client, std::list <I_Transport::PtrT> &cars) {
    enum class TypeOfPurchasing {
        DATABASE = '1',
        CUSTOM = '2',
        MY_CARS = '3',
        REPAIR = '4',
        QUIT = '5',
    };
    TypeOfPurchasing choice;
    do {
        show_posibilities(client);
        choice = static_cast<TypeOfPurchasing>(getChoice());
        switch (choice) {
            case TypeOfPurchasing::DATABASE: {
                purchasing_car_from_database(client,cars);
                break;
            }
            case TypeOfPurchasing::CUSTOM: {
                purchasing_custom_car(client, cars);
                break;
            }
            case TypeOfPurchasing::MY_CARS: {
                show_clients_cars(client);
                break;
            }
            case TypeOfPurchasing::REPAIR: {
                repair_clients_car(client);
                break;
            }
            case TypeOfPurchasing::QUIT: {
                break;
            }
            default: {
                std::cout << "We have only 5 options" << std::endl;
            }
        }
    } while(choice != TypeOfPurchasing::QUIT);
}
void mainProblem() {
    std::list <I_Transport::PtrT> cars = get_list_of_cars();
    Login login;
    login.startToLogin();
    const auto &client = std::make_shared<Client>(login.get_id(), login.get_username(), login.get_age()); 
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