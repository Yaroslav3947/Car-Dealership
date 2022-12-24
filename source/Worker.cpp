#include <string>
#include <iostream>

#include <Worker.hpp>

Worker::Worker(std::string name, int age, int wage) 
    : I_Person{name, age}, wage{wage} {
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
void Worker::printInfo(std::ostream &os) const {
    os << "[Worker: " <<  name << ": " << age << "y.o: $"  <<  wage << ": " << number_of_repaired_cars << " cars repaired]";
}

