class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        int half = n / 2;

        long long totalSum = 0;

        for (int num : nums) {
            totalSum += num;
        }

   
        long long windowSum = 0;

        for (int i = 0; i < half; i++) {
            windowSum += nums[i];
        }

        int ans = 0;

      
        for (int start = 0; start < n; start++) {

            long long secondSum = totalSum - windowSum;

            if (windowSum > secondSum) {
                ans++;
            }

         
            windowSum -= nums[start];
            windowSum += nums[(start + half) % n];
        }

        return ans;
    }
};