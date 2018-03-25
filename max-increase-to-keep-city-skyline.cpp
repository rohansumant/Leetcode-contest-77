class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& a) {
        int r = a.size(), c = a[0].size();
        vector<int> tb(c),rl(r);
        for(int i=0;i<r;i++) for(int j=0;j<c;j++) {
            tb[j] = max(tb[j],a[i][j]);
            rl[i] = max(rl[i],a[i][j]);
        }
        int ans = 0;
        for(int i=0;i<r;i++) for(int j=0;j<c;j++) {
            if(min(rl[i],tb[j]) > a[i][j]) ans += min(rl[i],tb[j]) - a[i][j];
        }
        return ans;
    }
};