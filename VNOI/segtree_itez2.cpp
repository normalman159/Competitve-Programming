//Link: https://oj.vnoi.info/problem/segtree_itez2

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

const ll maxN = 1e5;

ll n,m, seg[4*maxN + 5], arr[maxN + 5];


void update(ll id, ll l, ll r, ll pos, ll val){
    if (pos < l || pos >r) return;
    if (l == r){
      seg[id] = val;
      return;
    }
    ll mid = (l+r)/2;
    update(id*2, l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    seg[id] = seg[id*2] + seg[id*2+1];
}

ll get(ll id, ll l, ll r, ll u, ll v){
    if (u > r || v < l) return 0;
    if (u <= l && r <= v) return seg[id];
    ll mid = (l+r)/2;
    return get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v);
}

void solve(){
    cin >> n >> m;

    for (ll i = 1;i<=n;i++) update(1,1,n,i,0);

    while (m--){
        ll ch; cin >> ch;
        if (ch==1){
            ll x,y; cin >> x >> y;
            update(1,1,n,x,y);
        }
        else{
            ll l,r; cin >> l >> r;
            cout << get(1,1,n,l,r) << ln;
        }
    }
}


int main()
{
    fast_cin();
    solve();
    return 0;
}
