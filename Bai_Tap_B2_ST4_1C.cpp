#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define MAXSIZE 100
typedef int Itemtype;//Khai bao 1 kieu du lieu nguoi dung
void inpurArr(Itemtype *arr, int &n);
void ouputArr(Itemtype *arr, int n);
void writeFile(int *arr, int n, char nameFile[]);
void readFile(int *arr, int &n,char nameFile[50]);
void mangNgauNhienLonHonHoacBang15(Itemtype *arr, int n);
void mangNgauNhienToanLaSoChan(Itemtype *arr, int &n );
int tinXTuyenTinh(Itemtype *arr, int n, Itemtype x);
void swap(Itemtype &a, Itemtype &b);
void mangTangDan(Itemtype *arr, int n);
int timXNhiPhan_nonDQ(Itemtype *arr, int n, Itemtype x);
int timXNhiPhan_DQ(Itemtype *arr, int left, int right, Itemtype x);
void mangGiamDan(Itemtype *arr, int n);
void tang_Quick_Sort(Itemtype *arr,int Left, int Right);
int kiemTraSoNguyenTo(int n);
void lietKeSoNguyenToNhoHonN(int n);
int chuSoLeDauTien(int n);
int tongChuSoLeDauTien(Itemtype *arr, int n);
void demChuSoTrongArr(Itemtype *arr, int n, Itemtype b[]);
void tangDanChanLeDuNguyen(Itemtype *arr, int n);
Itemtype minMang(Itemtype *arr, int n);
Itemtype min2Mang(Itemtype *arr, int n);
void duaGiaTriChanLenDauMang(int *arr, int viTriChan);
void chanLenDauLeXuongDuoi(int *arr, int n);
int kiemTraX(int n, int x);
int timXCo2ChuSo(Itemtype n, int x);
void xuatPhanTuThoaDieuKienX(Itemtype *arr, int n, int x);
void sapXeptheoSelectionMIN(int *arr, int n); 
int kiemTraMangTangGiamKhongTangKhongGiam(Itemtype *arr, int n);
void  xuatSoLanPhanTuXuatHienTrongMang(Itemtype *arr, int n);
int demMangAtrongMangB(Itemtype *arr,Itemtype b[MAXSIZE], int n,int nb);
int  xuatSoLanPhanTuXuatHienTrongMandasdg(Itemtype *arr, int n);
int demSoLanPhanTuXuatHienTrongMang(Itemtype *arr, int n, int x);
void xuatPhanTuXuatHienNhieuNhatTrongMang(Itemtype *arr, int n);
void xuatCacPhanTuXuatHienTrongMang(Itemtype *arr, int n , int b[]);
int timMax_DeQuy(int *arr, int first , int last);
int tinhTongMangTheoDeQuy(int *arr, int n);
int TimMaxDeQuy(int *arr, int n);
int kiemTraDK(int n);
void lietKeCacPhanTuCoChuSoHangChucLonHonHangDonVi(int *arr, int n);
int kiemTraCoPhaiLaCapSoCongHayKhong(int *arr, int n);
int kiemTraCoPhaiLaCapSoNhanHayKhong(int *arr, int n);
int timSoNguyenToDauTien(Itemtype *arr, int n);
int timViTriMaxNT(Itemtype *arr, int n);
int timViTriMax(int *arr, int n);
int Max(int *arr, int n);
int Min(int *arr, int n);
void themXVaoSauMax(int *arr, int &n,  int GiaTri);
void themXTruocSauMin(int *arr, int &n, int GiaTri);
Itemtype min2Mang(Itemtype *arr, int n);
int max1(int *arr, int n);
void thucThi();

int main(){
	thucThi();
	
	
	return 0;
}

void nhapSoNhguyenN(int &n){
	do{
		scanf("%d", &n);
		if(n < 0)
			printf("\nVui long nhap lai!!!");
	}while(n < 0);
}

void inpurArr(Itemtype *arr, int &n){
	do{
		printf("\nNhap so phan tu trong mang : ");scanf("%d", &n);
		if(n <= 0)
			printf("\nVui long nhap lai!!!");
	}while(n <= 0);
	for(int i = 0;i < n;i++){
		printf("\narr[%d] = ", i);scanf("%d", arr + i);
	}
}

void ouputArr(Itemtype *arr, int n){
	for(int i = 0;i < n;i++){
		printf("%4d ", *(arr + i));
	}
}

//Ghi/Viet File Du Lieu
void writeFile(int *arr, int n, char nameFile[50]){
	FILE *f;
	f = fopen(nameFile, "wt");
	if(f == NULL){
		printf("\nLoi File!!!");
		return;
	}
	fprintf(f, "%d\n", n);
	for(int i = 0;i < n;i++){
		fprintf(f,"%5d", arr[i]);
	}
	fclose(f);
	
}

//Doc Du Lieu Tu File
void readFile(int *arr, int &n,char nameFile[50]){
	FILE *f = fopen(nameFile, "rt");
	if(f == NULL){
		printf("\nLoi File!!!");
		return;
	}
	fscanf(f, "%d", &n);
	printf("%d Phan Tu \t\n",n);
	for(int i = 0;i < n;i++){
		fscanf(f, "%d", &arr[i]);
	}
	fclose(f);
}

void mangNgauNhienLonHonHoacBang15(Itemtype *arr, int n){
	int x = 15;
	int y =  1000;
	srand((unsigned)time(NULL));
	for(int i = 0;i < n;i++){
		arr[i] = x + rand() % (y - x + 1);
	}
	ouputArr(arr,n);
}

void mangNgauNhienToanLaSoChan(Itemtype *arr, int &n){
	int x = -50;
	int y =  50;
	printf("Nhap so phan tu trong mang: ");
	nhapSoNhguyenN(n);
	printf("\n\tSo phan tu ngau nhien chan la : ");
	srand((unsigned)time(NULL));
	for(int i = 0;i < n;i++){
		int temp;
	do{
		temp = x + rand() % (y - x + 1);
	}while(temp % 2 != 0);//Neu temp % 2 != 0 thi tiep tuc lap
		arr[i] = temp;//tao so chan co gia tri tu -50 den 50
	}
	ouputArr(arr,n);
}

int tinXTuyenTinh(Itemtype *arr, int n, Itemtype x){
	for(int i = 0;i < n;i++){
		if(arr[i] == x)
		return i;
	}
	return -1;
}

int timXNhiPhan_nonDQ(Itemtype *arr, int n, Itemtype x){ //				 |Note: mang Phai Duoc Sap Xep|
	int left = 0;//Ben TRAI
	int right = n - 1;//BEN PHAI
	while(left <= right){
		int mid = (left + right) / 2;//Vi tri giua
			if(arr[mid] == x)//Tim thay X tai vi tri giua
				return mid;
		    else if(arr[mid] > x)
		    	right = mid - 1;//Chinh giua LON HON Tim tren nua TRAI
		    else
		    left = mid + 1;//Chinh giua NHO HON thi Tim tren nua PHAI
	}
	return -1;//Khong tim thay X
}

int timXNhiPhan_DQ(Itemtype *arr, int left, int right, Itemtype x){//      |Note:Mang Phai Duoc Sap Xep|
	if(left > right)
		return -1;
	int mid = (left + right) / 2;
	if(arr[mid] == x)
		return mid;//Tim thay o giua
	else if(arr[mid] > x)
		return timXNhiPhan_DQ(arr , 0 , mid - 1, x);
	else
		return timXNhiPhan_DQ(arr , mid + 1 , right , x);
}

void swap(Itemtype &a, Itemtype &b){
	Itemtype temp = a;
	a = b;
	b = temp;
}

void mangTangDan(Itemtype *arr, int n){
	printf("\n\tMang sau khi sap Xep Tang dan: ");
	for(int i = 0;i < n - 1;i++)
		for(int j = i + 1;j < n;j++){
			if(arr[i] > arr[j])
				swap(arr[i],arr[j]);
		}
		ouputArr(arr,n);
}

void mangGiamDan(Itemtype *arr, int n){
	printf("\n\tMang sau khi sap Xep Giam dan: ");
	for(int i = 0;i < n - 1;i++)
		for(int j = i + 1;j < n;j++){
			if(arr[i] < arr[j])
				swap(arr[i],arr[j]);
		}
		ouputArr(arr,n);
}

//NOTE : 

void tang_Quick_Sort(Itemtype *arr,int Left, int Right){
	if (Left >= Right) return;
	int i = Left, j = Right, Mid = (Left+Right)/2;
	int x = arr[Mid];
	do {
	while(arr[i] < x) 
		i++; // Lap cho den khi a[i] >= x
	while(arr[j] > x) 
		j--; // Lap cho den khi a[j] <= x
	if(i <= j) {
	if(i < j)
	swap(arr[i], arr[j]);
	i++;
	j--;
	}
	} while(i < j);
	tang_Quick_Sort(arr, Left, j);//Phan hoach xep ben trai 
	tang_Quick_Sort(arr, i, Right);//Phan hoach ben Phai
}

int kiemTraSoNguyenTo(int n){
	if(n < 2)
		return 0;
	for(int i = 2; i <= sqrt(n);i++){
		if(n % i == 0)
			return 0;
	}
	return 1;
}

void lietKeSoNguyenToNhoHonN(int n){
	printf("Cac so nguyen to nho hon n la: ");
	for(int i = 0;i < n;i++){
		if(kiemTraSoNguyenTo(i) == 1)
			printf("%4d", i);
	}
}

int timSoNguyenToDauTien(Itemtype *arr, int n){
	for(int i = 0;i < n;i++){
		if(kiemTraSoNguyenTo(arr[i]))
			return arr[i];
	}
	return -1;
}
int timViTriMaxNT(Itemtype *arr, int n){
	if(timSoNguyenToDauTien(arr,n) == -1)
		return -1;
	int id = 0,NTDT = timSoNguyenToDauTien(arr,n);
	for(int i = 0;i < n;i++){
		if(kiemTraSoNguyenTo(arr[i]) && arr[i] > NTDT)
		{
			id = i;	
		}
	}
	return id;
}

int chuSoLeDauTien(int n){
	while(n >= 10){
		n /= 10;	
	}
	return(n % 2 == 0 ? 0 : 1);
}

int tongChuSoLeDauTien(Itemtype *arr, int n){
	int tong = 0;
	for(int i = 0;i < n;i++){
		if(chuSoLeDauTien(arr[i]) == 1)
			tong += arr[i];
	}
	return tong;
}

void demChuSoTrongArr(Itemtype *arr, int n, Itemtype c[]){
	for(int i = 0;i < n;i++){
		int temp = abs(arr[i]);
		while(temp != 0){
			int i = temp % 10;
			c[i]++;//Lay tung chu So Dem vao mang c[]
			temp /= 10;
		}
	}
}

void tangDanChanLeDuNguyen(Itemtype *arr, int n){
	for(int i = 0;i < n - 1;i++)
		for(int j = i + 1;j < n;j++){
				if(arr[i] % 2 == 0 && arr[j] % 2 == 0 && arr[i] > arr[j])
					swap(arr[i],arr[j]);
			}
			ouputArr(arr,n);
}

Itemtype minMang(Itemtype *arr, int n){
	int min = arr[0];
	for(int i = 1;i < n;i++){
		if(arr[i] < min)
			min = arr[i];
	}
	return min;
}

Itemtype min2Mang(Itemtype *arr, int n){//??
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

//Tim MIn roi sap xep
void sapXeptheoSelectionMIN(int *arr, int n){
	printf("\n\tSap Xep theo kieu Selection sort (Tim min roi Sap xep) : ");
	for(int i = 0;i < n - 1;i++){
		int imin = i;//Cap nhat min thay doi
		for(int j = i + 1;j < n;j++){
			if(arr[imin] > arr[j])
				imin = j;
			}
				swap(arr[imin],arr[i]);//Hoan doi vi tri min vs vi tri thu i
	}
	ouputArr(arr,n);
}

int kiemTraMangTangGiamKhongTangKhongGiam(Itemtype *arr, int n){
	int flag = 0;
	for(int i = 0;i < n - 1;i++){
		if(arr[i] > arr[i + 1]){
			flag = 1;
			break;
		}
		else if(arr[i] < arr[i + 1]){
			flag = 2;
			break;
		}
	}
	return flag;//sai
}

void  xuatSoLanPhanTuXuatHienTrongMang(Itemtype *arr, int n){
	for(int i = 0;i < n;i++){
		int dem = 0;
		for(int j = 0;j < n;j++){
			if(arr[i] == arr[j]){
				if(i <= j){
					dem++;
				}
				else{
					break;
				}
			}
		}
		if(dem != 0)
			printf("\n\t[> <]Phan tu %d Xuat hien %d lan",arr[i],dem);
	}
} 

// 						 Dem phan tu xuat hien trong mang THOA DIEU KIEN

int demSoLanPhanTuXuatHienTrongMang(Itemtype *arr, int n, int x){
	int count = 0;
		for(int j = 0; j < n ;j++){ // Kiem tra phan tu do voi tung phan tu trong mang
			if(arr[x] == arr[j]){
				if(x <= j){ // DK: chi dem khi arr[x] = arr[j] va dong thoi x <= j [tuk la phan tu sau trung phan tu truoc thi bo qua cua lenh vi [x <= j]]
					count++;
				}
				else{
					break;
				}
			}
		}
	return count;
}

// 							Phan tu xuat hien nhieu nhat trong mang

void xuatPhanTuXuatHienNhieuNhatTrongMang(Itemtype *arr, int n){
	int temp = demSoLanPhanTuXuatHienTrongMang(arr,n,0), temp1, index = 0;
	for(int i = 1;i < n;i++){
		temp1 = demSoLanPhanTuXuatHienTrongMang(arr,n,i);
		if(temp1 > temp){
			temp = temp1;
			index = i;
		}
	}
	for(int i = 0;i < n;i++){
		if(demSoLanPhanTuXuatHienTrongMang(arr,n,i) == temp)
			printf("\n\tPhan tu %d Xuat hien nhieu nhat trong mang [%d lan]", arr[i],temp);
	}
}
//											cach 2
	
// 							Cac phan tu xuat hien nhieu nhat trong mang
void xuatCacPhanTuXuatHienTrongMang(Itemtype *arr, int n, int b[]){
	for(int i = 0;i < n;i++){ 
		for(int j = 0; j < n ;j++){ 
			if(arr[i] == arr[j]){
				if(i <= j){ //Dk neu phan tu SAU trung phan tu TRUOC thi break;
					b[i]++;
				}
				else{
					break;
				}
			}
		}
	}
	int max = b[0];
	for(int i = 1;i < n;i++){
		if(b[i] != 0){
			max = (b[i] > max ? b[i] : max);
		}
	}
	for(int i = 0;i < n;i++){
		if(b[i] == max)//Kiem tra 
			printf("\n\tPhan tu %d Xuat hien nhieu nhat [%d lan] ", arr[i],b[i]);
	}
}

// Dem phan tu mang A co trong mang B hay khong ?
int demMangAtrongMangB(Itemtype *arr, Itemtype b[MAXSIZE],int n,int nb){
	int flag,start,count = 0;
	for(int i = 0;i < nb;i++){//Duyet Mang B[]
		 if(arr[0] == b[i] && nb - i >= n){
		 	flag = 1;//Danh Dau
		 	start = i;//Bat dau tu Vi tri dau tien cua mang A vs Mang Phan tu Bi Trung Thu i cua Mang B
		 	for(int j = 0;j < n;j++){ // Duyet Mang arr[]
		 		if(arr[j] != b[start])//hoac arr[j] != b[start++]
				 {
		 			flag = 0;
		 			break;
				 }
				 start++;//Tang Vi tri Bi trung len 1 don Vi
			 }
			 if(flag == 1){//Mang arr[] xuat hien trong b[] thi tang count len 1 don vi
			 	count++;
			 }
		 }
	}
	return count;
}

//int kiemTraX(Itemtype n, int x){
//	while(n > 0){
//		int k = n % 10;
//		if(k == x)
//			return 1;
//		n /= 10;
//	}
//	return 0;
//}
//int timXCo2ChuSo(Itemtype n, int x){
//	int i = x % 10;
//	x /= 10;
//	int j = x % 10;
//	while(n > 0){
//		int k = n % 10;
//		if(kiemTraX(k,i) == 1 || kiemTraX(k,j) == 1 );
//		return 1;
//		n /= 10;
//	}
//	return 0;
//}
//void xuatPhanTuThoaDieuKienX(Itemtype *arr, int n, int x){
//	int flag = 0;
//	for(int i = 0;i < n;i++){
//		if(timXCo2ChuSo(arr[i],x) == 1){
//			printf("%4d ", arr[i]);
//				flag = 1;
//	}
//	}
//	if(flag == 0)
//		printf("\n\tKhong co phan tu thoa man DIEU KIEN X!!!");
//}
int timMax_DeQuy(int *arr, int first , int last){
	if(first == last)
		return arr[first];// Neu Ma mang co 1 phan tu thi return arr[first] hoac arr[last] deu duoc
	int max = timMax_DeQuy(arr,first + 1,last);
		if(max < arr[first])
			max = arr[first];
	return max;
}
//Tinh tong theo phuong phap[De Quy]
int tinhTongMangTheoDeQuy(int *arr, int n){
	if(n == 1)
		return arr[0];
	return tinhTongMangTheoDeQuy(arr,n - 1) + arr[n - 1];
}
//Tinh Max theo phuong phap De Quy
int max2So(int a , int b){
	return a > b ? a : b;
}
int TimMaxDeQuy(int *arr, int n){
	if(n == 1)
		return arr[0];
	return max2So(TimMaxDeQuy(arr,n - 1),arr[n - 1]);
}

int max1(int *arr, int n){
	if(n == 1){
		if(arr[0] % 2 == 0)
			return arr[0];
		else
			return 0;
	}
	int max = max1(arr,n - 1);
	if(arr[n - 1] % 2 == 0 && arr[n - 1] > max)
		max = arr[n - 1];
	return max;
}

//Kiem Tra Mang Doi Xung Bang DE QUY

int kiemTraMangDoiXung_De_Quy(int *arr, int left, int right){
	if(left >= right)
		return 1;
	if(arr[left] != arr[right])
		return 0;
	return kiemTraMangDoiXung_De_Quy(arr,left + 1,right - 1);
}

//Xuat cac phan tu co chu so han chuc lon hon chu so hang don vi

int kiemTraDK(int n){
	if(n < 10)
		return 0;
	int i = n % 10;//Hang Don Vi
	n /= 10;
	int k = n % 10;//Hang Chuc
	return k > i ? 1 : 0;
}
void lietKeCacPhanTuCoChuSoHangChucLonHonHangDonVi(int *arr, int n){
	printf("\n\tCac So Co Chu So Hang Chuc Lon Hon Hang Don Vi la : ");
	for(int i = 0;i < n;i++){
		if(kiemTraDK(arr[i]) == 1)
			printf("%6d", arr[i]);
	}
}

int kiemTraCoPhaiLaCapSoCongHayKhong(int *arr, int n){//VD : 3 6 9 12 15 18 21...
	int d = arr[1] - arr[0];
	for(int i = 1;i < n - 1;i++){
		if(arr[i + 1] - arr[i] != d)
			return 0;
	}
	return 1;
}
int kiemTraCoPhaiLaCapSoNhanHayKhong(int *arr, int n){//3 6 12 24 48 96....
	for(int i = 0;i < n - 1;i++){
		if(arr[i] * 2 != arr[i + 1])
			return 0;
	}
	return 1;
}

int Max(int *arr, int n){
	int max = arr[0];
	for(int i = 1;i < n;i++) {
		if(arr[i] > max)
			max = arr[i];
	}
	return max;
}
int Min(int *arr, int n){
	int min = arr[0];
	for(int i = 1;i < n;i++) {
		if(arr[i] < min)
			min = arr[i];
	}
	return min;
}

//			Them X Vao SAU Gia tri Lon Nhat Trong Mang

void themXVaoSauMax(int *arr, int &n, int GiaTri){
	printf("\n\tGia tri sau khi duoc them vao  \n");
	int max = Max(arr,n);
	for(int i = n - 1;i >= 0;i--){//Nguoc Xui Deu Duoc
		if(arr[i] == max)// T / M
		{
			n++;
			for(int j = n - 1;j > i;j--){//Duyet Cac Phan Tu Sau I
				arr[j + 1] = arr[j];
			}
			arr[i + 1] = GiaTri;//Gian Tai Vi Trí Truoc Max = GiaTri Can Chen
		}
	}
	ouputArr(arr,n);
}

//			Them X Vao TRUOC Gia Tri Nho Nhat 

void themXTruocSauMin(int *arr, int &n, int GiaTri){
	printf("\n\tGia tri sau khi duoc them vao Truoc Gia Tri Nho Nhat  \n");
	int min = Min(arr,n);
	for(int i = n - 1;i >= 0;i--){
		if(arr[i] == min)
		{
				n++;
				for(int k = n - 1;k >= i;k--){
					arr[k + 1] = arr[k];
				}
				arr[i] = GiaTri;
		}
	}
	ouputArr(arr,n);
}


void showMenu(){
	printf("\n**************************************************");
	printf("\n*                      MENU                      *");
	printf("\n**************************************************");
	printf("\n* 0 De Thoat Khoi Chuong Trinh                   *");
	printf("\n* 1 Nhap Xuat mang 1 chieu                       *");
	printf("\n* 2 Tao mang 1 chieu ngau nhien co phan tu >= 15 *");
	printf("\n* 3 Tao mang ngau nhien chua toan chan           *");
	printf("\n* 4 Tim Gia tri X trong mang(Tuyen Tinh)         *");
	printf("\n* 5 Tim Gia tri X trong mang(Nhi Phan - noDQ)    *");
	printf("\n* 6 Tim Gia tri X trong mang(Nhi Phan - DQ)      *");
	printf("\n* 7 Xap Xep Mang Tang Dan                        *");
	printf("\n* 8 Xap Xep Mang Giam Dan                        *");
	printf("\n* 9 Thuat Toan Sap xep tang dan(Quick_Soft)      *");
	printf("\n* 10 Liet Ke So nguyen to nho hon n              *");
	printf("\n* 11 Tong cac phan tu co chu so LE dau  tien     *");
	printf("\n* 12 Liet Ke Chu So lan Xuat hien Trong Mang     *");
	printf("\n* 13 Sap Xep Theo Chan Tang Dan , Le Giu Nguyen  *");
	printf("\n* 14 Tim So nho thu 2 trong mang                 *");
	printf("\n* 15 Chan len dau mang le Xuong cuoi mang        *");
	printf("\n* 16 Thuat Toan Sap xep tang dan(Selectionsort)  *");
	printf("\n* 17 Kiem tra mangTang/Giam/KhongTangKhongGiam   *");
	printf("\n* 18 Dem so phan tu xuat hien trong mang         *");
	printf("\n* 19 Dem Mang Arr[] trong mang B[]               *");
	printf("\n* 20 xuat so phan tu xuat hien nhiue nhat  Tmang *");
	printf("\n* 21 Xuat cac  phan tu xuat hien nhieu nhat Tmang*");
	printf("\n* 22 Tim MAX trong mang trong [DE QUY]           *");
	printf("\n* 23 Kiem Tra Mang Doi Xung Bang  [DE QUY]       *");
	printf("\n**************************************************");	 
}
void thucThi(){
	int n,c[10] = {0};
	Itemtype arr[MAXSIZE],b[MAXSIZE],x;
	char nameFile[50];
	int luachon;
	do{
		showMenu();
		printf("\nSu lua chon cua ban la: ");
		nhapSoNhguyenN(luachon);
		switch(luachon){
			case 1:{
				inpurArr(arr,n);
				printf("\n\tMang sau khi duoc xuat: ");
				ouputArr(arr,n);
//				readFile(arr,n, "File1C.txt");
//				ouputArr(arr,n);
//				printf("\n\tNhap File Can Ghi Vao : ");scanf("%s", &nameFile);
//				writeFile(arr,n,nameFile);
				break;
			}
			case 2:{
				printf("\n\tSinh mang ngau nhien lon hon hoac bang 15 : ");
				mangNgauNhienLonHonHoacBang15(arr,n);
				break;
			}
			case 3:{
				mangNgauNhienToanLaSoChan(arr,n);
				break;
			}
			case 4:{
				printf("Nhap gia tri X can tim : ");scanf("%d", &x);
				if(tinXTuyenTinh(arr,n,x) == -1)
					printf("Khong Tim Thay gia tri %d can Tim!!!", x);
				else
				printf("\n\tGia tri %d nam o Vi tri Thu %d ", x,tinXTuyenTinh(arr,n,x));
				break;
			}
			case 5:{
				printf("Nhap gia tri X can tim : ");scanf("%d", &x);
				if(timXNhiPhan_nonDQ(arr,n,x) == -1)
					printf("\n\tKhong tim Thay gia tri X trong mang!!!");
				else
					printf("\n\tGia tri %d nam o vi tri thu %d",x,timXNhiPhan_nonDQ(arr,n,x));
				break;
			}
			case 6:{
				printf("Nhap gia tri X can tim : ");scanf("%d", &x);
				if(timXNhiPhan_DQ(arr , 0 , n - 1 , x) == -1)
					printf("\n\tKhong Tim thay gia tri %d trong mang!!!",x);
				else
				printf("\n\tGia tri %d nam o vi tri thu %d",x,timXNhiPhan_DQ(arr, 0 , n - 1, x));
				break;
			}
			case 7:{
				mangTangDan(arr,n);
				break;
			}
			case 8:{
				mangGiamDan(arr,n);
				break;
			}
			case 9:{
				printf("\n\tMang sau khi duoc sap xep tang dan theo Kieu  quick_Soft : ");
				tang_Quick_Sort(arr , 0 , n - 1);
				ouputArr(arr,n);
				break;
			}
			case 10:{
				printf("Nhap gia tri n = ");
				nhapSoNhguyenN(n);
				lietKeSoNguyenToNhoHonN(n);
				break;
			}
			case 11:{
				printf("\n\tTong cac phan Tu co chu so le dau tien = %d ",tongChuSoLeDauTien(arr,n));
				break;
			}
			case 12:{
				demChuSoTrongArr(arr,n,c);
				for(int i = 0;i < 10;i++){
					if(c[i] != 0)
						printf("\n\t[> <]Chu so %d Xuat hien %d lan", i,c[i]);
				}
				break;
			}
			case 13:{
				printf("\n\tMang duoc Sap Xep Theo Chan Tang Dan Le Giu Nguyen : ");
				tangDanChanLeDuNguyen(arr,n);
				break;
			}
			case 14:{
				printf("\n\tGia tri nho thu 2 trong mang la %d", min2Mang(arr,n));
				break;
			}
			case 15:{
				printf("\n\tSo chan len dau So le Xuong cuoi : ");
				chanLenDauLeXuongDuoi(arr,n);
				break;
			}
			case 16:{
				sapXeptheoSelectionMIN(arr,n);
				break;
			}
			case 17:{
				if(kiemTraMangTangGiamKhongTangKhongGiam(arr,n) == 1)
					printf("\n\tMang Sap Xep Giam dan");
				else if(kiemTraMangTangGiamKhongTangKhongGiam(arr,n) == 2)
					printf("\n\tMang sap Xep tang dan");
			    else
				printf("\n\tMang Khong tang khong Giam!!!");
				break;
			}
			case 18:{
				xuatSoLanPhanTuXuatHienTrongMang(arr,n);
				break;
			}
			case 19:{
				int nb;
				inpurArr(b,nb);
				ouputArr(b,nb);
				printf("\n\tMang A Xuat hien %d Lan trong Mang B ", demMangAtrongMangB(arr,b,n,nb));
				break;
			}
			case 20:{
				xuatPhanTuXuatHienNhieuNhatTrongMang(arr,n);
				break;
			}
			case 21:{
				Itemtype b[MAXSIZE] = {0};
				xuatCacPhanTuXuatHienTrongMang(arr,n,b);
				break;
			}
			case 22:{
				printf("\n\tGia tri lon nhat trong mang theo phuong phap DE QUY la %d ", timMax_DeQuy(arr,0,n - 1));
				break;
			}
			case 23:{
				printf("%d", tinhTongMangTheoDeQuy(arr,n));
				break;
			}
			case 24:{
				if(kiemTraMangDoiXung_De_Quy(arr,0,n-1) == 1)
					printf("\n\tDOI XUNG");
				else
					printf("\n\tKHONG DOI XUNG!!!");
				break;
			}
			case 25:{
				lietKeCacPhanTuCoChuSoHangChucLonHonHangDonVi(arr,n);
				break;
			}
			case 26:{
				if(kiemTraCoPhaiLaCapSoCongHayKhong(arr,n))
					printf("\n\tMang tao thanh cap so cong");
				else
					printf("\n\tMang KHONG tao thanh cap so cong!!!");
				break;
			}
			case 27:{
				if(kiemTraCoPhaiLaCapSoNhanHayKhong(arr,n))
					printf("\n\tMang tao thanh cap so Nhan");
				else
					printf("\n\tMang KHONG tao thanh cap so Nhan!!!");
				break;
			}
			case 28:{
				if(timViTriMaxNT(arr,n) != 0)
					printf("\n\tVi tri Nguyen To Max la Vi tri thu [%d] ", timViTriMaxNT(arr,n));
				else
					printf("\n\tKhong co so nguyen to trong mang!!!!");
				break;
			}
			case 29:{
				int gt;
				printf("\n\tGia tri can them : ");scanf("%d", &gt);
				themXVaoSauMax(arr,n,gt);
				break;
			}
			case 30:{
				int gt;
				printf("\n\tGia tri can them : ");scanf("%d", &gt);
				themXTruocSauMin(arr,n,gt);
				break;
			}
			case 31:{
				printf("\n\tMax 1 De Quy = %d", max1(arr,n));
				break;
			}
		}
	}while(luachon != 0);
}










