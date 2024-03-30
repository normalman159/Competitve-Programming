#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MOD = 1e9+7;
#define ln "\n"
#define pb push_back
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const ll LimN = 1e5+5;
ll t,n,a[LimN], c[LimN];
vector<ll> v;
void solve(){
    cin >> n >> t;
    for (ll i=1;i<=n;i++){
        cin >> a[i];
    } 
    sort(a+1,a+1+n);
    a[0] = -INF;
    for (ll i=1;i<=n;i++){
        if (a[i]!=a[i-1]){
            v.pb(a[i]);
        }
    }
    for (ll i=1;i<v.size();i++){
        c[i] = c[i-1] + (v[i] - v[i-1] -1);
    }
    ll z = v.size();
    c[z] = INF;
    while (t--){
        ll k; cin >> k;
        ll p = lower_bound(c+1,c+1+z,k) - c -1;
        cout << v[p] + (k - c[p]) << ln;
    }
}
int main()
{
    fast_cin();
    solve();
    return 0;
}