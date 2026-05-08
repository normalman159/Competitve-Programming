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


bool ch(ll &u, vector<ll> &MauDinh, vector<vector<bool>> &Dinh){

    for (ll v = 0; v < Dinh[u].size(); v++){
        if (Dinh[u][v]){
            if (MauDinh[v] != -1 && MauDinh[u] == MauDinh[v]) return false;
        }
    }

    return true;
}

void solve() {
    ll v,e; cin>>v>>e;

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

    // ll ANS = 0;

    for (ll i = 0; i < v; i++){
        bool fg = 0;

        for (ll m : tapMauDaDung) {
            MauDinh[i] = m;
            if (ch(i, MauDinh, Dinh)) {
                cout << m << " ";
                fg = true;
                break;
            }
        }

        ll k = 0;
        while(!fg){
            if (tapMauDaDung.count(k)){
                k++; continue;
            };
            MauDinh[i] = k;
            if (ch(i, MauDinh, Dinh)) {
                cout << k << " ";
                fg = 1;
                break;
            } 
            k++;
        }

    }

    
}

int main() {
  freopen("TASK.INP", "r", stdin);
  freopen("TASK.OUT", "w", stdout);
  fast_cin();
  solve();
  return 0;
}
