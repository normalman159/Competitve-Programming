#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const long long INF = 1e15;
const ll MOD = 1e9+7;
#define ln "\n"
#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const ll LimN = 1e5+5;

ll n,a[LimN], f[LimN];

void solve(){
    ll ans = 0;
    cin >> n;
    for (ll i=1;i<=n;i++){
        cin >> a[i];
        ans+=a[i];
    }
    f[0] = 0;
    for (ll i=1;i<=n+1;i++) f[i] = INF;
    for (ll i=1;i<=n+1;i++){
        for (ll j = max(0LL,i-3);j<i;j++){
            f[i] = min(f[i],f[j] + a[i]);
        }
    }
    cout << ans - f[n+1];
}
ll dp[LimN],p[LimN];
void solve1(){
    cin >> n;
    for (ll i=1;i<=n;i++){
        cin >> a[i];
    }
    dp[1] = a[1];
    dp[2] = max(a[2] + a[1],a[2]);
    p[1] = max(dp[1],0LL);
    p[2] = max(p[1],dp[2]);
    for (ll i=3;i<=n;i++){
        //chon tu i-1
        dp[i] = max(dp[i],p[i-3] + a[i] + a[i-1]);
        //chon tu i-2
        dp[i] = max(dp[i],p[i-2] + a[i]);
        //ko noi 
        dp[i] = max(dp[i],p[i-3] + a[i]);
        p[i] = max(p[i-1], dp[i]);
        // cout << i << " " << dp[i] << " " << p[i] << ln;
    }
    cout << p[n];
}

int main()
{
    // freopen("REWARD.INP","r",stdin);
    // freopen("REWARD.OUT", "w",stdout);
    fast_cin();
    solve1();
    return 0;
}