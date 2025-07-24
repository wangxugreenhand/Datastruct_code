//
// Created by 86158 on 2025/4/24.
//

#ifndef DATASTRUCT_UFSET_H
#define DATASTRUCT_UFSET_H
//用双亲表示法实现并查集
const int maxn = 100;
class UFset {
private:
    int *parent; // parent[i]表示i的父节点
    int size; // 并查集的大小
public:
    UFset(int sz = maxn);
    ~UFset();
    void Union(int root1, int root2);
    int Find(int x); // 查找x的根节点
    void UnionByWeight(int root1, int root2);
    void UnionByHeight(int root1, int root2);  //此时，parent中放的就不是权重，而是高度
    
};


#endif //DATASTRUCT_UFSET_H
