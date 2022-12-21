#include <string>
#include <iostream>

#include <Worker.hpp>

Worker::Worker(std::string name, int age, int wage, int number_of_repaired_cars) 
    : I_Person{name, age}, wage{wage}, number_of_repaired_cars{number_of_repaired_cars} {
        if(!isNormalWage(wage)) {
            throw IllegalWageException();
        }
        if(!isNormalAge(age)) {
            throw IllegalAgeException();
        }
        if(!isNormalNumberOfRepairedOrSoldCars(number_of_repaired_cars)) {
            throw IllegalNumberOfRepairedOrSoldCarsException();
        }
}

int Worker::get_age() const {
    return age;
}
std::string Worker::get_name() const {
    return name;
}
int Worker::get_number_of_repaired_cars() const {
    return number_of_repaired_cars;
}
void Worker::printInfo(std::ostream &os) const {
    os << "[Worker: " <<  name << ": " << age << "y.o: "  << number_of_repaired_cars << " cars repaired]";
}
