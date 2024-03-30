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
const ll LimN = 2*1e5+5, Lim = 1e7+5;
ll n, a[LimN], cnt[Lim];
void solve(){
    cin >> n;
    ll hi = -1;
    for (ll i=1;i<=n;i++){
        cin >> a[i];
        cnt[a[i]]++;
        hi = max(hi,a[i]);
    }
    for (ll i=hi;i>=1;i--){
        ll res = 0;
        for (ll j = i;j<=hi;j+=i){
            res += cnt[j];
        }
        if (res >= 2){
            cout << i;
            return;
        }
    }
    cout << 1;
}
int main()
{
    // freopen("DISCOUNT.INP","r",stdin);
    // freopen("DISCOUNT.OUT","w",stdout);
    fast_cin();
    solve();
    return 0;
}