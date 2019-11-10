#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct drop {
	 int data;
    struct drop *next;
};
typedef struct drop drop;

drop *createdrop(void);
void tambahAwal(drop **head);
void tambahData(drop **head);
void tranverse(drop *head);
void insertdrop(drop **head, drop *pPre, drop *pNew);
void deletedrop(drop **head, drop *pPre, drop *pCur);
void hapusData(drop **head);
//============
void deleteList(drop *head);
void jumlahData(drop *head);
void hapusAkhir(drop **head);
void hapusAwal(drop **head);
void tambahAkhir(drop **head);

int main(){
	drop *head;
	int pilih;
	int ulang = 0;  
  	head = NULL;
	while(ulang==0){
		system("cls");
    	printf("masukkan pilihan\n");
    	printf("1. Tambah data di awal\n");
    	printf("2. Tambah data di tengah list\n");
    	printf("3. Hapus data\n");
    	printf("4. Cetak isi list\n");
    	printf("5. Jumlah semua data\n");
    	printf("6. Hapus data di awal list\n");
    	printf("7. Hapus data di akhir list\n");
    	printf("8. Tambah data di akhir\n");
    	printf("MASUKKAN PILIHAN (tekan 0 untuk keluar) : ");
    	fflush(stdin);
    	scanf("%d", &pilih);
		switch(pilih){
			case 1:
				tambahAwal(&head);
				break;
			case 2:
				tambahData(&head);
				break;
			case 3:
				hapusData(&head);
				break;
			case 4:
				tranverse(head);
	        	getch();
				break;
			case 5:
				jumlahData(head);
	    		getch();
				break;
			case 6:
				hapusAwal(&head);
				getch();
				break;
			case 7:
				hapusAkhir(&head);
		 		getch();
				break;
			case 8:
				tambahAkhir(&head);
				break;
			case 0:
				ulang=1;
				deleteList(head);
			default:
				break;
		}
	} 
}
drop *createdrop(void){
  drop *ptr;

  ptr = (drop *)malloc(sizeof(drop));
  return(ptr);
}
	 //tranverse
void tambahAwal(drop **head){
	int bil;
	drop *pTemp;
	system("cls");
	fflush(stdin);
	printf("Masukkan bilangan (int) : ");
	fflush(stdin);
	scanf("%d", &bil);
  	pTemp = (drop *)malloc(sizeof(drop));

  	if (pTemp != NULL){
		pTemp->data = bil;
      	pTemp->next = NULL;
      	insertdrop(head, NULL, pTemp);
  	}
  	else{
		printf("Alokasi memori gagal");
	    getch();
  	}
}

void tambahData(drop **head){
  int pos, bil;
  drop *pTemp, *pCur;

  system("cls");
  
  tranverse(*head);
  printf("\nPosisi penyimpanan setelah data bernilai : ");
  fflush(stdin);
  scanf("%d", &pos);
  printf("\nData yang disisipkan : ");
  fflush(stdin);
  scanf("%d", &bil);

  pCur = *head;
  while (pCur != NULL && pCur -> data != pos) {
    pCur = pCur -> next;
  }
  pTemp = (drop *)malloc(sizeof(drop));

  if (pCur == NULL){
     printf("\ndrop tidak ditemukan");
     getch();
  }
  else if (pTemp == NULL){
     printf("\nalokasi memeori gagal");
     getch();
  }
  else{
     pTemp->data = bil;
     pTemp->next = NULL;
     insertdrop(head, pCur, pTemp);
}
}
void tranverse(drop *head){
	//traverse linked list
	drop *pWalker;

	system("cls");
	pWalker = head;
	printf("Hasil : ");
	while (pWalker != NULL){
		printf("%d->", pWalker -> data);
		pWalker = pWalker -> next;
	}
	printf("NULL");
}

void insertdrop(drop **head, drop *pPre, drop *pNew){
	if (pPre == NULL){
   		//menambahkan diawal atau pada empty list
    	pNew -> next = *head;
   		*head = pNew;
	}
	else {
	   	//menambahkan drop di tengah atau di akhir
   		pNew -> next = pPre -> next;
   		pPre -> next = pNew;
	}
}

void deletedrop(drop **head, drop *pPre, drop *pCur){
	if (pPre == NULL)
		*head = pCur -> next;
	else
		pPre -> next = pCur -> next;
	free(pCur);
}

void hapusData(drop **head){
	int pos;
	drop *pCur, *pPre;

	//clrscr();
	system("cls");
	

tranverse(*head);
	printf("\nData yang akan dihapus : ");
	fflush(stdin);
	scanf("%d", &pos);

	pPre = NULL;
	pCur = *head;
	//cari target value sampai ditemukan atau sampai pada akhir list
	while (pCur != NULL && pCur -> data != pos) {
		pPre = pCur;
		pCur = pCur -> next;
	}

	if (pCur == NULL){
		printf("\ndrop tidak ditemukan");
		getch();
	}
	else
		deletedrop(head, pPre, pCur);
}

void deleteList(drop *head){
	drop *pTemp;
  	while(head != NULL){
		pTemp = head;
		head = head->next;
		free(pTemp);
  	}
}
//=====================baru===========
void jumlahData(drop *head){
   //jumlah data input linked list
	drop *pWalker;
	int jumlah=0;
    system("cls");
	pWalker = head;
	while (pWalker != NULL){
   	printf("%d->", pWalker -> data);
   	jumlah=jumlah + pWalker -> data;
   	pWalker = pWalker -> next;
	}
   printf("NULL");
   printf("\n Jumlah : %d",jumlah);
}

void hapusAwal(drop **head){
	drop *hapus;
	system("cls");
	if(*head == NULL){
		printf("Data Kosong lol");
		getch();
		return;
	}
	hapus=*head;
	*head = hapus->next;
	free(hapus);
	tranverse(*head);
}

void hapusAkhir(drop **head){
	drop *hapus,*temp;
	system("cls");
	if(*head == NULL){
		printf("Data Kosong :) ");
		getch();
		return;
	}
	hapus = *head;
	temp = NULL;
	while(hapus -> next != NULL){
		temp = hapus;
		hapus = hapus -> next;
	}
	free(hapus);
	temp -> next = NULL;
	tranverse(*head);
}

void tambahAkhir(drop **head){
	drop *tambah,*pTemp;
	int bil;
	system("cls");
	tambah = *head;
	pTemp = NULL;
	fflush(stdin);
  	printf("Masukkan bilangan (int) : ");
  	fflush(stdin);
  	scanf("%d", &bil);
  	pTemp = (drop *)malloc(sizeof(drop));
  	if (pTemp == NULL){
	  	    printf("\nalokasi memeori gagal");
		    getch();
		    return ;
	}
  	//Awal
  	if(*head == NULL){
		 pTemp->data = bil;
	     pTemp->next = NULL;
	     insertdrop(head, NULL, pTemp);
	}
	//Akhir
	else {
		while(tambah != NULL && tambah -> next != NULL){
			tambah = tambah -> next;
		}
		     pTemp->data = bil;
		     pTemp->next = NULL;
		     insertdrop(head, tambah, pTemp);
	}	
}
