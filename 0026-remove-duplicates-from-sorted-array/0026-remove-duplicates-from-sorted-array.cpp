class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int right=0;
        for(int left=1;left<nums.size();left++){
            if(nums[right]!=nums[left]){
                right++;
                nums[right]=nums[left];
            }
        }
        return right+1;
        
    }
};