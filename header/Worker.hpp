#pragma once

#include "I_Person.hpp"
#include "Client.hpp"

class Worker : public I_Person {
    int wage;
    int number_of_repaired_cars = default_number_of_repaired_cars;
    static constexpr const int default_age = 18;
    static constexpr const int default_wage = 70;
    static constexpr const char *default_name = "Unnamed Worker";
    static constexpr const int default_number_of_repaired_cars = 0;

public:
    Worker(int id = default_id, std::string name = default_name,
           int age = default_age,
           int wage = default_wage);
    int get_wage() const { return wage; };
    virtual ~Worker() = default;
    void set_id(const size_t &id);
    void repair_car(I_Transport::PtrT car, std::shared_ptr<Client> client);
    int get_number_of_repaired_cars() const { return number_of_repaired_cars; };
    void printInfo(std::ostream &os) const override;
};