#include<bits/stdc++.h>

using namespace std;


#define pb push_back
#define mp make_pair



int segment[100100];
int input[100100];
vector<map<int,int> >v;

int preprocess(int n)
{
    int current_segment=-1;
    int segment_size=sqrt(n);
    for(int i=0;i<n;i++)
    {
        if(i%segment_size==0)
        {
            current_segment++;
        }
        segment[current_segment]+=input[i];
    }
    return segment_size;
}


int query(int segment_size,int l,int r)
{
    while(l<r && l%segment_size!=0)
    {
        sum+=input[i];
        l++;
    }
    while(l+segment_size<=r)
    {
        sum+=segment[l/segment_size];
        l+=segment_size;
    }
    while(l<=r)
    {
        sum+=input[l];
        l++;
    }
    return sum;
}


int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>input[i];
    }
    preprocess(n);
}
