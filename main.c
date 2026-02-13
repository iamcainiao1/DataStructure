/*#include<stdio.h>
int find_the_max(int arr[],int g);
int main(){
    int n,m,i;
    scanf("%d",&n,&m);
    int arr1[10000];
    i=0;
    for(i=0;i<=n-1;i++){
    	scanf("%d",&arr1[i]);
	}
    int arr2[9997];
    int t=i-1;
    int j; 
    for(j=1;j<=t-2;j++){
        arr2[j-1]=arr1[j+1]-arr1[j];
    }
    int arrmax[1000];
    int sum=0;
    for(i=0;i<=m-2;i++){
        arrmax[i]=find_the_max(arr2,t);
        sum+=arrmax[i];
    }
    int a=arr1[t]-arr1[0]+m-sum;
    printf("%d",a);
}



int find_the_max(int arr[],int g){
    int i;
    int max=arr[0];
    int count=0;
    for(i=0;i<=g;i++){
        if(max<arr[i]){
            max=arr[i];
            count=i;
        }
    }
    int need;
    need=arr[count];
    arr[count]=0;
    return need;
}*/
#include<stdio.h>

int find_the_max(int arr[], int g);

int main(){
    int n, m, i;
    scanf("%d %d", &n, &m);
    long long arr1[15001];
    for(i = 0; i < n; i++){
        scanf("%lld", &arr1[i]);
    }
    int arr2[15001];
    int t = n - 1;
    int j;
    for(j = 0; j < t; j++){
        arr2[j] = arr1[j+1] - arr1[j];
    }
    long long sum = 0;
    for(i = 0; i < m - 1; i++){
        sum += find_the_max(arr2, t - 1);
    }
    long long a = arr1[t] - arr1[0] + m - sum;
    printf("%lld", a);
    return 0;
}

int find_the_max(int arr[], int g){
    int i;
    int max = arr[0];
    int count = 0;
    for(i = 0; i <= g; i++){
        if(max < arr[i]){
            max = arr[i];
            count = i;
        }
    }
    int need = arr[count];
    arr[count] = 0;
    return need;
}



