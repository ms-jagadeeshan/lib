#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::string;
extern int no_of_variables;
extern int no_of_inputs;
extern const int dummy_variable = 8;
extern int function_code;
void csvAnalyse(FILE *inputdata)
{
    char s[200];
    while (fscanf(inputdata, "%s", s) == 1)
    {
        if (no_of_inputs == 0)
        {
            ++no_of_variables;
            for (int i = 0; i < 100 && s[i] != '\0'; ++i)
            {
                // printf("s[%d]%c\n",i,s[i]);
                if (s[i] == ',')
                {
                    //printf("\n");
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
                //printf("%f,", *((data + i * dummy_variable) + j));
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
        printf("Your given data have %d inputs\n", no_of_inputs);
        printf("And also it have %d variables\n\n", no_of_variables);
        int local_function_code[10] = {500, 501, 502, 503, 504, 505, 519, 518, 520, 506};
        printf("What do you want?\n");
        printf("1.Trignometric\n");                  //function code =>500,
        printf("2.Inverse\n");                       //function code =>501,
        printf("3.Square\n");                        //function code =>502,
        printf("4.Square root\n");                   //function code =>503,
        printf("5.Log(base n of x)\n");              //function code =>504,
        printf("6.Power(x power n or n power x)\n"); //function code =>505,
        printf("7.Exponential( e power x)\n");       //function code =>519,
        printf("8.Negation\n");                      //function  code=>518,
        printf("9.Polynomial");                      //function code =>520,
        printf("10.Custom\n");                       //function code =>506,
        printf("Your choice(1-9):");
        cin >> option;
        if (option <= 10 && option >= 1)
            function_code = local_function_code[option - 1];
        else
            printMenu(a);
    };
    break;
    case 2:
    {
        printf("Your given data have %d inputs\n", no_of_inputs);
        printf("And also it have %d variables\n\n", no_of_variables);
        int local_function_code[10] = {507, 508, 509, 510, 511, 512, 513, 514, 515, 516};
        printf("What do you want?\n");
        printf("1.Addition\n");                      //function code =>507,
        printf("2.Subraction\n");                    //function code =>508,
        printf("3.Multiplication\n");                //function code =>509,
        printf("4.Division\n");                      //function code =>510,
        printf("5.Average\n");                       //function code =>511,
        printf("6.Maximum\n");                       //function code =>512,
        printf("7.Minimum\n");                       //function code =>513,
        printf("8.Hypotenuse(sqrt(x^2 + y^2)\n");    //function code =>514,
        printf("9.Power(x power y or y power x)\n"); //function code =>515,
        printf("10.Custom");                         //function code =>516,
        printf("Your choice(1-10):");
        cin >> option;
        if (option <= 10 && option >= 1)
            function_code = local_function_code[option - 1];
        else
            printMenu(a);
    };
    break;
    default:
    {
        printf("Your given data have %d inputs\n", no_of_inputs);
        printf("And also it have %d variables\n\n", no_of_variables);
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
        if (option <= 6 && option >= 1)
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
            result[i] = data[i][0] - (float)data[i][1];
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
    float minimum;
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
    float maximum;
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
void polynomial(float data[][dummy_variable],float *result)
{
    int highest_deg;
    
    printf("\n\033[1m9.Polynomial\033[0m\n");
    printf("Enter the highest degree of polynomial\n");
    cin>>highest_deg;
    float coefficient[highest_deg];
    printf("Now enter the coefficients(a");
    
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

void trignometric(float data[][dummy_variable], float *result)
{
    char option;
    printf("\n\033[1m1.Trignometric\033[0m\n");
    printf("What function you want?\n");
    printf("a) sin(ϑ)\tg) arcsin()\n");
    printf("b) cos(ϑ)\th) arccos()\n");
    printf("c) tan(ϑ)\ti) arctan()\n");
    printf("d) cosec(ϑ)     j) arccosec()\n");
    printf("e) sec(ϑ)\tk) arcsec()\n");
    printf("f) cot(ϑ)\tl) arccot()\n");
    printf("\033[031;1mCaution: input value for arcsin,arccos should be [-1,1] and for arccosec, arcsec should not be (-1,1)\033[0m\n");
    printf("Your option(a-l): ");
    cin >> option;
    switch (option)
    {
    case 'a':
    {
        char option1;
        printf("\n\033[1ma) sin(ϑ)\033[0m\n");
        printf("Is ϑ given in degrees(d) or radians(r)?\n");
        printf("Your option(d or r): ");
        cin >> option1;
        for (int i = 0; i < no_of_inputs; ++i)
        {
            if (option1 == 'r')
                result[i] = sinf(data[i][0]);
            else if (option1 == 'd')
                result[i] = sinf(data[i][0] * M_PI / 180);
        }
    }
    break;
    case 'b':
    {
        char option1;
        printf("\n\033[1mb) cos(ϑ)\033[0m\n");
        printf("Is ϑ given in degrees(d) or radians(r)?\n");
        printf("Your option(d or r): ");
        cin >> option1;
        for (int i = 0; i < no_of_inputs; ++i)
        {
            if (option1 == 'r')
                result[i] = cosf(data[i][0]);
            else if (option1 == 'd')
                result[i] = cosf(data[i][0] * M_PI / 180);
        }
    }
    break;
    case 'c':
    {
        char option1;
        printf("\n\033[1mc) tan(ϑ)\033[0m\n");
        printf("Is ϑ given in degrees(d) or radians(r)?\n");
        printf("Your option(d or r): ");
        cin >> option1;
        for (int i = 0; i < no_of_inputs; ++i)
        {
            if (option1 == 'r')
                result[i] = tanf(data[i][0]);
            else if (option1 == 'd')
                result[i] = tanf(data[i][0] * M_PI / 180);
        }
    }
    break;
    case 'd':
    {
        char option1;
        printf("\n\033[1md) cosec(ϑ)\033[0m\n");
        printf("Is ϑ given in degrees(d) or radians(r)?\n");
        printf("Your option(d or r): ");
        cin >> option1;
        for (int i = 0; i < no_of_inputs; ++i)
        {
            if (option1 == 'r')
                result[i] = (float)1 / sinf(data[i][0]);
            else if (option1 == 'd')
                result[i] = (float)1 / sinf(data[i][0] * M_PI / 180);
        }
    }
    break;
    case 'e':
    {
        char option1;
        printf("\n\033[1me) sec(ϑ)\033[0m\n");
        printf("Is ϑ given in degrees(d) or radians(r)?\n");
        printf("Your option(d or r): ");
        cin >> option1;
        for (int i = 0; i < no_of_inputs; ++i)
        {
            if (option1 == 'r')
                result[i] = (float)1 / cosf(data[i][0]);
            else if (option1 == 'd')
                result[i] = (float)1 / cosf(data[i][0] * M_PI / 180);
        }
    }
    break;
    case 'f':
    {
        char option1;
        printf("\n\033[1mf) cot(ϑ)\033[0m\n");
        printf("Is ϑ given in degrees(d) or radians(r)?\n");
        printf("Your option(d or r): ");
        cin >> option1;
        for (int i = 0; i < no_of_inputs; ++i)
        {
            if (option1 == 'r')
                result[i] = (float)1 / tanf(data[i][0]);
            else if (option1 == 'd')
                result[i] = (float)1 / tanf(data[i][0] * M_PI / 180);
        }
    }
    break;
    case 'g':
    {

        for (int i = 0; i < no_of_inputs; ++i)
        {
            result[i] = asinf(data[i][0]);
        }
    }
    break;
    case 'h':
    {

        for (int i = 0; i < no_of_inputs; ++i)
        {
            result[i] = acosf(data[i][0]);
        }
    }
    break;
    case 'i':
    {

        for (int i = 0; i < no_of_inputs; ++i)
        {
            result[i] = atanf(data[i][0]);
        }
    }
    break;
    case 'j':
    {

        for (int i = 0; i < no_of_inputs; ++i)
        {
            result[i] = asinf((float)1 / data[i][0]);
        }
    }
    break;
    case 'k':
    {

        for (int i = 0; i < no_of_inputs; ++i)
        {
            result[i] = acosf((float)1 / data[i][0]);
        }
    }
    break;
    case 'l':
    {

        for (int i = 0; i < no_of_inputs; ++i)
        {
            result[i] = atanf((float)1 / data[i][0]);
        }
    }
    break;
    }
}
void printresult(float *result)
{
    int option;
    printf("\nWhat do you want?\n");
    printf("1.To be displayed on output console.\n");
    printf("2.Export as file(.txt).\n");
    printf("Your option(1 or 2): ");
    cin >> option;
    if (option == 1)
    {
        printf("\n\034[1mResult\033[0m\n");
        for (int i = 0; i < no_of_inputs; ++i)
        {
            printf("%f\n", result[i]);
        }
    }
    else if (option == 2)
    {
        char *output;
        printf("Enter output file name(with extension): ");
        cin >> output;
        FILE *output_data = fopen(output, "w");
        for (int i = 0; i < no_of_inputs; ++i)
        {
            fprintf(output_data, "%f\n", result[i]);
        }
    }
}
