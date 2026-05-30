#include <bits/stdc++.h>

using namespace std;

typedef int ll;
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

const ll MAX = 2e5 + 5, I = 20;

ll up[MAX][20];
vector<ll> adj[MAX];
ll doSau[MAX];

void init(ll root){
    queue<ll> q;
    vector<ll> order;

    doSau[root] = 0;
    up[root][0] = root;

    for (ll i = 1; i < I; i++){
        up[root][i] = up[up[root][i-1]][i-1];
    }

    q.push(root);

    while(!q.empty()){
        ll u = q.front();
        q.pop();
        order.pb(u);

        for (ll v : adj[u]){
            if (v == up[u][0]) continue;

            doSau[v] = doSau[u] + 1;
            up[v][0] = u;

            q.push(v);
        } 
    }
    for (ll t : order){
        for (ll i = 1; i < I; i++){
            up[t][i] = up[up[t][i-1]][i-1];
        }
    }

}

ll get(ll u, ll v){
    if (doSau[u] < doSau[v]) swap(u, v);

    ll diff = doSau[u] - doSau[v];
    for (ll i = I-1; i >= 0; i--){
        if ((diff >> i) & 1) {
            u = up[u][i];
        }
    }

    if (u == v) return u;

    for (ll i = I-1; i >= 0; i--){
        if (up[u][i] != up[v][i]){
            u = up[u][i];
            v = up[v][i];
        }
    }

    return up[u][0];
}

void solve() {
    ll n, q; cin >> n >> q;
    for (ll i = 0; i < n-1; i++){
        ll t1, t2; cin >> t1 >> t2; 
        adj[t1].emplace_back(t2);
        adj[t2].emplace_back(t1);
    }

    init(1);
    ll t1, t2;
    while (q--){
         cin >> t1 >> t2;

        ll lca = get(t1, t2);

        cout << (ll)doSau[t1] + doSau[t2] - 2*doSau[lca] << ln;
    }
}

int main() {
  freopen("TASK.INP", "r", stdin);
  freopen("TASK.OUT", "w", stdout);
  fast_cin();
  solve();
  return 0;
}
