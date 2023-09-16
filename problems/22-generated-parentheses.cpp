class Solution {
public:

    void solve(string curr, int left, int right, vector<string> &answer){

        if(left == 0 && right == 0){
            answer.push_back(curr);
            return;
        }

        if(left == right){
            solve(curr+"(", left-1, right, answer);
            return;
        }

        if(left > 0){
            solve(curr+"(",left-1,right,answer);
        }
        if(right > 0){
            solve(curr+")", left,right-1,answer);
        }
        
        
        

        

    }

    vector<string> generateParenthesis(int n) {
       vector<string> answer;
       solve("",n,n,answer);
      

        return answer;
        

    }
};