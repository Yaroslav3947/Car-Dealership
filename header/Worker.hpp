#include <I_Person.hpp>

class Worker: public I_Person {
private:
    static constexpr const int default_age = 18;
    static constexpr const int default_wage = 70;
    static constexpr const char *default_name = "Unnamed Worker";
    static constexpr const int default_number_of_repaired_cars = 0;
private:
    int wage;
    static int code_of_worker;
    int number_of_repaired_cars;
    I_Transport *transport = new Car();
public:
    Worker(std::string name = default_name, int age = default_age, int wage = default_wage, int number_of_repaired_cars = default_number_of_repaired_cars);
    int get_wage() const;
    virtual ~Worker() = default;
    int get_number_of_repaired_cars() const;
    virtual void printInfo(std::ostream &os) const override;
};