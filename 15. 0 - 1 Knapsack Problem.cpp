// 0 - 1 Knapsack Problem

#include <iostream>
using namespace std;

void knapsack(int cap, int w[], int val[], int n){
	int F[n+1][cap+1];
	
	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= cap; j++){
			F[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= cap; j++){
			if (w[i-1] <= j){
				F[i][j] = max(val[i-1] + F[i-1][j-w[i-1]], F[i-1][j]);
			}
			else{
				F[i][j] = F[i-1][j];
			}
		}
	}
	
	cout << "\nThe Matrix is:\n";
	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= cap; j++){
			cout << F[i][j] << "\t";
		}
		cout << endl;
	}
	
	int i = n, j = cap;
	cout << "Selected items:\n";
	while (i>0 && j>0){
		if (F[i][j] != F[i-1][j]){
			cout << "Item: " << i << " (Weight: " << w[i-1] << " & Value: " << val[i-1] << ")\n";
			j -= w[i-1];
		}
		i--;
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
	
	knapsack(cap, w, val, n);
}
