#include <iostream>
#include <vector>

using namespace std;

void star(vector<vector<int> > &v, int sr, int sc, int len){
    if(len == 5){
        v[sr - 1][sc + 1] = 0;
        return;
    }
    for (int i = 0; i < len / 4 + 1 ; i++){
        for (int j = 0; j < i * 2 + 1; j++){
            v[sr - i][sc + (len / 2) - (2 * i) + j] = 0;
        }
    }


    star(v, sr, sc, len / 2);
    star(v, sr, sc + len/2 + 1, len / 2);
    star(v, sr - len / 4 - 1, sc, len / 2);
    return ;
}

int main(){

    int n; cin >> n;

    vector<vector<int> > v(n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i * 2 + 1; j++){
            v[i].push_back(1);
        }
    }

    star(v, n - 1, 0, 2 * n - 1);



    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            cout<<' ';
        }

        for(int j = 0; j < v[i].size(); j++){
            if(v[i][j] == 1)
                cout << '*';
            else{
                cout << ' ';
            }
        }
        for(int j = 0; j < n - i - 1; j++){
            cout<<' ';
        }
        cout << '\n';
    }
    return 0;
}