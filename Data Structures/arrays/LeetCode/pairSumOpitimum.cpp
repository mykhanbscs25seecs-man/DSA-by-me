//now lets look into the optimum approach of doing pairSum
#include <iostream>
#include <vector>
using namespace std;

vector<int> parSum(const vector<int> &nums, int target) {

    //two pointer approach
    vector<int> result;
    int start = 0;
    int end = nums.size() - 1;
    for (int i = 0; i < nums.size(); i++) {

        if (nums[start] + nums[end] == target) {

            result.push_back(start);
            result.push_back(end);
            return result;

        }

        if (nums[start] + nums[end] > target) {
            end = end - 1;
        }

        if (nums[start] + nums[end] < target) {
            start = start + 1;
        }
    }
}


int main() {

    vector<int> nums = {1,2,3,4,5,6};
    vector<int> answer = parSum(nums, 8);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }

}
