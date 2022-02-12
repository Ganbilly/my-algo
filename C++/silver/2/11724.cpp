#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    int a, b, count = 0;
    int **arr = new int*[n];
    bool *check = new bool[n];
    queue<int> q;

    for(int i = 0; i < n; i++){
        arr[i] = new int[n]{0, };
    }

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        arr[a - 1][b - 1] = 1;
        arr[b - 1][a - 1] = 1;
    }

    for(int i = 0; i < n; i++){
        if(!check[i]){
            q.push(i);
            check[i] = true;
            while(!q.empty()){
                for(int j = 0; j < n; j++){
                    if(arr[q.front()][j] == 1 && !check[j]){
                        q.push(j);
                        check[j] = true;
                    }
                }   
                q.pop();
            }

            count++;
        }
    }

    cout << count;
    
    return 0;
}