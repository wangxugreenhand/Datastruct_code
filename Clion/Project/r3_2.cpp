#include<iostream>

using namespace std;
int a[100005] = {0};
int sum = 0;
extern void Quicksort(int left, int right);
extern int Partition(int low,int high);
extern int judge(int n,int c, int d, int k);
int main()
{
    int n,c,d,k;
    cin>>n>>c>>d;
    for(int i =1;i<= n;i++)
        cin>>a[i];
    for(int i =1;i<= n;i++)
        sum+=a[i];
    Quicksort(1,n);
    int left = 1;
    int right = d-1;
    int temp = 0;
    while(left <= right) {
        int mid = (left + right) / 2;
        int res = judge(n, c, d, mid);
        if (res < c) {
            if (left == right) {
                k = temp;
                break;
            } else
                right = mid - 1;
        }
        else if (res == c) {
            k = mid;
            break;
        }
        else {
            if (left == right) {
                k = mid;
                break;
            } else {
                temp = mid;
                left = mid + 1;
            }
        }
    }
    if (k == 0)
        cout << "Impossible";
    else if (k == d - 1)
        cout << "Infinity";
    else
        cout << k;


    return 0;
}
void Quicksort(int left, int right)
{
    if(left < right){
        int pivotpos = Partition(left,right);
        Quicksort(left,pivotpos-1);
        Quicksort(pivotpos+1,right);
    }
}
int Partition(int low,int high)
{
    int pivotpos = low;
    int pivot = a[low];
    for(int i = low+1;i<=high;i++) {
        if (a[i] > pivot) {
            pivotpos++;
            if (pivotpos != i) {
                int temp = a[pivotpos];
                a[pivotpos] = a[i];
                a[i] = temp;
            }
        }
    }
    a[low] = a[pivotpos];
    a[pivotpos] = pivot;
    return pivotpos;
}
int judge(int n,int c, int d, int k)
{
    if(k >= n-1)
    {
        int i = d /k;
        //int j = d % k;
        int r = sum * i;
        for(int g = k * i+1;g <= n && g<= d;g++ )
            r += a[g - k*i];
        return r;
    }
    else
    {
        int s_ = 0;
        for(int i = 1;i<=k+1;i++)
            s_ += a[i];
        int i = d/k;
        int r = i * s_;
        for(int g = k*i +1;g<= d&& g<= n;g++)
            r+=a[g - k* i];
        return r;
    }
}