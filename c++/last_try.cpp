#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::string;
int no_of_variables = 0;
int no_of_inputs = 0;
void getData(float *, FILE *);
int printMenu();
int main()
{

    string csv;
    printf("Enter the csv file name(with extension): ");
    cin>>csv;
    cout<<csv;
    printf("Number of inputs=");
    scanf("%d", &no_of_inputs);
    printf("Number of variables=");
    scanf("%d", &no_of_variables);
    return 0;
    FILE *inputdata = fopen("~/lib/c++/input.txt", "r");
    float data[no_of_inputs][no_of_inputs];
    return 0;
    getData((float *)data, inputdata);
}
void getData(float *data, FILE *inputdata)
{
    for (int i = 0; i < no_of_inputs; ++i)
    {
        for (int j = 0; j < no_of_variables; ++j)
        {
            fscanf(inputdata, "%f%*c", ((data + i * no_of_variables) + j));
        }
    }
}

int printmenu()
{
    printf("What do you want?\n");
    printf("1.Addition\n");
    printf("2.Subraction\n");
    printf("3.Multiplication\n");
    printf("4.Division\n");
    printf("5.Average\n");
    printf("6.Maximum\n");
    printf("7.Minimum\n");
    printf("8.Trignometric\n");
    printf("9.Square root\n");
    printf("10.Exponential\n");
    printf("11.Inverse\n");
    printf("Will be devoloped soon");
    return 1;
}