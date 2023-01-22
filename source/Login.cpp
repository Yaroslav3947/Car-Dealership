#include <string>
#include <fstream>
#include <iostream>
#include <exception>

#include "Login.hpp"

char get_choice();
void showPosibilities();
std::string getPassword();
std::string getUsername();
bool is_password_valid(const std::string &password);
void put_info_into_file(const std::string &username, const std::string &password, const int &id);

enum class LoginOption {
    LOGIN = 'L',
    SINGUP = 'S',
};
bool is_password_valid(const std::string &password) {
    const size_t min_size = 8;
    const size_t required_num_of_underscores = 1;
    const size_t required_num_of_digits = 1;
    const size_t required_num_of_uppercase_chars = 1;
    size_t underscore_count{0};
    size_t digit_count{0};
    size_t uppercase_char_count{0};

    for (size_t i{0}; i < password.size(); i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            uppercase_char_count++;
        }
        if (password[i] == '_') {
            underscore_count++;
        }
        if (password[i] >= '0' && password[i] <= '9') {
            digit_count++;
        }
    }

    if (password.size() >= min_size && uppercase_char_count >= required_num_of_uppercase_chars 
        && underscore_count >= required_num_of_underscores && digit_count >= required_num_of_digits) {
        return true;
    } else {
        return false;
    }
}
std::vector<std::string> get_all_usernames() {
    std::vector<std::string> all_usernames;
    std::string path_to_user_data_file = "PassAndUsernames.txt";
    std::ifstream in_file;
    in_file.open(path_to_user_data_file);
    if (!in_file) {
        throw FileOpenIssue();
    }

    size_t line_number{0};
    std::string line{};
    while (!in_file.eof()) {
        if (line_number % 3 == 0) {
            in_file >> line;
            all_usernames.push_back(line);
        }
        line_number++;
    }

    in_file.close();
    return all_usernames;
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
    } while (!is_password_valid(password));

    return hash_passwordSHA256(password);     
}
void showPosibilities() {
    std::cout << "==========================================\n"
              << "Hello, we are happy you to join our system\n"
              << "Press L to Login\n"
              << "Press S to Sign up\n"
              << "==========================================\n";
}
char get_choice() {
    char choice;
    std::cout << "Enter choice:";
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
    const std::string path_to_folder_with_pass_and_usernames = "PassAndUsernames.txt";
    std::ifstream in_file;
    in_file.open(path_to_folder_with_pass_and_usernames);
    if(!in_file) {
        throw FileOpenIssue();
    }
    std::string line1{}, line2{}, line3{};
    while(!in_file.eof()) {
        std::getline(in_file, line1);
        std::getline(in_file, line2);
        std::getline(in_file, line3);
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
    return  hash_passwordSHA256(password);
}
void Login::isLoggedIn() {
    size_t numberOfTries{0};
    bool is_logged_in = false;
    do {
        numberOfTries++;
        if(numberOfTries > 1) { 
            ////TODO: magic number
            std::cout << "Your password or login is't right" << std::endl;
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


void put_info_into_file(const std::string &username, const std::string &password, const int &id) {
    const std::string path = "PassAndUsernames.txt";
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
void Login::registerNewUser() {
    username = getUsername();
    password = getPassword();
    age = getAge();
    std::vector <int> all_ids = get_all_ids();
    id = generate_id(all_ids);
    put_info_into_file(username, password, id);
    std::cout << "Hello, welcome to the system" << std::endl;
}
void Login::logInToSystem() {
    isLoggedIn();
    std::cout << "================================================\nYou have succesfully logged in" << std::endl;
    std::cout << "Hello, welcome to the system" << std::endl;
}
void Login::startToLogin()
{
    LoginOption choice{};
    do {
        showPosibilities();
        choice = static_cast<LoginOption>(get_choice());
        switch (choice) {
            case LoginOption::SINGUP: {
                registerNewUser();
                break;
            }
            case LoginOption::LOGIN: {
                logInToSystem();
                break;
            }
            default: {
                std::cout << "Invalid choice, please try again" << std::endl;
                break;
            }
        }
    } while (choice != LoginOption::SINGUP && choice != LoginOption::LOGIN);
}
