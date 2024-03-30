#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const ll MOD = 1e9+7;
#define ln "\n"
#define pb push_back
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
string s1,s2;
const ll Lim = 1e6+5;
string t1[Lim], t2[Lim];
ll u1;

void tachsau(string s, ll z){
    string token;
    stringstream ss(s);
    ll u = 1;
    while (ss >> token){
        if (z==1){
            t1[u]  =token;
        }
        else{
            t2[u] = token;
        }
        u++;
    }
    u--;
    u1 = u;
}

bool checkvar(string s1,string s2){
    if (s1.size() < s2.size()) return false;
    ll i=0,j=0;
    while (i<s1.size()){
        if (s1[i] == s2[j]){
            j++;
        }
        else{
            if (s1[i]!=s1[i-1]){
                return false;
            }
        }
        i++;
    }
    if (j == s2.size()) return true;
    return false;
}

void solve(){
    getline(cin,s1);
    getline(cin,s2);
    tachsau(s1,1);
    tachsau(s2,2);
    ll res = 0;
    bool flag = true;
    for (ll i = 1;i<=u1;i++){
        string a = t1[i], b=t2[i];
        if (checkvar(a,b)) res++;
    }
    cout << res;
}
int main()
{
    // freopen("BAI2.INP","r",stdin);
    // freopen("BAI2.OUT", "w", stdout);
    fast_cin();
    solve();
    return 0;
}