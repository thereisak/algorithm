#include<stdio.h>
#define n 5  //ȫ����1~n 
int result[n+1]={0};//��¼���н�� ��result[0]���� 
int flag[n+1]={0};//��¼��i�Ƿ�ʹ�ù���flag[0]���� 

void dfs(int step){//stepΪ���裬��1��ʼ 
	if(step==n+1){//�ݹ���� 
		for(int i=1;i<=n;i++)
		printf("%d ",result[i]);
		printf("\n");
		return;
	}
	for(int i=1;i<=n;i++) {		
            if(flag[i]==0) {            	
                flag[i] = 1;  //��ǵ�i�����ù�
                result[step] = i; //���½����stepλ�õ��� 
                dfs(step+1);  //������һλ 
                flag[i] = 0;  //����
                }
        }		
}
int main(){
	dfs(1);
} 