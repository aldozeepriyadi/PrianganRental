#define ENTER 13
#define TAB 9
#define BCKSPC 8

void Login();
void gotoxy(int x, int y);

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
	//abc123@gmail.com
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
	printf("========================================================");
	printf("------------- SELAMAT DATANG DI PRIANGAN RENT -------------");
	printf("========================================================");
	printf("\nSilahkan masukkan pilihan");
	printf("\n1. Daftar");
	printf("\n2. Masuk");
	printf("\n3. Keluar");
	
	printf("\n\nPilihan : \t");
	scanf("%d",&opt);
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
			if(strcmp(user.password,password)){
				generateUsername(user.email,user.username);
				fp = fopen("DataLogin.dat","a+");
				fwrite(&user,sizeof (user),1,fp);
			if(fwrite != 0) printf("\n\nRegistrasi data login berhasil, username =  %s",user.username);
				else printf("\n\nSorry! Something went wrong :(");
				Login();
				fclose(fp);

			}
			else{
				printf("\n\nPassword tidak sesuai");
				

			}
		break;
		
		case 2:;
			char email[50],pword[50];
			printf("\nEnter your username:\t");
			takeinput(username);
			printf("Enter your password:\t");
			takepassword(password);


			fp = fopen("DataLogin.dat","rb");
			
			while(fread(&user,sizeof(user),1,fp)){
				if(!strcmp(user.username,username)){
					if(!strcmp(user.password,password)){
						char manager[50];
			            char admin[50];
			            char kasir[50];
			            char noRole [50];
			            strcpy(manager,"Manager");
			            strcpy(admin,"Admin");
			            strcpy(kasir,"Kasir");
			            strcpy(noRole,"0");
			            if(!strcmp(user.fullName,admin))
									{
										printf("Login berhasil","Login sebagai Admin");
										getch();
										MenuAdmin();

									}
								else if (!strcmp(user.fullName,kasir))
								{
								printf("Login berhasil","Login sebagai kasir");
										getch();
										MenuKasir();
									}
							else if (!strcmp(user.fullName,manager))
								{
								printf("\n\nLogin berhasil","Login sebagai Manager");
										getch();
										MenuManager();
									}
							
						
				}
					else {
						printf("\n\nPassword Salah!");
					}
					userFound = 1;
					system("cls");
						printf("\n\t\t\t\t\t\tSelamat Datang %s",user.fullName);
						printf("\n|Job Desk :\t%s",user.fullName);
						printf("\n|Email :\t%s",user.email);
						printf("\n|Username :\t%s",user.username);
						printf("\n");
				}
			}
			
			if(!userFound){
				printf("\n\nAnda belum terdaftar! Silahkan daftar terlebih dahulu.");
				
			}
			
				
			fclose(fp);
			
			
	
		case 3:
			system("cls");
			printf("Selamat Tinggal");
			getche();
	}
	}






void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void fullscreeen()
{
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}
