#pragma once

#include <exception>

class IllegalFuelComsumptionException : public std::exception {
public:
    IllegalFuelComsumptionException() noexcept = default;
    ~IllegalFuelComsumptionException() = default;
    virtual const char *what() const noexcept {
        return  "Illegal fuel comsumption exception\nThe fuel comsumption can not be less than zero";
    }
};