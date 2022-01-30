#include <iostream>
#include <queue>

using namespace std;

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, m, priority;
    int j;

    queue<pair<int, int>> q1;
    priority_queue<int> q2;

    cin >> t;

    for(int i = 0; i < t; i++){
        while(!q1.empty())
            q1.pop();
        while(!q2.empty())
            q2.pop();

        cin >> n >> m;

        for(j = 0; j < n; j++){
            cin >> priority;

            q1.push({j, priority});
            q2.push(priority);
        }

        for(j = 1; !q1.empty(); ){
            if(q1.front().second == q2.top()){
                if(q1.front().first == m){
                    break;
                }
                q1.pop();
                q2.pop();
                j++;
            }
            else{
                q1.push(q1.front());
                q1.pop();
            }
        }
        cout << j <<'\n';
    }
    return 0;

}