#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const long long INF = 1e15;
const ll MOD = 1e9+7;
const double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
ll h,w;
const ll LimH = 1e3+5;
char a[LimH][LimH];
ll f[LimH][LimH];
void solve(){
    cin >> h >> w;
    for (ll i=1;i<=h;i++){
        for (ll j = 1;j<=w;j++){
            cin >> a[i][j];
        }
    }
    memset(f,0,sizeof(f));
    f[1][1] = 1;
    for (ll i=1;i<=h;i++){
        for (ll j = 1;j<=w;j++){
            if (f[i][j]!=0){
                //sang phai
                if (a[i][j+1] == '.'){
                    f[i][j+1] +=f[i][j];
                    f[i][j+1]%=MOD;
                }
                if (a[i+1][j] == '.'){
                    f[i+1][j]+=f[i][j];
                    f[i+1][j]%=MOD;
                }
            }
        }
    }
    cout << f[h][w];
}
int main()
{
    fast_cin();
    solve();
    cerr << " Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return 0;
}