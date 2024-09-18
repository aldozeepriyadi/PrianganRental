//Login

void MenuAdmin();
void MenuKasir();
void MenuManager();
void Keluar();

void MenuAdmin(){
	int x;
	system("cls");
	
	printf("\n");
	gotoxy(73,18);  printf("========ADMIN========\n\n"    );
	gotoxy(74,20);  printf("[1] Data Karyawan\n"          );
	gotoxy(74,21);  printf("[2] Data Mobil\n"             );
	gotoxy(74,22);  printf("[3] Data Supir\n"             );
	gotoxy(74,23);  printf("[4] Logout\n"                 );
	gotoxy(74,24);  printf("[5] Keluar Program\n"         );
	gotoxy(68,26);  printf("Pilih Menu yang ingin Anda Akses");
	gotoxy(83,28);  printf("["); gotoxy(85,28); printf("]");
	gotoxy(84,28);  scanf("%d",&x);
	switch(x)
	{
		case 1:
			MenuCRUDKaryawan();
		break;
		case 2:
			MenuCRUDMobil();
		break;
		case 3:
			MenuCRUDSupir();
		case 4:
			Keluar();
		case 5:
			exit(0);
		break;
		default : printf("Pilihan Tidak Tersedia, Mohon Pilih Kembali!");
		MenuAdmin();
		break;
	}
}

void MenuKasir(){
	int x;
	system("cls");
	
	printf("\n");
	gotoxy(73,18);  printf("========KASIR========\n\n"    );
 	gotoxy(74,20);  printf ("[1] Data Mobil");
	gotoxy(74,21);  printf ("[2] Data Supir");
	gotoxy(74,22);  printf ("[3] Input Pesanan");
	gotoxy(74,23);  printf ("[4] Pembayaran Mobil");
	gotoxy(74,24);  printf ("[5] Pembayaran Supir");
	gotoxy(74,25);  printf ("[6] Kembali ");
    gotoxy(74,26);  printf ("[7] Keluar Program");
	gotoxy(68,27);  printf("Pilih Menu yang ingin Anda Akses");
	gotoxy(83,29);  printf("["); gotoxy(85,29); printf("]"); 
	gotoxy(84,29);  scanf("%d",&x);
		switch (x)
		{
				case 1 :UpdateDaftarMobil();
				        MenuKasir(); 
				 		break;
				case 2 :UpdateDaftarSupir();
						MenuKasir();
						break;
				case 3 :LihatDaftarMobil();
				        getche();
						SewaMobil();
						break;
				case 4 :keranjangBook();
						Bayar();
						break;		
				case 5 :keranjang();
				        BayarSupir();
				case 6 :Login();
						break;
				case 7 :exit(0);
						break;
				default : ("Pilihan Tidak Tersedia, Mohon Pilih Kembali!");
						  MenuKasir();
						  break;
		}
	}

void MenuManager(){
	int x;
	system("cls");
	
	printf("\n");
	printf("\t\t\t\t   ========MANAGER========\n\n"   );
	printf("\t\t\t\t    [1] Data Karyawan\n"          );
	printf("\t\t\t\t    [2] Data Mobil\n"             );
	printf("\t\t\t\t    [3] Data Supir\n"             );
	printf("\t\t\t\t    [4] Laporan Bulanan Mobil\n"  );
	printf("\t\t\t\t    [5] Laporan Tahunan Mobil\n"  );
	printf("\t\t\t\t    [6] Laporan Bulanan Supir\n"  );
	printf("\t\t\t\t    [7] Laporan Tahunan Supir\n"  );
	printf("\t\t\t\t    [8] Logout\n"                 );
	printf("\t\t\t\t    [9] Keluar Program\n"         );
	printf("\t\t\t                                   ");
	printf("\n\t\t\t    Pilih Menu yang ingin Anda Akses : ");
	scanf("%d",&x);
	switch(x)
	{
		case 1:
			LihatDaftarKaryawan();
			MenuManager();
		break;
		case 2:
			LihatDaftarMobil();
			MenuManager();
		break;
		case 3:
			LihatDaftarMobil();
			MenuManager();
		break;
		case 4:
			SortingRiwayatBulanan();
		break;
		case 5:
			SortingRiwayatTahunan();
		break;
		case 6:
			SortingRiwayatBulan();
		break;
		case 7:
			SortingRiwayatTahun();
		break;
		case 8:
			Keluar();
		break;
		case 9:
			exit(0);
		break;
		default : printf("Pilihan Tidak Tersedia, Mohon Pilih Kembali!");
		MenuManager();
		break;
	}
}

void Keluar(){
	Login();
}
