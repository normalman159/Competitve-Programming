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

ll MI = 1e6;



void dq(string s, ll w, string ini, vector<string> &path, vector<string> &ANS, map<string, vector<pair<string, ll>>> &st, map<string, bool> &mp){
    if (path.size() == st.size()){
        if (MI < w) return;
        if (path.back() != ini) return;
        ANS.assign(ALL(path));
        MI = w;
        return;
    }

    if (w > MI) return;

    for (auto &v : st[s]){
        if (mp[v.first] == 1) continue;

        path.push_back(v.first);
        mp[v.first] = 1;
        w += v.second;
        // DEBUG(w);
        dq(v.first, w, ini, path,ANS , st,mp);

        path.pop_back();
        mp[v.first] = 0;
        w -= v.second;
    }
}

void solve() {
    ll e; string s; cin >> e >> s;
    map<string, vector<pair<string, ll>>> st;

    map<string, bool> mp;

    for (ll i = 0; i < e; i++){
        string u, v; ll x;
        cin >> u >> v >> x;
        
        st[u].push_back({v,x});
    }
    
    vector<string> path;
    vector<string> ANS;
    dq(s, 0,s , path, ANS, st, mp);
    cout << s << " ";
    for (auto &c : ANS){
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
