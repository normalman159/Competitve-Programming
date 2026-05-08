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
    ll e; string s; cin >> e >> s;
    map<string, vector<pair<string, ll>>> st;

    for (ll i = 0; i < e; i++){
        string u, v; ll x;
        cin >> u >> v >> x;
        
        st[u].push_back({v,x});
    }
    for (auto &c : st){
        sort(c.second.begin(), c.second.end(), [](pair<string, ll> &a, pair<string, ll> &b){
            return a.second < b.second;
        });
    }
    ll n = st.size();

    map<string, bool> v;
    v[s] = 1;
    vector<string> p;
    p.pb(s);

    string q = s;

    while(p.size() < n){
        for(auto &c : st[q]){
            if (v[c.first] == 1) continue;
            q = c.first;
            p.pb(q);
            v[q] = 1;
            break;   
        }
    }
    p.pb(s);
    for (auto &c : p){
        cout << c << " ";
    }
}

int main() {
  freopen("TASK.INP", "r", stdin);
  freopen("TASK.OUT", "w", stdout);
  fast_cin();
  solve();
  return 0;
}
