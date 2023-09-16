class Solution {

private:
    int calcArea(vector<int>& height, int left, int right){

        return (right-left) * min(height[right],height[left]);

    }

public:
    //recursive solution doesnt work, gives TLE
    int solveMaxArea(int left, int right, vector<int>& height, vector<vector<int>> &dp){

        if(left == right){
            dp[left][right] = 0;
            return 0;
        }
        
        if(dp[left][right] != -1){
            return dp[left][right];
        }

        if(right > left){
            
            int area = calcArea(height,left,right);
            
            if(height[left+1] >= height[right-1]){
                dp[left][right] = max(solveMaxArea(left+1,right,height,dp), area);
            }else{
                dp[left][right] = max(solveMaxArea(left,right-1,height,dp), area);
            }

           // dp[left][right] = max({solveMaxArea(left,right-1,height,dp), solveMaxArea(left+1,right,height,dp),area} );
            return dp[left][right];
        }

        return -1;

        

    }
    



    int maxArea(vector<int>& height) {
        //vector<vector<int>> dp(height.size(),vector<int>(height.size(),-1));
        //return solveMaxArea(0,height.size()-1,height,dp);

        int left = 0;
        int right = height.size()-1;

        int maxArea = 0;

        while(left < right){

            maxArea = max(maxArea, calcArea(height,left,right));

            if(height[left] >= height[right]){
                right--;
            }else{
                left++;
            }
        }
        return maxArea;
    }
};