/*
author : Maxwill Lin @ 2014/12/09
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(i,s,t) for(int (i)=(s);(i)<(t);(i)++)
using namespace std;

int m,n;
int s[1003][1003];
struct E{
    int h,s;
}stack[1002];
int top;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int ans=0;
        scanf("%d%d\n",&m,&n);
        memset(s,0,sizeof s);
        FOR(i,1,m+1){
            FOR(j,1,n+1){
                char ch=getchar();
                getchar();
                if(ch=='F') s[i][j]=s[i-1][j]+1;
            }
            top=0;
            FOR(j,1,n+2){
                while(top&&stack[top].h>s[i][j]){
                    E tmp=stack[top--];
                    ans=max(ans,(j-tmp.s)*tmp.h);
                    if(!top||top&&stack[top].h<s[i][j])
                        stack[++top]=(E){s[i][j],tmp.s};
                }
                if(!top||top&&stack[top].h<s[i][j])
                    stack[++top]=(E){s[i][j],j};
            }
        }
        printf("%d\n",ans*3);
    }
    return 0;
}
