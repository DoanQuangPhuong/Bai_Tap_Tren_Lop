#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#define MAX 100
struct PHANSO{
	int tuso;
	int mauso;
};

void nhap2Songuyen(int *pa, int *pb);
int KetQuatong2SoNguyen(int *pa, int *pb);
int KetQuaHieu2SoNguyen(int *pa, int *pb);
float KetQuatich2SoNguyen(int *pa, int *pb);
float KetQuathuong2SoNguyen(int *pa, int *pb);

void chuyenThanhChuHoa();
void kyTuDauVietHoa();

void inputArr(int *arr, int &n);
void ouputArr(int *arr, int n);
void ouputArrThuc(float *arr, int n);
void xuatSoCucTieu(int *arr, int n);
void xoaPhanTuTrongMang(int *arr, int &n, int &k);
void themMotPhanTu(int *arr, int &n,int k, int x);
void swap(int &a, int &b);
void duaGiaTriChanLenDauMang(int *arr, int viTriChan);
void chanLenDauLeXuongDuoi(int *arr, int n);
int chanLeXenKe(int *arr, int n);
int chanLeTheoDeQuy(int *arr, int n, int i);
void chiaAchoB(int *a, int *b,float *c,int n);
void timMAX(int *arr, int n, int *max);
void chanLonNhat(int *arr, int n, int *chan);
void leNhoNhat(int *arr, int n, int *le);
void deleteX(int *arr, int &n,int viTri);
void xoaGiaTri0(int *arr, int &n);
void themXvaoSauPTDauTien(int *arr, int &n, int &x);
int ktSoChinhPhuong(int n);
void tongSoChinhPhuong(int *arr, int n, int *sumCP);
void xuatSoCucDai(int *arr, int n);

void InputPhanSo(PHANSO &ps);
void OuputPhanSo(PHANSO ps);
int UCLN(int a,int b);
void RutgonPS(PHANSO &ps);
void inputArrPhanSo(PHANSO dsps[], int &n);
void ouputArrPhanSo(PHANSO dsps[], int n);
void xuatPtMauLonHonTu(PHANSO dsps[], int n);
int countPtCoMauTuChan(PHANSO dsps[], int n);

int main(){
	
//							Bai 9

//	int a,b,kt[MAX];
//	nhap2Songuyen(&a,&b);
//	int Tong = KetQuatong2SoNguyen(&a,&b);
//	printf("\nGia tri tong = %d va Dia chi %x",Tong,&Tong);
//	int Hieu = KetQuaHieu2SoNguyen(&a,&b);
//	printf("\nGia tri hieu = %d va Dia chi %x",Hieu,&Hieu);
//	int Tich = KetQuatich2SoNguyen(&a,&b);
//	printf("\nGia tri Tich = %d va Dia chi %x",Tich,&Tich);
//	float Thuong = KetQuathuong2SoNguyen(&a,&b);
//	printf("\nGia tri Thuong = %.3f va Dia chi %x",Thuong,&Thuong);
//======================================================================================================================
//							Bai 10

//	chuyenThanhChuHoa();
//	kyTuDauVietHoa();

//========================================================================================================================
//							Bai 11

//int arr[MAX],n,k,x;
//inputArr(arr,n);
//ouputArr(arr,n);
//xuatSoCucTieu(arr,n);
//xoaPhanTuTrongMang(arr,n,k);
//themMotPhanTu(arr,n,k,x);
////chanLenDauLeXuongDuoi(arr,n);
////if(chanLeXenKe(arr,n) == 1)
////	printf("\n\tMang Chan le Xen ke");
////else
////	printf("\n\tMang Khong Chan le Xen ke!!!");
//	if(chanLeTheoDeQuy(arr,n,0) == 1)
//		printf("\n\tMang Chan le Xen ke");
//	else
//		printf("\n\tMang Khong Chan le Xen ke!!!");

//====================================================================================================================================

//							Bai 13

//int a[MAX],b[MAX],n;
//float c[MAX];
//inputArr(a,n);
//inputArr(b,n);
//chiaAchoB(a,b,c,n);

//===============================================================================================================================================

//							Bai 7
//int arr[MAX],n,k,x,p;
//inputArr(arr,n);
//ouputArr(arr,n);
//int max = arr[0];
//timMAX(arr,n,&max);
//printf("\n\t+Gia tri lon nhat trong mang = %d", max);
//printf("\n\t+DIA CHI cua max la %x", &max);
//int chan;
//int le;
//chanLonNhat(arr,n,&chan);
//leNhoNhat(arr,n,&le);
//printf("\n\t++Gia tri chan lon nhat la : %x ", &chan);
//printf("\n\t++Gia tri le nho nhat la : %x ", &le);
//printf("\n\tMang sau khi Xoa tat ca phan tu 0 trong mang");
//xoaGiaTri0(arr,n);
//////themXvaoSauPTDauTien(arr,n,p);
//int sumCP = 0;
//tongSoChinhPhuong(arr,n,&sumCP);
//printf("\n\tTong tat ca so chinh phuong trong mang = %d", sumCP);
//xuatSoCucDai(arr,n);
//==================================================================================================================================

//								BAI 8

//int n;
//PHANSO ps;
//PHANSO dsps[MAX];
//inputArrPhanSo(dsps,n);
//ouputArrPhanSo(dsps,n);
//xuatPtMauLonHonTu(dsps,n);
//printf("\n\tSo Phan tu co Mau so va Tu so deu la so chan : %d ", countPtCoMauTuChan(dsps,n));
	return 0;
}


void nhap2Songuyen(int *pa, int *pb){
	do{
		printf("Nhap so Nguyen a = ");scanf("%d", pa);
		printf("\nNhap so Nguyen b = ");scanf("%d", pb);
	}while(*pa <= 0 || *pb <= 0);
}
int KetQuatong2SoNguyen(int *pa, int *pb){
	int KetQua = *pa + *pb;
	return KetQua;
}

int KetQuaHieu2SoNguyen(int *pa, int *pb){
	int KetQua = *pa - *pb;
	return KetQua;
}

float KetQuatich2SoNguyen(int *pa, int *pb){
	int KetQua = *pa * *pb;
	return KetQua;
}

float KetQuathuong2SoNguyen(int *pa, int *pb){
	float KetQua = float(*pa / *pb);
	return KetQua;
}

void chuyenThanhChuHoa(){//Chuyen chu thuong thanh chu hoa
	char kt[MAX], *ptr;
	printf("\nNhap chuoi ki tu tuy y:");
	gets(kt);
	ptr = kt;
	for(int i = 0;i < strlen(kt);i++){
	if(*(ptr + i) >=97 && *(ptr + i) <= 122){//Chuyen Hoa
		*(ptr + i) -= 32;
		}
	}
		printf("%s", ptr);
}

void kyTuDauVietHoa(){//Ki tu dau in hoa
	char kt[MAX], *ptr;
	ptr = kt;
	for(int i = 0;i < strlen(kt);i++){
		if(i == 0 || (i > 0 && *((ptr + i) - 1) == 32 )){ 
			if(*(ptr + i) >=97 && *(ptr + i) <= 122)//Chuyen Hoa
				*(ptr + i) -= 32;
			}
			else{
				if(*(ptr + i) >= 65 && *(ptr + i) <= 90)//Chuyen thuong
					*(ptr + i) += 32;
		}
	}
		printf("\n%s", ptr);
}
void inputArr(int *arr, int &n){//nhap mang
	do{
		printf("\nNhap so luong phan tu mang: ");scanf("%d", &n);
		if(n <= 0 ||n > MAX){
			printf("Vui long nhap lai!!!\n");
		}
	}while(n <= 0 ||n > MAX);
	for(int i = 0;i < n;i++){
		printf("\narr[%d] = ",i);scanf("%d", &arr[i]);
	}	
}
void ouputArr(int *arr, int n){//xuat mang
	printf("\nMang Sau khi duoc xuat la: ");
	for(int i = 0;i < n;i++){
		printf("%d ", arr[i]);
	}
}
void ouputArrThuc(float *c, int n){//xuat mang so thuc
	printf("\nMang Sau khi duoc xuat la: ");
	for(int i = 0;i < n;i++){
		printf("%.3f ", c[i]);
	}
}
void xuatSoCucTieu(int *arr, int n){//xuat cac gia tri cua tieu
	int flag = 0;
	for(int i = 1;i < n - 1;i++){
		if(arr[i] < arr[i - 1] && arr[i] < arr[i + 1]){//so cuc tieu la so nho hon so xung quanh no
			printf("\n+Gia tri cuc tieu trong mang la %d", arr[i]);
			flag = 1;
		}
	}
	if(flag  == 0)
		printf("\nKhong co gia tri cuc tieu nao trong mang ca!!!");
}
void xoaPhanTuTrongMang(int *arr, int &n, int &k){//Xoa phan tu tai vi tri thu
	printf("\nBan muon xoa vi tri thu = ");scanf("%d", &k);
	for(int i = k;i < n - 1;i++){
		arr[i] = arr[i + 1];
	}
	n--;
	ouputArr(arr,n);
}
void themMotPhanTu(int *arr, int &n,int k, int x){//Them 1 phan tu vao mang
	printf("\nBan muon them vao vi tri thu = ");scanf("%d", &k);
	printf("Gia tri Muon them vao = ");scanf("%d", &x);
	for(int i = n - 1;i >= k;i--){
		arr[i + 1] = arr[i];
	}
	arr[k] = x;
	n++;
	ouputArr(arr,n);
}
void swap(int &a, int &b){//Ham hoan doi
	int temp = a;
	a = b;
	b = temp;
}
void duaGiaTriChanLenDauMang(int *arr, int viTriChan){//Dua gia tri chan len dau mang
	int temp = arr[viTriChan];
	for(int i = viTriChan; i > 0;i--){
		arr[i] = arr[i - 1];
	}
	arr[0] = temp;
}
void chanLenDauLeXuongDuoi(int *arr, int n){//Chan len dau, le xuong duoi
	for(int i = 0;i < n;i++){
		if(arr[i] % 2 == 0){
			duaGiaTriChanLenDauMang(arr,i);
		}
	}
	ouputArr(arr,n);
}
int kienTraChanLeXenKe(int *arr, int n){//Kiem tra mang co chan le sen ke hay khong
	for(int i = 0;i < n - 1;i++){
		if(arr[i] % 2 == 0 && arr[i + 1] % 2 == 0 || arr[i] % 2 != 0 && arr[i + 1] % 2 != 0)
			return 0;
	}
	return 1;
}
//Theo phuong phap De Quy
int chanLeTheoDeQuy(int *arr, int n,int i){
	if(i >= n - 1)
		return 1;
	if(arr[i] % 2 == 0 && arr[i + 1] % 2 == 0 || arr[i] % 2 != 0 && arr[i + 1] % 2 != 0)
		return 0;
	chanLeTheoDeQuy(arr,n,i + 1);
}
void chiaAchoB(int *a, int *b,float *c,int n){//chia mang a cho mang b
	for(int i = 0;i < n;i++){
		c[i] = float(a[i] / b[i]);
	}
	ouputArrThuc(c,n);
}
void timMAX(int *arr, int n, int *max){//Tim gia tri lon nhat trong mang
	for(int i = 0;i < n;i++){
		if(arr[i] > *max)
			*max = arr[i];
	}
}
void chanLonNhat(int *arr, int n, int *chan){//chan lon nhat trong mang
	for(int i = 0;i < n;i++){
		if(arr[i] % 2 == 0 && arr[i] > *chan)
			*chan = arr[i];
	}
}
void leNhoNhat(int *arr, int n, int *le){//Le nho nhat trong mang
	for(int i = 0;i < n;i++){
		if(arr[i] % 2 != 0){
			*le = arr[i];
			break;
		}
	}
	for(int i = 0;i < n;i++){
		if(arr[i] % 2 != 0)
			if(arr[i] < *le)
				*le = arr[i];
	}
}
void deleteX(int *arr, int &n,int viTri){//Xoa mot phan tu
	for(int i = viTri;i < n - 1;i++){//n = 5
		arr[i] = arr[i + 1];
	}
	n--;
}
void xoaGiaTri0(int *arr, int &n){//Xoa tat  ca so 0 trong mang
	for(int i = 0;i < n;i++){
		if(arr[i] == 0){
			deleteX(arr,n,i);
			i--;
		}
	}
	ouputArr(arr,n);
}
void themXvaoSauPTDauTien(int *arr, int &n, int &x){//Sai
	printf("\nNhap gia tri can them vao : ");scanf("%d", &x);
	for(int i = n - 1;i > 0;i--){
		arr[i] = arr[i + 1];
	}
	arr[1] = x;
	n++;
	ouputArr(arr,n);
}
int ktSoChinhPhuong(int n){//Kiem tra so chinh phuong
	if(n < 1)
		return 0;
	int i = sqrt(n);
	return(pow(i,2) != n ? 0 : 1);
}
void tongSoChinhPhuong(int *arr, int n, int *sumCP){//Tong cac so chinh phuong trong mang
	for(int i = 0;i < n;i++){
		if(ktSoChinhPhuong(arr[i]) == 1)
			*sumCP += arr[i];
	}
}
void xuatSoCucDai(int *arr, int n){//Xuat gia tri cuc dai trong mang
	printf("\n\tSo cuc dai trong mang la: ");
	for(int i = 1;i < n - 1;i++){
		if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
			printf("%d ", arr[i]);
	}
}

int UCLN(int a,int b){//Tim uoc chung lon nhat
	a = abs(a);
	b = abs(b);
	while(a != b){
		if(a > b)
		a -= b;
		else 
		b -= a;
	}
	return a;
}
void RutgonPS(PHANSO &ps){//Rut Gon Phan so
	int k = UCLN(ps.tuso,ps.mauso);
	ps.tuso /= k;
	ps.mauso /= k;
}
//Nhap phan so
void InputPhanSo(PHANSO &ps){
	printf("\nTu So:");scanf("%d", &ps.tuso);
	do{
		printf("Mau So:");scanf("%d", &ps.mauso);
		if(ps.mauso == 0)
		printf("\nVui long nhap lai mau khac 0!!!");
	}while(ps.mauso == 0);// Bang 0 thi lap lai
}
void OuputPhanSo(PHANSO ps){//Xuat Phan so
	printf("\t%d / %d", ps.tuso,ps.mauso);
	RutgonPS(ps);
}
void inputArrPhanSo(PHANSO dsps[], int &n){
	do{
		printf("\nNhap so phan  tu trong mang: ");scanf("%d", &n);
		if(n <= 0 || n > MAX)
			printf("\nVui long nhap lai!!!!");
	}while(n <= 0 || n > MAX);
	for(int i = 0;i < n;i++){
		InputPhanSo(dsps[i]);
	}
}
void ouputArrPhanSo(PHANSO dsps[], int n){
	printf("Mang Phan so khi duoc xuat:");
	for(int i = 0;i < n;i++){
		OuputPhanSo(dsps[i]);
		RutgonPS(dsps[i]);
	}
}
void xuatPtMauLonHonTu(PHANSO dsps[], int n){//Xuat phan so co mau lon hon tu
	printf("\n\tPhan so co Mau so lon hon Tu so la ");
	for(int i = 0;i < n;i++){
		if(dsps[i].mauso > dsps[i].tuso)
			OuputPhanSo(dsps[i]);
	}
}
int countPtCoMauTuChan(PHANSO dsps[], int n){//Dem phan so co mau va tu deu chan
	int count = 0;
	for(int i = 0;i < n;i++){
		if(dsps[i].tuso % 2 == 0 && dsps[i].mauso % 2 == 0)
			count++;
	}
	return count;
}
int phanSoMax(PHANSO dsps[], int n){
	
}

