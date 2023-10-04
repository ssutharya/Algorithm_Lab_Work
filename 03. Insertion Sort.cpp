// insertion sort

#include <iostream>
using namespace std;

void insertion_sort(int arr[], int n){
	int i, j ,key;
	
	for ( i = 0; i < n; i++){
		key = arr[i];
		j = i - 1;
		
		while (j >= 0 && arr[j] > key){
			arr [j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

int main(){
	cout << "Enter number of elements in the array: ";
	int n;
	cin >> n;
	
	int arr[n];
	
	cout << "Enter " << n << " elements: ";
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	insertion_sort(arr,n);
	
	cout << "The sorted array is: ";
	for ( int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
}

/* INPUT - OUTPUT: 

Enter number of elements in the array: 5
Enter 5 elements: 6 3 2 5 1
The sorted array is: 1 2 3 5 6

*/
