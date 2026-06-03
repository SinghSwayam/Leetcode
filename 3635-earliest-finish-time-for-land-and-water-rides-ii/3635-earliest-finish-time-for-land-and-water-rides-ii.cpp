class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        long long ans = LLONG_MAX;

        vector<pair<int,int>> water(m);
        for(int i=0;i<m;i++){
            water[i] = {waterStartTime[i],waterDuration[i]};
        }
        sort(water.begin(),water.end());
        vector<int> waterstart(m);
        vector<long long> waterpref(m),watersuff(m);

        for(int i=0;i<m;i++){
            waterstart[i] = water[i].first;
            if(i==0)
                waterpref[i] = water[i].second;
            else
                waterpref[i] = min(waterpref[i-1], (long long)water[i].second);
        }

        for(int i=m-1;i>=0;i--){
            long long val = (long long)water[i].first + water[i].second;
            if(i == m-1)
                watersuff[i] = val;
            else
                watersuff[i] = min(watersuff[i+1],val);
        }

        for(int i=0;i<n;i++){
            long long finish = landStartTime[i] + landDuration[i];
            int pos = upper_bound(waterstart.begin(),waterstart.end(),finish) - waterstart.begin();

            if(pos > 0){
                ans = min(ans, finish + waterpref[pos-1]);
            }

            if(pos < m){
                ans = min(ans, watersuff[pos]);
            }
        }


        vector<pair<int,int>> land(n);
        for(int i=0;i<n;i++){
            land[i] = {landStartTime[i],landDuration[i]};
        }
        sort(land.begin(),land.end());
        vector<int> landstart(n);
        vector<long long> landpref(n),landsuff(n);

        for(int i=0;i<n;i++){
            landstart[i] = land[i].first;
            if(i==0)
                landpref[i] = land[i].second;
            else
                landpref[i] = min(landpref[i-1], (long long)land[i].second);
        }

        for(int i=n-1;i>=0;i--){
            long long val = (long long)land[i].first + land[i].second;
            if(i == n-1)
                landsuff[i] = val;
            else
                landsuff[i] = min(landsuff[i+1],val);
        }

        for(int i=0;i<m;i++){
            long long finish = waterStartTime[i] + waterDuration[i];
            int pos = upper_bound(landstart.begin(),landstart.end(),finish) - landstart.begin();

            if(pos > 0){
                ans = min(ans, finish + landpref[pos-1]);
            }

            if(pos < n){
                ans = min(ans, landsuff[pos]);
            }
        }
        return (int)ans;
    }
};