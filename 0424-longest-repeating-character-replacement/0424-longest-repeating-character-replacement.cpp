class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length(), ans = 0;
        int start = 0, end = 0, maxFreq = 0;
        map<int, int> freq;
        
        for(end=0; end<n; end++){
            freq[s[end]]++;
            maxFreq = max(maxFreq, freq[s[end]]);
           
            
            while(end-start+1 - maxFreq > k){
                freq[s[start]]--;
                start++;
            }
            
            ans = max(ans, end-start+1);
        }
        
        return ans;
    }
};