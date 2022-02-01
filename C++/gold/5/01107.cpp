#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool canPush(int input, vector<char> v){
    string ch = to_string(input);
    bool flag;

    for(int i = 0; i < ch.size(); i++){
        flag = false;
        for(auto j : v){
            if(j == ch[i]){
                flag = true;
                break;
            }
        }
        if(!flag)
            return false;
    }
    return true;
}

int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int m;                                  //고장난 버튼 개수
    char input;                             //고장난 버튼 입력받는 변수
    bool ch1c = false, ch2c = false;
    string  n;                              //도착해야하는 채널
    string ch1;                             //도착해야하는 채널에 가장 가까운 버튼의 lowerbound
    string ch2;                             //도착해야하는 채널에 가장 가까운 버튼의 upperbound
    vector<char> v;                         //누를 수 있는 번호 버튼
    vector<int> pushbutton;                 //갈 수 있는 채널들의 눌렀던 버튼의 수


    for(int i = 0; i < 10; i++){
        v.push_back('0' + i);
    }    
    

    cin >> n >> m;

    for(int i = 0;i < m; i++){
        cin >> input;
        v.erase(remove(v.begin(), v.end(), input), v.end());
    }

    if(v.size() != 0){
        for(int i = 0, ch = stoi(n); (!ch1c || !ch2c) && (i <= ch || i <= 500000); i ++){
            if(!ch1c && i <= ch && canPush(ch - i, v)){
                ch1 = to_string(ch - i);
                ch1c = true;
            }
            if(!ch2c && canPush(ch + i, v)){
                ch2 = to_string(ch + i);
                ch2c = true;
            }
        }

    }

    if(ch1c)
        pushbutton.push_back(ch1.size() + abs(stoi(n) - stoi(ch1)));                    // 채널로 갈때 누른 버튼 횟수 + 목표채널까지 + 또는 - 누른 횟수
    if(ch2c)
        pushbutton.push_back(ch2.size() + abs(stoi(n) - stoi(ch2)));
    pushbutton.push_back(abs(stoi(n) - 100));
    sort(pushbutton.begin(), pushbutton.end());

    cout << pushbutton[0];

    return 0;

}