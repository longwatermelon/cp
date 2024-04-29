#include <bits/stdc++.h>
using namespace std;
#define fs filesystem

const string TYPE="usaco";

int main(int argc, char **argv) {
    // no args ==> new env if no save file
    // arg is "new" ==> ignore save file
    if ((argc==1 && !fs::exists("/home/long/cp/contest/save")) || (argc==2 && strcmp(argv[1],"new")==0)) {
        // reset env
        fs::remove_all("/home/long/cp/contest");
        fs::copy("/home/long/templates/"+TYPE, "/home/long/cp/contest");
    }
}
