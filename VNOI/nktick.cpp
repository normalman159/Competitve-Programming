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

const ll SIZE = 6e4 + 5;

ll n, dp[SIZE][2] = {INF}, t[SIZE], r[SIZE];

void solve()
{
    cin >> n;
    for (ll i = 0; i < n; i++){
        cin >> t[i];
    }
    for (ll i = 0; i < n-1; i++){
        cin >> r[i];
    }

    dp[0][0] = t[0];
    dp[0][1] = INF;
    dp[1][0] = t[0] + t[1];
    dp[1][1] = r[0];

    for (ll i = 2; i<n; i++){
        dp[i][0] = t[i] + min(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = r[i-1] + min(dp[i-2][0], dp[i-2][1]); 
    }
    cout << min(dp[n-1][0], dp[n-1][1]);
}

int main()
{
    
    freopen("TASK.INP", "r", stdin);
    freopen("TASK.OUT", "w", stdout);
    fast_cin();
    solve();
    return 0;
}
