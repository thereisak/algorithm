package algorithm;

import java.util.Scanner;

public class Machine_Burden {
	public static final int S = 1;//假设各年的产量为1个单位
	
	public static void machine_burden(int N,int M) {
		int ukbool[] = new int[M];//ukbool[k]表示第k年，高负荷机器数量相对那一年完好机器数的量，取0|1
		double ck[] = new double[M+1];//最优值函数的系数
		double sk[] = new double[M];//各年初的完好机器数量
		double uk[] = new double[M];//各年初的高负荷机器数量
		//double fk[] = new double[M];
		//计算ck,ukbool 
		ck[M]=0;
		double ck_0;double ck_1;
		for(int i=M-1;i>=0;i--) {
			ck_0=8*0+6*(S-0)+ck[i+1]*(0.4*0+0.9*(S-0));//ukbool[i]取0
		    ck_1=8*1+6*(S-1)+ck[i+1]*(0.4*1+0.9*(S-1));//ukbool[i]取1
		    //ukbool[i]取使得ck[i]最大的值
		    if(ck_0>ck_1){
				ukbool[i]=0;ck[i]=ck_0;
			}
			else{
				ukbool[i]=1;ck[i]=ck_1;
			}
		}
		//通过ukbool计算sk,uk
		sk[0]=N;uk[0]=N*ukbool[0];
		//fk[0]=ck[0]*sk[0];
		for(int i=1;i<=M-1;i++) {
			sk[i]=(0.4*ukbool[i-1]+0.9*(S-ukbool[i-1]))*sk[i-1];//状态转移方程
			uk[i]=sk[i]*ukbool[i];
			//fk[i]=ck[i]*sk[i];
		}
		//打印
		System.out.print("各年初的完好机器数量为\n");
		for(int i=0;i<M;i++)
			System.out.print(sk[i]+"	");
		System.out.print("\n各年初的高负荷机器数量为\n");
		for(int i=0;i<M;i++)
			System.out.print(uk[i]+"	");
		System.out.print("\n最优决策变量下的最高产量为："+ck[0]*sk[0]);
		
	}

	public static void main(String[] args) {
		System.out.println("请输入完好机器数量，计划年数");
		Scanner input=new Scanner(System.in);
		int N=input.nextInt();
		int M=input.nextInt();
		System.out.println("机器数量:"+N+",计划年数:"+M);
		machine_burden(N,M);
				
	}

}
