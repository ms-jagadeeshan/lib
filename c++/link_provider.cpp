#include <iostream>
#include <string.h>
using namespace std;
bool isFound = false;
bool nextisFound = true;
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
                    if (day == day_ && hour == hour_)
                    {
                        cout << link;
                        isFound = true;
                    }
                }
                else if (minute_ <= 49)
                {
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
            nextisFound = false;
        }
    }
};

int main(int argc, char *argv[])
{
    timings a[21] = {
        {8, 55, 1, "https://meet.google.com/qzi-ywmf-cry?pli=1&authuser=1", "Calculus"},                                                                                                                                                                                        //Calculus ,Monday
        {9, 55, 1, "https://meet.google.com/zic-wtjg-maw?pli=1&authuser=1", "Electromagnetics_Engineering"},                                                                                                                                                                    //Electomagnetics ,Monday
        {10, 55, 1, "https://teams.microsoft.com/l/channel/19%3a3ce9fe07ff004a9683ef056bc016551e%40thread.tacv2/General?groupId=905dfe47-e342-4fb0-8cd5-d7f98addfc2b&tenantId=be5109ea-c534-473c-af60-2054e070a0ed", "Programming_and_Problem_Solving"},                        //Programming team link
        {11, 55, 1, "https://meet.google.com/lookup/hcstbcvhfm", "Electric_Circuits"},                                                                                                                                                                                         //Electric_Circuits batch-1 link ,Edit it if you are batch-2
        {13, 55, 1, "https://teams.microsoft.com/l/meetup-join/19%3ad7c001250cf44a56a26ddf61651226ea%40thread.tacv2/1607239221851?context=%7b%22Tid%22%3a%22be5109ea-c534-473c-af60-2054e070a0ed%22%2c%22Oid%22%3a%2227bcf7a3-f6f6-495d-b151-aa7c00445f43%22%7d", "Materials"}, //Materials class, monday
        {14, 55, 1, "https://teams.microsoft.com/l/channel/19%3a5c513859ecd248e5adc7cea1a340c951%40thread.tacv2/General?groupId=8886f005-dd3f-471a-9f21-cb0917281223&tenantId=be5109ea-c534-473c-af60-2054e070a0ed", "Electromagnetics_Lab"},                                   //Electromagnetics practice (lab)
        {8, 55, 2, "https://meet.google.com/zic-wtjg-maw?pli=1&authuser=1", "Electromagnetics_Engineering"},                                                                                                                                                                    //Electromagnetics, Tuesday
        {9, 55, 2, "https://teams.microsoft.com/l/channel/19%3a3ce9fe07ff004a9683ef056bc016551e%40thread.tacv2/General?groupId=905dfe47-e342-4fb0-8cd5-d7f98addfc2b&tenantId=be5109ea-c534-473c-af60-2054e070a0ed", "Programming_and_Problem_Solving"},                         //Programming Team link
        {10, 55, 2, "https://meet.google.com/lookup/hcstbcvhfm", "Electric_Circuits"},                                                                                                                                                                                          //Electric_Circuits batch-1 link ,Edit it if you are batch-2
        {11, 55, 2, "https://teams.microsoft.com/l/meetup-join/19%3ad7c001250cf44a56a26ddf61651226ea%40thread.tacv2/1607239355272?context=%7b%22Tid%22%3a%22be5109ea-c534-473c-af60-2054e070a0ed%22%2c%22Oid%22%3a%2227bcf7a3-f6f6-495d-b151-aa7c00445f43%22%7d", "Materials"}, //Materials Tuesday
        {14, 55, 2, "https://meet.google.com/qbm-bxsc-dvg?pli=1&authuser=1", "Programming_Practice"},                                                                                                                                                                           //Programming practice
        {9, 55, 3, "https://meet.google.com/zic-wtjg-maw?pli=1&authuser=1", "Electromagnetics_Engineering"},
        {13, 55, 3, "https://meet.google.com/osi-mxea-jpc?pli=1&authuser=1", "Calculus"},                                                                                                                                                                                      //Calculus ,Wednesday
        {14, 55, 3, "https://teams.microsoft.com/l/channel/19%3a4d6698b0643c44718a6799735a228dbd%40thread.tacv2/General?groupId=8d9df39f-d753-4bcf-9394-693ccec2c426&tenantId=be5109ea-c534-473c-af60-2054e070a0ed", "Foundation_for_engineering_and_product_design"},         //Engineering and Product design
        {8, 55, 4, "https://meet.google.com/lookup/hcstbcvhfm", "Electric_Circuits"},                                                                                                                                                                                          //Electric_Circuits batch-1 link ,Edit it if you are batch-2
        {9, 55, 4, "https://teams.microsoft.com/l/meetup-join/19%3ad7c001250cf44a56a26ddf61651226ea%40thread.tacv2/1607239410210?context=%7b%22Tid%22%3a%22be5109ea-c534-473c-af60-2054e070a0ed%22%2c%22Oid%22%3a%2227bcf7a3-f6f6-495d-b151-aa7c00445f43%22%7d", "Materials"}, //Materials Thursday
        {13, 55, 4, "https://meet.google.com/osi-mxea-jpc?pli=1&authuser=1", "Calculus"},                                                                                                                                                                                      //Calculus ,Thrusday
        {9, 55, 5, "https://meet.google.com/juj-fhmq-yrm?pli=1&authuser=1", "Calculus"},                                                                                                                                                                                       //Calculus,Friday
        {10, 55, 5, "https://meet.google.com/zic-wtjg-maw?pli=1&authuser=1", "Electromagnetics_Engineering"},                                                                                                                                                                  //Electromagnetics ,Friday
        {11, 55, 5, "https://meet.google.com/lookup/hcstbcvhfm", "Electric_Circuits"},                                                                                                                                                                                         //Electric_Circuits batch-1 link ,Edit it if you are batch-2
        {13, 55, 5, "https://teams.microsoft.com/l/channel/19%3a3ce9fe07ff004a9683ef056bc016551e%40thread.tacv2/General?groupId=905dfe47-e342-4fb0-8cd5-d7f98addfc2b&tenantId=be5109ea-c534-473c-af60-2054e070a0ed", "Progamming_and_Problem_Solving"}};                       //Programming team link
    int day1 = argv[3][0] - '0';
    int hour1 = (strlen(argv[1]) == 1) ? (argv[1][0] - '0') : ((argv[1][0] - '0') * 10) + (argv[1][1] - '0');
    int minute1 = ((argv[2][0] - '0') * 10) + (argv[2][1] - '0');
    //a[i].search(hour1, minute1, day1);
    int i = 0;
    for (i; i < 21; ++i)
    {

        if (isFound)
        {
            break;
        }   
        else
            a[i].search(hour1, minute1, day1);
        if (!nextisFound)
        {
            break;
        }
    }
    if (!isFound)
        cout << "noc";
    if (isFound)
    {
        a[i-1].getInfo();
    }
    else
        a[i%21].getInfo();
}