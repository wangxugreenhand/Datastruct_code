//平衡树的实现

#include<iostream>
using namespace std;

int a[1000005];

//ALV tree
struct AVLNode{
    int bf;
    int data;
    AVLNode* left;
    AVLNode* right;
    AVLNode* parent;
    AVLNode():bf(0),left(NULL),right(NULL),data(0),parent(NULL){}
    AVLNode(int d,AVLNode* l, AVLNode* r)
    {
        data = d;
        left = l;
        right = r;
        parent = NULL;
    }
};
//
AVLNode* root = NULL; //根节点
int num_ = 0;
extern void RotateL(AVLNode* &ptr);  //左单旋
extern void RotateR(AVLNode* &ptr);  //右单旋
extern void RotateLR(AVLNode* &ptr); // 先左后右
extern void RotateRL(AVLNode* &ptr); //先右后左
extern void insert( AVLNode* &pptr,AVLNode* &ptr,int val);//插入函数
extern int find(AVLNode* sub,int x);//查找函数
int main()
{
    int m,n;
    cin>>m>>n;
    int res;
    AVLNode* root_ = NULL;
    //int rank = 0;
    AVLNode* p;
    for(int i =1;i<=n;i++)
    {
        cin>>a[i];
        insert(root_,root,a[i]);
        if(i == 1)
        {
            res = a[1];
            p = root;
        }
        else
        {
            if(i % m != 1 && a[i] <= p->data)
                p = p;
            else if(i %m == 1 && a[i] <= p->data)
            {
                p = p->left;
            }
            else if(i %m != 1 && a[i] > p->data)
            {
                if(p->right) {
                    p = p->right;
                    while(p->left)
                        p = p->left;
                }
                else
                    p = p->parent;
            }
            else if(i % m == 1 && a[i] > p->data)
                p = p;
            res = p->data;
        }

        cout<<res<<" ";
    }
    return 0;
}
void RotateL(AVLNode* &ptr)
{
    AVLNode* subL = ptr;
    ptr = subL->right;
    subL->right = ptr->left;
    if(ptr->left !=NULL)
        ptr->left->parent = subL;
    ptr->left = subL;
    ptr->parent = subL->parent;
    subL->parent = ptr;
    ptr->bf = subL->bf = 0;
}
void RotateR(AVLNode* &ptr)
{
    AVLNode* subR = ptr;
    ptr = subR->left;
    subR->left = ptr->right;
    if(ptr->right)
        ptr->right->parent = subR;
    ptr->right = subR;
    ptr->parent = subR->parent;
    subR->parent = ptr;
    ptr->bf = subR->bf = 0;
}
void RotateLR(AVLNode* &ptr)
{
    AVLNode* subR = ptr;
    AVLNode* subL = subR->left;
    ptr = subL->right;
    subL->right = ptr->left;
    if(ptr->left) ptr->left->parent = subL;
    ptr->left = subL;
    subL->parent = ptr;
    if(ptr->bf<=0)subL->bf = 0;
    else subL->bf =-1;
    subR->left = ptr->right;
    if(ptr->right) ptr->right->parent = subR;
    ptr->right = subR;
    ptr->parent = subR->parent;
    subR->parent = ptr;
    if (ptr->bf == -1) subR->bf = 1;
    else subR->bf = 0;
    ptr->bf = 0;
}
void RotateRL(AVLNode* &ptr)
{
    AVLNode* subL = ptr;
    AVLNode* subR = subL->right;
    ptr = subR->left;
    subR->left = ptr->right;
    if(ptr->right) ptr->right->parent = subR;
    ptr->right = subR;
    subR->parent = ptr;
    if (ptr->bf >= 0) subR->bf = 0;
    else subR->bf = 1;
    subL->right = ptr->left;
    if(ptr->left) ptr->left->parent = subL;
    ptr->left = subL;
    ptr->parent = subL->parent;
    subL->parent = ptr;
    if (ptr->bf == 1) subL->bf = -1;
    else subL->bf = 0;
    ptr->bf = 0;

}
void insert(AVLNode* &pptr, AVLNode* &ptr,int val)
{
   if(ptr == NULL)
   {
       ptr = new AVLNode;
       ptr->data = val;
       ptr->parent = pptr;
       AVLNode* par = pptr;
       AVLNode* cur = ptr;
       while(par)
       {
           if(par->left == cur)
               par->bf-=1;
           else if(par->right == cur)
               par->bf+=1;
           if(par->bf == 0)
               break;
           else if(par->bf == 1 || par->bf == -1 )
           {
               cur = par;
               par = par->parent;
               continue;
           }
           else if(par->bf == 2 && par->right->bf == 1)
           {
               if(par->parent!=NULL && par->parent->right == par)
                   RotateL(par->parent->right);
               else if(par->parent!=NULL && par->parent->left == par)
                   RotateL(par->parent->left);
               else if(par->parent == NULL)
                   RotateL(root);
           }
           else if(par->bf == 2 && par->right->bf == -1)
           {
               if(par->parent!=NULL && par->parent->right == par)
                   RotateRL(par->parent->right);
               else if(par->parent!=NULL && par->parent->left == par)
                   RotateRL(par->parent->left);
               else if(par->parent == NULL)
                   RotateRL(root);
           }
           else if(par->bf == -2 && par->right->bf == -1)
           {
               if(par->parent!=NULL && par->parent->right == par)
                   RotateR(par->parent->right);
               else if(par->parent!=NULL && par->parent->left == par)
                   RotateR(par->parent->left);
               else if(par->parent == NULL)
                   RotateR(root);
           }
           else if(par->bf == -2 && par->right->bf == 1)
           {
               if(par->parent!=NULL && par->parent->right == par)
                   RotateLR(par->parent->right);
               else if(par->parent!=NULL && par->parent->left == par)
                   RotateLR(par->parent->left);
               else if(par->parent == NULL)
                   RotateLR(root);
           }
       }

   }
   else if(ptr->data < val) insert(ptr,ptr->right,val);
   else if(ptr->data >= val) insert(ptr,ptr->left,val);

}
