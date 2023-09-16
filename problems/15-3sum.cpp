class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        

        sort(nums.begin(),nums.end());

        if(nums.size() < 3){
            return {};
        }
        if(nums[0] > 0){
            return {};
        }

        vector<vector<int>> result;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                break;
            }
            if(i > 0 && nums[i] == nums[i-1]){
                continue; //for repeated numbers;
            }
            int left = i+1;
            int right = nums.size()-1;

            int sum = 0;

            while(left < right){

                sum = nums[i] + nums[left] + nums[right];

                if(sum > 0){
                    right--; //need to look for a smaller number
                }else  if ( sum < 0){
                    left++; // need to look for a higher number
                }else{
                    result.push_back({nums[i],nums[left],nums[right]});
                    int last_low = nums[left];
                    int last_high = nums[right];

                    while(left < right && nums[left] == last_low){ 
                        left++;
                    }
                    while(left < right && nums[right] == last_high){
                        right--;
                    }

                }




            }



        }

        return result;

        

    }
};