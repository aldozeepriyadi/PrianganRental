//Pembuatan Laporan
void SortingRiwayatBulanan();
void SortingRiwayatTahunan();
void TampilRiwayatSort();

void SortingRiwayatBulanan()
{

	int cekbulan;
	int cektahun;
	FILE  *Riwayat;
	FILE  *TempRiwayat;
	SYSTEMTIME str_t;
	GetSystemTime(&str_t);
	booking Trs;
	
	gotoxy (15,26);	printf ("[1]  Januari ");
	gotoxy (15,27);	printf ("[2]  Februari ");
	gotoxy (15,28);	printf ("[3]  Maret ");
	gotoxy (15,29);	printf ("[4]  April ");
	gotoxy (15,30);	printf ("[5]  Mei ");
	gotoxy (15,31);	printf ("[6]  Juni ");
	gotoxy (15,32);	printf ("[7]  Juli ");
	gotoxy (15,33);	printf ("[8]  Agustus ");
	gotoxy (15,34);	printf ("[9]  September ");
	gotoxy (15,35);	printf ("[10] Oktober ");
	gotoxy (15,36);	printf ("[11] November ");
	gotoxy (15,37);	printf ("[12] Desember ");
		
	gotoxy (12,21);printf ("Masukan No Bulan : ");
	gotoxy (32,21);getnum (&cekbulan,2);
	gotoxy (12,22);printf ("Masukan Tahun    : ");
	gotoxy (32,22);getnum(&cektahun,4);
	
	Riwayat = fopen ("riwayat.txt","rb");
	TempRiwayat = fopen ("TempRiwayat.txt","wb");
	
	fread (&Trs,sizeof (Trs),1,Riwayat);
	while (!feof(Riwayat))
	{
		if((cekbulan == Trs.bulan) && (cektahun == Trs.tahun))
		{
			fwrite(&Trs,sizeof(Trs),1,TempRiwayat);
		}
		fread (&Trs, sizeof(Trs),1,Riwayat);
	}
	fclose (Riwayat);
	fclose (TempRiwayat);
	TampilRiwayatSort ();
	getch();
}

void SortingRiwayatTahunan()
{
	int cektahun;
	FILE  *Riwayat;
	FILE  *TempRiwayat;
	
	booking Trs;
		
	gotoxy (12,21);printf ("Masukan Tahun    : ");
	gotoxy (32,21);getnum(&cektahun,4);
	
	Riwayat = fopen ("riwayat.txt","rb");
	TempRiwayat = fopen ("TempRiwayat.txt","wb");
	
	fread (&Trs,sizeof (Trs),1,Riwayat);
	while (!feof(Riwayat))
	{
		if(cektahun == Trs.tahun)
		{
			fwrite(&Trs,sizeof(Trs),1,TempRiwayat);
		}
		fread (&Trs, sizeof(Trs),1,Riwayat);
	}
	fclose (Riwayat);
	fclose (TempRiwayat);
	TampilRiwayatSort ();
}

void TampilRiwayatSort()
{
//	Trs.KodeTrx = 0;
	int i;
	int y;
	y=19;
	char harga [25];
	FILE *Riwayat;
	FILE *TempRiwayat;
	SYSTEMTIME str_t;
	GetSystemTime(&str_t);
	
	int total=0;

	booking Trs;
	
	//Trs.KodeTrx = Trs.KodeTrx+1;
	TempRiwayat=fopen ("TempRiwayat.txt","rb");
	fread (&Trs,sizeof (Trs),1,TempRiwayat);
	while (!feof (TempRiwayat))
	{
//		Trs.tgl = str_t.wDay;
//		Trs.bulan = str_t.wMonth;
//		Trs.tahun = str_t.wYear;	

			gotoxy (49,17);	printf("Kode");y++;
			gotoxy (49,y);	printf("CAR%d",Trs.IDMobil);
			gotoxy (60,17);	printf("Tanggal");
			gotoxy (60,y);	printf("%d-%d-%d", Trs.tgl,Trs.bulan,Trs.tahun);
			gotoxy (77,17);	printf("Nama");
			gotoxy (77,y);	printf("%s",Trs.nama);
			gotoxy (95,17);printf("Nomor Plat");
			gotoxy (95,y);	printf("%s",Trs.noplat);
			gotoxy (110,17);printf("Warna");
			gotoxy (110,y);	printf("%s",Trs.warna);
			gotoxy (125,17);printf("Lama Sewa");
			gotoxy (128,y);printf("%i",Trs.lamasewa);
			gotoxy (140,17);printf("Harga");
			rupiah(Trs.harga,harga);
			gotoxy (140,y);	printf("Rp %s",harga);
		
		total = total + Trs.harga;
		
		fread (&Trs,sizeof (Trs),1,TempRiwayat);
	}
	rupiah(total, harga);
	gotoxy(135,y+3),printf("Total = Rp %s", harga);
	
	while (feof (TempRiwayat))
	{
		break;
	}
	fclose(TempRiwayat);
	getch();
	system("cls");
	MenuManager();
}
