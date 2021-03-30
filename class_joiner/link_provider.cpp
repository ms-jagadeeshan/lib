#include <iostream>
#include <string.h>
using namespace std;
bool isFound = false;
bool notFound = false;
class timings
{
private:
    string link;
    int hour, minute, day;
    string classname;

public:
    timings();
    timings(int hour_, int minute_, int day_, string link_, string classname_)
    {
        hour = hour_;
        minute = minute_;
        day = day_;
        link = link_;
        classname = classname_;
    }
    void getInfo()
    {

        cout << ' ' << classname;
        printf(" %d %d", day, hour + 1);
    }
    void search(int hour_, int minute_, int day_)
    {
        if (day <= day_)
        {
            if (day == day_)
            {
                if (minute_ > 49)
                {
                    if (hour > hour_)
                    {
                        notFound = true;
                    }
                    if (day == day_ && hour == hour_)
                    {
                        cout << link;
                        isFound = true;
                    }
                }
                else if (minute_ <= 49)
                {
                    if (hour > hour_ - 1)
                    {
                        notFound = true;
                    }
                    if (day == day_ && hour == hour_ - 1)
                    {
                        cout << link;
                        isFound = true;
                    }
                }
            }
        }
        else
        {
            notFound = true;
        }
    }
};

int main(int argc, char *argv[])
{
    timings a[] = {
        {8, 55, 1, "fill_link_here", "Differential_Equations"},
        {9, 55, 1, "fill_link_here", "Physics_Elective"},
        {10, 55, 1, "fill_link_here", "Data_structure_and_algorithm"},
        {11, 55, 1, "fill_link_here", "Engineering_graphics"},
        {13, 55, 1, "fill_link_here", "Discrete_Structures_for_Computer_Science"},
        {14, 55, 1, "fill_link_here", "Engineering_graphics_practice"},
        {15, 55, 1, "fill_link_here", "Engineering_graphics_practice"},
        {16, 55, 1, "fill_link_here", "Engineering_graphics_practice"},
        {17, 55, 1, "fill_link_here", "Engineering_graphics_practice"},
        {8, 55, 2, "fill_link_here", "Physics_Elective"},
        {9, 55, 2, "fill_link_here", "Data_structure_and_algorithm"},
        {11, 55, 2, "fill_link_here", "Discrete_Structures_for_Computer_Science"},
        {13, 55, 2, "fill_link_here", "Differential_Equations"},
        {14, 55, 2, "fill_link_here", "Data_structure_and_algorithm_practice"},
        {15, 55, 2, "fill_link_here", "Data_structure_and_algorithm_practice"},
        {16, 55, 2, "fill_link_here", "Data_structure_and_algorithm_practice"},
        {17, 55, 2, "fill_link_here", "Data_structure_and_algorithm_practice"},
        {13, 55, 3, "fill_link_here", "Physics_Elective"},
        {14, 55, 3, "fill_link_here", "Sociology_of_design"},
        {15, 55, 3, "fill_link_here", "Sociology_of_design"},
        {16, 55, 3, "fill_link_here", "Sociology_of_design"},
        {10, 55, 4, "fill_link_here", "Discrete_Structures_for_Computer_Science"},
        {11, 55, 4, "fill_link_here", "Engineering_graphics"},
        {13, 55, 4, "fill_link_here", "Differential_Equations"},
        {15, 55, 4, "fill_link_here", "Design_and_Manufacturing_Lab"},
        {9, 55, 5, "fill_link_here", "Differential_Equations"},
        {10, 55, 5, "fill_link_here", "Physics_Elective"},
        {13, 55, 5, "fill_link_here", "Data_structure_and_algorithm"},
        {14, 55, 5, "fill_link_here", "Discrete_Structures_for_Computer_Science"}};

    //converting the string arguments to integer
    int day1 = argv[3][0] - '0';
    int hour1 = (strlen(argv[1]) == 1) ? (argv[1][0] - '0') : ((argv[1][0] - '0') * 10) + (argv[1][1] - '0'); 
    int minute1 = ((argv[2][0] - '0') * 10) + (argv[2][1] - '0');
    //a[i].search(hour1, minute1, day1);
    int no_of_rows = sizeof(a) / sizeof(a[0]);
    int i = 0;
    for (i; i < no_of_rows; ++i)
    {
        if (isFound) // whenever link found breaks the loop
        {
            break;
        }
        else
            a[i].search(hour1, minute1, day1);

        if (notFound) //whenever sure about link won't be found, breaks the loop
        {
            break;
        }
    }
    if (!isFound) // if class not found returns noc
        cout << "noc";
    if (isFound) // if class link found prints the details of the class
    {
        a[i - 1].getInfo();
    }
    else
        a[i % no_of_rows].getInfo(); //prints the next class details
}