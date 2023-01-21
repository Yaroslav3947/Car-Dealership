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
    std::string fileName = "Clients/" + std::to_string(client->get_id()) + ".txt";
    std::ifstream inputFile(fileName);
    std::string line;
    std::string updatedFile;

    while (std::getline(inputFile, line)) {
        std::string carData[16];
        std::stringstream lineStream(line);
        int i = 0;
        while (lineStream >> carData[i]) {
            i++;
        }

        int currentId = std::stoi(carData[0]);
        if (currentId == id) {
            int currentStatus = std::stoi(carData[12]);
            carData[12] = std::to_string(!currentStatus);
        }
        for (int j = 0; j < 14; j++) {
            updatedFile += carData[j] + " ";
        }
        updatedFile += "\n";
    }

    inputFile.close();

    std::ofstream outputFile(fileName);
    outputFile << updatedFile;
    outputFile.close();
}
void Worker::repair_car(I_Transport::PtrT car, std::shared_ptr<Client> client) {
    int id_car_to_repair = car->get_id();
    std::cout << "ID:" << id_car_to_repair << '\n';
    if(car->get_is_need_repair()) {
        std::cout << "Your car has been successfully repaired.\n";
        change_repair_status(id_car_to_repair, client);
        number_of_repaired_cars++;
    } else {
        std::cout << "This car doesn't need repair\n";
    }
    return;
}
