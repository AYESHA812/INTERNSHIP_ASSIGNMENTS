#include <stdio.h>

int a, b, c;
int result;

void add();
void sub();
void mult();
void div();

void add()
{
    result = a + b;
    printf("The result is: %d", result);
}

void sub()
{
    result = a - b;
    printf("The result is: %d", result);
}

void mult()
{
    result = a * b;
    printf("The result is: %d", result);
}

void div()
{
    result = a / b;
    printf("The result is: %d", result);
}

int main()
{
    printf("Enter first number\n");
    scanf("%d", &a);
    
    printf("Enter second number\n");
    scanf("%d", &b);
    
    printf("Which operation needs to be performed?\n");
    printf("For add press 1, for sub press 2, for mult press 3, for div press 4:\n");
    scanf("%d", &c);

    if (c == 1)
    {
        add();
    }
    else if (c == 2)
    {
        sub();
    }
    else if (c == 3)
    {
        mult();
    }
    else if (c == 4)
    {
        div();
    }
    else
    {
        printf("Invalid Input");
    }

    return 0;
}
