#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> get_stair_paths(int n){
    if(n==0){
        vector<string> k;
        k.push_back("");
        return k;
    }
    vector<string> stm1=get_stair_paths(n-1);
    vector<string> yu;
    for(string instm1:stm1){
        yu.push_back("1"+instm1);
        yu.push_back(instm1+"1");
    }
    string str=to_string(n);
    yu.push_back(n);
    return yu;
    
    
}

int main(){
    int n;
    cin >> n;
    vector<string> ans = get_stair_paths(n);
    int cnt = 0;

    cout << '[';
    for (string str : ans){
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
}