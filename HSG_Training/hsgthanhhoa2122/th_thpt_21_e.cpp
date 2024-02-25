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
ll n,a[LimN],f[LimN];

void solve(){
    cin >> n;
    for (ll i=1;i<=n;i++) cin >> a[i];
    //f[i]: tổng giá trị lớn nhất các đơn hàng được miễn phí đến i
    for (ll i=0;i<10;i++){
        f[i] = 0;
    }
    for (ll i=10;i<=n;i++){
        //ko chon tk i+1
        f[i] = max(f[i-1], f[i]);
        ll mi = INF;
        for (ll j = 10; j<=19;j++){
            mi = INF;
            if (i-j <0) continue;
            for (ll k = i-j+1;k<=i;k++){
                mi = min(mi,a[k]);
            }
            f[i] = max(f[i],f[i-j] + mi);
        }
    }   
    ll res = 0;
    for (ll i=1;i<=n;i++){
        res+=a[i];
    }
    cout << res-f[n];
}
int main()
{
    // freopen("BAI5.INP", "r",stdin);
    // freopen("BAI5.OUT","w",stdout);
    fast_cin();
    solve();
    return 0;
}