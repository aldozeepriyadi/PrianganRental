//Pembuatan Laporan
void SortingRiwayatBulan();
void SortingRiwayatTahun();
void TampilRiwayatSorting();

void SortingRiwayatBulan()
{

	int cekbulan;
	int cektahun;
	FILE  *Riwayat;
	FILE  *TempRiwayat;
	SYSTEMTIME str_t;
	GetSystemTime(&str_t);
	booksupir Trx;
	
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
	
	Riwayat = fopen ("riwayatsupir.txt","rb");
	TempRiwayat = fopen ("TempRiwayat.txt","wb");
	
	fread (&Trx,sizeof (Trx),1,Riwayat);
	while (!feof(Riwayat))
	{
		if((cekbulan == Trx.bulan) && (cektahun == Trx.tahun))
		{
			fwrite(&Trx,sizeof(Trx),1,TempRiwayat);
		}
		fread (&Trx, sizeof(Trx),1,Riwayat);
	}
	fclose (Riwayat);
	fclose (TempRiwayat);
	TampilRiwayatSorting();
	getch();
}

void SortingRiwayatTahun()
{
	int cektahun;
	FILE  *Riwayat;
	FILE  *TempRiwayat;
	
	booksupir Trx;
		
	gotoxy (12,21);printf ("Masukan Tahun    : ");
	gotoxy (32,21);getnum(&cektahun,4);
	
	Riwayat = fopen ("riwayatsupir.txt","rb");
	TempRiwayat = fopen ("TempRiwayat.txt","wb");
	
	fread (&Trx,sizeof (Trx),1,Riwayat);
	while (!feof(Riwayat))
	{
		if(cektahun == Trx.tahun)
		{
			fwrite(&Trx,sizeof(Trx),1,TempRiwayat);
		}
		fread (&Trx, sizeof(Trx),1,Riwayat);
	}
	fclose (Riwayat);
	fclose (TempRiwayat);
	TampilRiwayatSorting();
}

void TampilRiwayatSorting()
{
//	Trx.KodeTrx = 0;
	int i;
	int y;
	y=19;
	char harga [25];
	FILE *Riwayat;
	FILE *TempRiwayat;
	SYSTEMTIME str_t;
	GetSystemTime(&str_t);
	
	int total=0;

	booksupir Trx;
	
	//Trx.KodeTrx = Trx.KodeTrx+1;
	TempRiwayat=fopen ("TempRiwayat.txt","rb");
	fread (&Trx,sizeof (Trx),1,TempRiwayat);
	while (!feof (TempRiwayat))
	{
//		Trx.tgl = str_t.wDay;
//		Trx.bulan = str_t.wMonth;
//		Trx.tahun = str_t.wYear;	

			gotoxy (40,17);	printf("Kode");y++;
			gotoxy (40,y);	printf("DRV%d",Trx.IDSupir);
			gotoxy (48,17);	printf("Tanggal");
			gotoxy (48,y);	printf("%d-%d-%d", Trx.tgl,Trx.bulan,Trx.tahun);
			gotoxy (72,17);	printf("Nama");
			gotoxy (72,y);	printf("%s",Trx.nama);
			gotoxy (95,17);printf("NIK");			
			gotoxy (95,y);	printf("%s",Trx.nik);
			gotoxy (110,17);printf("Nomor Telepon");
			gotoxy (110,y);	printf("%s",Trx.notelp);
			gotoxy (128,17);printf("Lama Sewa");
			gotoxy (131,y);printf("%i",Trx.lamasewa);
			gotoxy (148,17);printf("Harga");
			rupiah(Trx.harga,harga);
			gotoxy (148,y);	printf("Rp %s",harga);
		
		total = total + Trx.harga;
		
		fread (&Trx,sizeof (Trx),1,TempRiwayat);
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
