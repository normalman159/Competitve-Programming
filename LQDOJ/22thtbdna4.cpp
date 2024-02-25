#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const ll MOD = 1e9+7;
#define ln "\n"
#define pb push_back
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const ll LimN = 1e2+5;
ll n, f[LimN][LimN],m;
ll p[LimN][LimN];
void solve(){
    cin >> n >> m;
    for (ll i=1;i<=m;i++){
        ll x1,x2;cin >> x1 >> x2;
        p[x1][x2] = 1;
    }
    f[1][1]=1;
    for (ll i=1;i<=n;i++){
        for (ll j =1;j<=n;j++){
            if (f[i][j]!=0){
                if (p[i+1][j]!=1){
                    f[i+1][j]+=f[i][j];
                }
                if (p[i][j+1]!=1){
                    f[i][j+1]+=f[i][j];
                }
            }
        }
    }
    // for (ll i=1;i<=n;i++){
    //     for (ll j = 1;j<=n;j++){
    //         cout << i << " " << j << " " << f[i][j] << ln;
    //     }
    // }
    cout << f[n][n];
}
int main()
{
    // freopen("robot.inp","r",stdin);
    // freopen("robot.out","w",stdout);
    fast_cin();
    solve();
    return 0;
}