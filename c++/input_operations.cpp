#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::string;
int no_of_variables = 0;
int no_of_inputs = 0;
//int getdataMenu();
void csvAnalyse(FILE *);
void addition(float *, float *, float *);
void getData(float *, FILE *);
void printresult(float *);
int printMenu();
void subraction(float *, float *, float *);
void multiplication(float *, float *, float *);
void division(float *, float *, float *);
void average(float *, float *, float *);
void minimum(float *, float *, float *);
void maximum(float *, float *, float *);
void sin(float *, float *);
void print(int *arr, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            printf("%d ", *((arr + i * n) + j));
}
int main()
{

    /*switch (getdataMenu())
    {
        int a;
    case 1:
    {
        char *csv;
        printf("Enter the csv file name(with extension): ");
        scanf("%s", csv);
        FILE *inputdata = fopen(csv, "r");
        csvAnalyse(inputdata);
        cout<<no_of_inputs<<"||"<<no_of_variables;
        fclose(inputdata);
    };
    break;
    case 2:
    {
    };
    break;
    case 3:
    {
    };
    break;
    }*/

    char *csv;
    printf("Enter the csv file name(with extension): ");
    scanf("%s", csv);
    FILE *inputdata = fopen(csv, "r");
    csvAnalyse(inputdata);
    //cout << no_of_inputs << "||" << no_of_variables;
    fclose(inputdata);
    //getdataMenu();
    FILE *inputdata1 = fopen(csv, "r");
    
    float data[no_of_inputs][no_of_variables];
    return 0;
    getData((float *)data, inputdata1);
    
    int m = no_of_inputs;
    int n = no_of_variables;
    print((int *)data, m, n);
    return 0;
}
/*int getdataMenu()
{
    int option;
    printf("Which format you want to enter?\n");
    printf("1.CSV\n");
    printf("2.Text(single variable)\n");
    printf("3.From input console\n");
    printf("4.Will be developed soon\n");

    do
    {
        printf("Your option(1-3)....");
        scanf("%d", &option);
    }

    while (option != 1 && option != 2 && option != 3);
    return option;
}*/
void csvAnalyse(FILE *inputdata)
{
    char s[100];
    while (fscanf(inputdata, "%s", s) == 1)
    {
        if (no_of_inputs == 0)
        {
            ++no_of_variables;
            for (int i = 0; i < 100 && s[i] != '\0'; ++i)
            {
                if (s[i] == ',')
                {
                    ++no_of_variables;
                }
            }
        }
        ++no_of_inputs;
    }
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
void addition(float *data1, float *data2, float *result)
{
    for (int i = 0; i < no_of_inputs; ++i)
    {
        result[i] = data1[i] + data2[i];
    }
}

void printresult(float *result)
{
    for (int i = 0; i < no_of_inputs; ++i)
    {
        printf("%f\n", result[i]);
    }
}