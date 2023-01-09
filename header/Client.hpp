#pragma once
#include <list>

#include <I_Person.hpp>

class Client final : public I_Person {
    static constexpr const char *default_name = "Unnamed Client";
    static constexpr const int default_age = 18;
    static constexpr const int default_number_of_cars = 0;
    std::list<I_Transport::PtrT> cars;
    int number_of_cars = default_number_of_cars;
public:
    Client(int id,
        std::string name = default_name,
        int age = default_age);
    void set_id(const size_t &id) override;
    int get_number_of_cars() const override;
    ~Client() = default;
    std::list<I_Transport::PtrT> get_cars() override;
    void add_car(I_Transport::PtrT car) override;
    void printInfo(std::ostream &os) const override;
    void repair_car(I_Transport::PtrT car) override {}
};