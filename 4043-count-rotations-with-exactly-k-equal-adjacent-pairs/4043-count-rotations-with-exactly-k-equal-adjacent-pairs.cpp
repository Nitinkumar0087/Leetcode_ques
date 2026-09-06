class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();
        int ans = 0;

        for (int shift = 0; shift < n; shift++) {

        
            string t = s.substr(shift) + s.substr(0, shift);

       
            int score = 0;

            for (int i = 0; i < n - 1; i++) {
                if (t[i] == t[i + 1]) {
                    score++;
                }
            }

            if (score == k) {
                ans++;
            }
        }

        return ans;
    }
};