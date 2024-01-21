#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
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
 
ll n, q,k, a[MXN], b[MXN];

void solve(){
    cin >> n >> q >> k;
    for (ll i = 1; i <=n ; i++) cin >> a[i];
    for (ll i=1; i<=q;i++) cin >> b[i];
    ll ans = 0;
    sort(a+1,a+1+n);
    sort(b+1,b+1+q);
    ll i=1, j =1;
    while (i <= n && j <= q ){
        if (abs(a[i] - b[j]) <=k) {
            ans++; i++; j++;
        }
        else if (a[i] - b[j] > k){
            j++;
        }
        else{
            i++;
        }
    }    
    cout << ans;
} 
int main()
{
    fast_cin();
    solve();
    cerr << endl;
    cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return 0;
}