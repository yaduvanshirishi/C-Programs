#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

void sort_by_area(triangle* tr, int n) {
    /**
    * Sort an array a of the length n
    */
    double p[n],s[n];
    int flag1,flag2;
    float temp;
    for(int i=0;i<n;i++){
        p[i]= (double)(tr[i].a + tr[i].b +tr[i].c);
        p[i]=p[i]/2;
        s[i]= (double)(p[i]*(p[i]-tr[i].a)*(p[i]-tr[i].b)*(p[i]-tr[i].c));
        s[i]=sqrt(s[i]);
        
    }
    for(int i=0;i<n;i++){
        flag1=0;
        flag2=0;
        for(int j=0;j<n-1-i;j++){
            
            if(s[j]>s[j+1]){
                   temp=s[j];
                   s[j]=s[j+1];
                   s[j+1]=temp;
                   flag2=1;
                   
                   temp=tr[j].a;
                tr[j].a=tr[j+1].a;
                tr[j+1].a=temp;
                   
                temp=tr[j].b;
                tr[j].b=tr[j+1].b;
                tr[j+1].b=temp;
                   
                temp=tr[j].c;
                tr[j].c=tr[j+1].c;
                tr[j+1].c=temp;
            }
            
            if(p[j]>p[j+1]){
                   temp=p[j];
                   p[j]=p[j+1];
                   p[j+1]=temp;
                   flag1=1;      
            }
        }
    }
    
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
