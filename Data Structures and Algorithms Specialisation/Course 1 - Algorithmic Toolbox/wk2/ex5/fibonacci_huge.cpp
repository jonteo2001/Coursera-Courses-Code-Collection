#include <iostream>
#include <vector>
using namespace std;
//This program may still be buggy, for it fails on much larger values of n and m.
int fibonacci_fast(int n, int m) {//Modified from wk2ex1
    // write your code here
    if (n <= 1){return n;}
    int count = 2;
    long long *fibprev = new long long(1);
    long long *fibprev2 = new long long(0);
    long long *fib = new long long();
    while (count < n+1)
    {
        *fib = (*fibprev + *fibprev2)%m;
        if (count+1 < n+1)
        {
            *fibprev2 = *fibprev;
            *fibprev = *fib;
        }
        count++;
    }
    //std::cout << *fib << std::endl;
    return (*fib); //Just to make sure that the value is smaller than m.
}
long long fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return (current % m);
}
vector<long long> sequence(long long m)
{ //Run the naive fibonacci sequence until we obtain a sequence.
    vector<long long> fib_sequence;
    fib_sequence.push_back(0); // index 0 - 0th term of seq
    fib_sequence.push_back(1); // index 1 - 1st term of seq
    int count = 2; // now set at 2nd term of seq
    bool EOS = false;
    while (!EOS)
    {
        long long temp = fibonacci_fast(count, m);
        if (temp == 0)
        {
            //If the subsequent digit is 1, it is a start of a new period. The 0 prior to it is not inserted.
            if (fibonacci_fast(count+1, m) == 1){EOS = true; break;}
            else
            {//Insert the 0 as per normal, since the sequence has yet to end.
                fib_sequence.push_back(temp);
            }
        }
        else
        {//If the current value is non-zero, add it to the sequence, since the sequence has yet to end.
            fib_sequence.push_back(temp);
        }
        count++;
    }//endwhile
    /*for (int i = 0; i < fib_sequence.size(); i++)
    {
        cout << fib_sequence[i] << " ";
    }
    cout << endl;*/
    return fib_sequence;
}
long long fib_fast(long long n, long long m)
{
    vector<long long> fib_sequence = sequence(m);
    return (fib_sequence[n % fib_sequence.size()]);
}
bool informalTests(int N)
{
    int count = 0;
    while (count < N)
    {
        cout<< "Attempt #" << count++ << endl;
        int M = rand()%1000+1;
        int N = rand()%100000+1;
        if(fibonacci_huge_naive(N, M) != fib_fast(N,M))
        {
            cout << "Wrong answer when N = " << N
            << " and M = " << M << "\n"
            <<fibonacci_huge_naive(N, M) << " | " << fib_fast(N,M) << "\n"
            << "Program is still buggy." << endl;
            return false;
        }
        else
        {
            cout << "N = " << N << " M = " << M << " - OK" << endl;
        }
    }
    cout << "Informal Tests passed. Enter a value of n and m to continue:  " << endl;
    return true;
}

int main() {
    long long n, m;
    /*
    bool test = informalTests(20);
    if (test == false) {return -1;}
     */
    std::cin >> n >> m;
    std::cout << fib_fast(n, m) << '\n';
    return 0;
}
