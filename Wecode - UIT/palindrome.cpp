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


bool ch(string &s, ll l, ll r) {
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

void dq(ll lastid, ll n, string &s, vector<bool> &cur) {
    if (lastid == n){
        if (!ch(s,lastid, n-1)){
            return;
        }
        for (ll k = 0; k < n; k++){
            cout << s[k];
            if (cur[k]== 1) cout << " ";
        }
        cout << ln;
        return;
    }
    for (ll j = lastid; j < n; j++) {
        if (ch(s, lastid, j)){
            cur[j] = 1;
            dq(j+1, n, s, cur);
            cur[j] = 0;
        }
    }
}

void solve() {
  string s; cin >> s;
  ll n = s.size();
  vector<bool> cur(n, false);
  dq(0, n, s, cur);
}

int main() {
  freopen("TASK.INP", "r", stdin);
  freopen("TASK.OUT", "w", stdout);
  fast_cin();
  solve();
  return 0;
}
