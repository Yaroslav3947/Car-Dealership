#pragma once

#include <list>
#include <fstream>

#include <Car.hpp>
#include <I_Transport.hpp>

template <typename T>
void display(const std::list<T*> list);
bool isNormalAge(const int &age);
bool isNormalWage(const int &wage);
bool isNormalYearForCar(const int &num);
bool isPositiveNumber(const double &num);
void get_list_of_cars (std::list<I_Transport *> &list);
