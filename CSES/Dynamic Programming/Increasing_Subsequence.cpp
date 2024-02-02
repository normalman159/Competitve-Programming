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

/*
Gọi dp[l] là giá trị nhỏ nhất mà tại đó độ dài mảng con tăng dài nhất là l
dp[0] = -INF
Duyệt từ 1->n : 
*/
const ll MAX_N = 2*1e5+3;
ll n, a[MXN],dp[MAX_N];
// void solve(){
//     cin >> n;
//     for (ll i=1;i<=n;i++){
//         cin >> a[i];
//     }
//     dp[0] = -INF;
//     for (ll i=1;i<=n;i++){
//         dp[i] = INF;
//     }
//     //O(n^2)
//     for (ll i=1;i<=n;i++){
//         for (ll l = 1;l<=n;l++){
//             if (dp[l-1] < a[i]){
//                 dp[l] = min(a[i], dp[l]);
//             }
//         }
//     }

//     //O(nlogn)
//     for (ll i=1;i<=n;i++){
//         ll l = upper_bound(dp+1,dp+1+n,a[i]) - dp;
//         if (dp[l-1] < a[i]) dp[l]= min(a[i],dp[l]);
//     }

//     ll ans = 0;
//     for (ll l=1;l<=n;l++){
//         if (dp[l] != INF){
//             ans = max(ans,l);
//         }
//     }
//     cout << ans;
// }

ll t[4*MXN];

void build(ll id, ll l, ll r){
    if (l == r){
        t[id] = a[l];
        return;
    }
    
}

void solve1(){
    cin >> n;
    for (ll i=1;i<=n;i++){
        cin >> a[i];
    }

}

int main()
{
    fast_cin();
    solve1();
    cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return 0;
}