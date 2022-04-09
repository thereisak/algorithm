//ʵ��O(nlogn)��δʵ��O(n) 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void QSort(int *r,int low ,int high){
	if(low>=high)return;
	int begin=low,end=high;
	r[0]=r[low];//��L->r[0]��¼����L->r[low]��ֵ 
	while(low<high){
		while(low<high&&r[high]>=r[0]){//high����̽ѰС�������ֵ 
			high--;
		}
		if(r[high]<r[0]){r[low]=r[high];} 		
		while(low<high&&r[low]<=r[0]){//low����̽Ѱ�����������ֵ 
			low++;
		}
		if(r[low]>r[0]){r[high]=r[low];} 		
	}
	r[low]=r[0];//�����ֵ��λ 
	QSort(r,begin,low-1);//low��Ϊ�µ����Ὣ�ӱ��Ϊ�����ֵݹ����� 
	QSort(r,low+1,end); 
	 
} 

//������������
void QuickSort(int *r,int n){
	QSort(r,1,n);
}
int main(){
	int k,n;
	printf("����������Ԫ�ظ���");
	scanf("%d",&n);
	printf("����������λ����ӽ������ĸ���");
	scanf("%d",&k);
	int a[n+1],b[n+1];//0��λ���� 
	printf("ԭ����Ϊ��");
	for(int i=1;i<=n;i++){
		a[i]=rand()%100;
		printf("%d ",a[i]);
	} 	
	QuickSort(a,n);
	int mid;
	mid=n%2 ?a[n/2+1]:(a[n/2]+a[n/2+1])/2;

	for(int i=1;i<=n;i++)
	b[i]=abs(a[i]-mid);
	QuickSort(b,n);
	int temp=b[k]; 

    printf("\n����λ����ӽ���%d����Ϊ��",k);
    for(int i=1;i<=n;i++)			
	if(abs(a[i]-mid)<=temp)
	printf("%d ",a[i]);
	return 0;
}   