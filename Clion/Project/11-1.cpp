//哈希映射算法


#include<iostream>
using namespace std;


int hash_[10005] = {0};
int b[10005] = {0};
int main()
{
    float sal = 0, fal = 0;
    int n,prime,m;
    cin>>n>>prime>>m;
    int temp;
    for(int i = 0;i<m;i++) { cin >> temp; b[i] = temp; }
    for(int i = 0;i<m;i++)
    {
        int num_ = 1;
        int p = b[i] % prime;
        while(hash_[p] != 0)
        {
            p = (p + 1) % n;
            num_++;
        }
        hash_[p] = b[i];
        //b[i].num = num_;
        sal+= num_;
    }
    for(int i =0;i<prime;i++)
    {
        int num_ = 1;
        int p = i;
        while(hash_[p]!= 0){ p = (p + 1) % n;num_++;}
        //hash_[i].num = num_;
        fal+= num_;
    }
    sal = sal / m;
    fal = fal / prime;
    std::printf("%.3f %.3f",sal, fal);
    return 0;
}