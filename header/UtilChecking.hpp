#pragma once

#include <list>
#include <vector>
#include <memory>
#include <fstream>
#include <iomanip>

#include "Car.hpp"
#include "I_Person.hpp"
#include "I_Transport.hpp"


void print_headline_in_file();
std::vector<int> get_all_ids();
bool isNormalAge(const int &age);
bool isNormalWage(const int &wage);
bool isNormalYearForCar(const int &num);
bool isPositiveNumber(const double &num);
int generate_id(const std::vector<int> &ids);
std::list<I_Transport::PtrT> get_list_of_cars();
void display(std::list <I_Transport::PtrT> list);
void print_headline();
