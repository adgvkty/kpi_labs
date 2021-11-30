#include <iostream>

using namespace std;

void divide(int n)
{
    if (n == 2)
    {   
        cout << "True";
        return;
    }
    else if (n > 2)
    {
        if (n%2 != 0)
        {
            cout << "False";
            return;
        }
        divide(n/2);
    }else
    {
        cout << "False";
        return;
    }
}

int main()
{
    int n;

    cout << "Enter N: ";
    cin >> n;

    divide(n);
    
    return 0;
}   