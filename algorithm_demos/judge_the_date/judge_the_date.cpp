#include <iostream>

using namespace std;

void dashbar(void);
int input_year(void);
bool is_leapyear(int);
int year_day(bool);
int input_day(int);
void show_year_day(int, int);

const int normal_month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int leap_month_day[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const char *month[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sept", "Oct", "Nov", "Dec"};

int main()
{
    cout << "Alter from Julian Calendar" << endl << endl;

    int day, year;
    year = input_year();
    day = input_day(year);

    show_year_day(year, day);
    return 0;
}
void dashbar(void)
{
    cout << "______________________________________" << endl;
}
bool is_leapyear(int year)
{
    if(year % 4 != 0) return false;
    else if(year % 100 != 0) return true;
    else if(year % 400 != 0) return false;
    else return true;
}
int year_day(bool flag)
{
    if(flag) return 366;
    else return 365;
}
int input_year(void)
{
    int year;
    while(1)
    {
        cout << "Input the year in Julian Calendar: ";
        cin >> year;
        if(!cin.good())
        {
            cout << "Invalid input" << endl;
            cout << "Please try again" << endl;
            dashbar();
            cin.clear();
            cin.sync();
            continue;
        }
        else if(cin.get() != '\n')
        {
            cout << "Please input digit only" << endl;
            cout << "Try again" << endl;
            dashbar();
            cin.sync();
            continue;
        }
        else if(year <= 0)
        {
            cout << "The year cannot be below 0" << endl;
            cout << "Try again" << endl;
            dashbar();
            cin.sync();
            continue;
        }
        else
        {
            return year;
        }
    }
}
int input_day(int year)
{
    int day;
    while(1)
    {
        cout << "Input the day in Julian Calendar: ";
        cin >> day;
        if(!cin.good())
        {
            cout << "Invalid input" << endl;
            cout << "Please try again" << endl;
            dashbar();
            cin.clear();
            cin.sync();
            continue;
        }
        else if(cin.get() != '\n')
        {
            cout << "Please input digit only" << endl;
            cout << "Try again" << endl;
            dashbar();
            cin.sync();
            continue;
        }
        else if(day <= 0 || day > year_day(is_leapyear(year)))
        {
            cout << "The day is out of the range" << endl;
            cout << "Try again" << endl;
            dashbar();
            cin.sync();
            continue;
        }
        else
        {
            return day;
        }
    }
}
void show_year_day(int year, int day)
{
    if(is_leapyear(year))
    {
        int index;
        for(index = 0; day > leap_month_day[index]; index++)
        {
            day -= leap_month_day[index];
        }
        cout << year << " " << month[index] << " " << day << endl;
        return ;
    }
    else
    {
        int index;
        for(index = 0; day > leap_month_day[index]; index++)
        {
            day -= normal_month_day[index];
        }
        cout << year << " " << month[index] << " " << day << endl;
        return ;
    }
}
