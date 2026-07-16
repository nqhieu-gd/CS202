#include "Theater.h"
#include <limits>

Theater::Theater() : totalSales(0.0), valid(true) {
    cout << "Theater::Default constructor" << endl;
    for (int i = 0; i < ROWS; i++) {
        rowPrices[i] = 10.0;
        for (int j = 0; j < SEATS_PER_ROW; j++) {
            seats[i][j] = false;
        }
    }

    cout << "Load seat prices from:" << endl;
    cout << "0. Cancel (abandon theater)" << endl;
    cout << "1. Manual entry" << endl;
    cout << "2. File" << endl;
    cout << "3. Use defaults ($10/seat)" << endl;
    cout << "Choose (0-3): ";

    int priceChoice;
    cin >> priceChoice;
    while (cin.fail() || priceChoice < 0 || priceChoice > 3) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid choice. Enter 0-3: ";
        cin >> priceChoice;
    }

    if (priceChoice == 0) {
        valid = false;
        cout << "Theater creation cancelled." << endl;
    } else if (priceChoice == 1) {
        initializePrices();
    } else if (priceChoice == 2) {
        cout << "Enter path to file: ";
        string filename;
        cin >> filename;
        loadPricesFromFile(filename);
    } else {
        cout << "Using default prices ($10 per seat)." << endl;
    }
}

Theater::Theater(const Theater& other) : totalSales(other.totalSales), valid(other.valid) {
    cout << "Theater::Copy constructor" << endl;
    for (int i = 0; i < ROWS; i++) {
        rowPrices[i] = other.rowPrices[i];
        for (int j = 0; j < SEATS_PER_ROW; j++) {
            seats[i][j] = other.seats[i][j];
        }
    }
}

Theater& Theater::operator=(const Theater& other) {
    cout << "Theater::Copy assignment" << endl;
    if (this != &other) {
        totalSales = other.totalSales;
        valid = other.valid;
        for (int i = 0; i < ROWS; i++) {
            rowPrices[i] = other.rowPrices[i];
            for (int j = 0; j < SEATS_PER_ROW; j++) {
                seats[i][j] = other.seats[i][j];
            }
        }
    }
    return *this;
}

Theater::~Theater() {
    cout << "Theater::Destructor" << endl;
}

bool Theater::loadPricesFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Could not open file \"" << filename << "\"" << endl;
        return false;
    }
    double price;
    int count = 0;
    while (file >> price && count < ROWS) {
        if (price >= 0) {
            rowPrices[count++] = price;
        }
    }
    file.close();
    if (count < ROWS) {
        cout << "Warning: Only read " << count << " prices (expected " << ROWS << ")." << endl;
        for (int i = count; i < ROWS; i++) {
            rowPrices[i] = 10.0;
        }
    }
    return count > 0;
}

void Theater::initializePrices() {
    cout << "Enter price for each row (1-" << ROWS << "):" << endl;
    for (int i = 0; i < ROWS; i++) {
        cout << "Row " << (i + 1) << " price: $";
        cin >> rowPrices[i];
        while (cin.fail() || rowPrices[i] < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid price. Enter a positive number: $";
            cin >> rowPrices[i];
        }
    }
}

void Theater::displaySeatingChart() const {
    cout << endl << "  ";
    for (int j = 1; j <= SEATS_PER_ROW; j++) {
        cout << (j % 10);
    }
    cout << endl;

    for (int i = 0; i < ROWS; i++) {
        cout << setw(2) << (i + 1) << " ";
        for (int j = 0; j < SEATS_PER_ROW; j++) {
            cout << (seats[i][j] ? '*' : '#');
        }
        cout << " $" << fixed << setprecision(0) << rowPrices[i] << endl;
    }
    cout << endl;
}

bool Theater::sellTicket(int row, int seat) {
    if (row < 1 || row > ROWS || seat < 1 || seat > SEATS_PER_ROW) {
        cout << "Error: Invalid row or seat number." << endl;
        return false;
    }

    int r = row - 1;
    int s = seat - 1;

    if (seats[r][s]) {
        cout << "Error: Seat " << row << "-" << seat << " is already taken." << endl;
        return false;
    }

    seats[r][s] = true;
    totalSales += rowPrices[r];
    cout << "Seat " << row << "-" << seat << " sold for $" << fixed << setprecision(0) << rowPrices[r] << endl;
    return true;
}

int Theater::sellConsecutive(int row, int startSeat, int count) {
    if (row < 1 || row > ROWS) {
        cout << "Error: Invalid row number." << endl;
        return 0;
    }
    if (startSeat < 1 || count < 1 || startSeat + count - 1 > SEATS_PER_ROW) {
        cout << "Error: Invalid seat range." << endl;
        return 0;
    }

    int r = row - 1;
    for (int s = startSeat - 1; s < startSeat - 1 + count; s++) {
        if (seats[r][s]) {
            cout << "Error: Seat " << row << "-" << (s + 1) << " is already taken." << endl;
            return 0;
        }
    }

    double groupTotal = 0;
    for (int s = startSeat - 1; s < startSeat - 1 + count; s++) {
        seats[r][s] = true;
        groupTotal += rowPrices[r];
    }
    totalSales += groupTotal;
    cout << count << " seats sold in row " << row << " for $" << fixed << setprecision(2) << groupTotal << endl;
    return count;
}

int Theater::sellGroup(int count) {
    int sold = 0;
    double total = 0;
    for (int i = 0; i < count; i++) {
        cout << "\nSeat " << (i + 1) << " of " << count << ":" << endl;
        int row, seat;
        cout << "Enter row (1-" << ROWS << "): ";
        cin >> row;
        while (cin.fail() || row < 1 || row > ROWS) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid row. Enter 1-" << ROWS << ": ";
            cin >> row;
        }
        cout << "Enter seat (1-" << SEATS_PER_ROW << "): ";
        cin >> seat;
        while (cin.fail() || seat < 1 || seat > SEATS_PER_ROW) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid seat. Enter 1-" << SEATS_PER_ROW << ": ";
            cin >> seat;
        }
        if (sellTicket(row, seat)) {
            sold++;
            total += rowPrices[row - 1];
        } else {
            cout << "Skipping this seat." << endl;
        }
    }
    if (sold > 0) {
        cout << sold << " of " << count << " seats sold for $" << fixed << setprecision(2) << total << endl;
    }
    return sold;
}

void Theater::showTotalSales() const {
    cout << fixed << setprecision(2);
    cout << "Total ticket sales: $" << totalSales << endl;
}

void Theater::showStats() const {
    int totalAvailable = 0;

    cout << endl << "--- Seat Statistics ---" << endl;
    for (int i = 0; i < ROWS; i++) {
        int rowSold = 0;
        for (int j = 0; j < SEATS_PER_ROW; j++) {
            if (seats[i][j]) rowSold++;
        }
        int rowAvail = SEATS_PER_ROW - rowSold;
        totalAvailable += rowAvail;
        cout << "Row " << (i + 1) << ": " << rowSold << " sold, " << rowAvail << " available" << endl;
    }
    cout << "------------------------" << endl;
    cout << "Total seats available in the auditorium: " << totalAvailable << endl << endl;
}

string Theater::toString() const {
    stringstream ss;
    ss << "Theater{rows=" << ROWS << ", seatsPerRow=" << SEATS_PER_ROW
       << ", totalSales=" << totalSales << "}";
    return ss.str();
}

Theater Theater::clone() const {
    return Theater(*this);
}

void Theater::run() {
    if (!valid) {
        cout << "Theater was abandoned. No operations available." << endl;
        return;
    }
    cout << "=== Welcome to the Theater Ticket System ===" << endl;

    int option;
    do {
        cout << endl << "--- Menu ---" << endl;
        cout << "1. Sell ticket(s)" << endl;
        cout << "2. View total sales" << endl;
        cout << "3. View seat statistics" << endl;
        cout << "4. Exit" << endl;
        cout << "Choose an option (1-4): ";
        cin >> option;

        while (cin.fail() || option < 1 || option > 4) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid option. Choose 1-4: ";
            cin >> option;
        }

        switch (option) {
            case 1: {
                displaySeatingChart();
                cout << "Group consecutive (1) or group custom (2)? ";
                int type;
                cin >> type;
                while (cin.fail() || type < 1 || type > 2) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Enter 1 or 2: ";
                    cin >> type;
                }

                if (type == 1) {
                    int row, startSeat, count;
                    cout << "Enter row (1-" << ROWS << "): ";
                    cin >> row;
                    while (cin.fail() || row < 1 || row > ROWS) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid row. Enter 1-" << ROWS << ": ";
                        cin >> row;
                    }
                    cout << "Enter starting seat (1-" << SEATS_PER_ROW << "): ";
                    cin >> startSeat;
                    while (cin.fail() || startSeat < 1 || startSeat > SEATS_PER_ROW) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid seat. Enter 1-" << SEATS_PER_ROW << ": ";
                        cin >> startSeat;
                    }
                    cout << "Enter number of seats: ";
                    cin >> count;
                    while (cin.fail() || count < 1 || startSeat + count - 1 > SEATS_PER_ROW) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid count (max " << (SEATS_PER_ROW - startSeat + 1) << "): ";
                        cin >> count;
                    }
                    sellConsecutive(row, startSeat, count);
                } else {
                    int count;
                    cout << "Enter number of seats: ";
                    cin >> count;
                    while (cin.fail() || count < 1) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid count. Enter at least 1: ";
                        cin >> count;
                    }
                    sellGroup(count);
                }
                break;
            }
            case 2:
                showTotalSales();
                break;
            case 3:
                showStats();
                break;
            case 4:
                cout << "Thank you for using the Theater Ticket System!" << endl;
                break;
        }
    } while (option != 4);
}
