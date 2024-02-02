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

ll t, dp[103][103];
void solve(){
    cin >> t;
    for (ll i=1;i<=100;i++){
        for (ll j=1;j<=100;j++) dp[i][j] = INF;
    }
    dp[1][1] = 0;
    for (ll x=1;x<=100;x++){
        for (ll y=1;y<=100;y++){
            if (x == 1 && y==1) continue;
            dp[x][y] = min(dp[x][y-1]+x, dp[x-1][y]+y);
        }
    }
    while (t--){
        ll n,m,k; cin >> n >> m >> k;
        if (dp[n][m] == k){
            cout << "YES" << ln;
        }
        else cout << "NO" << ln;
    }
}
int main()
{
    fast_cin();
    solve();
    cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return 0;
}