package algorithm;

import java.util.Scanner;

public class Machine_Burden {
	public static final int S = 1;//�������Ĳ���Ϊ1����λ
	
	public static void machine_burden(int N,int M) {
		int ukbool[] = new int[M];//ukbool[k]��ʾ��k�꣬�߸��ɻ������������һ����û�����������ȡ0|1
		double ck[] = new double[M+1];//����ֵ������ϵ��
		double sk[] = new double[M];//���������û�������
		double uk[] = new double[M];//������ĸ߸��ɻ�������
		//double fk[] = new double[M];
		//����ck,ukbool 
		ck[M]=0;
		double ck_0;double ck_1;
		for(int i=M-1;i>=0;i--) {
			ck_0=8*0+6*(S-0)+ck[i+1]*(0.4*0+0.9*(S-0));//ukbool[i]ȡ0
		    ck_1=8*1+6*(S-1)+ck[i+1]*(0.4*1+0.9*(S-1));//ukbool[i]ȡ1
		    //ukbool[i]ȡʹ��ck[i]����ֵ
		    if(ck_0>ck_1){
				ukbool[i]=0;ck[i]=ck_0;
			}
			else{
				ukbool[i]=1;ck[i]=ck_1;
			}
		}
		//ͨ��ukbool����sk,uk
		sk[0]=N;uk[0]=N*ukbool[0];
		//fk[0]=ck[0]*sk[0];
		for(int i=1;i<=M-1;i++) {
			sk[i]=(0.4*ukbool[i-1]+0.9*(S-ukbool[i-1]))*sk[i-1];//״̬ת�Ʒ���
			uk[i]=sk[i]*ukbool[i];
			//fk[i]=ck[i]*sk[i];
		}
		//��ӡ
		System.out.print("���������û�������Ϊ\n");
		for(int i=0;i<M;i++)
			System.out.print(sk[i]+"	");
		System.out.print("\n������ĸ߸��ɻ�������Ϊ\n");
		for(int i=0;i<M;i++)
			System.out.print(uk[i]+"	");
		System.out.print("\n���ž��߱����µ���߲���Ϊ��"+ck[0]*sk[0]);
		
	}

	public static void main(String[] args) {
		System.out.println("��������û����������ƻ�����");
		Scanner input=new Scanner(System.in);
		int N=input.nextInt();
		int M=input.nextInt();
		System.out.println("��������:"+N+",�ƻ�����:"+M);
		machine_burden(N,M);
				
	}

}
