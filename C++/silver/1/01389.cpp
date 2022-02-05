#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b){
    if(a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}
int findkevin(int **arr, int n, int target){
    int kevin = 0;
    int depth;
    int *visited;
    bool flag;
    deque<int> dq;
    deque<int> standby;

    for(int i = 1; i <= n; i ++){
        if(i == target)
            continue;
        depth = 0;
        dq.clear();
        dq.push_back(i);
        standby.clear();
        visited = new int[n + 1]{0, };

        while(!dq.empty()){
            flag = false;

            for(int j = 1; j <= n; j++){
                if(i == j)
                    continue;
                if(arr[dq.front()][j] == 1 && visited[j] == 0){
                    if(j == target){
                        depth++;
                        flag = true;
                        break;
                    }
                    standby.push_back(j);
                }
            }
            dq.pop_front();

            if(flag)
                break;

            if(dq.empty()){
                dq.swap(standby);
                depth++;
            }
        }
        kevin += depth;

        delete visited;
        
    }

    return kevin;
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    int a, b;
    int **arr;
    vector<pair<int, int> > v;      //{kevin , index}
    cin >> n >> m;

    arr = new int*[n + 1];

    for(int i = 0; i <= n; i++)
        arr[i] = new int[n + 1]{0, };

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1; 
    }

    for(int i = 1; i <= n; i++)
        v.push_back({findkevin(arr, n, i), i});

    sort(v.begin(), v.end(), compare);

    cout << v[0].second;
    return 0;
}