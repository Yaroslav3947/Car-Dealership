#pragma once

#include <exception>

class IllegalAgeException : public std::exception {
public:
    IllegalAgeException() noexcept = default;
    ~IllegalAgeException() = default;
    virtual const char *what() const noexcept {
        return  "Illegal age exeption\nWe accept only people >= 18 y.o";
    }
};