#include<bits/stdc++.h>

using namespace std;


#define pb push_back
#define mp make_pair



int segment[100100];
int input[100100];
map<int,int>maap[1000];
int n;

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
        maap[current_segment][input[i]]++;
        //cout<<i<<" "<<current_segment<<endl;
     //   segment[current_segment]+=input[i];
    }
    return segment_size;
}


int query(int segment_size,int l,int r)
{
    int sum=0;
    map<int,int>query_map;
    while(l<r && l%segment_size!=0)
    {
        //cout<<input[l]<<endl;
        query_map[input[l]]++;
        l++;
    }
    while((l/segment_size)<(r/segment_size))
    {
     //   cout<<l<<" "<<l/segment_size<<endl;
        for(auto it=maap[l/segment_size].begin();it!=maap[l/segment_size].end();it++)
        {
            int val=it->first;
            int cnt=it->second;
           // cout<<l<<" "<<l/segment_size<<endl;
          // cout<<(l/segment_size)<<" "<<it->first<<" "<<it->second<<endl;
            //cout<<"segement: "<<l<<" "<<it->first<<" "<<it->second<<endl;
            if(it->second>it->first || (cnt+(n-l)<val))
                continue;
            query_map[it->first]+=it->second;
        }
        l+=segment_size;
    }
    while(l<=r)
    {
        query_map[input[l]]++;
        l++;
    }
    int ret=0;
    for(auto it=query_map.begin();it!=query_map.end();it++)
    {
        int x=it->first;
        int y=it->second;
     //   cout<<x<<" "<<y<<endl;
        if(x==y)
        {
            ret++;
        }
    }
    return ret;
}


main()
{
    int m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&input[i]);
    }

    int segment_size= preprocess(n);
    //cout<<segment_size<<endl;
//    cout<<query(segment_size,0,6)<<endl;
    for(int i=0;i<m;i++)
    {
        int l,r;
        scanf("%d %d",&l,&r);
        int ans=query(segment_size,l-1,r-1);
        printf("%d\n",ans);
    }
}
