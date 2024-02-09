#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const long long INF = 1e15;
const ll MOD = 1e9+7;
#define ln "\n"
#define pb push_back
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
ll a[30];
string s;
void solve(){
    cin >> s;
    for (ll i=0;i<s.size();i++){
        a[s[i] - 'a']++;
    }
    for (auto x : a){
        if (x &1){
            cout << "No";
            return;
        }
    }
    cout << "Yes";
}
int main()
{
    fast_cin();
    solve();
    return 0;
}