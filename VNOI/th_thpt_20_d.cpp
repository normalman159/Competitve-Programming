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
string s;
const ll LimN = 1e6+5;

ll p1[LimN], p2[LimN];
void solve(){
    cin >> s;
    ll n = s.size();
    s = ' ' + s;
    
    p1[0] = 0, p2[0] = 0;
    for (ll i=1; i<=n;i++){
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] =='o' || s[i] =='u'){
            p1[i] = p1[i-1]+1;
            p2[i] = p2[i-1];
        }
        else {
            p1[i] = p1[i-1];
            p2[i] = p2[i-1]+1;
        }
    }   
    ll res =0; 
    for (ll l = 1;l<n;l++){
        if (s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] =='o' || s[l] =='u'){
            res+=p2[n] - p2[l];
        }
        else{
            res+=p1[n] - p1[l];
        }
    }
    cout << res;
}
int main()
{
    // freopen("CAU4.INP", "r",stdin);
    // freopen("CAU4.OUT","w",stdout);
    fast_cin();
    solve();
    cerr << " Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return 0;
}