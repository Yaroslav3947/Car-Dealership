#include <I_Printable.hpp>

std::ostream &operator <<(std::ostream &os, const I_Printable &obj) {
    obj.printInfo(os);
    return os;
}
std::istream &operator >>(std::istream &is, I_Printable &obj) {
    obj.inputInfo(is);
    return is;
}