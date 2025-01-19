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
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((ll)(x).size())

// Modulo Calculation
ll add(ll x, ll y)
{
    return (x % MOD + y % MOD) % MOD;
}

ll sub(ll x, ll y)
{
    return ((x - y) % MOD + MOD) % MOD;
}

ll mul(ll x, ll y)
{
    return (long long)(x % MOD) *  (y % MOD) % MOD;
}

ll n,m;
vector<ll> a(11), dau(11);
ll cnt =0;

ll ch(){
    stack<pair<ll,ll>> st;
    st.push({a[0], 0});
    for (ll i=1;i < n;i++){
        if (dau[i] == 2){
            pair<ll,ll> t = st.top();
            st.pop();
            t.fi = t.fi * a[i] % m;
            st.push(t);
        }
        else st.push({a[i],dau[i]});
    }
    ll res = 0;
    while (!st.empty()){
        pair<ll,ll> t = st.top();
        st.pop();
        if (t.se == 0) res = (res + t.fi) % m;
        else res = (res - t.fi) % m;
    }
    return res;
}

void quaylui(ll i){
    if (i == n-1){
        if (ch() == 0) cnt++;
        return;
    }
    for (ll j = 0; j < 3;j++){
        dau[i+1] = j;
        quaylui(i+1);
    }
}

void solve(){
    ll t; cin >> t;
    while (t--){
        cnt = 0;  
        dau.clear(); 
        dau.resize(11);
        cin >> n >> m;
        for (ll i=0; i < n;i++) cin >> a[i];
        quaylui(0);
        cout << cnt << ln;
    }
}

int main()
{
    fast_cin();
    solve();
    return 0;
}
