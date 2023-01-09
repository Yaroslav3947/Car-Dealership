#pragma once
#include <UtilChecking.hpp>

class Login {
    std::string username;
    int id;
    void isLoggedIn();
    void logInSystem();
    void singUpSystem();
public:
    std::string get_username() const;
    int get_id() const;
    void startToLogin();
};