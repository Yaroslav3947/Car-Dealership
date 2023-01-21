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
void change_repair_status(int id, std::shared_ptr<Client> client) {
    std::string file_name = "Clients/" + std::to_string(client->get_id()) + ".txt";
    std::ifstream input_file(file_name);

    if (!input_file.is_open()) {
        throw FileOpenIssue();
    }

    std::vector<std::string> updated_file;

    std::string line;
    while (std::getline(input_file, line)) {
        // Use a stringstream to split the line by spaces
        std::stringstream line_stream(line);
        std::vector<std::string> car_data;
        std::string data;
        while (line_stream >> data) {
            car_data.push_back(data);
        }
        // Check if the current line's ID matches the ID passed to the function
        if (std::stoi(car_data[0]) == id) {
            // Update the repair status
            int current_status = std::stoi(car_data[12]);
            car_data[12] = std::to_string(!current_status);
        }
        // Join the elements of the vector into a single string
        std::string updatedLine = boost::algorithm::join(car_data, " ");
        // Add the updated line to the vector
        updated_file.push_back(updatedLine);
    }
    input_file.close();
    std::ofstream output_file(file_name);

    if (!output_file.is_open()) {
        throw FileOpenIssue();
    }
    for (const auto &line : updated_file) {
        output_file << line << std::endl;
    }
    output_file.close();
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

