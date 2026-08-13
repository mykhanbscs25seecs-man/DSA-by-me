#include <iostream>
#include <vector>
using namespace std;

int main() {

    int arr[] = {1,2,-3,4,- false   5,-6};
    vector<int> v;


    for (int i = 0; i < 6; i++) {
        int sum = arr[i];
        for (int j = i + 1; j < 6; j++) {
            sum += arr[j];

            v.push_back(sum);

        }
        sum = 0;
    }

    int max = v[0];
    for (int i = 0; i < 6; i++) {
        if (max < v[i]) max = v[i];

    }
    cout << max << endl;

}