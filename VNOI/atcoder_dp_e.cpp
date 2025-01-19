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

ll n, w[MXN], W, v[MXN];
ll dp[MXN];
const ll max_value = 1e5+5;
void solve(){
    cin >> n >> W;
    for (ll i=1;i<=n;i++) cin >> w[i] >> v[i];
    for (ll i=0;i < max_value; i++){
        dp[i] = INF;
    }
    dp[0] = 0, dp[v[1]] = w[1];
    for (ll i=2;i<=n;i++){
        for (ll j = max_value-1;j>=0;j--){
            if (j - v[i] >=0 && dp[j - v[i]]!=INF && dp[j-v[i]] + w[i] <=W){
                dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
            }
        }
    }
    for (ll i=max_value-1;i>=0;i--){
        if (dp[i] != INF){
            cout << i;
            break;
        }
    }
}
int main()
{
    fast_cin();
    solve();
    cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return 0;
}