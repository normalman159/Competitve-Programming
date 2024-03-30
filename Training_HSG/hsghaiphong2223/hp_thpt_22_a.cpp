#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = 1e18;
#define ln "\n"

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;
    string ans = "virus";
    string tmp;
    ll res = 0;
    for (ll i=0;i<s.size();i++){
        tmp+=s[i];
        for (ll j = 1;j<5;j++){
            tmp +=s[j+i];
        }
        if (tmp == ans){
            res++;
        }
        tmp="";
    }

    cout << res;

    return 0;
}
