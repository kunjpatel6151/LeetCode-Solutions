class Solution {
public:

    int floorIndex(vector<pair<int,int>>& arr, int x) {
        int l = 0, r = arr.size() - 1;
        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (arr[mid].first <= x) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }

    int ceilIndex(vector<pair<int,int>>& arr, int x) {
        int l = 0, r = arr.size() - 1;
        int ans = arr.size();

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (arr[mid].first >= x) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int n = landStartTime.size();
        int m = waterStartTime.size();

        vector<pair<int,int>> land, water;

        for(int i = 0; i < n; i++)
            land.push_back({landStartTime[i], landDuration[i]});

        for(int i = 0; i < m; i++)
            water.push_back({waterStartTime[i], waterDuration[i]});

        sort(land.begin(), land.end());
        sort(water.begin(), water.end());

        vector<int> landPrefDur(n);
        vector<int> waterPrefDur(m);

        vector<int> landSufFinish(n);
        vector<int> waterSufFinish(m);

        landPrefDur[0] = land[0].second;
        for(int i = 1; i < n; i++)
            landPrefDur[i] = min(landPrefDur[i - 1], land[i].second);

        waterPrefDur[0] = water[0].second;
        for(int i = 1; i < m; i++)
            waterPrefDur[i] = min(waterPrefDur[i - 1], water[i].second);

        landSufFinish[n - 1] =
            land[n - 1].first + land[n - 1].second;

        for(int i = n - 2; i >= 0; i--)
            landSufFinish[i] =
                min(landSufFinish[i + 1],
                    land[i].first + land[i].second);

        waterSufFinish[m - 1] =
            water[m - 1].first + water[m - 1].second;

        for(int i = m - 2; i >= 0; i--)
            waterSufFinish[i] =
                min(waterSufFinish[i + 1],
                    water[i].first + water[i].second);

        int ans = INT_MAX;

        // Land -> Water
        for(int i = 0; i < n; i++) {

            int sl = land[i].first;
            int el = sl + land[i].second;

            int pidx = floorIndex(water, el);
            int nidx = ceilIndex(water, el + 1);

            if(pidx != -1)
                ans = min(ans, el + waterPrefDur[pidx]);

            if(nidx != m)
                ans = min(ans, waterSufFinish[nidx]);
        }

        // Water -> Land
        for(int i = 0; i < m; i++) {

            int sw = water[i].first;
            int ew = sw + water[i].second;

            int pidx = floorIndex(land, ew);
            int nidx = ceilIndex(land, ew + 1);

            if(pidx != -1)
                ans = min(ans, ew + landPrefDur[pidx]);

            if(nidx != n)
                ans = min(ans, landSufFinish[nidx]);
        }

        return ans;
    }
};