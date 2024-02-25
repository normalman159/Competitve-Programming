#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const ll MOD = 1e9+7;
#define ln "\n"
#define pb push_back
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
string s;

ll prime(ll x){
    for (ll i=2;i*i<=x;i++){
        if (x%i==0) return 0;
    }
    return 1;
}

void solve(){
    cin >> s;
    ll n = s.size();
    s = ' '+s;
    s+='H';
    ll res = -INF;
    string tmp;
    for (ll i=1;i<=n+1;i++){
        if (s[i] >='0' && s[i]<='9'){
            tmp+=s[i];
        } 
        else{
            for (ll j = 0;j<tmp.size();j++){
                for (ll k = 8;k>=1;k--){
                    string tmp1 = tmp.substr(j,k);
                    ll num = stoll(tmp1);
                    if (prime(num)==1) res = max(res, num);
                }
            }
            tmp="";
        }
    }
    cout << res;
}
int main()
{
    fast_cin();
    solve();
    return 0;
}