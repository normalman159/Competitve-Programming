#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define ln "\n"
const ll INF = 1e18;

void fast_cin(void){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    fast_cin();
    string s;
    getline(cin,s);
    string tmp = "";
    ll n = s.size();
    s = ' ' + s;
    for (ll i=1;i<=n;i++){
        if ((s[i]>='a' && s[i] <='z') || (s[i]>='A' && s[i]<='Z')   ){
            tmp+=s[i];
        }
    }
    cout << tmp;
    return 0;
}
