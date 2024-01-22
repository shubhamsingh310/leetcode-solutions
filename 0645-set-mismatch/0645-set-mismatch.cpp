class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i = 1; i<=nums.size();i++){
            mp[i] = 0;
        }
        for(int num:nums){
            mp[num]++;
        }
        vector<int> ans(2,-1);
        for(auto k:mp){
            if(k.second == 2){
                int temp = k.first;
                ans[0] = temp;
            } 
            if(k.second == 0){
                int temp = k.first;
                ans[1] = temp;
            }
        }
        return ans;
    }
};