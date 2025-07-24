#include <iostream>
using namespace std;

class item
{
    friend class Heap;
    friend class Shop;
public:
    int BuyTime; //商品的购买时间
    int sales; //销量
    int idx; //商品编号
    int idx_shelf_buytime; //按购买时间排序后的序号
    int idx_shelf_salse; //按销量排序后的序号
    item() //初始化商品——后续五个属性都需要修改
    {
        BuyTime = 0;
        sales = 0;
        idx = 0;
        idx_shelf_buytime = 0;
        idx_shelf_salse = 0;
    }
    void set_item(int t, int x) //设置商品的属性
    {
        BuyTime = t;
        sales = 0;
        idx = x;
    }
    /*加上购买时间这个条件后，不会出现两种商品排序idx相等的情况*/
    bool operator>=(const item& a) //操作符重载（用于对销量比较时进行排序）剔除销量最差的商品中最久没有被购买的商品
    {
        bool ans = false;
        if(sales > a.sales) //销量不相等时直接按照销量比较
        {
            ans = true;
        }
        else if(sales == a.sales && BuyTime >= a.BuyTime) //销量相等时按照购买时间先后顺序比较
        {
            ans = true;
        }
        return ans;
    }
    bool operator<(const item& a)
    {
        bool ans = false;
        if(sales < a.sales)
        {
            ans = true;
        }
        else if(sales == a.sales && BuyTime < a.BuyTime)
        {
            ans = true;
        }
        return ans;
    }
};

/*用最小堆来维护按购买时间和按照销量排序序列
销量和购买时间都是越大越好
最先剔除的一定是堆顶元素*/

class Heap
{
    friend class Shop;
private:
    item **mHeap; //堆中存储item对象指针
    int count; //堆中元素个数
public:
    Heap()
    {
        mHeap = nullptr;
        count = 0;
    }

    Heap(int n)
    {
        mHeap = new item*[n + 1];
        for(int i = 0; i <= n; ++i)
            mHeap[i] = nullptr;
        count = 0;
    }

    item* peek()
    {
        return mHeap[0];
    }

    int left(int i)
    {
        return 2 * i + 1;
    }

    int right(int i)
    {
        return 2 * i + 2;
    }

    int parent(int i)
    {
        return (i - 1) / 2;
    }
/*type = 0 buytime || type = 1 sales*/
    void siftup(int i, int type)
    {
        if (type == 0) //按照购买时间排序时只需要直接对buytime进行比较，用基础操作符即可
        {
            while (i > 0)
            {
                int p = parent(i);
                if (mHeap[i]->BuyTime >= mHeap[p]->BuyTime)
                    break;
                item *it = mHeap[i];
                mHeap[i] = mHeap[p];
                mHeap[p] = it;
                mHeap[i]->idx_shelf_buytime = i;
                mHeap[p]->idx_shelf_buytime = p;
                i = p;
            }
        }
        else
        {
            while (i > 0)
            {
                int p = parent(i);
                if (*mHeap[i] >= *mHeap[p])
                    break;
                item *it = mHeap[i];
                mHeap[i] = mHeap[p];
                mHeap[p] = it;
                mHeap[i]->idx_shelf_salse = i;
                mHeap[p]->idx_shelf_salse = p;
                i = p;
            }
        }
    }

    void siftdown(int i, int type)
    {
        if (type == 0)
        {
            while (i < count)
            {
                int l = left(i), r = right(i), ma = i;
                if (l < count && mHeap[l]->BuyTime < mHeap[ma]->BuyTime)
                    ma = l;
                if (r < count && mHeap[r]->BuyTime < mHeap[ma]->BuyTime)
                    ma = r;
                if (ma == i)
                    break;
                item *it = mHeap[i];
                mHeap[i] = mHeap[ma];
                mHeap[ma] = it;
                mHeap[i]->idx_shelf_buytime = i;
                mHeap[ma]->idx_shelf_buytime = ma;
                i = ma;
            }
        }
        else
        {
            while (i < count)
            {
                int l = left(i), r = right(i), ma = i;
                if (l < count && *mHeap[l] < *mHeap[ma])
                    ma = l;
                if (r < count && *mHeap[r] < *mHeap[ma])
                    ma = r;
                if (ma == i)
                    break;
                item *it = mHeap[i];
                mHeap[i] = mHeap[ma];
                mHeap[ma] = it;
                mHeap[i]->idx_shelf_salse = i;
                mHeap[ma]->idx_shelf_salse = ma;
                i = ma;
            }
        }
    }

    void push(item* val, int type)
    {
        mHeap[count] = val;
        if(type == 0)
            mHeap[count]->idx_shelf_buytime = count;
        else
            mHeap[count]->idx_shelf_salse = count;
        siftup(count, type);
        count++;
    }

    void pop(int idx, int type)
    {
        item *it = mHeap[idx];
        mHeap[idx] = mHeap[count - 1];
        mHeap[count - 1] = it;
        bool up = false;
        if(type == 0)
        {
            mHeap[idx]->idx_shelf_buytime = idx;
            mHeap[count - 1]->idx_shelf_buytime = count - 1;
            if(idx != 0 && mHeap[idx]->BuyTime < mHeap[parent(idx)]->BuyTime)
                up = true;
        }
        else
        {
            mHeap[idx]->idx_shelf_salse = idx;
            mHeap[count - 1]->idx_shelf_salse = count - 1;
            if(idx != 0 && *mHeap[idx] < *mHeap[parent(idx)])
                up = true;
        }
        count--;
        if(up)
            siftup(idx, type);
        else
            siftdown(idx, type);
    }

};

class Shop
{
private:
    int n; //商店容量的上限
    int time; //维护全局时间
    int num; //当前商店中商品数量
    item *items; //按照商品序号排序的货架
    Heap *shelf_buytime; //按照商品购买时间排序的货架
    Heap *shelf_salse; //按照商品销量排序的货架
public:
    Shop(int limit)
    {
        n = limit;
        time = 0;
        num = 0;
        items = new item[100001]();
        for(int i = 0; i < 100001; ++i)
            items[i].set_item(-10, i); //先将所有商品的购买时间初始化为负数
        shelf_buytime = new Heap(n);
        shelf_salse = new Heap(n);
    }

    void posi1(int x)
    {
        time++;
        item *it = &items[x];
        if(it->BuyTime >= 0) //顾客能购买idx为x的商品
        {
            it->BuyTime = time;
            it->sales++;
            shelf_buytime->siftdown(it->idx_shelf_buytime, 0);
            shelf_salse->siftdown(it->idx_shelf_salse, 1);
        }
        else if(it->BuyTime < 0) //没货
        {
            cout << -1 << endl;
        }
    }

    void posi2(int y, int z)
    {
        time++;
        item *it = &items[y];
        if(it->BuyTime >= 0) //已经有货了不再进货
            return;
        if(num == n) //商店满了 剔除掉一个商品，剔除之后商品数据对应清零
        {
            item *remove = nullptr;
            if(z == 1)
            {
                remove = shelf_buytime->peek();
                shelf_buytime->pop(0, 0);
                shelf_salse->pop(remove->idx_shelf_salse, 1);
            }
            else
            {
                remove = shelf_salse->peek();
                shelf_salse->pop(0, 1);
                shelf_buytime->pop(remove->idx_shelf_buytime, 0);
            }
            num--;
            cout << remove->idx << endl;
            items[remove->idx].BuyTime = -10;
            items[remove->idx].sales = 0;
        }
        it->BuyTime = time;
        it->sales = 0;
        shelf_buytime->push(it, 0);
        shelf_salse->push(it, 1);
        num++;
    }

    void print()
    {
        int times = 0;
        for(int i = 0; i < 100001; ++i)
        {
            if(items[i].BuyTime >= 0)
            {
                cout << i << " ";
                times++;
                if(times == num)
                    break;
            }
        }
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    Shop shop(n);
    int type, a, b;
    for(int i = 0; i < m; ++i)
    {
        cin >> type;
        if(type == 1)
        {
            cin >> a;
            shop.posi1(a);
        }
        else
        {
            cin >> a >> b;
            shop.posi2(a, b);
        }
    }
    shop.print();
    system("pause");
    return 0;
}