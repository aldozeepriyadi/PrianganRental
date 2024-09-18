//Menu CRUD Karyawan

FILE *ArsKaryawan;		    /* nama file */
FILE *Baru;				    /* nama file */

//Deklarasi
typedef struct {
				int IDKaryawan;
				char NamaKaryawan[25];
				int NIKKaryawan[16];
				char AlamatKaryawan[30];
				int TelpKaryawan[15];
				char RoleKaryawan[10];
				} arsipkaryawan;
arsipkaryawan Karyawan;
typedef arsipkaryawan FileKaryawan; FileKaryawan EditKaryawan;

typedef struct {
				int IDBaru;
				char NamaBaru;
				int NIKBaru;
				char RoleBaru;
				}KaryawanBaru;
KaryawanBaru karyawanbaru;

void MenuCRUDKaryawan();
void TambahDaftarKaryawan();
void LihatDaftarUser();
void UpdateDaftarUser();
void HapusDaftarKaryawan();

void MenuCRUDKaryawan() 
{
	//Deklarasi
	int Pilihan;
	system("cls");
	do
	{
	gotoxy(20,14);	printf("Kelola Data Karyawan");
	gotoxy(18,16);	printf("[1] Tambah Data Karyawan ");
	gotoxy(18,17);	printf("[2] Lihat Data Karyawan ");
	gotoxy(18,18);	printf("[3] Update Data Karyawan ");
	gotoxy(18,19);	printf("[4] Hapus Data Karyawan ");
	gotoxy(18,20);	printf("[5] Kembali ");
	gotoxy(18,21);	printf("[6] Keluar Program ");
	gotoxy(25,23);	printf("["); gotoxy(27,23);	printf("]"); 
	gotoxy(26,23);	getnum(&Pilihan,1);
	switch (Pilihan) 
	{
		case 1 : TambahDaftarKaryawan();
		break;
		case 2 : LihatDaftarKaryawan();
		break;
		case 3 : UpdateDaftarKaryawan();
		break;
		case 4 : HapusDaftarKaryawan();
		break;
		case 5 : MenuAdmin();
		break;
		case 6 : 
				
				exit(0);
		default: printf("Pilihan Tidak Tersedia, Mohon Pilih Kembali!");
		MenuCRUDKaryawan();
	}
	}
	while(Pilihan !=6);
}

void TambahDaftarKaryawan()
{
	//Deklarasi
	int id;
	
	//Algortima
	ArsKaryawan = fopen("arsipkaryawan.dat", "r+");
	fread(&Karyawan,sizeof(Karyawan),1,ArsKaryawan);
	while(!feof(ArsKaryawan))
		{
			fread(&Karyawan,sizeof(Karyawan),1,ArsKaryawan);
			id = Karyawan.IDKaryawan;
		}
	fclose(ArsKaryawan);
	Karyawan.IDKaryawan		= id +1;	
	gotoxy(45,15);	printf("-----Tambah Daftar Karyawan-----");
	gotoxy(45,21);	printf("ID Karyawan        = KRW%d ", Karyawan.IDKaryawan);
	gotoxy(45,22);	printf("Nama Karyawan      = "); fflush(stdin);
	getteks(Karyawan.NamaKaryawan, 25);
	gotoxy(45,23);	printf ("Alamat Karyawan     = ");
	getteks(&Karyawan.AlamatKaryawan,30);
	gotoxy(45,24);	printf ("NIK Karyawan      = ");
	getteksnum (&Karyawan.NIKKaryawan,16);
	gotoxy(45,25);	printf ("Telepon Karyawan = "); fflush(stdin);
	getteksnum (&Karyawan.TelpKaryawan,15);
	gotoxy(45,26);  printf ("Role Karyawan = "); fflush(stdin);
	getteks(&Karyawan.RoleKaryawan, 10);
	
	ArsKaryawan = fopen("arsipkaryawan.dat", "ab");
	fwrite(&Karyawan, sizeof(Karyawan),1,ArsKaryawan);
	fclose(ArsKaryawan);
	
	printf("\nKaryawan Berhasil Ditambahkan!");
	getche();
	system("cls");
	MenuCRUDKaryawan();
}

void LihatDaftarKaryawan()
{
	// Deklarasi
	int y;
	system("cls");
	
	// Algoritma
	ArsKaryawan = fopen("arsipkaryawan.dat", "rb");
	printf("-----Lihat Daftar Karyawan-----");
	printf("\n=====================================================================================================================");
	printf("\nID");
	printf("\nNama Karyawan");
	printf("\nNIK Karyawan");
	printf("\nAlamat Karyawan");
	printf("\nTelepon Karyawan");
	printf("\nRole Karyawan");
	printf("\n=====================================================================================================================");
	y = 24;
	fread(&Karyawan, sizeof(Karyawan),1,ArsKaryawan);
	while (!feof(ArsKaryawan)) 
	{ 
		printf("\n\nKRW%d ", Karyawan.IDKaryawan); fflush(stdin);
		printf("\n%s ", Karyawan.NamaKaryawan); fflush(stdin);
		printf("\n%s ", Karyawan.NIKKaryawan); fflush(stdin);
		printf("\n%s ", Karyawan.AlamatKaryawan); fflush(stdin);
		printf("\n%s ", Karyawan.TelpKaryawan); fflush(stdin);
		printf("\n%s ", Karyawan.RoleKaryawan); fflush(stdin);
		fread(&Karyawan, sizeof(Karyawan),1,ArsKaryawan);
		y=y+1;
	}
	fclose(ArsKaryawan);
	getch();
	system("cls");
}

void UpdateDaftarKaryawan()
{
	FILE *Baru;
	
	// Deklarasi
	bool found;
	int a;
	char nama[20];
	
	// Algoritma
	ArsKaryawan = fopen("arsipkaryawan.dat", "rb");
	Baru = fopen("karyawanbaru.dat", "wb");
	printf("\t-----Update Data Karyawan-----");
	printf("\nMasukkan ID User yang ingin diupdate = KRW"); 
	getnum(&karyawanbaru.IDBaru,4);
	found = false;
	while (!found && !feof(ArsKaryawan)) 
	{
		fread (&Karyawan, sizeof(Karyawan) , 1 , ArsKaryawan);
		if(Karyawan.IDKaryawan == karyawanbaru.IDBaru) 
		{
			found = true;
		}
		else
		{
			fwrite (&Karyawan, sizeof (Karyawan),1,Baru);
		}
	}
	if(found == true)
	{
		printf("\nID Karyawan      = KRW%d \n ", Karyawan.IDKaryawan);
		printf("Nama Karyawan     = %s \n", Karyawan.NamaKaryawan);
		printf("Alamat Karyawan   = %s \n", Karyawan.AlamatKaryawan);
		printf("NIK Karyawan    = %s \n", Karyawan.NIKKaryawan);
		printf("Telepon Karyawan     = %s \n", Karyawan.TelpKaryawan);
		printf("Role Karyawan    = %s \n", Karyawan.RoleKaryawan);
		
		printf("Pilih data yang akan diupdate = \n");
		printf("[1] Alamat Karyawan \n");
		printf("[2] Role Karyawan \n");
		printf("[3] Nomor Telpon Karyawan \n");
		printf("[4] Batal \n"); 
		printf("Pilih = ");
		getnum(&a,1);
		
		if(a==1)
		{
			printf("\nMasukkan Alamat Karyawan Baru  = "); getteks(&Karyawan.AlamatKaryawan,25);
			fwrite(&Karyawan,sizeof(Karyawan),1,Baru);
			fread(&Karyawan,sizeof(Karyawan),1,ArsKaryawan);
			
			while(!feof(ArsKaryawan))
			{
				fwrite(&Karyawan,sizeof(Karyawan),1,Baru);
				fread(&Karyawan,sizeof(Karyawan),1,ArsKaryawan);
			}
		}
		else
		if(a==2)
		{
			printf("\nMasukkan Role Baru Karyawan =  "); getteks(&Karyawan.RoleKaryawan,10);
			fwrite(&Karyawan,sizeof(Karyawan),1,Baru);
			fread(&Karyawan,sizeof(Karyawan),1,ArsKaryawan);
			
			while(!feof(ArsKaryawan))
			{
				fwrite(&Karyawan,sizeof(Karyawan),1,Baru);
				fread(&Karyawan,sizeof(Karyawan),1,ArsKaryawan);
			}
		}
		else
		if(a==3)
		{
			printf("\nMasukkan Nomor Telpon Baru Karyawan =  "); getteksnum(&Karyawan.TelpKaryawan,15);
			fwrite(&Karyawan,sizeof(Karyawan),1,Baru);
			fread(&Karyawan,sizeof(Karyawan),1,ArsKaryawan);
			
			while(!feof(ArsKaryawan))
			{
				fwrite(&Karyawan,sizeof(Karyawan),1,Baru);
				fread(&Karyawan,sizeof(Karyawan),1,ArsKaryawan);
			}
	    }
		else
		if(a==4)
		{
			system("cls");
			MenuCRUDKaryawan();
		}
		else
		{
			printf("\nKaryawan Tidak Ada");
			system("cls");
			MenuCRUDKaryawan();
		}
		fclose(ArsKaryawan);
		fclose(Baru);
			
		Baru = fopen("karyawanbaru.dat", "rb");
		ArsKaryawan = fopen("ArsipKaryawan.dat", "wb");
		
		fread (&Karyawan, sizeof(Karyawan),1,Baru);
		while(!feof(Baru))
		{
			fwrite (&Karyawan, sizeof (Karyawan),1,ArsKaryawan);
			fread (&Karyawan, sizeof (Karyawan),1,Baru);
		}
		fclose(ArsKaryawan);
		fclose(Baru);
		
		printf("\nKaryawan Berhasil Diupdate");
		getche();
		system("cls");
		MenuCRUDKaryawan();
	}
}

void HapusDaftarKaryawan() 
{
	//Deklarasi
	bool found;
	int IDKaryawan;
	
	//Algoritma
	ArsKaryawan = fopen("arsipkaryawan.dat", "rb");
	Baru = fopen("karyawanbaru.dat", "wb");
	printf("\t-----Hapus Data Karyawan-----");
	printf("\nMasukkan ID Karyawan yang ingin dihapus = ORG"); 
	getnum(&IDKaryawan,4);
	found = false;	
	fread (&Karyawan, sizeof(Karyawan),1,ArsKaryawan);
	while (!(found) && !feof(ArsKaryawan)) 
	{
		if (Karyawan.IDKaryawan == IDKaryawan) 
		{
			found = true;
			break;
		}else
		{
			fwrite (&Karyawan, sizeof (Karyawan),1,Baru);
			fread (&Karyawan, sizeof(Karyawan),1,ArsKaryawan);
		}
	}
	if (found) 
	{
		fread (&Karyawan, sizeof(Karyawan),1,ArsKaryawan);
		while (!feof(ArsKaryawan)) 
		{
			fwrite (&Karyawan, sizeof (Karyawan),1,Baru);
			fread (&Karyawan, sizeof(Karyawan),1,ArsKaryawan);
		}
	}
	else
	{
		printf("\nKaryawan Tidak Tersedia");
		getche();
		system("cls");
		MenuCRUDKaryawan();
	}
	fclose(Baru);
	fclose(ArsKaryawan);
	
	ArsKaryawan = fopen("arsipkaryawan.dat", "wb");
	Baru = fopen("karyawanbaru.dat", "rb");
	fread (&Karyawan, sizeof(Karyawan),1,Baru);
	while(!feof(Baru)) 
	{
		fwrite (&Karyawan, sizeof (Karyawan),1,ArsKaryawan);
		fread (&Karyawan, sizeof(Karyawan),1,Baru);
	}
	fclose(ArsKaryawan);
	fclose(Baru);
	
	printf("\nKaryawan Berhasil Dihapus");
	getche();
	system("cls");
	MenuCRUDKaryawan();
}
