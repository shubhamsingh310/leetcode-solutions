class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(begin(nums), end(nums));
                
        int maxL = 0;
        
        for(const int &x : st) {
            //It means we have numbers before this 'x' which is a potential start to the consecutive
            //sequence of which this 'x' is a member
          
            if(st.find(x-1) != st.end()) {
                continue;
            }
            
            int tempL = 1;
            while(st.find(x+tempL) != st.end()) { 
                tempL++;
            }
            
            maxL = max(maxL, tempL);
        }
        
        return maxL;
        
    }
};