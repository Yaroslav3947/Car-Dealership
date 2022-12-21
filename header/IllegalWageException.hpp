#pragma once

#include <exception>

class IllegalWageException : public std::exception {
public:
    IllegalWageException() noexcept = default;
    ~IllegalWageException() = default;
    virtual const char *what() const noexcept {
        return  "Illegal wage exeption\nThe wage should be from $20 to $100 - 120 per day";
    }
};