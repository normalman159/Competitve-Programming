#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const ll MOD = 1e9+7;
#define ln "\n"
#define pb push_back
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const ll LimN = 1e3+5;
ll n, a[LimN], f[LimN],f1[LimN];

void solve(){
    cin >> n;
    ll sum = 0;
    for (ll i=1;i<=n;i++){
        cin >> a[i];
        sum+=a[i];
    }
    ll mx = -INF;
    for (ll i=1;i<=n;i++){
        f[i]=a[i];
        f1[i]=1;
        for (ll j = 1;j<i;j++){
            if (a[j]<=a[i] && f1[i] < f1[j] +1){
                f[i] = f[j] + a[i];
                f1[i]=f1[j]+1;
            }
        }
        mx = max(mx,f1[i]);
    }
    ll res = 0;
    for (ll i=1;i<=n;i++){
        if (f1[i]==mx){
            res = max(res,f[i]);
        }
    }
    cout << sum - res;
}
int main()
{
    fast_cin();
    solve();
    return 0;
}