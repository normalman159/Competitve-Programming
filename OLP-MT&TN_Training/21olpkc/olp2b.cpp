#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const long long INF = 1e15;
const ll MOD = 1e9+7;
const double eps = 1e-12;
#define forn(i,e) for(ll i = 1; i <= e; i++)
#define forsn(i,s,e) for(ll i = s; i <= e; i++)
#define rforn(i,s) for(ll i = s; i >= 1; i--)
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

bool ch(ll x){
    string s = to_string(x);
    forsn(i,0,s.size()-2){
        if (s[i] != s[i+1]){
            return false;
        }
    }
    return true;
}

void solve(){
    ll n; cin >> n;
    if (ch(n)==true){
        cout << 1;
        return;
    }
    if (n%10 == 0){
        cout << -1;
        return;
    }
    if (1 <=n && n<=9){
        cout << 11;
        return;
    }
    // if (10<=n && n <=99){

    // }    
    forsn(phi,2,1e8){
        ll z = phi*n;
        if (ch(z)==true){
            cout << phi << " " << z;
            return;
        }
    }
    cout << -1;
}
 
 
int main()
{
    fast_cin();
    solve();
    return 0;
}