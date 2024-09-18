bool found;
	
typedef struct { int KodeTrx;
				 int IDSupir;
				 int KODE;
				 char nama[25];
				 int nik[16];
				 int notelp[15];
				 char status[15];
				 int lamasewa;
				 int harga;
				 int tgl;
				 int bulan;
				 int tahun;
				} booksupir;
booksupir Trx;
//time_t timet = time(NULL);
//struct tm tm = *localtime(&t);
//SYSTEMTIME str_t;
//GetSystemTime(&str_t);

void MenuKasir();
void keranjang();
void LihatDaftarSupir();
void SewaSupir();
void BayarSupir();
void struksupir();
void MenuCRUDSupir();

int KonfirmasiSewa=0;

FILE *Baru;
FILE *ArsSupir;
FILE *Temp;
FILE *KeranjangSupir, *Booking2;

void SewaSupir()
{
	
	bool found;
	//Deklrasi
	FILE *ArsSupir;
	FILE *Temp;
	FILE *KeranjangSupir, *Booking2;
	
	//deklarasi supir
	typedef struct {
				int IDSupir;
				int NIK[16];
				char NamaSupir[25];
				char JenisKelamin[10];
				int Telepon[15];
				int Harga;
				int StokSupir;
				char Status[15];
				} arsipsupir;
    arsipsupir Supir;
	booksupir Trx;
	int acc;
	char hargarp[20];
	
	//Algoritma
	KeranjangSupir = fopen("keranjangsupir.txt","ab+");
	fread(&Trx,sizeof(Trx),1,KeranjangSupir);
	ArsSupir = fopen ("arsipsupir.dat","rb");
	Temp = fopen("temp.dat","wb");
	Baru = fopen("supirbaru.dat", "wb");
		
	SYSTEMTIME str_t;
	GetSystemTime(&str_t);
	
	gotoxy(45,16);	printf("Penyewaan Supir");
	gotoxy(45,18);	printf("ID Supir : DRV"); fflush(stdin);getnum(&Trx.IDSupir,4);
	
	found = false;
	fread(&Supir,sizeof(Supir),1,ArsSupir);
	while((!found)&&(!feof(ArsSupir)))
	{
			if (Supir.IDSupir == Trx.IDSupir)
			{
				found = true;
			}
			else
			{
				fwrite(&Supir,sizeof(Supir),1,Temp);
				fread(&Supir,sizeof(Supir),1,ArsSupir);
			}
	
	}
	if(found == true)
	{
		
		gotoxy(45,20);	printf("-----Data Berhasil Ditemukan-----");
		gotoxy(45,21);	printf("ID\t\t\t: DRV%i ",Supir.IDSupir);
		gotoxy(45,23);	printf("NIK\t\t: %s",Supir.NIK);
		gotoxy(45,22);	printf("Nama Supir\t\t: %s",Supir.NamaSupir);
		gotoxy(45,24);	printf("Jenis Kelamin\t: %s",Supir.JenisKelamin);
		gotoxy(45,25);	printf("Nomor Telepon\t: %s",Supir.Telepon);
		rupiah(Supir.Harga, hargarp);
		gotoxy(45,26);	printf("Harga Sewa\t\t: Rp %s",hargarp);
		gotoxy(45,27);	printf("Status Supir\t: %s", Supir.Status);
		gotoxy(45,28);	printf("Lama Sewa\t\t: ");	getnum(&Trx.lamasewa,4);
		
		if ((strcmp(Supir.Status,"Tersewa")==0))
		{
			printf("Supir Telah di Sewa :)");
			SewaSupir();
		}else
		{
		Trx.tgl = str_t.wDay;
		Trx.bulan = str_t.wMonth;
		Trx.tahun = str_t.wYear;
		
		Supir.StokSupir = Supir.StokSupir-1;
		strcpy(Supir.Status, "Tersewa");
		fwrite(&Supir,sizeof(Supir), 1, Temp);
		fread(&Supir,sizeof(Supir), 1, ArsSupir);
		while(!feof(ArsSupir))
		{
			fwrite(&Supir,sizeof(Supir), 1, Temp);
			fread(&Supir,sizeof(Supir), 1, ArsSupir);
		}
		fclose(ArsSupir);	 
		fclose(Temp);
		
		Temp = fopen("temp.dat", "rb");
		ArsSupir = fopen("arsipsupir.dat", "wb");
		fread(&Supir,sizeof(Supir), 1, Temp);
		while(!feof(Temp))
			{
				fwrite(&Supir,sizeof(Supir), 1, ArsSupir);
				fread(&Supir,sizeof(Supir), 1, Temp);
			}
			fclose(ArsSupir);
			fclose(Temp);
		
		gotoxy(100, 18); printf("Lama Sewa (Hari)\t: %d", Trx.lamasewa);
		Trx.harga = Supir.Harga*Trx.lamasewa;
		rupiah(Trx.harga, hargarp);
		gotoxy(100, 19); printf("Total\t\t: Rp %s", hargarp);
		Trx.KODE= Supir.IDSupir;
		strcpy(Trx.notelp,Supir.Telepon);
		strcpy(Trx.nik,Supir.NIK);
		strcpy(Trx.nama,Supir.NamaSupir);
		gotoxy(100,21);	printf ("Yakin akan pesanan (Y/N)");
		acc=getch();
		
		if (acc=='Y'||acc=='y')
		{
			Booking2 = fopen("keranjangsupir.txt", "ab");
			fwrite(&Trx,sizeof(Trx),1,Booking2);
			fclose(Booking2);
			printf("Supir Berhasil di Booking ^_^ ");
			gotoxy(100,25);printf("Ada lagi?(Y/N)");
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
		fwrite(&Supir,sizeof(Supir),1,Temp);
		fread(&Supir,sizeof(Supir),1,ArsSupir);
		while(!feof(ArsSupir))
		{
			fwrite(&Supir,sizeof(Supir),1,Temp);
			fread(&Supir,sizeof(Supir),1,ArsSupir);
		}
		fclose(ArsSupir);
		fclose(Temp);
		Temp = fopen("temp.dat","rb");
		ArsSupir = fopen("arsipsupir.dat","wb"); 			
		
		fread(&Supir,sizeof(Supir),1,Temp);
		while(!feof(Temp))
		{
			fwrite(&Supir,sizeof(Supir),1,ArsSupir);
			fread(&Supir,sizeof(Supir),1,Temp);
		} 
		fclose(ArsSupir);
		fclose(Temp);
		fclose(KeranjangSupir);
		fclose(Baru);
		
		printf("");
		KonfirmasiSewa=1;
		getch();
		}
	else
	{
		printf("Supir Belum Tersedia");
		getche();
		MenuKasir();

		fclose(ArsSupir);
		fclose(Temp);
		fclose(KeranjangSupir);
	}
}

void keranjang()
{
	
	//Deklarasi
	int y;
	char hargarp[20];
	system("cls");
	
	FILE *KeranjangSupir;
	FILE *sewa;
	booksupir Trx;
	
	//Algoritma
	KeranjangSupir = fopen("keranjangsupir.txt","rb");
	y=16;
	fread(&Trx,sizeof(Trx),1,KeranjangSupir);
	while (!feof(KeranjangSupir))
	{
		gotoxy (20,y);printf("Tanggal\t: %d-%d-%d",Trx.tgl,Trx.bulan,Trx.tahun);y++;	
		gotoxy (20,y);printf("Kode\t: DRV%i",Trx.IDSupir);y++;
		gotoxy (20,y);printf("Nama Supir\t: %s",Trx.nama);y++;
		gotoxy (20,y);printf("NIK\t: %s",Trx.nik);y++;
		gotoxy (20,y);printf("Nomor Telepon\t: %s",Trx.notelp);y++;
		gotoxy (20,y);printf("Lama Sewa\t: %i Hari",Trx.lamasewa);y++;
		rupiah(Trx.harga, hargarp);
		gotoxy (20,y);printf("Harga\t: Rp %s",hargarp);y++;
		gotoxy (20,y);printf("");y++;
		y=y+1;
		fread(&Trx,sizeof(Trx),1,KeranjangSupir);
	}
	getch();
	fclose(KeranjangSupir);
}

void BayarSupir()
{
	
	FILE *KeranjangSupir;
	TotalHarga = 0;
	booksupir Supir2;
	
	char hargarp[20];

	//Algoritma
	if(KonfirmasiPenyewaan == 0)
	{
		KeranjangSupir = fopen("Keranjangsupir.txt","rb");	
		fread(&Supir2,sizeof(Supir2),1,KeranjangSupir);
		do
		{
			TotalHarga = TotalHarga + Supir2.harga;
			fread(&Supir2,sizeof(Supir2),1,KeranjangSupir);
		}
		while (!feof(KeranjangSupir));
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
			fclose(KeranjangSupir);
			Bayar();
		}
		fclose(KeranjangSupir);
		struksupir();
	
		fwrite(&Supir2,sizeof(Supir2),1,KeranjangSupir);
		KeranjangSupir = fopen("Keranjangsupir.txt","wb");
		fclose(KeranjangSupir);	
	}
	else
	{
		getch();
		gotoxy(45,25);	printf("Keranjang Barang Kosong!");
		getch();
		MenuKasir();
	}
}

void struksupir()
{
	FILE *KeranjangSupir;
	FILE *sewa;
	FILE *Riwayat;
	
	char hargarp[20];
	
	booksupir Trx, SupirKosong;
	
	//Algoritma
	KeranjangSupir = fopen("Keranjangsupir.txt","rb");
	Riwayat = fopen("riwayatsupir.txt","ab");
	fread(&Trx,sizeof(Trx),1,KeranjangSupir);
	while (!feof(KeranjangSupir))
	{
		fwrite(&Trx,sizeof(Trx),1,Riwayat);
		fread(&Trx,sizeof(Trx),1,KeranjangSupir);
	}
	fclose(Riwayat);
	fclose(KeranjangSupir);
	
	KeranjangSupir = fopen("Keranjangsupir.txt","rb");
	gotoxy(85,19);	printf("==================STRUK PEMBAYARAN==================");
	fread(&Trx,sizeof(Trx),1,KeranjangSupir);						
	while (!feof(KeranjangSupir))
	{
		gotoxy (85,21);printf("Tanggal\t: %d-%d-%d",Trx.tgl,Trx.bulan,Trx.tahun);
		gotoxy (85,22);printf("Kode\t: DRV%i",Trx.IDSupir);
		gotoxy (85,23);printf("Nama Supir\t: %s",Trx.nama);
		gotoxy (85,24);printf("NIK\t: %s",Trx.nik);
		gotoxy (85,25);printf("Nomor Telepon\t: %s",Trx.notelp);
		gotoxy (85,26);printf("Lama Sewa\t: %i Hari",Trx.lamasewa);
		rupiah(Trx.harga, hargarp);
		gotoxy (85,27);printf("Harga\t: Rp %s",hargarp);
		gotoxy (85,28);printf("");
		fread(&Trx,sizeof(Trx),1,KeranjangSupir);
		getch();
	}
	rupiah(TotalHarga, hargarp);
	gotoxy(85,29);	printf("Total Tagihan\t= Rp %s",hargarp);
	rupiah(UangPembeli, hargarp);
	gotoxy(85,30);  printf("Jumlah Uang\t= Rp %s",hargarp);
	rupiah(Kembalian, hargarp);
	gotoxy(85,31);	printf("Kembalian\t\t= Rp %s",hargarp);
	getch();	
	fclose(KeranjangSupir);
	KeranjangSupir = fopen("Keranjangsupir.txt", "wb");
	fclose(KeranjangSupir);
	KonfirmasiPenyewaan = 0;
	MenuKasir();
}
