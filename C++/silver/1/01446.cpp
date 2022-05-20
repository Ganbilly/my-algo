#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000007

using namespace std;



int minl[10001];
bool visited[10001];

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n, d; cin >> n >> d;
    int start, end, len;
    
    pair<int, int> p;
    vector<vector<pair<int, int>>> v(d + 1);
    priority_queue<pair<int, int>> pq;          //pq = {-지름길길이, 거리}

    for(int i = 0; i < d + 1; i++)
        minl[i] = INF;
    
    for(int i = 0; i < n; i++){
        cin >> start >> end >> len;
        v[start].push_back({end, len});
    }

    for(int i = 0; i < v[0].size(); i++){
        pq.push({-v[0][i].second, v[0][i].first});
        if (minl[v[0][i].first] > v[0][i].second)
            minl[v[0][i].first] = v[0][i].second; 
    }
    
    while(pq.empty()){
        p = pq.top();
        if (p.second == d)
            break;
        if (visited[p.second])
            continue;
        visited[p.second] = true;

        for(int i = 0; i < v[p.second].size(); i++){
            if(minl[v[p.second][i].second] > minl[p.second] - v[p.second][i].first)
                minl[v[p.second][i].second] = minl[p.second] - v[p.second][i].first;
                pq.push({-minl[v[p.second][i].second], v[p.second][i].second});
        }

    }
    if(minl[d] != INF)
        cout << minl[d];
    int i = d;
    
    while(minl[i] == INF)
        i--;
    cout << minl[i] + (d - i);
    return 0;
}