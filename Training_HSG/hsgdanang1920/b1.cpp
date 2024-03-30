#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const long long INF = 1e15;
const ll MOD = 1e9+7;
#define ln "\n"
#define pb push_back
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
string s;
ll tinhtong(string s){
    ll res = 0;
    for (ll i=0;i<s.size();i++){
        res+= s[i] - '0';
    }
    return res;
}
ll tinhtong1(ll x){
    ll res = 0;
    while (x > 0){
        res += x%10;
        x/=10;
    }
    return res;
}
void solve(){
    cin >> s;
    ll res = 0;
    res = tinhtong(s);
    while (!(res < 10 && res >=0)){
        res = tinhtong1(res);
    }
    cout << res;
}
int main()
{
    fast_cin();
    solve();
    return 0;
}