class Solution {
public:
    int subarraysDivByK(vector<int>& A, int M) {

        int pre = 0; 
        vector<int> cPre(M);
        cPre[pre]++;
        
        int ans = 0;
        for(int i = 0; i < A.size(); i++) {
            
            pre = (pre + A[i]) % M; 
            
            if(pre < 0) pre += M; 
            ans += cPre[pre]; 
            cPre[pre]++;
        }
        return ans;
    }
};