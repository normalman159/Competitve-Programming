//Link: https://codeforces.com/gym/530514/problem/B

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

const ll LimN = 5e4 + 5;
ll n,q;

struct node{
    ll ma, mi;
};
node seg[4*LimN];

node mer(node left, node right){
    node ans;
    ans.ma = max(left.ma , right.ma);
    ans.mi = min(left.mi , right.mi);
    return ans;
}

void update(ll id,ll l,ll r,ll pos, ll val){
    if (!(l<=pos && pos <=r)) return;
    if (l==r){
        seg[id] = {val, val}; return;
    }
    ll mid = (l+r)>>1;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    seg[id] = mer(seg[id*2] , seg[id*2+1]);
}

node get(ll id,ll l, ll r, ll u, ll v){
    if (u >r || v < l) return {-INF, INF};
    if (u<=l && r <= v) return seg[id];
    ll mid = (l+r)>>1;
    return mer(get(id*2,l,mid,u,v) , get(id*2+1,mid+1,r,u,v));
}

void solve(){
    cin >> n >> q;
    for (ll i=1;i<=n;i++){
        ll x; cin >> x;
        update(1,1,n,i,x);
    }
    while (q--){
        ll u,v; cin >> u >> v;
        node ans = get(1,1,n,u,v);
        cout << ans.ma - ans.mi << ln;
    }
}


int main()
{
    fast_cin();
    solve();
    return 0;
}
