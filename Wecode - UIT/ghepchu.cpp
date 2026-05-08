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

ll dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
ll dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool ch(ll l, ll r, ll n, ll m) {
    if (l < 0 || r < 0 || l >= n || r >= m) return 0;
    return 1;
}

bool dq(ll i, ll j, ll ind, ll n, ll m, string &s, vector<vector<char>> &A, vector<vector<bool>> &cur) {
    if (A[i][j] != s[ind]) return false;
    if (ind == s.size() - 1) return true; 

    cur[i][j] = 1;

    for (ll k = 0; k < 8; k++){
        ll new_i = i + dx[k];
        ll new_j = j + dy[k];

        if (ch(new_i, new_j, n,m) && !cur[new_i][new_j]) {
            if (dq(new_i, new_j, ind + 1, n,m, s, A, cur)) {
                return true; 
            }
        }
    }
    cur[i][j] = 0;
    return false;
}

void solve() {
    string s; cin >> s;
    if (s.empty()){
        cout << "false"; return;
    }
    vector<vector<char>> A;
    string tmp;
    
    while (cin >> tmp && tmp != "."){
        vector<char> f;
        for (auto x : tmp) f.pb(x);
        A.pb(f);
    }

    ll n = A.size();
    ll m = A[0].size();
    vector<vector<bool>> cur(n, vector<bool>(m,false));

    for (ll i = 0; i < n; i++){
        for (ll j = 0; j < m; j++){
            if (A[i][j] == s[0]){
                if (dq(i,j,0, n, m, s, A, cur)){
                    cout << "true"; return;
                }
            }
        }
    } 
    cout << "false";
}

int main() {
  freopen("TASK.INP", "r", stdin);
  freopen("TASK.OUT", "w", stdout);
  fast_cin();
  solve();
  return 0;
}
