#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        
        int n = 0;

        bool first = true;

        bool negative = false;

        if(x < 0) {
            
            if(x == INT_MIN){
                return 0;
            }
            
            negative = true;
            x *= -1;
        }

        while(x){
            
            if(first){

                if(x%10 != 0){
                    n = x % 10;
                    first = false;
                }
                
                x = x / 10;
            }else{

                if(INT_MAX / 10 < n){
                    return 0;
                }
                n = n * 10;

                if(INT_MAX - (x % 10) < n){
                    return 0;
                }

                n += x % 10;
                x = x / 10;


            }

        

    }

        if(negative){
            n *= -1;
        }

        return n;
    }
};