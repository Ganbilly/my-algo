#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n, input, count, result;
    double avg = 0;
    vector<int> v;
    vector<pair<int, int>> v2;                  // {나온 횟수, 숫자}
    pair<int, int> p;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin>>input;
        avg += input;
        v.push_back(input);
    }
    avg /= n;
    sort(v.begin(), v.end());

    v2.push_back({0, v[0]});
    for(int i = 0; i < n; i++){
        if(v[i] == v2.back().second){
            v2[v2.size() - 1].first++;
        }
        else{
            v2.push_back({1, v[i]});
        }
    }
    sort(v2.begin(), v2.end(), compare);

    if(v2.size() > 2){
        if(v2[v2.size() - 1].first == v2[v2.size() - 2].first)
            p = v2[v2.size() -2];
        else
            p = v2[v2.size() -1];
    }

    else{
        p = v2[0];
    }

    cout << round(avg) << '\n';
    cout << v[n / 2] << '\n';
    cout << p.second <<'\n';
    cout << *v.rbegin() - *v.begin() << '\n';
    return 0;
}