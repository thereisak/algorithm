#include <stdio.h>
int IntPartCount(int n, int m){//n为待求划分数整数 ，m为最大加数 
     if (n == 1 || m == 1)//递归出口 
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
	printf("6的最大划分数为%d\n",count);
	return 0;
} 