class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return helper(0, nums, memo);
    }

    int helper(int i, vector<int>& nums, vector<int>& memo) {
        if (i >= nums.size()) {
            return 0;
        }
        if (memo[i] != -1) {
            return memo[i];
        }
        int taken = nums[i] + helper(i + 2, nums, memo); 
        int nottaken = helper(i + 1, nums, memo);

      
        return memo[i] = max(taken, nottaken);
    }
};