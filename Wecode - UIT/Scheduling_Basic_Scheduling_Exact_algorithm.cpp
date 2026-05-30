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

bool dq(ll i, ll &n, ll &m, ll &MAX, vector<pair<ll, ll>> &v, vector<ll> &t,  vector<ll> &tmp,vector<ll> &ans){
    if (i == n){
        ans = tmp;
        return 1;
    }

    for (ll j = 0; j < m; j++){
        if (t[j] + v[i].first > MAX) continue;

        t[j] += v[i].first;

        tmp[v[i].second] = j;

        if (dq(i+1,n,m,MAX,v,t, tmp, ans)) return 1;

        t[j] -= v[i].first;
        tmp[v[i].second] = -1;
    }

    return 0;
}

void solve() {
    ll n,m; cin >> n >> m;
    vector<pair<ll, ll>> v(n); //duration, id
    vector<ll> ans(n), tmp(n,-1), t(m, 0);

    ll tgianMax = -INF,  tgianTong = 0;

    for (ll i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i;
        tgianMax = max(tgianMax, v[i].first);
        tgianTong += v[i].first;
    }
    sort(v.begin(), v.end(), [](pair<ll,ll> &a, pair<ll,ll> &b){
        return a.first > b.first;
    });

    ll l = max(tgianMax, (tgianTong + m - 1)/m) , r = tgianTong;

    ll time_ans = 0;

    while (l <= r){
        ll mid = (l + r) >> 1;
        t.assign(m, 0);
        if (dq(0,n,m,mid,v,t,tmp,ans)){
            time_ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }

    dq(0,n,m,time_ans,v,t,tmp, ans);

    for (auto &c : ans) cout << c << " ";
}

int main() {
  freopen("TASK.INP", "r", stdin);
  freopen("TASK.OUT", "w", stdout);
  fast_cin();
  solve();
  return 0;
}
