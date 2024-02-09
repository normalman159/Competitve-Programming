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
const ll LimN = 1e7+5;
unordered_map<ll,ll> mp;
ll n;
bool ch[LimN];
void sangnt(ll n){
    memset(ch,true,sizeof(ch));
    ch[0] = ch[1] = false;
    for (ll i=2;i*i<=n;i++){
        if (ch[i]){
            for (ll j=i*i;j<=n;j+=i){
                ch[j]=false;
            }
        }
    }    
}

ll tach(ll n, ll k){

    // for (ll i=2;i*i<=x;i++){
    //     while (x%i==0){
    //         mp[i]++;
    //         x/=i;
    //     }
    // }
    // if (x!=1) mp[x]++;

    // while (x!=1){
    //     ll tmp = ch[x];
    //     while (x%tmp==0){
    //         mp[tmp]++;
    //         x/=tmp;
    //     }
    // }
    ll p = k, res = 0;
    while (p<=n){
        res+=n/p;
        p*=k;
    }
    return res;
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
    sangnt(n);
    ll res = 1;
    for (ll i=2;i<=n;i++){
        if (ch[i] == true){
            res= (res* bp(i, tach(n,i)/2*2))%MOD;
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