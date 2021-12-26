//=======================================================================//
//*********** Fungsi Untuk Menampilkan Konfirmasi Pemesanan *************//
//=======================================================================//
// Nama Fungsi    : konfirmasiPemesanan                                  //
// Input Argumen  : int kembali                                          //
//                  char benar                                           //
// Output Argumen : char bank [20]                                       //
//                  int noRekening                                       //
//                  int jumlahTransfer                                   //
//                  char idInvoice [20]                                  //
//                  char nama [60]                                       //
//                  char nohp [20]                                       //
// Deskripsi      : Fungsi ini digunakan untuk menampilkan daftar        //
//                  transaksi yang lunas dengan mengkonfirmasi pembayaran//
//                  yang telah dilakukan oleh customer.                  //
// Dibuat Oleh    : Puja - 2105551016                                    //
//                                                                       //
// Versi : 1.0                                     Rev. 0                //
// Tgl   : 18-12-2021                              Tgl: -                //
//=======================================================================//
void konfirmasiPemesanan (void){
	konfirmasiPemesanan:
	system("cls");
	int kembali;
	char benar;
    FILE * fpointerkuitansiCostumer;
    fpointerkuitansiCostumer=fopen(pengguna.nama, "r");
    if(fpointerkuitansiCostumer!=NULL){
		printf("\t\t\t\t\tHistory Pemesanan\n");
		char buff[255];
    	while(fgets(buff, sizeof(buff), fpointerkuitansiCostumer)){
    		printf("%s ",buff);
    	}
    fclose(fpointerkuitansiCostumer);
    	printf("[1] Konfirmasi Pembayaran\n");
    	printf("[2] Kembali\n\n");
    	int pilihKonfirmasi;
	   	printf("pilih                               : ");
	    scanf("%d",&pilihKonfirmasi);
	    if (pilihKonfirmasi==1){
	    	konfirmasi:;
	        char bank[20];
	        int noRekening;
	        int jumlahTransfer;
	        char idInvoice[20];
	        char nama[60];
	        char nohp[20];

	        printf("Bank                                : "); fflush(stdin);
	        gets(bank);
	        printf("No Rekening Anda                    : "); fflush(stdin);
	        scanf("%d", &noRekening);
	        printf("Atas Nama                           : "); fflush(stdin);
	        gets(nama);
	        printf("Jumlah Transfer                     : "); fflush(stdin);
	        scanf("%d", &jumlahTransfer);
	        printf("Apakah Data Anda Sudah Benar? (y/n) : \n");
	       	getchar();
	       	benar = getchar();
	        if(benar=='y'||benar=='Y'){
		        printf("----------------------------------------------------------------------------");
		        printf("\nTerimakasih Pesanan Anda Sedang Kami Cek\n\n");
		        cekPembayaran(bank, noRekening, nama, jumlahTransfer);
		        system("pause");
		        menuPelanggan();
		    }
		    else{
		    	printf("\n\nKonfirmasi Telah Dibatalkan !\n\n");
		    	goto konfirmasiPemesanan;
		    }
	    }
	    else if(pilihKonfirmasi==2){
	        menuPelanggan();
	    }
	    else{
	        inputSalah();
	        goto konfirmasiPemesanan;
	    }
    }

    else{
    	printf("\n\n\nAnda Belum Melakukan Pemesanan Apapun\n\n\n");
    	getch();
    	menuPelanggan();
    }

}
