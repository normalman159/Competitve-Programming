#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
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
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((ll)(x).size())

bool AreSame(double a, double b)
{
    return fabs(a - b) < eps;
}

void solve(){
    double a1,b1,a2,b2;
    cin >> a1 >> b1 >> a2 >> b2;
    double z1 = a1 / a2 * b2 / b1;
    double z2 = b1 / b2 * a2 / a1;
    // DEBUG(z1);
    // DEBUG(z2);
    if (z1==1 && z2==1){
        cout << "YES";
    }
    else cout << "NO";
}
 
 
int main()
{
    fast_cin();
    solve();
    return 0;
}