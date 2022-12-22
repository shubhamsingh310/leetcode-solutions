class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        if(s.size() != goal.size()){
            return false;
        }
        goal = goal+goal;
        
        int cnt =0;
        bool flag = false;
        
        for(int i=0;i<goal.size();i++){
            if(s[0] == goal[i]){
                for(int j=0;j<n;j++){
                    if(s[j] == goal[i+j]){
                        cnt++;
                        flag = true;
                    }else{
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    break;
                }else{
                    cnt=0;
                }
            }
        }
    
        if(cnt == n){
            return true;
        }
        else{
            return false;
        }
    }
};