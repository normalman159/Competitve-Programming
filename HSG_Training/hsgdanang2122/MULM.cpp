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
ll l,r;
void solve(){
    cin >> l >> r;
    ll l1 = l/2022;
    ll r1 = r/2022;
    // cout << l1 << " " << r1 << ln;
    if (l1 != r1){
        cout << 0;
        return;
    }
    ll res = 1;
    for (ll i=l;i<=r;i++){
       res *= i%2022;
       res%=2022;
    }
    cout << res;
}
int main()
{
    // freopen("MULM.INP","r",stdin);
    // freopen("MULM.OUT","w",stdout);
    fast_cin();
    solve();
    return 0;
}