//01�������⣬ʵ������Ϊ�������龰 
#include<stdio.h>
#include<stdlib.h>
int m[100][100];//�ܼ�ֵ��� 
int max(int a,int b){
   return  (a>=b)?a:b; 
}
void Knapsack(int c,int n,int weight[],int value[]){
	int i,j; //jΪ��Ӧ�ı������� 
 	//��ʼ����ֵ���� 
 	for(i=0;i<=n;i++)
 	for(j=0;j<=c;j++)
 	m[i][j]=0;
 	//������Ʒ�ͱ����������ܼ�ֵ���,��һ�С���һ��Ϊ�� 
    for(i=1;i<=n;i++) 	
    for(j=1;j<=c;j++)
    if(j>=weight[i-1])//��װ���µ�i����Ʒ���Ƚ�װ�Ͳ�װ����Ʒ���ܼ�ֵ 
    	 m[i][j]=max(m[i-1][j],m[i-1][j-weight[i-1]]+value[i-1]);    
    else
         m[i][j]=m[i-1][j];
    //��ʾ�ܼ�ֵ���
	printf("\n�ܼ�ֵ���Ϊ��\n"); 
	for(i=0;i<=n;i++){
		for(j=0;j<=c;j++)
 	    printf("%d	",m[i][j]);
 	    printf("\n"); 	
	}   	                        
}
void chooseItem(int c,int n,int weight[]){	//�ж�ѡ����Щ��Ʒ
    int j=c;//�ӱ��ĩβ�������� 
    int *item=(int *)malloc(n*sizeof(int));//�洢ѡ�й�ϵ������     
    for(int i=n;i>=1;i--)
	    if(m[i][j]>m[i-1][j]){ //���װ�˵�i����Ʒ
				item[i-1]=1;//1Ϊѡ�е�i����Ʒ 
				j=j-weight[i-1];//��ȥ��i����Ʒ���� 
	        }
	    else
	        item[i-1]=0;
    //��ʾװ�뱳������Ʒ���ܼ�ֵ 
    printf("\nװ�뱳������Ʒ��:");
    for(int i=0;i<=n-1;i++)
        if(item[i]==1)
        	printf("%d ",i+1);
    printf("\n�ܼ�ֵΪ%d\n",m[n][c]);
}

int main(){
	int c,n;
	c=10;n=5;
	int weight[5]={2,2,6,5,4};
	int value[5]={6,3,5,4,6};
	printf("��������Ϊ:%d����Ʒ����Ϊ:%d\n",c,n);
	printf("��Ʒ�����ֱ�Ϊ��");
	for(int i=0;i<=n-1;i++)
	printf("%d	",weight[i]);
	printf("\n��Ʒ��ֵ�ֱ�Ϊ��");	
	for(int i=0;i<=n-1;i++)
	printf("%d	",value[i]);
	
	Knapsack(c,n,weight,value);
 	chooseItem(c,n,weight);
 	return 0;
} 