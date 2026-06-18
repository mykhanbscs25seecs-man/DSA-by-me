#include <algorithm>
#include <iostream>
using namespace std;

int search(int target, int arr[], int size);

int main() {

    //this programs implements the linear search algorithm
    const int size = 7; //constatn as arrays cant grow or shrink during runtime
    int arr[size] = {1, 2, 39, 2, 5, 6, 90};

    //user input
    int num;
    cout << "Enter the element to find the position: ";
    cin >> num;

    //function to find the index where the element is present.
    int index = search(num, arr, size);
    if (index != -1) {
        cout << "The element is located at the index: " << index << endl;
    }
    else {
        cout << "The element is not in the array" << endl;
    }


}

//the linear search algorithm implemented by the search function.
int search(int target, int arr[], int size) {

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {

            return i;
        }
    }
    return -1;

}
