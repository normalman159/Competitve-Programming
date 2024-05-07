#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const long long INF = 1e15;
const ll MOD = 1e9+7;
const double eps = 1e-12;
#define forn(i,e) for(ll i = 1; i <= e; i++)
#define forsn(i,s,e) for(ll i = s; i <= e; i++)
#define rforn(i,s) for(ll i = s; i >= 1; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define DEBUG(x) cout<<#x<<" = "<<x<<ln
#define pb push_back
#define fi first
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((ll)(x).size())

//Modulo Calculation
ll add(ll x, ll y){
    return (x + y) % MOD;
}

ll sub(ll x, ll y){
    return ((x - y) % MOD + MOD) % MOD;
}

ll mul(ll x, ll y){
    return (long long)x * y % MOD;
}

void sub1(ll n, vector<ll> &v){
    ll ans = -INF;
    for (ll i=1;i<=n;i++){
        for (ll j = i+1;j<=n;j++){
            for (ll k = j+1; k <=n;k++) {
                ans = max(ans, 3*v[i] + 2*v[j] - 5*v[k]);
            }
        }
    }
    cout << ans;
}

void sub2(ll n, vector<ll> &v){
    ll ans = -INF;
    vector<ll> v1(n+2,INF);
    for (ll i=1;i<=n;i++){
        for (ll j = i+1;j<=n;j++){
            v1[i] = min(v1[i], v[j]);
        }
    }
    for (ll i=1;i<=n;i++){
        for (ll j = i+1;j<=n;j++){
            ans = max(ans, 3*v[i] + 2*v[j] - 5*v1[j]);
        }
    }
    cout << ans;
}

const ll LimN = 1e6+5;
struct node{
    ll Max, Min;
}; node seg[4*LimN];
vector<ll> v(LimN);
void build(ll id, ll l, ll r){
    if (l == r){
        seg[id] = {v[l], v[l]};
        return;
    }
    ll mid = (l+r)/2;
    build(id*2, l ,mid);
    build(id*2+1,mid+1,r);
    seg[id].Max = max(seg[id*2].Max, seg[id*2+1].Max);
    seg[id].Min = min(seg[id*2].Min, seg[id*2+1].Min);
}

ll get_min(ll id, ll l, ll r, ll u , ll v){
    if (u > r || v < l){
        return INF;
    }
    if (u<=l && v >= r) return seg[id].Min;
    ll mid = (l+r)/2;
    return min(get_min(id*2,l,mid,u,v) , get_min(id*2+1,mid+1,r,u,v));
}

ll get_max(ll id, ll l, ll r, ll u , ll v){
    if (u > r || v < l){
        return -INF;
    }
    if (u<=l && v >= r) return seg[id].Max;
    ll mid = (l+r)/2;
    return max(get_max(id*2,l,mid,u,v) , get_max(id*2+1,mid+1,r,u,v));
}

void sub3(ll n, vector<ll> &v){
    ll ans = -INF;
    build(1,1,n);
    for (ll j=2;j<=n-1;j++){
        ll d1 = get_max(1,1,n,1,j-1);
        ll d2 = get_min(1,1,n,j+1,n);
        ans = max(ans, 3* d1 + 2*v[j] - 5*d2);
    }
    cout << ans;
}

void solve(){
    ll n; cin >> n;
    for (ll i=1;i<=n;i++) cin >> v[i];
    if (n<=100){
        sub1(n,v);
    }
    else if (n<=5e3){
        sub2(n,v);
    }
    else{
        sub3(n,v);
    }
}


int main()
{
//    freopen("BOBASO.INP","r",stdin);
//    freopen("BOBASO.OUT", "w", stdout);
    fast_cin();
    solve();
    return 0;
}

