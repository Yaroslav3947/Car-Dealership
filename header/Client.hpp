#include <vector>

#include <I_Person.hpp>


class Client : public I_Person {
private:
    static constexpr const char *default_name = "Unnamed Client";
    static constexpr const int default_age = 18;
private:
    // std::vector <Transport *> cars; ////TODO: implement base class Transport
    int number_of_cars;
    static int code_of_client;
public:
    Client(std::string name = default_name, int age = default_age);
    virtual ~Client() = default;
    int get_number_of_cars() const;
    virtual int get_age() const override;
    virtual std::string get_name() const override;
    virtual void printInfo(std::ostream &os) const override;
};