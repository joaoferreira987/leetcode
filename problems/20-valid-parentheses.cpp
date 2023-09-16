class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1) return false;
        
        stack<char> myStack;

        for(char c : s){

            switch(c){
                case '{':
                    myStack.push('}');
                    break;
                case '(':
                    myStack.push(')');
                    break;
                case '[':
                    myStack.push(']');
                    break;
                
                default:
                    if(myStack.empty() || myStack.top() != c){

                        return false;

                    }
                    myStack.pop();
            }
        }

        if(!myStack.empty()) return false;

        return true;

    }
};