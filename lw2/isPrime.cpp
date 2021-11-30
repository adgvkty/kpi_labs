#include <iostream>
#include <math.h>
#include <ctime>

using namespace std;

// isPrime - определяет простое ли число методом подбора
bool isPrime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n%i == 0)
        {
            return false;
        }
    }
    return true;
}

// sieve - методом Эратосфера определяет количество простых чисел в массиве
int sieve(int a[], int n)
{
    int result;
    for (int p = 2; p < n + 1; p++)
    {
        if (a[p] != 0)
        {
            result++;
            for (int j = p*p; j < n + 1; j += p)
            {
                a[j] = 0;
            }
        }
    }
    return result;
}

// linear - определяет количество простых чисел в массиве
// методом линейного перебора делителей
int linear(int a[], int n)
{
    int result;
    for (int i = 2; i < n; i++)
    {
        if (isPrime(a[i]) == true)
        {
            result++;
        }
    }
    return result;
}

int main() 
{
    int n = 900;
    int aLinear [n];
    int aSieve [n];

    for (int i = 0; i < n; i++)
    {
        aLinear[i] = i + 100;
        aSieve[i] = i + 100;
    }

    int start;
    int end;

    start = clock();
    for (int i = 0; i < 1000; i++)
    {
        linear(aLinear, n);
    }
    end = clock();
    cout << "Linear Prime Search time: " << double(end - start) / CLOCKS_PER_SEC << endl;

    start = clock();
    for (int i = 0; i < 1000; i++)
    {
        sieve(aSieve, n);
    }
    end = clock();
    cout << "Sieve Prime Search time: " << double(end - start) / CLOCKS_PER_SEC << endl;
}