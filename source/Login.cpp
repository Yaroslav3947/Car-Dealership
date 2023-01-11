#include <string>
#include <fstream>
#include <iostream>
#include <exception>

#include "Login.hpp"

char get_choice();
void welcomeToSystemMessage();
void showPosibilities();
std::string getPassword();
std::string getUsername();
void passOrLoginIsNotRight();
void YouAreAlreadyInSystem();
void youHaveSuccesfullyLoggedIn();
bool IsPassOk(const std::string &password);
void put_info_into_file(const std::string &username, const std::string &password);

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
std::vector <std::string> get_all_usernames() {
    std::vector<std::string> all_usernames;
    std::string path_to_folder_with_pass_and_usernames = "D:\\PassAndUsernames.txt";
    std::ifstream in_file;
    in_file.open(path_to_folder_with_pass_and_usernames);
    if (!in_file) {
        throw FileOpenIssue();
    }
    size_t number_of_line{0};
    std::string line{};
    while (!in_file.eof()) {
        if (number_of_line % 3 == 0) {
            in_file >> line;
            all_usernames.push_back(line);
        }
        number_of_line++;
    }
    return all_usernames;
    in_file.close();
}
std::string getUsername() {
    std::vector<std::string> all_usernames = get_all_usernames();
    std::string username;
    bool is_taken;
    do {
        is_taken = false;
        std::cout << "Enter username: ";
        std::cin >> username;
        for (size_t i{0}; i < all_usernames.size(); i++) {
            if (username == all_usernames[i]) {
                is_taken = true;
                std::cout << "This username is taken, choose another one\n";
            }
        }
    } while (is_taken);

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
void get_user_data(const std::string &username, const std::string &password, int &id, std::string &fileUsername, std::string &filePassword) {
    const std::string path_to_folder_with_pass_and_usernames = "D:\\PassAndUsernames.txt";
    std::ifstream in_file;
    in_file.open(path_to_folder_with_pass_and_usernames);
    if(!in_file) {
        throw FileOpenIssue();
    }
    std::string line1{}, line2{}, line3{};
    while(!in_file.eof()) {
        in_file >> line1;
        in_file >> line2;
        in_file >> line3;
        if(line1 == username && line2 == password) {
            fileUsername = line1;
            filePassword = line2;
            id = stoi(line3);
        }
    }

    in_file.close();
}
std::string enter_username() {
    std::string username;
    std::cout << "Enter username:";
    std::cin >> username;
    return username;
}
std::string enter_password() {
    std::string password;
    std::cout << "Enter password:";
    std::cin >> password;
    return password;
}
void Login::isLoggedIn() {
    size_t numberOfTries{0};
    bool is_logged_in = false;
    do {
        numberOfTries++;
        if(numberOfTries > 1) { 
            ////TODO: magic number
            passOrLoginIsNotRight();
        } 
        username = enter_username();
        password = enter_password();
        std::string fileUsername;
        std::string filePassword;
        int id;
        get_user_data(username, password, id, fileUsername, filePassword);
        this->id = id;
        if(fileUsername == username && filePassword == password) {
            is_logged_in = true;
        } else {
            is_logged_in = false;
        }
    } while (!is_logged_in);
}
void welcomeToSystemMessage() {
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
void put_info_into_file(const std::string &username, const std::string &password, const int &id) {
    const std::string path = "D:\\PassAndUsernames.txt";
    std::cout << "================================================\nYou have successfully registered\n";
    std::ofstream out_file;
    out_file.open(path, std::ios::app);
    if(!out_file) {
        throw "Problems with file";
    }
    out_file << username << std::endl << password << std::endl << id << std::endl;
    out_file.close();
}
int getAge() {
    int age;
    std::cout << "Enter age:";
    std::cin >> age;
    if(!isNormalAge(age)) {
        throw IllegalAgeException();
    }
    return age;
}
void Login::singUpSystem() {
    username = getUsername();
    password = getPassword();
    age = getAge();
    std::vector <int> all_ids = get_all_ids();
    id = generate_id(all_ids);
    put_info_into_file(username, password, id);
    welcomeToSystemMessage();
}
void Login::logInSystem() {
    isLoggedIn();
    youHaveSuccesfullyLoggedIn();
    welcomeToSystemMessage();
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
