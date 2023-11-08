// robot coin collection

#include <iostream>
using namespace std;

int coin[50][50];
int matrix[50][50];

int coin_collection(int m, int n){
	
	for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            coin[i][j] = 0;
        }
    }

    coin[0][0] = matrix[0][0];

    for (int j = 1; j < n; j++) {
        coin[0][j] = coin[0][j - 1] + matrix[0][j];
    }

    for (int i = 1; i < m; i++) {
        coin[i][0] = coin[i - 1][0] + matrix[i][0];
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            coin[i][j] = max(coin[i - 1][j], coin[i][j - 1]) + matrix[i][j];
        }
    }

    return coin[m - 1][n - 1];
}

int main(){
	int m,n;
	cout << "Enter number of rows: ";
	cin >> m;
	cout << "Enter number of columns: ";
	cin >> n;
	
	cout << "Enter the vlaues (0 or 1): ";
	for ( int i = 0; i < m; i++){
		for ( int j = 0; j< n; j++){
			cin >> matrix[i][j];
		}
	}
	
	int c = coin_collection(m,n);
	
	cout << "\n\n";
	
	for ( int i = 0; i < m; i++){
		for ( int j = 0; j< n; j++){
			cout << coin[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << "\nThe number of coins collected is: " << c;
	return 0;
}

/* INPUT - OUTPUT:

Enter number of rows: 5
Enter number of columns: 6
Enter the vlaues (0 or 1):
0 0 0 0 1 0
0 1 0 1 0 0
0 0 0 1 0 1
0 0 1 0 0 1
1 0 0 0 1 0


0 0 0 0 1 1
0 1 1 2 2 2
0 1 1 3 3 4
0 1 2 3 3 5
1 1 2 3 4 5

The number of coins collected is: 5

*/
