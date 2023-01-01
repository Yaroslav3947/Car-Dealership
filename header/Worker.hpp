#pragma once

#include <I_Person.hpp>

class Worker: public I_Person {
    int wage;
    int number_of_repaired_cars = default_number_of_repaired_cars;
    static constexpr const int default_age = 18;
    static constexpr const int default_wage = 70;
    static constexpr const char *default_name = "Unnamed Worker";
    static constexpr const int default_number_of_repaired_cars = 0;
public:
    Worker(std::string name = default_name,
        int age = default_age,
        int wage = default_wage);
    int get_wage() const;
    virtual ~Worker() = default;
    int get_number_of_repaired_cars() const;
    void printInfo(std::ostream &os) const override;
};