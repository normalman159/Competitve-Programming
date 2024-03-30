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
ll n,q, BIT[LimN],sg[4*LimN];
void update(ll id, ll l, ll r, ll pos, ll val){
    if (pos < l || pos > r){
        return ;
    }
    if (l == r){
        sg[id] = val;
        return;
    }
    ll mid = (l+r)/2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    sg[id] = sg[id*2] + sg[id*2+1];
}

ll getsum(ll id,ll l, ll r, ll u , ll v){
    if (u > r || v < l) return 0;
    if (u <= l && v>=r){
        return sg[id];
    }
    ll mid = (l+r)/2;
    return getsum(id*2,l,mid,u,v) + getsum(id*2+1,mid+1,r,u,v);
}

void solve(){
    cin >> n >> q;
    for (ll i=1;i<=n;i++){
        ll x; cin >> x;
        update(1,1,n,i,x);
    }
    while (q--){
        ll ch; cin >> ch;
        if (ch==1){
            ll k,u; cin >> k >> u;
            update(1,1,n,k,u);
        }
        else{
            ll a,b; cin >> a >>b;
            cout << getsum(1,1,n,a,b) << ln;
        }
    }
}
 
 
int main()
{
    fast_cin();
    solve();
    return 0;
}