//Menu CRUD Mobil

FILE *ArsMobil;		    /* nama file */
FILE *Baru;				/* nama file */

// Deklarasi
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
typedef arsipmobil FileMobil; FileMobil EditMobil;

typedef struct {
				int IDBaru;
				int StokBaru;
				int HargaBaru;
				}MobilBaru;
MobilBaru mobilbaru;

void MenuCRUDMobil();
void TambahDaftarMobil();
void LihatDaftarMobil();
void UpdateDaftarMobil();
void HapusDaftarMobil();

void MenuCRUDMobil()
{
	//Deklarasi
	int Menu;
	system("cls");
	
	//Algoritma

	printf("\n");
	printf("\t\t\t\t    ========Kelola Data Mobil========\n\n"    );
	printf("\t\t\t\t    [1] Tambah Data Mobil\n"                  );
	printf("\t\t\t\t    [2] Lihat Data Mobil\n"                   );
	printf("\t\t\t\t    [3] Update Data Mobil\n"                  );
	printf("\t\t\t\t    [4] Hapus Data Mobil\n"                   );
	printf("\t\t\t\t    [5] Kembali\n"                            );
	printf("\t\t\t\t    [6] Keluar Program\n"                     );
	printf("\t\t\t                                               ");
	printf("\n\t\t\t    Pilih Menu yang ingin Anda Akses : "      );
	scanf("%d", &Menu,1);
	switch(Menu)
	{
		case 1 : TambahDaftarMobil();
		break;
		case 2 : LihatDaftarMobil();
		         MenuCRUDMobil();
		break;
		case 3 : UpdateDaftarMobil();
		         MenuCRUDMobil();
		break;
		case 4 : HapusDaftarMobil();
		break;
		case 5 : MenuAdmin();
		break;
		case 6 :
				 exit(0);
		default: printf("Pilihan Tidak Tersedia, Mohon Pilih Kembali!");
		MenuCRUDMobil();
		break;
	}
	while(Menu !=6);
}

void TambahDaftarMobil()
{
	//Deklarasi
	int id;

	//Algoritma 

	ArsMobil = fopen("arsipmobil.dat", "r+");
	fread(&Mobil,sizeof(Mobil),1,ArsMobil);
	while(!feof(ArsMobil))
		{
			fread(&Mobil,sizeof(Mobil),1,ArsMobil);
			id = Mobil.IDMobil;
		}
	fclose(ArsMobil);
	Mobil.IDMobil = id +1;
	printf("-----Tambah Daftar Mobil-----\n");
	printf("ID Mobil        = CAR%d \n" , Mobil.IDMobil);
	printf("Nama Mobil      = "); fflush(stdin);
	getteks (Mobil.NamaMobil, 25);
	printf ("\nNo Plat     = "); fflush(stdin); 
	getteksnum (Mobil.NomorPlat, 10);
	printf ("\nWarna Mobil    = "); fflush(stdin); 
	getteks (Mobil.Warna, 10);
	printf ("\nStok Mobil      = "); 
	getnum(&Mobil.StokMobil, 4);
	printf ("\nHarga Sewa Mobil     = Rp ");
	getRp(&Mobil.HargaSewa,1,20,26,17);
	printf("\nStatus Mobil	= ");
	getteks(Mobil.Status,15);
	
	ArsMobil = fopen("arsipmobil.dat", "ab");
	fwrite(&Mobil, sizeof(Mobil),1,ArsMobil);
	fclose(ArsMobil);
	
	printf("\nMobil Berhasil Ditambahkan");
	getche();
	system("cls");
	MenuCRUDMobil();
}

void LihatDaftarMobil()
{
	//Deklarasi
	int y;
	char harga[20];
	system("cls");
	
	//Algoritma
	ArsMobil = fopen("arsipmobil.dat", "rb");
    gotoxy(90,15);	printf("-----Lihat Daftar Mobil-----");
	gotoxy(34,20);	printf("==========================================================================================================================");
	gotoxy(34,21);	printf("ID Mobil");
	gotoxy(49,21);	printf("Nama Mobil");
	gotoxy(67,21);	printf("Nomor Plat");
	gotoxy(87,21);	printf("Warna Mobil");
	gotoxy(107,21); printf("Stok Mobil");
	gotoxy(125,21);	printf("Harga Sewa");
	gotoxy(143,21);	printf("Status Mobil");
	gotoxy(34,22);	printf("==========================================================================================================================");
	y = 24; 
	fread(&Mobil, sizeof(Mobil),1,ArsMobil);
	while (!feof(ArsMobil)) 
	{ 
	printf("\n\nCAR%d ",Mobil.IDMobil); fflush(stdin);
	printf("\n%s ", Mobil.NamaMobil); fflush(stdin);
	printf("\n%s ", Mobil.NomorPlat); fflush(stdin);
	printf("\n%s ", Mobil.Warna); fflush(stdin);
	printf("\n%d ", Mobil.StokMobil); 
		rupiah(Mobil.HargaSewa, harga);
	printf("\nRp %s", harga); fflush(stdin);
	printf("\n%s", Mobil.Status);
		y=y+1;
		fread(&Mobil, sizeof(Mobil),1,ArsMobil);
	}
	fclose(ArsMobil);
	getch();
	system("cls");
}

void UpdateDaftarMobil()
{
	FILE *Baru;
	
	//Deklarasi
	bool found;
	int a;
	char harga[20];
	
	//Algoritma
	ArsMobil = fopen("arsipmobil.dat", "rb");
	Baru = fopen("mobilbaru.dat", "wb");
	printf("-----Update Data Mobil-----");
	printf("\nMasukkan ID Mobil yang ingin diupdate = CAR");
	getnum(&mobilbaru.IDBaru,4);
	found = false;
	while (!found && !feof(ArsMobil)) 
	{
		fread (&Mobil, sizeof(Mobil) , 1 , ArsMobil);
		if(Mobil.IDMobil == mobilbaru.IDBaru) 
		{
			found = true;
		}
		else
		{
			fwrite (&Mobil, sizeof (Mobil),1,Baru);
		}
	}
	if(found == true)
	{
		printf("\nID Mobil       = CAR%d \n", Mobil.IDMobil);
		printf("Nama Mobil     = %s \n", Mobil.NamaMobil);
		printf("Nomor Plat      = %s \n", Mobil.NomorPlat);
		printf("Warna Mobil    = %s \n", Mobil.Warna);
		printf("Stok Mobil     = %d \n", Mobil.StokMobil);
		rupiah(Mobil.HargaSewa, harga);
		printf("Harga Mobil    = Rp %s \n", harga);
		printf("Status Mobil   = %s", Mobil.Status);
		
		printf("\n\nPilih data yang akan diupdate = ");
		printf("\n[1] Status Mobil ");
		printf("\n[2] Harga Sewa Mobil ");
		printf("\n[3] Stok Mobil ");
		printf("\n[4] Batal ");
		printf("\nPilih = ");
		getnum(&a,1);
		
		if(a==1)
		{
			printf("\nMasukkan Status Baru Mobil = "); getteks(&Mobil.Status,15);
			fwrite(&Mobil,sizeof(Mobil),1,Baru);
			fread(&Mobil,sizeof(Mobil),1,ArsMobil);
			
			while(!feof(ArsMobil))
			{
				fwrite(&Mobil,sizeof(Mobil),1,Baru);
				fread(&Mobil,sizeof(Mobil),1,ArsMobil);
			}
		}
		else
		if(a==2)
		{
			printf("\nMasukkan Harga Baru Mobil = Rp "); getRp(&Mobil.HargaSewa,1,20,31,26);
			fwrite(&Mobil,sizeof(Mobil),1,Baru);
			fread(&Mobil,sizeof(Mobil),1,ArsMobil);
			
			while(!feof(ArsMobil))
			{
				fwrite(&Mobil,sizeof(Mobil),1,Baru);
				fread(&Mobil,sizeof(Mobil),1,ArsMobil);
			}
		}
		else
		if(a==3)
		{
			gotoxy(45,37);	printf("Masukkan Stok Baru Mobil = "); getnum(&Mobil.StokMobil,4);
			fwrite(&Mobil,sizeof(Mobil),1,Baru);
			fread(&Mobil,sizeof(Mobil),1,ArsMobil);
			
			while(!feof(ArsMobil))
			{
				fwrite(&Mobil,sizeof(Mobil),1,Baru);
				fread(&Mobil,sizeof(Mobil),1,ArsMobil);
			}
		}
		else
		if(a==4)
		{
			system("cls");
			MenuCRUDMobil();
		}
		else
		{
			printf("\nMobil Belum Tersedia");
			getche();
			system("cls");
			MenuCRUDMobil();
		}
		fclose(ArsMobil);
		fclose(Baru);
			
		Baru = fopen("mobilbaru.dat", "rb");
		ArsMobil = fopen("arsipmobil.dat", "wb");
		
		fread (&Mobil, sizeof(Mobil),1,Baru);
		while(!feof(Baru))
		{
			fwrite (&Mobil, sizeof (Mobil),1,ArsMobil);
			fread (&Mobil, sizeof (Mobil),1,Baru);
		}
		fclose(ArsMobil);
		fclose(Baru);
		
		printf("\nMobil Berhasil Diupdate");
		getche();
		system("cls");
		MenuCRUDMobil();
	}
        printf("\nMobil Berhasil Diupdate");
		getche();
	    system("cls");
}

void HapusDaftarMobil() 
{
	//Deklarasi
	bool found;
	int IDMobil;
	
	//Algoritma
	ArsMobil = fopen("arsipmobil.dat", "rb");
	Baru = fopen("mobilbaru.dat", "wb");
	printf("-----Hapus Data Mobil-----");
	printf("\nMasukkan ID Mobil yang ingin dihapus = CAR"); 
	getnum(&IDMobil,4);
	found = false;	
	fread (&Mobil, sizeof(Mobil),1,ArsMobil);
	while (!(found) && !feof(ArsMobil)) 
	{
		if (Mobil.IDMobil == IDMobil) 
		{
			found = true;
			break;
		}else
		{
			fwrite (&Mobil, sizeof (Mobil),1,Baru);
			fread (&Mobil, sizeof(Mobil),1,ArsMobil);
		}
	}
	if (found) 
	{
		fread (&Mobil, sizeof(Mobil),1,ArsMobil);
		while (!feof(ArsMobil)) 
		{
			fwrite (&Mobil, sizeof (Mobil),1,Baru);
			fread (&Mobil, sizeof(Mobil),1,ArsMobil);
		}
	}
	else
	{
		printf("\nMobil Belum Tersedia");
		getche();
		system("cls");
		MenuCRUDMobil();
	}
	fclose(Baru);
	fclose(ArsMobil);
	
	ArsMobil = fopen("arsipmobil.dat", "wb");
	Baru = fopen("mobilbaru.dat", "rb");
	fread (&Mobil, sizeof(Mobil),1,Baru);
	while(!feof(Baru)) 
	{
		fwrite (&Mobil, sizeof (Mobil),1,ArsMobil);
		fread (&Mobil, sizeof(Mobil),1,Baru);
	}
	fclose(ArsMobil);
	fclose(Baru);
	
	printf("\nMobil Berhasil Dihapus");
	getche();
	system("cls");
	MenuCRUDMobil();
}
