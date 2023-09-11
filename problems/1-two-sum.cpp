#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> hash_complement;
        
        for(int i=0;i<nums.size(); i++){

            int complement =  target - nums[i];

            if(hash_complement.contains(complement)){

                return {hash_complement[complement],i};

            }

            hash_complement[nums[i]] = i;

        }

        return {};
    
    }
};