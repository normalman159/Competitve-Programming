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
ll n;
void solve(){
    cin >> n;
    ll k = n/2;
    if (k*2 == n) k--;
    cout << k;
}
int main()
{
    // freopen("DEMCAP.INP","r",stdin);
    // freopen("DEMCAP.OUT","w",stdout);
    fast_cin();
    solve();
    return 0;
}