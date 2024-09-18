#ifndef loginSignUp

#define ENTER 13
#define TAB 9
#define BCKSPC 8

// STRUCT DECLARATION

struct user
{
    int No;
    char namaLengkap[50];
    char password[50];
    char phone[50];
    char role[50];
};

void takeInput(char ch[50])
{
    fgets(ch, 50, stdin);
    ch[strlen(ch) - 1] = 0;
}

void takePassword(char pwds[50])
{
    // manager@gmail.com - manager
    // admin@gmail.com - admin
    // customer@gmail.com - customer

    int is;
    char chs;
    while(1)
    {
        chs = getch();
        if (chs == ENTER || chs == TAB)
        {
            pwds[is] = '\0';
            break;
        } else if (chs == BCKSPC)
        {
            if (is > 0)
            {
                is--;
                printf("\b \b");
            }
        } else
        {
            pwds[is++] = chs;
            printf("* \b");
        }
    }
}

void LoginForm()
{
    FILE *fp, *ek;

    int opt, usrFound = 0, id;
    struct user user;

    OutterBorder();
	BersihKanan();
	BersihKiri();

    gotoxy(7,14); printf("Menu Login & Sign Up");
    gotoxy(10,16); printf("Pilih Opsi: \n");
    gotoxy(10,17); printf("1. Buat Akun");
    gotoxy(10,18); printf("2. Login");
    gotoxy(10,19); printf("3. Keluar");
    gotoxy(10,20); printf("Pilihan Opsi: \t");

    gotoxy(12,22); printf("["); gotoxy(16,22);	printf("]");
    gotoxy(14,22); scanf("%d", &opt);
    fgetc(stdin);

    switch(opt)
    {
        case 1:
            ek = fopen("database/users.dat", "rb");

            fread(&user, sizeof(user), 1, ek);
            while(!feof(ek))
            {
                fread(&user, sizeof(user), 1, ek);
                id = user.No;
            }

            fclose(ek);
            user.No = id + 1;

            gotoxy(90,25);	printf("Buat Akun");

            gotoxy(60,27); printf("Masukan Nama Lengkap: ");
            takeInput(user.namaLengkap);

            gotoxy(60,29); printf("Masukan Password: ");
            takePassword(user.password);

            gotoxy(60,31); printf("Masukan No Telepon: ");
            takeInput(user.phone);

            strcpy(user.role, "0");

            fp = fopen("database/users.dat", "ab");
            fwrite(&user, sizeof(struct user), 1, fp);
            if (fwrite != 0)
            {
                gotoxy(60,33); printf("Akun sudah berhasil dibuat, tekan apapun untuk melanjutkan...");
                fclose(fp);

                getch();
                system("cls");
                LoginForm();
            }
        break;

        case 2:;
            char email[50], pword[50];
            struct user usr;

            gotoxy(90,25);	printf("Login");

            gotoxy(60,27);printf("Masukan No Telepon: ");
            takeInput(email);

            gotoxy(60,29);printf("Masukan Password Anda: ");
            takePassword(pword);

            fp = fopen("database/users.dat", "rb");
            while (fread(&usr, sizeof(struct user), 1, fp))
            {
                if (!strcmp(usr.phone, email))
                {
                    if (!strcmp(usr.password,pword))
                    {
                        char manager[50];
                        char admin[50];
                        char customer[50];
                        char noRole[50];

                        strcpy(manager, "Manager");
                        strcpy(admin, "Admin");
                        strcpy(customer, "Customer");
                        strcpy(noRole, "0");

                        if (!strcmp(usr.role, manager))
                        {

                            gotoxy(60,31);printf(" Login Berhasil, tekan apapun untuk melanjutkan...\n");
                            getch();

                            ManagerMainMenu();
                        } else if (!strcmp(usr.role, admin))
                        {
                            gotoxy(60,31);printf(" Login Berhasil, tekan apapun untuk melanjutkan...\n");
                            getch();

                            AdminMainMenu();
                        } else if (!strcmp(usr.role, customer))
                        {
                            gotoxy(60,31);printf(" Login Berhasil, tekan apapun untuk melanjutkan\n");
                            getch();

                            CustomerMainMenu();
                        } else if (!strcmp(usr.role, noRole))
                        {
                            gotoxy(60,31);printf("Akun belum di verifikasi...\n");
                            Beep(800,300);

                            getch();
                            system("cls");
                            LoginForm();
                        }
                    } else
                    {
                        gotoxy(60,31);printf("Password salah! Tekan apapun untuk melanjutkan...\n");
                        Beep(800,300);

                        getch();
                        system("cls");
                        LoginForm();
                    }
                    usrFound = 1;
                }
            }

            if (!usrFound)
            {
                gotoxy(60,31);printf("User tidak terdaftar! Tekan apapun untuk melanjutkan...\n");
                Beep(800,300);
                fclose(fp);

                getch();
                system("cls");
                LoginForm();
            }
            break;

        case 3:
            gotoxy(60,31);printf("Terimakasih sudah menggunakan aplikasi ini :)\n");
            return 0;

        default:
            gotoxy(60,31); printf("Angka tidak sesuai, tekan untuk melanjutkan....\n");
            getch();

            system("cls");
            LoginForm();
    }

    return 0;
}

void WelcomeScreen() // function for welcome screen
{
    PrintFile ("title/title4.txt", 48,6);
}

/* ********* TITLE SCREEN ********* */

void Title()
{
    printf("\n DiDo Rent Car\n");
}

#define loginSignUp
#endif // loginSignUp
