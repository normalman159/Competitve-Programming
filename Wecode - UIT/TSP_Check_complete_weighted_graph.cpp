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

double gap = 0.25;

bool ch(ll i, ll j, ll q, vector<vector<ll>> &A){
    for (ll f = 0; f < 9; f++){
        if (A[f][j] == q) return 0;
        if (A[i][f] == q) return 0; 
        if (A[3*(i/3) + f/3][3*(j/3) + f%3] == q) return 0;
    }
    return 1;
}

bool dq(vector<vector<ll>> &A) {
    for (ll i = 0; i < 9; i++){
        for (ll j = 0; j < 9; j++){
            if (A[i][j] != -1) continue;
            
            for (ll q = 1; q <= 9; q++){
                if (!ch(i,j,q,A)) continue;
                A[i][j] = q;
                if (dq(A)) return true;
                A[i][j] = -1;
            }
            return false;
        }
        
    }
    return true;
}

void solve() {
    ll e; cin >> e;
    set<pair<string,string>> st;
    set<string> ve; 

    for (ll i = 0; i < e; i++){
        string u, v;
        cin >> u >> v;
        st.insert({u,v});
        ve.insert(u); ve.insert(v);
    }
    ll n = ve.size();

    if (st.size() != n*(n-1)){
        cout << "FALSE"; return;
    }
    for (auto s : st){
        if (st.find({s.second, s.first}) == st.end()){
            cout << "FALSE"; return;
        }
    }

    cout << "TRUE";
}

int main() {
  freopen("TASK.INP", "r", stdin);
  freopen("TASK.OUT", "w", stdout);
  fast_cin();
  solve();
  return 0;
}
