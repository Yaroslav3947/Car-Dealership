#pragma once
#include "UtilChecking.hpp"

class Login {
    int id;
    int age;
    std::string username;
    std::string password;
    void isLoggedIn();
    void logInToSystem();
    void registerNewUser();
public:
    std::string get_username() const {return username;};
    int get_id() const {return id;};
    int get_age() const {return age;};
    void startToLogin();
};