class Solution {
public:
    vector<string> letterCombinations(string digits) {

        

        if(digits.empty()){
            return {}; 
        }
        int combinations = 1;

        for(char c : digits){
            if(c == '7' || c == '9'){
                combinations *=4;
            }else{
                combinations *=3;
            }
        }

        vector<vector<char>> phone(8,vector<char>(4,' '));
        
        phone[0] = {'a','b','c',' '};
        phone[1] = {'d','e','f',' '};
        phone[2] = {'g','h','i',' '};
        phone[3] = {'j','k','l',' '};
        phone[4] = {'m','n','o',' '};
        phone[5] = {'p','q','r','s'};
        phone[6] = {'t','u','v',' '};
        phone[7] = {'w','x','y','z'};
    

        vector<string> result(combinations,"");

        int every_n = combinations;

        for(int i = 0; i < digits.size(); i++){

            int curr_digit = digits[i] - '0';
            int digs = 3;
            if(curr_digit == 7 || curr_digit == 9){
                digs = 4;
            }

            every_n /=digs;

            

            for(int j = 0; j < combinations; j++){

                if(digits.size() == i + 1){
                    result[j] += phone[curr_digit - 2][j%digs];
                }else{

                    int index = j / every_n;

                    result[j] += phone[curr_digit - 2][index%digs];
               }

            }

            }
            return result;

        }

        

    
};