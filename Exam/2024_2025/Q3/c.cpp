#include "b.h"
#include <vector>

car::car(std::string reg_num, int rate, std::string model, int capacity, int disc) {
    this->reg_num = reg_num;
    this->rent_rate = rate;
    this->model = model;
    this->engine_capacity = capacity;
    this->discount = disc;
}

bike::bike(std::string reg_num, int rate, std::string model, bool electric, int battery_fee, int discount) {
    this->reg_num = reg_num;
    this->rent_rate = rate;
    this->model = model;
    this->is_electric = electric;
    this->battery_fee = battery_fee;
    this->discount = discount;
}

motorcycle::motorcycle(std::string reg_num, int rate, std::string model, bool sidecar, int surcharge) {
    this->reg_num = reg_num;
    this->rent_rate = rate;
    this->model = model;
    this->has_sidecar = sidecar;
    this->sidecar_surcharge = surcharge;
}

void car::display() {
    std::cout << "Car Model: " << model << '.' << std::endl;
    std::cout << "Car Registration Number: " << reg_num << '.' << std::endl;
    std::cout << "Car Engine Capacity: " << engine_capacity << '.' << std::endl;
    std::cout << "Car Rental Rate: " << rent_rate << '.' << std::endl;
    std::cout << "Discount for renting more than 1 week: " << discount << "%.\n" << std::endl;
}

void motorcycle::display() {
    std::cout << "Motorcycle Model: " << model << '.' << std::endl;
    std::cout << "Motorcycle Registration Number: " << reg_num << '.' << std::endl;
    std::cout << "Motorcycle Rental Rate: " << rent_rate << '.' << std::endl;
    if (has_sidecar) {
        std::cout << "Additional Sidecar Surcharge: " << sidecar_surcharge << '.' << std::endl;
    }
}

void bike::display() {
    std::cout << "Bike Model: " << model << '.' << std::endl;
    std::cout << "Bike Registration Number: " << reg_num << '.' << std::endl;
    std::cout << "Bike Rental Rate: " << rent_rate*((float) (100 - is_electric*discount)/100) << '.' << std::endl;
    if (is_electric) {
        std::cout << "Additional Electric Bike Fee: " << battery_fee << '.' << std::endl;
    }
}

std::string car::quote(int days) {
    return "Car Quote: " + std::to_string(rent_rate * days * ((days > 7) ? ((float) (100 - discount)/100) : 1.0)) + '.';
}

std::string motorcycle::quote(int days) {
    return "Motorcycle Quote: " + std::to_string(rent_rate * days + (has_sidecar ? sidecar_surcharge : 0)) + '.';
}

std::string bike::quote(int days) {
    return "Bike Quote: " + std::to_string(rent_rate * days * (1 - (float)discount/100) + (is_electric ? battery_fee : 0)) + '.';
}

int main() {
    std::vector<vehicle*> vehicles;
    vehicle* car1 = new car("CAR001", 50, "Toyota Camry", 2000, 10);
    vehicle* motorcycle1 = new motorcycle("MOTO001", 30, "Harley Davidson", true, 20);
    vehicle* bike1 = new bike("BIKE001", 20, "Trek FX", true, 15, 5);

    vehicles.push_back(car1);
    vehicles.push_back(motorcycle1);
    vehicles.push_back(bike1);

    for (const auto& vehicle : vehicles) {
        vehicle->display();
        std::cout << vehicle->quote(10) << std::endl;
    }

    for (auto& vehicle : vehicles) {
        delete vehicle;
    }

    return 0;
}