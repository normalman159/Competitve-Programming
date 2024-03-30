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
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((ll)(x).size())
const ll LimN = 2e5+5;
ll n,q;

struct Node{
    ll val,lazy;
}; Node sg[4*LimN];

void down(ll id){
    ll la = sg[id].lazy;
    sg[id*2].lazy+=la;
    sg[id*2+1].lazy+=la;
    sg[id*2].val+=la;
    sg[id*2+1].val+=la;
    sg[id].lazy = 0;
}

void build(ll id, ll l, ll r, ll pos, ll va){
    if (pos > r || pos < l) return;
    if (l==r){
        sg[id].val = va;
        sg[id].lazy = 0;
        return;
    }
    ll mid = (l+r)/2;
    build(id*2,l,mid,pos,va);
    build(id*2+1,mid+1,r,pos,va);
}

void update(ll id,ll l, ll r, ll u, ll v, ll va){
    if (u > r || v < l) {
        return;
    }
    if (u <=l && v>=r){
        sg[id].val+=(r-l+1) * va;
        sg[id].lazy +=va;
        return;
    }
    down(id);   
    ll mid = (l+r)/2;
    update(id*2,l,mid,u,v,va);
    update(id*2+1,mid+1,r,u,v,va);
}

ll get(ll id, ll l, ll r, ll pos){
    if (pos < l || pos > r) return -1;
    if (l==r){
        return sg[id].val;
    }
    ll mid = (l+r)/2;
    down(id);
    return max(get(id*2,l,mid,pos) , get(id*2+1,mid+1,r,pos));
}

void solve(){
    cin >> n >> q;
    forn(i,n){
        ll x; cin >> x;
        build(1,1,n,i,x);
    }
    while (q--){
        ll ch; cin >> ch;
        if (ch==1){
            ll a,b,u; cin >> a >> b >> u;
            update(1,1,n,a,b,u);
        }
        else{
            ll k; cin >> k;
            cout << get(1,1,n,k) << ln;
        }
    }
}
 
 
int main()
{
    fast_cin();
    solve();
    return 0;
}