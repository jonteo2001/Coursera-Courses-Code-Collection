#include <iostream>
using namespace std;
//Global variable COIN count
int COIN_COUNT1 = 0;
int COIN_COUNT2 = 0;

int get_change(int m) {
  //write your code here
    if (m >= 10)
    {
        
        COIN_COUNT1 = COIN_COUNT1 + m/10;
        get_change(m%10);
    }
    else if (m >= 5)
    {
        COIN_COUNT1 = COIN_COUNT1 + m/5;
        get_change(m%5);
    }
    else if (m > 0)
    {
        COIN_COUNT1 = COIN_COUNT1 + m;
    }
    return COIN_COUNT1;
}
/*
int get_change2(int m)
{
    if (m < 0) {return 0;}
    if (m >= 10)
    {
        COIN_COUNT2++;
        get_change2(m-10);
    }
    else if (m >= 5)
    {
        COIN_COUNT2++;
        get_change2(m-5);
    }
    else if (m > 0)
    {
        COIN_COUNT2++;
        get_change2(m-1);
    }
    return COIN_COUNT2;
}
void informalTests()
{
    while(true)
    {
        COIN_COUNT1 = COIN_COUNT2 = 0;
        int m = rand()%1000 + 1;
        int result1 = get_change(m);
        int result2 = get_change2(m);
        if (result1 == result2) {
            cout << " m = " << m << " - OK" << endl;
        }
        else
        {
            cout <<"Wrong Answer for m = " << m << endl;
            cout << "get_change(m) = " << result1 << " | get_change2(m) = " << result2 << endl;
            break;
        }
        
    }
}
 */
int main() {
    int m;
    //informalTests();
    std::cin >> m;
    std::cout << get_change(m) << '\n';
}
