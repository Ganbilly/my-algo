#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int m;                  //고장난 버튼 개수
    char input;             //고장난 버튼 입력받는 변수
    bool flag;
    int n;
    int ch1;
    int ch2;
    // string  n;              //도착해야하는 채널
    // string ch1;             //도착해야하는 채널에 가장 가까운 버튼의 lowerbound
    // string ch2;             //도착해야하는 채널에 가장 가까운 버튼의 upperbound
    vector<char> v;         //누를 수 있는 번호 버튼
    vector<int> pushbutton; //갈 수 있는 채널들의 눌렀던 버튼의 수


    for(int i = 0; i < 10; i++){
        v.push_back('0' + i);
    }    
    

    cin >> n >> m;

    for(int i = 0;i < m; i++){
        cin >> input;
        v.erase(remove(v.begin(), v.end(), input), v.end());
    }

    for(int i = 0; i < n.size(); i++){
        flag = false;
        for(auto j : v){
            if(n[i] == j){
                ch1 += j;
                ch2 += j; 
                flag = true;
                break;
            }
        }
        if(!flag){
            for(int j = v.size() - 1; j >= 0; j--){
                if(v[j] < n[i]){
                    ch1 += v[j];
                    for(int size = ch1.size(); size < n.size(); size++)
                        ch1 += v[v.size()-1];
                    
                    pushbutton.push_back(ch1.size() + abs(stoi(n) - stoi(ch1)));
                    break;
                    
                }
                if(n[i] == 0 && ch1.size() >= 1){
                    ch1.pop_back();
                    ch1.push_back(v[v.size() - 1]);
                    for(int size = ch1.size(); size < n.size(); size++)
                        ch1 += v[v.size()-1];
                }
            }
            for(int j = 0; j < v.size(); j++){
                if(v[j] > n[i]){
                    ch2 += v[j];
                    for(int size = ch2.size(); size < n.size(); size++)
                        ch2+= v[0];
                    
                    pushbutton.push_back(ch2.size() + abs(stoi(n) - stoi(ch2)));
                    break;
                }
                if (n[i] == 9 && ch1.size() >= 1){
                    ch2.pop_back();
                    ch2.push_back(v[v.size() - 1]);
                    for(int size = ch1.size(); size < n.size(); size++)
                        ch1 += v[v.size()-1];
                }
            }
            break;
        }
        if(i == n.size() - 1)
            pushbutton.push_back(ch1.size());
    }

    pushbutton.push_back(abs(stoi(n) - 100));
    sort(pushbutton.begin(), pushbutton.end());

    cout << pushbutton[0];

    return 0;

}