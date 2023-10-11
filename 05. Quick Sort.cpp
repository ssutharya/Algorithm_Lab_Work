// Quick sort

#include <iostream>
using namespace std;

int partition(int arr[], int low, int high){
	int pivot = arr[high];
	int i = (low - 1);
	
	for (int j = low; j <= high - 1; j++){
		if (arr[j] <= pivot){
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

void quick_sort (int arr[], int low, int high){
	if ( low < high){
		int part = partition(arr, low, high);
		quick_sort(arr, low, part - 1);
		quick_sort (arr, part + 1, high);
	}
}

int main(){
	cout << "Enter number of elements in the array: ";
	int n; 
	cin >> n;
	cout << "\nEnter the elements: ";
	int arr[n];
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	quick_sort(arr, 0, n);
	
	cout << "The sorted array is: ";
	for (int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	return 0;
}
