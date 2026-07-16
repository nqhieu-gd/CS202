#include "Date.h"

int main()
{
	Date d1;
	Date d2(2012);
	Date d3(2012, 8);
	Date d4(2012, 10, 17);
	Date d5(d2);
	Date d6;
	d6 = d3;

	d6 = d3.Tomorrow();
	d5 = d2.Yesterday();

	std::cout << (d6 == d4);
	std::cout << (d6 != d4);
	std::cout << (d6 >= d4);
	std::cout << (d6 <= d4);
	std::cout << (d6 > d4);
	std::cout << (d6 < d4);

	d3 = d2 + 1;
	d2 = d3 - 2;
	d4++;
	++d2;
	d5--;
	--d6;

	std::cout << d3;
	std::cin >> d4;

	std::cout << (int)d3;

	std::cout << (long)d4;

	Date d7;
	d7 += 7;
	d2 -= 6;

	return 0;
}
