#include <stdio.h>
int IntPartCount(int n, int m){//nΪ���󻮷������� ��mΪ������ 
     if (n == 1 || m == 1)//�ݹ���� 
        return 1;
    else if (n < m)
         return IntPartCount(n, n);
    else if (n == m)
         return 1 + IntPartCount(n, m-1);
     else
         return IntPartCount(n,m-1) + IntPartCount(n-m, m);
}
int main(){
	int count=IntPartCount(6,6);
	printf("6����󻮷���Ϊ%d\n",count);
	return 0;
} 