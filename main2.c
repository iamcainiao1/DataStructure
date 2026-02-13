#include<stdio.h>
#include<stdlib.h>
int main(){
    int m,f;
    scanf("%d",&m);
    int *arr1=NULL;
    int *arr2=NULL;
    arr1=(int*)malloc(m*sizeof(int));
    arr2=(int*)malloc(m*sizeof(int));
    int i=0;
    for(;i<=m-1;i++){
        scanf("%d",&arr1[i]);
    }
    scanf("%d",&f);
    arr2[0]=f;
    for(i=1;i<=m-1;i++){
        arr2[i]=arr1[arr2[i-1]-1];
    }
    for(i=0;i<=m-2;i++){
        printf("%d ",arr2[i]);
    }
    printf("%d",arr2[i]);
    return 0; 
}
