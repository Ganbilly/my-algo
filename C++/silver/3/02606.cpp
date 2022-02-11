#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n, m, a, b;
    int count = 0;
    int **arr;
    int *infested;
    queue<int> q;

    cin >> n >> m;

    infested = new int[n]{ 0, };
    arr = new int*[n];

    for(int i = 0 ; i < n; i++)
        arr[i] = new int[n]{0, };

    for(int i = 0; i < m; i ++){
        cin >> a >> b;
        arr[a - 1][b - 1] = 1;
        arr[b - 1][a - 1] = 1;
    }
    
    q.push(0);
    infested[0] = 1;

    while(!q.empty()){
        for(int i = 0; i < n; i++){
            if(q.front() == i)
                continue;
            if(arr[q.front()][i] == 1 && infested[i] == 0){
                infested[i] = 1;
                q.push(i);
            }
        }
        q.pop();
    }

    for(int i = 1; i < n; i++){
        if(infested[i] == 1)
            count++;
    }
    
    cout << count;
    return 0;
}