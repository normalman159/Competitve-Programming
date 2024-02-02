#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const long long INF = 1e15;
const ll MOD = 1e9+7;
const double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

ll n,m,a[MXN],dp[MXN],dp1[MXN];
void solve(){
    cin >> n >> m;
    for (ll i=1;i<=n;i++) cin >> a[i];
    for (ll i=1;i<=n;i++) dp[i] = INF, dp1[i] = INF;
    dp[0] = 0, dp[1] =0;
    dp1[n+1] = dp1[n] = 0;
    for (ll i =1; i<=n;i++){
        if (a[i] > a[i+1]){
            dp[i+1] = min(dp[i] + a[i] - a[i+1], dp[i+1]);
        }
        else dp[i+1] = min(dp[i+1],dp[i]);
        if (i !=1){
            if (a[i-1] < a[i]){
                dp[i-1] = min(dp[i] + a[i] - a[i-1], dp[i-1]);
            }
            else dp[i-1] = min(dp[i-1], dp[i]);
        }
    }
    for (ll i =n; i>=1;i--){
        if (a[i-1] < a[i]){
            dp1[i-1] = min(dp1[i] + a[i] - a[i-1], dp1[i-1]);
        }
        else dp1[i-1] = min(dp1[i-1], dp1[i]);
        
        if (i !=n){
            if (a[i] > a[i+1]){
                dp1[i+1] = min(dp1[i] + a[i] - a[i+1], dp1[i+1]);
            }
            else dp1[i+1] = min(dp1[i+1],dp1[i]);    
        }
    }
    // for (ll i=1;i<=n;i++) cout << dp[i] << " ";
    // cout << ln;
    while (m--){
        ll s,t;cin >> s >> t;
        if (s <= t){
            cout << dp[t] - dp[s] << ln;
        }
        else cout << dp1[t] - dp1[s] << ln;
    }
}
int main()
{
    fast_cin();
    solve();
    cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return 0;
}