#include <iostream>
#include <vector>
#include <algorithm>
#include <unistd.h>
using namespace std;
//Brute force approach to be used for stress test
long long MaxPairwiseProductAlt(const vector<long long>& numbers)
{
    long long max_product = 0;
    int n = numbers.size();
    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                numbers[first] * numbers[second]);
        }
    }
    return max_product;
}
//Efficient approach
long long MaxPairwiseProduct(const vector<long long>& numbers)
{//Find the index where the largest 2 numbers in the array occurs.
    int l1 , l2;
    long long largest = -1;
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] > largest){largest = numbers[i]; l1 = i;}
    }
    largest = -1;
    for (int i = 0; i < numbers.size();i++)
    {
        if (i == l1){continue;}
        if (numbers[i] > largest){largest = numbers[i]; l2 = i;}
    }

    return (numbers[l1] * numbers[l2]);
}
//Stress Test Implementation
bool informalTests(int n)
{
    cout << "Stress test implementation commencing in 5 seconds..." <<endl;
    sleep(5);
    int count = 0;
    while (count < n+1)
    {
        int n = rand()%99 +2; // Array size of max 100
        cout << "-------Test case #" << ++count << "------------" << endl;
        vector<long long> test;
        //generate random integers for this test
        for (int i = 0; i < n; i++)
        {
            test.push_back(rand()% 50000); //Integers from 0 to 9
        }
        //Print out the array
        for (int i = 0; i < n; i++)
        {
            cout << test[i] << " ";
        }
        cout << endl;
        long long res1 = MaxPairwiseProductAlt(test);
        long long res2 = MaxPairwiseProduct(test);
        if (res1 != res2)
        {
            cout << "Wrong Answer: " << res1 << " | " << res2;
            return false;
        }
        else{
            cout <<"OK" << endl;
        }
    }//endwhile
    return true;
}//end func
//Driver code
int main()
{
    /*
    bool test = informalTests(400000);
    if (test == false)
    {
        cout << "\n" << "Program is still buggy" << endl; return (-1);
    }
    else
    {
        int debug; cout <<"Program paused. Enter any integer to continue: " <<endl; cin >> debug;
    }
     */
    int n;
    //Manually enter vector size
    cin >> n;
    //Create vector numbers and initialise all vector elements to 0
    vector<long long> numbers(n, 0);
    //Manual Input
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
