#ifndef PROJECT_H_
#define PROJECT_H_
#include <string>
using namespace std;
struct Account {
	std::string Name;
	std::string Password;
};
struct Date {
	int Day;
	int Month;
	int Year;
};
struct Time {
	int Seconds;
	int Minutes;
	int Hours;
};
struct LocalTime {
	struct Time time;
	struct Date date;
};
struct Student {
	int ID;
	std::string FirstName;
	std::string LastName;
	std::string Gender;
	Date Dateofbirth;
	int SocialID;
};
#endif // !PROJECT_H_