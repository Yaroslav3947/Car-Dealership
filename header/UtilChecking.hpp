#pragma once

#include <list>
#include <fstream>

// #include <Car.hpp>
#include <I_Transport.hpp>


void display(const std::list<I_Transport*> list);
bool isNormalAge(const int &age);
bool isNormalWage(const int &wage);
bool isNormalYearForCar(const int &num);
bool isPositiveNumber(const double &num);
