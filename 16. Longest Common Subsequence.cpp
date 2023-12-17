// Longest Common Subsequence

#include <iostream>
#include <string>
using namespace std;

void LCS(string x, string y){
	int m = x.length();
	int n = y.length();
	
	int F[m+1][n+1];
	
	for (int i = 0; i <= m; i++){
		for (int j = 0; j <= n; j++){
			F[i][j] = 0;
		}
	}
	
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++){
			if (x[i-1] == y[j-1]){
				F[i][j] = F[i-1][j-1] + 1;
			}
			else{
				F[i][j] = max(F[i-1][j], F[i][j-1]);
			}
		}
	}
	
	cout << "\nThe matrix is:\n";
	for (int i=0; i <=m; i++){
		for (int j=0; j<=n; j++){
			cout << F[i][j] << "\t";
		}
		cout << endl;
	}
	
	int i=m, j=n;
	string lcs = "";
	while (i>0 && j>0){
		if (x[i-1] == y[j-1]){
			lcs = x[i-1] + lcs;
			i--;
			j--;
		}
		else if (F[i-1][j] > F[i][j-1]){
			i--;
		}
		else{
			j--;
		}
	}
	
	cout << "\nThe longest common subsequence is: " << lcs << endl;
}

int main(){
	string x,y;
	cout << "Enter the first string: ";
	cin >> x;
	
	cout << "Enter the second string: ";
	cin >> y;
	
	LCS(x,y);
	return 0;
}
