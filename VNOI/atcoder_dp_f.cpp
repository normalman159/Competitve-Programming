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
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

string s,t;
ll n1,n2,dp[3003][3003];  
void solve(){
    cin >> s >> t;
    n1=s.length();
    n2 = t.length();
    for (ll i=0;i<=n2;i++){
        dp[0][i] = 0;
    }
    for (ll i=1;i<=n1;i++){
        for (ll j=1;j<=n2;j++){
            if (s[i-1] == t[j-1]){
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
            }
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    string res;
    ll i=n1, j = n2;
    while (i !=0 && j != 0){
        if (s[i-1] == t[j-1]){
            res+=s[i-1];
            i--,j--;
        }
        else if (dp[i][j-1] >= dp[i-1][j]){
            j--;
        }
        else i--;
    }
    reverse(res.begin(), res.end());
    cout << res;
} 
int main()
{
    fast_cin();
    solve();
    cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return 0;
}