#pragma once

#include <vector>
#include <string>
#include <memory>
#include <iostream>

#include <I_Printable.hpp>
#include <I_Transport.hpp>
#include <UtilChecking.hpp>
#include <IllegalAgeException.hpp>
#include <IllegalWageException.hpp>
#include <IllegalNumberOfRepairedOrSoldCarsException.hpp>

class I_Person : public I_Printable {
    static constexpr const int default_age = 18;
    static constexpr const int default_id = -1;
    static constexpr const char *default_name = "Unnamed Person";
protected:
    int age;
    int id;
    std::string name;
public:
    I_Person(int id = default_id,
            std::string name = default_name,
            int age = default_age);
    int get_age() const;
    I_Person() = default;
    virtual int get_id() const;
    std::string get_name() const;
    virtual ~I_Person() = default;
    virtual void set_id(const size_t &id) = 0;
    virtual int get_number_of_cars() const = 0;
    void printInfo(std::ostream &os) const override;
    virtual void add_car(I_Transport::PtrT car) = 0;
    virtual void repair_car(I_Transport::PtrT car) = 0;
    virtual std::list<I_Transport::PtrT> get_cars() = 0;
};


