#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const ll MOD = 1e9+7;
#define ln "\n"
#define pb push_back
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
ll x,y;
ll ucln(ll x,ll y){
    if (x==0){
        return y;
    }
    return ucln(y%x,x);
}
ll demuoc(ll x){
    ll res =0;
    for (ll i=1;i*i<=x;i++){
        if (x%i==0){
            res++;
            if (i!=x/i) res++;
        }
    }
    return res;
}
void solve(){
    cin >> x >> y;
    ll z = ucln(x,y);
    cout << demuoc(z);
}
int main()
{
    // freopen("CAU1.INP","r",stdin);
    // freopen("CAU1.OUT","w",stdout);
    fast_cin();
    solve();
    return 0;
}