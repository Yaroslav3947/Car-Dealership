#include <string>
#include <fstream>
#include <iostream>

#include <Login.hpp>

char get_choice();
void isLoggedIn();
void logInSystem();
void singUpSystem();
void welcomeToBank();
void showPosibilities();
std::string get_password();
std::string get_username();
void PassOrLoginIsNotRight();
void YouAreAlreadyInSystem();
void youHaveSuccesfullyLoggedIn();
bool IsPassOk(const std::string &password);
void succesfullyRegister(const std::string &username, const std::string &password);

enum choiceToLogin { 
    LOGIN = 'L',
    SINGUP = 'S',
    QUIT = 'Q'
};
bool IsPassOk(const std::string &password) {
    const size_t minSize = 8;
    const size_t requiredNumOfHen = 1;
    const size_t requiredNumOfNums = 1;
    const size_t requiredNumOfBigChars = 1;
    size_t hen_cnt{0};
    size_t num_cnt{0};
    size_t upperCaseChars_cnt{0};
    for (size_t i{0}; i < password.size(); i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            upperCaseChars_cnt++;
        }
        if (password[i] == '_') {
            hen_cnt++;
        }
        if (password[i] >= '0' && password[i] <= '9') {
            num_cnt++;
        }
    }
    if (password.size() >= minSize && upperCaseChars_cnt >= requiredNumOfBigChars 
        && hen_cnt >= requiredNumOfHen && num_cnt >= requiredNumOfNums)
        return true;
    else
        return false;
}

std::string get_username() {
    std::string username;
    std::cout << "Enter username : ";
    std::cin >> username;
    return username;
}
std::string get_password() {
    std::string password;
    size_t numberOfTries{0};
    do {
        numberOfTries++;
        if(numberOfTries > 1) {
            std::cout << "You password isn't strong, try again" << std::endl;
        }
        std::cout << "Enter password : ";
        std::cin >> password;
    } while (!IsPassOk(password));

    return password;    
}
void showPosibilities() {
    std::cout << "\t\tHello, we are happy you to join our bank" << std::endl 
              << "\t\tPress S to Sing up" << std::endl 
              << "\t\tPress L to Login" << std::endl
              << "\t\tPress Q to QUIT" << std::endl;
}
char get_choice() {
    char choice{};
    std::cout << "\t\tEnter your choice: ";
    std::cin >> choice;
    choice = toupper(choice);
    return choice;
}
void isLoggedIn() {
    size_t numberOfTries{0};
    std::string password{};
    std::string username{};
    std::string filePassword{};
    std::string fileUsername{};
    do {
        numberOfTries++;
        if(numberOfTries > 1) {
            PassOrLoginIsNotRight();
        } 
        std::string username = get_username();
        std::string password = get_password();
        std::string path = "D:\\" + username + ".txt";
        std::ifstream in_file(path);
        std::getline(in_file, fileUsername);
        std::getline(in_file, filePassword);
    } while (fileUsername != username || filePassword != password);
}
void welcomeToBank() {
    std::cout << "Hello, welcome to the bank" << std::endl;
}
void only3Options() {
    std::cout << "You have input something wrong, try again" << std::endl;
}
void PassOrLoginIsNotRight() {
    std::cout << "Your password or login is't right" << std::endl;
}
void youHaveSuccesfullyLoggedIn() {
    std::cout << "================================================\nYou have succesfully logged in" << std::endl;
}
void YouAreAlreadyInSystem() {
    std::cout << "You are already in system";
}
void succesfullyRegister(const std::string &username, const std::string &password) {
    const std::string path = "D:\\" + username + ".txt";
    std::ofstream out_file;
    std::cout << "================================================\nYou have successfully registered" << std::endl;
    out_file.open(path);
    out_file << username << std::endl << password;
    out_file.close();
}
void singUpSystem() {
    std::string username = get_username();
    std::string password = get_password();
    succesfullyRegister(username, password);
    welcomeToBank();
}
void logInSystem() {
    isLoggedIn();
    youHaveSuccesfullyLoggedIn();
    welcomeToBank();
}
void Login::startToLogin() {
    char choice{};
    do {
        showPosibilities();
        choice = get_choice();
        switch (choice) {
            case SINGUP: {
                singUpSystem();
                break;
            }
            case LOGIN: {
                logInSystem();
                break;
            }
            case QUIT: {
                break;
            }
            default: {
                std::cout << "Here we have an issue, try again!!!";
                break;
            }
        }
    } while (choice != QUIT && choice != SINGUP && choice != LOGIN);

}