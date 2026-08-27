class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //using additive method
        int actualsum = 0;
        int n  = nums.size();
        //using this formula to calculate sum of all elemnts pressent in that size n
        int sum = (n * (n + 1))/2;
        //loop to traverse the array
        for(int i  = 0; i < n; i++){
            //using this to find sum of all elemenst present in array
            actualsum += nums[i];
        }
        return sum - actualsum;
    }
};