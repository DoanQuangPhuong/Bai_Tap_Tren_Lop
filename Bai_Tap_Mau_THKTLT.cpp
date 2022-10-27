#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#define MAXSIZE 100
typedef float Itemtype;
struct SANPHAM{
	char msp[6];
	char ten[20];
	float dongia;
	int soluong;
};
void showMenu();
void inputMang1C(Itemtype *arr, int &n);
void ouputMang1C(Itemtype *arr, int n);
void sinhNgauNhien(Itemtype *arr, int &n);
void xuatGiaTriVaDiaChiPTtrongMang(Itemtype *arr, int n);
void delete1PhanTu(Itemtype *arr, int &n, float &x);
void them1PTvaoMang(Itemtype *arr, int &n, int &k, float &GT);
//=============================================================
void nhapMang2C(int arr[][MAXSIZE], int &n);
void xuatMang2Chieu(int arr[][MAXSIZE], int n);
void sinhMangNgauNhien(int arr[][MAXSIZE], int &n);
void swap(int &a, int &b);
void sapChanTungDong(int arr[][MAXSIZE], int n, int k);
void sapXepMangChanTangDan(int arr[][MAXSIZE], int n);
void sapXepKieuSelectionsort(int arr[][MAXSIZE], int n);
//==============================================================
void nhap1SanPham(SANPHAM &sp);
void xuat1SanPham(SANPHAM sp);
void nhapDSSP(SANPHAM dssp[], int &n);
void xuatDSSP(SANPHAM dssp[], int n);
void swapSP(SANPHAM &x,SANPHAM &y);
void sapXepTangDanTheoGia(SANPHAM dssp[], int n);
void xuatThongTinTheoMa(SANPHAM dssp[], int n);
void suLi();
int main(){
	suLi();

	
	return 0; 
}
void showMenu(){
	printf("\n********************************************************************");
	printf("\n*                                  MENU                            *");
	printf("\n********************************************************************");
	printf("\n* 0 De Ket Thuc Chuong Trinh                                       *");
	printf("\n* 1 Mang mot Chieu                                                 *");
	printf("\n* 2 Ma Tran Vuong                                                  *");
	printf("\n* 3 Mang Cau Truc [Thong Tin San Pham]                             *");
	printf("\n********************************************************************");
	printf("\n********************************************************************");
}
void suLi(){
	int luachon;
	do{
		showMenu();
		do{
			printf("\n\tLua Chon Cua Ban La : ");scanf("%d", &luachon);
			if(luachon < 0)
				printf("\n\tLoi!!Vui long nhap lai");
		}while(luachon < 0);
		switch(luachon){
			case 1:{
				float x,gt;
				int n,k;
				Itemtype arr[MAXSIZE];
				inputMang1C(arr,n);
				printf("\n\t\tMA TRAN SAU KHI DUOC XUAT : ");
				ouputMang1C(arr,n);
				printf("\n\tMANG SAU KHI XOA : ");
				delete1PhanTu(arr,n,x);
				printf("\n\tMANG SAU KHI THEM PHAN TU VAO  : ");
				them1PTvaoMang(arr,n,k,gt);
				sinhNgauNhien(arr,n);
				printf("\n\tXUAT GIA TRI VA DIA CHI CUA MANG ");
				xuatGiaTriVaDiaChiPTtrongMang(arr,n);
				break;
			}
			case 2:{
				int arr[MAXSIZE][MAXSIZE],n;
				nhapMang2C(arr,n);
				printf("\n\tMANG 2 CHIEU SAU KHI DUOC XUAT \n");
				xuatMang2Chieu(arr,n);
//				sinhMangNgauNhien(arr,n);
				sapXepMangChanTangDan(arr,n);
				sapXepKieuSelectionsort(arr,n);
				break;
			}
			case 3:{
				int n;
				SANPHAM sp;
				SANPHAM dssp[MAXSIZE];
				nhapDSSP(dssp,n);
				xuatDSSP(dssp,n);
				sapXepTangDanTheoGia(dssp,n);
				xuatThongTinTheoMa(dssp,n);
				break;
			}
		}
		
	}while(luachon != 0);
}
//                                           MANG 1 CHIEU
void inputMang1C(Itemtype *arr, int &n){
	do{
		printf("So luong Phan Tu : ");scanf("%d", &n);
		if(n < 0 || n > MAXSIZE)
			printf("\n\tLoi!!!");
	}while(n < 0 || n > MAXSIZE);
	for(int i = 0;i < n;i++){
		printf("\narr[%d] = ", i);scanf("%f", arr + i);
	}
}
void ouputMang1C(Itemtype *arr, int n){
	for(int i = 0;i < n;i++){
		printf("%.2f\t", *(arr + i));
	}
}
void sinhNgauNhien(Itemtype *arr, int &n){
	printf("\n\tNhap so phan tu Sinh Ngau Nhien : ");scanf("%d", &n);
	printf("\n\tMANG sau Khi Tao Ngau Nhien  ");
	srand((unsigned)time(NULL));
	for(int i = 0;i < n;i++){
		*(arr + i) = (rand() % 101 * 0.1);
	}
	ouputMang1C(arr,n);
}
void xuatGiaTriVaDiaChiPTtrongMang(Itemtype *arr, int n){
	for(int i = 0;i < n;i++)
	{
		printf("\n\tGia tri %.2f co dia chi %x",*(arr + i),arr + i);
	}
}
void delete1PhanTu(Itemtype *arr, int &n, float &x){
	printf("\n\tPT can xoa : ");scanf("%f", &x);
	for(int i = x;i < n - 1;i++){
		*(arr + i) = *(arr + i + 1);
	}
	n--;
	ouputMang1C(arr,n);
}
void them1PTvaoMang(Itemtype *arr, int &n, int &k, float &GT){
	printf("\n\tVi tri can them : ");scanf("%d", &k);
	printf("\n\tGia tri : ");scanf("%f", &GT);
	for(int i = n - 1;i >= k;i--){
		*(arr + i + 1) = *(arr + i);
	}
	*(arr + k) = GT;
	n++;
	ouputMang1C(arr,n);
}
//float chanDauTien(Itemtype *arr, int n){
//	for(int i = 0;i < n;i++){
//		if((*(arr + i)) % 2 == 0)
//			return *(arr + i);
//	}
//	return -1.0;
//}

//                                  PHAN MA TRAN VUONG
//===================================================================================
void nhapMang2C(int arr[][MAXSIZE], int &n){
	do{
		printf("\nMa Tran Cap : ");scanf("%d", &n);
		if(n < 0 || n > MAXSIZE)
			printf("\n\tCap Ma Tran Khong Hop Le!!!!");
	}while(n < 0 || n > MAXSIZE);
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			printf("\narr[%d][%d] =  ",i,j);scanf("%d", &arr[i][j]);
		}
	}
}
void xuatMang2Chieu(int arr[][MAXSIZE], int n){
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			printf("%3d",arr[i][j]);
		}
		printf("\n");
	}
}
void sinhMangNgauNhien(int arr[][MAXSIZE], int &n){
	do{
		printf("\n\tNhap Cap Sinh Ngau Nhien : ");scanf("%d", &n);
		if(n < 0 || n > MAXSIZE)
			printf("\n\tVui long nhap lai!!!!");
	}while(n < 0);
	printf("\n\tMANG SAU KHI DUOC SINH NGAU NHIEN \n");
	int a = -50;
	int b = 50;
	srand((unsigned)time(NULL));
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			arr[i][j] = a + rand() % (b - a + 1);
		}
		printf("\n");
	}
	xuatMang2Chieu(arr,n);
}
void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}
void sapChanTungDong(int arr[][MAXSIZE], int n, int k){
	for(int i = 0;i < n;i++){
		if(arr[k][i] % 2 == 0){
			for(int j = i + 1;j < n;j++){
				if(arr[k][i] > arr[k][j] && arr[k][j] % 2 == 0)
					swap(arr[k][i], arr[k][j]);
			}
		}	
	}
}
void sapXepMangChanTangDan(int arr[][MAXSIZE], int n){
	printf("\n\tMANG SAU KHI SAP XEP CHAN TANG DAN \n");
	for(int i = 0;i < n;i++){
		sapChanTungDong(arr,n,i);
	}
	xuatMang2Chieu(arr,n);
}
void sapXepKieuSelectionsort(int arr[][MAXSIZE], int n){
	printf("\n\tMANG DUOC SAP XEP GIAM DAN THEO DUONG CHEO PHU \n");
	for(int i = 0;i < n - 1;i++){
		for(int j = i + 1;j < n;j++){
		if(arr[i][n - 1 - i] < arr[j][n - 1 - j]);
			swap(arr[i][n - 1 - i],arr[j][n - 1 - j]);
		}
	}
	xuatMang2Chieu(arr,n);
}
//                                    MANG CAU TRUC
//================================================================================

void nhap1SanPham(SANPHAM &sp){
	printf("\n\tMSSP : ");scanf("%s", &sp.msp);
	printf("\n\tTEN SP : ");
	fflush(stdin);
	gets(sp.ten);
	printf("\n\tGia : ");scanf("%f", &sp.dongia);
	printf("\n\tSo luong : ");scanf("%d", &sp.soluong);
}
void xuat1SanPham(SANPHAM sp){
	printf("%-10s%-20s%-10s%-15s","MaSP", "TenSP","Don Gia","So Luong");
	printf("\n%-10s%-20s%.2f%10d", sp.msp,sp.ten,sp.dongia,sp.soluong);	
}
void nhapDSSP(SANPHAM dssp[], int &n){
	do{
		printf("\n\tSo luong san Pham : ");scanf("%d", &n);
	}while(n < 0);
	for(int i = 0;i < n;i++){
		printf("\n\t\t\t\t\tThong Tin Sap Pham Thu %d", i + 1);
		nhap1SanPham(dssp[i]);
	}
}
void xuatDSSP(SANPHAM dssp[], int n){
	for(int i = 0;i < n;i++){
		printf("\n\t\tSan Pham Thu %d\n", i + 1);
		xuat1SanPham(dssp[i]);
	}
}
void swapSP(SANPHAM &x,SANPHAM &y){
	SANPHAM temp = x;
	x = y;
	y = temp;
}
void sapXepTangDanTheoGia(SANPHAM dssp[], int n){
	printf("\n\t\t\tDANH SACH SAN PHAM SAU KHI DUOC SAP XEP TANF DAN \n");
	for(int i = 0;i < n - 1;i++){
		for(int j = i + 1;j < n;j++){
			if(dssp[i].dongia > dssp[j].dongia)
				swapSP(dssp[i],dssp[j]);
		}
	}
	xuatDSSP(dssp,n);
}
void xuatThongTinTheoMa(SANPHAM dssp[], int n){
	int flag = 0;
	for(int i = 0;i < n;i++){
		if(strcmp(dssp[i].msp,"A01") == 0){
			printf("\n\t\tSAN PHAM CO MA SO [A01] THU %d \n ", i + 1);
			xuat1SanPham(dssp[i]);
			flag = 1;
		}	
	}
	if(flag == 0)
		printf("\n\t\tKHONG TIM THAY THONG TIN SAN PHAM [A01] !!!");
}

