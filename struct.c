/*任务1：
给定一批整数，以 0 为结束标志且不作为结点，将其建成一个先进先出的链表，
先进先出链表的头指针始终指向最先创建的结点（链头），
先建结点指向后建结点，后建结点始终是尾结点。
#include<stdio.h>
struct wtf{
    int number;
    struct wtf *middlepoint;
};
void create_list(struct wtf **headp,int *p);
int main()
{
    struct wtf *head2=NULL,*p1;
    int s[100];
    int i=0;
    int ret=0;
    while(i<99){
        ret = scanf("%d",&s[i]);
        if(ret!=1){
            break;
        }
        i++;
    }
    create_list(&head2,s);
    p1=head2;
    while(p1){
        printf("%d\t",p1->number);
        p1=p1->middlepoint;
    }
	return 0; 
}
void create_list(struct wtf **headp,int *p){
    struct wtf *head=NULL,*head1;
    head = (struct wtf *)malloc(sizeof(struct wtf));
    head->number = *p++;
    head1=head;
    while(*p!=0){
        head1->middlepoint = (struct wtf *)malloc(sizeof(struct wtf));
        head1 = head1->middlepoint;
        head1->number = *p++;
    }
    head1->middlepoint = NULL;
    *headp=head;
}
*/

/*任务2：
设计一个字段结构 struct bits, 它将一个 8 位无符号字节从最低位到最高位声明为 8 个字段，
依次为 bit0, bit1,..., bit7，且 bit0 优先级最高。
同时设计8个函数，第 i 个函数以 biti(i=0, 1, ..., 7)为参数，
并且在函数体内输出 biti 的值。将 8 个函数的名字存入一个函数指针数组 p_fun。
如果 bit0 为 1, 调用 p_fun[0] 指向的函数。
如果 struct bits 中有多位为 1，
则根据优先级从高到低顺序依次调用函数指针数组 p_fun 中相应元素指向的函数。

#include<stdio.h>
#include<stdlib.h>
void f0();
void f1();
void f2();
void f3();
void f4();
void f5();
void f6();
void f7();
struct bits{
    unsigned char bit0 : 1;  
    unsigned char bit1 : 1;
    unsigned char bit2 : 1;
    unsigned char bit3 : 1;
    unsigned char bit4 : 1;
    unsigned char bit5 : 1;
    unsigned char bit6 : 1;
    unsigned char bit7 : 1;
};
int main(){
    int in=0;
    scanf("%d",&in);
    struct bits in0b;
    int arr[8];
    int judge=0;
    int count=0;
    while(in!=0){
        judge=in%2;
        switch(judge){
           case 0:
               in=in/2;
               arr[count]=0;
               break;
           case 1:
               in=(in-1)/2;
               arr[count]=1;
               break;
        }
        count++;
    }
    if(count<=6){
        while(count<=7){
            arr[count]=0;
            count++;
        }
    }
    in0b.bit0=arr[0];
    in0b.bit1=arr[1];
    in0b.bit2=arr[2];
    in0b.bit3=arr[3];
    in0b.bit4=arr[4];
    in0b.bit5=arr[5];
    in0b.bit6=arr[6];
    in0b.bit7=arr[7];
    void(*p_func[8])()={f0,f1,f2,f3,f4,f5,f6,f7};
    for(int i=0;i<8;i++){
        if(arr[i]==1){
            p_func[i]();
        }
    }
    return 0;
}
void f0(){
    printf("the function %d is called!\n",0);
}
void f1(){
    printf("the function %d is called!\n",1);
}
void f2(){
    printf("the function %d is called!\n",2);
}
void f3(){
    printf("the function %d is called!\n",3);
}
void f4(){
    printf("the function %d is called!\n",4);
}
void f5(){
    printf("the function %d is called!\n",5);
}
void f6(){
    printf("the function %d is called!\n",6);
}
void f7(){
    printf("the function %d is called!\n",7);
}
*/
//？那我写尼玛bit呢，有什么卵用





/*任务3*
本关任务：现有如表中所示的4个常用的网站网址信息，包括缩略名、全名、url信息。
现设计一个结构体struct web,并编写结构体数组获取表中的网址信息，
同时将网站信息按照缩略名排序并按照升序输出,最后获取一个缩略名，输出它的URL信息。
要求：将排序定义成函数。

缩略名	全名	URL
hkd	华中科技大学	http://www.hust.edu.cn
bd	百度搜索网站	http://www.baidu.com
gg	谷歌搜索网站	http://www.google.com
wy	网易邮箱登录	https://mail.163.com
测试说明
平台会对你编写的代码进行测试，若是与预期输出相同，则算通关。

测试输入：
hkd 华中科技大学 http://www.hust.edu.cn
bd 百度搜索网站 http://www.baidu.com
gg 谷歌搜索网站 http://www.google.com
wy 网易邮箱登录 https://mail.163.com
gg
预期输出：
bd 百度搜索网站 http://www.baidu.com
gg 谷歌搜索网站 http://www.google.com
hkd 华中科技大学 http://www.hust.edu.cn
wy 网易邮箱登录 https://mail.163.com
http://www.google.com

测试输入：
hkd 华中科技大学 http://www.hust.edu.cn
bd 百度搜索网站 http://www.baidu.com
gg 谷歌搜索网站 http://www.google.com
wy 网易邮箱登录 https://mail.163.com
cs
预期输出：
bd 百度搜索网站 http://www.baidu.com
gg 谷歌搜索网站 http://www.google.com
hkd 华中科技大学 http://www.hust.edu.cn
wy 网易邮箱登录 https://mail.163.com
未找到搜寻的网址

要求
输入格式与输出格式为，同一网站的信息之间以空格分隔，不同网站信息之间以回车分隔。
*/

/*
#include<stdio.h>

void sort(struct web webs[],int n);
void bubble_sort_char(char arr[], int n);
struct web   设计表示网址的结构 
{
    
    char abb;
    char name;
    char add;
	
};
void bubble_sort_char(char arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int flag = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            // 直接比较char的ASCII值
            if (arr[j] > arr[j+1]) {
                char temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1;
            }
        }
        if (!flag) break;
    }
}
#define N  4   
int main()
{
    struct web a1,a2,a3,a4;
    struct web webs[N]={a1,a2,a3,a4};
    void sort(struct web webs[],int n);
    
	return 0; 
}
void sort(struct web webs[],int n)//为避免反表示结构变量的顺序，直接对结构变量排序，通过指针根据abb升序排序（怎么做捏。。。）
{
    scanf("%s",&a1.abb);
    scanf("%s",&a1.name);
    scanf("%s",&a1.add);

    scanf("%s",&a2.abb);
    scanf("%s",&a2.name);
    scanf("%s",&a2.add);

    scanf("%s",&a3.abb);
    scanf("%s",&a3.name);
    scanf("%s",&a3.add);

    scanf("%s",&a4.abb);
    scanf("%s",&a4.name);
    scanf("%s",&a4.add);

    char s[N]={a1.abb,a2.abb,a3.abb,a4.abb};
    bubble_sort_char(char s[],N);
}
*/
//日了，有点复杂，先放着





/*任务4：本关任务：
（1）用一个单向链表接收一个长字符串，且每个节点接收一个字符，
遍历输出链表中的所有字符，并将字符串无冗余地存放到一个动态存储分配的的字符数组中，
并且输出该字符串。（本题暂不考虑空字符串情况）(结尾以回车结束)
（2）再输入一个字符，如果该字符已在链表中，则删除该结点，
否则在输入字符和结点的数据域字符差值最小的结点后面插入包含该字符的结点，输出最后的字符串。
要求：采用模块化设计方法，将创建链表、遍历链表、删除结点、插入结点等功能用函数实现。
（我服了，神人要求我全都会写）
测试输入：
qwertyuiopasdfghjkl
i
预期输出：
q w e r t y u i o p a s d f g h j k l
qwertyuiopasdfghjkl
qwertyuopasdfghjkl

测试输入：
qwertyuiopasdfghjkl
q
预期输出：
q w e r t y u i o p a s d f g h j k l
qwertyuiopasdfghjkl
wertyuiopasdfghjkl

测试输入：
qwer1234?@%
5
预期输出：
q w e r 1 2 3 4 ? @ %
qwer1234?@%
qwer12345?@%
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct wtf{
    char number;
    struct wtf *next;
};

void create_list(struct wtf **headp,char *p);//创建链表函数
void delete_point(struct wtf **headp,struct wtf *goal_p);//删除节点函数
void find_the_char_add(struct wtf *headp,struct wtf** goal,char new_char,int *flag);//找到插入或删除节点的位置
void insert_after(struct wtf *goal_p,char new_char);//插入节点函数

int main()
{
    struct wtf *head2=NULL,*p1,*p2,*p3,*goal;
    char temp_buf[1024];
    fgets(temp_buf, sizeof(temp_buf), stdin);//不用scanf，因为要同时输入各种类型的字符
    int flag=0;
    create_list(&head2,temp_buf);
    p1=head2;
    p2=head2;
    printf("%c",p1->number);
    p1=p1->next;
    while(p1){
        printf(" %c",p1->number);
        p1=p1->next;
    }
    int i = 0;
    while(temp_buf[i]!='\0'){
        printf("%c",temp_buf[i]);
        i++;
    }
    size_t input_len = strlen(temp_buf);
    /*if (temp_buf[input_len - 1] == '\n') {
        temp_buf[input_len - 1] = '\0';
        input_len--;
    }*/    //暂时不清楚要不要用，先注释掉
    char *content = (char *)malloc((input_len + 1) * sizeof(char)); 
    strcpy(content, temp_buf);
    char new_char = fgetc(stdin);
    find_the_closest_char_add(p2,&goal,new_char,&flag);
    if(flag==0){
        delete_point(&head2,goal);
    }
    else{
        insert_after(goal,new_char);
    }
    p3=head2;
    while(p3){
        printf("%c",p3->number);
        p3=p3->next;
    }
	return 0; 
}

void create_list(struct wtf **headp,char *p){
    struct wtf *head=NULL,*head1;
    head = (struct wtf *)malloc(sizeof(struct wtf));
    head->number = *p++;
    head1=head;
    while(*p!='\0'){
        head1->next = (struct wtf *)malloc(sizeof(struct wtf));
        head1 = head1->next;
        head1->number = *p++;
    }
    head1->next = NULL;
    *headp=head;
}

void find_the_char_add(struct wtf *headp,struct wtf** goal,char new_char,int *flag){
    struct wtf *head2 = headp;
    char closest_char = head2->number;
    int min_distance = abs(closest_char - new_char);
    struct wtf *min_fatherstruct = head2;
    while(head2){
        int current_distance = abs(head2->number - new_char);
        if (current_distance < min_distance) {
            min_distance = current_distance;
            closest_char = head2->number;
            min_fatherstruct = head2;
        }
        head2 = head2->next;
    }
    if(min_distance==0){
        *flag = 0;
    }
    else{
        *flag = 1;
    }
    *goal = min_fatherstruct;
}
void insert_after(struct wtf *goal_p,char new_char){
    struct wtf *new = (struct wtf *)malloc(sizeof(struct wtf));
    new->number = new_char;
    new->next = goal_p->next;
    goal_p->next = new;
}
void delete_point(struct wtf **headp,struct wtf* goal_p){
    struct wtf *head = headp;
    if (*headp == goal_p) {
        *headp = goal_p->next;
        free(goal_p);
        return;
    }
    while(head->next!=goal_p){
        head = head->next;
    }
    head->next = goal_p->next;
    free(goal_p);
}