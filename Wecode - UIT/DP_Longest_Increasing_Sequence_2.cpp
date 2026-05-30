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
    
    vector<ll> v(n+5,0), dp(n+5,0), p(n+5, -1);

    for (ll i =0 ; i < n; i++){
        cin >> v[i];
    }
    ll ans = 0;

    for (ll i = 0; i < n; i++){
        ll left = 1, right = ans, l = ans + 1;
        while (left <= right){
            ll mid = (left + right) >> 1;
            if (v[dp[mid]] >= v[i]){
                right = mid - 1;
                l = mid;
            }
            else{
                left = mid + 1;
            }
        }

        if (l > 1){
            p[i] = dp[l - 1];
        }
        else {
            p[i] = -1;
        }

        dp[l] = i;
        ans = max(ans, l);
    }
    
    cout << ans << ln;

    vector<ll> trace;
    ll c = dp[ans];
    while (c != -1){
        trace.pb(v[c]);
        c = p[c];
    }

    reverse(ALL(trace));
    for (auto &c : trace) cout << c << " ";

}

int main() {
  freopen("TASK.INP", "r", stdin);
  freopen("TASK.OUT", "w", stdout);
  fast_cin();
  solve();
  return 0;
}
