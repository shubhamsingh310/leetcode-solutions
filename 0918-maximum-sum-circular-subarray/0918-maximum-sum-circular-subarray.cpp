class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total_sum=0,current_sum1=0,current_sum2=0,max_sum_subarray=INT_MIN,min_sum_subarray=INT_MAX;   
        for(auto i:nums)
        {
            total_sum+=i; current_sum1+=i; current_sum2+=i;
            max_sum_subarray=max(max_sum_subarray,current_sum1);
            if(current_sum1<0) current_sum1=0;
            min_sum_subarray=min(current_sum2,min_sum_subarray);
            if(current_sum2>0) current_sum2=0;
        }
        return (total_sum==min_sum_subarray)?max_sum_subarray:max(max_sum_subarray,total_sum-min_sum_subarray);  
    }
};
