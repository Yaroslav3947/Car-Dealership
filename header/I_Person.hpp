#pragma once

#include <vector>
#include <string>
#include <memory>
#include <iostream>

#include "I_Printable.hpp"
#include "I_Transport.hpp"
#include "UtilChecking.hpp"
#include "IllegalAgeException.hpp"
#include "IllegalWageException.hpp"
#include "IllegalNumberOfRepairedOrSoldCarsException.hpp"

class I_Person : public I_Printable {
    static constexpr const int default_age = 18;
    static constexpr const char *default_name = "Unnamed Person";

protected:
    std::string name;
    int age;
    int id;
    static constexpr const int default_id = -1;

public:
    I_Person(int id = default_id,
             std::string name = default_name,
             int age = default_age);
    int get_age() const { return age; };
    I_Person() = default;
    int get_id() const { return id; };
    std::string get_name() const { return name; };
    virtual ~I_Person() = default;
    void set_id(const size_t &id);
    void printInfo(std::ostream &os) const override;
};
