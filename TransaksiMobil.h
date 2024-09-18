
bool found;
	
typedef struct { int KodeTrx;
				 int IDMobil;
				 int KODE;
				 char nama[25];
				 char noplat[3];
				 char warna[25];
				 char status[15];
				 int lamasewa;
				 int harga;
				 int tgl;
				 int bulan;
				 int tahun;
				} booking;
booking Trs;
//time_t timet = time(NULL);
//struct tm tm = *localtime(&t);
//SYSTEMTIME str_t;
//GetSystemTime(&str_t);

void MenuKasir();
void LihatDaftarMobil();
void keranjangBook();
void Bayar();
void SewaMobil();
void struk();
void MenuCRUDMobil();

int KonfirmasiPenyewaan=0;
int TotalHarga=0;
int UangPembeli=0;
int Kembalian=0;
void keranjangBook();
void RiwayatTransaksi();

FILE *Baru;
FILE *ArsMobil;
FILE *Temp;
FILE *KeranjangBook, *Booking2;

void SewaMobil()
{
	
	bool found;
	//Deklrasi
	FILE *ArsMobil;
	FILE *Temp;
	FILE *KeranjangBook, *Booking2;
	
	//deklarasi mobil
	typedef struct {
				int IDMobil;
				char NomorPlat[10];
				char NamaMobil[25];
				char Warna[10];
				int StokMobil;
				int HargaSewa;
				char Status[15];
				} arsipmobil;
    arsipmobil Mobil;
	booking Trs;
	int acc;
	char hargarp[20];
	
	//Algoritma
	KeranjangBook = fopen("Keranjangbook.txt","ab+");
	fread(&Trs,sizeof(Trs),1,KeranjangBook);
	ArsMobil = fopen ("arsipmobil.dat","rb");
	Temp = fopen("temp.dat","wb");
	Baru = fopen("mobilbaru.dat", "wb");
	
	SYSTEMTIME str_t;
	GetSystemTime(&str_t);
	
	gotoxy(45,16);	printf("Penyewaan Mobil");
	gotoxy(45,18);	printf("ID Mobil : CAR"); fflush(stdin);getnum(&Trs.IDMobil,4);
	
	found = false;
	fread(&Mobil,sizeof(Mobil),1,ArsMobil);
	while((!found)&&(!feof(ArsMobil)))
	{
			if (Mobil.IDMobil == Trs.IDMobil)
			{
				found = true;
			}
			else
			{
				fwrite(&Mobil,sizeof(Mobil),1,Temp);
				fread(&Mobil,sizeof(Mobil),1,ArsMobil);
			}
	
	}
	if(found == true)
	{
		
		gotoxy(45,20);	printf("-----Data Berhasil Ditemukan-----");
		gotoxy(45,21);	printf("ID\t\t\t: CAR%i ",Mobil.IDMobil);
		gotoxy(45,22);	printf("Nama Mobil\t\t: %s",Mobil.NamaMobil);
		gotoxy(45,23);	printf("Nomor Plat\t\t: %s",Mobil.NomorPlat);
		gotoxy(45,24);	printf("Warna Mobil\t: %s",Mobil.Warna);
		gotoxy(45,25);	printf("Stok Mobil\t\t: %d",Mobil.StokMobil);
		rupiah(Mobil.HargaSewa, hargarp);
		gotoxy(45,26);	printf("Harga Sewa\t\t: Rp %s",hargarp);
		gotoxy(45,27);	printf("Status Mobil\t: %s", Mobil.Status);
		gotoxy(45,28);	printf("Lama Sewa\t\t: ");	getnum(&Trs.lamasewa,4);
		
		if ((strcmp(Mobil.Status,"Tersewa")==0))
		{
			printf("Stok Habis, Mobil Telah Tersewa");
			system ("cls");
			SewaMobil();
		}else
		{
		Trs.tgl = str_t.wDay;
		Trs.bulan = str_t.wMonth;
		Trs.tahun = str_t.wYear;
				
		Mobil.StokMobil = Mobil.StokMobil-1;
		strcpy(Mobil.Status, "Tersewa");
		fwrite(&Mobil,sizeof(Mobil), 1, Temp);
		fread(&Mobil,sizeof(Mobil), 1, ArsMobil);
		while(!feof(ArsMobil))
		{
			fwrite(&Mobil,sizeof(Mobil), 1, Temp);
			fread(&Mobil,sizeof(Mobil), 1, ArsMobil);
		}
		fclose(ArsMobil);
		fclose(Temp);
		
		Temp = fopen("temp.dat", "rb");
		ArsMobil = fopen("arsipmobil.dat", "wb");
		fread(&Mobil,sizeof(Mobil), 1, Temp);
		while(!feof(Temp))
			{
				fwrite(&Mobil,sizeof(Mobil), 1, ArsMobil);
				fread(&Mobil,sizeof(Mobil), 1, Temp);
			}
			fclose(ArsMobil);
			fclose(Temp);
		
		gotoxy(100, 18); printf("Lama Sewa (Hari)\t: %d Hari", Trs.lamasewa);
		Trs.harga = Mobil.HargaSewa*Trs.lamasewa;
		rupiah(Trs.harga, hargarp);
		gotoxy(100, 19); printf("Total\t\t: Rp %s", hargarp);
		Trs.KODE= Mobil.IDMobil;
		strcpy(Trs.noplat,Mobil.NomorPlat);
		strcpy(Trs.warna,Mobil.Warna);
		strcpy(Trs.nama,Mobil.NamaMobil);
		gotoxy(100,21);	printf ("Yakin akan pesanan (Y/N)");
		acc=getch();
		
		if (acc=='Y'||acc=='y')
		{
			Booking2 = fopen("Keranjangbook.txt", "ab");
			fwrite(&Trs,sizeof(Trs),1,Booking2);
			fclose(Booking2);
			printf("Mobil Berhasil di Booking ^_^ ");
			gotoxy(100,25);printf("Ingin Sewa Supir?(Y/N)");
			acc=getch();
			if (acc=='Y'||acc=='y')
			{
				LihatDaftarSupir();
				SewaSupir();
			}
			else if (acc =='n'|| acc =='N')
			{
				MenuKasir();
			}
		}
		else
		{
			MenuKasir();
		}
		}
		fwrite(&Mobil,sizeof(Mobil),1,Temp);
		fread(&Mobil,sizeof(Mobil),1,ArsMobil);
		while(!feof(ArsMobil))
		{
			fwrite(&Mobil,sizeof(Mobil),1,Temp);
			fread(&Mobil,sizeof(Mobil),1,ArsMobil);
		}
		fclose(ArsMobil);
		fclose(Temp);
		Temp = fopen("temp.dat","rb");
		ArsMobil = fopen("arsipmobil.dat","wb"); 			
		
		fread(&Mobil,sizeof(Mobil),1,Temp);
		while(!feof(Temp))
		{
			fwrite(&Mobil,sizeof(Mobil),1,ArsMobil);
			fread(&Mobil,sizeof(Mobil),1,Temp);
		} 
		fclose(ArsMobil);
		fclose(Temp);
		fclose(KeranjangBook);
		fclose(Baru);
		
		printf("");
		KonfirmasiPenyewaan=1;
		getch();
		}
	else
	{
		printf("Mobil Belum Tersedia");
		getche();
		MenuKasir();

		fclose(ArsMobil);
		fclose(Temp);
		fclose(KeranjangBook);
	}
}

void keranjangBook()
{
	
	//Deklarasi
	int y;
	char hargarp[20];
	system("cls");
	
	FILE *KeranjangBook;
	FILE *sewa;
	booking Trs;
	
	//Algoritma
	KeranjangBook = fopen("Keranjangbook.txt","rb");
	y=16;
	fread(&Trs,sizeof(Trs),1,KeranjangBook);
	while (!feof(KeranjangBook))
	{
		gotoxy (45,y);printf("Tanggal\t: %d-%d-%d",Trs.tgl,Trs.bulan,Trs.tahun);y++;	
		gotoxy (45,y);printf("Kode\t: CAR%d",Trs.IDMobil);y++;
		gotoxy (45,y);printf("Nama\t: %s",Trs.nama);y++;
		gotoxy (45,y);printf("Nomor Plat\t: %s",Trs.noplat);y++;
		gotoxy (45,y);printf("Warna\t: %s",Trs.warna);y++;
		gotoxy (45,y);printf("Lama Sewa\t: %i Hari",Trs.lamasewa);y++;
		rupiah(Trs.harga, hargarp);
		gotoxy (45,y);printf("Harga\t: Rp %s",hargarp);y++;
		gotoxy (45,y);printf("");y++;
		y=y+1;
		fread(&Trs,sizeof(Trs),1,KeranjangBook);
	}
    
	getch();
	fclose(KeranjangBook);
}

void Bayar()
{
	
	FILE *KeranjangBook;
	TotalHarga = 0;
	booking Mobil2;
	
	char hargarp[20];

	//Algoritma
	if(KonfirmasiPenyewaan == 0)
	{
		KeranjangBook = fopen("Keranjangbook.txt","rb");	
		fread(&Mobil2,sizeof(Mobil2),1,KeranjangBook);
		do
		{
			TotalHarga = TotalHarga + Mobil2.harga;
			fread(&Mobil2,sizeof(Mobil2),1,KeranjangBook);
		} 
		while (!feof(KeranjangBook));
		rupiah(TotalHarga, hargarp);
		gotoxy(45,30);	printf("Total Tagihan        = Rp %s",hargarp);
		gotoxy(45,32);	printf("Masukkan Jumlah Uang = Rp "); getRp(&UangPembeli,1,20,71,32);
		if(TotalHarga<=UangPembeli)
		{
			Kembalian = UangPembeli-TotalHarga;
			rupiah(Kembalian,hargarp);
			gotoxy(45,35);   printf("Kembalian 	          = Rp %s",hargarp);
			getch();
			gotoxy(45,40);   printf("Transaksi Berhasil, Terima Kasih ^_^ ");
	 
		//RiwayatTransaksi();
		}else
		{
			printf("Uang Tidak Mencukupi !");
			fclose(KeranjangBook);
			Bayar();
		}
		fclose(KeranjangBook);
		getch();
		struk();
	
		fwrite(&Mobil2,sizeof(Mobil2),1,KeranjangBook);
		KeranjangBook = fopen("Keranjangbook.txt","wb");
		fclose(KeranjangBook);
	}
	else
	{
		getch();
		gotoxy(45,25);	printf("Keranjang Barang Kosong!");
		getch();
		MenuKasir();
	}
	BayarSupir();
}

void struk()
{
	FILE *KeranjangBook;
	FILE *sewa;
	FILE *Riwayat;
	
	char hargarp[20];
	
	booking Trs, MobilKosong;
	
	//Algoritma
	KeranjangBook = fopen("Keranjangbook.txt","rb");
	Riwayat = fopen("riwayat.txt","ab");
	fread(&Trs,sizeof(Trs),1,KeranjangBook);
	while (!feof(KeranjangBook))
	{
		fwrite(&Trs,sizeof(Trs),1,Riwayat);
		fread(&Trs,sizeof(Trs),1,KeranjangBook);
	}
	fclose(Riwayat);
	fclose(KeranjangBook);
	
	KeranjangBook = fopen("Keranjangbook.txt","rb");
	gotoxy(85,19);	printf("==================STRUK PEMBAYARAN==================");
	fread(&Trs,sizeof(Trs),1,KeranjangBook);						
	while (!feof(KeranjangBook))
	{	
		gotoxy(85,21);	printf("Tanggal\t: %d-%d-%d",Trs.tgl,Trs.bulan,Trs.tahun);
		gotoxy(85,22);	printf("Kode\t: CAR%d",Trs.KODE);
		gotoxy(85,23);	printf("Nama\t: %s",Trs.nama);
		gotoxy(85,24);	printf("Nomor Plat\t: %s",Trs.noplat);
		gotoxy(85,25);	printf("Warna\t: %s",Trs.warna);
		gotoxy(85,26);	printf("Lama Sewa\t: %i Hari",Trs.lamasewa);
		rupiah(Trs.harga, hargarp);
		gotoxy(85,27);	printf("Harga\t: Rp %s",hargarp);		
		fread(&Trs,sizeof(Trs),1,KeranjangBook);
		getch();
	}
	rupiah(TotalHarga, hargarp);
	gotoxy(85,29);	printf("Total Tagihan\t= Rp %s",hargarp);
	rupiah(UangPembeli, hargarp);
	gotoxy(85,30);  printf("Jumlah Uang\t= Rp %s",hargarp);
	rupiah(Kembalian, hargarp);
	gotoxy(85,31);	printf("Kembalian\t\t= Rp %s",hargarp);
	getch();	
	fclose(KeranjangBook);
	KeranjangBook = fopen("Keranjangbook.txt", "wb");
	fclose(KeranjangBook);
	KonfirmasiPenyewaan = 0;
	MenuKasir();
}
