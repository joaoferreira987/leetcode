class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int count = nums.size();
        
        for(auto it=nums.begin(); it != nums.end();){

            if(*it == val){

                count--;
                it = nums.erase(it);
            
            }else{

                ++it;

            }


        }

        return count;

    }
};