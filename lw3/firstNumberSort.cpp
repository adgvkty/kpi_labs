#include <iostream>

using namespace std;

int findFirstDigit(int integer)
{
    bool flag = true;
    if (integer < 10)
    {
        return integer;
    }
    while (flag) {
        integer = integer / 10;
        if (integer/10 == 0)
        {
            return integer;
        }
    } 
    
    return -1;
}

void firstDigitSort(int array[], int size)
{
    for (int step = 0; step < size-1; ++step)
    {   
        for (int i = step+1; i < size; ++i)
        {
            int numberOne = findFirstDigit(array[i]);
            int numberTwo = findFirstDigit(array[step]);
            if (numberOne < numberTwo)
            {   
                int temp = array[i];
                array[i] = array[step];
                array[step] = temp;
            }
            else if (numberOne == numberTwo) 
            {
                if (array[i] < array[step])
                {
                    int temp = array[i];
                    array[i] = array[step];
                    array[step] = temp;
                }
            }
        }
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 

void fisherYatesShuffle(int array[], int size)
{
    for (int i = size-1; i != 1; i--)
    {
        int j = rand() % 200;
        swap(&array[i], &array[j]);
    }
}

int main()
{
    // инициализируем массив
    int array [200] = {};
    
    // заполняем массив последовательными числами
    for (int i = 0; i < 200; i++)
    {
        array[i] = i + 1;
    }
    
    // находим размер массива
    int n = sizeof(array)/sizeof(array[0]);
    
    fisherYatesShuffle(array, n);
    firstDigitSort(array, n);
    printArray(array, n);
    
}