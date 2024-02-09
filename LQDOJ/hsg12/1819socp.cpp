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
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

unordered_map<ll,ll> mp;
ll n;

void tach(ll x){
    for (ll i=2;i*i<=x;i++){
        while (x%i==0){
            mp[i]++;
            x/=i;
        }
    }
    if (x!=1) mp[x]++;
}

ll bp(ll a,ll b){
    a%=MOD;
    ll ans=1;
    while (b){
        if (b&1){
            ans = (ans * a)%MOD;
        }
        a = (a*a)%MOD;
        b = b>>1;
    }
    return ans;
}

void solve(){
    cin >> n;
    for (ll i=1;i<=n;i++){
        tach(i);
    }
    ll res=1;
    auto it = mp.begin();
    for (it;it!=mp.end();++it){
        if (it->second %2==0){
            res*=bp(it->first, it->second);
            res%=MOD;
        }
        else{
            if (it->second -1 ==0) continue;
            res*=bp(it->first, it->second-1);
            res%=MOD;
        }
    }
    cout << res;
}
int main()
{
    fast_cin();
    solve();
    cerr << " Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return 0;
}