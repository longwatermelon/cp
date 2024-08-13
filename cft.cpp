#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define sig(x) (x<0?-1:1)
#define sz(x) ((int)size(x))
#define all(x) begin(x),end(x)
#define all1(x) begin(x)+1,end(x)
template <typename T> T cdiv(T a, T b) {return a/b+(sig(a)/sig(b)==1 && a%b);}
template <typename T> T fdiv(T a, T b) {return a/b-(sig(a)/sig(b)==-1 && a%b);}
// only + solution
template <typename T> T mod(T a, T b) {return ((a%b)+b)%b;}
// wrap around to [mn,mx]
template <typename T> T rmod(T a, T mn, T mx) {return mod((a-mn),(mx-mn+1))+mn;}
template <typename T> void vprint(T st, T nd) {auto it=st;while (next(it)!=nd){cout<<*it<<' ';it=next(it);}cout<<*it<<'\n';}
#define PTX x
#define PTY y
struct pt_t {int PTX,PTY;bool operator==(pt_t pt2)const{return PTX==pt2.PTX&&PTY==pt2.PTY;}};
int MD=1e9+7;
int modpow(int x, ll p) {assert(p>=0);return p==0?1:((ll)modpow(((ll)x*x)%MD,p/2)*(p&1?x:1))%MD;}
int modinv(int x) {return modpow(x,MD-2);}
template <typename T> map<T,int> primefac(T x) {map<T,int> mp;for(T i=2;i*i<=x;++i){while(x%i==0){mp[i]++;x/=i;}}if(x>1)mp[x]++;return mp;}
void sieveofe(int mx, bool *prime) {prime[1]=false;fill(prime+2,prime+1+mx,true);for(int i=2;i*i<=mx;++i){int j=i;while(i*j<mx){prime[i*j]=false;++j;}}}
// unordered, O(sqrt(x))
template <typename T> vector<T> factor(T x) {vector<T>f;for(T i=1;i*i<=x;++i){if(x%i==0){f.push_back(i);if (x/i!=i)f.push_back(x/i);}}return f;}
void yn(bool ans) {puts(ans?"yes":"no");}
template <typename T> struct vec2:vector<vector<T>> {vec2(int n, int m, T val=T()):vector<vector<T>>(n,vector<T>(m,val)){}};
template <typename T> struct vec3:vector<vector<vector<T>>> {vec3(int n, int m, int k, T val=T()):vector<vector<vector<T>>>(n,vector<vector<T>>(m,vector<T>(k,val))){}};
// ncr is modded
int rencr(int n,int r){if(n<r)return 0;else if(r==0||r==n) return 1;else return(rencr(n-1,r-1)+rencr(n-1,r))%MD;}
vector<int> fac,invfac;int clncr(int n,int r){if(n<r)return 0;return(((ll)fac[n]*invfac[r])%MD*invfac[n-r])%MD;}

void solve() {
}

int main() {
    int _; cin>>_;
    while (_--) {
        solve();
    }
}
