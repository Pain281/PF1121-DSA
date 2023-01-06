#include <stdio.h>

void Exercise1(int n)
{
    if (n > 100)
        return;
    printf("%2d, ", n);
    n++;
    Exercise1(n);
}

void Exercise2(int n)
{
    int nextTerm;
    int prevNum = 0, nextNum = 1;
    printf("\n\nExercise 2: \n");
    printf("%d, %d, ", prevNum, nextNum);
    for (int i = 2; i < n; i++)
    {
        nextTerm = prevNum + nextNum;
        printf("%d, ", nextTerm);
        prevNum = nextNum;
        nextNum = nextTerm;
    }
}

// Exercise3
float usingLoop(int n, float d, float u)
{
    float result;
    for (int i = 0; i < n; i++)
    {
        result += u + (i * d);
    }
    return result;
}

float usingRecursive(int n, float d, float u, int count, float result)
{
    if(count == n) {
        return result;
    }

    u += d;
    result += u;
    count++;

    usingRecursive(n, d, u, count, result);
}

void Exercise3(int n, float d, float u)
{
    printf("\n\nExercise 3: \n");
    float result1 = usingLoop(n, d, u);
    float result2 = usingRecursive(n, d, u, 1, u);
    printf("Result = %.2f\n", result1);
    printf("Result (using recursive) = %.2f", result2);
}

int main()
{
    int n1 = 0, n2 = 15, n3 = 20; 
    float d = 1.5, u = 2.5;
    // Use a recursive algorithm to write a program to print numbers between 1 and 100.
    Exercise1(n1);

    // Use a program to display the Fibonacci sequence of n Fibonacci numbers (using Recursive algorithm)
    Exercise2(n2);

    // Write a program to calculate the sum of the first n terms of an arithmetic progression
    // Requirements:
    //  - Use function
    //  - Write 2 algorithms for calculating factorial using loop and recursion
    Exercise3(n3, d, u);
    return 0;
}