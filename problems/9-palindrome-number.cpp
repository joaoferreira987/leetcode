#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x<0){
            return false;
        }

        string number = to_string(x);

        for(int i=0;i<number.size()/2;i++){

            if(number[i]!=number[number.size()-1-i]){
                return false;
            }


        }

        return true;


    }
};