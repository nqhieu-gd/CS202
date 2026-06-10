#include "Theater.h"
#include <limits>

Theater::Theater() : totalSales(0.0) {
    cout << "Theater::Default constructor" << endl;
    for (int i = 0; i < ROWS; i++) {
        rowPrices[i] = 10.0;
        for (int j = 0; j < SEATS_PER_ROW; j++) {
            seats[i][j] = false;
        }
    }

    cout << "Load seat prices from:" << endl;
    cout << "1. Manual entry" << endl;
    cout << "2. File" << endl;
    cout << "3. Use defaults ($10/seat)" << endl;
    cout << "Choose (1-3): ";

    int priceChoice;
    cin >> priceChoice;
    while (cin.fail() || priceChoice < 1 || priceChoice > 3) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid choice. Enter 1-3: ";
        cin >> priceChoice;
    }

    if (priceChoice == 1) {
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

Theater::Theater(const Theater& other) : totalSales(other.totalSales) {
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

int Theater::sellGroup(int row, int startSeat, int count) {
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

void Theater::showTotalSales() const {
    cout << fixed << setprecision(2);
    cout << "Total ticket sales: $" << totalSales << endl;
}

void Theater::showStats() const {
    int totalSold = 0;
    int totalAvailable = 0;

    cout << endl << "--- Seat Statistics ---" << endl;
    for (int i = 0; i < ROWS; i++) {
        int rowSold = 0;
        for (int j = 0; j < SEATS_PER_ROW; j++) {
            if (seats[i][j]) rowSold++;
        }
        int rowAvail = SEATS_PER_ROW - rowSold;
        totalSold += rowSold;
        totalAvailable += rowAvail;
        cout << "Row " << (i + 1) << ": " << rowSold << " sold, " << rowAvail << " available"
             << " ($" << fixed << setprecision(0) << rowPrices[i] << "/seat)" << endl;
    }
    cout << "------------------------" << endl;
    cout << "Total: " << totalSold << " sold, " << totalAvailable << " available"
         << " (out of " << (ROWS * SEATS_PER_ROW) << " seats)" << endl;
    cout << fixed << setprecision(2);
    cout << "Total sales: $" << totalSales << endl << endl;
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
    cout << "=== Welcome to the Theater Ticket System ===" << endl;

    int option;
    do {
        cout << endl << "--- Menu ---" << endl;
        cout << "1. Display seating chart" << endl;
        cout << "2. Sell ticket(s)" << endl;
        cout << "3. View total sales" << endl;
        cout << "4. View seat statistics" << endl;
        cout << "5. Exit" << endl;
        cout << "Choose an option (1-5): ";
        cin >> option;

        while (cin.fail() || option < 1 || option > 5) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid option. Choose 1-5: ";
            cin >> option;
        }

        switch (option) {
            case 1:
                displaySeatingChart();
                break;
            case 2: {
                cout << "Single ticket (1) or group (2)? ";
                int type;
                cin >> type;
                while (cin.fail() || (type != 1 && type != 2)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Enter 1 (single) or 2 (group): ";
                    cin >> type;
                }

                if (type == 1) {
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
                    sellTicket(row, seat);
                } else {
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
                    sellGroup(row, startSeat, count);
                }
                break;
            }
            case 3:
                showTotalSales();
                break;
            case 4:
                showStats();
                break;
            case 5:
                cout << "Thank you for using the Theater Ticket System!" << endl;
                break;
        }
    } while (option != 5);
}
