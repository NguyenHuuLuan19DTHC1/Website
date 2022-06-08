#include<stdio.h>
#include<conio.h>

#define MAX 100

//===============================================
typedef struct CuonSach
{
	int masach;
	char tensach[40];    // string
	float gia;
}Sach;
//===============================================
void Nhap1Sach(Sach &x)
{
	printf("Nhap ma sach: ");
	scanf("%d", &x.masach);
	printf("Nhap ten sach: ");
	fflush(stdin); gets(x.tensach);
	
	printf("Nhap gia sach: ");
	fflush(stdin); scanf("%f", &x.gia);
}
//===============================================
void TieuDe() 
{
	printf("\n |========|=======================================|=========|");
	printf("\n |%8s|%-39s|%9s|","MA SACH","TEN SACH","GIA");
	printf("\n |========|=======================================|=========|");
}
//==========================================   
void Xuat1Sach(Sach x)
{
	printf("\n |%8d|%-39s|%9.2f|", x.masach, x.tensach, x.gia);
}
//===============================================
void NhapSL(int &n)
{
	do
	{
		printf("Nhap so luong cuon sach (0 < N <= %d): ", MAX);
   		scanf("%d",&n);
   		if(n<1 || n>MAX) printf("Nhap sai\n");
   }while(n<1 || n>MAX);
}
//===============================================
void NhapMang(Sach a[],int n)
{
	for(int i=0; i<n; i++)
	{
		printf("Nhap thong tin cuon sach thu %d: \n", i+1);
		Nhap1Sach(a[i]);
	}
}
//===============================================
void XuatMang(Sach a[],int n)
{
	TieuDe() ;
	for(int i=0; i<n; i++)
	{
		Xuat1Sach(a[i]);
	}
	printf("\n |========|=======================================|=========|");
}
//===============================================
int LinearSearch_MaSach(Sach a[],int n, int key)
{
	int i=0;
	while( i<n && key != a[i].masach)
		 i++;
	
	if(i<n)	return i;
	else return -1;
}


//===============================================
int main()
{
	Sach a[MAX]={
					{44444, "Go cua trai tim", 35.15},
					{66666, "Ai Cho toi tinh Yeu", 40.49},
					{11111, "Tinh Yeu Que Huong", 32.36},
					{99999, "Dat Nuoc va Con Nguoi", 65.40},
					{33333, "Mai Mai Ben Nhau", 32.15},
					{22222, "Tinh Nhat Phai", 38.28},
					{88888, "Anh O Dau Song, Em Cuoi Song", 92.41},
					{10001, "Lan va Diep", 73.65},
					{77777, "Hoa Trinh Nu", 12.42},
					{55555, "Khoa Hoc Ky Thuat", 81.75}
				};
	int n=10;
	int X;
	int vt;
	char ph;
//	NhapSL(n);
//	NhapMang(a,n);
	XuatMang(a,n);
	
	do
	{

		printf("\nNhap ma sach can tim: ");
		scanf("%d", &X);
		vt = LinearSearch_MaSach(a, n,  X);
		if(vt == -1) 
			printf("\nTim tuyen tinh khong co");
		else 
		{
			printf("\nTim tuyen tinh:");
			printf("\n |========|=======================================|=========|");
			Xuat1Sach(a[vt]);
			printf("\n |========|=======================================|=========|");
		}
		printf("\nBan tiep tuc nua khong[Y/N]: ");
		ph = getche();

	}while(ph=='y'||ph=='Y');
	
	printf("\n\n\n\n\n");
	return 0;	
}

