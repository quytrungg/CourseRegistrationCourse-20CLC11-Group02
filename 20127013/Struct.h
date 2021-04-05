#ifndef PROJECT_H_
#define PROJECT_H_
#include <string>
struct Account {
	std::string Name;
	std::string Password;
};
struct Date {
	char Day[3];
	char Month[3];
	char Year[5];
};
struct Time {
	char Seconds[3];
	char Minutes[3];
	char Hours[3];
};
struct LocalTime {
	struct Time time;
	struct Date date;
} local;
struct Student {
	int ID;
	std::string FirstName;
	std::string LastName;
	std::string Gender;
	Date Dateofbirth;
	int SocialID;
};
#endif // !PROJECT_H_

