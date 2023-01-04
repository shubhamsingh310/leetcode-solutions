
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> a;
        for(auto x: tasks){
            a[x]++;
        }

        int count = 0;
        for(auto x: a){
            int t = x.second;

            if(t == 1){
                return -1;
            }
            if(t % 3 == 0){
                count += t / 3;
            }else if(t % 3 == 2){
                count += t / 3;
                count++;
            }else{
                count += t / 3;
                count++;
            }
        }
        return count;
    }
};