#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const ll MOD = 1e9+7;
#define ln "\n"
#define pb push_back
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
ll n,a,b;
void solve(){
    cin >> n >> a >> b;
    if (a<=b){
        cout << 0 << " ";
    }
    else cout << a-b << " ";
    if (a+b<=n){
        cout << a;
    }
    else cout << n-b;
}
int main()
{
    // freopen("BAI1.INP", "r",stdin );
    // freopen("BAI1.OUT", "w",stdout);
    fast_cin();
    solve();
    return 0;
}