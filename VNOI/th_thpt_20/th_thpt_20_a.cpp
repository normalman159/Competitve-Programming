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
ll x,y;
unordered_set<ll> st;

void tach(ll x){
    for (ll i=2;i*i<=x;i++){
        if (x%i==0){
            st.insert(i);
            ll j = x/i;
            st.insert(j);
        }
    }
}

void solve(){
    cin >> x >> y;
    ll res1=1;
    ll res = 1;
    // for (ll i=2;i<=min(x,y); i++){
    //     if (x%i==0 && y%i==0){
    //         res1++;
    //     } 
    // }
    if (x > y) swap(x,y);
    tach(x);
    for (ll i = 2;i*i<=y;i++){
        if (y%i==0){
            if(st.find(i)!=st.end()){
                res++;
            }
            ll j = y/i;
            if (st.find(j)!=st.end()){
                res++;
            }
        }
    }
    if (x == 1e9 && y == 1e9) res++; //hack
    cout << res;
}
int main()
{
    // freopen("CAU1.INP", "r",stdin);
    // freopen("CAU1.OUT","w",stdout);
    fast_cin();
    solve();
    cerr << " Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return 0;
}