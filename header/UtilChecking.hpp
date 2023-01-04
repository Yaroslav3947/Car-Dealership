#pragma once

#include <list>
#include <vector>
#include <memory>
#include <fstream>
#include <iomanip>

#include <Car.hpp>
#include <I_Person.hpp>
#include <I_Transport.hpp>


void display(std::list <I_Transport::PtrT> list);
bool isNormalAge(const int &age);
bool isNormalWage(const int &wage);
bool isNormalYearForCar(const int &num);
bool isPositiveNumber(const double &num);
void print_headline_in_file();
// std::vector <int> get_ids(const std::string &path_to_file_with_ids);
// void write_id_to_file(const int &id, const std::string &path_to_file_with_ids);
std::list<I_Transport::PtrT> get_list_of_cars();
std::vector<int> get_ids_from_cars(std::list<I_Transport::PtrT> &cars);
int generate_id(const std::vector<int> &ids);
// void sorting_cars(std::list <I_Transport::PtrT> cars);
// void car_purchase(std::shared_ptr<I_Person> client, const std::list <I_Transport::PtrT> &cars);
// void purchasing_car_from_database(std::shared_ptr<I_Person> client, const std::list <I_Transport::PtrT> &cars);
// void main_drive(std::shared_ptr<I_Person> client, std::list <I_Transport::PtrT> &cars);
// void purchasing_custom_car(std::shared_ptr<I_Person> client, std::list <I_Transport::PtrT> &cars);
// size_t getChoice();