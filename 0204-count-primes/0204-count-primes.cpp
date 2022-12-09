class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<bool> prime(n,true);
        for(int i=2 ; i<n ; i++){
            if(prime[i]==true){
                for(int j=2*i ; j<n ; j+=i){
                    prime[j]=false;
                }
                count++;
            }
        }
        return count;
    }
}; 