#include <string>
#include <iostream>

#include <I_Person.hpp>


I_Person::I_Person(int id, std::string name, int age) 
    : name{name}, age{age}, id{id} {
        if(age < default_age) {
            throw IllegalAgeException(); 
        }
}
int I_Person::get_id() const {
    return id;
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
void I_Person::set_id(const size_t &id) {
    this->id = id;
}
