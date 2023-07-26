class Solution {
public:

    double possible(vector<int>&dist, long speed){
        double time = 0.0;
        for(int i = 0; i<dist.size()-1; i++){

            double t = double(dist[i])/double(speed);
           time += ceil(t);
        }
        time+=double(dist[dist.size()-1])/double(speed);
        return time;
    };

   

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int result = -1;
        long left = 1;
        long right = 1e7;

        while(left<=right){
            long mid = left + (right-left)/2;

            if(possible(dist, mid)<=hour){
                result = mid;
                right = mid -1;
            }else{
                left = mid+1;
            }
        }

        return result;
    }
};