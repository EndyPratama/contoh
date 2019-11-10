#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct coba {
	int data;
	struct coba *next;
};
typedef struct coba coba;

coba *createNode(void);
void TambahAwal(coba **head);
void List(coba *head);
void deleteList(coba *head);
void insertNode(coba **head, coba *pPre, coba *pNew);

int main(){
	coba *head;
	int pilih;
	
	head = NULL;
	int ulang=0;
	while(ulang==0){
		printf("Menu\n");
		printf("1. Tambah Data\n");
		printf("2. Cetak List\n");
		printf("Masukkan Pilihan : ");
		scanf("%d",pilih);
		if(pilih==1){
			TambahAwal(&head);
		}
		else if(pilih==2){
			List(head);
		}
		else{
			ulang=1;
		}
	}
	deleteList(head);
}
coba *createNode(void){
  coba *ptr;

  ptr = (coba *)malloc(sizeof(coba));
  return(ptr);
}

void TambahAwal(coba **head){
  int bil;
  coba *pTemp;
  //system("cls");
  fflush(stdin);
  printf("masukkan bilangan integer : ");
  fflush(stdin);
  scanf("%d", &bil);
  pTemp = (coba *)malloc(sizeof(coba));

  if (pTemp != NULL){
  		pTemp->data = bil;
      pTemp->next = NULL;
      insertNode(head, NULL, pTemp);
  }
  else{
      printf("Alokasi memori gagal");
      getch();
  }
}

void List(node *head){
	node *pWalker;

    system("cls");
	pWalker = head;
	while (pWalker != NULL){
   		printf("%d->", pWalker -> data);
   		pWalker = pWalker -> next;
	}
   printf("NULL");
}

void deleteList(node *head){
  node *pTemp;


  while(head != NULL){
     pTemp = head;
     head = head->next;
     free(pTemp);
  }
}
