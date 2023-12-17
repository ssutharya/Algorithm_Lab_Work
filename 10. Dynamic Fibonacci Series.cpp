// fibonacci series
#include <iostream>
using namespace std;

void Fibonacci(int fib[],int N)
{
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= N; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    cout<<"THE FIBONACCI SERIES : ";
    for(int i=0;i<=N;i++){
        cout<<fib[i];
        if(i<N){
            cout<<", ";
        }
    }
    cout<<endl;
}

int main()
{
    int n;
    cout << "Enter n to calculate nth fibonacci term: ";
    cin >> n;
    int fib[n + 1];
    Fibonacci(fib,n);
    return 0;
}
