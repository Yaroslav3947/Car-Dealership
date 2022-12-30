#include <vector>

#include <I_Person.hpp>


class Client final : public I_Person {
    static constexpr const char *default_name = "Unnamed Client";
    static constexpr const int default_age = 18;
    static constexpr const int default_number_of_cars = 0;
    // static int code_of_client;
    std::vector <I_Transport *> cars;
    int number_of_cars = default_number_of_cars;
public:
    Client(std::string name = default_name, int age = default_age);
    int get_number_of_cars() const;
    ~Client() = default;
    std::vector<I_Transport *> get_cars();
    void add_car( I_Transport *car);
    virtual void printInfo(std::ostream &os) const override;
};