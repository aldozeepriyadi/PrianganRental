#define ENTER 13
#define TAB 9
#define BCKSPC 8

//Prosedur
void Login();
void gotoxy(int x, int y);
//Prosedur dari header lain
void MenuAdmin();
void MenuKasir();
void MenuManager();

typedef struct{
	char fullName[50];
	char email[50];
	char password[50];
	char username[50];
}DataLogin; 

DataLogin user;

void takeinput(char ch[50]){
	fgets(ch,50,stdin);
	ch[strlen(ch) - 1] = 0; 
}

char generateUsername(char email[50],char username[50]){
	int i = 0;
	for(i;i<strlen(email);i++){
		if(email[i] == '@') break;
		else username[i] = email[i];
	}
}

void takepassword(char password[50]){
	int i;
	char ch;
	while(1){
		ch = getch();
		if(ch == ENTER || ch == TAB){
			password[i] = '\0';
			break;
		}else if(ch == BCKSPC){
			if(i>0){
				i--;
				printf("\b \b");
			}
		}else{
		password[i++] = ch;
			printf("* \b");
		}
	}
}


void Login(){

	FILE *fp;
	int opt,userFound = 0;
	int iden = 0;
	system("cls");
	char username[50],password[50];
	gotoxy(55, 13); printf("========================================================");
	gotoxy(55, 14); printf("=                                                      =");
	gotoxy(55, 15); printf("---------- Selamat Datang di Priangan Rental ---------- ");
	gotoxy(55, 16); printf("=                                                      =");
	gotoxy(55, 17); printf("========================================================");
	gotoxy(69, 19); printf("Silahkan masukkan pilihan");
	gotoxy(70, 20); printf("1. Daftar");
	gotoxy(70, 21); printf("2. Masuk");
	gotoxy(70, 22); printf("3. Keluar");
	
	gotoxy(76,24);  printf("Pilihan Anda");
	gotoxy(80,25);  printf("["); gotoxy(82,25); printf("]");
	gotoxy(81,25);  scanf("%d",&opt);
	fgetc(stdin);
	 
	switch(opt){
		case 1:
			system("cls");
			printf("\nMasukkan job desk : ");
			takeinput(user.fullName);
			printf("Masukkan Email : ");
			takeinput(user.email);
			printf("Masukkan Password : ");
			takepassword(user.password);
			printf("\nKonfirmasi Password : ");
			takepassword(password);
			
			if(!strcmp(user.password,password)){
				generateUsername(user.email,user.username);
				fp = fopen("DataLogin.dat","ab+");
				fwrite(&user,sizeof (user),1,fp);
			if(fwrite != 0){
			printf("\n\nRegistrasi data login berhasil, username =  %s",user.username);
			getche();
			Login();
			
				}else printf("\n\nSorry! Something went wrong");
				fclose(fp);
			}
			else{
				printf("\n\nPassword tidak sesuai");
				getche();
				exit(0);

			}
		break;
		
		case 2:
			
			gotoxy(67,27);  printf("Masukkan Username Anda : ");
			takeinput(username);
			gotoxy(67,29);  printf("Masukkan Password Anda : ");
			takepassword(password);


			fp = fopen("DataLogin.dat","r");
			
			while(fread(&user,sizeof(user),1,fp)){
				if(!strcmp(user.username,username)){
					if(!strcmp(user.password,password)){
						system("cls");
						gotoxy(66,18);  printf("======== Selamat Datang %s ========",user.fullName);
						gotoxy(75,20);  printf("|Job Desk :%s",user.fullName);
						gotoxy(75,21);  printf("|Email :%s",user.email);
						gotoxy(75,22);  printf("|Username :%s",user.username);
						printf("\n");	
						getche();
						
						if((strcmp(user.fullName,"Admin")==0))
									{
								gotoxy(66,24);  printf("Login berhasil, Login sebagai Admin");
										getche();
										MenuAdmin();
									}
								else if ((strcmp(user.fullName,"Kasir")==0))
								{
								gotoxy(66,24);  printf("Login berhasil, Login sebagai Bagian Kasir");
										getche();
										MenuKasir();
									}
							else if ((strcmp(user.fullName,"Manager")==0))
								{
								gotoxy(66,24);  printf("\n\nLogin berhasil, Login sebagai Manager");
										getche();
										MenuManager();
						
								fclose(fp);
								break;
								}
				}
					else {
						printf("\n\nPassword yang Dimasukkan Salah!");
						getche();
						exit(0);
					}
					userFound = 1;
				}
			}
			if(!userFound){
				printf("\nUser Tidak Ditemukan, Harap Daftar Terlebih Dahulu ^_^");
				getche();
				exit(0);
			}
								
		case 3:
			system("cls");
			gotoxy(76,30);  printf("Selamat Tinggal ^_^");
			getche();
			exit(0);
	}

}

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void fullscreen()
{
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}
