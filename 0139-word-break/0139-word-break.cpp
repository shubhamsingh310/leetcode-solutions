class Solution {
public:
    unordered_map<string, bool> mp;
    bool solve(unordered_set<string>& st, string s) {
        if(s.length() == 0)
            return true;
        if(mp.find(s) != mp.end())
            return mp[s];
        
        for(int l = 1; l<=s.length(); l++) {
            string tempL = s.substr(0, l);
            string tempR = s.substr(l);
            if(st.count(tempL) && solve(st, tempR))
                return mp[s] = true;
        }
        return mp[s] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        
        mp.clear();
        return solve(st, s);
        
        return false;
        
    }
};