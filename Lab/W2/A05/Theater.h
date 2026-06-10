#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
using namespace std;

class Theater {
private:
    static const int ROWS = 15;
    static const int SEATS_PER_ROW = 30;
    bool seats[ROWS][SEATS_PER_ROW];
    double rowPrices[ROWS];
    double totalSales;

public:
    Theater();
    Theater(const Theater& other);
    ~Theater();

    Theater& operator=(const Theater& other);

    void initializePrices();
    bool loadPricesFromFile(const string& filename);
    void displaySeatingChart() const;
    bool sellTicket(int row, int seat);
    int sellGroup(int row, int startSeat, int count);
    void showTotalSales() const;
    void showStats() const;
    string toString() const;
    Theater clone() const;
    void run();
};
