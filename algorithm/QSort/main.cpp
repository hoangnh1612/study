#include<iostream>
#include<vector>
#include<algorithm>

std::vector<int> a = {1,4,2,5,2,4,1,4,3};
// 1,4,2,5,2,4,1,4,3

// 1 1 2 2 5 4 4 4 3
void qsort(int l, int r)
{
    int lv  = l, rv = r;
    int p = a[(l+r)/2];
    while(l<r)
    {

        while(a[l] < p)
            l++;
        while (a[r] > p)
            r--;
        if(l <= r)
        {
            std::swap(a[l], a[r]);
            l++;
            r--;
        }
    }
    if(l > lv)
        qsort(lv, r);
    if(r < rv)
        qsort(l,rv);
}

int main()
{
    qsort(0, a.size()-1);
    for(auto i : a)
        std::cout<<i<<" ";
}