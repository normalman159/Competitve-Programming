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

ll dx[4] = {-1, 1, 0, 0};
ll dy[4] = {0, 0, -1, 1};

bool ch_1(ll i, ll j, ll n, ll m, vector<vector<ll>> &A){
    for (ll k = 0; k < 4; k++){
        ll nx = i + dx[k];
        ll ny = j + dy[k];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (A[nx][ny] <= 0) return false;
        }
    }
    return true;
}

bool ch_2(ll i, ll j, ll n, ll m, vector<vector<ll>> &A){
    // i,j -> i, j-1 
    if (j > 0){
        ll val = A[i][j-1];
        if (i == n-1 && val != 0) return false;
        if (i < n-1 && (val < 0 || val > 1)) false;
    }
    if (j == m- 1){
        ll val = A[i][j];
        if (i == n-1 && val != 0) return false;
        if (i < n-1 && (val < 0 || val > 1)) false;
    }
    return true;
}

bool dq(ll i, ll j, ll &n, ll &m, ll &sum_A,vector<vector<ll>> &A, vector<vector<bool>> &B) {
    if (i == n) {
        return sum_A == 0;
    }

    ll val = -1;
    
    ll n_i = (j == m - 1) ? i + 1 : i;
    ll n_j = (j == m - 1) ? 0 : j + 1;
    
    if (i > 0){
        val = A[i-1][j];
    }

    if (val > 1) return false;

    if ((val == -1 || val == 0)){
        if (dq(n_i, n_j, n, m, sum_A, A, B)) return true;
    }

    if (ch_1(i,j,n,m,A)){
        B[i][j] = 1;
        for (ll k = 0; k < 4; k++){
            ll nx = i + dx[k]; ll ny = j + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                A[nx][ny]--;
                sum_A--;
            }
        }
        if (ch_2(i,j,n,m,A)){
            if (dq(n_i, n_j, n, m, sum_A, A, B)) return true;
        }
        
        B[i][j] = 0;
        for (ll k = 0; k < 4; k++) {
            ll nx = i + dx[k], ny = j + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                A[nx][ny]++;
                sum_A++;
            }
        }
    }
    
    return false;
}

void solve() {
    ll n, m; cin >> n >> m;
    bool fg = 0;
    if (m > n){
        fg = 1;
        swap(n,m);
    }
    ll sum_A = 0;
    vector<vector<ll>> A(n, vector<ll>(m));
    for (ll i = 0; i < (fg ? m : n); i++){
        for (ll j = 0; j < (fg ? n : m); j++){
            if (fg){
                cin >> A[j][i];
            }
            else cin >> A[i][j];
            sum_A += (fg ? A[j][i] : A[i][j]);
        }
    }
    vector<vector<bool>> B(n, vector<bool>(m, 0));
    if (dq(0,0, n,m,sum_A, A,B)){
        for (ll i = 0; i < (fg ? m : n); i++){
            for (ll j = 0; j < (fg ? n : m); j++){
                if (fg){
                    cout <<  B[j][i] << " ";
                }
                else cout <<  B[i][j] << " ";
            }
            cout << ln;
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
