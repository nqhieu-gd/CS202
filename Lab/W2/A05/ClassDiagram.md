classDiagram
    class Theater {
        - bool seats[15][30]
        - double rowPrices[15]
        - double totalSales
        + Theater()
        + Theater(const Theater& other)
        + ~Theater()
        + operator=(const Theater& other) Theater&
        + initializePrices() void
        + loadPricesFromFile(const string& filename) bool
        + displaySeatingChart() void
        + sellTicket(int row, int seat) bool
        + sellGroup(int row, int startSeat, int count) int
        + showTotalSales() void
        + showStats() void
        + toString() string
        + clone() Theater
        + run() void
    }
