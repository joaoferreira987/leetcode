#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        

        

        int left = 0;
        int right = 0;

        int sorted_index = 0;

        int prev = -1;
        int curr = -1;

        bool is_even = false;

        if((nums1.size()+nums2.size()) % 2 == 0) {
            is_even = true;
        }

        //edge case
        if(nums1.size() == 0 && nums2.size() == 1){
            return nums2[0];
        }
        //edge case
        if(nums2.size() == 1 && nums2.size() == 0){
            return nums1[0];
        }
        

        while(sorted_index <= (nums1.size()+ nums2.size())/2){
            
            prev = curr;

            if(left != nums1.size() && right != nums2.size()){
                if(nums1[left] <= nums2[right]){
                    curr = nums1[left];
                    left++;
                }else{
                    curr = nums2[right];
                    right++;
                }
            }else{
                if(left == nums1.size()){
                    curr = nums2[right];
                    right++;
                }else{
                    curr = nums1[left];
                    left++;
                }
            }

        sorted_index++;
            

        }


        if(is_even){
            // cout << "is even " << prev << " " <<  curr <<endl;


            double result = (prev + curr)/(double)2; 
            return result;
        }

        return curr;


    }
};