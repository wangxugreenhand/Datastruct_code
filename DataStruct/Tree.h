
#ifndef DATASTRUCT_TREE_H
#define DATASTRUCT_TREE_H

class TreeNode {
private:
    int val;
    TreeNode *left;
    TreeNode *right;
public:
    TreeNode(int v):val(v), left(nullptr), right(nullptr) {}
    ~TreeNode() {}
};


#endif //DATASTRUCT_TREE_H
