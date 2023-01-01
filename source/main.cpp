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



void mainProblem() {
    std::list <I_Transport::PtrT> cars = get_list_of_cars();
    

    // Client *client1 = new Client("Anderew", 20);
    // std::shared_ptr<I_Person> client1 = std::make_shared<Client>("Andrew", 20);
    // generate_id(client1);
    
    // std::shared_ptr<I_Person> client2 = std::make_shared<Client>("Max", 21);

    // std::cout << *client1 << std::endl;
    // std::cout << *client2 << std::endl;

    
    I_Transport::PtrT car1 = std::make_shared<Car>();
    car1->inputInfo(cars);
    // generate_id(ids);
    std::cout << *car1 << std::endl;
    // // car1->inputInfo(cars);
    // client1->add_car(car1);
    // std::cout << client1->get_number_of_cars() << std::endl;
    // std::vector<I_Transport::PtrT> vec = client1->get_cars();
    // for(const auto x: vec) {
    //     std::cout << *x << std::endl;
    // }
    


    
    // cars.sort([]( I_Transport::PtrT a,  I_Transport::PtrT b){ return a->get_brand() < b->get_brand();});
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