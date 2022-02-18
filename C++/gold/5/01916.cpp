#include <iostream>
#include <climits>
#include <queue>

#define INF INT_MAX

using namespace std;

int arr[1000][1000];
bool visited[1000];

void dijkstra(int a, int n){
    priority_queue<pair<int, int> > pq;
    pair<int, int> tmp;

    
    fill_n(visited, n, false);
    pq.push({0, a});

    visited[a] = true;

    for(int i = 0; i < n; i++){
        if(arr[a][i] != INF)
            pq.push({-arr[a][i], i});
    }

    while(!pq.empty()){
        
        tmp = pq.top();
        tmp.first *= -1;
        pq.pop();
        
        if(visited[tmp.second])
            continue;
        visited[tmp.second] = true;
        for(int i = 0; i < n; i++){
            if(arr[tmp.second][i] != INF && arr[tmp.second][i] + tmp.first < arr[a][i]){
                arr[a][i] = arr[tmp.second][i] + tmp.first;
                pq.push({-arr[a][i], i});
            }
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b, d; cin >> n >> m;

    for(int i = 0; i < n; i ++){
        fill_n(arr[i], n, INF);
        arr[i][i] = 0;
    }

    for(int i = 0; i < m; i++){
        cin >> a >> b >> d;
        if(arr[a - 1][b - 1] > d)
            arr[a - 1][b - 1] = d;
    }

    cin >> a >> b;
    
    dijkstra(a - 1, n);

    cout << arr[a - 1][b - 1] ;

    return 0;
}