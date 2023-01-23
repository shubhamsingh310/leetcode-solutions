class Solution {
public:
    int findJudge(int n, vector<vector<int>> trst) {
        if (trst.size() == 0 && n == 1) 
            return 1;
        vector<int> cnt(n + 1);
        for (auto prsn : trst) {
            cnt[prsn[0]]--;
            cnt[prsn[1]]++;
        }

        for (int prsn = 0; prsn < cnt.size(); prsn++) {
           
            if (cnt[prsn] == n - 1) 
                return prsn;
        }
        return -1;
    }
};