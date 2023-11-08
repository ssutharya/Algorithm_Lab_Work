// minimum cost path

#include <iostream>
using namespace std;

int M[10][10];
int F[10][10];

int min (int a, int b, int c){
	if (a < b)
		return (a < c) ? a : c;
	else
		return (b < c) ? b : c;
}

int minimum (int m, int n){
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			F[i][j] = 0;
		}
	}
	
	F[0][0] = M[0][0];
	
	for (int j = 1; j < n; j++){
		F[0][j] = F[0][j-1] + M[0][j];
	}
	
	for (int i = 1; i < m; i++){
		F[i][0] = F[i-1][0] + M[i][0];
		
		for ( int j = 1; j < n; j++){
			F[i][j] = min(F[i-1][j], F[i][j-1],F[i-1][j-1]) + M[i][j];
		}
	}
	
	return F[m-1][n-1];
}

int main(){
	cout << "Enter the size of matrix (m and n): ";
	int m,n;
	cin >> m;
	cin >> n;
	
	cout << "Enter " << m*n << " elements: ";
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			cin >> M[i][j];
		}
	}
	
	int mini = minimum(m,n);
	
	cout << "The minimum cost path is: " << mini << endl;
	cout << "The matrix is: \n";
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			cout << F[i][j] << " ";
		}
		cout << endl;
	}
}
