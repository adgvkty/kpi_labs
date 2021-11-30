#include <iostream>
#include <string>
#include <ctime>
// #include <stack>

using namespace std;

struct documentEditEvent
{
    string text;
    int strNum;
};

int main()
{

    // srand(time(0));

    return 0;
}

/*
documentEditEvent newEventEditDocument() {
    documentEditEvent newEvent;

    char randText[256] = "qwertyuiopasdfghjklzxcvbnm";

    newEvent.strNumber = rand() % 100;
    
    int count = rand() % 10 + 5;
    while (--count >= 0)
    {
        newEvent.text += randText[rand() % 25];
    }

    return newEvent;
}
*/