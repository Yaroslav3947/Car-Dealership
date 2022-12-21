#pragma once

#include <exception>

class IllegalNumberOfRepairedOrSoldCarsException : public std::exception {
public:
    IllegalNumberOfRepairedOrSoldCarsException() noexcept = default;
    ~IllegalNumberOfRepairedOrSoldCarsException() = default;
    virtual const char *what() const noexcept {
        return  "Illegal number of repaired cars\nNumber of repaired or repaired cars can not be less that 0";
    }
};