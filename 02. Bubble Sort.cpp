//bubble sort - Algorithm class

#include <iostream>
using namespace std;

void bubble(int arr[], int n){
    for (int i = 0; i < n-1; i++){
        bool swapped = false;

        for (int j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){
                swap (arr[j], arr[j+1]);
                swapped = true;
            }
        }
        
        if (swapped == false)
            break;
    }
}

int main(){
    int n, i;
    cout << "Enter number of elements in the array: ";
    cin >> n;
    int arr[n];

    cout << "Enter the elements: ";

    for (i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "\nThe entered array is: ";
    for (i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    bubble(arr,n);

    cout << "\nThe sorted array is: ";
    for (i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}