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
    ll x1  = x, res = 0;
    while (x >0){
        res+=x%10;
        x/=10;
    }
    if (res == x1) return 1;
    return 0;
}
void solve(){
    cin >> a >> b;
    ll a1 = sqrt(a), b1 = sqrt(b);
    if (a1*a1  < a) a1++;
    sangnt(b1);
    ll res = 0;
    for (ll i=a1;i<=b1;i++){
        if (nt[i] && checkdx(i)){
            res++;
        }
    }
    cout << res;
}
int main()
{    
    // freopen("SOCPDEP.INP","r",stdin);
    // freopen("SOCPDEP.OUT","w",stdout);
    fast_cin();
    solve();
    return 0;
}