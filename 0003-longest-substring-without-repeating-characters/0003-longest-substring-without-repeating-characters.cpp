class Solution {
public:
    unordered_map<int,int>mp;
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0){
            return 0;
        }
        // Sliding Window Approach
        int i=0;
        int j=0;
        int big=INT_MIN;
        
        while(j<s.length()){
            // 1
            mp[s[j]]++;
            
            if(mp.size() > j-i+1){
                j++;
            }
            else if(mp.size()==j-i+1){
                // We are getting an answer
                big=max(big,j-i+1);
                j++;
            }
            else if(mp.size() < j-i+1){
                // Remove calculatio for i
                while(mp.size() < j-i+1){
                    mp[s[i]]--;
                    if(mp[s[i]]==0){
                        mp.erase(s[i]);
                       
                    }
                   i++;
                }
                j++;
            }
        }
        
        return big;
    }
};