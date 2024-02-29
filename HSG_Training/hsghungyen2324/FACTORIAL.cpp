#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MOD = 1e9+7;
#define ln "\n"
#define pb push_back
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const ll M = 20240131;
ll n;
void solve(){
    cin >> n;
    ll res = 0;
    ll gt = 1;
    for (ll i=1;i<=min(n,M);i++){
        gt = (gt*i)%M;
        res+=gt;
        res%=M;
    }
    cout << res;
}
int main()
{
    fast_cin();
    solve();
    return 0;
}