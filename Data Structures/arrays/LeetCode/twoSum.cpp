#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//the brute force approach
vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
                for (int j = i + 1; j < nums.size(); j++) {

                        if (nums[i] + nums[j] == target) {

                                result.push_back(i);
                                result.push_back(j);
                        }
                }
        }

        return result;
}

//optimal approach
vector<int> twooSum(vector<int>& nums, int target) {


        vector<int> result;
        unordered_map<int, int> mp;



        for (int j = 0; j < nums.size(); j++) {

                int comp = target - nums[j];
                if (mp.find(comp) != mp.end()) {

                        result.push_back(mp[comp]);
                        result.push_back(j);

                }
                else {
                        mp[nums[j]] = j;
                }

                }



        return result;


}
int main() {



}