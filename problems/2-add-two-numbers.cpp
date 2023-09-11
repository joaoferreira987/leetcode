#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        string number1 = getNumber(l1);
        string number2 = getNumber(l2);

        //string sum = to_string(number1+number2);

        string sum = sumNumber(number1,number2);

        ListNode* l = buildList(sum);


        return l;
    }

public: 

    string sumNumber(string n1, string n2){
         
         string result;

         int carry = 0;
         int i = 0;
         int j = 0;

         while(i <n1.size() || j<n2.size() || carry){

             int sum = carry;

             //cout << carry << endl;

             if(i<n1.size()){
                 sum += n1[i] - '0';
                 i++;

                //cout << sum << endl;

             }
             if(j<n2.size()){
                 sum += n2[j] - '0';
                 j++;
             }

            carry = sum / 10;
            sum %=10;

            result += to_string(sum);


         }


        //cout << result << endl;

        reverse(result.begin(),result.end());

        

        return result;

    }   

public:
    string getNumber(ListNode* l){
        
        ListNode *current = l;

        string number;

        while(current != nullptr){

            number.append(to_string(current->val));
            current = current->next;

        }


        //reverse(number.begin(),number.end());

        //cout << number << endl;
        return number;

    }

public:
    ListNode* buildList(string number){

        ListNode *tail = new ListNode(number[0]-'0');

        ListNode *curr = tail;

        for(int i=1; i < number.size(); i++){

                curr = new ListNode(number[i]-'0',tail);
                tail = curr;


        }

        return curr;

    }

};