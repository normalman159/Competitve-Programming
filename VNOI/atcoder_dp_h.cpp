#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const long long INF = 1e15;
const ll MOD = 1e9 + 7;
const double eps = 1e-12;
#define forn(i, e) for (ll i = 1; i <= e; i++)
#define forsn(i, s, e) for (ll i = s; i <= e; i++)
#define rforn(i, s) for (ll i = s; i >= 1; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define DEBUG(x) cout << #x << " = " << x << ln
#define pb push_back
#define fi first
#define se second
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((ll)(x).size())

// Modulo Calculation
ll add(ll x, ll y)
{
    return (x + y) % MOD;
}

ll sub(ll x, ll y)
{
    return ((x - y) % MOD + MOD) % MOD;
}

ll mul(ll x, ll y)
{
    return (long long)x * y % MOD;
}

const ll SIZE = 1e3 + 5;

ll H, W, dp[SIZE][SIZE] = {0}, g[SIZE][SIZE] = {0};

void solve()
{
    cin >> H >> W;
    for (ll i = 1; i <= H; i++){
        for (ll j = 1; j <= W; j++){
            char t; cin >> t;
            if (t == '#') g[i][j] = 0;
            else g[i][j] = 1; //di duoc
        }
    }
    dp[1][1] = 1;
    // DEBUG(dp[1][3]);
    for (ll i = 1; i <= H; i++){
        for (ll j = 1; j <= W; j++){
            if (i == 1 && j == 1) continue;
            if (g[i][j] == 0) continue;
            dp[i][j] = add(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[H][W] % MOD;
}

int main()
{
    
    freopen("TASK.INP", "r", stdin);
    freopen("TASK.OUT", "w", stdout);
    fast_cin();
    solve();
    return 0;
}
