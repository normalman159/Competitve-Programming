#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define ln " \n"
const ll INF = 1e18;

int main(){
    string s;
    cin >> s;
    ll res  =0;
    for (ll i=0;i<s.size();i++){
        if (s[i] >='0' && s[i]<='9') res++;
    }
    cout << res;

    return 0;
}
