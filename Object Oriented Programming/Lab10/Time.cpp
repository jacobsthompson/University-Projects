#include "Time.h"
#include <iostream>

using namespace std;

int main()
{

	cout << char(97) << endl;

	Time time1(1, 20, 30);
	Time time2(3, 15, 8);
	Time time3(21, 50, 45);

	Time time4 = time1 + time2;
	Time time5 = time1++ + time3;
	Time time6 = time1 + time3;
	Time time7 = ++time4 + time4;

	time4.print();
	time5.print();
	time6.print();
	time7.print();
}