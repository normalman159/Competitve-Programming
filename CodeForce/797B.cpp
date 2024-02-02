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

ll n,a[MXN],dp[MXN];
void solve(){
    cin >> n;
    for (ll i=1;i<=n;i++) cin >> a[i];
    ll sum = 0, m= -INF, m1=INF;
    for (ll i=1;i<=n;i++){
        if (a[i] > 0){
            sum+=a[i];
            if ((a[i] & 1)){
                m1 = min(m1,a[i]);
            }
        }
        else{
            if ((a[i] & 1)){
                m = max(m,a[i]);
            }
        }
    }
    if (!(sum&1)){
        m = abs(m);
        sum-=min(m,m1);
    }
    cout << sum;
}

void solve1(){
    
}

int main()
{
    fast_cin();
    solve();
    return 0;
}