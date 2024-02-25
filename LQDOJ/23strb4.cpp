#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const ll MOD = 1e9+7;
#define ln "\n"
#define pb push_back
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const ll LimN = 1e3 + 5;
ll n,a,x,b,y, ar[LimN];
void solve(){
    cin >> n >> a >> x >> b >> y;
    for (ll i=1;i<=n;i++){
        cin >> ar[i];
    }
    ll f[n+5][n+5][n+5];
    memset(f,-1,sizeof(f));
    f[0][0][0] = 0;
    for (ll i=0;i<n;i++){
        for (ll fa = 0; fa<=min(i, a);fa++){
            for (ll fb = 0; fb <=min(i,b);fb++){
                if (f[i][fa][fb] !=-1){
                    //chon buoc a
                    f[i+x][fa+1][fb] = max(f[i+x][fa+1][fb], f[i][fa][fb] + ar[i+x]);
                    //chon buoc b
                    f[i+y][fa][fb+1] = max(f[i+y][fa][fb+1],f[i][fa][fb] + ar[i+y]);
                }
            }
        }
    }    
    cout << f[n][a][b];
}
int main()
{   
    // freopen("KTIEPDAT.INP","r",stdin);
    // freopen("KTIEPDAT.OUT","w",stdout);
    fast_cin();
    solve();
    return 0;
}