#include <algorithm>

class Solution {

public:
    int getDigit(char c){

        switch(c){
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;   
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500; 
            case 'M':
                return 1000;
            default:
                return 0;
    }
}

public:
    int romanToInt(string s) {
        
        int number = 0;

        bool skipped = false;
        
        for(int i = 0; i < s.size();i++ ){
            
            skipped = false;

            if(i== s.size()-1){

                if(!skipped){
                    number+= getDigit(s[s.size()-1]);
                }
                break;
            }

            

            string aux = s.substr(i,2);

            cout << aux << endl;

            if(aux == "IV"){   
                number+=4;
                skipped = true;
            }
            else if(aux =="IX"){
                number+=9;
                skipped = true;   
            }
            else if(aux =="XL"){
                number+=40;
                skipped = true;
            }
            else if(aux =="XC"){
                number+=90;
                skipped = true;
            }
            else if(aux =="CD"){
                number+=400;
                skipped = true;
            }
            else if(aux =="CM"){
                number+=900;
                skipped = true;
            }
            else{
                
                number+=getDigit(s[i]);
                skipped = false;
                
            }

            if(skipped){
                i++;   
            }

        }
        

        return number;

        }




};