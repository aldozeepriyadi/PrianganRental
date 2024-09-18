typedef struct {
	int tgl, bulan, tahun;
} Date;

typedef struct {
	int tgl, bulan, tahun, hour, min, sec;
} DateTime;


typedef struct{
	int Id;
	int Mobil;
	char NIK[50];
	char Nama[50];
	char Nosim[50];
	Date tglambil,tglkembali;
	DateTime tglmasuk,tglkeluar;
	int Lamasewa;
	int Idsupir;
	int TotalHarga;
	char status[50];
	
}transaksi;

transaksi rent1,rent2;
Date tgl1;

FILE *arstransaksi;
FILE *temptransaksi;

void booking();
void pengembalian();
void pengambilan();

void booking(){
  char formattedID[5],id [5],harga [25],pilih,tgl1[50],tgl2[50],text[255],nama[20],NIK[16];
  int x,y,trID, intID,idsup,hargaSupir,bayar,lamasewa,i,j,tagihantambahan;
  tgl1 TglPesan,Tglmobil,TglAmbil,Tglkembali,Nowdate,TglSupir;
  
  transaksi:
  	arstransaksi=fopen("arstransaksi.dat","rb");
  	if(arstransaksi!=NULL){
  		while(!feof(arstransaksi)){
  			fflush(stdin);
  			fread(&rent1.Id,sizeof(rent1),1,arstransaksi);
		  }
		  trID = rent1.Id+1;
	  } else{
	  	trID = 1;
	  }
	  fclose(arstransaksi);
	  
	  
	  /* input tanggal pengambilan */
   
   	inputtgl:
   	    DateTime(&Now)
	
	  
}

