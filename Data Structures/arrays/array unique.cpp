#include <iostream>
using namespace std;

void arrayUnique (int arr[], int size) {

    int count = 0;

    for (int i = 0; i < size; i++) {

        for (int j = 0; j < size; j++) {

            if (arr[i] == arr[j]) {

                count++;

            }

        }

        if (count == 1) {
            cout << arr[i] << " ";
        }

        count = 0;
    }


}


int* arrayIntersect(int arr1[],int arr2[],int size1, int size2) {


    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                cout << arr1[i] << " ";

            }
        }
    }

}

int main() {

    int arr1[8] = {1, 2, 3, 2, 5, 6, 7, 5};

    int arr2[9] = {0, 7, 4, 4, 5, 6, 7,7};

    arrayUnique(arr1, 8);
    cout << endl;
    arrayIntersect(arr1, arr2, 8, 8);
    cout << endl;
    arrayUnique(arr2,9);
    cout << endl;

}
