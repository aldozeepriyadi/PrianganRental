void masterUser();
void tambahUser();
void ubahUser();
void hapusUser();
void bacaUser();

void masterUser(){
	//persiapan
	system("cls");
	frameutama(identitas);
	
	//keterangan
	printf("\t\t\t\t<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>");
	printf("\n\t\t\t\t\tMENU > MASTER PEGAWAI						   ");
	
	bacaUser();
	printf("\n\n\t\t\t\t\tPilih Menu : ");
	printf("\n\t\t\t\t\tMaster Pegawai");
	printf("\n\t\t\t\t\t1. Kembali");
	printf("\n\t\t\t\t\t2. Tambah Data");
	printf("\n\t\t\t\t\t3. Ubah Data");
	printf("\n\t\t\t\t\t4. Hapus Data");
	
	printf("\n\t\t\t\t\tPilihan : ");getnum(&pilihmenu,1); fflush(stdin);
	
	switch(pilihmenu){
		case 1 : MenuAdmin();break;
		case 2 : tambahUser(); break;
		case 3 : ubahUser(); break;
		case 4 : hapusUser(); break;
		default :{
			printf("\n\t\t\t\t\tPilihan tidak tersedia");
			masterUser();
			break;
		}
	}	
}

void tambahUser(){
	
	//persiapan
	system("cls");
	frameutama(identitas);
	found = false;
	dataUser.idUser=0;
	arsUser = fopen("arsip//User//arsUser.dat","ab+");
	tempUser = fopen("arsip//User//tempUser.dat","wb");
	
	
	//keterangan
	printf("\n\t\t\t\t<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>");
	printf("\n\t\t\t\t\tMENU > MASTER PEGAWAI > TAMBAH DATA 		   ");
	printf( "\n\t\t\t\t\t- Nama isi dengan X untuk kembali");
	
	printf("\n\t\t\t\t\tPilihan Role : ");
	printf("\n\t\t\t\t\t1. Admin");
	printf("\n\t\t\t\t\t2. Kasir");
	printf("\n\t\t\t\t\t3. Manajer");

	fread(&dataUser,sizeof(dataUser),1,arsUser);
	while(!found && !feof(arsUser)){
		if(strcmp(dataUser.namaUser,"kosong")==0 && strcmp(dataUser.username,"kosong")==0 && strcmp(dataUser.password,"kosong")==0 && strcmp(dataUser.jabatan,"kosong")==0){
		
			printf("\n\t\t\t\t\tTAMBAH DATA");
			printf("\n\t\t\t\t\tID Pegawai : "); printf("PG%d",dataUser.idUser);
			printf("\n\t\t\t\t\tNama Pegawai : ");getteks(dataUser.namaUser,20);fflush(stdin);	
				if(strcmp(dataUser.namaUser,"X")==0){
					fclose(arsUser);
					fclose(tempUser);
					masterUser();	
				}
				
			printf("\n\t\t\t\t\tUsername : ");getteks(dataUser.username,20);fflush(stdin);
			printf("\n\t\t\t\t\tPassword : ");getteks(dataUser.password,20);fflush(stdin);
			do{
		
				printf("\n\t\t\t\t\tJabatan : ");getteksnum(dataUser.jabatan,1);fflush(stdin);
				if(strcmp(dataUser.jabatan,"1")==0){
					found = true;
					strcpy(dataUser.jabatan,"Admin");
				}else if(strcmp(dataUser.jabatan,"2")==0){
					found = true;
					strcpy(dataUser.jabatan,"Kasir");
				}else if(strcmp(dataUser.jabatan,"3")==0){
					found = true;
					strcpy(dataUser.jabatan,"Manajer");
				}else{
				printf("Jabatan salah!");
				}		
			}while(!found);	
			}
		fwrite(&dataUser,sizeof(dataUser),1,tempUser);
		fread(&dataUser,sizeof(dataUser),1,arsUser);
	}
	
	if(!found){
		dataUser.idUser++;
		printf("\n\t\t\t\t\tID Pegawai : ");printf("PG%d",dataUser.idUser);
		printf("\n\t\t\t\t\tNama Pegawai: ");getteks(dataUser.namaUser,20);fflush(stdin);
		
		if(strcmp(dataUser.namaUser,"X")==0){
			fclose(arsUser);
			fclose(tempUser);
			masterUser();	
		}
		
		printf("\n\t\t\t\t\tUsername : ");getteks(dataUser.username,20);fflush(stdin);
		printf("\n\t\t\t\t\tPassword : ");getteks(dataUser.password,20);fflush(stdin);
		do{
		
			printf("\n\t\t\t\t\tJabatan: ");getteksnum(dataUser.jabatan,1);fflush(stdin);
			if(strcmp(dataUser.jabatan,"1")==0){
				found = true;
				strcpy(dataUser.jabatan,"Admin");
			}else if(strcmp(dataUser.jabatan,"2")==0){
				found = true;
				strcpy(dataUser.jabatan,"Kasir");
			}else if(strcmp(dataUser.jabatan,"3")==0){
				found = true;
				strcpy(dataUser.jabatan,"Manajer");
			}else{
				printf("\n\t\t\t\t\tJabatan salah!");
			}	
				
		}while(!found);
		fwrite(&dataUser,sizeof(dataUser),1,arsUser);
		fclose(arsUser);
		fclose(tempUser);
		
	}else{
		while(!feof(arsUser)){
			fwrite(&dataUser,sizeof(dataUser),1,tempUser);
			fread(&dataUser,sizeof(dataUser),1,arsUser);
		}
		
		fclose(arsUser);
		fclose(tempUser);
		
		arsUser = fopen("arsip//User//arsUser.dat","wb");
		tempUser = fopen("arsip//User//tempUser.dat","rb");
		
		fread(&dataUser,sizeof(dataUser),1,tempUser);
		while(!feof(tempUser)){
		fwrite(&dataUser,sizeof(dataUser),1,arsUser);
		fread(&dataUser,sizeof(dataUser),1,tempUser);
		}
		fclose(arsUser);
		fclose(tempUser);
	}
	
	
	tempUser = fopen("arsip//User//tempUser.dat","wb");
	
	fclose(tempUser);
	printf("\n\t\t\t\t\tData Telah Ditambahkan");
	fclose(arsUser);
	masterUser();
}


void ubahUser(){
	//persiapan
	system("cls");
	frameutama(identitas);

	found = false;
	arsUser = fopen("arsip//User//arsUser.dat","rb");
	tempUser = fopen("arsip//User//tempUser.dat","wb");
	
	//keterangan
	printf("\n\t\t\t\t<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>");
	printf("\n\t\t\t\t\tMENU > MASTER PEGAWAI > UBAH DATA			   ");
	printf("\n\t\t\t\t\t- ID isi dengan 0 untuk kembali");

	printf("\n\t\t\t\t\t- Pilihan Role : ");
	printf("\n\t\t\t\t\t1. Admin");
	printf("\n\t\t\t\t\t2. Kasir");
	printf("\n\t\t\t\t\t3. Manager");
	
	printf("\n\t\t\t\t\tID Pegawai : "); printf("PG"); 
	//inputan
	getnummin(&cari,1,3); fflush(stdin);
	if(cari == 0){
		fclose(arsUser);
		fclose(tempUser);
		masterUser();
	}
	
	fread(&dataUser,sizeof(dataUser),1,arsUser);
	while(!feof(arsUser)){
		if(cari == dataUser.idUser && strcmp(dataUser.namaUser,"kosong")!=0 && strcmp(dataUser.username,"kosong")!=0 && strcmp(dataUser.password,"")!=0 && strcmp(dataUser.jabatan,"kosong")!=0){
			//form data awal
			printf("\n\t\t\t\t<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>");
			printf("\n\t\t\t\t\tDATA ASAL");
			printf("\n\t\t\t\t\tNama Pegawai : ");printf("%s",dataUser.namaUser);
			printf("\n\t\t\t\t\tUsername : "); printf("%s",dataUser.username);
			printf("\n\t\t\t\t\tPassword : "); printf("%s",dataUser.password);
			printf("\n\t\t\t\t\tJabatan : "); printf("%s",dataUser.jabatan);
			
			//form data akhir
			printf("\n\t\t\t\t<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>");
			printf("\n\t\t\t\t\tDATA UBAH");
			printf("\n\t\t\t\t\tID Pegawai : "); printf("PG%d",dataUser.idUser);
			printf("\n\t\t\t\t\tNama Pegawai : ");
			getteks(dataUser.namaUser,20);fflush(stdin);
			printf("\n\t\t\t\t\tUsername : ");
			getteks(dataUser.username,20);fflush(stdin);
			printf("\n\t\t\t\t\tPassword : ");
			getteks(dataUser.password,20);fflush(stdin);
		
			do{
		
				printf("\n\t\t\t\t\tJabatan : ");getteksnum(dataUser.jabatan,1);fflush(stdin);
				if(strcmp(dataUser.jabatan,"1")==0){
					found = true;
					strcpy(dataUser.jabatan,"Admin");
				}else if(strcmp(dataUser.jabatan,"2")==0){
					found = true;
					strcpy(dataUser.jabatan,"Kasir");
				}else if(strcmp(dataUser.jabatan,"3")==0){
					found = true;
					strcpy(dataUser.jabatan,"Manager");
				}else{
					printf("\n\t\t\t\t\tJabatan salah!");
				}	
			}while(!found);
		}
		fwrite(&dataUser,sizeof(dataUser),1,tempUser);
		fread(&dataUser,sizeof(dataUser),1,arsUser);
	}
	fclose(arsUser);
	fclose(tempUser);
	
	if(found){
		
		//validasi
		do{
			printf("\n\t\t\t\t\tUbah Data (y/t) : "); getteks(keputusan,1); fflush(stdin);
		}while(!((strcmp(keputusan,"y")==0 || strcmp(keputusan,"Y")==0 ) || (strcmp(keputusan,"t")==0 || strcmp(keputusan,"T")==0)));
		if(strcmp(keputusan,"t")==0 || strcmp(keputusan,"T")==0 ){
		ubahUser();
		}
		
		
		arsUser = fopen("arsip//User//arsUser.dat","wb");
		tempUser = fopen("arsip//User//tempUser.dat","rb");
		
		fread(&dataUser,sizeof(dataUser),1,tempUser);
		while(!feof(tempUser)){
		fwrite(&dataUser,sizeof(dataUser),1,arsUser);
		fread(&dataUser,sizeof(dataUser),1,tempUser);
		}
		fclose(arsUser);
		fclose(tempUser);
		printf("\n\t\t\t\t\tData Telah Diubah");
	}else{
		printf("\n\t\t\t\t\tData Tidak Ditemukan");	
	}
	tempUser = fopen("arsip//User//tempUser.dat","wb");
	fclose(tempUser);
	masterUser();	
}

void hapusUser(){
	//persiapan
	system("cls");
	frameutama(identitas);

	found = false;
	arsUser = fopen("arsip//User//arsUser.dat","rb");
	tempUser = fopen("arsip//User//tempUser.dat","wb");
	
	//keterangan
	printf("\n\t\t\t\t<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>");
	printf("\n\t\t\t\t\tMENU > MASTER PEGAWAI > HAPUS DATA 		   	   ");
	printf("\n\t\t\t\t\t- ID isi dengan 0 untuk kembali");
	
	//inputan
	printf ("\n\t\t\t\t\tID Pegawai : ");printf("PG");getnummin(&cari,1,3);
	if(cari == 0){
		fclose(arsUser);
		fclose(tempUser);
		masterUser();
	}
	
	fread(&dataUser,sizeof(dataUser),1,arsUser);
	while(!feof(arsUser)){
		if(cari == dataUser.idUser && strcmp(dataUser.namaUser,"kosong")!=0 && strcmp(dataUser.username,"kosong")!=0 && strcmp(dataUser.password,"")!=0 && strcmp(dataUser.jabatan,"kosong")!=0){
			
			printf("\n\t\t\t\t\tNama Pegawai : "); printf("%s",dataUser.namaUser);
			printf("\n\t\t\t\t\tUsername : "); printf("%s",dataUser.username);
			printf("\n\t\t\t\t\tPassword : "); printf("%s",dataUser.password);
			printf("\n\t\t\t\t\tJabatan : "); printf("%s",dataUser.jabatan);
			
			strcpy(dataUser.namaUser,"kosong");
			strcpy(dataUser.username,"kosong");
			strcpy(dataUser.password,"kosong");
			strcpy(dataUser.jabatan,"kosong");
			found = true;
		}
		fwrite(&dataUser,sizeof(dataUser),1,tempUser);
		fread(&dataUser,sizeof(dataUser),1,arsUser);
	}
	fclose(arsUser);
	fclose(tempUser);
	

	if(found){
		
		//validasi
		do{
			printf("\n\t\t\t\t\tHapus Data (y/t) : "); getteks(keputusan,1); fflush(stdin);
		}while(!((strcmp(keputusan,"y")==0 || strcmp(keputusan,"Y")==0 ) || (strcmp(keputusan,"t")==0 || strcmp(keputusan,"T")==0)));
		if(strcmp(keputusan,"t")==0 || strcmp(keputusan,"T")==0 ){
		masterUser();
		}
		
		
		arsUser = fopen("arsip//User//arsUser.dat","wb");
		tempUser = fopen("arsip//User//tempUser.dat","rb");
		
		fread(&dataUser,sizeof(dataUser),1,tempUser);
		while(!feof(tempUser)){
		fwrite(&dataUser,sizeof(dataUser),1,arsUser);
		fread(&dataUser,sizeof(dataUser),1,tempUser);
		}
		fclose(arsUser);
		fclose(tempUser);
		printf("\n\t\t\t\t\tData Telah Dihapus");
	}else{
		printf("\n\t\t\t\t\tData Tidak Ditemukan");	
	}
	tempUser = fopen("arsip//User//tempUser.dat","wb");
	fclose(tempUser);
	masterUser();
}

void bacaUser(){
	//persiapan
	arsUser = fopen("arsip//User//arsUser.dat","rb");
	int j;
	
	printf("\n\t\t\t\t<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>");
	printf("\n\t\t\t\t\tDATA USER									   ");
	
	fread(&dataUser,sizeof(dataUser),1,arsUser);
	while(!feof(arsUser)){
		if(strcmp(dataUser.namaUser,"kosong")!=0 && strcmp(dataUser.username,"kosong")!=0 && strcmp(dataUser.password,"kosong")!=0 && strcmp(dataUser.jabatan,"kosong")!=0){
		
		printf("\n\t\t\t\t\tID : "); printf("PG%d",dataUser.idUser);
		printf("\n\t\t\t\t\tNama User : "); printf("%s",dataUser.namaUser);
		printf("\n\t\t\t\t\tUsername : "); printf("%s",dataUser.username);
		printf("\n\t\t\t\t\tJabatan : "); printf("%s",dataUser.jabatan);
		j++;
		}
	fread(&dataUser,sizeof(dataUser),1,arsUser);
	}

	fclose(arsUser);
}
