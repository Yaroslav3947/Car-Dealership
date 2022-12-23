#include <vector>

#include <I_Person.hpp>


class Client : public I_Person {
private:
    static constexpr const char *default_name = "Unnamed Client";
    static constexpr const int default_age = 18;
private:
    int number_of_cars;
    static int code_of_client;
    std::vector <I_Transport *> cars;
public:
    Client(std::string name = default_name, int age = default_age);
    virtual ~Client() = default;
    int get_number_of_cars() const;
    virtual void printInfo(std::ostream &os) const override;
};