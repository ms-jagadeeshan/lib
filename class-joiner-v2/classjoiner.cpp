#include <iostream>
#include <string.h>
#include <ctime>
#include <list>
#include <iomanip>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>
#include <iterator>
#include <getopt.h>
using std::cin;
using std::cout;
using std::string;
int oopsid = 1;
int ooplabid = 1;
int daalabid = 1;
struct class_info
{
    int hour, day, length;
    int s_value;
    int e_value;
    string link;
    string classname;
};

class classes
{
private:
    bool view_flag;
    int next;
    int previous;
    bool join_flag;
    bool daa;
    int daa_value;
    bool dsd;
    bool la;
    int la_value;
    int dsd_value;
    bool help_flag;
    bool isfound;
    std::list<class_info> l1;

public:
    classes()
    {
        view_flag = false;
        next = 0;
        previous = 0;
        join_flag = false;
        daa = false;
        dsd = false;
        la = false;
        daa_value = 0;
        dsd_value = 0;
        la_value = 0;
        help_flag = false;
        isfound = false;
    }
    void add_class(int hour, int day, int length, string classname, string link)
    {
        class_info tmp;
        tmp.hour = hour;
        tmp.day = day;
        tmp.s_value = (day * 1440) + (hour * 60) - 10;
        tmp.e_value = tmp.s_value + (length * 60);
        tmp.classname = classname;
        tmp.length = length;
        tmp.link = link;
        l1.push_back(tmp);
    }
    void u_view()
    {
        view_flag = true;
    }
    void u_help()
    {
        help_flag = true;
    }
    void u_next(int num)
    {
        next = num;
    }
    void u_previous(int num)
    {
        previous = num;
    }
    void u_join()
    {
        join_flag = true;
    }
    void u_daa(int num)
    {
        daa = true;
        daa_value = num;
    }
    void u_dsd(int num)
    {
        dsd = true;
        dsd_value = num;
    }
    bool ret_view()
    {
        return view_flag;
    }
    bool ret_help()
    {
        return help_flag;
    }
    int ret_next()
    {
        return next;
    }
    int ret_previous()
    {
        return previous;
    }
    bool ret_join()
    {
        return join_flag;
    }
    int ret_daa()
    {
        return daa_value;
    }
    int ret_la()
    {
        return la_value;
    }
    int ret_dsd()
    {
        return dsd_value;
    }
    void join();
    void join_n(int);
    void join_daa();
    void join_dsd();
    void join_la();
    void view();
    void info();
    void info_n(int);
    int find();
    void help();
};
void classes::help()
{
    cout << "Usage: classjoiner [OPTION] \n";
    cout << "\n--daa[=1]                Joins daa class\n";
    cout << "    1  - opens first link\n";
    cout << "    2  - opens second link\n";
    cout << "    3  - opens youtube channel\n";
    cout << "--dsd[=1]                Joins dsd class\n";
    cout << "      1  - opens first link\n";
    cout << "      2  - opens second link\n";
    cout << "-n, --next[=integer]     Prints the info of next class\n";
    cout << "-j, --join               When used with next, joins the next class\n";
    cout << "-v, --view               Prints the entire timetable with info\n";
    cout << "-p, --previous[=integer] Prints the info of previous class\n";
    cout << "--help                   Print usage and this help message and exit.\n\n";
    cout << "Sample usage:\n";
    cout << "classjoiner               - If class is there, then opens it\n";
    cout << "classjoiner --view        - Prints the timetable with info\n";
    cout << "classjoiner --next        - Prints next class info\n";
    cout << "classjoiner --next=3      - Prints next to next to next class info \n";
    cout << "classjoiner -j --next     - Opens next class\n";
    cout << "classjoiner --daa=2       - Opens daa second link\n";
    cout << "classjoiner -jp           - Opens previous class\n";

}
void classes::info_n(int num)
{
    int n = (num % (int)l1.size());
    if (n == 0)
    {
        n = (int)l1.size();
    }
    std::list<class_info>::iterator it;
    int i = 1;
    string days[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    for (it = l1.begin(); it != l1.end(); ++it)
    {
        if (i == n)
        {
            cout << "CLASS INFO" << std::endl;
            cout << "Class name: " << it->classname << std::endl;
            printf("Timing    : %02d:00 - %02d:00    %s\n", it->hour, (it->hour + it->length), days[it->day].c_str());
            cout << "Class link: " << it->link << std::endl;
            break;
        }
        i++;
    }
}
void classes::info()
{
    if (next)
    {
        int n = find();
        if (isfound)
        {
            info_n(n + next);
        }
        else
        {
            info_n(n + next - 1);
        }
    }
    else if (previous)
    {
        int n = find();
        info_n(n + 1500 - previous);
    }
}
void classes::view()
{
    std::list<class_info>::iterator it;
    int i = 1;

    for (it = l1.begin(); it != l1.end(); ++it)
    {
        string i_str = std::to_string(i);
        string s_str = std::to_string(it->hour);
        string e_str = std::to_string(it->hour + it->length);
        string tmp_str = string("%2d) %s %02d.00-%02d.00   \e]8;;").append(it->link).append("\e\\").append(it->classname).append("\e]8;;\e\\");
        string days[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

        pid_t pid = fork();
        if (!pid)
        {
            execl("/usr/bin/printf", "printf", tmp_str.c_str(), i_str.c_str(), days[it->day].c_str(), s_str.c_str(), e_str.c_str(), (char *)0);
        }
        wait(NULL);
        cout << "\n";
        i++;
    }
}
void classes::join_n(int num)
{
    int n = (num % (int)l1.size());
    if (n == 0)
    {
        n = (int)l1.size();
    }
    std::list<class_info>::iterator it;
    int i = 1;
    for (it = l1.begin(); it != l1.end(); ++it)
    {
        if (i == n)
        {
            pid_t pid = fork();
            if (!pid)
            {
                execl("/usr/bin/xdg-open", "xdg-open", it->link.c_str(), (char *)0);
                exit(EXIT_SUCCESS);
            }
            else
            {
                cout << "Opening " << it->link << "  ...." << std::endl;
                cout << "CLASS INFO" << std::endl;
                cout << "Class name: " << it->classname << std::endl;
                printf("Timing    : %02d:00 - %02d:00\n", it->hour, (it->hour + it->length));
                execl("/usr/bin/sleep", "sleep", "10", (char *)0);
                break;
            }
        }
        i++;
    }
}
void classes::join_daa()
{
    string str;
    if (daa_value == 1)
    {
        str = "https://meet.google.com/fmv-yypx-ofe?authuser=1";
    }
    else if (daa_value == 2)
    {
        str = "https://meet.google.com/een-aerr-sbk?authuser=1";
    }
    else if (daa_value == 3)
    {
        str = "https://www.youtube.com/channel/UCGxgiYa5l4ZpFpU-nnarqXg/playlists";
    }
    cout << str;
    pid_t pid = fork();
    if (!pid)
    {
        execl("/usr/bin/xdg-open", "xdg-open", str.c_str(), (char *)0);
    }
    else
        execl("/usr/bin/sleep", "sleep", "10", (char *)0);
}

void classes::join_dsd()
{
    string str;
    if (dsd_value == 1)
    {
        str = "https://meet.google.com/lookup/bxi53rg2xz?authuser=1";
    }
    else if (dsd_value == 2)
    {
        str = "https://meet.google.com/lookup/bgdvql5cu6?authuser=1";
    }
    cout << str;
    pid_t pid = fork();
    if (!pid)
    {
        execl("/usr/bin/xdg-open", "xdg-open", str.c_str(), (char *)0);
    }
    else
        execl("/usr/bin/sleep", "sleep", "10", (char *)0);
}
void classes::join()
{
    if (((bool)next) != ((bool)previous))
    {
        if (next)
        {
            int n = find();
            if (isfound)
            {
                join_n(n + next);
            }
            else
            {
                join_n(n + next - 1);
            }
        }
        else if (previous)
        {
            int n = find();
            join_n(n + 1500 - previous);
        }
    }
    else
    {
        int n = find();
        if (isfound)
            join_n(n);
        else
        {
            cout << "Cool, you don't have any classes" << std::endl;
            execl("/usr/bin/sleep", "sleep", "10", (char *)0);
            // execl("/usr/bin/sleep", "sleep", "10", (char *)0);
        }
    }
}
int classes::find()
{
    time_t now = time(0);
    tm *loc_tm = localtime(&now);
    int value = ((loc_tm->tm_hour) * 60) + ((loc_tm->tm_wday) * 1440) + (loc_tm->tm_min);
    std::list<class_info>::iterator it;
    int i = 1;
    for (it = l1.begin(); it != l1.end(); ++it)
    {
        if (value < it->s_value)
        {
            isfound = false;
            return i;
        }
        else if (value < it->e_value && value > it->s_value)
        {
            isfound = true;
            return i;
        }
        i++;
    }
    return 1;
}

int main(int argc, char **argv)
{
    classes cse;

    cse.add_class(10, 1, 1, "Digital System Design", "https://meet.google.com/lookup/bxi53rg2xz?authuser=1");
    cse.add_class(11, 1, 1, "Linear Algebra", "https://meet.google.com/nfn-xiwj-vpg?authuser=1");

    if (daalabid == 1)
        cse.add_class(15, 1, 4, "DAA Practice", "https://meet.google.com/fmv-yypx-ofe?authuser=1");
    else
        cse.add_class(15, 1, 4, "DAA Practice", "https://meet.google.com/een-aerr-sbk?authuser=1");

    cse.add_class(9, 2, 1, "Digital System Design", "https://meet.google.com/lookup/bxi53rg2xz?authuser=1");
    cse.add_class(10, 2, 1, "Linear Algebra", "https://meet.google.com/nfn-xiwj-vpg?authuser=1");

    if (oopsid == 1)
        cse.add_class(14, 2, 1, "Object oriented programming", "https://meet.google.com/gqd-gbaf-ixq?authuser=1");
    else
        cse.add_class(14, 2, 1, "Object oriented programming", "https://meet.google.com/gqd-gbaf-ixq?authuser=1");

    cse.add_class(15, 2, 4, "DSD Practice", "https://meet.google.com/lookup/bxi53rg2xz?authuser=1");
    cse.add_class(9, 3, 1, "Linear Algebra Tutorial", "https://meet.google.com/zpx-xepy-dgi?authuser=1");

    if (oopsid == 1)
        cse.add_class(11, 3, 1, "Object oriented programming", "https://meet.google.com/gqd-gbaf-ixq?authuser=1");
    else
        cse.add_class(11, 3, 1, "Object oriented programming", "https://meet.google.com/gqd-gbaf-ixq?authuser=1");

    cse.add_class(14, 3, 1, "DAA-Discussion", "https://meet.google.com/fmv-yypx-ofe?authuser=1");
    cse.add_class(15, 3, 3, "System Thinking of Design", "https://teams.microsoft.com/l/channel/19%3aWVZAU6AP1oGOgqofN8hfjJXHY8G551cm1BePFf5MoR41%40thread.tacv2/General?groupId=9fc411af-bdbe-4f49-af6b-2d2909390728&tenantId=be5109ea-c534-473c-af60-2054e070a0ed");

    cse.add_class(10, 4, 1, "Digital System Design", "https://meet.google.com/lookup/bxi53rg2xz?authuser=1");

    if (oopsid == 1)
        cse.add_class(15, 4, 1, "Object oriented programming", "https://meet.google.com/gqd-gbaf-ixq?authuser=1");
    else
        cse.add_class(15, 4, 1, "Object oriented programming", "https://meet.google.com/gqd-gbaf-ixq?authuser=1");

    if (ooplabid == 1)
        cse.add_class(16, 4, 3, "Object oriented programming practice", "https://meet.google.com/esf-zvzw-swo?authuser=1");
    else
        cse.add_class(16, 4, 3, "Object oriented programming practice", "https://meet.google.com/ygo-ixix-gmr?authuser=1");

    cse.add_class(11, 5, 1, "Digital System Design", "https://meet.google.com/lookup/bxi53rg2xz?authuser=1");
    cse.add_class(14, 5, 1, "Linear Algebra Tutorial", "https://meet.google.com/wug-maeb-cfn?authuser=1");

    int c;
    static struct option long_options[] = {
        /*   NAME       ARGUMENT           FLAG  SHORTNAME */
        {"view", no_argument, NULL, 'v'},
        {"next", optional_argument, NULL, 'n'},
        {"previous", optional_argument, NULL, 'p'},
        {"join", no_argument, NULL, 'j'},
        {"daa", optional_argument, NULL, 0},
        {"dsd", optional_argument, NULL, 0},
        {"help", no_argument, NULL, 0},
        {NULL, 0, NULL, 0}};
    int option_index = 0;

    if (argc < 2)
    {
        cse.u_join();
        cse.join();
        return 0;
    }
    else
    {
        while ((c = getopt_long(argc, argv, "vn::p::jh", long_options, &option_index)) != -1)
        {
            switch (c)
            {
            case 0:
            {
                if (!strcmp(long_options[option_index].name, "daa"))
                {
                    if (optarg)
                    {
                        if ((atoi(optarg) < 4) && (atoi(optarg) > 0))
                        {
                            cse.u_daa(atoi(optarg));
                        }
                        else
                        {
                            cout << "class_joiner: --daa requires any one of these arguments\n--daa=1\t- opens first meet\n--daa=2\t- opens second meet\n--daa=3\t- opens youtube channel\n";
                            cout << "Try: 'class_joiner --help' for more information\n";
                        }
                    }
                    else
                    {
                        cse.u_daa(1);
                    }
                }
                else if (!strcmp(long_options[option_index].name, "help"))
                {
                    cse.u_help();
                }
                else if (!strcmp(long_options[option_index].name, "dsd"))
                {
                    if (optarg)
                    {
                        if ((atoi(optarg)) < 3 && (atoi(optarg) > 0))
                        {
                            cse.u_dsd(atoi(optarg));
                        }
                        else
                        {
                            cout << "class_joiner: --dsd requires any one of these arguments\n--dsd=1\t- opens first meet\n--dsd=2\t- opens second meet\n";
                            cout << "Try: 'class_joiner --help' for more information\n";
                        }
                    }
                    else
                    {
                        cse.u_dsd(1);
                    }
                }
                break;
            }
            case 'v':
                cse.u_view();
                break;
            case 'n':
                if (optarg)
                {
                    cse.u_next(atoi(optarg));
                }
                else
                {
                    cse.u_next(1);
                }
                break;
            case 'p':
                if (optarg)
                {
                    cse.u_previous(atoi(optarg));
                }
                else
                {
                    cse.u_previous(1);
                }
                break;
            case 'j':
                cse.u_join();
                break;
            case '?':
                fprintf(stderr, "Try: 'class_joiner --help' for more information\n");
                exit(EXIT_FAILURE);
                break;
            default:
                fprintf(stderr, "?? getopt returned character code 0%o ??\n", c);
            }
        }
    }
    if (cse.ret_help())
    {
        cse.help();
    }
    else if (cse.ret_view())
    {
        cse.view();
    }
    else if (cse.ret_join())
    {
        cse.join();
    }
    else if (cse.ret_daa())
    {
        cse.join_daa();
    }
    else if (cse.ret_dsd())
    {
        cse.join_dsd();
    }
    else if (cse.ret_next() || cse.ret_previous())
    {
        cse.info();
    }
}
