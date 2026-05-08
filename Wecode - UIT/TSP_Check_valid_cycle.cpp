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

ll ch(vector<char> &v, map<char, map<char, ll>> &st){
    ll ans = 0;
    if (v.empty()) return 0;
    ll n = v.size();

    for (ll i = 0; i < n-1; i++){
        auto ite = st.find(v[i]);
        if (ite == st.end()) return -1;

        auto ite1 = ite->second.find(v[i+1]);
        if (ite1 == ite->second.end()) return -1;

        ans += ite1->second;
    }


    return ans;
}

void solve() {
    ll e, n; cin >> e >> n;
    map<char, map<char, ll>> st;

    for (ll i = 0; i < e; i++){
        char u, v; ll x;
        cin >> u >> v >> x;
        
        st[u][v] = x;
    }

    for (ll i = 0; i < n; i++){
        vector<char> v;
        char tmp;
        while (cin >> tmp && tmp != '.') {
            v.pb(tmp);
        }

        ll ans = ch(v, st);
        if (ans == -1){
            cout << "FALSE" << ln;
        }
        else cout << ans << ln;
    }
}

int main() {
  freopen("TASK.INP", "r", stdin);
  freopen("TASK.OUT", "w", stdout);
  fast_cin();
  solve();
  return 0;
}
