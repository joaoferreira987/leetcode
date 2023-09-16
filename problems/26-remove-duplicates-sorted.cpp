#include <unordered_map>

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int k = nums.size();
        unordered_map<int,int> umap;

        for(auto it = nums.begin(); it != nums.end();){

            if(umap.contains(*it)){

                it = nums.erase(it);
                k--;

            }else{

                umap[*it] = 1;
                ++it;

            }


        }

        return k;

    }
};