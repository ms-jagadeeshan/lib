#include <iostream>
#include <cmath>
#include "mathfunc.h"
using std::cin;
using std::cout;
using std::string;
//global variables
int no_of_variables = 0;
int no_of_inputs = 0;
int function_code;
/*
void print(float *arr, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            printf("%f ", *((arr + i * n) + j));
} 
*/
int main()
{
    char csv[15];
    printf("Enter the input file name(with extension): ");
    cin >> csv;
    FILE *inputdata = fopen(csv, "r");
    if (inputdata == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    csvAnalyse(inputdata);
    //cout << no_of_inputs << "||" << no_of_variables;
    fclose(inputdata);
    inputdata = fopen(csv, "r");
    if (inputdata == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    float data[no_of_inputs][dummy_variable];
    float result[no_of_inputs];
    getData((float *)data, inputdata);
    fclose(inputdata);
    switch (printMenu(no_of_variables))
    {
    case 500:
        trignometric(data, result);
        break;
    case 501:
        inverse(data, result);
        break;
    case 502:
        square(data, result);
        break;
    case 503:
        squareroot(data, result);
        break;
    case 504:
        log_1_var(data, result);
        break;
    case 505:
        power_1_var(data, result);
        break;
    case 518:
        exponential(data, result);
        break;
    case 519:
        negation(data, result);
        break;
    case 520:
        polynomial(data, result);
        break;
    case 506:

        break;
    case 507:
        addition(data, result);
        break;
    case 508:
        subraction(data, result);
        break;
    case 509:
        multiplication(data, result);
        break;
    case 510:
        division(data, result);
        break;
    case 511:
        average(data, result);
        break;
    case 512:
        maximum(data, result);
        break;
    case 513:
        minimum(data, result);
        break;
    case 514:
        hypotenuse(data, result);
        break;
    case 515:
        power_2_var(data, result);
        break;
    case 516:
        break;
    case 517:
        break;
    }

    printresult(result);
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