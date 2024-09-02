function cft() {
    echo "cf template to $1.cpp"
    cp ~/templates/cft.cpp $1.cpp
}

function cpt() {
    echo "cp template to $1.cpp"
    cp ~/templates/cpt.cpp $1.cpp
}

function contest() {
    builtin cd ~/cp/contest
    clear
    nvim
}

function cf() {
    cf-reset $1
    builtin cd ~/cp/contest
    cft A
    cft B
    cft C
    cft D
    cft E
    cft F
    cft G
    cft H
    clear
    nvim
}

function usaco() {
    usaco-reset $1
    builtin cd ~/cp/contest
    clear
    nvim
}
