#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::string;
//global variables
int no_of_variables = 0;
int no_of_inputs = 0;
const int dummy_variable = 6;
int function_code;
void csvAnalyse(FILE *);
void getData(float *, FILE *);
int printMenu(int);
void addition(float[][dummy_variable], float *);
void printresult(float *);
void subraction(float[][dummy_variable], float *);
void multiplication(float[][dummy_variable], float *);
void division(float[][dummy_variable], float *);
void average(float[][dummy_variable], float *);
void minimum(float[][dummy_variable], float *);
void maximum(float[][dummy_variable], float *);
void exponential(float[][dummy_variable], float *);
void power_1_var(float[][dummy_variable], float *);
void power_2_var(float[][dummy_variable], float *);
void log_1_var(float[][dummy_variable], float *);
void negation(float[][dummy_variable], float *);
void square(float[][dummy_variable], float *);
void squareroot(float[][dummy_variable], float *);
void cuberoot(float[][dummy_variable], float *);
void inverse(float[][dummy_variable], float *);
void hypotenuse(float[][dummy_variable], float *);
void sin(float *, float *);
void print(float *arr, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            printf("%f ", *((arr + i * n) + j));
}
int main()
{
    char csv[15];
    printf("Enter the csv file name(with extension): ");
    cin >> csv;
    FILE *inputdata = fopen("input.txt", "r");
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

    switch (printMenu(no_of_variables))
    {
    case 500:
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
    fclose(inputdata);
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
        for (int j = 0; j < dummy_variable; ++j)
        {
            if (j < no_of_variables)
            {
                fscanf(inputdata, "%f%*c", ((data + i * dummy_variable) + j));
                printf("%f,", *((data + i * dummy_variable) + j));
            }
        }
    }
}

int printMenu(int a)
{
    switch (a)
    {
        int option;
    case 0:
        printf("Oops, No input values");
        break;
    case 1:
    {
        int local_function_code[9] = {500, 501, 502, 503, 504, 505, 519, 518, 506};
        printf("What do you want?\n");
        printf("1.Trignometric\n");                  //function code =>500,
        printf("2.Inverse\n");                       //function code =>501,
        printf("3.Square\n");                        //function code =>502,
        printf("4.Square root\n");                   //function code =>503,
        printf("5.Log(base n of x)\n");              //function code =>504,
        printf("6.Power(x power n or n power x)\n"); //function code =>505,
        printf("7.Exponential( e power x)\n");       //function code =>519,
        printf("8.Negation\n");                      //function  code=>518,
        printf("9.Custom\n");                        //function code =>506,
        printf("Your choice(1-9):");
        cin >> option;
        if(option<=9&&option>=1)
        function_code = local_function_code[option - 1];
        else 
        printMenu(a);
    };
    break;
    case 2:
    {
        int local_function_code[10] = {507, 508, 509, 510, 511, 512, 513, 514, 515, 516};
        printf("What do you want?\n");
        printf("1.Addition\n");                      //function code =>507,
        printf("2.Subraction\n");                    //function code =>508,
        printf("3.Multiplication\n");                //function code =>509,
        printf("4.Division\n");                      //function code =>510,
        printf("5.Average\n");                       //function code =>511,
        printf("6.Maximum\n");                       //function code =>512,
        printf("7.Minimum\n");                       //function code =>513,
        printf("8.Hypotenuse\n");                    //function code =>514,
        printf("9.Power(x power y or y power x)\n"); //function code =>515,
        printf("10.Custom");                         //function code =>516,
        printf("Your choice(1-10):");
        cin >> option;
        if(option<=10&&option>=1)
        function_code = local_function_code[option - 1];
        else 
        printMenu(a);
    };
    break;
    default:
    {
        int local_function_code[6] = {507, 509, 511, 512, 513, 517};
        printf("What do you want?\n");
        printf("1.Addition\n");       //function code =>507
        printf("2.Multiplication\n"); //function code =>509
        printf("3.Average\n");        //function code =>511
        printf("4.Maximum\n");        //function code =>512
        printf("5.Minimum\n");        //function code =>513
        printf("6.Custom\n");         //function code =>517
        printf("Your choice(1-6):");
        cin >> option;
        if(option<=6&&option>=1)
        function_code = local_function_code[option - 1];
        else 
        printMenu(a);
    };
    break;
    }
    return function_code;
}
void addition(float data[][dummy_variable], float *result)
{
    for (int i = 0; i < no_of_inputs; ++i)
    {
        result[i] = 0;
        for (int j = 0; j < no_of_variables; ++j)
        {
            result[i] += data[i][j];
        }
    }
}
void subraction(float data[][dummy_variable], float *result)
{
    int option;
    printf("\n\033[1m2.SUBTRACTION\033[0m\n");
    printf("If your input format is x,y\n");
    printf("Do you want 1)x-y or 2)y-x ?\n");
    printf("Your option(1 or 2):");
    cin >> option;
    if (option == 1)
    {
        for (int i = 0; i < no_of_inputs; ++i)
            result[i] = data[i][0] - data[i][1];
    }
    else if (option == 2)
    {
        for (int i = 0; i < no_of_inputs; ++i)
            result[i] = data[i][1] - data[i][0];
    }
    else
    {
        subraction(data, result);
    }
}
void multiplication(float data[][dummy_variable], float *result)
{
    for (int i = 0; i < no_of_inputs; ++i)
    {
        result[i] = data[i][0];
        for (int j = 1; j < no_of_variables; ++j)
        {
            result[i] *= data[i][j];
        }
    }
}
void division(float data[][dummy_variable], float *result)
{
    int option;
    printf("\n\033[1m4.DIVISION\033[0m\n");
    printf("If your input format is x,y\n");
    printf("Do you want 1)x-y or 2)y-x ?\n");
    printf("Your option(1 or 2):");
    cin >> option;
    if (option == 1)
    {
        for (int i = 0; i < no_of_inputs; ++i)
            result[i] = data[i][0] - data[i][1];
    }
    else if (option == 2)
    {
        for (int i = 0; i < no_of_inputs; ++i)
            result[i] = data[i][1] - data[i][0];
    }
    else
    {
        division(data, result);
    }
}
void average(float data[][dummy_variable], float *result)
{
    addition(data, result);
    for (int i = 0; i < no_of_inputs; ++i)
    {
        result[i] = result[i] / (float)no_of_variables;
    }
}
void minimum(float data[][dummy_variable], float *result)
{
    int minimum;
    for (int i = 0; i < no_of_inputs; ++i)
    {
        minimum = data[i][0];
        for (int j = 0; j < no_of_variables - 1; ++j)
        {
            if (data[i][j] > data[i][j + 1])
            {
                minimum = data[i][j + 1];
            }
        }
        result[i] = minimum;
    }
}
void maximum(float data[][dummy_variable], float *result)
{
    int maximum;
    for (int i = 0; i < no_of_inputs; ++i)
    {
        maximum = data[i][0];
        for (int j = 0; j < no_of_variables - 1; ++j)
        {
            if (data[i][j] < data[i][j + 1])
            {
                maximum = data[i][j + 1];
            }
        }
        result[i] = maximum;
    }
}
void exponential(float data[][dummy_variable], float *result)
{
    for (int i = 0; i < no_of_inputs; ++i)
    {
        result[i] = exp(data[no_of_inputs][0]);
    }
}
void power_1_var(float data[][dummy_variable], float *result)
{
    int option, n;
    printf("\n\033[1m9.Power(x power n or n power x)\033[0m\n");
    printf("If your input variable is x\n");
    printf("Enter the value n=");
    cin >> n;
    printf("Do you want 1)x^n or 2)n^x ?\n");
    printf("Your option(1 or 2):");
    cin >> option;
    if (option == 1)
    {
        for (int i = 0; i < no_of_inputs; ++i)
            result[i] = pow(data[i][0], n);
    }
    else if (option == 2)
    {
        for (int i = 0; i < no_of_inputs; ++i)
            result[i] = pow(n, data[i][0]);
    }
    else
    {
        power_1_var(data, result);
    }
}
void power_2_var(float data[][dummy_variable], float *result)
{
    int option;
    printf("\n\033[1m9.Power(x power y or y power x)\033[0m\n");
    printf("If your input format is x,y\n");
    printf("Do you want 1)x^y or 2)y^x ?\n");
    printf("Your option(1 or 2):");
    cin >> option;
    if (option == 1)
    {
        for (int i = 0; i < no_of_inputs; ++i)
            result[i] = pow(data[i][0], data[i][1]);
    }
    else if (option == 2)
    {
        for (int i = 0; i < no_of_inputs; ++i)
            result[i] = pow(data[i][1], data[i][0]);
    }
    else
    {
        power_2_var(data, result);
    }
}
void log_1_var(float data[][dummy_variable], float *result)
{
    int option, n;
    printf("\n\033[1m5.LOG\033[0m\n");
    printf("If your input variable is x\n");
    printf("Do you want 1)log base e of x or 2)log base 10 of x 3)log base 2 of x ?\n");
    printf("Your option(1-3):");
    cin >> option;
    if (option == 1)
    {
        for (int i = 0; i < no_of_inputs; ++i)
            result[i] = log(data[i][0]);
    }
    else if (option == 2)
    {
        for (int i = 0; i < no_of_inputs; ++i)
            result[i] = log10(data[i][0]);
    }
    else if (option == 3)
    {
        for (int i = 0; i < no_of_inputs; ++i)
            result[i] = log2(data[i][0]);
    }
    else
    {
        log_1_var(data, result);
    }
}
void negation(float data[][dummy_variable], float *result)
{
    for (int i = 0; i < no_of_inputs; ++i)
    {
        result[i] = data[i][0] * (-1);
    }
}
void square(float data[][dummy_variable], float *result)
{
    for (int i = 0; i < no_of_inputs; ++i)
    {
        result[i] = data[i][0] * data[i][0];
    }
}
void squareroot(float data[][dummy_variable], float *result)
{
    for (int i = 0; i < no_of_inputs; ++i)
    {
        result[i] = sqrt(data[i][0]);
    }
}
void cuberoot(float data[][dummy_variable], float *result)
{
    for (int i = 0; i < no_of_inputs; ++i)
    {
        result[i] = cbrt(data[i][0]);
    }
}
void inverse(float data[][dummy_variable], float *result)
{
    for (int i = 0; i < no_of_inputs; ++i)
    {
        result[i] = (float)1 / data[i][0];
    }
}
void hypotenuse(float data[][dummy_variable], float *result)
{
    for (int i = 0; i < no_of_inputs; ++i)
    {
        result[i] = hypot(data[i][0], data[i][1]);
    }
}
void printresult(float *result)
{
    for (int i = 0; i < no_of_inputs; ++i)
    {
        printf("%f\n", result[i]);
    }
}