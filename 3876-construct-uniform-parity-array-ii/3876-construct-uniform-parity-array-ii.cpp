class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minimum = INT_MAX;
        for(int i : nums1){
            if(i % 2 == 1){
                minimum = min(minimum,i);
            }
        }
        for(int i : nums1){
            if(i % 2 == 0 && minimum != INT_MAX && i < minimum){
                return false;
            }
        }
        return true;
    }
};