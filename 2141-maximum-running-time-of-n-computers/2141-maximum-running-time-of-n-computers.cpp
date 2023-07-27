class Solution {
public:

    bool possible(vector<int>& batteries, long long mid, int n){
        long long target = mid *  n;
        long long sum = 0;
        for(long long i =0; i< batteries.size(); i++){
            target -= min((long long)batteries[i], mid);

            if(target<=0){
                return true;
            }
        }
        return false;
    }

    long long maxRunTime(int n, vector<int>& batteries) {

       long long left =  *min_element(batteries.begin(), batteries.end());
       long long sum = 0;
       for(int i = 0; i<batteries.size(); i++){
           sum+=batteries[i];
       }
       long long right = sum/n;
       

        long long ans = INT_MIN; 
     while(left<=right){
         long long mid = left + ((right-left)/2);

         if(possible(batteries, mid, n)){
             left = mid+1;
             ans = mid;
         }else{
             right = mid-1;
         }
     }

    return ans;
    }
};