#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXSIZE 100
void showMenu();
void nhapMangChuoi(char arr[MAXSIZE][MAXSIZE], int &n);
void xuatMangChuoi(char arr[][MAXSIZE], int n);
int StringlenghtMin(char arr[][MAXSIZE], int n);
void xuatChuoiCoKichThuocNhoNhat(char arr[][MAXSIZE], int n);
int StringlenghtMax(char arr[][MAXSIZE], int n);
void xuatChuoiCoKichThuocLonNhat(char arr[][MAXSIZE], int n);
float trungBinhCongKichThuocChuoiTrongMang(char arr[][MAXSIZE], int n);
void xuatChuoiCoKichThuocLonHonTBC(char arr[][MAXSIZE], int n);
void sapXepTangDanTheoKichThuocChuoi(char arr[][MAXSIZE], int n);
void sapXepGiamDanTheoKichThuocChuoi(char arr[][MAXSIZE], int n);
void xuatChuoiMinTheoMaAscill(char arr[][MAXSIZE], int n);
void xuatChuoiMaxTheoMaAscill(char arr[][MAXSIZE], int n);
void sapXepTangDanTheoMaAscill(char arr[][MAXSIZE], int n);
void sapXepGiamDanTheoMaAscill(char arr[][MAXSIZE], int n);
void timChuoiTrongMangArrCoKichThuocBangChuoiST(char arr[][MAXSIZE], int n,char st[]);
void xuatChuoiCoChuaChuoiST(char arr[][MAXSIZE], int n, char st[]);
void suLi();
int main(){
	suLi();
	
	return 0;
}
void showMenu(){
	printf("\n************************************************************");
	printf("\n*                               MENU                        ");
	printf("\n************************************************************");
	printf("\n* 0 De ket thuc chuong trinh                                ");
	printf("\n* 1 Nhap / Xuat Mang Chuoi                                  ");
	printf("\n* 2 Tim Chuoi Co Kich Thuoc Nho/Lon(Nhat)                   ");
	printf("\n* 3 Tinh Kich Thuoc TBC Cua Tat Ca Cac Chuoi Trong Mang     ");
	printf("\n* 4 Hien Thi Co Kich Thuoc Lon Hon Gia Tri Trung Binh       ");
	printf("\n* 5 Sap Xep Cac Chuoi Tang/Giam Dan Theo Kich Thuoc Chuoi   ");
	printf("\n* 6 Tim Chuoi Nho/lon Nhat theo ma Ascill                   ");
	printf("\n* 7 Sap Xep Chuoi Tang/Giam Dan Theo Ma Ascill              ");
	printf("\n* 8 Tim nhung chuoi trong mang Arr co kich thuoc = mang st[]");
	printf("\n* 8 Tim Chuoi Trong Mang Arr Co Chua Chuoi st[]             ");
	printf("\n* 9 Tim Nhung Chuoi Doi Xung Trong Mang Chuoi              ");
	printf("\n* 10 Hien Thi Nhung Chuoi Dung Chuan la Dia Chi email       ");
	printf("\n* 11 Tim Nguyen Chuoi Co Chua Ki Tu So                      ");
	printf("\n* 12 Tim Nhung Chuoi Co Chua Ki Tu In HOA                   ");
	printf("\n* 13 Tim Chuoi Co Chua Ki Tu C trong Mang Chuoi             ");
	printf("\n* 14 Moi Chuoi Trong Mang a Co Bao Nhieu Tu ?               ");
	printf("\n************************************************************");
	printf("\n************************************************************");
}
void suLi(){
	int luachon,n;
	char arr[MAXSIZE][MAXSIZE];
	do{
		showMenu();
		do{
			printf("\n\tSu lua chon cua ban la : ");scanf("%d", &luachon);
			if(luachon < 0)
				printf("\n\tVui long nhap lai lua chon cua ban!!!!");
		}while(luachon < 0);
		switch(luachon){
			case 1:{
				nhapMangChuoi(arr,n);
				printf("\n\tMang Chuoi Xau Khi Duoc Xuat : ");
				xuatMangChuoi(arr,n);
				break;
			}
			case 2:{
				xuatChuoiCoKichThuocNhoNhat(arr,n);
				xuatChuoiCoKichThuocLonNhat(arr,n);
				break;
			}
			case 3:{
				printf("\n\t\tTrung Binh Cong Kich Thuoc Tat Ca Chuoi Trong Mang = %.2f", trungBinhCongKichThuocChuoiTrongMang(arr,n));
				break;
			}
			case 4:{
				xuatChuoiCoKichThuocLonHonTBC(arr,n);
				break;
			}
			case 5:{
				sapXepTangDanTheoKichThuocChuoi(arr,n);
				sapXepGiamDanTheoKichThuocChuoi(arr,n);
				break;
			}
			case 6:{
				xuatChuoiMinTheoMaAscill(arr,n);
				xuatChuoiMaxTheoMaAscill(arr,n);
				break;
			}
			case 7:{
				sapXepTangDanTheoMaAscill(arr,n);
				sapXepGiamDanTheoMaAscill(arr,n);
				break;
			}
			case 8:{
				char st[31];
				printf("\n\t Chuoi : ");
				fflush(stdin);
				gets(st);
				timChuoiTrongMangArrCoKichThuocBangChuoiST(arr,n,st);
				xuatChuoiCoChuaChuoiST(arr,n,st);
				break;
			}
		}			
	}while(luachon != 0);
}
//==========================================================================================================
void nhapMangChuoi(char arr[MAXSIZE][MAXSIZE], int &n){
	do{
		printf("\n\tNhap N Chuoi : ");scanf("%d", &n);
		if(n <= 0 || n > MAXSIZE)
			printf("\n\tVui long nhap lai!!!!");
	}while(n <= 0 || n > MAXSIZE);
	for(int i = 0;i < n;i++){
		fflush(stdin);
		printf("\n\tString[%d] = ", i);
		gets(arr[i]);
	}
}
//=========================================================================================================
void xuatMangChuoi(char arr[][MAXSIZE], int n){
	for(int i = 0;i < n;i++){
		printf("\nString[%d] = ", i);
		puts(arr[i]);
	}
}
//=========================================================================================================
int StringlenghtMin(char arr[][MAXSIZE], int n){
	int  min = strlen(arr[0]);
	for(int i = 1;i < n;i++){
		if(strlen(arr[i]) < min)
		min = strlen(arr[i]);
	}
	return min;
}
//=========================================================================================================
void xuatChuoiCoKichThuocNhoNhat(char arr[][MAXSIZE], int n){
	printf("\n\tChuoi Co Kich Thuoc Nho Nhat Trong Mang Chuoi La : ");
	int minLenght = StringlenghtMin(arr,n);
	for(int i = 0;i < n;i++){
		if(strlen(arr[i]) == minLenght)
			printf("[%s]  ", arr[i]);
	}
}
//=========================================================================================================
int StringlenghtMax(char arr[][MAXSIZE], int n){
	int  max = strlen(arr[0]);
	for(int i = 1;i < n;i++){
		if(strlen(arr[i]) > max)
		max = strlen(arr[i]);
	}
	return max;
}
//=========================================================================================================
void xuatChuoiCoKichThuocLonNhat(char arr[][MAXSIZE], int n){
	printf("\n\tChuoi Co Kich Thuoc Nho Nhat Trong Mang Chuoi La : ");
	int maxLenght = StringlenghtMax(arr,n);
	for(int i = 0;i < n;i++){
		if(strlen(arr[i]) == maxLenght)
			printf("[%s]  ", arr[i]);
	}
}
//=========================================================================================================
float trungBinhCongKichThuocChuoiTrongMang(char arr[][MAXSIZE], int n){
	int tong = 0;
	for(int i = 0;i < n;i++){
		tong += strlen(arr[i]);
	}
	return (float)tong / n;
}
//=========================================================================================================
void xuatChuoiCoKichThuocLonHonTBC(char arr[][MAXSIZE], int n){
	int flag = 0;
	float tbc = trungBinhCongKichThuocChuoiTrongMang(arr,n);
	printf("\n\tKich Thuoc Chuoi Lon Kich Thuoc Trung Binh La : ");
	for(int i = 0;i < n;i++){
		if(strlen(arr[i]) > tbc){
			printf("%s ", arr[i]);
			flag = 1;
		}
	}
	if(flag == 0)
		printf("\n\tMang Khong Chua Kich Thuoc Chuoi Lon Hon Gia Tri Trung Binh Chuoi!!!!!");
}
//=========================================================================================================
void sapXepTangDanTheoKichThuocChuoi(char arr[][MAXSIZE], int n){
	printf("\n\t\tChuoi Sau Khi Duoc Sap Xep Tang Dan Theo Kich Thuoc Chuoi ");
	char temp[100];
	for(int i = 0;i < n - 1;i++)
		for(int j = i + 1;j < n;j++){
			if(strlen(arr[i]) > strlen(arr[j])){
				strcpy(temp , arr[i]);
				strcpy(arr[i], arr[j]);
				strcpy(arr[j],temp);
			}
		}
		xuatMangChuoi(arr,n);
}
//=========================================================================================================
void sapXepGiamDanTheoKichThuocChuoi(char arr[][MAXSIZE], int n){
	printf("\n\t\tChuoi Sau Khi Duoc Sap Xep Giam Dan Theo Kich Thuoc Chuoi ");
	char temp[100];
	for(int i = 0;i < n - 1;i++)
		for(int j = i + 1;j < n;j++){
			if(strlen(arr[i]) < strlen(arr[j])){
				strcpy(temp , arr[i]);
				strcpy(arr[i], arr[j]);
				strcpy(arr[j],temp);
			}
		}
		xuatMangChuoi(arr,n);
}
//=========================================================================================================
void xuatChuoiMinTheoMaAscill(char arr[][MAXSIZE], int n){
	char minString[100];
	strcpy(minString,arr[0]);
	for(int i = 1;i < n;i++){
		if(strcmp(arr[i],minString) < 0)
			strcpy(minString,arr[i]);
	}
	printf("\n\t\tChuoi Nho Nhat Theo Ma Ascill : [%s]  ", minString);
}
//=========================================================================================================
void xuatChuoiMaxTheoMaAscill(char arr[][MAXSIZE], int n){
	char maxString[100];
	strcpy(maxString,arr[0]);
	for(int i = 1;i < n;i++){
		if(strcmp(arr[i],maxString) > 0)
			strcpy(maxString,arr[i]);
	}
	printf("\n\t\tChuoi Lon Nhat Theo Ma Ascill : [%s]  ", maxString);
}
//=========================================================================================================
void sapXepTangDanTheoMaAscill(char arr[][MAXSIZE], int n){
	char temp[100];
	printf("\n\t\tChuoi Sau Khi Duoc Sap Xep Tang Dan Theo Ma Ascill : ");
	for(int i = 0;i < n - 1;i++)
		for(int j = i + 1;j < n;j++){
			if(strcmp(arr[i],arr[j]) > 0){
				strcpy(temp, arr[i]);
				strcpy(arr[i],arr[j]);
				strcpy(arr[j],temp);
			}	
		}
		xuatMangChuoi(arr,n);	
}
//=========================================================================================================
void sapXepGiamDanTheoMaAscill(char arr[][MAXSIZE], int n){
	char temp[100];
	printf("\n\t\tChuoi Sau Khi Duoc Sap Xep Giam Dan Theo Ma Ascill : ");
	for(int i = 0;i < n - 1;i++)
		for(int j = i + 1;j < n;j++){
			if(strcmp(arr[i],arr[j]) < 0){
				strcpy(temp, arr[i]);
				strcpy(arr[i],arr[j]);
				strcpy(arr[j],temp);
			}	
		}
		xuatMangChuoi(arr,n);	
}
void timChuoiTrongMangArrCoKichThuocBangChuoiST(char arr[][MAXSIZE], int n,char st[]){
	int flag = 0;
	printf("\n\t\tNhung Chuoi trong mang Arr co kich thuoc Giong Chuoi st[] : ");
	for(int i = 0;i < n;i++){
		if(strlen(arr[i]) == strlen(st)){
			flag = 1;
			printf("[%s] ", arr[i]);
		}	
	}
	if(flag == 0)
		printf("\n\t\tKhong Co Chuoi Nao Co Kich Thuoc Bang Chuoi st[] Vua Nhap!!!");
}
void xuatChuoiCoChuaChuoiST(char arr[][MAXSIZE], int n, char st[]){
	int flag = 0,start;
	printf("\n\tChuoi co chua chuoi st trong mang chuoi la :  ");
	for(int i = 0;i < n;i++){
		for(int j = 0;j < strlen(arr[i]);j++){
			if(st[0] == arr[i][j] && strlen(arr[i]) - j >= strlen(st)){
				flag = 1;
				start = j;
			}
			for(int k = 0;k < strlen(st);k++){
				if(st[k] != arr[i][start]){
					flag = 0;
					break;
				}
				start++;
			}
		}
		if(flag == 1)
			printf("[%s] ", arr[i]);
	}
	if(flag == 0)
			printf("\n\t\tKhong co Chuoi Nao Trong Mang Chua Chuoi st[]!!!!");
}
//int demMangAtrongMangB(Itemtype *arr, Itemtype b[MAXSIZE],int n,int nb){
//	int flag,start,count = 0;
//	for(int i = 0;i < nb;i++){//Duyet Mang B[]
//		 if(arr[0] == b[i] && nb - i >= n){
//		 	flag = 1;
//		 	start = i;//Bat dau tu Vi tri dau tien cua mang A vs Mang Phan tu Bi Trung Thu i cua Mang B
//		 	for(int j = 0;j < n;j++){ // Duyet Mang arr[]
//		 		if(arr[j] != b[start])//hoac arr[j] != b[start++]
//				 {
//		 			flag = 0;
//		 			break;
//				 }
//				 start++;//Tang Vi tri Bi trung len 1 don Vi
//			 }
//			 if(flag == 1){//Mang arr[] xuat hien trong b[] thi tang count len 1 don vi
//			 	count++;
//			 }
//		 }
//	}
//	return count;
//} 

 
