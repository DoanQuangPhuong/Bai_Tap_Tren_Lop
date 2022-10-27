#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define MAXSIZE 100

struct SINHVIEN{
	char mssv[11];
	char ho[9];
	char holot[20];
	char ten[9];
	float diemTB;
	char xeploai[20];
};
void input1SV(SINHVIEN &sv);
void ouput1SV(SINHVIEN sv);
void inputDSSV(SINHVIEN dssv[], int &n);
void ouputDSSV(SINHVIEN dssv[], int n);
void sepLoai1SV(SINHVIEN &sv);
void xepLoaiDSSV(SINHVIEN dssv[], int n);
void swap(SINHVIEN &a, SINHVIEN &b);
void sapXepTangDanTheoDTB(SINHVIEN dssv[], int n);
void sapXepGiamDanTheoDTB(SINHVIEN dssv[], int n);
float sinhVienCoDiemTrungBinhCaoNhat(SINHVIEN dssv[], int n);
void xuatSinhVienCoDiemTBMax(SINHVIEN dssv[], int n);
float sinhVienCoDiemTrungBinhThapNhat(SINHVIEN dssv[], int n);
void xuatSinhVienCoDiemTBMin(SINHVIEN dssv[], int n);
void xuatSinhVienXepLoaiGioiANDKha(SINHVIEN dssv[], int n);
int demSinhVienCoHoNguyen(SINHVIEN dssv[], int n);
void ghiFileSV();
void docDSSV(SINHVIEN dssv[], int &n,char *ten);
bool docfile(FILE *f,SINHVIEN &sv);
void showMenu();
void suLi();
int main(){
	suLi();
	
	return 0;
}
void input1SV(SINHVIEN &sv){
	printf("\n\tMSSV : ");scanf("%s", &sv.mssv);
	printf("\n\tHo : ");scanf("%s", &sv.ho);
	printf("\n\tHo lot : ");
	fflush(stdin);
	gets(sv.holot);
	printf("\n\tTen : ");scanf("%s", &sv.ten);
	printf("\n\tDiem Trung Binh : ");scanf("%f", &sv.diemTB);
}
void ouput1SV(SINHVIEN sv){
	printf("\n----------------------------------------------------------------------------------------------------------");
	printf("\n\n");
	printf("%-15s%-10s%-20s%-10s%-40s%-25s\n", "MSSV","Ho","Ho lot", "Ten", "DIEN TRUNG BINH","XEP LOAI");
	printf("%-15s%-10s%-20s%-10s\t%5.2f\t\t\t\t      %-15s", sv.mssv,sv.ho,sv.holot,sv.ten,sv.diemTB,sv.xeploai);
	printf("\n-----------------------------------------------------------------------------------------------------------");
}
void inputDSSV(SINHVIEN dssv[], int &n){
	do{
		printf("Nhap so luong Sinh Vien : ");scanf("%d", &n);
		if(n <= 0)
			printf("\n\tVui long nhap lai!!!!");
	}while(n <= 0);
	for(int i = 0;i < n;i++){
		printf("\n\tSinh Vien thu %d ", i + 1);
		input1SV(dssv[i]);
	}
}
void ouputDSSV(SINHVIEN dssv[], int n){
	for(int i = 0;i < n;i++){
		printf("\n\tSinh Vien thu %d \n", i + 1);
		xepLoaiDSSV(dssv,n);
		ouput1SV(dssv[i]);
	}
}
////void docFileTTSV(FILE *fi,SINHVIEN &sv){
////	scanf("%[^\t]%*c%[^\t]%*c%[^\t]%*c%[^\t]%*c%lf", &sv.mssv, &sv.ho, &sv.holot,&sv.ten, &sv.diemTB);
////}
////void ghiFileTTSV(FILE *fo, SINHVIEN sv){
////	fprintf(fo, "%-15s%-10s%-20s%-10s%5.2lf\n", sv.mssv, sv.ho, sv.holot, sv.ten, sv.diemTB);
//}
void ghiFileSV(){ // Ghi thong tin cua mot DSSV co n Sinh Vien Xuong FILE
	FILE *f = fopen("DocFileSinhVien.TXT", "wt"); //wt: write text
	if (f == NULL)
	{
		printf("Loi: mo file de ghi du lieu.");
		return;
	}
	int n;
	printf("So luong Sinh Vien : ");scanf("%d", &n);
	SINHVIEN sv;
	for (int i = 0; i < n; i++)
	{
		fflush(stdin);
		printf("MSSV : ");scanf("%s", &sv.mssv);
		fflush(stdin);
		printf("Ho : ");scanf("%s", &sv.ho);
		fflush(stdin);
		printf("Ho Lot : ");
		gets(sv.holot);
		printf("Ten : ");scanf("%s", &sv.ten);
		printf("Diem Trung Binh :  ");scanf("%f", &sv.diemTB);
		fprintf(f, "\t%-10s%-10s%-20s%-12s%.2f\n", sv.mssv,sv.ho,sv.holot,sv.ten,sv.diemTB);
	}
	printf("\n\tDa Ghi File Thanh Cong");
	fclose(f); //Ðóng file vua mo
}


bool docfile(FILE *f,SINHVIEN &sv){
	return fscanf(f, "%[^#]#%[^#]#%[^#]#%[^#]#%f\n", &sv.mssv,&sv.ho,&sv.holot,&sv.ten,&sv.diemTB) == 5;
}

void docDSSV(SINHVIEN dssv[], int &n,char *ten){ //Doc Thong tin sinh Vien trong dssv tu file
	FILE *fi = fopen(ten, "rt"); //rt: read text
	if (fi == NULL)
	{
		printf("\nLoi: mo file de doc du lieu.");
		return;
	}
	fscanf(fi, "%d\n", &n);
	for(int i = 0;i < n;i++){
		if(docfile(fi, dssv[i]) == false){
			n = i;
			break;
		}
	}
	fclose(fi); //Ðóng file Vua mo
}

void sepLoai1SV(SINHVIEN &sv){
	if(sv.diemTB >= 8)
		strcpy(sv.xeploai, "Gioi");
	else if(sv.diemTB >= 6.5)
		strcpy(sv.xeploai, "Kha");
	else if(sv.diemTB >= 5)
		strcpy(sv.xeploai, "Trung Binh");
	else 
	strcpy(sv.xeploai, "Yeu");
}
void xepLoaiDSSV(SINHVIEN dssv[], int n){
	for(int i = 0;i < n;i++){
		sepLoai1SV(dssv[i]);
	}
}
void swap(SINHVIEN &a, SINHVIEN &b){
	SINHVIEN temp = a;
		a = b;
		b = temp;
}
void sapXepTangDanTheoDTB(SINHVIEN dssv[], int n){
	printf("\n\t\t\tDANH SACH SINH VIEN DUOC SAP XEP TANG DAN THEO DIEM TRUNG BINH");
	for(int i = 0;i < n - 1;i++)
		for(int j = i + 1;j < n;j++){
			if(dssv[i].diemTB > dssv[j].diemTB)
			swap(dssv[i],dssv[j]);
		}
		ouputDSSV(dssv,n);
}
void sapXepGiamDanTheoDTB(SINHVIEN dssv[], int n){
	printf("\n\t\t\tDANH SACH SINH VIEN DUOC SAP XEP GIAM DAN THEO DIEM TRUNG BINH");
	for(int i = 0;i < n - 1;i++)
		for(int j = i + 1;j < n;j++){
			if(dssv[i].diemTB < dssv[j].diemTB)
			swap(dssv[i],dssv[j]);
		}
		ouputDSSV(dssv,n);
}
float sinhVienCoDiemTrungBinhCaoNhat(SINHVIEN dssv[], int n){
	float max = dssv[0].diemTB;
	for(int i = 1;i < n;i++){
		if(dssv[i].diemTB > max)
			max = dssv[i].diemTB;
	}
	return max;
}
void xuatSinhVienCoDiemTBMax(SINHVIEN dssv[], int n){
	printf("\n\t\tSINH VIEN CO DIEM TRUNG BINH CAO NHAT");
	float max = sinhVienCoDiemTrungBinhCaoNhat(dssv,n);
	for(int i = 0;i < n;i++){
		if(dssv[i].diemTB == max)
			ouput1SV(dssv[i]);
	}
}
float sinhVienCoDiemTrungBinhThapNhat(SINHVIEN dssv[], int n){
	float min = dssv[0].diemTB;
	for(int i = 1;i < n;i++){
		if(dssv[i].diemTB < min)
			min = dssv[i].diemTB;
	}
	return min;
}
void xuatSinhVienCoDiemTBMin(SINHVIEN dssv[], int n){
	printf("\n\t\tSINH VIEN CO DIEM TRUNG BINH THAP NHAT");
	int min = sinhVienCoDiemTrungBinhThapNhat(dssv,n);
	for(int i = 0;i < n;i++){
		if(dssv[i].diemTB == min)
			ouput1SV(dssv[i]);
	}
}
void xuatSinhVienXepLoaiGioiANDKha(SINHVIEN dssv[], int n){
	int flag = 0;
	for(int i = 0;i < n;i++){
		if(strcmp(dssv[i].xeploai,"Gioi") == 0 || strcmp(dssv[i].xeploai,"Kha") == 0){
			ouput1SV(dssv[i]);
			flag = 1;
		}
	}
	if(flag == 0)
		printf("\n\tKhong co sinh Vien Xep Loai GIOI,KHA trong DSSV!!!!");
}
int demSinhVienCoHoNguyen(SINHVIEN dssv[], int n){
	int count = 0;
	for(int i = 0;i < n;i++){
		if(strcmp(dssv[i].ho,"Nguyen") == 0)
			count++;
	}
	return count;
}
float tongDiemSinhVienCoChuNDauTien(SINHVIEN dssv[], int n){
	float tong = 0;
	for(int i = 0;i < n;i++){
		if(dssv[i].ho[0] == 'N')
			tong += dssv[i].diemTB;
	}
	return tong;
}
void showMenu(){
	printf("\n**************************************************************");
	printf("\n*                             MENU                            ");
	printf("\n**************************************************************");
	printf("\n* 0 De Thoat Khoi Chuong Trinh								");
	printf("\n* 1 Nhap Xuat Danh Sach Sinh Vien								");
	printf("\n* 2 Sap Xep Sinh Vien Tang/Giam Theo Diem Trung Binh			");
	printf("\n* 3 Tim kiem Va in ra SV co DTB cao nhat/ Thap nhat			");
	printf("\n* 4 In ra Danh Sach Sinh Vien Xep loai Gioi AND Kha			");
	printf("\n* 5 Dem xem co Bao Nhieu SV co ho Nguyen						");
	printf("\n* 6 Tong diem trung binh sinh vien co Ho Chu dau tien	la [N]  ");
	printf("\n**************************************************************");
}
void suLi(){
	int n = 0,luachon;
	SINHVIEN sv;
	SINHVIEN dssv[MAXSIZE];
	do{
		showMenu();
		do{
			printf("\nLua Chon Cua BAN La: ");scanf("%d", &luachon);
			if(luachon < 0)
				printf("\n\tLua Chon Khong Hop Le!!!");
		}while(luachon < 0);
		switch(luachon){
			case 1:{
//				inputDSSV(dssv,n);
//				printf("\n\t\t\t\tDANH SACH SINH VIEN SAU KHI DUOC XUAT");
//				ouputDSSV(dssv,n);
//				ghiFileSV();
				docDSSV(dssv,n,"DocFileSinhVien.txt");
				ouputDSSV(dssv,n);
				break;
			}
			case 2:{
				sapXepTangDanTheoDTB(dssv,n);
				sapXepGiamDanTheoDTB(dssv,n);
				break;
			}
			case 3:{
				xuatSinhVienCoDiemTBMax(dssv,n);
				xuatSinhVienCoDiemTBMin(dssv,n);
				break;
			}
			case 4:{
				xuatSinhVienXepLoaiGioiANDKha(dssv,n);
				break;
			}
			case 5:{
				printf("\n\tCo %d Sinh Vien co ho Nguyen trong DSSV", demSinhVienCoHoNguyen(dssv,n));
				break;
			}
			case 6:{
				printf("\n\tTong sinh Vien co Ho chua Chu Cai'N' trong danh sach = %.2f", tongDiemSinhVienCoChuNDauTien(dssv,n));
				break;
			}
		}
	}while(luachon != 0);
}









