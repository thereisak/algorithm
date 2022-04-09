//实现O(nlogn)，未实现O(n) 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void QSort(int *r,int low ,int high){
	if(low>=high)return;
	int begin=low,end=high;
	r[0]=r[low];//用L->r[0]记录枢轴L->r[low]的值 
	while(low<high){
		while(low<high&&r[high]>=r[0]){//high向左探寻小于枢轴的值 
			high--;
		}
		if(r[high]<r[0]){r[low]=r[high];} 		
		while(low<high&&r[low]<=r[0]){//low向右探寻大于于枢轴的值 
			low++;
		}
		if(r[low]>r[0]){r[high]=r[low];} 		
	}
	r[low]=r[0];//枢轴的值归位 
	QSort(r,begin,low-1);//low作为新的枢轴将子表分为两部分递归整理 
	QSort(r,low+1,end); 
	 
} 

//快速排序（升序）
void QuickSort(int *r,int n){
	QSort(r,1,n);
}
int main(){
	int k,n;
	printf("请输入数组元素个数");
	scanf("%d",&n);
	printf("请输入与中位数最接近的数的个数");
	scanf("%d",&k);
	int a[n+1],b[n+1];//0号位不用 
	printf("原数组为：");
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

    printf("\n与中位数最接近的%d个数为：",k);
    for(int i=1;i<=n;i++)			
	if(abs(a[i]-mid)<=temp)
	printf("%d ",a[i]);
	return 0;
}   