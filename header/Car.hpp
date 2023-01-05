#pragma once
#include <fstream>

#include <I_Transport.hpp>
#include <UtilChecking.hpp>
class Car : public I_Transport, public std::enable_shared_from_this<Car> {
    bool is_need_repair;
    int number_of_doors;
    std::string type_of_fuel;
    std::string configuration;
    std::string car_body_styles;
    void write_info_to_file() override;
    const std::string path_to_car_file = "Car.txt";
    static constexpr const char *default_car_body_styles = "no style";
    static constexpr const int default_number_of_doors = 0;
    static constexpr const bool default_is_need_repair = false;
    static constexpr const char *default_type_of_fuel = "no fuel";
public:
    Car(int id = default_id, std::string brand = default_brand,
        std::string model = default_model,
        std::string color = default_color,
        std::string country = default_country,
        int year_of_manufacture = default_year_of_manufacture,
        double fuel_consumption = default_fuel_consumption, 
        double price = default_price,
        bool is_new = default_is_new,
        std::string car_body_styles = default_car_body_styles,
        int number_of_doors = default_number_of_doors,
        bool is_need_repair = default_is_need_repair,
        std::string type_of_fuel = default_type_of_fuel);
    ~Car() = default;
    void set_configuration();
    bool get_is_need_repair() const;
    int get_number_of_doors() const;
    std::string get_type_of_fuel() const;
    std::string get_configuration() const;
    void set_id(const size_t &id) override;
    std::string get_car_body_styles() const;
    void print_all_info_from_file() const override;
    void inputInfo(std::list <PtrT> &list) override; 
    virtual void printInfo(std::ostream &os) const override;
    void set_is_need_repair(const bool &is_need_repair) override;
    void set_number_of_doors(const std::string &car_body_styles, int &number_of_doors);
};

