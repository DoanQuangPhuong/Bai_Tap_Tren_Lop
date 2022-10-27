#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#define MAXSIZE 50
typedef int Itemtype;
void nhapMaTranVuong(Itemtype arr[][MAXSIZE], int &n);
void xuatMaTranVuong(Itemtype arr[][MAXSIZE], int n);
void taoMaTranNgayNhien(Itemtype arr[][MAXSIZE], int n);
void xuatPhanTuThuocDuongCheoChinh(Itemtype arr[][MAXSIZE], int n);
int timMaxThuocTamGiacTrenDuongCheoChinh(Itemtype arr[][MAXSIZE], int n);
void swap(int &a, int &b);
void sapXepDuongCheoPhuTangDan(Itemtype arr[][MAXSIZE], int n);
void sapXepDuongCheoPhuGiamDan(Itemtype arr[][MAXSIZE], int n);
void sapXepDongChanGiamDan(Itemtype arr[][MAXSIZE], int n,int k);
void sapXepDongLeTangDan(Itemtype arr[][MAXSIZE], int n,int k);
void sapXepDongChiSoLeTangDanChanGiamDan(Itemtype arr[][MAXSIZE], int n);
void sapXepCotChanTangDan(Itemtype arr[][MAXSIZE], int n,int k);
void sapXepCotLeGiamDan(Itemtype arr[][MAXSIZE], int n,int k);
void sapXepCotLeGiamDanChanTang(Itemtype arr[][MAXSIZE], int n);
void xuatCacPhanTuSongSongCheoChinh(Itemtype arr[][MAXSIZE], int n);
void duaGiaTriChanLenDauMang(int arr[][MAXSIZE], int viTriChan,int k);
void chanLenDauLeXuongDuoi(int arr[][MAXSIZE], int n);
void showMenu();
void suLi();
int main(){
	suLi();
	
	return 0;
}
void nhapMaTranVuong(Itemtype arr[][MAXSIZE], int &n){
	do{
		printf("\n\tMA TRAN CAP : ");scanf("%d", &n);
		if(n <= 0)
			printf("\n\tVui long nhap lai. Cap ma tran!!!!");
	}while(n <= 0);
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			printf("\tarr[%d][%d] =  ", i,j);scanf("%d", &arr[i][j]);
		}
		printf("\n");
	}
}
void xuatMaTranVuong(Itemtype arr[][MAXSIZE], int n){
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			printf("%3d ",arr[i][j]);
		}
		printf("\n");
	}
}
void taoMaTranNgayNhien(Itemtype arr[][MAXSIZE], int n){
	do{
		printf("\n\tMA TRAN CAP : ");scanf("%d", &n);
		if(n <= 0)
			printf("\n\tVui long nhap lai. Cap ma tran!!!!");
	}while(n <= 0);
	printf("\t\t\tMA TRAN SAU KHI DUOC TAO NGAU NHIEN ");
	int a = -50;
	int b = 50;
	srand((unsigned)time(NULL));
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			arr[i][j] = a + rand() % (b - a + 1);
		}
		printf("\n");
	}
	xuatMaTranVuong(arr,n);
}
void xuatPhanTuThuocDuongCheoChinh(Itemtype arr[][MAXSIZE], int n){
	printf("\n\t\tPHAN TU THUOC DUONG CHEO CHINH la : ");
	for(int i = 0;i < n;i++){
		printf("%3d", arr[i][i]);
	}
}
int timMaxThuocTamGiacTrenDuongCheoChinh(Itemtype arr[][MAXSIZE], int n){
	int max = 0;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			if(i < j)
			{
				if(arr[i][j] > max)
					max = arr[i][j];
			}
		}
	}
	return max;
}
void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}
void sapXepDuongCheoPhuTangDan(Itemtype arr[][MAXSIZE], int n){
	printf("\n\tMA TRAN SAU KHI SAP XEP DUONG CHEO PHU TANG DAN \n");
	for(int i = 0;i < n - 1;i++){
		for(int j = i + 1;j < n;j++){
			if(arr[i][n - 1 - i] > arr[j][n - 1 - j])
				swap(arr[i][n - 1 - i],arr[j][n - 1 - j]);
		}
	}
	xuatMaTranVuong(arr,n);
}
void sapXepDuongCheoPhuGiamDan(Itemtype arr[][MAXSIZE], int n){
	printf("\n\tMA TRAN SAU KHI SAP XEP DUONG CHEO PHU GIAM DAN \n");
	for(int i = 0;i < n - 1;i++){
		for(int j = i + 1;j < n;j++){
			if(arr[i][n - 1 - i] < arr[j][n - 1 - j])
				swap(arr[i][n - 1 - i],arr[j][n - 1 - j]);
		}
	}
	xuatMaTranVuong(arr,n);
}
//======================================================================================================================
void sapXepDongChanGiamDan(Itemtype arr[][MAXSIZE], int n,int k){
	for(int i = 0;i < n - 1;i++){
		for(int j = i + 1;j < n;j++){
			if(arr[k][i] < arr[k][j])
				swap(arr[k][i],arr[k][j]);
		}
	}	
}
void sapXepDongLeTangDan(Itemtype arr[][MAXSIZE], int n,int k){
	for(int i = 0;i < n - 1;i++){
		for(int j = i + 1;j < n;j++){
			if(arr[k][i] > arr[k][j])
				swap(arr[k][i],arr[k][j]);
		}
	}	
}
void sapXepDongChiSoLeTangDanChanGiamDan(Itemtype arr[][MAXSIZE], int n){
	printf("\n\tSAP XEP DONG CO CHI SO LE TANG DAN, DONG CO CHI SO CHAN GIAM DAN \n");
	for(int i = 0;i < n;i++){
		if(i % 2 == 0)
		{
			sapXepDongChanGiamDan(arr,n,i);
		}
		else
		{
			sapXepDongLeTangDan(arr,n,i);
		}
	}
	xuatMaTranVuong(arr,n);
}
//========================================================================================================================
void sapXepCotChanTangDan(Itemtype arr[][MAXSIZE], int n,int k){
	for(int i = 0;i < n - 1;i++){
		for(int j = i + 1;j < n;j++){
			if(arr[i][k] > arr[j][k])
				swap(arr[i][k],arr[j][k]);
		}
	}	
}
void sapXepCotLeGiamDan(Itemtype arr[][MAXSIZE], int n,int k){
	for(int i = 0;i < n - 1;i++){
		for(int j = i + 1;j < n;j++){
			if(arr[i][k] < arr[j][k])
				swap(arr[i][k],arr[j][k]);
		}
	}	
}
void sapXepCotLeGiamDanChanTang(Itemtype arr[][MAXSIZE], int n){
	printf("\n\tSAP XEP COT TANG DAN THEO CHI SO CHAN, GIAM DAN THEO CHI SO LE \n");
	for(int i = 0;i < n;i++){
		if(i % 2 == 0)
		{
			sapXepCotChanTangDan(arr,n,i);
		}
		else
		{
			sapXepCotLeGiamDan(arr,n,i);
		}
	}
	xuatMaTranVuong(arr,n);
}
void duaGiaTriChanLenDauMang(int arr[][MAXSIZE], int viTriChan,int Dong){//Dua gia tri chan len dau mang
	int temp = arr[Dong][viTriChan];//Gia tri chan
	for(int i = viTriChan; i > 0;i--){
		arr[Dong][i] = arr[Dong][i - 1]; //Dich ve sau 
	}
	arr[Dong][0] = temp;//Gan Gia tri DAU TIEN MOI DONG = temp tk la so Chan Vua Duoc Tim thay
}

void chanLenDauLeXuongDuoi(int arr[][MAXSIZE], int n){//Chan len dau, le xuong duoi
	printf("\n\tMA TRAN SAU KHI DUOC SAP XEP CHAN LEN DAU NAM,LE XUONG DUOI \n");
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			if(arr[i][j] % 2 == 0){
				duaGiaTriChanLenDauMang(arr,j,i);
			}
		}
	}
	xuatMaTranVuong(arr,n);
}
void xuatCacPhanTuSongSongCheoChinh(Itemtype arr[][MAXSIZE], int n){
	printf("\nPHAN TU NAM SONG SONG VS DUONG CHEO CHINH : ");
	for(int i = 0;i < n;i++){
		int row = 0;
		int col = i;
		while(row < n && col < n){
			printf("%3d %3d", arr[row][col],arr[col][row]);
			row++;
			col++;
		}
	}
}
void tongCacPhanTuSongSongCheoChinh(Itemtype arr[][MAXSIZE], int n){
	printf("\nPHAN TU NAM SONG SONG VS DUONG CHEO CHINH : ");
	for(int i = 0;i < n;i++){
		int row = 0;
		int col = i;
		while(row < n && col < n){
			printf("%3d %3d", arr[row][col],arr[col][row]);
			row++;
			col++;
		}
	}
}
void showMenu(){
	printf("\n*************************************************************************************");
	printf("\n*                                        MENU                                       *");
	printf("\n*************************************************************************************");
	printf("\n* 0 De thoat khoi chuong trinh                                                      *");
	printf("\n* 1 Nhap/Xuat chuong trinh                                                          *");
	printf("\n* 2 Tao Ma tran NGAU NHIEN                                                          *");
	printf("\n* 3 Xuat cac phan tu THUOC DUONG CHEO CHINH                                         *");
	printf("\n* 4 Tim phan tu MAX thuoc TAM GIAC TREN CUA DUONG CHEO CHINH                        *");
	printf("\n* 5 Sap xep duong CHEO PHU tang/giam dan                                            *");
	printf("\n* 6 Sap xep Ma Tran sao cho DONG chi so le TANG, chi so chan GIAM                   *");
	printf("\n* 7 Sap xep Ma Tran sao cho COT chi so le GIAM, chi so chan TANG                    *");
	printf("\n* 8 Kiem Tra Ma Tran Co DOI XUNG QUA Duong CHEO CHINH HAY KHONG                     *");
	printf("\n* 9 sap xep ma tran sao cho CHAN nam DAU mang,LE nam Dong CUOI Mang                 *");
	printf("\n* 10 Sap xep sao cho PT NAM TREN DUONG CHEO CHINH song song VOI CHEO CHINH TANG DAN *");
	printf("\n* 11 Xuat cac phan tu thuoc duong CHEO SONG SONG VS DUONG CHEO CHINH                *");
	printf("\n* 12 Sap Xep Ma Tran Tang Dan Theo Kieu ZICZAC                                      *");
	printf("\n*************************************************************************************");
}
void suLi(){
	int n,luachon;
	Itemtype arr[MAXSIZE][MAXSIZE];
	do{
		showMenu();
		do{
		printf("\n\tLua Chon Cua Ban La : ");scanf("%d", &luachon);
		if(luachon < 0)
			printf("\n\tVui long Nhap lai! Lua Chon Cua Ban!!!!");
		}while(luachon < 0);
		switch(luachon){
			case 1:{
				nhapMaTranVuong(arr,n);
				printf("\n\tMA TRAN VUONG SAU KHI DUOC XUAT \n");
				xuatMaTranVuong(arr,n);
				break;
			}
			case 2:{
				taoMaTranNgayNhien(arr,n);
				break;
			}
			case 3:{
				xuatPhanTuThuocDuongCheoChinh(arr,n);
				break;
			}
			case 4:{
				printf("\n\tPHAN TU LON NHAT THUOC TAM GIAC TREN DUONG CHEO CHINH LA %d  ", timMaxThuocTamGiacTrenDuongCheoChinh(arr,n));
				break;
			}
			case 5:{
				sapXepDuongCheoPhuTangDan(arr,n);
				sapXepDuongCheoPhuGiamDan(arr,n);
				break;
			}
			case 6:{
				sapXepDongChiSoLeTangDanChanGiamDan(arr,n);
				break;
			}
			case 7:{
				sapXepCotLeGiamDanChanTang(arr,n);
				break;
			}
			case 8:{
				xuatCacPhanTuSongSongCheoChinh(arr,n);
				break;
			}
			case 9:{
				chanLenDauLeXuongDuoi(arr,n);
				break;
			}
		}
	}while(luachon != 0);
	
}


