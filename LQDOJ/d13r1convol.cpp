#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const ll MOD = 1e9+7;
#define ln "\n"
#define pb push_back
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const ll LimN = 5e3+5;
ll n,a[LimN],f[LimN][LimN],b[LimN];

void solve(){
    cin >> n;
    for (ll i=1;i<=n;i++) cin >> a[i];
    for (ll i=1;i<=n;i++) cin >> b[i];
    ll res = -INF;
    for (ll i=1;i<=n;i++){
        for (ll j =1;j<=n;j++){
            ll z = a[i]*b[j];
            f[i][j] = max(z,f[i-1][j-1] + a[i]*b[j]);
        }
    }
    for (ll i=1;i<=n;i++){
        for (ll j = 1;j<=n;j++){
            res = max(res, f[i][j]);
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