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
#define fast_cin()                                                             \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((ll)(x).size())

// Modulo Calculation
ll add(ll x, ll y) { return (x + y) % MOD; }

ll sub(ll x, ll y) { return ((x - y) % MOD + MOD) % MOD; }

ll mul(ll x, ll y) { return (long long)x * y % MOD; }

void solve() {
    ll n; cin >> n;

    vector<vector<ll>> dp(n+5, vector<ll>(n+5,0));

    for (ll i = 1; i <= n; i++){
        for (ll j = 1; j <= n; j++){
            char t; cin >> t;
            if (t == '*'){
                dp[i][j] = 0;
            }
            else{
                if (i == 1 && j == 1)   dp[1][1] = 1;
                else dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            }

        }
    }

    cout << dp[n][n];

}

int main() {
  freopen("TASK.INP", "r", stdin);
  freopen("TASK.OUT", "w", stdout);
  fast_cin();
  solve();
  return 0;
}
