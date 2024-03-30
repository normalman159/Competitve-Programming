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
const ll LimN = 2e5 +5;
ll sg[4*LimN];
ll n,m;

void update(ll id, ll l, ll r,ll pos,ll val){
    if (pos > r || pos < l) return;
    if (l==r){
        sg[id] = val;
        return;
    }
    ll mid = (l+r)/2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    sg[id] = max(sg[id*2], sg[id*2+1]);
}

void get(ll id, ll l, ll r, ll val){
    if (l==r){
        sg[id] -=val;
        cout << l << " ";
        return; 
    }
    ll mid = (l+r)/2;
    if (sg[id*2] >= val){
        get(id*2,l,mid,val);
    }
    else get(id*2+1,mid+1,r,val);
    sg[id] = max(sg[id*2],sg[id*2+1]);
}

void solve(){
    cin >> n >> m;
    forn(i,n){
        ll x; cin >> x;
        update(1,1,n,i,x);
    }
    while (m--){
        ll h; cin >> h; 
        if (h > sg[1]) cout << 0 << " ";
        else{
            get(1,1,n,h);
        }
    }
}
 
 
int main()
{
    fast_cin();
    solve();
    return 0;
}