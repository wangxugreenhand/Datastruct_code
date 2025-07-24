//使用了二叉搜索树中的建树和删除、队列实现树的层次遍历

#include<iostream>
using namespace std;

//int N[100005] = {0};
//int M[100005] = {0};




struct BSTNode {                //二叉树结点类
    int data;                    //数据域
    BSTNode *left, *right;  //左子女和右子女
    BSTNode() {
        left = NULL;
        right = NULL;
        data = 0;
    }

    //构造函数
    BSTNode(int d, BSTNode *L = NULL,
            BSTNode *R = NULL) {
        data = d;
        left = L;
        right = R;
    }
};

class BST {
private:
    BSTNode* root;	//根指针

    //BSTNode* Search (int x, BSTNode*ptr);
    //void makeEmpty (BSTNode*& ptr);						//递归：置空
    void Print (BSTNode *ptr) const;						//递归：打印
    //BSTNode *Copy (const BSTNode*ptr);
    //BSTNode* Min (BSTNode* ptr);						//递归：求最小
    //BSTNode* Max (BSTNode* ptr);					//递归：求最大
    bool Insert (const int& e1, BSTNode*& ptr);					//递归：插入
    bool Remove (const int x, BSTNode*& ptr);

public:
    BST() { root = NULL; }	  //构造函数
    ~BST() {};			  //析构函数
    //bool Search (const int x) //搜索
    //{ return (Search(x,root) != NULL); }
    BSTNode* getroot(){ return root;}
    //输出
    //int Min() { return Min(root)->data; }	 //求最小
    //int Max() { return Max(root)->data; }	 //求最大
    bool Insert (const int& e1) { return Insert(e1, root);}//添加新节点
    bool Remove (const int x) { return Remove(x, root);} 	  //删除含x的结点

};
//BSTNode* BST:: Search ( int x, BSTNode*ptr) {
////私有递归函数：在以ptr为根的二叉搜索树中搜
////索含x的结点。若找到，则函数返回该结点的
////地址，否则函数返回NULL值。
//    if (ptr == NULL) return NULL;
//    else if (x < ptr->data) return Search(x, ptr->left);
//    else if (x > ptr->data) return Search(x, ptr->right);
//    else return ptr;				//搜索成功
//};
bool BST::Insert (const int& e1,BSTNode *& ptr) {
//私有函数：在以ptr为根的二叉搜索树中插入值为
//e1的结点。若在树中已有含e1的结点则不插入
    if (ptr == NULL) {	   //新结点作为叶结点插入
        ptr = new BSTNode(e1);	  //创建新结点
        if (ptr == NULL)
        { cerr << "Out of space" << endl;  exit(1); }
        return true;
    }
    else if (e1 < ptr->data) Insert (e1, ptr->left);	 		//左子树插入
    else if (e1 > ptr->data) Insert (e1, ptr->right);		//右子树插入
    else return false;	      //x已在树中,不再插入
};
bool BST::Remove(const int x, BSTNode*& ptr)
{
    BSTNode* temp;
    if (ptr != NULL) {
        if (x < ptr->data) Remove(x, ptr->left);
            //在左子树中执行删除
        else if (x > ptr->data) Remove(x, ptr->right);
        //在右子树中执行删除
        else if (ptr->left != NULL && ptr->right != NULL)
        {       //ptr指示关键码为x的结点，它有两个子女
            temp = ptr->left;
            while(temp->right != NULL)
                temp = temp->right;
            ptr->data = temp->data;
            Remove(ptr->data,ptr->left);
        }
        else
        {
            temp = ptr;
            if (ptr->left == NULL) ptr = ptr->right;
            else ptr = ptr->left;
            delete temp;
            return true;

        }
    }
    return false;

 };

BSTNode* queue[100005] = {0};
int back = 0,front = 0;
void push_back(BSTNode* x)
{
    queue[back++] = x;
}
void pop_front(BSTNode* &x)
{
    x = queue[front];
    front++;
}
bool empty()
{
    return front == back;
}



int main()
{
    int n,m;
    cin>>n>>m;
    BST mybst;
    int p;
    for(int i = 0;i<n;i++)
    {
        cin>>p;
        mybst.Insert(p);
    }
    for(int i =0;i<m;i++)
    {
        cin>>p;
        mybst.Remove(p);
    }
    BSTNode* q =mybst.getroot();
    push_back(q);
    while(!empty())
    {
        BSTNode* te;
        pop_front(te);
        cout<<te->data << " ";
        if(te->left !=NULL)
            push_back(te->left);
        if(te->right != NULL)
            push_back(te->right);

    }


    return 0;
}