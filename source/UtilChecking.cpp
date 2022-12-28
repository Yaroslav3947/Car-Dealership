#include <UtilChecking.hpp>

bool isNormalWage(const int &wage) {
    const int minimunWage = 20;
    const int maximumWage = 100;
    return wage > minimunWage && wage < maximumWage;
}
bool isNormalAge(const int &age) {
    const int acceptedAge = 18;
    return age >= acceptedAge;
}
bool isPositiveNumber(const double &num) {
    const double bound = 0.0;
    return num >= bound;
}
bool isNormalYearForCar(const int &num) {
    const int yearOfFirstCar = 1886;
    const int ceilOfCarYear = 2023;
    return yearOfFirstCar <= num &&  num <= ceilOfCarYear;
}
void display(const std::list<I_Transport*> list) {
    for(const auto x: list) {
        std::cout << *x << std::endl;
    }
}
