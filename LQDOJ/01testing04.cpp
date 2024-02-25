#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const ll MOD = 1e9+7;
#define ln "\n"
#define pb push_back
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const ll Lim = 1e6 +5;
ll s , t, f[Lim];
void solve(){
    cin >> s>> t;
    for (ll i=1;i<1e6;i++) f[i] = INF;
    f[s] = 0;
    for (ll a = s;a<=t;a++){
        for (ll k = 1;k*k<=a;k++){
            if (a%k == 0){
                ll b = k+a;
                if (a+1 < b && b < 2*a) f[b] = min(f[b], f[a]+1);
                b = a/k + a;
                if (a+1 < b && b < 2*a) f[b] = min(f[b], f[a]+1);
            }
        }
    }
    if (f[t] == INF) cout << -1;
    else cout << f[t];
}
int main()
{
    // freopen("DIVISOR.INP","r",stdin);
    // freopen("DIVISOR.OUT","w",stdout);
    fast_cin();
    solve();
    return 0;
}