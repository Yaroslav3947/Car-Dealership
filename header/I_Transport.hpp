#pragma once

#include <list>
#include <vector>
#include <memory>
#include <string>

#include <I_Printable.hpp>
#include <FileOpenIssue.hpp>

#include <NoFreeIdException.hpp>
#include <IllegalPriceException.hpp>
#include <IllegalFuelComsumptionException.hpp>
#include <IllegalYearOfManufactureException.hpp>

class I_Transport : public I_Printable {
    const int floor_price = 0;
protected:
    int id;
    bool is_new;
    double price;
    std::string brand;
    std::string model;
    std::string country;
    std::string color;
    double fuel_consumption;
    int year_of_manufacture;
    static constexpr const int default_id = -1;  
    static constexpr const double default_price = 0.0;
    static constexpr const bool default_is_new = true;
    static constexpr const int default_year_of_manufacture = 0;
    static constexpr const double default_fuel_consumption = 0.0;
    static constexpr const char *default_model = "unknown model";
    static constexpr const char *default_brand = "unknown brand";
    static constexpr const char *default_country = "unknown country";
    static constexpr const char *default_color = "unknown color";
public:
    I_Transport(int id = default_id, std::string brand = default_brand,
            std::string model = default_model,
            std::string color = default_color,
            std::string country = default_country,
            int year_of_manufacture = default_year_of_manufacture,
            double fuel_consumption = default_fuel_consumption, 
            double price = default_price,
            bool is_new = default_is_new);
    int get_id() const;
    bool get_is_new() const;
    double get_price() const;
    std::string get_brand() const;
    std::string get_color() const;
    std::string get_model() const;
    std::string get_country() const;
    virtual ~I_Transport() = default;
    double get_fuel_consumption() const;
    int get_year_of_manufacture() const;
    virtual void write_info_to_file() = 0;
    using PtrT = std::shared_ptr<I_Transport>;
    virtual void set_id(const size_t &id) = 0;
    void printInfo(std::ostream &os) const override = 0;
    virtual void print_all_info_from_file() const = 0;
    virtual void inputInfo(std::list <PtrT> &list) = 0;
};