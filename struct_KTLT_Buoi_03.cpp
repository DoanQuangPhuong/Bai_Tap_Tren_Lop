#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<math.h>
struct SINHVIEN{
	int stt;
	char mssv[30];
	char htsv[70];
	float dtl;
	float diemthi;
	float dientongket;
	char xeploai[3];
};
void nhap1SoNguyen(int &n);
void input1SinhVien(SINHVIEN &sv);
void ouput1SinhVien(SINHVIEN sv);
void writeFile(SINHVIEN dssv[], int n,char fileName[50]);
void inputDssv(SINHVIEN dssv[], int &n);
void ouputDssv(SINHVIEN dssv[], int n);
void swap(SINHVIEN &a, SINHVIEN &b);
float sinhVienCoDiemTongKetThapNhat(SINHVIEN dssv[], int n);
void xuatSinhVienCoDiemTongKetThapNhat(SINHVIEN dssv[], int n);
float sinhVienCoDiemTongKetCaoNhat(SINHVIEN dssv[], int n);
void xuatSinhVienCoDiemTongKetCaoNhat(SINHVIEN dssv[], int n);
void xepLoaiSinhVien(SINHVIEN &sv);
void sapXepSinhVienTangDan(SINHVIEN dssv[], int n);
void sapXepSinhVienGiamDan(SINHVIEN dssv[], int n);
void diemTongKet(SINHVIEN &sv);
void danhSachDiemTongKet(SINHVIEN dssv[], int n);
void xepLoaiDanhSach(SINHVIEN dssv[], int n);
void demCoBaoNhieuHocSinhDatVaKhongDat(SINHVIEN dssv[], int n);
double diemTrungBinhTatCaHocSinh(SINHVIEN dssv[], int n);
void chuanHoaChuoi(SINHVIEN &sv);
void chuanHoaDSSV(SINHVIEN dssv[], int n);
int khoangTrangCuoiCung(SINHVIEN sv);
void timKiemTenTrongChuoi(SINHVIEN sv);
void timKiemTenTrongDanhSaxh(SINHVIEN dssv[], int n);
void menu();
void thucThi();

int main(){
	thucThi();
	
	return 0;
}

void nhap1SoNguyen(int &n){
	do{
	scanf("%d", &n);
	if(n < 0)
		printf("\nVui long nhap lai!!!");
	}while(n < 0);
}

void input1SinhVien(SINHVIEN &sv){
	printf("\tNhap stt : ");scanf("%d", &sv.stt);
	printf("\n\tNhap ma so sinh Vien: ");scanf("%s", &sv.mssv);
	printf("\n\tHo va Ten : ");
	fflush(stdin);
	gets(sv.htsv);
	printf("\n\tDiem tieu luan: ");scanf("%f", &sv.dtl);
	printf("\n\tDiem thi ket thuc mom: ");scanf("%f", &sv.diemthi);	
}

void ouput1SinhVien(SINHVIEN sv){
	printf("\n\tSTT: %d", sv.stt);
	printf("\n\tMa : %s", sv.mssv);
	printf("\n\tHo va Ten: %s", sv.htsv);
	printf("\n\tDIEM TIEU LUAN : %.2f",sv.dtl);
	printf("\n\tDIEM THI KET THUC MON : %.2f", sv.diemthi);
	printf("\n\tDIEM TONG KET : %.2f", sv.dientongket);
	printf("\n\tXEP LOAI : %s ", sv.xeploai);
}

void inputDssv(SINHVIEN dssv[], int &n){
	printf("\n\tNhap So luong sinh vien: ");
	nhap1SoNguyen(n);
	for(int i = 0;i < n;i++){
		printf("Sinh vien thu %d \n", i + 1);
		input1SinhVien(dssv[i]);
	}
}
void writeFile(SINHVIEN dssv[], int n,char fileName[50]){
	FILE *f = fopen(fileName, "wt");
	if(f == NULL){
		printf("\nLoi Ghi File!!!");
	}
	for(int i = 0;i < n;i++){
		fprintf(f, "%s\t%s\t%s", dssv[i].stt,dssv[i].mssv,dssv[i].htsv);
	}
	fclose(f);
}
void ouputDssv(SINHVIEN dssv[], int n){
	for(int i = 0;i < n;i++){
		printf("\nXuat sinh vien thu %d \n", i + 1);
		danhSachDiemTongKet(dssv,n);
		xepLoaiDanhSach(dssv,n);
		chuanHoaDSSV(dssv,n);
		ouput1SinhVien(dssv[i]);
	}
}
void diemTongKet(SINHVIEN &sv){
	sv.dientongket = ((30 * sv.dtl) / 100 + (70 * sv.diemthi) / 100);
}
void danhSachDiemTongKet(SINHVIEN dssv[], int n){
	for(int i = 0;i < n;i++){
		diemTongKet(dssv[i]);
	}
}
void xepLoaiSinhVien(SINHVIEN &sv){
	if(sv.dientongket >= 9)
		strcpy(sv.xeploai, "A+");
	else if(sv.dientongket >= 8.5)
		strcpy(sv.xeploai, "A");
	else if(sv.dientongket >= 8)
		strcpy(sv.xeploai, "B+");
	else if(sv.dientongket >= 7)
		strcpy(sv.xeploai, "B");
	else if(sv.dientongket >= 6.5)
		strcpy(sv.xeploai, "C+");
	else if(sv.dientongket >= 5.5)
		strcpy(sv.xeploai, "C");
	else if(sv.dientongket >= 5)
    	strcpy(sv.xeploai, "D+");
    else if(sv.dientongket >= 4)
    	strcpy(sv.xeploai, "D");
    else
    	strcpy(sv.xeploai, "F")	;	
}
void xepLoaiDanhSach(SINHVIEN dssv[], int n){
	for(int i = 0;i < n;i++){
		xepLoaiSinhVien(dssv[i]);
	}
}

float sinhVienCoDiemTongKetThapNhat(SINHVIEN dssv[], int n){
	float min = dssv[0].dientongket;
	for(int i = 1;i < n;i++){
		if(dssv[i].dientongket < min)
			min = dssv[i].dientongket;
	}
	return min;
}

void xuatSinhVienCoDiemTongKetThapNhat(SINHVIEN dssv[], int n){
	float min = sinhVienCoDiemTongKetThapNhat(dssv,n);
	for(int i = 0;i < n;i++){
		if(dssv[i].dientongket == min){
		printf("\nSinh Vien thu %d ", i + 1);
			ouput1SinhVien(dssv[i]);
		}
	}
}

float sinhVienCoDiemTongKetCaoNhat(SINHVIEN dssv[], int n){
	float max = dssv[0].dientongket;
	for(int i = 1;i < n;i++){
		if(dssv[i].dientongket > max){
			max = dssv[i].dientongket;
		}
	}
	return max;
}

void xuatSinhVienCoDiemTongKetCaoNhat(SINHVIEN dssv[], int n){
	float max = sinhVienCoDiemTongKetCaoNhat(dssv,n);
	for(int i = 0;i < n;i++){
		if(dssv[i].dientongket == max){
		printf("\nSinh Vien thu %d ", i + 1);
			ouput1SinhVien(dssv[i]);
		}
	}
}

void swap(SINHVIEN &a, SINHVIEN &b){
	SINHVIEN temp = a;
	a = b;
	b = temp;
}

void sapXepSinhVienTangDan(SINHVIEN dssv[], int n){
	printf("\n\t\tDANH SACH SINH VIEN DUOC SAP XEP TANG DAN THEO DIEM TONG KET");
	for(int i = 0;i < n - 1;i++)
		for(int j = i + 1;j < n;j++){
			if(dssv[i].dientongket > dssv[j].dientongket)
				swap(dssv[i],dssv[j]);
		}
		ouputDssv(dssv,n);
}

void sapXepSinhVienGiamDan(SINHVIEN dssv[], int n){
	printf("\n\t\tDANH SACH SINH VIEN DUOC SAP XEP GIAM DAN THEO DIEM TONG KET");
	for(int i = 0;i < n - 1;i++)
		for(int j = i + 1;j < n;j++){
			if(dssv[i].dientongket < dssv[j].dientongket)
				swap(dssv[i],dssv[j]);
		}
		ouputDssv(dssv,n);
}
void demCoBaoNhieuHocSinhDatVaKhongDat(SINHVIEN dssv[], int n){
	int demDAT = 0,demKHONGDAT = 0;
	for(int i = 0;i < n;i++){
		if(dssv[i].dientongket >= 4)
		{
			demDAT++;
		}
		else
		{
			demKHONGDAT++;
		}
	}
	printf("\n\tSo Hoc Sinh DAT la : %d ", demDAT);
	printf("\n\tSo Hoc Sinh KHONG DAT!!! la : %d ", demKHONGDAT);
}
double diemTrungBinhTatCaHocSinh(SINHVIEN dssv[], int n){
	double diemTB = 0;
	for(int i = 0;i < n;i++){
		diemTB += dssv[i].dientongket;
	}
	return diemTB / n;
}
void chuanHoaChuoi(SINHVIEN &sv){
	//Chuyen Hoa dau chuoi
	while(sv.htsv[0] == ' ')
		strcpy(&sv.htsv[0],&sv.htsv[1]);
		//Chuyen Hoa Giua Chuoi
	int len = strlen(sv.htsv);
	for(int i = 0;i < len - 1;i++){
		if(sv.htsv[i] ==' ' && sv.htsv[i + 1] == ' '){
			strcpy(&sv.htsv[i],&sv.htsv[i + 1]);
			i--;
		}			
	}
	//Chuoi Hoa Cuoi Chuoi
	while(sv.htsv[len - 1] == ' '){
		sv.htsv[len - 1] = '\0';
		len--;
	}
}
void chuanHoaDSSV(SINHVIEN dssv[], int n){
	for(int i = 0;i < n;i++){
		chuanHoaChuoi(dssv[i]);
	}
}
int khoangTrangCuoiCung(SINHVIEN sv){
	int len = strlen(sv.htsv);
	for(int i = len - 1;i >= 0;i--){
		if(sv.htsv[i] == ' ')
			return i;
	}
	return -1;
}
void timKiemTenTrongChuoi(SINHVIEN sv){
	int ktc = khoangTrangCuoiCung(sv);
	int len = strlen(sv.htsv);
	for(int i = ktc + 1;i < len;i++){
		printf("%c", sv.htsv[i]);
	}
}
void menu(){
	printf("\n********************************************************");
	printf("\n*			MENU						  				  ");
	printf("\n********************************************************");
	printf("\n* 0 De thoat khoi chuong trinh						  ");
	printf("\n* 1 Nhap , xuat danh sach sinh vien					  ");
	printf("\n* 2 In sinh vien co dien tong ket cao nhat AND thap nhat");
	printf("\n* 3 Sap xep danh sach sinh vien Tang/Giam theo DTK 	  ");
	printf("\n* 4 Cho biet co bao nhieu sinh vien dat va khong dat	  ");
	printf("\n* 5 Hay tinh dien trung binh cua tat ca sinh vien		  ");
	printf("\n* 6 Thuc hien viec nhap xuat du lieu bang file text	  ");
	printf("\n********************************************************");
}

void thucThi(){
	int n,luachon;
	SINHVIEN sv;
	SINHVIEN dssv[100];
	do{
		menu();
		printf("\n\tSu lua chon cua ban la: ");
		nhap1SoNguyen(luachon);
		switch(luachon){
			case 1:{
				inputDssv(dssv,n);
				printf("\tDANH 	SACH	SINH	VIEN	SAU	   KHI	  XUAT");
				ouputDssv(dssv,n);
				break;
			}
			case 2:{
				printf("\nDANH  SACH   SINH  SIEN   CO  DIEM  TONG  KET THAP  NHAT");
				xuatSinhVienCoDiemTongKetThapNhat(dssv,n);
				printf("\nDANH  SACH   SINH  SIEN   CO  DIEM  TONG  KET CAO NHAT  ");
				xuatSinhVienCoDiemTongKetCaoNhat(dssv,n);
				
				break;
			}
			case 3:{
				sapXepSinhVienTangDan(dssv,n);
				sapXepSinhVienGiamDan(dssv,n);
				break;
			}
			case 4:{
				demCoBaoNhieuHocSinhDatVaKhongDat(dssv,n);
				break;
			}
			case 5:{
				printf("\n\tDIEM TRUNG BINH CUA TAT CA CAC HOC SINH : %.3f", diemTrungBinhTatCaHocSinh(dssv,n));
				break;
			}
			case 6:{
				writeFile(dssv,n,"dsSV.txt");//sai
				break;
			}
		}
		
	}while(luachon != 0);
}


