// 0 - 1 Knapsack Problem

#include <iostream>
using namespace std;

int knapsack(int cap, int w[], int val[], int n){
	if (n == 0 || cap == 0){
		return 0;
	}
	
	if (w[n-1] > cap){
		return knapsack(cap, w, val, n-1);
	}
	
	else{
		return max(val[n-1] + knapsack(cap - w[n-1], w, val, n-1), knapsack(cap, w, val, n-1));
	}
}

int main(){
	int n;
	cout << "Enter the number of items: ";
	cin >> n;
	
	cout << "Enter the maximum capacity: ";
	int cap;
	cin >> cap;
	
	int w[n], val[n];
	
	cout << "Enter the weight and its corresponding value:\n";
	for (int i = 0; i < n; i++){
		cout << "Weight " << i+1 << ": ";
		cin >> w[i];
		cout << "Value " << i+1 << ": ";
		cin >> val[i];
	}
	
	int k = knapsack(cap, w, val, n);
	
	cout << "The maximum value is: " << k << endl;
}
