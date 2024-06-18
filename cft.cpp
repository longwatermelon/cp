#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define sig(x) (x<0?-1:1)
#define sz(x) ((int)size(x))
template <typename T> T cdiv(T a, T b) {return a/b+(a/b>=0 && a%b!=0);}
template <typename T> T fdiv(T a, T b) {return a/b-(a/b<0 && a%b!=0);}
template <typename T> T mod(T a, T b) {return ((a%b)+b)%b;}
template <typename T> void vprint(T st, T nd) {auto it=st;while (next(it)!=nd){cout<<*it<<' ';it=next(it);}cout<<*it<<'\n';}
struct pt_t {int x,y;bool operator<(pt_t b)const{return x==b.x?y<b.y:x<b.x;}bool operator==(pt_t b)const{return x==b.x&&y==b.y;}};

void solve() {
}

int main() {
    int _; cin>>_;
    while (_--) {
        solve();
    }
}
