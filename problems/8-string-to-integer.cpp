#include <limits.h>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        
        //step 1
        for(int i=0; i < s.size(); i++){

            if(!isspace(s[i])){
                s = s.substr(i,s.size()-i);
                break;
            }

            

        }

       

        //step 2
        int negative = false;

        if(s[0] == '-') {
            negative = true; s.erase(s.begin());
        }else if(s[0] == '+'){
            s.erase(s.begin());
        } 

       

       // if(s.size() == 0) return 0;
        

        //step 3

        for(int i = 0; i < s.size(); i++){

            if(!isdigit(s[i])){
                s = s.substr(0,i);
                break;
            }

        }

        
        
        


        //step 4 - remove zeros
        while(s.size()){

            if(s[0] == '0'){
                s.erase(s.begin());
            }else{
                break;
            }

        }
        //step 4 - convert and step 5 check for bounds
        
        int result = 0;

        cout << s << endl;
        
        for(int i = 0; i < s.size(); i++){
            
            int increment = s[i] - '0';

            
            
            if(!negative && (INT_MAX/10 < result || INT_MAX - increment < result * 10) ){
                result = INT_MAX;
                return result;
            }
            if(negative && (INT_MAX/10 < result ||(increment != 0 && INT_MAX - increment + 1 <= result * 10 ))){
                result = INT_MIN;
                return result;
            }
            
            result = result*10;
            result += increment;
            

            


        }

        if(negative){
            return result*-1;
        }

        return result;

        

    }
};