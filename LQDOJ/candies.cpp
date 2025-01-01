//https://lqdoj.edu.vn/problem/candies

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

const ll LimN = 1e6 + 5;
ll arr[LimN], seg[4 * LimN], n,m, laz[4*LimN];

void build(ll id,ll l, ll r){
    if (l==r){
        seg[id] = arr[l]; return;
    }
    ll mid = (l+r)>>1;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    seg[id] = max(seg[id*2],seg[id*2+1]);
}

void update(ll id, ll l, ll r, ll u, ll v){
    if (u > r || v < l) return;
    if (u<=l && r <= v){
        seg[id]--;
        laz[id]--;
        return;
    }
    ll mid = (l+r)>>1;
    if (laz[id]){
        laz[id*2] += laz[id];
        laz[id*2+1] += laz[id];
        seg[id*2] += laz[id];
        seg[id*2+1] += laz[id];
        laz[id] = 0;
    }
    update(id*2,l,mid,u,v);
    update(id*2+1,mid+1,r,u,v);
    seg[id] = max(seg[id*2],seg[id*2+1]);
}

ll get(ll id, ll l, ll r, ll k){
    if (laz[id]){
        laz[id*2] +=laz[id];
        laz[id*2+1] += laz[id];
        seg[id*2] +=laz[id];
        seg[id*2+1] +=laz[id];
        laz[id] = 0;
    }
    ll mid = (l+r)>>1;
    if (seg[id] < k) return n+1;
    if (l==r) return l;
    if (seg[id*2]>=k) return get(id*2,l,mid,k);
    else return get(id*2+1,mid+1,r,k);
}

void solve(){
    cin >> n;
    for (ll i=1;i<=n;i++) cin >> arr[i];
    sort(arr,arr+1+n);
    build(1,1,n);
    cin >> m;
    while (m--){
        ll t; cin >> t;
        ll z = get(1,1,n,t);
        cout << n - z + 1 << ln;
        update(1,1,n,z,n);
    }
}


int main()
{
    fast_cin();
    solve();
    return 0;
}

