#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const long long INF = 1e15;
const ll MOD = 998244353;
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

const ll SIZE = 5e5 +5;
const ll LG = 20;

struct Node{
    ll target, id;
};

ll n, m;
vector<vector<Node>> adj(SIZE);
vector<ll> color(SIZE, 0);
vector<Node> parent(SIZE, {-1,-1});
vector<ll> cycle_edges, vertices;

//DFS + Chu trinh tren do thi vo huong

bool dfs(ll u, ll parent_id = -1){
    color[u] = 1;
    for (auto edge : adj[u]){
        ll v = edge.target, id = edge.id;
        if (id == parent_id) continue;

        if (color[v] == 0){
            parent[v] = {u, id};
            if (dfs(v, id)) return true;
        }
        else if (color[v] == 1){
            cycle_edges.push_back(id);
            vertices.push_back(u);
            
            ll curr = u;
            while (curr != v){
                cycle_edges.push_back(parent[curr].id);
                curr = parent[curr].target;
                vertices.push_back(curr);
            }
            reverse(ALL(cycle_edges));
            reverse(ALL(vertices));
            return true;
        }

    }
    color[u] = 2;
    return false;
}

void solve()
{
    cin >> n >> m;
    for (ll i= 0; i < m; i++){
        ll u, v; cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    for (ll i = 0; i < n; i++) {
        if (color[i] == 0) {
            if (dfs(i)) {
                cout << cycle_edges.size() << "\n";
                for (ll vec : vertices){
                    cout << vec << " ";
                }
                cout << ln;
                for (ll edge_id : cycle_edges) {
                    cout << edge_id << " ";
                }
                return;
            }
        }
    }

    cout << "-1" << ln;
}

int main()
{
    freopen("TASK.INP", "r", stdin);
    freopen("TASK.OUT", "w", stdout);
    fast_cin();
    solve();
    return 0;
}
