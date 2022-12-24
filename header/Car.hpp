#include <I_Transport.hpp>

class Car final: public I_Transport {
private:
    // size_t code_of_car;
    bool is_need_repair;
    int number_of_doors;
    std::string type_of_fuel;
    std::string configuration;
    std::string car_body_styles;
    static constexpr const char *default_car_body_styles = "no car body style";
    static constexpr const int default_number_of_doors = 0;
    static constexpr const bool default_is_need_repair = false;
    static constexpr const char *default_type_of_fuel = "no type of fuel";
    
public:
    Car(std::string brand = default_brand, std::string model = default_model, std::string color = default_color, std::string country = default_country,
                int year_of_manufacture = default_year_of_manufacture, double fuel_comsumption = default_fuel_comsumption, 
                double price = default_price, bool is_new = default_is_new, std::string car_body_styles = default_car_body_styles, int number_of_doors = default_number_of_doors,
                bool is_need_repair = default_is_need_repair, std::string type_of_fuel = default_type_of_fuel);
    ~Car() = default;
    void set_configuration();
    bool get_is_need_repair() const;
    int get_number_of_doors() const;
    std::string get_type_of_fuel() const;
    std::string get_configuration() const;
    std::string get_car_body_styles() const;
    virtual void inputInfo(std::istream &is) override;
    virtual void printInfo(std::ostream &os) const override;
};

