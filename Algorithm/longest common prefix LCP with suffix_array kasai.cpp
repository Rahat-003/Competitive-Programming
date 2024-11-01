// LCP with suffix array_kasai

#define mx 100005

int sa[mx],ind[mx],lcp[mx];
struct node{
    int index,r1,r2;
    bool operator < (const node &n) const{
        if(r1!=n.r1)    return r1<n.r1;
        return r2<n.r2;
    }
} ar[mx];
string s;
void suffix_aray(){
    int n = s.size();
    for(int i = 0; i<n; i++){
        ar[i].index = i;
        ar[i].r1 = s[i] - 'a';
        ar[i].r2 = (i+1<n?s[i+1]-'a':-1);
    }
    sort(ar,ar+n);

    for(int k = 4; k<2*n; k*=2){
        int rank = 0,tmp = ar[0].r1;
        ind[ar[0].index] = 0;
        ar[0].r1 = 0;
        for(int i = 1; i<n; i++){
            if(ar[i].r1==tmp && ar[i].r2 == ar[i-1].r2){
                tmp = ar[i].r1;
                ar[i].r1 = rank;
            }
            else{
                tmp = ar[i].r1;
                ar[i].r1 = ++rank;
            }
            ind[ar[i].index] = i;
        }

        for(int i = 0; i<n; i++){
            int j = ar[i].index + k/2;
            ar[i].r2 = (j<n)?ar[ind[j]].r1:-1;
        }
        sort(ar,ar+n);
    }
    for(int i = 0; i<n; i++)    sa[i] = ar[i].index;
}
void lcp_kasai(){
    int n = s.size(),k = 0;
    for(int i = 0; i<n; i++)    ind[sa[i]] = i;
    for(int i = 0; i<n; i++,k>0?--k:0){
        if(ind[i]==n-1) continue;
        int j = sa[ind[i]+1];
        while(i+k<n && j+k<n && s[i+k]==s[j+k]) k++;
        lcp[ind[i]] = k;
    }
}
int distinct_substring(){
    int n = s.size(),ans = 1;
    ans+=n-sa[0];
    for(int i = 0; i<n-1; i++){
        int p = (n-sa[i+1]);    /// Length of i+1 th suffix in suffix array;
        int x = p - lcp[i];
        ans+=x;
    }
    return ans;
}

main(){
int t,tc = 0;

cin>>s;
suffix_aray();
lcp_kasai();

for(int i = 0; i<s.size(); i++) cout<<sa[i]<<" ";   cout<<endl;
for(int i = 0; i<s.size(); i++) cout<<lcp[i]<<" ";  cout<<endl;

int ans = distinct_substring();
cout<<ans<<endl;

return 0;
}

