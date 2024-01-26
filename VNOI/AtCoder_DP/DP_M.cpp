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

ll n,k, a[MXN],dp[103][100005];
void solve(){
    cin  >> n >> k;
    for (ll i=1;i<=n;i++){
        cin >> a[i];
    }
    dp[0][0] =1;
    for (ll i=1;i<=n;i++){
        ll sum[k+1];
        sum[0] = dp[i-1][0];
        for (ll j=1;j<=k;j++){
            sum[j] = (sum[j-1] + dp[i-1][j])%MOD;
        }
        for (ll j=0;j<=k;j++){
            ll s = sum[j];
            ll u = j - a[i] -1;
            if (u>=0){
                s = (s-sum[u] + MOD)%MOD;
            }
            dp[i][j] = s%MOD;
        }       
    }
    cout << dp[n][k];
}
int main()
{
    fast_cin();
    solve();
    cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return 0;
}