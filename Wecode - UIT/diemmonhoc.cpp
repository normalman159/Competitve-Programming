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

bool ch(double tb, ll n, vector<double> &cur, vector<ll> &A){
    double current_val = 0;
    double remaining_weight = 0;

    for (ll j = 0; j < cur.size(); j++){
        current_val += cur[j] * (double(A[j]) / 100.0);
    }

    for (ll j = cur.size(); j < n; j++){
        remaining_weight += (double(A[j]) / 100.0);
    }

    if (current_val + remaining_weight * 10.0 < tb - 0.05 - 1e-9) return false;
    if (current_val + remaining_weight * 0.25 >= tb + 0.05 - 1e-9) return false;
    return true;
}

void dq(ll i, ll n, double tb, vector<double> &cur, vector<ll> &A) {
    if (!ch(tb,n,cur,A)) return;

    if (i == n + 1){
        for (int k = 0; k < n; k++) {
                cout << cur[k] << " ";
            }
        cout << ln;
        return;
    }

    for (double j = 0.25; j <= 10.01; j+= gap){
        cur.pb(j);
        dq(i+1, n, tb, cur, A);
        cur.pop_back();
    }
    return;
}

void solve() {
    ll n; cin >> n;
    vector<ll> A(n);
    for (auto &x : A) cin >> x;
    vector<double> cur;
    double tb; cin >> tb;
    dq(1, n, tb, cur,A);
}

int main() {
  freopen("TASK.INP", "r", stdin);
  freopen("TASK.OUT", "w", stdout);
  fast_cin();
  solve();
  return 0;
}
