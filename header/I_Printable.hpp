#pragma once

#include <iostream>

class I_Printable {
    friend std::ostream &operator <<(std::ostream &os, const I_Printable &obj);
public:
    virtual void printInfo(std::ostream &os) const = 0;
    virtual ~I_Printable() = default;
};