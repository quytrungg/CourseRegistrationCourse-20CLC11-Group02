#include <ctime>
#include <iostream>
using namespace std;
int main()
{
    time_t t = time(0);
    struct tm* ti = new tm;
    gmtime_s(ti,&t);
    cout << ti->tm_year<<" "<<ti->tm_mon<<" "<<ti->tm_mday;
    delete ti;
    return 0;
}
