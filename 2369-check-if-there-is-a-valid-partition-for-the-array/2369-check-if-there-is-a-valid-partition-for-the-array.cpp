class Solution {
public:
    
    int n;

    int t[100001];
    int solve(vector<int>& nums, int i){
        
    if(i>=n)
        return true;
        
     if(t[i] != -1){
         return t[i];
     }   
        
     bool res = false;
        
     //rule 1
     if((i+1<n) && nums[i] == nums[i+1]){
        
        res |= solve(nums,i+2);
     }
       
        
     //rule 2
     if((i+2<n) && nums[i] == nums[i+1] && nums[i+1] == nums[i+2]){
        
        res |= solve(nums,i+3);
     }
    
      // rule 3
        
      if((i+2<n && nums[i+1] - nums[i]== 1 && nums[i+2] - nums[i+1] == 1)){
          res |= solve(nums,i+3);
      }
      
         return t[i] = res;
    }
    
    bool validPartition(vector<int>& nums) {
    
    n = nums.size();
    
    memset(t, -1, sizeof(t));
    return  solve(nums, 0);
    
    }
};