#include <string>
#include <iostream>

#include <I_Person.hpp>


I_Person::I_Person(std::string name ,int age) 
    : name{name}, age{age} {
        if(age < default_age) {
            throw IllegalAgeException(); 
        }
}
int I_Person::get_age() const {
    return age;
}
std::string I_Person::get_name() const {
    return name;
}
void I_Person::printInfo(std::ostream &os) const {
    os << "[Person: " <<  name << ": " << age << "y.o]";
}
void I_Person::inputInfo(std::istream &is) {
    std::cout << "Input name:";
    is >> name;
    std::cout << "Input age:";
    is >> age;
    I_Person(name, age);
}