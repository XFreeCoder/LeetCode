#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int> nums, int target){

        vector<int> result;
        int second_number;

        for(int i=0; i<nums.size()-1; i++){
            for(int j=i+1; j<nums.size(); j++){
                if (target == nums[i]+nums[j]){
                    result.push_back(i);
                    result.push_back(j);
                }
            }
        }

        return result;
    }
};



int main(int argc, char const *argv[]){

    Solution s;

    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(4);

    int target = 6;

    vector<int> result = s.twoSum(nums, target);
    cout<<result[0]<<" "<<result[1];
	return 0;
}