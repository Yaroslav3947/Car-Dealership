#pragma once

#include "I_Person.hpp"

class Worker : public I_Person {
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
    void set_id(const size_t &id) override;
    void repair_car(I_Transport::PtrT car);
    int get_number_of_repaired_cars() const;
    int get_number_of_cars() const override {}
    void add_car(I_Transport::PtrT car) override {}
    void printInfo(std::ostream &os) const override;
    std::list<I_Transport::PtrT> get_cars() override {} /// TODO: erase this 3 methods
};