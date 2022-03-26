#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int uf[10001];                  // uf[노드] = 노드의 루트

bool compare(vector<int> &a, vector<int> &b){
    return a[0] < b[0];
}

int findroot(int a){
    while (a != uf[a])
        a = uf[a];
    return a;
}

int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    
    int v, e; cin >> v >> e;        // v = 노드의 수, e = 간선의 수
    int a, b, c;                    // a, b, c = 출발, 도착, 가중치
    int tmp1, tmp2, count = 0;      // count = kruskal하면서 새로 만든 간선의 수
    int w = 0;                      // 새로만든 mst의 가중치 저장용 변수

    vector<vector<int>> edge;               // 입력받은 간선 저장용벡터

    for(int i = 0; i < e; i++){
        cin >> a >> b >> c;
        edge.push_back({c, a, b});
    }

    sort(edge.begin(), edge.end(), compare);    //kruskal 돌리기 위해서 간선들의 가중치로 정렬

    for(int i = 1; i <= v; i++)                 //unionfind를 위해 각 노드의 루트를 자기자신으로 변경
        uf[i] = i;
    
    for(int i = 0; i < e; i++){
        if(count == v - 1)                      // 새로만든 간선의 개수가 노드의수보다 1작을 경우 종료
            break;
        tmp1 = findroot(edge[i][1]);
        tmp2 = findroot(edge[i][2]);
        if(tmp1 == tmp2)                        // 두 노드가 같은 루트를 가질 경우 연결했을 때 사이클이 생기므로 넘어감
            continue;
        uf[edge[i][1]] = tmp1;
        uf[edge[i][2]] = tmp2;
        uf[tmp1] = tmp2;
        w += edge[i][0];
        count++;
    }

    cout << w;

    return 0;
}
