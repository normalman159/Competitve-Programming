#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const long long INF = 1e15;
const ll MOD = 1e9+7;
const double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

ll n,m,a[MXN], b[MXN];
void solve(){
    cin >> n >> m;
    for (ll i=1;i<=n;i++){
        cin >> a[i];
        b[a[i]] = i;
    }
    ll res = 0;
    for (ll i=1;i<=n;i++){
        res+= (b[i] > b[i+1]);
    }
    set<pair<ll,ll>> update;
    while (m--){
        ll u,v; cin >> u >> v;
        if (a[u] + 1 <=n){
            update.insert({a[u],a[u]+1});
        }
        if (a[u]-1>=1){
            update.insert({a[u]-1,a[u]});
        }
        if (a[v]+1 <=n){
            update.insert({a[v], a[v]+1});
        }
        if (a[v]-1 >=1){
            update.insert({a[v]-1,a[v]});
        }
        for (auto f : update){
            res -= (b[f.first] > b[f.second]);
        }
        swap(a[u], a[v]);
        b[a[u]] = u;
        b[a[v]] = v;
        for (auto f : update){
            res += (b[f.first]  > b[f.second]);
        }
        cout << res << ln;
        update.clear();
    }
}
int main()
{
    fast_cin();
    solve();
    cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return 0;
}