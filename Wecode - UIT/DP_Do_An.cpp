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

struct OBJ{
    ll a, b, p;
};


ll bn(vector<OBJ> &v, ll &n, ll val){
    ll l = 0, r = n-1, ans = -1;

    while (l <= r){
        ll mid = (l + r) >> 1;

        if (v[mid].b < val){
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return ans;
}

void solve() {
    ll n; cin >> n;
    vector<OBJ> v(n);

    for (auto &c : v){
        cin >> c.a >> c.b >> c.p;
    }
    sort(v.begin(), v.end(), [](OBJ &x, OBJ &y){
        return x.b < y.b;
    });

    vector<ll> DP(n+5, 0);
    for (ll i = 0; i < n; i++){
        ll j = bn(v,n, v[i].a); // j < i
        ll chon = v[i].p;
        if (j != -1){
            chon += DP[j];
        }
        if (i == 0) DP[i] = chon;
        else DP[i] = max(DP[i-1], chon);

    }
    cout << DP[n-1];
}

int main() {
  freopen("TASK.INP", "r", stdin);
  freopen("TASK.OUT", "w", stdout);
  fast_cin();
  solve();
  return 0;
}
