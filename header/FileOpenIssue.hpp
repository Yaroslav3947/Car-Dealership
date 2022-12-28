#pragma once

#include <exception>

class FileOpenIssue : public std::exception {
public:
    FileOpenIssue() noexcept = default;
    ~FileOpenIssue() = default;
    virtual const char *what() const noexcept {
        return  "File Open Issue\nThere is a problem with file or file doesn't exist";
    }
};