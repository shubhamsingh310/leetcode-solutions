class Solution {
public:
    vector<int> successfulPairs(vector<int>& ss, vector<int>& p, long long suc) {
        vector<int>s=ss;
        unordered_map<int,int>mpp;
        vector<int>ans; 

        sort(p.begin(),p.end());

        sort(s.begin(),s.end(),greater<int>());  

        int n=s.size();int n2=p.size();

        int k=0;

        for(int i=0;i<n;i++){

            bool flag=0;

            for(int j=k;j<n2;j++){
               
                if(1LL*s[i]*p[j]>=suc){
                    k=j; 
                    flag=1;
                    mpp[s[i]]=n2-j;
                    break;
                }
            }

            if(flag==0){  break; } 
        }

        for(int i=0;i<n;i++){
          
            if(mpp.count(ss[i]))ans.push_back(mpp[ss[i]]);

            else ans.push_back(0);
        }

        return ans;
    }
};