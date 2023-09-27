/* linear search:
input : a sequence of 'n' numbres 'A = {a1, a2, a3, ... , an}' and a value 'v'
output : an index 'i' such that v = A[i] or the special value NIL if v doesnt appear in A. */
 
 #include <iostream>
 using namespace std;

int linear_search (int A[], int n, int v){

    for (int i = 0 ; i < n; i++){
        if (A[i] == v){
            return i;
        }
    }
    return -1;
}

int main(){
    cout << "Enter number of elements in the array: ";
    int n;
    cin >> n;
    cout << "Enter " << n << " elements of the array: ";
    int A[n], v;
    
    for (int i = 0; i < n; i++){
        cin >> A[i];
    }

    cout << "\nThe given array is: \nA = [";
    for (int i = 0; i < n ; i++){
        cout << A[i] << " ";
    }
    cout << "]\n\nEnter the value to find: ";
    cin >> v;

    int result = linear_search(A, n, v);

    if (result != -1){
        cout << "Element found at index: " << result;
    }
    else{
        cout << "Element not in array.";
    }
}