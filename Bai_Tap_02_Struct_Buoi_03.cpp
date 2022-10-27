#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAXSIZE 100
struct SINHVIEN{
	char mssv[11];
	char ho[9];
	char holot[20];
	char ten[9];
	float diemTB;
	char xeploai[20];
};
struct LOPHOC{
	char tenlophoc[40];
	int siso;
	SINHVIEN dssv[MAXSIZE];
};
void input1SV(SINHVIEN &sv);
void ouput1SV(SINHVIEN sv);
void swap(SINHVIEN &a, SINHVIEN &b);
void sepLoai1SV(SINHVIEN &sv);
void xepLoaiDSSV(SINHVIEN dssv[], int n);
void inputDSSV(SINHVIEN dssv[], int n);
void input1LopHoc(LOPHOC &lh);
void ouput1LopHoc(LOPHOC lh);
void inputDSLH(LOPHOC dslh[], int &n);
void ouputDSLH(LOPHOC dslh[], int n);
int lopHocNhieuSVNhat(LOPHOC dslh[], int n);
void inLopHocCoNhieuSinhVienNhat(LOPHOC dslh[], int n);
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

void inputDSSV(SINHVIEN dssv[], int n){
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

void input1LopHoc(LOPHOC &lh){
	printf("\n\tTen Lop Hoc: ");
	fflush(stdin);
	gets(lh.tenlophoc);
	do{
		printf("\n\tSi So : ");scanf("%d", &lh.siso);
		if(lh.siso<= 0)
			printf("\n\tVui long nhap lai!!!!");
	}while(lh.siso<= 0);
	inputDSSV(lh.dssv,lh.siso);
}

void ouput1LopHoc(LOPHOC lh){
	printf("\t\t\t%-30s\t\t\t%-10s\n", "TEN LOP HOC" , "SI SO");
	printf("\t\t\t%-40s\t%3d", lh.tenlophoc,lh.siso);
	ouputDSSV(lh.dssv,lh.siso);
}

void inputDSLH(LOPHOC dslh[], int &n){
	do{
		printf("\n\tSo lop hoc : ");scanf("%d", &n);
		if(n <= 0)
			printf("\n\tLop hoc khong hop le,Vui long nhap lai!!!!");
	}while(n <= 0);
	for(int i = 0;i < n;i++){
		printf("\n\t\t\tLop Hoc Thu %d ", i + 1);
		input1LopHoc(dslh[i]);
	}
}

void ouputDSLH(LOPHOC dslh[], int n){
	for(int i = 0;i < n;i++){
		ouput1LopHoc(dslh[i]);
	}
}
void docFileTT1LH(FILE *fi , LOPHOC &lh){
	fscanf(fi,"%[^\t]*c%[^\t]", &lh.tenlophoc,&lh.siso);
}
void ghiFileTT1LH(FILE *fo,  LOPHOC lh){
	fprintf(fo,"%-40s%3d", lh.tenlophoc,lh.siso);
} 
void inloplonhon5SinhVienCoDiemTBLoaiGioi(LOPHOC dslh, int n){
	
}
int lopHocNhieuSVNhat(LOPHOC dslh[], int n){
	int max = dslh[0].siso;
	for(int i = 1;i < n;i++){
		if(dslh[i].siso > max)
			max = dslh[i].siso;
	}
	return max;
}
void inLopHocCoNhieuSinhVienNhat(LOPHOC dslh[], int n){
	int max = lopHocNhieuSVNhat(dslh,n);
	for(int i = 0;i < n;i++){
		if(dslh[i].siso == max)
			ouput1LopHoc(dslh[i]);
	}
}
void swap(SINHVIEN &a, SINHVIEN &b){
	SINHVIEN temp = a;
		a = b;
		b = temp;
}
void showMenu(){
	printf("\n*********************************************************************");
	printf("\n*				MENU							   ");
	printf("\n*********************************************************************");
	printf("\n* 0 De Thoat Khoi Chuong Trinh									   ");
	printf("\n* 1 Nhap/xuat Danh Sach Lop Hoc									   ");
	printf("\n* 2 In lop hoc co Nhieu Sinh Vien NHAT							   ");
	printf("\n* 3 Sinh Vien Co Diem Trung Binh Cao Nhat Trong Cac Lop			   ");
	printf("\n*********************************************************************");
}
void suLi(){
	int n,luachon;
	LOPHOC dslh[MAXSIZE];
	do{
		showMenu();
		do{
		printf("\n\tLua Chon Cua Ban La : ");scanf("%d", &luachon);
		if(luachon < 0)
			printf("\n\tVui long nhap lai!!!");
		}while(n < 0);
		switch(luachon){
			case 1:{
				inputDSLH(dslh,n);
				ouputDSLH(dslh,n);
				break;
			}
			case 2:{
				printf("\n\t\t\t\tLop Hoc Co nhieu sinh Vien nhat\n");
				inLopHocCoNhieuSinhVienNhat(dslh,n);
				break;
			}
		}
	}while(luachon != 0);
}




