#pragma once

#include <memory>
#include <list>

#include <I_Person.hpp>
#include <I_Transport.hpp>



class Client final : public I_Person {
    static constexpr const char *default_name = "Unnamed Client";
    static constexpr const int default_age = 18;
    static constexpr const int default_number_of_cars = 0;
    std::list <I_Transport::PtrT> cars;
    int number_of_cars = default_number_of_cars;
public:
    void set_id(const size_t &id) override;
    Client(std::string name = default_name, int age = default_age);
    int get_number_of_cars() const;
    ~Client() = default;
    std::list<I_Transport::PtrT> get_cars();
    void add_car(I_Transport::PtrT car);
    void printInfo(std::ostream &os) const override;
};