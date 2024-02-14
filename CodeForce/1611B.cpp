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

//n team -> a - n, b-n

ll t;
void solve(){
    cin >> t;
    while (t--){
        ll a,b; cin >> a >> b;
        if (a > b){
            swap(a,b);
        }
        ll hai_hai = a/2;
        a-= hai_hai*2;
        b-=hai_hai*2;
        ll mot_ba = min(hai_hai, b/4);
        hai_hai-=mot_ba;
        b-=mot_ba*4;
        mot_ba*=2;
        ll ans = mot_ba + hai_hai;
        if (a !=0 && b != 0 && a +b >=4){
            ans++;
        }
        cout << ans << ln;
    }
}
int main()
{
    fast_cin();
    solve();
    return 0;
}