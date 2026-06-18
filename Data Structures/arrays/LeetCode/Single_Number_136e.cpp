#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {

    int initial = 0;
    int final = nums.size() - 1;
    while (nums.size() > 1)
    {

        int first = nums[initial];
        int last = nums[final];

        if (not(first ^ last)) {
            initial++;
            final--;
        }
        else {
            int counter1 = initial+1;
            int counter2 = final-1;
            int breaker = 0;
            while (true) {
                //trust case
                if ((first ^ nums[counter1]))
                {
                    counter1++;
                }
                else {
                    initial++;
                    breaker++;
                }
                if (last ^ nums[counter2]) {
                    counter2--;
                }
                else {
                    final--;
                    breaker++;
                }
                if (breaker > 0) {
                    break;
                }
            }
        }
    }

}


int main() {

    vector<int> nums = {1,2,2,6,5,4,1,4,3,7,6,3,5};


}
