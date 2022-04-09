#include<stdio.h>
#define n 5  //全排列1~n 
int result[n+1]={0};//记录排列结果 ，result[0]不用 
int flag[n+1]={0};//记录数i是否使用过，flag[0]不用 

void dfs(int step){//step为步骤，从1开始 
	if(step==n+1){//递归出口 
		for(int i=1;i<=n;i++)
		printf("%d ",result[i]);
		printf("\n");
		return;
	}
	for(int i=1;i<=n;i++) {		
            if(flag[i]==0) {            	
                flag[i] = 1;  //标记第i个数用过
                result[step] = i; //记下结果中step位置的数 
                dfs(step+1);  //处理下一位 
                flag[i] = 0;  //回溯
                }
        }		
}
int main(){
	dfs(1);
} 