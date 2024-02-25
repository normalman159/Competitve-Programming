#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const ll MOD = 1e9+7;
#define ln "\n"
#define pb push_back
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
string s,t;

void solve(){
    cin >> s >> t;
    ll n = s.size();
    ll res = INF;
    s+=s;
    for(ll i=0;i<n;i++){
        string ne;
        for (ll j = i;j<=n-i+1;j++){
            ne+=s[j];
        }
        ll res1 = 0;
        for (ll i=0;i<ne.size();i++){
            res1+=(ne[i]!=t[i]);
        }
        res= min(res,res1+ min(i,n-i-1));
    }
    cout << res;
}
int main()
{
    // freopen("CHANGE.INP","r",stdin);
    // freopen("CHANGE.OUT","w",stdout);
    fast_cin();
    solve();
    return 0;
}