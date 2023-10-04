// Selection sort

#include <iostream>
using namespace std;

void selection_sort ( int arr[], int n){
	int i, j, min;      //min is index of minimum value
	
	for (i = 0; i < n; i++){
		min = i;
		
		for (j = 0; j < n-1; j++){
			if (arr[j] > arr[min]){
				swap(arr[j],arr[i]);
			}
		}
		swap(arr[i],arr[min]);
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
	
	selection_sort(arr,n);
	
	cout << "The sorted array is: ";
	for ( int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
}
