#include <string>
#include <sstream>
#include <iostream>
#include <boost/algorithm/string.hpp>

#include "Worker.hpp"

Worker::Worker(int id, std::string name, int age, int wage) 
    : I_Person{id, name, age}, wage{wage} {
        if(!isNormalWage(wage)) {
            throw IllegalWageException();
        }
}
void Worker::set_id(const size_t &id) {
    I_Person::set_id(id);
}
void Worker::printInfo(std::ostream &os) const {
    os << "[Worker: id:" << id << ": "<<  name << ": " << age << "y.o: $"  <<  wage << ": " << number_of_repaired_cars << " cars repaired]";
}

// void change_repair_status(int id, std::shared_ptr<Client> client) {
//     std::string fileName = "Clients/" + std::to_string(client->get_id()) + ".txt";
//     std::ifstream inputFile(fileName);
//     std::string line;
//     std::string updatedFile;

//     while (std::getline(inputFile, line)) {
//         std::string carData[16];
//         std::stringstream lineStream(line);
//         int i = 0;
//         while (lineStream >> carData[i]) {
//             i++;
//         }

//         int currentId = std::stoi(carData[0]);
//         if (currentId == id) {
//             int currentStatus = std::stoi(carData[12]);
//             carData[12] = std::to_string(!currentStatus);
//         }
//         for (int j = 0; j < 14; j++) {
//             updatedFile += carData[j] + " ";
//         }
//         updatedFile += "\n";
//     }

//     inputFile.close();

//     std::ofstream outputFile(fileName);
//     outputFile << updatedFile;
//     outputFile.close();
// }
void change_repair_status(int id, std::shared_ptr<Client> client) {
    std::string fileName = "Clients/" + std::to_string(client->get_id()) + ".txt";
    std::ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        throw FileOpenIssue();
    }

    std::vector<std::string> updatedFile;

    std::string line;
    while (std::getline(inputFile, line)) {
        // Use a stringstream to split the line by spaces
        std::stringstream lineStream(line);
        std::vector<std::string> carData;
        std::string data;
        while (lineStream >> data) {
            carData.push_back(data);
        }
        // Check if the current line's ID matches the ID passed to the function
        if (std::stoi(carData[0]) == id) {
            // Update the repair status
            int currentStatus = std::stoi(carData[12]);
            carData[12] = std::to_string(!currentStatus);
        }
        // Join the elements of the vector into a single string
        std::string updatedLine = boost::algorithm::join(carData, " ");
        // Add the updated line to the vector
        updatedFile.push_back(updatedLine);
    }
    inputFile.close();
    std::ofstream outputFile(fileName);

    if (!outputFile.is_open()) {
        throw FileOpenIssue();
    }
    for (const auto &line : updatedFile) {
        outputFile << line << std::endl;
    }
    outputFile.close();
}
void Worker::repair_car(I_Transport::PtrT car, std::shared_ptr<Client> client) {
    int id_car_to_repair = car->get_id();
    if(!car->get_is_need_repair()) {
        std::cout << "Car with ID:" << id_car_to_repair << " doesn't need repair\n";
        return;
    }
    std::cout << "Car with ID:" << id_car_to_repair << " has been successfully repaired.\n";
    change_repair_status(id_car_to_repair, client);
    number_of_repaired_cars++;
}

