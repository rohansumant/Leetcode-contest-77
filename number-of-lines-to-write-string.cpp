class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int cnt = 0;
        int rsum = 0;
        for(char ch:S) {
            if(rsum + widths[ch-'a'] > 100) {
                cnt++;
                rsum = widths[ch-'a'];
            } else {
                rsum += widths[ch-'a'];
            }
        }
        return {cnt+1,rsum};
    }
};
