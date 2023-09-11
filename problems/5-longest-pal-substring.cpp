#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    
    string longestPalindrome(string s) {
        
        int n = s.size();
        
        if(n == 1 || n == 0){
            return s;
        }

        vector<vector<bool>> dp(n,vector<bool>(n,false));

        for(int i = 0; i < n ; i++){
            dp[i][i] = true;
        } // every character is a palindrome of itself

        string ans = "";
        ans+= s[0]; // default answer;
    
        for(int i = n-1; i >=0; i--){
            for(int j = i+1; j < n;j++){
                if(s[i] == s[j]){
                    if(i+1 == j || dp[i+1][j-1] == true){ //if the substring is just i and j or inside i and j is palindrome;
                            dp[i][j] = true;
                            if(ans.size() < s.substr(i,j+1-i).size()){
                                ans = s.substr(i,j+1-i);
        }}}}}
        
        return ans;

    }
};