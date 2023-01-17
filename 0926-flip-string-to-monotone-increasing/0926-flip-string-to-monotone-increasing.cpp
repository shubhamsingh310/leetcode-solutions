class Solution {
public:
    //DP approach
    int minFlipsMonoIncr(string s) {
        int flps = 0, counter = 0;
        for (auto c : s) {
            if (c == '1') counter++;
            else flps++;
            flps = min(flps, counter);
        }
        return flps;
    }
};