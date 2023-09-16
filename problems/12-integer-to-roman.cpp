class Solution {

    string handleDigit(int digit, char c1, char c2, char c3){

        string result = "";

        if(digit == 9){
            result +=c1;
            result +=c3;
            return result;
        }
        if(digit == 4){
            result +=c1;
            result +=c2;
            return result;
        }

        

        if(digit >= 5){
            result+= c2;
            digit-=5;
        }

        while(digit){
            result+=c1;
            digit--;
        }

        return result;

    }

public:
    string intToRoman(int num) {
        
        string result = "";

        int digit1 = num / 1000;
        int digit2 = num / 100 % 10;
        int digit3 = num / 10 % 10;
        int digit4 = num % 10;

        while(digit1){
            result +="M";
            digit1--;
        }
        

        result += handleDigit(digit2,'C','D','M');
        result += handleDigit(digit3,'X','L','C');
        result += handleDigit(digit4,'I','V','X');

        return result;



    }
};