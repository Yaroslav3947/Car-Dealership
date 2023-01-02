#pragma once

#include <exception>

class NoFreeIdException : public std::exception {
public:
    NoFreeIdException() noexcept = default;
    ~NoFreeIdException() = default;
    virtual const char *what() const noexcept {
        return  "No free id exception\nYou cannot add any car into database";
    }
};