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

void solve() {
    ll n,m; cin >> n >> m;
    vector<pair<ll, ll>> v(n); //duration, id
    vector<ll> ans(n), d(n);
    for (ll i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i;
        d[i] = v[i].first;
    }
    sort(v.begin(), v.end(), [](pair<ll,ll> &a, pair<ll,ll> &b){
        return a.first > b.first;
    });
    
    // load,machine id
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    for (ll i = 0; i < m; i++) {
        pq.push({0, i});
    }

    for (ll i =0 ; i < n; i++){
        pair<ll,ll> q = pq.top();
        pq.pop();

        ans[v[i].second] = q.second;
        q.first += v[i].first;
        pq.push(q);
    }

    vector<ll> q(m,0);
    for (ll i =0; i < n; i++){
        q[ans[i]] += d[i];
    }
    bool fg = true;

    while (fg){
        fg = false;
        ll mi = 0, ma = 0;

        for (ll i=0; i < m; i++){
            if (q[i] > q[ma]) ma = i;
            if (q[i] < q[mi]) mi = i;
        }

        for (ll i = 0; i < n; i++){
            if (ans[i] != ma) continue;

            ll new_max = q[ma] - d[i];
            ll new_min = q[mi] + d[i];

            if (max(new_max, new_min) < q[ma]){
                q[ma] = new_max;
                q[mi] = new_min;
                ans[i] = mi;
                fg = true;
                break;
            }

        }
    }

    for (auto &c : ans){
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
