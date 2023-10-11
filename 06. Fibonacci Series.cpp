// fibonacci series

#include <iostream>
using namespace std;

int fibonacci (int n){
	if (n <= 1){
		return n;
	}
	return (fibonacci(n - 1) + fibonacci(n - 2));
}

int main(){
	cout << "Enter the number to find the fibonacci series of: ";
	int n;
	cin >> n;
	
	cout << "The fibonacci series is: " << fibonacci(n);
	return 0;
}
