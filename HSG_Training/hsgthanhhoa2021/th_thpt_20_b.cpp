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
ll n, a[LimN],cnt[LimN];
void solve(){
    cin >> n;
    for (ll i=1;i<=n;i++) cin >> a[i];
    for (ll i=1;i<=n;i++){
        cnt[a[i]]++;
    }
    ll mi = -1;
    for (ll i=1;i<=n;i++){
        mi = max(mi,cnt[a[i]]);
    }
    cout << mi;
}
int main()
{
    // freopen("CAU2.INP","r",stdin);
    // freopen("CAU2.OUT","w",stdout);
    fast_cin();
    solve();
    return 0;
}