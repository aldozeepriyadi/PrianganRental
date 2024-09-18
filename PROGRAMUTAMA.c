#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include "Login.h"
#include "MenuUtama.h"
#include "MenuCRUDMobil.h"
#include "MenuCRUDSupir.h"
#include "MenuCRUDKaryawan.h"
#include "lib.h"
#include "Getlib.h"
#include "TransaksiMobil.h"
#include "TransaksiSupir.h"
#include "LaporanMobil.h"
#include "LaporanSupir.h"

main(){
	
	system("color E6");
    fullscreen();
	Login();
	
}
