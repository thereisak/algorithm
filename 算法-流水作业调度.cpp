//��ˮ��ҵ���������Johnson�㷨 
#include <stdio.h>
struct Jobtype{//������ҵ�ṹ��
    int key,index;//key��¼a[i],b[i]�еĽ�С�� 
    bool job;//���飬true��ʾN1�飨 a[i]<b[i]�� 
};
//������ʵ�ֵĿ�������ʵ��sort(d,n) 
void QSort(Jobtype *r,int low ,int high){
	if(low>=high)return;
	int begin=low,end=high;
	Jobtype temp=r[low];//��temp��¼����r[low]��ֵ 
	while(low<high){
		while(low<high&&r[high].key>=temp.key){//high����̽ѰС�������ֵ 
			high--;
		}
		if(r[high].key<temp.key){r[low]=r[high];} 		
		while(low<high&&r[low].key<=temp.key){//low����̽Ѱ�����������ֵ 
			low++;
		}
		if(r[low].key>temp.key){r[high]=r[low];} 		
	}
	r[low]=temp;//�����ֵ��λ 
	QSort(r,begin,low-1);//low��Ϊ�µ����Ὣ�ӱ��Ϊ�����ֵݹ����� 
	QSort(r,low+1,end); 
	 
} 
//������������
void QuickSort(Jobtype *r,int n){
	QSort(r,0,n-1);
}

void Flowshop(int n,int a[],int b[],int c[]){
//nΪ��ҵ����������a,b�ֱ�Ϊ������ҵ��M1,M2�ϵļӹ�ʱ�䣬����c��¼���ŵ���˳�� 
    Jobtype *d =new Jobtype[n];//����N����ҵ 
    for(int i=0;i<n;i++){ //��ʼ����ҵ 	  
        d[i].key = a[i]>b[i]?b[i]:a[i];
		d[i].job = a[i]<=b[i];//����
		d[i].index = i; 
    }
    QuickSort(d,n);//��keyֵ����ҵ���� 
    //sort(d,n+d,cmp);//
    int j=0,k=n-1;
    for(int i=0;i<n;i++){    
        if(d[i].job ==true)//�����N1�� ,��a[i]��������߼�¼ 
            c[j++]=d[i].index;
        else
            c[k--]=d[i].index;//�����N2�飬��b[i]�������ұ߼�¼��ʵ�ֽ���  
    }
    //��ӡ˳�� 
    printf("\n���żӹ�˳��Ϊ��");
	for(int i=0; i<n; i++)
	printf("%d	",c[i]);
    //����̼ӹ�ʱ�� 
    j=a[c[0]];//j��¼M1����ʱ�� 
    k=j+b[c[0]];//k��¼M2����ʱ�䣬������ʱ�� 
    for(int i=1;i<n;i++){    
    j=j+a[c[i]];
    k= j<k ? k+b[c[i]] : j+b[c[i]] ;//ȡ���ں�ӹ���Ļ��� 
    }
    //delete d;
    printf("\n��̼ӹ�ʱ��Ϊ%d	",k); 
}
int main(){	
    int n=6; 
	int a[] = {3,5,7,1,9,4};
	int b[] = {2,4,6,7,3,5};
	int c[n];//c[]��¼�ӹ�˳�� 
	printf("������ҵ��M1�ϵļӹ�ʱ��Ϊ��");
	for(int i=0; i<n; i++)
	printf("%d	",a[i]);
	printf("\n������ҵ��M2�ϵļӹ�ʱ��Ϊ��");
	for(int i=0; i<n; i++)
	printf("%d	",b[i]);	
	Flowshop(n,a,b,c); 
    return 0;
}