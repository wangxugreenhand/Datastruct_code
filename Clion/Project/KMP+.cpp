#include<iostream>
#include<cstring>

using namespace std;
int next_1[100005] = { 0 };
int next_2[100005] = {0};

int main()
{
    int n;
    cin >> n;
    string pat;
    cin >> pat;
    int pos = 0;
    int p_len = pat.size();
    for(int i = 0; i<p_len;i++ ) {
        if (pat[i] == '*') {
            pos = i;
            break;
        }
    }


    int j = 0, k = -1;
    next_1[0] = -1;
    while(j < p_len)
    {
        if(k == -1 || pat[j] == pat[k] || pat[k] == '*' || pat[j] == '*'){
            j++;
            k++;
            next_1[j] = k;
        }
        else k = next_1[k];
    }
    int j_ = 0, k_ = -1;
    next_2[0] = -1;
    while(j_ < p_len)
    {
        if(k_ == -1 || pat[j_] == pat[k_]){
            j_++;
            k_++;
            next_2[j_] = k_;
        }
        else k_ = next_2[k_];
    }



    for(int i =0; i< n;i++) {
        string test;
        int flag = 0;
        cin >> test;
        int t_len = test.size();
        int posP = 0, posT = 0;
        while (posP < p_len && posT < t_len) {
           if(posP == -1 || pat[posP] == test[posT] || pat[posP] == '*')
                {posP++; posT++;}
           else if(posP < pos ||next_1[posP] < posP - pos)
               posP = next_1[posP];
           else if(pat[next_1[posP] -(posP - pos)] == test[posT - posP + pos]  )
               posP = next_1[posP];
           else
               posP = next_2[posP];

        }
        if (posP < p_len)
            flag = 0;
        else
            flag= 1;
        if(flag)
            cout<<"true"<<endl;
        else
            cout<<"false"<<endl;
    }

    return 0;
}
