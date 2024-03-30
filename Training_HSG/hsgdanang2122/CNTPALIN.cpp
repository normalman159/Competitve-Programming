#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const long long INF = 1e15;
const ll MOD = 1e9+7;
#define ln "\n"
#define pb push_back
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
string s;
const ll Lim = 1e6+5;
ll cnt[30];

ll powMod(ll a, ll b){
    ll res = 1;
    while (b){
        if (b&1) {
            res = (res * a) %MOD;
        }
        a = (a*a)%MOD;
        b/=2;
    }
    return res;
}
ll giaithua(ll x){
    ll res = 1;
    for (ll i=2;i<=x;i++){
        res = (res*i)%MOD;
    }
    return res;
}
void solve(){
    cin >> s;
    ll n = s.size();
    s = ' ' + s;
    for (ll i = 1;i<=n;i++){
        cnt[s[i] - 'A']++;
    }
    ll count = 0;
    for (ll i =0;i<=26;i++){
        if (cnt[i] & 1){
            count++;
        }
    }
    if (count>=2){
        cout << "0";
        return;
    }
    ll x = 0;
    for (ll i=0;i<=26;i++){
        x+=cnt[i]/2;
    }
    ll up = giaithua(x);
    ll down = 1;
    for (ll i=0;i<=26;i++){
        down = (down * giaithua(cnt[i]/2))%MOD;
    }
    ll ans = up * powMod(down,MOD-2) %MOD;
    ans%=MOD;
    cout << ans;
}
int main()
{
    // freopen("CNTPALIN.INP","r",stdin);
    // freopen("CNTPALIN.OUT","w",stdout);
    fast_cin();
    solve();
    return 0;
}