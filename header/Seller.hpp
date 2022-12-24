#include <I_Person.hpp>

class Seller: public I_Person {
    int wage;
    int code_of_seller;
    int number_of_sold_cars;
    static constexpr const int default_age = 18;
    static constexpr const int default_wage = 50;
    static constexpr const int default_number_of_sold_cars = 0;
    static constexpr const char *default_name = "Unnamed Seller";
public:
    Seller(std::string name = default_name,
        int age = default_age,
        int wage = default_wage,
        int number_of_sold_cars = default_number_of_sold_cars);
    ~Seller() = default;
    int get_code_of_seller() const;
    int get_number_of_sold_cars() const;
    void printInfo(std::ostream &os) const override;
};