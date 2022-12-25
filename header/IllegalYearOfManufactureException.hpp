#pragma once

#include <exception>

class IllegalYearOfManufactureException : public std::exception {
public:
    IllegalYearOfManufactureException() noexcept = default;
    ~IllegalYearOfManufactureException() = default;
    virtual const char *what() const noexcept {
        return  "Illegal year of manufacture exception\nThe year of the car's manufacture must be (1886 <= year <= 2023)";
    }
};