//Menu CRUD Mobil

FILE *ArsSupir;		    /* nama file */
FILE *Baru;				/* nama file */

// Deklarasi
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
typedef arsipsupir FileSupir; FileSupir EditSupir;

typedef struct {
				int IDBaru;
				int StokBaru;
				int StatusBaru;
				int HargaBaru;
				}SupirBaru;
SupirBaru supirbaru;

void MenuCRUDSupir();
void LihatDaftarSupir();
void UpdateDaftarSupir();
void HapusDaftarSupir() ;

void MenuCRUDSupir()
{
	//Deklarasi
	int Menu;
	system("cls");
	
	//Algoritma

	printf("\n");
	printf("\t\t\t\t    ========Kelola Data Supir========\n\n"    );
	printf("\t\t\t\t    [1] Tambah Data Supir\n"                  );
	printf("\t\t\t\t    [2] Lihat Data Supir\n"                   );
	printf("\t\t\t\t    [3] Update Data Supir\n"                  );
	printf("\t\t\t\t    [4] Hapus Data Supir\n"                   );
	printf("\t\t\t\t    [5] Kembali\n"                            );
	printf("\t\t\t\t    [6] Keluar Program\n"                     );
	printf("\t\t\t                                               ");
	printf("\n\t\t\t    Pilih Menu yang ingin Anda Akses : "      );
	scanf("%d", &Menu,1);
	switch(Menu)
	{
		case 1 : TambahDaftarSupir();
		break;
		case 2 : LihatDaftarSupir();
		         MenuCRUDSupir();
		break;
		case 3 : UpdateDaftarSupir();
		         MenuCRUDSupir();
		break;
		case 4 : HapusDaftarSupir();
		break;
		case 5 : MenuAdmin();
		break;
		case 6 :
				 exit(0);
		default: printf("Pilihan Tidak Tersedia, Mohon Pilih Kembali!");
		MenuCRUDSupir();
		break;
	}
	while(Menu !=6);
}

void TambahDaftarSupir()
{
	//Deklarasi
	int id;

	//Algoritma 

	ArsSupir = fopen("arsipsupir.dat", "r+");
	fread(&Supir,sizeof(Supir),1,ArsSupir);
	while(!feof(ArsSupir))
		{
			fread(&Supir,sizeof(Supir),1,ArsSupir);
			id = Supir.IDSupir;
		}
	fclose(ArsSupir);
	Supir.IDSupir = id+1;									
	printf("-----Tambah Daftar Supir-----\n");
	printf("ID Supir        = ORG%d " , Supir.IDSupir);
	printf ("\nNIK     = "); fflush(stdin); 
	getteksnum (Supir.NIK, 16);
	printf("\nNama Supir      = "); fflush(stdin);
	getteks (Supir.NamaSupir, 25);
	printf ("\nJenis Kelamin    = "); fflush(stdin); 
	getteks (Supir.JenisKelamin, 10);
	printf ("\nNomor Telepon      = ");
	getteksnum (&Supir.Telepon, 15);
	printf ("\nHarga Sewa Supir     = Rp ");
	getRp(&Supir.Harga,1,20,26,17);
	printf ("\nStok Supir      = "); 
	getnum(&Supir.StokSupir, 4);
	printf("\nStatus Supir      = "); 
	getteks (Supir.Status, 15);
	
	ArsSupir = fopen("arsipsupir.dat", "ab");
	fwrite(&Supir, sizeof(Supir),1,ArsSupir);
	fclose(ArsSupir);
	
	printf("\nSupir Berhasil Ditambahkan"," ATTENTION ");
	getche();
	system("cls");
	MenuCRUDSupir();
}

void LihatDaftarSupir()
{
	//Deklarasi
	int y;
	char harga[20];
	system("cls");
	
	//Algoritma
	ArsSupir = fopen("arsipsupir.dat", "rb");
    printf("-----Lihat Daftar Supir-----");
	printf("\n=====================================================================================================================");
	printf("\nID Supir");
	printf("\nNIK");
	printf("\nNama Supir");
	printf("\nJenis Kelamin");
	printf("\nNomor Telepon");
	printf("\nStok Supir");
	printf("\nHarga Sewa Supir");
	printf("\n=====================================================================================================================");
	y = 24; 
	fread(&Supir, sizeof(Supir),1,ArsSupir);
	while (!feof(ArsSupir)) 
	{ 
	printf("\n\nORG%d ",Supir.IDSupir); fflush(stdin);
	printf("\n%s ", Supir.NIK); fflush(stdin);
	printf("\n%s ", Supir.NamaSupir); fflush(stdin);
	printf("\n%s ", Supir.JenisKelamin); fflush(stdin);
	printf("\n%s ", Supir.Telepon); 
		rupiah(Supir.Harga, harga);
	printf("\nRp %s", harga); fflush(stdin);
	printf("\n%d ", Supir.StokSupir); 
	printf("\n%s", Supir.Status);
		y=y+1;
	fread(&Supir, sizeof(Supir),1,ArsSupir);
	}
	fclose(ArsSupir);
	getch();
	system("cls");
}

void UpdateDaftarSupir()
{
	FILE *Baru;
	
	//Deklarasi
	bool found;
	int a;
	char harga[20];
	
	//Algoritma
	ArsMobil = fopen("arsipsupir.dat", "rb");
	Baru = fopen("supirbaru.dat", "wb");
	printf("-----Update Data Supir-----");
	printf("\nMasukkan ID Supir yang ingin diupdate = ORG"); 
	getnum(&supirbaru.IDBaru,4);
	found = false;
	while (!found && !feof(ArsSupir)) 
	{
		fread (&Supir, sizeof(Supir) , 1 , ArsSupir);
		if(Supir.IDSupir == supirbaru.IDBaru) 
		{
			found = true;
		}
		else
		{
			fwrite (&Supir, sizeof (Supir),1,Baru);
		}
	}
	if(found == true)
	{
		printf("\nID Supir     = ORG%d \n", Supir.IDSupir);
		printf("NIK            = %s \n", Supir.NIK);
		printf("Nama Supir     = %s \n", Supir.NamaSupir);
		printf("Jenis Kelamin  = %s \n", Supir.JenisKelamin);
		printf("Nomor Telepon     = %s \n", Supir.Telepon);
		rupiah(Supir.Harga, harga);
		printf("Harga Sewa Supir    = Rp %s \n", harga);
		printf("Stok Supir   = %d", Supir.StokSupir);
		printf("Status Supir   = %s", Supir.Status);
		
		printf("\n\nPilih data yang akan diupdate = ");
		printf("\n[1] Status Supir ");
		printf("\n[2] Harga Sewa Supir ");
		printf("\n[3] Stok Supir ");
		printf("\n[3] Batal "); 
		printf("\nPilih = ");
		getnum(&a,1);
		
		if(a==1)
		{
			printf("\nMasukkan Status Baru Supir = "); getteks(&Supir.Status,15);
			fwrite(&Supir,sizeof(Supir),1,Baru);
			fread(&Supir,sizeof(Supir),1,ArsSupir);
			
			while(!feof(ArsSupir))
			{
				fwrite(&Supir,sizeof(Supir),1,Baru);
				fread(&Supir,sizeof(Supir),1,ArsSupir);
			}
		}
		else
		if(a==2)
		{
			gotoxy(46,25);	printf("\nMasukkan Harga Baru Supir = Rp "); getRp(&Supir.Harga,1,20,32,26);
			fwrite(&Supir,sizeof(Supir),1,Baru);
			fread(&Supir,sizeof(Supir),1,ArsSupir);
			
			while(!feof(ArsSupir))
			{
				fwrite(&Supir,sizeof(Supir),1,Baru);
				fread(&Supir,sizeof(Supir),1,ArsSupir);
			}
		}
		else
		if(a==3)
		{
			gotoxy(45,37);	printf("Masukkan Stok Baru Supir = "); getnum(&Supir.StokSupir,4);
			fwrite(&Supir,sizeof(Supir),1,Baru);
			fread(&Supir,sizeof(Supir),1,ArsSupir);
			
			while(!feof(ArsSupir))
			{
				fwrite(&Supir,sizeof(Supir),1,Baru);
				fread(&Supir,sizeof(Supir),1,ArsSupir);
			}
		}
		else
		if(a==4)
		{
			system("cls");
			MenuCRUDSupir();	
		}
		else
		{
			printf("\nSupir Belum Tersedia");
			getche();
			system("cls");
			MenuCRUDSupir();
		}
		fclose(ArsSupir);
		fclose(Baru);
			
		Baru = fopen("supirbaru.dat", "rb");
		ArsSupir = fopen("arsipsupir.dat", "wb");
		
		fread (&Supir, sizeof(Supir),1,Baru);
		while(!feof(Baru))
		{
			fwrite (&Supir, sizeof (Supir),1,ArsSupir);
			fread (&Supir, sizeof (Supir),1,Baru);
		}
		fclose(ArsSupir);
		fclose(Baru);
	
		printf("\nSupir Berhasil Diupdate");
		getche();
		system("cls"); 
	}
}
    

void HapusDaftarSupir() 
{
	//Deklarasi
	bool found;
	int IDSupir;
	
	//Algoritma
	ArsSupir = fopen("arsipsupir.dat", "rb");
	Baru = fopen("supirbaru.dat", "wb");
	printf("-----Hapus Data Supir-----");
	printf("\nMasukkan ID Supir yang ingin dihapus = DRV"); 
	getnum(&IDSupir,4);
	found = false;	
	fread (&Supir, sizeof(Supir),1,ArsSupir);
	while (!(found) && !feof(ArsSupir)) 
	{
		if (Supir.IDSupir == IDSupir)
		{
			found = true;
			break;
		}else
		{
			fwrite (&Supir, sizeof (Supir),1,Baru);
			fread (&Supir, sizeof(Supir),1,ArsSupir);
		}
	}
	if (found) 
	{
		fread (&Supir, sizeof(Supir),1,ArsSupir);
		while (!feof(ArsSupir)) 
		{
			fwrite (&Supir, sizeof (Supir),1,Baru);
			fread (&Supir, sizeof(Supir),1,ArsSupir);
		}
	}
	else
	{
		printf("\nSupir Belum Tersedia");
		getche();
		system("cls");
		MenuCRUDSupir();
	}
	fclose(Baru);
	fclose(ArsSupir);
	
	ArsMobil = fopen("arsipsupir.dat", "wb");
	Baru = fopen("supirbaru.dat", "rb");
	fread (&Supir, sizeof(Supir),1,Baru);
	while(!feof(Baru)) 
	{
		fwrite (&Supir, sizeof (Supir),1,ArsSupir);
		fread (&Supir, sizeof(Supir),1,Baru);
	}
	fclose(ArsSupir);
	fclose(Baru);
	
	printf("\nSupir Berhasil Dihapus");
	getche();
	system("cls");
	MenuCRUDSupir();
}
