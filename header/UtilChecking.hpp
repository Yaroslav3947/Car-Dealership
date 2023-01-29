#pragma once

#include <map>
#include <list>
#include <ctime>
#include <vector>
#include <string>
#include <memory>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#include <openssl/sha.h>

#include "Car.hpp"
#include "I_Person.hpp"
#include "I_Transport.hpp"


void print_headline();
void print_headline_in_file();
std::vector<int> get_all_ids();
bool isNormalAge(const int &age);
bool isNormalWage(const int &wage);
bool isNormalYearForCar(const int &num);
bool isPositiveNumber(const double &num);
int generate_id(const std::vector<int> &ids);
std::list<I_Transport::PtrT> get_list_of_cars();
void display(std::list <I_Transport::PtrT> list);
void print_half_line(const int &size_of_line, const std::string &line);
void print_headline_for_greetings(const std::string &line = "");
std::string hash_passwordSHA256(const std::string& password);
void print_half_line(); 
void ask_for_sorting();
char getChoice(); 
void show_way_of_sorting();
size_t get_id_of_wanted_car();
size_t get_id_of_car_to_repair();