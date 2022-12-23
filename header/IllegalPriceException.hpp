#pragma once

#include <exception>

class IllegalPriceException : public std::exception {
public:
    IllegalPriceException() noexcept = default;
    ~IllegalPriceException() = default;
    virtual const char *what() const noexcept {
        return  "Illegal price exception\nThe price of the car can not be less than zero";
    }
};