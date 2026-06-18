#include <iostream>
using namespace std;

//used the two pointer approach in order to reverse the array.


void reverse(int arr[], int n, int start = 0,int end = 0) {


    if (start == 0) {
        end = n-1;
    }

    if (start >= end) {

        return;
    }



    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    reverse(arr, n,start + 1, end -1);

}




int main() {

    int arr[6] = {1,2,3,4,5,6};
    reverse(arr, 6);

    for (int i = 0; i < 6; i++) {
        cout << arr[i] << " ";
    }

}