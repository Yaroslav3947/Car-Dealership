#include <iostream>


#include <Car.hpp>
#include <Login.hpp>
#include <Seller.hpp>
#include <Worker.hpp>
#include <Client.hpp>
#include <I_Person.hpp>
#include <I_Transport.hpp>

int main() {
    // try {

    //     I_Person *w1 = new Worker();
    //     std::cin >> *w1;
    //     std::cout << *w1 << std::endl;
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

    I_Transport *c1 = new Car();
    std::cin >> *c1;
    std::cout << *c1 << std::endl;
    


    
    return 0;
}