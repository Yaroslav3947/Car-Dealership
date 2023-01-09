#include <string>
#include <fstream>
#include <iostream>

#include <Login.hpp>

char get_choice();
void welcomeToSystem();
void showPosibilities();
std::string getPassword();
std::string getUsername();
void passOrLoginIsNotRight();
void YouAreAlreadyInSystem();
void youHaveSuccesfullyLoggedIn();
bool IsPassOk(const std::string &password);
void succesfullyRegister(const std::string &username, const std::string &password);

enum choiceToLogin { 
    LOGIN = 'L',
    SINGUP = 'S',
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

std::string getUsername() {
    std::string username;
    std::cout << "Enter username : ";
    std::cin >> username;
    return username;
}
std::string getPassword() {
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
    std::cout << "==========================================\n"
              << "Hello, we are happy you to join our system\n"  
              << "Press S to Sing up\n"  
              << "Press L to Login\n" 
              << "==========================================\n";
}
char get_choice() {
    char choice{};
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    choice = toupper(choice);
    return choice;
}
int getId() {
    int id;
    std::cout << "Enter id:";
    std::cin >> id;
    return id;
}
void Login::isLoggedIn() {
    size_t numberOfTries{0};
    bool is_logged_in = false;
    do {
        numberOfTries++;
        if(numberOfTries > 1) { ////TODO: magic number
            passOrLoginIsNotRight();
        } 
        id = getId();
        std::string username = getUsername();
        this->username = username;
        std::string password = getPassword();
        std::string fileUsername;
        std::string filePassword;
        const std::string path = "D:\\" + std::to_string(id) + ".txt";
        std::ifstream in_file(path);
        std::getline(in_file, fileUsername);
        std::getline(in_file, filePassword);
        if(fileUsername == username && filePassword == password) {
            is_logged_in = true;
        } else {
            is_logged_in = false;
        }
    } while (!is_logged_in);
}
void welcomeToSystem() {
    std::cout << "Hello, welcome to the system" << std::endl;
}
void only3Options() {
    std::cout << "You have input something wrong, try again" << std::endl;
}
void passOrLoginIsNotRight() {
    std::cout << "Your password or login is't right" << std::endl;
}
void youHaveSuccesfullyLoggedIn() {
    std::cout << "================================================\nYou have succesfully logged in" << std::endl;
}
void YouAreAlreadyInSystem() {
    std::cout << "You are already in system";
}
void succesfullyRegister(const int id, const std::string &username, const std::string &password) {
    const std::string path = "D:\\" + std::to_string(id) + ".txt";
    std::cout << "================================================\nYou have successfully registered\nYour id is " << id <<"\nremember it\n";
    std::ofstream out_file;
    out_file.open(path);
    out_file << username << std::endl << password << std::endl;
    out_file.close();
}
void Login::singUpSystem() {
    std::string username = getUsername();
    this->username = username;
    std::string password = getPassword();
    std::vector <int> all_ids = get_all_ids();
    this->id = generate_id(all_ids);
    succesfullyRegister(id, username, password);
    welcomeToSystem();
}
void Login::logInSystem() {
    isLoggedIn();
    youHaveSuccesfullyLoggedIn();
    welcomeToSystem();
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
            default: {
                std::cout << "Here we have an issue, try again!!!\n";
                break;
            }
        }
    } while (choice != SINGUP && choice != LOGIN);

}
std::string Login::get_username() const {
    return this->username;
}
int Login::get_id() const {
    return this->id;
}