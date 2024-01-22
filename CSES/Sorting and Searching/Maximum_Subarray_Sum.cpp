#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const long long INF = 1e15;
const ll MOD = 1e9+7;
const double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

ll n, a[MXN],dp[MXN];

struct Node
{
    /* data */
    ll sum,max,maxL,maxR;
}; Node t[4*MXN];

Node cmp(Node a, Node b){
    Node ans;
    ans.sum = a.sum + b.sum;
    ans.maxL = max({a.sum + b.maxL, a.maxL});
    ans.maxR = max(b.maxR, b.sum + a.maxR);
    ans.max = max({a.max, b.max, a.maxR + b.maxL});
    return ans;
}

void build(ll id, ll l, ll r){
    if (l==r){
        t[id] = {a[l], a[l], a[l], a[l]};
        return;
    }
    ll mid = (l+r)>>1;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    t[id] = cmp(t[id*2], t[id*2+1]);
}

void solve(){
    cin >> n;
    for (ll i=1;i<=n;i++) cin >> a[i];
    build(1,1,n);
    cout << t[1].max;
}
int main()
{
    fast_cin();
    solve();
    cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return 0;
}