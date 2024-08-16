#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define sig(x) (x<0?-1:1)
#define sz(x) ((int)size(x))
#define all(x) begin(x),end(x)
#define all1(x) begin(x)+1,end(x)
template <typename T> T cdiv(T a, T b) {return a/b+(sig(a)/sig(b)==1 && a%b);}
template <typename T> T fdiv(T a, T b) {return a/b-(sig(a)/sig(b)==-1 && a%b);}
template <typename T> T mod(T a, T b) {return ((a%b)+b)%b;}
template <typename T> T rmod(T a, T mn, T mx) {return mod((a-mn),(mx-mn+1))+mn;}
template <typename T> void vprint(T st, T nd) {auto it=st;while (next(it)!=nd){cout<<*it<<' ';it=next(it);}cout<<*it<<'\n';}
void yn(bool ans) {puts(ans?"yes":"no");}
template <typename T> using vec=vector<T>;
template <typename T> struct vec2:vector<vector<T>> {vec2(int n, int m, T val=T()):vector<vector<T>>(n,vector<T>(m,val)){}};
template <typename T> struct vec3:vector<vector<vector<T>>> {vec3(int n, int m, int k, T val=T()):vector<vector<vector<T>>>(n,vector<vector<T>>(m,vector<T>(k,val))){}};
#define PTX x
#define PTY y
struct pt_t {int PTX,PTY;bool operator==(pt_t pt2)const{return PTX==pt2.PTX&&PTY==pt2.PTY;}};
int MD=1e9+7;
int modpow(int x, ll p) {assert(p>=0);return p==0?1:((ll)modpow(((ll)x*x)%MD,p/2)*(p&1?x:1))%MD;}
int modinv(int x) {return modpow(x,MD-2);}

void solve() {
}

int main() {
    int _; cin>>_;
    while (_--) {
        solve();
    }
}
