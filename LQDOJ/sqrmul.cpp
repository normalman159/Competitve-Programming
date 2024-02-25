#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const ll MOD = 1e9+7;
#define ln "\n"
#define pb push_back
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const ll LimN =1e7+5;
ll n;
bool ch[LimN];
ll dem[LimN];
vector<ll> c;
void thuasont(ll x){
    for (ll i=2;i*i<=x;i++){
        if (x%i==0){
            ll cnt = 0;
            while (x %i==0){
                cnt++;
                x/=i;
            }
            if (dem[i]==0) c.push_back(i);
            dem[i] = max(dem[i],cnt);
        }
    }
    if (x>1){
        if (dem[x] == 0) c.push_back(x);
        dem[x] = max(dem[x],1LL);
    }
}
ll powMod(ll a,ll b){
    ll res=1;
    a%=MOD;
    if (a==0) return 0;
    while (b){
        if (b&1){
            res = (res*a)%MOD;
        }
        a = (a*a)%MOD;
        b/=2;
    }
    return res;
}
void solve(){
    memset(ch,false,sizeof(ch));
    cin >> n;
    for (ll i =1;i<=n;i++){
        ll x;
        cin >> x;
        if (ch[x] == false && x!=1){
            thuasont(x);
            ch[x]= true;
        }
    } 
    ll res =1;
    for (ll i=0;i<c.size();i++){
        ll k = c[i];
        if (dem[k]&1) dem[k]++;
        ll z = powMod(k,dem[k]);
        res = (res*z)%MOD;
    }
    cout << res;
}
int main()
{
    fast_cin();
    solve();
    return 0; 
}