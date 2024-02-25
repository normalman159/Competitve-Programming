#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const ll MOD = 1e9+7;
#define ln "\n"
#define pb push_back
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const ll LimN = 1e4+5;
ll n,k,a[LimN],dp[LimN][105],t[LimN][105];
char dau[LimN][105];
void solve(){  
    cin >> n >> k;
    for (ll i=1;i<=n;i++){
        cin >> a[i];
    }
    for (ll i=1;i<=n;i++){
        a[i] = (a[i]+10000*k)%k;
    }
    //dp[i][j]: có thể tạo được số dư j tại vật thứ i
    dp[1][a[1]] = 1;
    for (ll i=2;i<=n;i++){
        for (ll j = k-1;j>=0;j--){
            ll t1 = (a[i] + j) %k;
            ll t2 = (j - a[i] + k) %k;
            if (dp[i-1][t1]!=0){
                dp[i][j]=1;
                dau[i][j] = '-';
                t[i][j] = t1;
            }
            else{
                if (dp[i-1][t2]!=0){
                    dp[i][j] = 1;
                    dau[i][j]='+';
                    t[i][j] = t2;
                }
                
            }
        }
    }
    string res="";
    if (dp[n][0]){
        cout << 1 << ln;
        ll t1 = 0;
        while (n>1){
            res+=dau[n][t1];
            t1 = t[n][t1];
            n--;
        }
        reverse(res.begin(),res.end());
        cout << res;
    }
    else{
        cout << 0;
    }
}
int main()
{
    fast_cin();
    solve();
    return 0;
}