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

const ll LimN = 1e5  +5;
ll n, m;

struct node {
    ll one, zero;
};
node seg[4*LimN];

node mer(node left, node right){
    return {left.one + right.one , left.zero + right.zero};
}

void build(ll id,ll l, ll r, ll pos){
    if (!(l<=pos && pos <=r)) return;
    if (l==r){
        seg[id] = {0,1}; return;
    }
    ll mid = (l+r)>>1;
    build(id*2,l,mid,pos);
    build(id*2+1,mid+1,r,pos);
    seg[id] = mer(seg[id*2] , seg[id*2+1]);
}

void update(ll id, ll l, ll r,ll u, ll v ){
    if (u > r || v < l) return;
    if (l==r){
        ll tmp = seg[id].one;
        seg[id].one = seg[id].zero;
        seg[id].zero = tmp;
        return;
    }
    ll mid = (l+r)/2;
    update(id*2,l,mid,u,v);
    update(id*2+1,mid+1,r,u,v);
    seg[id] = mer(seg[id*2] , seg[id*2+1]);
}

ll get(ll id,ll l, ll r, ll u, ll v){
    if (u > r || v < l) return 0;
    if (u<=l && r <= v) return seg[id].one;
    ll mid = (l+r)>>1;
    return get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v);
}

void solve(){
    cin >> n >> m;
    for (ll i = 1; i<=n;i++) build(1,1,n,i);
    while (m--){
        ll ch, s, e; cin >> ch >> s >> e;
        if (ch==0){
            update(1,1,n,s,e);
        }
        else{
            cout << get(1,1,n,s,e) << ln;
        }
    }
}


int main()
{
    fast_cin();
    solve();
    return 0;
}
