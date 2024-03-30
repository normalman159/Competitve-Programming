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
const ll Lim = 1e7+5;
ll f[Lim];
bool nt[Lim];
ll a,b;
void sangnt(ll n){
    memset(nt,true,sizeof(nt));
    nt[0] = nt[1]  =false;
    for (ll i=2;i*i<=n;i++){
        if (nt[i]){
            for (ll j = i*i;j<=n;j+=i){
                nt[j] = false;
            }
        }
    }
}
bool checkdx(ll x){
    string res = to_string(x);
    reverse(res.begin(),res.end());
    if (x == stoll(res)) return true;
    return false;
}
void solve(){
    cin >> a >> b;
    ll a1 = sqrt(a), b1 = sqrt(b);
    if (a1*a1  < a) a1++;
    sangnt(b1);
    ll res = 0;
    for (ll i=2;i<=b1;i++){
        f[i] = f[i-1];
        if (nt[i]==true && checkdx(i)){
            f[i]++;
        }
    }
    cout << f[b1] - f[a1-1];
}
int main()
{    
    // freopen("SOCPDEP.INP","r",stdin);
    // freopen("SOCPDEP.OUT","w",stdout);
    fast_cin();
    solve();
    return 0;
}