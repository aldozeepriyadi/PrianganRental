#include <stdio.h>
#include <windows.h>

void Login();
void Admin();
void Kasir();
void Manager();
void MenuAdmin();
void MenuKasir();
void MenuManager();

main(){
	Login();
}

void Login(){
	
	int n;
		
	printf("\n");
    printf("\n\t\t  *--------------------------------------------------------*\n");
    printf("\n\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t        =                  WELCOME                  =");
    printf("\n\t\t        =                    TO                     =");
    printf("\n\t\t        =              Priangan Rental              =");
    printf("\n\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t                                                     ");
    printf("\n\t\t                      == MENU LOGIN ==               ");
	printf("\n\t\t        [1] Admin                                    ");
	printf("\n\t\t        [2] Kasir                                    ");
	printf("\n\t\t        [3] Manager                                  ");
	printf("\n\t\t        [4] Keluar Program                           ");
	printf("\n\t\t                                                     ");
    printf("\n\t\t  *--------------------------------------------------------*\n");
    printf("\n\t\t                  Anda Akan Login Sebagai : ");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			Admin();
		break;
		case 2:
			Kasir();
		break;
		case 3:
			Manager();	
		break;
		case 0:
			exit(0);
		break;
		default : Login();
		break;
	}
}

void Admin(){
   char username[15], password[12];
   int status = 0, salah = 0;
	system("cls");
   while(status < 3){
    printf("\n\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t        =                  WELCOME                  =");
    printf("\n\t\t        =                    TO                     =");
    printf("\n\t\t        =           Admin Priangan Rental           =");
    printf("\n\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t                                                     ");
      printf("\n\t\t          Masukkan Username : ");
      scanf("%s", &username);
      printf("\t\t          Masukkan Password : ");
      scanf("%s", &password);

      if(strcmp(username, "admin")==0 && strcmp(password, "admin")== 0){
         printf("\n\t\t\t     =-= Halo Admin, Selamat Bekerja! =-=\n");
         MenuAdmin();
         break;
      }else{
         printf("Username dan Password yang dimasukkan Salah\n");
         salah++;
         if(salah == 3){
            printf("Akses ditolak\n");
         }
      }
      status++;
   }

   system("pause");
}

void Kasir(){
   char username[15], password[12];
   int status = 0, salah = 0;
	system("cls");
   while(status < 3){
    printf("\n\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t        =                  WELCOME                  =");
    printf("\n\t\t        =                    TO                     =");
    printf("\n\t\t        =           Kasir Priangan Rental           =");
    printf("\n\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t                                                     ");
      printf("\n\t\t          Masukkan Username : ");
      scanf("%s", &username);
      printf("\t\t          Masukkan Password : ");
      scanf("%s", &password);

      if(strcmp(username, "kasir")==0 && strcmp(password, "kasir")== 0){
         printf("\n\t\t\t     =-= Halo Kasir, Selamat Bekerja! =-=\n");
         MenuKasir();
         break;
      }else{
         printf("Username dan Password yang dimasukkan Salah\n");
         salah++;
         if(salah == 3){
            printf("Akses ditolak\n");
         }
      }
      status++;
   }

   system("pause");
}

void Manager(){
   char username[15], password[12];
   int status = 0, salah = 0;
	system("cls");
   while(status < 3){
    printf("\n\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t        =                  WELCOME                  =");
    printf("\n\t\t        =                    TO                     =");
    printf("\n\t\t        =           Manager Priangan Rental         =");
    printf("\n\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t                                                     ");
      printf("\n\t\t          Masukkan Username : ");
      scanf("%s", &username);
      printf("\t\t          Masukkan Password : ");
      scanf("%s", &password);

      if(strcmp(username, "manager")==0 && strcmp(password, "manager")== 0){
         printf("\n\t\t\t    =-= Halo Manager, Selamat Bekerja! =-=\n");
         MenuManager();
         break;
      }else{
         printf("Username dan Password yang dimasukkan Salah\n");
         salah++;
         if(salah == 3){
            printf("Akses ditolak\n");
         }
      }
      status++;
   }

   system("pause");
}

void MenuAdmin(){
	printf("\t\t\t\t    ========ADMIN========\n\n"    );
	printf("\t\t\t\t    [1] Data User\n"              );
	printf("\t\t\t\t    [2] Data Mobil\n"             );
	printf("\t\t\t\t    [3] Data Supir\n"             );
	printf("\t\t\t\t    [4] Kembali\n"                );
	printf("\t\t\t\t    [5] Keluar Program\n"         );
	printf("\t\t\t                                   ");
	printf("\n\t\t\t    Pilih Menu yang ingin Anda Akses : \n");
}

void MenuKasir(){
	printf("\t\t\t\t    ========KASIR========\n\n"    );
	printf("\t\t\t\t    [1] Data Mobil\n"             );
	printf("\t\t\t\t    [2] Data Supir\n"             );
	printf("\t\t\t\t    [3] Data Booking\n"           );
	printf("\t\t\t\t    [4] Pengambilan\n"            );
	printf("\t\t\t\t    [5] Pengembalian\n"           );
	printf("\t\t\t\t    [6] Tagihan Pembayaran\n"     );
	printf("\t\t\t\t    [7] Laporan Transaksi\n"      );	
	printf("\t\t\t\t    [8] Kembali\n"                );
	printf("\t\t\t\t    [9] Keluar Program\n"         );
	printf("\t\t\t                                   ");
	printf("\n\t\t\t    Pilih Menu yang ingin Anda Akses : \n");
}

void MenuManager(){
	printf("\t\t\t\t   ========MANAGER========\n\n"   );
	printf("\t\t\t\t    [1] Data User\n"              );
	printf("\t\t\t\t    [2] Data Mobil\n"             );
	printf("\t\t\t\t    [3] Data Supir\n"             );
	printf("\t\t\t\t    [4] Laporan Transaksi\n"      );
	printf("\t\t\t\t    [5] Kembali\n"                );
	printf("\t\t\t\t    [6] Keluar Program\n"         );
	printf("\t\t\t                                   ");
	printf("\n\t\t\t    Pilih Menu yang ingin Anda Akses : \n");
}
