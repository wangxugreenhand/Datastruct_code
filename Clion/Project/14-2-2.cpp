#include <bits/stdc++.h>
using namespace std;
#define INF 100000000
int Map[505][2];
bool vis[505];
double ans[505];




void qsort(int l,int r){
    int i = l;
    int j = r;
    double mid = ans[(l+r) / 2];
    do{
        while(ans[i] < mid ){
            i++;
        }
        while (mid < ans[j] ) {
            j--;
        }
        if(i <= j){
            swap(ans[i],ans[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if(l<j){
        qsort(l,j);
    }
    if(r > i){
        qsort(i,r);
    }
}
int main(){
    int s,p;
    cin>>s>>p;
    for(int i = 0;i<p;i++){
        cin>>Map[i][0];
        cin>>Map[i][1];
    }
    double min_dist[505];
    for(int i = 0;i<505;i++){
        min_dist[i] = INF;
    }
    min_dist[0] = 0.0;
    for (int i = 0; i < p;i++) {
        int u = -1;
        double gmin = INF;
        for (int j = 0; j < p;j++) {
            if (!vis[j] && min_dist[j] <= gmin) {
                gmin = min_dist[j];
                u = j;
            }
        }
        ans[i] = gmin;
        vis[u] = true;
        for (int j = 0; j < p;j++){
            if (!vis[j]) {
                double new_dist = sqrt(pow((Map[j][0] - Map[u][0]), 2) + pow((Map[j][1] - Map[u][1]), 2));
                min_dist[j] = min(min_dist[j], new_dist);
            }
        }
    }
    qsort(0, p - 1);
    printf("%.2lf",ans[p-s]);
    return 0;
}
