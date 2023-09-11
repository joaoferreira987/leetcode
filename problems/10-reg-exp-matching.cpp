
#include <string>

using namespace std;

class Solution {
public:

    bool solve(string s, string p, int s_index, int p_index){
        
        if(p_index <= -1 && s_index <= -1) return true;
        
        if(s_index==-1  && p[p_index] == '*' ) return solve(s,p, s_index, p_index-2);
        
        if(s_index == -1 || p_index == -1) return false;
        
        if(s[s_index] == p[p_index]) return solve(s,p,s_index-1,p_index-1);

        if(p[p_index] == '.') return solve(s,p,s_index-1,p_index-1);

        if(p[p_index] == '*'){
            
            if(s[s_index] == p[p_index-1] || p[p_index-1] == '.')
             {
             return solve(s,p,s_index-1,p_index) || solve(s,p,s_index,p_index-2);
             }
            return solve(s,p,s_index,p_index-2);
        
        }

        return false;

        


    }

    bool isMatch(string s, string p) {

        return solve(s,p,s.size()-1,p.size()-1);

    }
}; 