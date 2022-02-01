#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<long long , long long> pll;

bool compare(const pll &a, const pll &b){
    return a.first < b.first;
}
int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n, color, size;
    long long sumsize, colorsize, tmp;
    vector<pll> seq;                // { 크기 , 색 }
    vector<pll> sum;               //  {크기, 누적합}

    cin >> n;

    vector<vector<pll> > colorv(n + 1);         // colorv[색번호] = {크기, 누적합}

    for(int i = 0; i < n; i ++){
        cin >> color >> size;
        
        seq.push_back({size, color});
    }

    vector<pll> v(seq);                 
    sort(v.begin(), v.end());
    sum.push_back({v[0].first, 0});
    colorv[v[0].second].push_back({v[0].first, 0});

    for(int i = 1; i < n; i++){
        sum.push_back({v[i].first, sum[sum.size() - 1].first + sum[sum.size() - 1].second});
        if(colorv[v[i].second].size() == 0)
            colorv[v[i].second].push_back({v[i].first, 0});
        else
            colorv[v[i].second].push_back({v[i].first, colorv[v[i].second].back().first + colorv[v[i].second].back().second});
            
    }

    for(int i = 0; i < n; i++){
        tmp = lower_bound(sum.begin(), sum.end(), pll(seq[i].first, 0), compare) - sum.begin();
        sumsize = sum[tmp].second;
        tmp = lower_bound(colorv[seq[i].second].begin(), colorv[seq[i].second].end(), pll(seq[i].first, 0), compare) - colorv[seq[i].second].begin();
        colorsize = colorv[seq[i].second][tmp].second;

        cout << sumsize - colorsize << '\n';
    }

    return 0;
}