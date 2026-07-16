#include <iostream>

class vehicle {
protected:
    std::string reg_num;
    int rent_rate;
    std::string model;

public:
    virtual void display() = 0;
    virtual std::string quote(int days) = 0;
    virtual ~vehicle() = default;
};

class car : public vehicle {
private:
    int engine_capacity;
    int discount;

    std::string quote(int days) override;
    void display() override;

public:
    car(std::string reg_num, int rate, std::string model, int capacity, int disc);
};

class motorcycle : public vehicle {
private:
    bool has_sidecar;
    int sidecar_surcharge;

    std::string quote(int days) override;
    void display() override;

public:
    motorcycle(std::string reg_num, int rate, std::string model, bool sidecar, int surcharge);
};

class bike : public vehicle {
private:
    bool is_electric;
    int battery_fee;
    int discount;

    std::string quote(int days) override;
    void display() override;

public:
    bike(std::string reg_num, int rate, std::string model, bool electric, int battery_fee, int discount);
};