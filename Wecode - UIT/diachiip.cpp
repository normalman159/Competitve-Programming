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


bool ch(string &s, ll l, ll r){
    if (r - l + 1 > 3 || r < l) return 0;
    if (r - l + 1 >= 2 && s[l] == '0') return 0;
    string tmp;
    for (ll i = l; i <= r; i++){
        tmp += s[i];
    }
    if (stoll(tmp) > 255) return 0;
    return 1;
}

void dq(ll count, ll lastid, ll n, string &s, vector<bool> &cur) {
  if (count == 0) {
    if (!ch(s,lastid, n-1)) return; 
    for (ll k = 0; k < n; k++) {
        cout << s[k];
        if (cur[k] == 1) cout << '.';
    }
    cout << ln;
    return;
  }
  for (ll j = lastid; j < min(lastid + 3, n); j++) {
    if (cur[j]) continue;
    
    if (ch(s, lastid, j)){
        cur[j] = 1;
        dq(count-1, j+1, n, s, cur);
        cur[j] = 0;
    }
  }
}

void solve() {
  string s; cin >> s;
  ll n = s.size();
  vector<bool> cur(n, false);
  dq(3, 0, n, s, cur);
}

int main() {
  freopen("TASK.INP", "r", stdin);
  freopen("TASK.OUT", "w", stdout);
  fast_cin();
  solve();
  return 0;
}
