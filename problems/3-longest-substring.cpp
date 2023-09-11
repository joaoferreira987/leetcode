
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.empty()){
            return 0;
        }

        unordered_set<char> charSet;
        int longest = 0;
        int left = 0;
        

        for(int right = 0 ; right < s.size(); right++)
            if(charSet.count(s[right]) == 0){
                charSet.insert(s[right]);
                longest = max(longest,right-left+1);

            }else{

                while(charSet.count(s[right])){ // while the element is repetead;
                    charSet.erase(s[left]);
                    left++;

                }

                charSet.insert(s[right]);
            }        
    
        return longest;
    }
};