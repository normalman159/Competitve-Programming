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
#define DEBUG(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((ll)(x).size())
 


void solve(){
    ll q; cin >> q;
    while (q--){
        ll a,b; cin >> a >> b;
        if (a==b){
            cout << "YES" << ln;
            continue;
        }
        if (a > b){
            cout << "NO" << ln;
            continue;
        }
        bool flag = false;
        while ((b%2==0 || b%10 == 1) && a<b){
            if (b%2==0) b/=2;
            else b/=10;
            if (a==b){
                flag = true;
                cout << "YES" << ln;
                break;
            }
        }
        if (flag == false) cout << "NO" << ln;
    }
}
 
int main()
{
    fast_cin();
    solve();
    return 0;
}