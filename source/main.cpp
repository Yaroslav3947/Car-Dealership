#include <iostream>


#include <Car.hpp>
#include <Login.hpp>
#include <Seller.hpp>
#include <Worker.hpp>
#include <Client.hpp>
#include <I_Person.hpp>
#include <I_Transport.hpp>

int main() {
    // Login p;
    // p.startToLogin();
    // // check
    // try {
        // I_Person *p = new I_Person("Max", 17);
        // I_Person *s1 = new Seller("Andrew", 22, 99);
        // I_Person *s2 = new Seller("Andrew");
        // I_Person *c1 = new Client("Anna",22);
        // I_Person *c2 = new Client();
    //     I_Person *w1 = new Worker("Tumoha", 18, 99,-1);
    //     I_Person *w2 = new Worker();
    //     std::cout << *w1 << std::endl;
    //     std::cout << *w2 << std::endl;
    // }
    // catch(const IllegalAgeException& e) {
    //     std::cerr << e.what() << '\n';
    // }
    // catch(const IllegalWageException& e) {
    //     std::cerr << e.what() << '\n';
    // }
    // catch(const IllegalNumberOfRepairedOrSoldCarsException& e) {
    //     std::cerr << e.what() << '\n';
    // }

    // I_Transport *t = new I_Transport();
    // std::cout << *t << std::endl;
    I_Transport *c1 = new Car("Audi", "RS6", "Germany", 2022, 13.2, 70000, true, "Sedan", 5, false, "diesel");
    // I_Transport *c2 = new Car(); 
    std::cout << *c1 << std::endl;


    
    return 0;
}