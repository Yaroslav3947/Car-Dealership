#include <I_Person.hpp>

class Seller : public I_Person {
private:
    static constexpr const int default_age = 18;
    static constexpr const int default_wage_per_day = 50;
    static constexpr const int default_number_of_sold_cars = 0;
    static constexpr const char *default_name = "Unnamed Seller";
private:
    int wage_per_day;
    int code_of_seller;
    int number_of_sold_cars;
public:
    Seller(std::string name = default_name, int age = default_age, int wage_per_day = default_wage_per_day,int number_of_sold_cars = default_number_of_sold_cars);
    virtual ~Seller() = default;
    int get_wage_per_day() const;
    int get_code_of_seller() const;
    int get_number_of_sold_cars() const;
    virtual int get_age() const override;
    virtual std::string get_name() const override;
    virtual void printInfo(std::ostream &os) const override;
};