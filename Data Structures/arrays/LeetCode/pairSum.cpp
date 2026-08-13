//lets solve pair sum by brute force
#include  <iostream>
#include <vector>
using namespace std;

vector<vector<int>> pairS(const vector<int> &v, int target) {

    vector<vector<int>> result;
    vector<int> line;
    int count  = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] < target) {
            for (int j = i + 1; j < v.size(); j++) {

                int sum = v[i] + v[j];
                if (sum == target) {

                    line.push_back(i);
                    line.push_back(j);

                    result.push_back(line);
                    line.clear();
                }
        }

        }
    }

    return result;

}


int main() {

    vector<int> v = {1,2,3,4,5};

    vector <vector<int>> answer  = pairS(v,6);

    for (int i = 0; i < answer.size(); i++) {
        for (int j = 0; j < answer[i].size(); j++) {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }

}