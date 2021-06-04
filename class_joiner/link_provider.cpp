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
        {8, 55, 1, "https://meet.google.com/rkg-ewkv-sjj?pli=1&authuser=1", "Differential_Equations"},
        {9, 55, 1, "https://meet.google.com/wfp-jjbb-psb?hs=224&pli=1&authuser=1", "Physics_of_Materials"},
        {11, 55, 1, "https://meet.google.com/ixr-ojie-aam?pli=1&authuser=1", "Engineering_graphics"},
        {13, 55, 1, "https://meet.google.com/ixr-ojie-aam?pli=1&authuser=1", "Engineering_graphics_practice"},
        {14, 55, 1, "https://meet.google.com/ixr-ojie-aam?pli=1&authuser=1", "Engineering_graphics_practice"},
        {15, 55, 1, "https://meet.google.com/ixr-ojie-aam?pli=1&authuser=1", "Engineering_graphics_practice"},
        {16, 55, 1, "https://meet.google.com/ixr-ojie-aam?pli=1&authuser=1", "Engineering_graphics_practice"},
        {8, 55, 2, "https://meet.google.com/wfp-jjbb-psb?hs=224&pli=1&authuser=1", "Physics_of_Materials"},
        {9, 55, 2, "https://meet.google.com/gzk-vopj-zid?pli=1&authuser=1", "Data_structure_and_algorithm"},
        {11, 55, 2, "https://meet.google.com/smw-yhdt-mww?pli=1&authuser=1", "Discrete_Structures_for_Computer_Science"},
        {13, 55, 2, "https://meet.google.com/gzk-vopj-zid?pli=1&authuser=1", "Data_structure_and_algorithm_practice"},
        {14, 55, 2, "https://meet.google.com/mjn-buif-fvr?pli=1&authuser=1", "Data_structure_and_algorithm_practice"},
        {15, 55, 2, "https://meet.google.com/mjn-buif-fvr?pli=1&authuser=1", "Data_structure_and_algorithm_practice"},
        {16, 55, 2, "https://meet.google.com/mjn-buif-fvr?pli=1&authuser=1", "Data_structure_and_algorithm_practice"},
        {11, 55, 3, "https://meet.google.com/smw-yhdt-mww?pli=1&authuser=1", "Discrete_Structures_for_Computer_Science"},
        {14, 55, 3, "https://teams.microsoft.com/l/meetup-join/19%3a03857cdf7c9b4e4e82a47c8021e1dc6d%40thread.tacv2/1617025637706?context=%7b%22Tid%22%3a%22be5109ea-c534-473c-af60-2054e070a0ed%22%2c%22Oid%22%3a%2222c26465-12a8-4caf-b070-1a5f7ca97e25%22%7d", "Sociology_of_design"},
        {15, 55, 3, "https://teams.microsoft.com/l/meetup-join/19%3a03857cdf7c9b4e4e82a47c8021e1dc6d%40thread.tacv2/1617025637706?context=%7b%22Tid%22%3a%22be5109ea-c534-473c-af60-2054e070a0ed%22%2c%22Oid%22%3a%2222c26465-12a8-4caf-b070-1a5f7ca97e25%22%7d", "Sociology_of_design"},
        {16, 55, 3, "https://teams.microsoft.com/l/meetup-join/19%3a03857cdf7c9b4e4e82a47c8021e1dc6d%40thread.tacv2/1617025637706?context=%7b%22Tid%22%3a%22be5109ea-c534-473c-af60-2054e070a0ed%22%2c%22Oid%22%3a%2222c26465-12a8-4caf-b070-1a5f7ca97e25%22%7d", "Sociology_of_design"},
        {8, 55, 4, "https://meet.google.com/wfp-jjbb-psb?hs=224&pli=1&authuser=1", "Physics_of_Materials"},
        {9, 55, 4, "https://meet.google.com/gzk-vopj-zid?pli=1&authuser=1", "Data_structure_and_algorithm"},
        {10, 55, 4, "https://meet.google.com/smw-yhdt-mww?pli=1&authuser=1", "Discrete_Structures_for_Computer_Science"},
        {11, 55, 4, "https://meet.google.com/rkg-ewkv-sjj?pli=1&authuser=1", "Differential_Equations"},
        {13, 55, 4, "https://meet.google.com/ixr-ojie-aam?pli=1&authuser=1", "Engineering_graphics"},
        {15, 55, 4, "https://meet.google.com/lookup/d5twd57nfl", "Design_and_Manufacturing_Lab"},
        {9, 55, 5, "https://meet.google.com/rkg-ewkv-sjj?pli=1&authuser=1", "Differential_Equations"},
        {10, 55, 5, "https://meet.google.com/wfp-jjbb-psb?hs=224&pli=1&authuser=1", "Physics_of_Materials"},
        {13, 55, 5, "https://meet.google.com/gzk-vopj-zid?pli=1&authuser=1", "Data_structure_and_algorithm"},
        {14, 55, 5, "https://meet.google.com/smw-yhdt-mww?pli=1&authuser=1", "Discrete_Structures_for_Computer_Science"}};

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