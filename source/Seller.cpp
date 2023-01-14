#include <chrono>
#include <iostream>

#include "Seller.hpp"

Seller::Seller(int id, std::string name, int age, int wage) 
    :I_Person{id, name, age}, wage{wage} {
        std::vector <int> all_ids = get_all_ids();
        this->id = generate_id(all_ids);
}
const std::string current_date_time() {
    auto end = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(end);
    return std::ctime(&time);
}
void print_current_date_time() {
    std::cout << "Current time and date: " << current_date_time() << std::endl;
}
int Seller::get_code_of_seller() const {
    return code_of_seller;
}
int Seller::get_number_of_sold_cars() const {
    return number_of_sold_cars;
}
void Seller::printInfo(std::ostream &os) const {
    os << "[Seller: id:" << id  << ":" << name << ": " << age << "y.o: $" << wage << ": " << number_of_sold_cars << " cars sold]";
}
void purchase_information(I_Transport::PtrT car, std::shared_ptr<Client> client) {
    std::cout << client->get_name() << " " << client->get_age();
    std::cout << " have successfully bought a car:\n" << car->get_brand() 
    << " " << car->get_model() <<" " << car->get_color() << " color by price $" 
    << car->get_price() << "\n";
}
void write_receipt_to_file(I_Transport::PtrT car, std::shared_ptr<Client> client) {
    std::string receipt_file_path = "Receipts.txt";
    std::ofstream out_file;
    out_file.open(receipt_file_path, std::ios::app);
    if(!out_file) {
        throw FileOpenIssue();
    }
    std::vector <int> all_ids = get_all_ids();
    int id_of_receipt = generate_id(all_ids);
    out_file << "Id of receipt: " << id_of_receipt 
    << "\nCar: id:" << car->get_id() << " " <<  car->get_brand() << " " << car->get_model() 
    << " "  << car->get_country() << " " << car->get_color() << " color $" << car->get_price() << "\n"
    << "Client: id:" << client->get_id() << " " << client->get_name() << "\n";
}
void Seller::sell_car(I_Transport::PtrT car, std::shared_ptr<Client> client) {
    print_headline_for_greetings("RECEIPT");
    purchase_information(car, client);
    print_headline_for_greetings("TIME");
    print_current_date_time();
    print_headline_for_greetings("TIME");
    number_of_sold_cars++;
    std::cout << "Info about a seller" << std::endl;
    std::cout << *this << std::endl;
    print_headline_for_greetings("RECEIPT");
    write_receipt_to_file(car, client);
    return;
}    
