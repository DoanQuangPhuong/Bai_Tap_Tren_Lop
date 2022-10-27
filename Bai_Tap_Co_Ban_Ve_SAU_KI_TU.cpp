#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define MAXSIZE 1000
void demSoLanXuatHienCuaTungKiTuThuong(char str[]);
void demSoLanXuatHienCuaTungKiTuHoa(char str[]);
void demSoLanXuatHienCuaTungKiTuLanLon(char str[]);
void demSoLanXuatHienCuaTungKiTuKhongTheoTuanTu(char str[]);
void tanXuatXuatHienKiTuTrongXauNhieuNhatTrongChuoi(char str[]);
void lietKeTuGiongNhauTrong2Chuoi(char str[], char s[]);
void lietKiTuXuatHienOXau1KhongXHienOXau2(char str[], char s[]);
void lietKiTuXuatHienOXau1HoacXHienOXau2(char str[], char s[]);
int kiemTraKiTuCoDayDuKiTuPangram(char str[]);
int kiemTraKiTuCoDayDuKiTuKhongPhanBietHoaThuongPangram(char str[]);
int kiemTraXauDoiXung(char str[]);
void tachTuTrongXau(char str[]);
int DemTuTrongXau(char str[]); 
int kiemTraTuToanChuInHoa(char c[]);
void xuatKiTuInHoaTrongXau(char str[]);
void sapXep(char arr[][MAXSIZE], int n);
void inraCacTuTrongXauTheoThuTuTuDien(char str[],char arr[][MAXSIZE]);
int cmp(const void *a, const void *b);
void inraCacTuTrongXauTheoThuTuTuDien2(char str[], char arr[][MAXSIZE]);
void sapXepTheoChieuDai(char arr[][MAXSIZE], int n);
void sapXepXauTangDanTheoChieuDaiTuTrongChuoi(char str[],char arr[][MAXSIZE]);
int cmp2(const void *a, const void *b);
void sapXepXauTangDanTheoChieuDaiTuTrongChuoi2(char str[], char arr[][MAXSIZE]);
void sapXepChuCaiTangDanTheoThuTuTuDien(char str[]);
int cmp3(const void *a, const void *b);
void sapXepChuCaiTangDanTheoThuTuTuDien2(char str[]);
void chuaHoaTungTu(char c[]);
void chuanHoaChuoi(char str[], char arr[][MAXSIZE]);
void taoEmailTuHoTenNguoiDung(char str[],char arr[][MAXSIZE]);
void taoEmailTuHoTenNguoiDungKieu2(char str[],char arr[][MAXSIZE]);
void demSoLanXuatHienTuTrongXau(char str[], char arr[][MAXSIZE]);
void TuXuatHienNhieuNhatTrongXau(char str[], char arr[][MAXSIZE]);
void xoaTuTrongXau(char str[], char arr[][MAXSIZE], char c[]);
void xuatCacTuXuatHienOXau1KhongXuatHienOXau2(char str[], char c[], char arr[][MAXSIZE],char a[][MAXSIZE]);
void xoaTuTrong2XauKhongPhanBietHoaThuong(char str[],char x[]);
void timTuLapDauTienTrongXau(char str[], char arr[][MAXSIZE]);
///=================================
void checkXauACoPhaiLaConCuaXauB(char str[], char c[]);
void  kiemTraHoanViDoiXung(char str[]);
void lietKeKiTuKhongLap(char str[]);
int tinhTongCacSoTrongXau(char str[]);
int tinhTongCacSoTrongXau2(char str[]);
void solve(char x[]);
void tinhTong2DaThucBieuDienBangXauKiTu(char str[], char c[]);
int taoHello(char str[]);
int kiemTra(char c);
int chuyenSoLaMa(char str[]);
int sauConLienTiepLienKeKhacNhau(char str[]); 
int sauConLienTiepLienKeGiongNhau(char str[]); 
void reverse(int a[], int n);
void add(char a[], char b[]);
void sub(char a[], char b[]);
int tongChuSoTrongXau(char str[]);
int kiemTraSauThuanNghichToanChan(char str[]);
int KiemTraSoDep(char str[]);
int KiemTraSoDep2(char str[]);
int kiemTraXauChiaHetCho6(char str[]);
int kiemTraXauChiaHetCho4(char str[]);
int kiemTraXauChiaHetCho25(char str[]);
int kiemTraXauChiaHetCho8(char str[]);
int kiemTraXauChiaHetCho235(char str[]);
long long tiemSoDuSoNguyenLon(char str[], long long m);
void suLi();
void showMenu();




int main(){
	suLi();
	
	return 0;
}

void showMenu(){
	printf("\n************************************************************");
	printf("\n*                               MENU                        ");
	printf("\n************************************************************");
	printf("\n* 0 De ket thuc chuong trinh                                ");
	printf("\n* 1 Nhap / Xuat Chuoi Ki tu                                 ");
	printf("\n* 2 Dem tu trong chuoi in  THUONG                           ");
	printf("\n* 3 Dem tu trong chuoi in  HOA                              ");
	printf("\n* 4 Dem tu trong chuoi lan lon THUONG, HOA ,KTU DAC  BIET   ");
	printf("\n* 5 Dem Ki tu Khong theo tuan tu                            ");
	printf("\n* 6 Ki tu xuat hien NHIEU NHAT trong XAU                    ");
	printf("\n* 7 Liet ke tu giong nhat trong 2 chuoi                     ");
	printf("\n* 8 Liet Ke tu Xuat hien trong XAU 1 KHONG XHien TRONG XAU 2");
	printf("\n* 9 Liet Ke tu Xuat hien trong XAU 1 HOAC X.Hien TRONG XAU 2");
	printf("\n* 10 Kiem Tra XAU Co chua DAY DU KI tu tu a -> z hay khong  ");
	printf("\n* 11 Kiem Tra XAU DAY DU KI tu tu a -> z khong PB hoa thuong");
	printf("\n* 12 Kiem tra XAU DOI XUNG                                  ");
	printf("\n* 13 Tach cac Tu Trong Xau                                  ");
	printf("\n* 14 Dem Cac Tu Trong Xau                                   ");
	printf("\n* 15 Xuat ra Tu Toan Chu In Hoa Hay Khong                   ");
	printf("\n* 16 Xap Xep Tu Trong XAU Theo Thu Tu Tu Diem               ");
	printf("\n************************************************************");
	printf("\n************************************************************");
}

void suLi(){
	int luachon,m;
	char arr[MAXSIZE][MAXSIZE];
	char a[MAXSIZE][MAXSIZE];
	char str[5000];
	char c[100];
	do{
		showMenu();
		do{
			printf("\n\tSu lua chon cua ban la : ");scanf("%d", &luachon);
			if(luachon < 0)
				printf("\n\tVui long nhap lai lua chon cua ban!!!!");
		}while(luachon < 0);
		switch(luachon){
			case 1:{
				printf("\n\tChuoi : ");
				fflush(stdin);
				gets(str);
				printf("\n\tXuat chuoi : %s", str);
				break;
			}
			case 2:{
				printf("\n\t\tDem tan xuat ki tu THUONG");
				demSoLanXuatHienCuaTungKiTuThuong(str);
				break;
			}
			case 3:{
				printf("\n\t\tDem tan xuat ki tu Hoa");
				demSoLanXuatHienCuaTungKiTuHoa(str);
				break;
			}
			case 4:{
				printf("\n\t\tDem Tan Xuat [Tat ca] Cac Ki Tu Co Trong Chuoi");
				demSoLanXuatHienCuaTungKiTuLanLon(str);
				break;
			}
			case 5:{
				printf("\n\t\tDem tan xuat Cua Chuoi [khong] Theo tuan tu a -> z");
				demSoLanXuatHienCuaTungKiTuKhongTheoTuanTu(str);
				break;
			}
			case 6:{
				printf("\n\t\tKi Tu Xuat Hien Nhieu nhat trong chuoi la ");
				tanXuatXuatHienKiTuTrongXauNhieuNhatTrongChuoi(str);
				break;
			}
			case 7:{
				char s[1000];
				printf("\n\tChuoi 2 : ");
				fflush(stdin);
				gets(s);
				printf("\n\t\tliet Ke ca ki tu trung nhau trong 2 chuoi : ");
				lietKeTuGiongNhauTrong2Chuoi(str,s);
				
				break;
			}
			case 8:{
				char s[1000];
				printf("\n\tChuoi 2 : ");
				fflush(stdin);
				gets(s);
				printf("\n\tLiet ke Ki Tu Xuat Hien O chuoi 1 Ma Khong Xuat Hien o chuoi 2 la : ");
				lietKiTuXuatHienOXau1KhongXHienOXau2(str,s);
				break;
			}
			case 9:{
				char s[1000];
				printf("\n\tChuoi 2 : ");
				fflush(stdin);
				gets(s);
				printf("\n\t\tLiet Ke cac ki tu Xuat Hien o Xau 1 hoac 2 hoac ca hai[Moi ki tu liet ke 1 lan] la ");
				lietKiTuXuatHienOXau1HoacXHienOXau2(str,s);
				break;
			}
			case 10:{
				if(kiemTraKiTuCoDayDuKiTuPangram(str) == 1) 
					printf("\n\tChuoi Chua DAY DU ki tu tu a -> z[pangram]  YES");
				else
				printf("\n\tChuoi KHONG chua Day Du ki tu tu a -> z [pangram]   NO!!!!");
				break;
			}
			case 11:{
				if(kiemTraKiTuCoDayDuKiTuKhongPhanBietHoaThuongPangram(str) == 1) 
					printf("\n\tChuoi Chua DAY DU ki tu tu a -> z[pangram]  YES");
				else
				printf("\n\tChuoi KHONG chua Day Du ki tu tu a -> z [pangram]   NO!!!!");
				break;
			}
			case 12:{
				if(kiemTraXauDoiXung(str) == 1)
					printf("\n\tXAU DOI XUNG");
				else
					printf("\n\tXAU KHONG DOI XUNG!!!");
				break;
			}
			case 13:{
				printf("\n\t\tXau sau khi duoc tach Tu ra  ");
				tachTuTrongXau(str);
				break;
			}
			case 14:{
				printf("\n\t\tXAU CO %d tu ", DemTuTrongXau(str));
				break;
			}
			case 15:{
				printf("\n\t\tTu Toan Chu IN Hoa Trong Xau la : ");
				xuatKiTuInHoaTrongXau(str);
				break;
			}
			case 16:{
				printf("\n\tSap Xep cac Tu Theo Thu Tu Tu Dien : ");
     			inraCacTuTrongXauTheoThuTuTuDien(str,arr);
//				inraCacTuTrongXauTheoThuTuTuDien2(str,arr);//Dung Ham [qsort] Trong Thu Vien
				
				break;
			}
			case 17:{
				printf("\n\tSap Xep Tang Dan Theo Kich Thuoc : ");
				sapXepXauTangDanTheoChieuDaiTuTrongChuoi(str,arr);
//				sapXepXauTangDanTheoChieuDaiTuTrongChuoi(str,arr);//Dung Ham [qsort] Trong Thu Vien
				break;
			}
			case 18:{
				sapXepChuCaiTangDanTheoThuTuTuDien(str);
//				sapXepChuCaiTangDanTheoThuTuTuDien2(str);//Dung Ham [qsort] Trong Thu Vien
				break;
			}
			case 19:{
				printf("\n\tChuoi Sau Khi Duoc Chuan Hoa : ");
				chuanHoaChuoi(str,arr);
				break;
			}
			case 20:{
//				printf("\n\tEmail Sau Khi Duoc Tao 1 :  ");//Kieu 1
//			    taoEmailTuHoTenNguoiDung(str,arr);
				printf("\n\tEmail Sau Khi Duoc Tao Kieu 2 :  ");//Kieu 2
				taoEmailTuHoTenNguoiDungKieu2(str,arr);
				break;
			}
			case 21:{
				printf("\n\t\t So Lan Tu Xuat Hien Trong Xau ");
				demSoLanXuatHienTuTrongXau(str,arr);
				break;
			}
			case 22:{
				printf("\n\t\tTu Xuat Hien Nhieu Nhat Trong Xau ");
				TuXuatHienNhieuNhatTrongXau(str,arr);
				break;
			}
			case 23:{
				printf("\n\tTu Can delete : ");scanf("%s", &c);
				printf("\n\t\tXau Sau khi xoa [%s] ra Khoi Xau Ban Dau : ", c);
				xoaTuTrongXau(str,arr,c);
				break;
			}
			case 24:{
				printf("\n\tXau 2 : ");
				fflush(stdin);
				gets(c);
				printf("\n\t\tTu Chi Xuat Hien O Xau 1 Khong Xuat Hien O Xau 2 : ");
				xuatCacTuXuatHienOXau1KhongXuatHienOXau2(str,c,arr,a);
				break;
			}
			case 25:{
				xoaTuTrong2XauKhongPhanBietHoaThuong(str,c);
				break;
			}
			case 26:{
				timTuLapDauTienTrongXau(str,arr);
				break;
			}
			case 27:{
				printf("\n\tTu : ");scanf("%s", &c);
				checkXauACoPhaiLaConCuaXauB(str,c);
				break;
			}
			case 28:{
				kiemTraHoanViDoiXung(str);
				break;
			}
			case 29:{
				printf("\n\t\tKi Tu Khong Lap Trong Mang : ");
				lietKeKiTuKhongLap(str);//CHUOI IN HOA
				break;
			}
			case 30:{
				printf("\n\tTong Cac Chu So Xuat Hien Trong Xau = %d ", tinhTongCacSoTrongXau2(str));
				break;
			}
			case 31:{
				char s[1000];
				printf("\n\tChuoi 2 : ");
				fflush(stdin);
				gets(s);
				tinhTong2DaThucBieuDienBangXauKiTu(str,s);
				break;
			}
			case 32:{
				if(taoHello(str) == 1)
					printf("\n\tCo the Tao!!");
				else
					printf("\n\tKhong the tao!!!");
				break;
			}
			case 33:{
				printf("\n\tChuoi [%s] Ki Tu Sau Khi Chuyen Doi Tu Chu Cai La Ma Ve Dang Thap Phan la %d", str,chuyenSoLaMa(str));
				break;
			}
			case 34:{
				printf("\n\tSau con [%s] Lien tiep chua cac ki tu lien ke khac nhau la %d ", str,sauConLienTiepLienKeKhacNhau(str));
				printf("\n\tSau con [%s] Lien tiep chua cac ki tu lien ke Giong nhau la %d ", str,sauConLienTiepLienKeGiongNhau(str));
				break;
			}
			case 35:{
				char a[1000],b[1000];
				printf("\n\tChuoi 1 : ");scanf("%s", &a);
				printf("\n\tChuoi 2 : ");scanf("%s", &b);
				int n = strlen(a),n1 = strlen(b);
				if(n >= n1){
				printf("Tong Chuoi = ");
				add(a,b);
				}
				else
				{
					printf("Tong Chuoi = ");
					add(b,a);
				}
				break;
			}
			case 36:{
				char a[1000],b[1000];
				printf("\n\tChuoi 1 : ");scanf("%s", &a);
				printf("\n\tChuoi 2 : ");scanf("%s", &b);
				int n = strlen(a),n1 = strlen(b);
				if(n >= n1){
				printf("Hieu Chuoi = ");
				sub(a,b);
				}
				else
				{
					printf("Hieu Chuoi = ");
					sub(b,a);
				}
				break;
			}
			case 37:{
				printf("\n\tTong Chu So trong Xau la %d", tongChuSoTrongXau(str));
				break;
			}
			case 38:{
				if(kiemTraSauThuanNghichToanChan(str) == 1)
					printf("\n\tSo thuan nghich Toan Chan");
				else
					printf("\n\tSo Khong thuan nghich Toan Chan!!!");
				break;
			}
			case 39:{
				if(KiemTraSoDep(str) == 1)	
					printf("\n\tChu So Dep");
				else
					printf("\n\tChu So Khong Dep!!!");
				if(KiemTraSoDep2(str) == 1)	
					printf("\n\tChu So Dep Kha Nghich");
				else
					printf("\n\tChu So Khong Dep!!!");
				break;
			}
			case 40:{
				if(kiemTraXauChiaHetCho6(str) == 1)
					printf("\n\tXau Chuoi So Chia Het Cho 6");
				else
					printf("\n\tXau Chuoi So Khong Chia Het Cho 6!!!");
				if(kiemTraXauChiaHetCho4(str) == 1)
					printf("\n\tXau Chuoi So Chia Het Cho 4");
				else
					printf("\n\tXau Chuoi So Khong Chia Het Cho 4!!!");
				break;
			}
			case 41:{
				if(kiemTraXauChiaHetCho25(str) == 1)
					printf("\n\tXau Chuoi So Chia Het Cho 25");
				else
					printf("\n\tXau Chuoi So Khong Chia Het Cho 25!!!");
				if(kiemTraXauChiaHetCho8(str) == 1)
					printf("\n\tXau Chuoi So Chia Het Cho 8");
				else
					printf("\n\tXau Chuoi So Khong Chia Het Cho 8!!!");
				if(kiemTraXauChiaHetCho235(str) == 1)
					printf("\n\tXau Chuoi So Chia Het Cho 235");
				else
					printf("\n\tXau Chuoi So Khong Chia Het Cho 235!!!");
				break;
				}
				case 42:{
					do{
						printf("Nhap So Chia = ");scanf("%d", &m);
					}while(m <= 0);
					printf("\n\tSo Du Chia Het Cho So Nguyen Lon %lld la %lld ",m,tiemSoDuSoNguyenLon(str,m));
					break;
				}
			}
	}while(luachon != 0);
}

//========================================================================================================

void demSoLanXuatHienCuaTungKiTuThuong(char str[]){//Dem theo tuan tu tu a -> z

	int count[26] = {0};//Dem ki tu tuan tu tu a -> z VD: |0|1|2|3|4|...
														// a b c d e ...
	int n = strlen(str);
	for(int i = 0;i < n;i++){
		count[str[i] - 'a']++;            /* Lay ki tu - di ki tu 'a' de Lay Vi tri cua ki tu do 
	                           	         VD 'b' = 98 , 'a' = 97 ->count['b' - 'a'] = count[1]++;
								         */
	}
	for(int i = 0;i < 26;i++){
		if(count[i] != 0){
			printf("\n%c   xuat hien  %d lan ", (i + 'a'), count[i]);
		}
	}
}

//========================================================================================================

void demSoLanXuatHienCuaTungKiTuHoa(char str[]){//Dem theo tuan tu tu a -> z
	int count[26] = {0};
	int n = strlen(str);
	for(int i = 0;i < n;i++){
		count[str[i] - 'A']++;
	}
	for(int i = 0;i < n;i++){
		if(count[str[i] - 'A'] != 0){
			printf("\n%c   xuat hien  %d lan ", str[i], count[str[i] - 'A']);
			count[str[i] - 'A'] = 0;//kHONG DEM KI TU TRUNG
		}
	}
}

//========================================================================================================

void demSoLanXuatHienCuaTungKiTuLanLon(char str[]){//Dem theo tuan tu tu a -> z
	int count[256] = {0};//Khoi tao bien dem chua 256 ki tu trong bang ma ascill
	int n = strlen(str);
	for(int i = 0;i < n;i++){
		count[(int)str[i]]++;
	}
	for(int i = 0;i < n;i++){
		if(count[(int)str[i]] != 0){//Duyet Dem khac khong thi in ra chu cai va so lan dem tuong ung coi chu cai do
			printf("\n%c   xuat hien  %d lan ", str[i] , count[str[i]]);
			count[(int)str[i]] = 0;//Cap Nhat Lai De Khong Bi Xuat Ki Tu Bi Lap
		}
	}
}

//========================================================================================================

void demSoLanXuatHienCuaTungKiTuKhongTheoTuanTu(char str[]){//Khong theo thu tu
	int count[26] = {0};
	int n = strlen(str);
	for(int i = 0;i < n;i++){
		count[str[i] - 'a']++;
	}
	for(int i = 0;i < 26;i++){
		if(count[str[i] - 'a'] != 0){//bacab
			printf("\n%c   Xuat Hien %d lan ", str[i], count[str[i] - 'a']);
			count[str[i] - 'a'] = 0;//Khong lap lai Ki tu do nua
			//Tu Dem Roi Thi Cap Nhat Lai De Khong Bi Lap
		}
	}
}

//========================================================================================================

void tanXuatXuatHienKiTuTrongXauNhieuNhatTrongChuoi(char str[]){//Ki tu Xuat hien nhieu nhat trong Xau
	int count[256] = {0}, demKT = 0,id;
	int n = strlen(str);
	for(int i = 0;i < n;i++){
		count[(int)str[i]]++;
	}
	for(int i = 0;i < n;i++){
		if(count[(int)str[i]] != 0)
		{
			if(count[(int)str[i]] > demKT){
				demKT = count[(int)str[i]];
				id = i;
			//	kt = char(i);
			}
		}
	}
	printf("\n\tKi tu Xuat hien nhieu nhat trong Chuoi la : %c %d lan", str[id],demKT);
}

//========================================================================================================

void lietKeTuGiongNhauTrong2Chuoi(char str[], char s[]){
	int count[256] = {0};
	int n = strlen(str), n1 = strlen(s);
	for(int i = 0;i < n;i++){
		count[str[i]] = 1;//Gan tat cac ki tu trong chuoi bang 1 
	}
	for(int j = 0;j < n1;j++){
		if(count[s[j]] != 0) // Kiem tra tu da xuat hien trong chuoi 1 chua
			count[s[j]] = 2;//Gan Ki Tu Trung == 2
	}
	for(int k = 0;k < 256;k++){
		if(count[k] == 2)
			printf("%c ", k);
	}
}

//========================================================================================================

void lietKiTuXuatHienOXau1KhongXHienOXau2(char str[], char s[]){
	int count[256] = {0};
	int n = strlen(str), n1 = strlen(s);
	for(int i = 0;i < n;i++){
		count[str[i]] = 1;//Gan tat cac ki tu trong chuoi bang 1 
	}
	for(int j = 0;j < n1;j++){
		if(count[s[j]] != 0)//Trung 
			count[s[j]] = 0;// Ki tu trung thi gan bang 0
	}
	for(int k = 0;k < 256;k++){
		if(count[k] != 0)// kien tra so Ki tu den khac o thi in ra man hinh 
			printf("%c ", k);
	}
}

//========================================================================================================

void lietKiTuXuatHienOXau1HoacXHienOXau2(char str[], char s[]){
	int count[256] = {0};
	int n = strlen(str), n1 = strlen(s);
	for(int i = 0;i < n;i++){
		count[str[i]] = 1;//Gan tat cac ki tu trong chuoi bang 1 
	}
	for(int j = 0;j < n1;j++){
			count[s[j]] = 1;// Gan tat cac Ki tu trung thi gan bang 1 
	}
	for(int k = 0;k < 256;k++){
		if(count[k] != 0)// In Ra Khi count[k] == 1 tuk la count[k] != 0
			printf("%c ", k);
	}
}

//=========================================================================================

int kiemTraKiTuCoDayDuKiTuPangram(char str[]){//Kiem tra pangram[Toan ky tu tu a -> z]
	int count[26] = {0};
	int n = strlen(str);
	for(int i = 0;i < n;i++){
		count[str[i] - 'a'] = 1;
	}
	for(int i = 0;i < 26;i++){
		if(count[i] == 0)
			return 0;
	}
	return 1;
}

//=========================================================================================

int kiemTraKiTuCoDayDuKiTuKhongPhanBietHoaThuongPangram(char str[]){//Kiem tra pangram[Toan ky tu tu a -> z]
	strlwr(str);//Chuyen Chuoi Ve Thuong Het
	int count[26] = {0};
	int n = strlen(str);
	for(int i = 0;i < n;i++){
		count[str[i] - 'a'] = 1;
	}
	for(int i = 0;i < 26;i++){
		if(count[i] == 0)
			return 0;
	}
	return 1;
}

//=========================================================================================

int kiemTraXauDoiXung(char str[]){
	int n = strlen(str);
	for(int i = 0;i < n / 2;i++){
		if(str[i] != str[n - 1 - i])
			return 0;
	}
	return 1;
}

//=========================================================================================
//												CACH SU DUNG HAM strtok

void tachTuTrongXau(char str[]){
	char *token = strtok(str," "); // strtok(XAU, delim)
	while(token != NULL){
		printf("\n%s ",token);
		token = strtok(NULL," ");
	}	
}

//=========================================================================================

int DemTuTrongXau(char str[]){
	int count = 0;
	char *token = strtok(str," "); // strtok(XAU, delim)
	while(token != NULL){
		count++;
		token = strtok(NULL," ");
	}	
	return count;
}

//=========================================================================================

int kiemTraTuToanChuInHoa(char c[]){
	int n = strlen(c);
	for(int i = 0;i < n;i++){
		if(!isupper(c[i]))// hoac if(islower(c[i]))
			return 0;
	}
	return 1;
}

//=========================================================================================

void xuatKiTuInHoaTrongXau(char str[]){
	char *token = strtok(str," "); // strtok(XAU, delim)
	while(token != NULL){
		if(kiemTraTuToanChuInHoa(token) == 1)
			printf("\n%s ", token);
		token = strtok(NULL," ");
	}	
}

//=========================================================================================

void sapXep(char arr[][MAXSIZE], int n){
	char temp[100];
	for(int i = 0;i < n - 1;i++){
		for(int j = i + 1;j < n;j++){
			if(strcmp(arr[i],arr[j]) > 0){
				strcpy(temp,arr[i]);
				strcpy(arr[i],arr[j]);
				strcpy(arr[j],temp);
			}
		}
	}
}

//Sap Xep Theo Thu Tu Tu Dien 

void inraCacTuTrongXauTheoThuTuTuDien(char str[], char arr[][MAXSIZE]){
	int n = 0;// Dong 
	char *token = strtok(str," "); // strtok(XAU, delim)
	while(token != NULL){
		strcpy(arr[n],token);
		++n;
		token = strtok(NULL," ");
	}	
	sapXep(arr,n);
	for(int i = 0; i < n;i++){
		printf("%s ", arr[i]);
	}
}

/*
return -1 : Neu Muon A dung Dang Truoc B
return 1 : Neu Muon A dung Sau B
*/

int cmp(const void *a, const void *b){
	char *x = (char*)a;
	char *y = (char*)b;
	if(strcmp(x,y) < 0)
		return -1;
	return 1;
}

//                              C2: Dung qickSort trong Thu Vien

void inraCacTuTrongXauTheoThuTuTuDien2(char str[], char arr[][MAXSIZE]){
	int n = 0;// Dong 
	char *token = strtok(str," "); // strtok(XAU, delim)
	while(token != NULL){
		strcpy(arr[n],token);
		++n;
		token = strtok(NULL," ");
	}	
	qsort(arr,n,sizeof(arr[0]),cmp);
	for(int i = 0; i < n;i++){
		printf("%s ", arr[i]);
	}
}

//=========================================================================================
//Sap Xep Chuoi Theo Kich Thuoc Tung Tu Neu Kich Thuoc Tu Trong Chuoi == Nhau Thi Sap Xep Theo Ma Ascill

void sapXepTheoChieuDai(char arr[][MAXSIZE], int n){
	char temp[100];
	for(int i = 0;i < n - 1;i++){
		int k = strlen(arr[i]); 
		for(int j = i + 1;j < n;j++){
			if(k >= strlen(arr[j])){
				if(k == strlen(arr[j])){
					if(strcmp(arr[i],arr[j]) > 0){
						strcpy(temp,arr[i]);
						strcpy(arr[i],arr[j]);
						strcpy(arr[j],temp);
					}
				}
				else
				{
					strcpy(temp,arr[i]);
					strcpy(arr[i],arr[j]);
					strcpy(arr[j],temp);
				}
			}
		}
	}
}

//=====================================================================================

void sapXepXauTangDanTheoChieuDaiTuTrongChuoi(char str[],char arr[][MAXSIZE]){
	int n = 0;// Dong 
	char *token = strtok(str," "); // strtok(XAU, delim)
	while(token != NULL){
		strcpy(arr[n],token);
		++n;
		token = strtok(NULL," ");
	}	
	sapXepTheoChieuDai(arr,n);
	for(int i = 0;i < n;i++){
		printf("%s ", arr[i]);
	}
}

//                                      C2 : Su Dung Ham qsort

int cmp2(const void *a, const void *b){
	char *x = (char*)a;
	char *y = (char*)b;
	if(strlen(x) != strlen(y)){
		if(strlen(x) > strlen(y))
			return 1;//Dung Sau
		return -1;//Dung Truoc
	}
	else
	{
		if(strcmp(x,y) > 0)
			return 1;//Dung Sau
		return -1;//Dung Truoc
	}
}

//                              C2: Dung qickSort trong Thu Vien

void sapXepXauTangDanTheoChieuDaiTuTrongChuoi2(char str[], char arr[][MAXSIZE]){
	int n = 0;// Dong 
	char *token = strtok(str," "); // strtok(XAU, delim)
	while(token != NULL){
		strcpy(arr[n],token);
		++n;
		token = strtok(NULL," ");
	}	
	qsort(arr,n,sizeof(arr[0]),cmp2);
	for(int i = 0; i < n;i++){
		printf("%s ", arr[i]);
	}
}

//=========================================================================================

void sapXepChuCaiTangDanTheoThuTuTuDien(char str[]){
	char temp;
	int n = strlen(str);
	for(int i = 0;i < n - 1;i++){
		for(int j = i + 1;j < n;j++){
			if(str[i] > str[j]){
					temp = str[i];
					str[i] = str[j];
					str[j] = temp;
			}
		}
	}
	printf("\n\t\tChuoi Sau Khi Duoc Sap Xep : %s", str);
}

int cmp3(const void *a, const void *b){
	char *x = (char*)a;
	char *y = (char*)b;
	if(*x > *y)
		return 1;
	return -1;
}

void sapXepChuCaiTangDanTheoThuTuTuDien2(char str[]){
	qsort(str,strlen(str),sizeof(char),cmp3);
	printf("\n\t\tChuoi Sau Khi Duoc Sap Xep : %s", str);
}

//=========================================================================================
//islower,isupper kiem tra chu thuong,hoa
//tolower,toupper Chuyen ki tu thanh thuong hoa

void chuaHoaTungTu(char c[]){
	int n = strlen(c);
	c[0] = toupper(c[0]);//Chuyen Ki Tu Dau Thanh Chu Cai In Hoa Bang Ham [toupper]
	for(int i = 1;i < n;i++){
		c[i] = tolower(c[i]);//Chuyen Ki Tu Dau Thanh Chu Cai In Hoa Bang Ham [tolower]
	}
}

void chuanHoaChuoi(char str[], char arr[][MAXSIZE]){
	char *token = strtok(str," ");
	int n = 0;
	while(token != NULL){
		strcpy(arr[n],token);//Coppy Tung Token Vao Mang 2 Chieu, Moi Token La Mot Mang 1 Chieu rieng Biet
		++n;
		token = strtok(NULL," ");
	}
	for(int i = 0;i < n;i++){
		chuaHoaTungTu(arr[i]);//Chua Hoa Tu
		printf("%s",arr[i]);
		if(i != n - 1)//Neu Ma i == n - 1 la Khong In Ra Khoang Trang Cuoi Cung,Nguoc Lai
			printf(" ");
	}
}

//=========================================================================================

void taoEmailTuHoTenNguoiDung(char str[],char arr[][MAXSIZE]){//Vd: Nguyen Van Manh -> manhnv@gmail.com
	strlwr(str);
	int n = 0;
	char *token = strtok(str," ");
	while(token != NULL){
		strcpy(arr[n],token);
		++n;
		token = strtok(NULL," ");
	}
	printf("%s",arr[n - 1]);
	for(int i = 0;i < n - 1;i++){
		printf("%c", arr[i][0]);
	}
	printf("@gmail.com");
}

//=========================================================================================

void taoEmailTuHoTenNguoiDungKieu2(char str[],char arr[][MAXSIZE]){//Vd: Nguyen Van Manh -> nvmanh@gmail.com
	strlwr(str);
	int n = 0;
	char *token = strtok(str," ");
	while(token != NULL){
		strcpy(arr[n],token);
		++n;
		token = strtok(NULL," ");
	}
	for(int i = 0;i < n - 1;i++){
		printf("%c", arr[i][0]);
	}
	printf("%s",arr[n - 1]);
	printf("@gmail.com");
}

//=========================================================================================

void demSoLanXuatHienTuTrongXau(char str[], char arr[][MAXSIZE]){
	strlwr(str);
	int n = 0;
	char *token = strtok(str," ");
	while(token != NULL){
		strcpy(arr[n],token);
		++n;
		token = strtok(NULL," ");
	}
	int b[n] = {0};
	for(int i = 0;i < n;i++){
		if(b[i] == 0){
			int count = 1;
			for(int j = i + 1;j < n;j++){
				if(strcmp(arr[i],arr[j]) == 0){
				count++;
				b[j] = 1;//Danh Dau Vi tri Trung
				}
			}
			printf("\nTu [%s] Xuat Hien %d Lan", arr[i],count);
		}
	}
}	

//=========================================================================================

void TuXuatHienNhieuNhatTrongXau(char str[], char arr[][MAXSIZE]){
	strlwr(str);
	int n = 0;
	char *token = strtok(str," ");
	while(token != NULL){
		strcpy(arr[n],token);
		++n;
		token = strtok(NULL," ");
	}
	int b[n] = {0},max = 0,index = 0;
	for(int i = 0;i < n;i++){
		if(b[i] == 0){
			int count = 1;
			for(int j = i + 1;j < n;j++){
				if(strcmp(arr[i],arr[j]) == 0){
				count++;
				b[j] = 1;//Danh Dau Vi tri Trung
				}
			}
			if(count > max)
			{
				max = count;
				index = i;
			}
			else if(count == max)//Neu Nhu So Dem So tu Bang Nhau Thi So sanh Theo Ma Ascil
			{
				if(strcmp(arr[index],arr[i]) > 0)
					index = i;
			}
		}
	}
	printf("\n\tTu [%s] Xuat Hien Nhieu Nhat Trong Xau [%d] lan ", arr[index], max)	;
}

//=======================================================================================

void xoaTuTrongXau(char str[], char arr[][MAXSIZE], char c[]){
	int n = 0;
	char *token = strtok(str," ");
	while(token != NULL){
		strcpy(arr[n],token);
		++n;
		token = strtok(NULL," ");
	}
	for(int i = 0;i < n;i++){
		if(strcmp(arr[i],c) != 0){
			printf("%s",arr[i]);
			if(i != n - 1)
			{
				printf(" ");
			}
		}
	}
}

//=======================================================================================

int soSanhTu(char a[],char b[]){
	int n = strlen(a);
	int n1 = strlen(b);
	if(n != n1)
		return 0;
	for(int i = 0;i < n;i++){
		if(tolower(a[i]) != tolower(b[i]))//Chuyen Tung Chu Cai Ve Dang In Thuong
			return 0;//Khong Giong Nhau
	}
	return 1;//Giong Nhau
}

//====================================================================================

void xoaTuTrong2XauKhongPhanBietHoaThuong(char str[],char x[]){
	for(int i = 1;i <= 2;i++){
		fflush(stdin);
		gets(str);
		fflush(stdin);
		printf("Test case %d Xoa tu : ", i);scanf("%s", &x);
		printf("\n\t\tTest %d : ", i);
		char *token = strtok(str," ");//sai
		while(token != NULL){
			if(soSanhTu(token,x) == 0)
				printf("%s ", token);
			token = strtok(NULL," ");
		}
	}
}

//==============================================================================

void xuatCacTuXuatHienOXau1KhongXuatHienOXau2(char str[], char c[], char arr[][MAXSIZE],char a[][MAXSIZE]){
	char temp[100];
	int n = 0;
	char *token = strtok(str," ");//sai
	while(token != NULL){
		strcpy(arr[n],token);
		++n;
		token = strtok(NULL," ");
	}
	int n1 = 0;
	token = strtok(c," ");
	while(token != NULL){
		strcpy(a[n1],token);
		++n1;
		token = strtok(NULL," ");
	}
	for(int i = 0;i < n - 1;i++){
		for(int j = i + 1;j < n;j++){
			if(strcmp(arr[i],arr[j]) > 0){//Sap Xep Chuoi 1 theo thu tu Tu Dien
				strcpy(temp,arr[i]);
				strcpy(arr[i],arr[j]);
				strcpy(arr[j],temp);
		}
	}
}
	for(int i = 0;i < n;i++){
		while(strcmp(arr[i],arr[i + 1]) == 0)
			++i;
		int flag = 1;
		for(int j = 0;j < n1;j++){
			if(strcmp(arr[i],a[j]) == 0){
				flag == 0;
				break;
			}
		}
		if(flag == 1)
			printf("%s ", arr[i]);
	}
}

//=========================================================================================

void timTuLapDauTienTrongXau(char str[], char arr[][MAXSIZE])
{
	int n = 0;
	char *token = strtok(str," ");
	while(token != NULL){
		strcpy(arr[n],token);
		++n;
		token = strtok(NULL," ");
	}
	int flag = 0;//Check Xem Co Tu nao lap hay khong
	for(int i = 0;i < n;i++){
		int ok = 0;//Check Xem co phai tu Duoc Lap Hay Khong
		for(int j = 0;j < i;j++){//Duyet Tat Ca Cac Tu Truoc No
			if(strcmp(arr[i],arr[j]) == 0)
			{
				ok = 1;
				break;//Dung Thi Ket Thuc Vong Lap
			}
		}
		if(ok == 1)
		{
			printf("Tu trung Dau Tien : %s", arr[i]);
			flag = 1;//Danh Dau Tu Lap Dau Tien
			break;
		}
	}
	if(flag == 0)
	{
		printf("\n\tKhong Co Tu Trung!!!");
	}
}


//===============================Su Dung Ham [strstr] trong Thu Vien======================
// 										Tim Xau Con

void checkXauACoPhaiLaConCuaXauB(char str[], char c[]){
	if(strstr(str,c) != NULL)
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}
}

void  kiemTraHoanViDoiXung(char str[]){//Kiem Tra Xem Co The Hoan Vi ki Tu Truoc De Tao Thanh Chuoi Doi Xung Hay Khong?
	int count[256] = {0};
	int n = strlen(str);
	for(int i = 0;i < n;i++)
	{
		count[str[i]]++;
	}
	int flag = 0;
	for(int j = 0;j < 256;j++){//Neu Nhu Count[i] Co 1 Chu Cai [Le] Hoac 0 Co Chu Cai Le Nao
		if(count[j] % 2 != 0)  //Con Lai [Chan] Thi [YES],Nguoc Lai [NO]
			flag++;
	}
	if(flag <= 1){//NEU Co Dung 1 Chu Cai Le Hoac 0 Co Thi Tra Ve [YES], Nguoc Lai [NO]
		printf("\n\t\tYES");
	}
	else
	{
		printf("\n\t\tN0");
	}
}

void lietKeKiTuKhongLap(char str[]){// NHAP KI TU DEU IN HOA
	int n = strlen(str),flag = 0;
	int count[26] = {0};
	for(int i = 0;i < n;i++){
		count[str[i] - 'A']++;
	}
	for(int i = 0;i < n;i++){
		if(count[i] == 1){
			printf("%c", i + 'A');
		}
	}
}

int tinhTongCacSoTrongXau(char str[]){
	int tong = 0,So = 0,n = strlen(str);
	for(int i = 0;i < n;i++){
		if(str[i] >='0' && str[i] <= '9')
		{
			So =  So * 10 + str[i] - '0';//Chuyen Ve Ki Tu So - di Ki tu[0]
		}
		else//Khi Gap Chu Cai Thi [Tong + So] Tra Ve So Bang O De Tiep Tuc Tinh 
		{
			tong += So;
			So = 0;
		}
	}
	if(str[n - 1] >='0' && str[n - 1] <= '9')//Vi Gap Chu Cai Thi Tong Moi Cong Nen Chu So Cuoi La So Nen Khong Cong Vao Duoc
		{
			tong += So;
		}
	return tong;
}

//                                            Cach 2

int tinhTongCacSoTrongXau2(char str[]){
	int tong = 0,n = strlen(str);
	for(int i = 0;i < n;i++){
		int so = 0;
		while(isdigit(str[i])){
			so = so * 10 + str[i] - '0';//Gap Ki Tu So Thi Tiep Tuc Lap
			i++;//Tang i Tiep Tuc Kt
		}
		tong += so;//Lap Den Khi Gap Ki Tu  Thi Thuc Hien Tong += So;
	}
	return tong;
}

int bieuThuc[10001];//So mu khong qua 10000
//==============================================================================
void solve(char x[]){//Xu Li
	int n = strlen(x);
	for(int i = 0;i < n;i++){
		if(isdigit(x[i]))
		{
			int sum = 0;
		while(isdigit(x[i]))
		{
			sum = sum * 10 + x[i] - '0';
			++i;
		}
		i += 3;//Nhay Toi Vi Tri Mu [Bo Qua Ki Tu[*x^]
		int mu = 0;
		while(isdigit(x[i]))
		{
			mu = mu * 10 + x[i] - '0';
			++i;
		}
		bieuThuc[mu] += sum;//Cong Don Bieu Thuc Co So [Mu] Trung
		}
	}
}

void tinhTong2DaThucBieuDienBangXauKiTu(char str[], char c[]){//2*x^5 + 3*x^2 + 4*x^7 +...
	memset(bieuThuc,0,sizeof(bieuThuc));
	int count = 0;
	solve(str);
	solve(c);
	for(int i = 10000;i >= 0;i--){
		if(bieuThuc[i] != 0)
			++count;
	}
	printf("\n\tTest  : " );
	for(int i = 10000;i >= 0;i--){
		if(bieuThuc[i] != 0)
		{
			printf("%d*x^%d",bieuThuc[i],i);
			--count;
			if(count != 0)
				printf(" + ");
		}
	}
}

int taoHello(char str[]){//Tao Tu Hello Bang Cach Xoa Ki Tu Trong Xau VD: helllllllo -> true   lllllheoll -> Fasle, theo thu tu
	char xinChao[5] = {'h','e','l','l','o'};
//	char xinChao[5];
//	strcpy(xinChao,"hello");
	int count = 0,n = strlen(str);
	for(int i = 0;i < n;i++){
		if(str[i] == xinChao[count]){
			count++;
		}
	}
	return (count != 5 ? 0 : 1)	;
}


/*
Chuyen Doi So La Ma Sang He So Thap Phan VD:III = 3 VD:MMMCMXCIX= 3999
I = 1 ; V = 5; X = 10; L = 50; C = 100; D = 500; M = 1000
** Truong hop khac
IV = 4; IX = 9; XL = 40; XC = 90 ; CD = 400; CM = 900
  ->   Neu So dung sau > so Dung Truoc : So sau - So Truong
*/


int kiemTra(char c){
	char s[] ="IVXLCDM";
	for(int i = 0;i < 7;i++){
		if(s[i] == c)
			return i;
	}
	return -1;
}


int chuyenSoLaMa(char str[]){//VD : MMMCMXCIX = 3999
	int value[7] ={ 1 , 5 , 10 , 50 , 100 , 500 , 1000},n = strlen(str);
	int  res = value[kiemTra(str[n - 1])];//Gan Gia tri Tu CUOI cung Cua Chuoi
	for(int i = n - 1;i > 0;i--){//	Duyet Tu Cuoi Len
		int pos1 = kiemTra(str[i]);
		int pos2 = kiemTra(str[i - 1]);
		if(value[pos1] <= value[pos2])//Neu nhu Gia Tri Tu Sau <= Tu Truoc Thi
		{
			res += value[pos2];     //Cong Gia tri Truoc no Vao Bien res
		}
		else
		{
			res -= value[pos2];	     //Nguoc lai -> Tru Gia tri Truoc no Vao Bien res
		}
	}
	return res;
}

//xau con lien tiep chua cac ki tu ke nhau khac nhau  [clip 25]

int soSanh2So(int a, int b){
	return a > b ? a : b;
}
int sauConLienTiepLienKeKhacNhau(char str[]){
	int n = strlen(str),res = 1,count = 1;
	for(int i = 0;i < n - 1;i++){
		if(str[i] != str[i + 1])
		{
			count++;
		}
		else
		    count = 1;//reste lai
		res = soSanh2So(res,count);//Dem cong xuong cap nhat lai lien
			
	}
	return res;
}

//xau con lien tiep chua cac ki tu ke nhau Giong nhau  [clip 25]

int sauConLienTiepLienKeGiongNhau(char str[]){
	int n = strlen(str),res = 1,count = 1;
	for(int i = 0;i < n - 1;i++){
		if(str[i] == str[i + 1])
		{
			count++;
		}
		else
		    count = 1;//reste lai
		res = soSanh2So(res,count);//Dem cong xuong cap nhat lai lien
			
	}
	return res;
}


/*
Tinh Tong Hai Chuoi So nguyen lon duoi 1000 Ki Tu
*/

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}
void reverse(int a[], int n){//Dao Nguoc Mang
//	int left = 0, right = n - 1;
//	while(left < right){
//		int temp = a[left];
//		a[left] = a[right];
//		a[right] = temp;
//		left++;right--;
//	}
	for(int i = 0; i < n / 2 ; i++){
		swap(a[i],a[n - 1- i]);
	}
}


void add(char a[], char b[]){
	int len1 = strlen(a),len2 = strlen(b),n = 0;
	int x[len1],y[len1],z[len1 + 1];
	for(int i = 0;i < len1;i++)
		x[i] = a[i] - '0';//Chuyen Ki tu Ve dang So
		
	for(int i = 0;i < len2;i++)
		y[i] = b[i] -'0';//Chuyen Ki tu Ve dang So
		
	reverse(x,len1);//Dao mang
	reverse(y,len2);//Dao mang
	for(int i = len2;i < len1;i++){
		y[i] = 0;
	}
	int nho = 0;
	for(int i = 0;i < len1;i++)
	{
		int temp = x[i] + y[i] + nho;
		z[n++] = temp % 10; //VD : 15 thì temp = 5 , Nêu 7 thi temp = 7
		nho = temp/10; // VD : 15 thi nho = 1, 7 thì nho = 0
	}
	if(nho != 0)
		z[n++] = nho;
	for(int i = n - 1;i >=0;i--)
	{
		printf("%d", z[i]);
	}
}


/*
Hieu Hai Chuoi Cho Lon Nho Hon 100 Ki Tu So
*/


void sub(char a[], char b[]){
	int len1 = strlen(a),len2 = strlen(b),n = 0;
	int x[len1],y[len1],z[len1 + 1];
	for(int i = 0;i < len1;i++)
		x[i] = a[i] - '0';//Chuyen Ki tu Ve dang So
	for(int i = 0;i < len2;i++){
		y[i] = b[i] -'0';//Chuyen Ki tu Ve dang So
	}
	reverse(x,len1);//Dao mang
	reverse(y,len2);//Dao mang
	for(int i = len2;i < len1;i++){
		y[i] = 0;
	}
	int nho = 0;
	for(int i = 0;i < len1;i++)
	{
		int temp = x[i] - y[i] - nho;
		if(temp < 0) //am
		{
			z[n++] = 10 + temp;
			nho = 1;//Tang nho len 1 
		}
		else
		{
			z[n++] = temp;
			nho = 0;
		}
	}
	int ok = 0;
	for(int i = n - 1;i >= 0;i--){
		if(ok == 0 && z[i] != 0){
			ok = 1;
		}
		if(ok != 0)
			printf("%d",z[i]);
	}
	if(ok == 0)
		printf("0");
}

//Tong Cac Chu So Nguyen Lon

int tongChuSoTrongXau(char str[]){
	int n = strlen(str),sum = 0;
	for(int i = 0;i < n;i++){
		if(isdigit(str[i]))
			sum += str[i] - '0';
	}
	return sum;
}

//Kiem Tra Xau La So Thuan Nghich[Doi Xung] Chua Toan So Chan

int kiemTraSauThuanNghichToanChan(char str[]){
	int n = strlen(str);
	for(int i = 0;i <= n / 2;i++){
		if(str[i] != str[n - i - 1] || (str[i] - '0') % 2 != 0 || (str[n - i - 1] - '0') % 2 != 0)
			return 0;
	}
	return 1;
}

/*
Mot So Nguyen Duoc Goi La Chu So Dep Neu No Chua Cac [Chu So Nguyen To]
Va Tong Chi So Nguyen To Cua No Tan Cung  Bang 0
*/

int KiemTraSoDep(char str[]){
	int n = strlen(str),sum = 0;
	for(int i = 0;i < n;i++){
		int temp = (str[i] - '0');
		if(temp != 2 && temp != 3 && temp != 5 && temp != 7)
			return 0;
		sum += temp;
	}
	return sum % 10 != 0 ? 0 : 1;
}

/*
Mot So Nguyen Duoc Goi La Chu So Dep Neu No Chua Cac [Chu So Nguyen To]
Va La Mot So Thuan Nghich
*/

int KiemTraSoDep2(char str[]){
	int n = strlen(str);
	for(int i = 0;i <= n / 2;i++){
		int temp1 = (str[i] - '0');
		int temp2 = (str[n - i - 1] - '0');
		if(str[i] != str[n - i - 1] && temp1 != 2 && temp1 != 3 && temp1 != 5 && temp1 != 7 && temp2 != 2 && temp2 != 3 && temp2 != 5 && temp2 != 7)
			return 0;
	}
	return 1;
}

/*
Kiem Tra Xau So Nguyen Lon Co Chia Het Cho 6 hay khong?
De chia het cho 6 khi So Tan Cung la so chan && Tong Cac Chu So chia Het Cho 3
*/

int kiemTraXauChiaHetCho6(char str[]){
	int n = strlen(str),sum;
	if((str[n - 1] - '0') % 2 != 0)
		return 0;
	for(int i = 0;i < n;i++) {
		sum += str[i] - '0';
	}
	return sum % 3 != 0 ? 0 : 1;
}

/*
Kiem Tra Xau So Nguyen Lon Co Chia Het Cho 6 hay khong?
De chia het cho 4 khi 2 Chu So Cuoi Cung Chia Het Co 4
*/

int kiemTraXauChiaHetCho4(char str[]){
	int n = strlen(str);
	if(n == 1){
		if((str[0] - '0')% 4 == 0)
			return 1;
		return 0;
	}
	int temp = (str[n - 2] - '0') * 10 + str[n - 1] - '0';
	return temp % 4 != 0 ? 0 : 1;
}

/*
Kiem Tra Xau So Nguyen Lon Co Chia Het Cho 25 hay khong?
De chia het cho 25 khi 2 Chu So Cuoi Cung Chia Het Co 25 hoac 2 Chu So Cuoi Cung la 0
*/

int kiemTraXauChiaHetCho25(char str[]){
	int n = strlen(str);
	if(n == 1)
		return 0;
	int temp = (str[n - 2] - '0') * 10 + str[n - 1] - '0';
	if(temp % 25 != 0)
		return 0;
	return 1;
}

/*
Kiem Tra Xau So Nguyen Lon Co Chia Het Cho 8 hay khong?
De chia het cho 8 khi 3 Chu So Cuoi Cung Chia Het Co 8
*/

int kiemTraXauChiaHetCho8(char str[]){
	int n = strlen(str);
	if(n == 1){
		if(str[0] -'0' % 8 != 0)
			return 0;
		return 1;
	}
	else if(n == 2){
		if(((str[0] - '0') * 10 + str[1] - '0') % 8 != 0)
			return 0;
		return 1;
	}
	int temp = (str[n - 3] - '0') * 100 + (str[n - 2] - '0') * 10 + str[n - 1] - '0';
	if(temp % 25 != 0)
		return 0;
	return 1;
}

/*
Kiem Tra Xau So Nguyen Lon Co Chia Het Cho 2,3,5 hay khong?
De chia het cho 2,5 khi Tan Cung Chuoi So la 0
chia het cho 3 khi tong chuoi so chia het cho 3
*/

int kiemTraXauChiaHetCho235(char str[]){
	int n = strlen(str),sum = 0;
	if(str[n - 1] != '0')
		return 0;
	for(int i = 0;i < n;i++){
		sum += str[i] - '0';
	}
	if(sum % 3 == 0)
		return 1;
	return 0;
}

long long tiemSoDuSoNguyenLon(char str[], long long m){
	int n = strlen(str);
	long long sum = 0;
	for(int i = 0;i < n;i++){
		sum = (sum * 10 + str[i] - '0') % m;
	}
	return sum;
}













