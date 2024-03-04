#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const long long INF = 1e15;
const ll MOD = 1e9+7;
const double eps = 1e-12;
#define forn(i,e) for(ll i = 1; i <= e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 1; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define DEBUG(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((ll)(x).size())

void solve(){
    ll n; cin >> n;
    vector<ll> v(n+5);
    forn(i,n){
        cin >> v[i];
    }
    vector<bool> check(n+5,false);
    vector<bool> check2(n+5,false);
    ll L = -1, R = n+5;
    bool co = false;
    forn(i,n){
        if (check2[v[i]]==false){
            check2[v[i]] = true;
        }
        else co = true;
    }
    if (co == false){
        cout << 0;
        return;
    }
    forn(i,n){
        if (check[v[i]]== true){
            L = i;
            break;
        }
        check[v[i]]= true;
    }
    vector<bool> check1(n+5,false);
    rforn(i,n){
        if (check1[v[i]]==true){
            R = i;
            break;
        }
        check1[v[i]] = true;
    }
    ll l = L,r = n;
    ll ans = n;
    while (l >=1 && r >= R){
        while (check[v[r]] == false){
            check[v[r]] = true;
            r--;
        }
        ans = min(ans,r-l+1);
        // DEBUG(l);
        // DEBUG(r);
        l--;
        check[v[l]] = false;
    }    
    cout << ans;
}
 
 
int main()
{
    fast_cin();
    solve();
    return 0;
}