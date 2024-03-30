#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const ll MOD = 1e9+7;
#define ln "\n"
#define pb push_back
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const ll LimN = 1e6+5;
ll n,m,a[LimN], p[LimN];
void solve(){
    cin >> n >> m;
    for (ll i=1;i<=n;i++){
        cin >> a[i];
    }
    for (ll i=1;i<=n;i++){
        p[i] = p[i-1] + a[i];
        cout<< p[i] << " ";
    }
    cout << ln;
    ll res = 0;
    for(ll i=1;i<=n;i++){
        ll x = p[i] -m;
        ll z = lower_bound(p,p+i+1,x) - p;
        res+=i-z;
    }
    cout << res;
}
int main()
{
    fast_cin();
    solve();
    return 0;
}