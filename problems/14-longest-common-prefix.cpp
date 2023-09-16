class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string curr = strs[0];

        for(int i = 1; i < strs.size(); i++){

            string next = strs[i];

            curr = curr.substr(0,next.size());

            for(int j = 0; j < next.size() && j < curr.size(); j++){

                if(curr[j] !=  next[j]){
                    
                    curr = curr.substr(0,j);
                    break;
                }

            }


        }

        return curr;

    }
};