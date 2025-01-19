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

ll n, a[MXN];
ll dp[MXN];
void solve1(){
    cin >> n;
    for (ll i=1;i<=n;i++){
        cin >> a[i];
    }
    fill(dp+1,dp+1+n,INF);
    dp[1] = 0;
    for (ll i=1;i<n;i++){
        dp[i+1] = min(dp[i+1], dp[i] + abs(a[i] - a[i+1]));
        if (i+2 <=n){
            dp[i+2] = min(dp[i+2], dp[i] + abs(a[i] - a[i+2]));
        }
    }
    cout << dp[n];
}

void solve2(){
    cin >> n;
    for (ll i=1;i<=n;i++){
        cin >> a[i];
    }
    fill(dp+1,dp+1+n,INF);
    dp[1] =0;
    for (ll i=2;i<=n;i++){
        dp[i] = min(dp[i-1] + abs(a[i] - a[i-1]), dp[i]);
        if (i-2 > 0){
            dp[i] = min(dp[i-2] + abs(a[i] - a[i-2]), dp[i]);
        }
    }
    cout << dp[n];
}

int main()
{
    fast_cin();
    solve2();
    cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return 0;
}