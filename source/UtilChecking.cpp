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
bool isNormalNumberOfRepairedOrSoldCars(const int &num) {
    const int bound = 0;
    return num >= bound;
}