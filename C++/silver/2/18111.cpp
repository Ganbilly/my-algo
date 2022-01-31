#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

long long getTime(int **arr, int &n, int &m, long long &avg, long long &b){
    long long time = 0; 
    long long tmp = 0; 

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            tmp = arr[i][j] - avg;
            if(tmp >= 0){
                time += tmp * 2;
            }
            else{
                time += tmp * (-1);
            }
        }
    }

    return time;
}

bool compare(pair<long long, long long> &a, pair<long long, long long> &b){
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

int main(){

    ios:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    long long b;
    int **arr;
    long long avg = 0;
    vector<pair<long long, long long>> v;
    long long tmp;

    cin >> n >> m >> b;
    arr = new int*[n];

    for(int i = 0; i < n; i++){
        arr[i] = new int[m];
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            avg += arr[i][j];
        }
    }

    avg = round(avg / (double)(n * m));

    for(long long i = avg; i >= 0; i--){
        tmp = getTime(arr, n, m, i, b);
        if( tmp >= 0 ){
            v.push_back({tmp, i});
        }
    }
    
    sort(v.begin(), v.end(), compare);

    cout << v[0].first << ' ' << v[0].second;
    return 0;
}