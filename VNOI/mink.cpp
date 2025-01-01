//Link: https://oj.vnoi.info/problem/mink

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

const ll limN = 1e6 + 5;

ll t, n, k, arr[limN], seg[4*limN];

void update(ll id,ll l, ll r, ll pos, ll val){
    if (pos < l || pos > r) return;
    if (l==r){
        seg[id] = val;
        return;
    }
    ll mid = (l+r)/2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    seg[id] = min(seg[id*2] , seg[id*2+1]);
}

ll get(ll id, ll l, ll r, ll u, ll v){
    if (u > r || v < l) return INF;
    if (u <= l && r <=v) return seg[id];
    ll mid = (l+r)/2;
    return min(get(id*2,l,mid,u,v) , get(id*2+1,mid+1,r,u,v));
}

void solve(){
    cin >> t;
    while (t--){
        cin >> n >> k;
        for (ll i=1; i<=n;i++){
            ll f; cin >> f;
            update(1,1,n,i,f);
        }
        for (ll i=1;i<= (n-k+1); i++){
            cout << get(1,1,n,i,k+i-1) << ' ';
        }
        cout << ln;
    }
}


int main()
{
    fast_cin();
    solve();
    return 0;
}
