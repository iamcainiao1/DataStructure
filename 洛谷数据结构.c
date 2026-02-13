/*


*****第1题*****


题目描述
由于长期没有得到维修，A 国的高速公路上出现了 n 个坑。为了尽快填补好这 n 个坑，A 国决定对 m 处地段采取交通管制。
为了求解方便，假设 A 国的高速公路只有一条，而且是笔直的。现在给出 n 个坑的位置，请你计算，最少要对多远的路段实施交通管制？

输入格式
输入数据共两行，第一行为两个正整数 n,m(2≤m≤n≤15000)。
第二行给出了 n 个坑的坐标（坐标值均在长整范围内，按从小到大的顺序给出，且不会有两个点坐标相同）。

输出格式
仅一行，为最小长度和。

输入输出样例

输入 
18 4
3 4 6 8 14 15 16 17 21 25 26 27 30 31 40 41 42 43
输出 
25

【样例说明】
需要在整条路上取 4 小段，这 4 段路需要包含所有坑。取 [3,8],[14,21],[25,31],[40,43] 这四段即可，长度总和为 6+8+7+4=25。


#include<stdio.h>
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
    for(j=0;j<=t-1;j++){ 
        arr2[j] = arr1[j+1] - arr1[j];
    }
    int arrmax[1000];
    int sum=0;
    for(i=0;i<=m-2;i++){
        arrmax[i]=find_the_max(arr2,t);
        sum+=arrmax[i];
    }
    int a=arr1[t]-arr1[0]-sum;
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
}
*/


/*题目描述

有 n(2≤n≤10^6) 个小朋友，他们的编号分别从 1 到 n。现在他们排成了一个队伍，每个小朋友只知道他后面一位小朋友的编号。
现在每个小朋友把他后面是谁告诉你了，同时你还知道排在队首的是哪位小朋友，请你从前到后输出队列中每个小朋友的编号。

输入格式
第一行一个整数 n，表示小朋友的人数。

第二行 n 个整数，其中第 i 个数表示编号为 i 的小朋友后面的人的编号。如果这个数是 0，则说明这个小朋友排在最后一个。

第三行一个整数 h，表示排在第一个的小朋友的编号。

输出格式
一行 n 个整数，表示这个队伍从前到后所有小朋友的编号，用空格隔开。

输入输出样例

输入 

6
4 6 0 2 3 5
1

输出 

1 4 2 6 5 3
*/


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