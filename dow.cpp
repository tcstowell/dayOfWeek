#include <iostream>
using namespace std;
bool isleapyear(int& year);
int getcentury(int& year);
int getyear(int& year);
int getmonth(int month, int year);
int dayofweek(int month, int day, int year);
int main()
{
	int year, month, day, w, x, y, z, a, b;
	bool v;
	cout << "Enter the year\n";
	cin >> year;
	cout << "Enter the month\n";
	cin >> month;
	cout << "Enter the day\n";
	cin >> day;
	z = dayofweek(month, day, year);
	switch (z){
		case 0:
		cout << "Sunday";
		break;
		case 1:
		cout << "Monday";
		break;
		case 2:
		cout << "Tuesday";
		break;
		case 3:
		cout << "Wednesday";
		break;
		case 4:
		cout << "Thurday";
		break;
		case 5:
		cout << "Friday";
		break;
		case 6:
		cout << "Sabbath";
		break;
	}
	cout << "\n";
	return 0;
}
bool isleapyear(int& year){
	int leap;
	leap = year % 4;
	switch (leap){
		case 0:
            cout << "Is leap year!\n";
		return true;
		break;
		default:
		return false;
		break;
	}
}
int getcentury(int& year){
	int cent, ye;
	ye = year / 100; // Get the first two digits in of the year 2007 => 20
	cent = ye % 4; // get remainder of the century divided by 4
	cent = 3 - cent; // 3 - the remainder of 4
	cent = cent * 2; // times 2
	cout << cent << " century\n";
	return cent;
	}
int getyear(int& year){
		int y, x;
		y = year;
		while(y >= 100){ // get the last two digits from to year 2007 => 07
			y -= 100;
		}
		x = y / 4; //  07 divided by 4
		x = y + x; // 07 + 07 divided by 4
		cout << x << " year\n";
		return x;
	}
int getmonth(int month, int year){
	bool leap;
	int mnth[] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5, 6, 2}, x, day;
	leap = isleapyear(year);
	if (leap == true && (month == 2 || month == 1))
		month = month + 11;
	else
		month -= 1;
	x = mnth[month];
	cout << x << " month\n";
	return x;
}
int dayofweek(int month, int day, int year){
	int m, d, ye, ar;
	ye = getcentury(year);
	ar = getyear(year);
	m = getmonth(month, year);
	d = day + m + ye + ar;
	d = d % 7;
	return d;
}
