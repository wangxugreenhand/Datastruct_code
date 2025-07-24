

#include "UFset.h"

UFset::UFset(int sz) {
    size = sz;
    parent = new int[size];
    for (int i = 0; i < size; i++) {
        parent[i] = -1; // 初始化为-1，表示每个节点都是根节点
    }
}

UFset::~UFset() {
    delete[] parent;
}
void UFset:: Union(int root1, int root2) {
    parent[root1] += parent[root2];
    parent[root2] = root1; // 将root2的父节点设为root1
}

int UFset:: Find(int x){
    if(parent[x] < 0) return x;
    return Find(parent[x]); // 递归查找x的根节点
}

void UFset:: UnionByWeight(int root1, int root2) {
    int temp = parent[root1] + parent[root2];
    if (parent[root1] < parent[root2]) {
        parent[root1] = temp;
        parent[root2] = root1; // 将root2的父节点设为root1
    } else {
        parent[root2] = temp;
        parent[root1] = root2; // 将root1的父节点设为root2
    }
}

void UFset:: UnionByHeight(int root1, int root2) {
    if (parent[root1] < parent[root2]) {
        parent[root2] = root1; // 将root2的父节点设为root1
    }
    else if(parent[root1] == parent[root2]) {
        parent[root1]--;
        parent[root2] = root1; // 将root1的父节点设为root2
    }
    else{
        parent[root1] = root2; // 将root1的父节点设为root2
    }
}