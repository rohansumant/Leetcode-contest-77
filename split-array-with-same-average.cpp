class Solution {
public:
    vector<int> a;
    int n;
    
    bool splitArraySameAverage(vector<int>& A) {
        a = A; n = a.size();
        int sum = 0;
        double avg = 0;
        for(int i:a) {
            avg += i;
            sum += i;
        }
        avg /= n;
        int N = sum+1;
        vector<int> mp(N),nmp(N);
        for(int i=0;i<n;i++) {
            nmp = mp;
            nmp[a[i]] |= 1;
            for(int j=0;j<N;j++) {
                if(mp[j]) nmp[j+a[i]] |= (mp[j] << 1);
            }
            mp = nmp;
        }
        
        for(int i=0;i<sum;i++) if(mp[i]) {
            for(int j=0;j<29;j++) if(mp[i] & (1<<j)) {
                if(avg == (i / (1.0*(j+1)))) return 1;
            }
        }
        return 0;
    }
};
