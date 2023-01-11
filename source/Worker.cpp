#include <string>
#include <iostream>

#include "Worker.hpp"

Worker::Worker(std::string name, int age, int wage) 
    : I_Person{id, name, age}, wage{wage} {
        std::vector <int> all_ids = get_all_ids();
        this->id = generate_id(all_ids);
        if(!isNormalWage(wage)) {
            throw IllegalWageException();
        }
}
int Worker::get_number_of_repaired_cars() const {
    return number_of_repaired_cars;
}
int Worker::get_wage() const {
    return wage;
}
void Worker::set_id(const size_t &id) {
    I_Person::set_id(id);
}
void Worker::printInfo(std::ostream &os) const {
    os << "[Worker: id:" << id << ": "<<  name << ": " << age << "y.o: $"  <<  wage << ": " << number_of_repaired_cars << " cars repaired]";
}
void Worker::repair_car(I_Transport::PtrT car) {
    bool repaired_car = false;
    if(car->get_is_need_repair()) {
        std::cout << "Your car has been successfully repaired.\n";
        car->set_is_need_repair(repaired_car);
        number_of_repaired_cars++;
    } else {
        std::cout << "This car doesn't need repair\n";
    }
    return;
}

