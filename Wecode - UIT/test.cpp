#include <bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define pb push_back
#define nl cout << "\n";
#define sz(a) (int)(a).size()
#define mem(a, b) memset((a), (b), sizeof((a)))
#define all(c) (c).begin(), (c).end()
#define file "TASK"
using namespace std;

template <class T1, class T2>
void mini(T1 &a, T2 b)
{
    if (a > b)
        a = b;
}
template <class T1, class T2>
void maxi(T1 &a, T2 b)
{
    if (a < b)
        a = b;
}
const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int N = 3e5 + 5;
const int LOG = 20;

int sub, n, m, q;
int h[N], par[N][LOG + 5];
ll d[N];
vector<pll> adj[N];

void inp()
{
    cin >> n >> q;
    m = n - 1;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        ll w = 1;
        cin >> u >> v;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
}

void dfs(int u)
{
    for (auto it : adj[u])
    {
        int v = it.fi;
        ll w = it.se;
        if (v != par[u][0])
        {
            par[v][0] = u;
            d[v] = d[u] + w;
            h[v] = h[u] + 1;
            dfs(v);
        }
    }
}

void prepare()
{
    dfs(1);
    for (int j = 1; j <= LOG; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            par[i][j] = par[par[i][j - 1]][j - 1];
        }
    }
    h[0] = -1;
}

int lca(int u, int v)
{
    if (h[u] < h[v])
        return lca(v, u);

    for (int i = LOG; i >= 0; i--)
    {
        if (h[par[u][i]] >= h[v])
            u = par[u][i];
    }

    if (u == v)
        return u;

    for (int i = LOG; i >= 0; i--)
    {
        if (par[u][i] != par[v][i])
        {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

void solve()
{
    prepare();
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        cout << d[x] + d[y] - 2 * d[lca(x, y)] << "\n";
    }
}

void run_with_file()
{
    if (fopen(file ".inp", "r"))
    {
        freopen(file ".inp", "r", stdin);
        freopen(file ".out", "w", stdout);
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    run_with_file();
    inp();
    solve();
}