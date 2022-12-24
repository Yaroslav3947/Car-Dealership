#pragma once

#include <string>
#include <iostream>

#include <I_Printable.hpp>
#include <I_Transport.hpp>
#include <UtilChecking.hpp>
#include <IllegalAgeException.hpp>
#include <IllegalWageException.hpp>
#include <IllegalNumberOfRepairedOrSoldCarsException.hpp>

class I_Person : public I_Printable {
    static constexpr const int default_age = 18;
    static constexpr const char *default_name = "Unnamed Person";
protected:
    int age;
    std::string name;
public:
    I_Person(std::string name = default_name, int age = default_age);
    int get_age() const;
    std::string get_name() const;
    virtual ~I_Person() = default;
    I_Person() = default;
    void printInfo(std::ostream &os) const override;
};


