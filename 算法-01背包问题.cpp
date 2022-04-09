//01背包问题，实现重量为整数的情景 
#include<stdio.h>
#include<stdlib.h>
int m[100][100];//总价值表格 
int max(int a,int b){
   return  (a>=b)?a:b; 
}
void Knapsack(int c,int n,int weight[],int value[]){
	int i,j; //j为相应的背包容量 
 	//初始化价值数组 
 	for(i=0;i<=n;i++)
 	for(j=0;j<=c;j++)
 	m[i][j]=0;
 	//建立物品和背包容量的总价值表格,第一行、第一列为零 
    for(i=1;i<=n;i++) 	
    for(j=1;j<=c;j++)
    if(j>=weight[i-1])//若装得下第i件物品，比较装和不装该物品的总价值 
    	 m[i][j]=max(m[i-1][j],m[i-1][j-weight[i-1]]+value[i-1]);    
    else
         m[i][j]=m[i-1][j];
    //显示总价值表格
	printf("\n总价值表格为：\n"); 
	for(i=0;i<=n;i++){
		for(j=0;j<=c;j++)
 	    printf("%d	",m[i][j]);
 	    printf("\n"); 	
	}   	                        
}
void chooseItem(int c,int n,int weight[]){	//判断选了哪些物品
    int j=c;//从表格末尾向上搜索 
    int *item=(int *)malloc(n*sizeof(int));//存储选中关系的数组     
    for(int i=n;i>=1;i--)
	    if(m[i][j]>m[i-1][j]){ //如果装了第i件物品
				item[i-1]=1;//1为选中第i件物品 
				j=j-weight[i-1];//减去第i件物品重量 
	        }
	    else
	        item[i-1]=0;
    //显示装入背包的物品和总价值 
    printf("\n装入背包的物品是:");
    for(int i=0;i<=n-1;i++)
        if(item[i]==1)
        	printf("%d ",i+1);
    printf("\n总价值为%d\n",m[n][c]);
}

int main(){
	int c,n;
	c=10;n=5;
	int weight[5]={2,2,6,5,4};
	int value[5]={6,3,5,4,6};
	printf("背包容量为:%d，物品件数为:%d\n",c,n);
	printf("物品重量分别为：");
	for(int i=0;i<=n-1;i++)
	printf("%d	",weight[i]);
	printf("\n物品价值分别为：");	
	for(int i=0;i<=n-1;i++)
	printf("%d	",value[i]);
	
	Knapsack(c,n,weight,value);
 	chooseItem(c,n,weight);
 	return 0;
} 