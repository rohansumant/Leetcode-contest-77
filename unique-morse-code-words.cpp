class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        const string a[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> st;
        for(string w:words) {
            string ans;
            for(char ch:w) {
                ans += a[ch-'a'];
            }
            st.insert(ans);
        }
        return st.size();
    }
};
