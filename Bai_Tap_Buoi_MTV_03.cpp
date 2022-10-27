#include<conio.h>
#include<stdio.h>
#define MAXSIZE 100
typedef int Itemtype;
void nhapSoNguyenDuong(int &n);
void nhapMaTranVuong(Itemtype arr[][MAXSIZE], int &n);
void xuatMaTranVuong(Itemtype arr[][MAXSIZE], int n);
int maTranDoiXung(Itemtype arr[][MAXSIZE], int n);
int sumDuongCheoChinh(Itemtype arr[][MAXSIZE], int n);
int sumDuongCheoPhu(Itemtype arr[][MAXSIZE], int n);
int sumPhanTuDuoiCheoPhu(Itemtype arr[][MAXSIZE], int n);
int sumPhanTuTrenCheoPhu(Itemtype arr[][MAXSIZE], int n);
int kienTraMaTranCoDoiXungQuaDuongCheoChinh(Itemtype arr[][MAXSIZE], int n);
int kienTraMaTranCoDoiXungQuaDuongCheoPhu(Itemtype arr[][MAXSIZE], int n);
void swap(int &a, int &b);
void mangTangDanTheoCot(Itemtype arr[][MAXSIZE], int n);
int kiemTraDuongCheoChinhTangDan(Itemtype arr[][MAXSIZE], int n);
int kiemTraMangGiamDanTheoCot(Itemtype arr[][MAXSIZE], int n);
void sapXep1C(Itemtype b[], int k);
void mang1cPhu(Itemtype arr[][MAXSIZE], int n, Itemtype b[], int &k);
void sapXepMaTranTangDanTuTrenXuongDuoiTuTraiSangPhai(Itemtype arr[][MAXSIZE], int n,Itemtype b[]);
void xuatMaTranCoDoiXungQuaDuongCheoPhu(Itemtype arr[][MAXSIZE], int n);
void showMenu();
void thucThi();


int main(){
	thucThi();
	
	
	return 0;
}

void nhapSoNguyenDuong(int &n){
	do{
		scanf("%d", &n);
		if(n < 0)
			printf("\nVui long nhap lai!!!");
	}while(n < 0);
}

void nhapMaTranVuong(Itemtype arr[][MAXSIZE], int &n){
	do{
		printf("\nNhap so phan tu : ");scanf("%d", &n);
		if(n <= 0 || n >= MAXSIZE)
			printf("\nVui long nhap lai!!!");
		
	}while(n <= 0 || n >= MAXSIZE);
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++){
			printf("\narr[%d][%d] = ",i,j);scanf("%d", &arr[i][j]);
		}
}

void xuatMaTranVuong(Itemtype arr[][MAXSIZE], int n){
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			printf("%4d", arr[i][j]);
		}
		printf("\n");
	}
}

int maTranDoiXung(Itemtype arr[][MAXSIZE], int n){
	for(int i = 0;i < n - 1;i++)
		for(int j = i + 1;j < n;j++)
			return((arr[i][j] != arr[j][i]) ? 0 : 1);
}

int sumDuongCheoChinh(Itemtype arr[][MAXSIZE], int n){
	int sum = 0; 
	for(int i = 0;i < n;i++)
		sum += arr[i][i];
	return sum;
	
}

int sumDuongCheoPhu(Itemtype arr[][MAXSIZE], int n){
	int sum = 0; 
	for(int i = 0;i < n;i++)
		sum += arr[i][n - i - 1];
	return sum;
}

int sumPhanTuDuoiCheoPhu(Itemtype arr[][MAXSIZE], int n){
	int sum = 0;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++){
			if(i + j > n - 1)
				sum += arr[i][j];
		}
		return sum;
}

int sumPhanTuTrenCheoPhu(Itemtype arr[][MAXSIZE], int n){
	int sum = 0;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++){
			if(i + j < n - 1)
				sum += arr[i][j];
		}
		return sum;
}

int kienTraMaTranCoDoiXungQuaDuongCheoChinh(Itemtype arr[][MAXSIZE], int n){
	for(int i = 1;i < n;i++){
		for(int j = 0;j < i;j++){
			if(arr[i][j] != arr[j][i]){
				return 0;
			}
		}
	}
	return 1;
}

//Note

int kienTraMaTranCoDoiXungQuaDuongCheoPhu(Itemtype arr[][MAXSIZE], int n){
	for(int i = 0;i < n - 1;i++){
		for(int j = 0;j < n - 1 - i;j++){//
			if(arr[i][j] != arr[n - 1 - j][n - 1 - i]){
				return 0;
			}
		}
	}
	return 1;
}
void xuatMaTranCoDoiXungQuaDuongCheoPhu(Itemtype arr[][MAXSIZE], int n){
	printf("\n\tCac phan tu thuoc duong cheo va xong xong vs Duong Cheo Phu la : ");
	for(int i = 0;i < n - 1;i++){
		for(int j = 0;j < n - 1 - i;j++){
				printf("%3d %3d",arr[i][j],arr[n - 1 - j][n - 1 - i]);
			}
	}
}

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}
void mangTangDanTheoCot(Itemtype arr[][MAXSIZE], int n){
	for(int j = 0;j < n;j++){
		for(int i = 0;i < n - 1;i++){
			for(int k = i + 1;k < n;k++){
				if(arr[i][j] > arr[k][j])
					swap(arr[i][j],arr[k][j]);
			}
		}
	}
	xuatMaTranVuong(arr,n);
}

int kiemTraDuongCheoChinhTangDan(Itemtype arr[][MAXSIZE], int n){
	for(int i = 0;i < n - 1;i++){
		if(arr[i][i] > arr[i + 1][i + 1])
			return 0;
	}
	return 1;
}

int kiemTraMangGiamDanTheoCot(Itemtype arr[][MAXSIZE], int n){
	for(int j = 0;j < n;j++){
		for(int i = 0;i < n - 1;i++){
			for(int k = i + 1;k < n;k++){
				if(arr[i][j] < arr[k][j])
					return 0;
			}
		}
	}
	return 1;
}
void mang1cPhu(Itemtype arr[][MAXSIZE], int n, Itemtype b[], int &k){
	k = 0;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			b[k++] = arr[i][j];
		}
	}
}
void sapXep1C(Itemtype b[], int k){
	for(int i = 0;i < k - 1;i++){
		for(int j = i + 1;j < k;j++){
			if(b[i] > b[j])
				swap(b[i] , b[j]);
		}
	}
}

void sapXepMaTranTangDanTuTrenXuongDuoiTuTraiSangPhai(Itemtype arr[][MAXSIZE], int n,Itemtype b[]){
	printf("\n\tMa Tran Sau Khi Duoc Sap Xep Tang Dan Tu Trai Qua Phai Tu Tren Xuong Duoi La : \n");
	int k = 0;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			arr[i][j] = b[k++];
		}
	}
	xuatMaTranVuong(arr,n);
}


void showMenu(){
	printf("\n**************************************************");
	printf("\n*                       MENU                      ");
	printf("\n**************************************************");
	printf("\n* 0 De thoat khoi chuong trinh					");
	printf("\n* 1 Nhap Xuat Ma tran Vuong 						");
	printf("\n* 2 Kiem tra ma tran co doi xung hay ko			");
	printf("\n* 3 Tong Duong Cheo Chinh							");
	printf("\n* 4 Tong Duong Cheo Phu							");
	printf("\n* 5 Tong cac Phan tu nam DUOI Duong Cheo PHU		");
	printf("\n* 6 Tong cac Phan tu nam TREN Duong Cheo PHU		");
	printf("\n**************************************************");
	
}

void thucThi(){
	Itemtype arr[MAXSIZE][MAXSIZE];
	int n,luachon;
	do{
		showMenu();
		printf("\n\tSu lua chon cua ban la: ");
		nhapSoNguyenDuong(luachon);
		switch(luachon){
			case 1:{
				nhapMaTranVuong(arr,n);
				printf("Ma tran sau khi duoc xuat : \n");
				xuatMaTranVuong(arr,n);
				break;
			}
			case 2:{
				if(maTranDoiXung(arr,n) == 1)
					printf("\n\tMa tran doi xung");
				else
				printf("\n\tMa tran khong doi xung");
				break;
			}
			case 3:{
				printf("\n\tTong Duong cheo CHINH la %d ", sumDuongCheoChinh(arr,n));
				break;
			}
			case 4:{
				printf("\n\tTong Duong Cheo PHU la %d ", sumDuongCheoPhu(arr,n));
				break;
			}
			case 5:{
				printf("\n\tTong cac phan tu nam DUOI Duong Cheo PHU la %d ", sumPhanTuDuoiCheoPhu(arr,n));
				break;
			}
			case 6:{
				printf("\n\tTong cac phan tu nam TREN Duong cheo Phu la %d ", sumPhanTuTrenCheoPhu(arr,n));
				break;
			}
			case 7:{
				if(kienTraMaTranCoDoiXungQuaDuongCheoChinh(arr,n) == 1)
					printf("\n\tMa Tran DOI XUNG Qua Duong Cheo Chinh");
				else
					printf("\n\tMa Tran Khong DOI XUNG Qua Duong Cheo Chinh!!! ");
				break;
			}
			case 8:{
				if(kienTraMaTranCoDoiXungQuaDuongCheoPhu(arr,n) == 1)
					printf("\n\tMa Tran DOI XUNG Qua Duong Cheo Phu");
				else
					printf("\n\tMa Tran Khong DOI XUNG Qua Duong Cheo Phu!!! ");
				break;
			}
			case 9:{
				printf("\n\tSap Xep Mang Cot Tang Dan : \n");
				mangTangDanTheoCot(arr,n);
				break;
			}
			case 10:{
				if(kiemTraDuongCheoChinhTangDan(arr,n) == 1)
					printf("\n\tDuong Cheo Chinh Tang Dan");
				else
					printf("\n\tDuong Cheo Chinh Khong Tang Dan!!!");
				break;
			}
			case 11:{
				if(kiemTraMangGiamDanTheoCot(arr,n))
					printf("\n\tMa Tran Giam Theo Cot");
				else
					printf("\n\tMa Tran Khong Giam Dan Theo Cot!!!");
				break;
			}
			case 12:{
				Itemtype k,b[MAXSIZE];
				mang1cPhu(arr,n,b,k);
				sapXep1C(b,k);
				sapXepMaTranTangDanTuTrenXuongDuoiTuTraiSangPhai(arr,n,b);
				break;
			}
			case 13:{
				xuatMaTranCoDoiXungQuaDuongCheoPhu(arr,n);
				break;
			}
		}
	}while(luachon != 0);
}










