#include <iostream>
#include <cmath>

using namespace std;

int convertToFour(int n)
{   
    int b = 0, k = 1;
    while (n)
    {
        b += n % 4 * k;
        n /= 4;
        k *= 10;
    }
    return b;
}

int convertToTen(int n)
{   
    int result;
    for (int i = 0; n != 0; i++)
    {
        result += (n % 10) * pow(4, i);
        n /= 10;
    }
    return result;
}
 
int main()
{
    int n;
    
    for (int i = 0; i < 3; i++)
    {   
        n = rand() % 100;
        
        int result = convertToFour(n);
        cout << "Converting: " << n << "-->" << result << endl;
        cout << "Converting back: " << result << "-->" << convertToTen(result) << endl << endl;
    }
 
    return 0;
}