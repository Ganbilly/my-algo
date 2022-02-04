#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<priority_queue<int, vector<int>, greater<int> > > vp;

void dfs(vp graph, int *arr, int start ){

    int tmp;
    int size;
    cout << start << ' ';

    if(graph[start].size() == 0)
        return;
    else{
        size = graph[start].size();
        for(int i = 0; i < size; i++){
            tmp = graph[start].top();
            graph[start].pop();
            if(arr[tmp] == 0){
                arr[tmp] = 1;
                dfs(graph, arr, tmp);
            }
        }
    }
    return;
}

void bfs(vp graph, int *arr, int start ){
    int size;
    int tmp;
    queue<int> pq;
    queue<int> standby;

    size = graph[start].size();
   
    cout << start << ' ';

    for(int i = 0; i < size; i++){
        if(arr[graph[start].top()] == 0){
            pq.push(graph[start].top());
            arr[graph[start].top()] = 1;
        }
        graph[start].pop();
    }

    while(!pq.empty()){
        tmp = pq.front();
        cout << tmp << ' ';
        size = graph[tmp].size();

        for (int i = 0; i < size; i++){
            if(arr[graph[tmp].top()] == 0){
                standby.push(graph[tmp].top());
                arr[graph[tmp].top()] = 1;
            }
            graph[tmp].pop();            
        }
        pq.pop();

        if(pq.empty()){
            while(!standby.empty()){
                pq.push(standby.front());
                standby.pop();
            }

        }
    }

    return;
}

int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n, m, v;
    int v1, v2;
    int *arr;

    cin >> n >> m >> v;

    vp graph(n + 1);

    for(int i = 0; i < m; i++){
        cin >> v1 >> v2;
        graph[v1].push(v2);
        graph[v2].push(v1);
    }

    arr = new int[n + 1]{0,};
    arr[v] = 1;
    dfs(graph, arr, v);
    
    delete arr;
    cout << '\n';

    arr = new int[n + 1]{0,};
    arr[v] = 1;
    bfs(graph, arr, v);
    
    return 0;
}