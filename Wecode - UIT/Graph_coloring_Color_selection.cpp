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


bool ch(string &s, vector<ll> &MauDinh, vector<vector<bool>> &Dinh, map<string, ll> &id){
    ll u = id[s];

    for (ll v = 0; v < Dinh[u].size(); v++){
        if (Dinh[u][v]){
            if (MauDinh[v] != -1 && MauDinh[u] == MauDinh[v]) return false;
        }
    }

    return true;
}

void solve() {
    ll v,e, n; cin>>v>>e >> n;

    vector<ll> MauDinh(v,-1);
    vector<vector<bool>> Dinh(v, vector<bool>(v, false));
    map<string, ll> id;
    set<ll> tapMauDaDung;

    for (ll i =0 ; i < v; i++){
        string tmp; cin >> tmp;
        id[tmp] = i;
    }

    for (ll i =0 ; i < e; i++){
        string tmp, tmp1; cin >> tmp >> tmp1;
        Dinh[id[tmp]][id[tmp1]] = 1;
        Dinh[id[tmp1]][id[tmp]] = 1;
    }

    for (ll i =0 ; i < v; i++){
        ll tmp; cin >> tmp;
        MauDinh[i] = tmp;
        if (tmp != -1) tapMauDaDung.insert(tmp);
    }

    for (ll i =0 ; i< n; i++){
        string tmp; cin >> tmp;
        ll u = id[tmp];
        ll old = MauDinh[u];
        if (MauDinh[u] != -1 && ch(tmp, MauDinh, Dinh, id)){
            cout << "TRUE" << ln; continue;
        }
        bool fg = 0;
        
        for (ll m : tapMauDaDung) {
            MauDinh[u] = m;
            if (ch(tmp, MauDinh, Dinh, id)) {
                cout << m << endl;
                fg = true;
                break;
            }
        }

        ll k = 0;
        while(!fg){
            if (tapMauDaDung.count(k)){
                k++; continue;
            };
            MauDinh[u] = k;
            if (ch(tmp, MauDinh, Dinh, id)) {
                cout << k << endl;
                fg = 1;
                break;
            } 
            k++;
        }
        MauDinh[u] = old;
    }
}

int main() {
  freopen("TASK.INP", "r", stdin);
  freopen("TASK.OUT", "w", stdout);
  fast_cin();
  solve();
  return 0;
}
