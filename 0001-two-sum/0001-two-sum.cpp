class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> prev;
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            int diff=target-nums[i];
            
            if(prev.find(diff)!=prev.end())
                return {prev[diff],i};
            
            prev[nums[i]]=i;
        }
        return {};
    } 
};