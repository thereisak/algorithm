//流水作业调度问题的Johnson算法 
#include <stdio.h>
struct Jobtype{//定义作业结构体
    int key,index;//key记录a[i],b[i]中的较小者 
    bool job;//分组，true表示N1组（ a[i]<b[i]） 
};
//调用已实现的快速排序实现sort(d,n) 
void QSort(Jobtype *r,int low ,int high){
	if(low>=high)return;
	int begin=low,end=high;
	Jobtype temp=r[low];//用temp记录枢轴r[low]的值 
	while(low<high){
		while(low<high&&r[high].key>=temp.key){//high向左探寻小于枢轴的值 
			high--;
		}
		if(r[high].key<temp.key){r[low]=r[high];} 		
		while(low<high&&r[low].key<=temp.key){//low向右探寻大于于枢轴的值 
			low++;
		}
		if(r[low].key>temp.key){r[high]=r[low];} 		
	}
	r[low]=temp;//枢轴的值归位 
	QSort(r,begin,low-1);//low作为新的枢轴将子表分为两部分递归整理 
	QSort(r,low+1,end); 
	 
} 
//快速排序（升序）
void QuickSort(Jobtype *r,int n){
	QSort(r,0,n-1);
}

void Flowshop(int n,int a[],int b[],int c[]){
//n为作业个数，数组a,b分别为各个作业在M1,M2上的加工时间，数组c记录最优调度顺序 
    Jobtype *d =new Jobtype[n];//定义N个作业 
    for(int i=0;i<n;i++){ //初始化作业 	  
        d[i].key = a[i]>b[i]?b[i]:a[i];
		d[i].job = a[i]<=b[i];//分组
		d[i].index = i; 
    }
    QuickSort(d,n);//按key值对作业排序 
    //sort(d,n+d,cmp);//
    int j=0,k=n-1;
    for(int i=0;i<n;i++){    
        if(d[i].job ==true)//如果是N1组 ,按a[i]递增从左边记录 
            c[j++]=d[i].index;
        else
            c[k--]=d[i].index;//如果是N2组，按b[i]递增从右边记录，实现降序  
    }
    //打印顺序 
    printf("\n最优加工顺序为：");
	for(int i=0; i<n; i++)
	printf("%d	",c[i]);
    //求最短加工时间 
    j=a[c[0]];//j记录M1的总时间 
    k=j+b[c[0]];//k记录M2的总时间，含空闲时间 
    for(int i=1;i<n;i++){    
    j=j+a[c[i]];
    k= j<k ? k+b[c[i]] : j+b[c[i]] ;//取决于后加工完的机器 
    }
    //delete d;
    printf("\n最短加工时间为%d	",k); 
}
int main(){	
    int n=6; 
	int a[] = {3,5,7,1,9,4};
	int b[] = {2,4,6,7,3,5};
	int c[n];//c[]记录加工顺序 
	printf("各个作业在M1上的加工时间为：");
	for(int i=0; i<n; i++)
	printf("%d	",a[i]);
	printf("\n各个作业在M2上的加工时间为：");
	for(int i=0; i<n; i++)
	printf("%d	",b[i]);	
	Flowshop(n,a,b,c); 
    return 0;
}