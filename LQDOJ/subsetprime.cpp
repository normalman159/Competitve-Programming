#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const ll MOD = 1e9+7;
#define ln "\n"
#define pb push_back
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const ll LimN = 1e5+5;
ll n,a[LimN],l,r;
ll p[LimN];
bool checknt(ll x){
    for (ll i=2;i*i<=x;i++){
        if (x%i==0) return false;
    }
    return true;
}

void solve(){
    cin >> n >> l >> r;
    for (ll i=1;i<=n;i++){
        cin >> a[i];
    }
    for (ll i=1;i<=n;i++){
        p[i] = p[i-1];
        if (checknt(a[i])){
            p[i]++;
        }
    }
    ll res1 = 0;
    for (ll i=1;i<=n;i++){
        ll x = p[i];
        if (x < l) continue;
        ll z = lower_bound(p,p+1+n,x -r ) - p;
        ll z1 = upper_bound(p,p+1+n, x - l) - p;
        z1--;
        // cout << i << " " << x << " " << p[z] << " " << p[z1] << ln;
        res1 += z1-z +1; 
    }
    cout << res1;
}
int main()
{
    fast_cin();
    solve();
    return 0;
}