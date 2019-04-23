/* 
Nama 	: Irfan Satrio
NPM		: 140810180003
Tanggal	: 23/04/2019
Kelas	: A
*/

#include <iostream>
using namespace std;

struct sepak {
	int nodaftar;
	char namatim[20];
	char asaldaerah[25];
	int gol;
	sepak* next;
};

typedef sepak* pointer;
typedef pointer list;

void createlist (list& first)
{
	first=NULL;
}
void createElmt (pointer& pBaru)
{
	pBaru = new sepak;
	cout<<"Masukan no Daftar 	: 	"; cin>>pBaru->nodaftar;
	cout<<"Masukan Nama Tim		:	"; cin.ignore(); cin.getline(pBaru->namatim,20);
	cout<<"Masukan Asal Daerah	:	"; cin.getline(pBaru->asaldaerah,25);
}

void insertFirst(list& first, pointer pBaru)
{
	if (first==NULL)
		first=pBaru;
	else {
		pBaru->next=first;
		first=pBaru;
	}
}

void update (list& first)
{
	pointer pBantu;
	pBantu=first;
	while (pBantu != NULL)
	{
		cout<<"Masukan Banyak GOL	: ";cin>>pBantu->gol;
		pBantu=pBantu->next;
	}	
}


void traversal(list First)
{
  pointer pBantu;
  pBantu=First;
  cout<<"NO daftar\t Nama tim\t Asal Daerah\t Gol"<<endl;
  while(pBantu!=NULL)
  {
    cout<<pBantu->nodaftar<<"\t"<<pBantu->namatim<<"\t"<<pBantu->asaldaerah<<"\t"<<pBantu->gol<<endl;
    pBantu=pBantu->next;
  }
}

void traversalBaru(list First){
  pointer pBantu;
  pBantu=First;
  cout<<"NO daftar\tNama tim\tAsal Daerah\tGol"<<endl;
  while(pBantu!=NULL){
    cout<<pBantu->nodaftar<<"\t\t"<<pBantu->namatim<<"\t"<<pBantu->gol<<endl;
    pBantu=pBantu->next;
  }
}

void swap (pointer& a, pointer& b)
{
	int temp = a->gol;
	a->gol = b->gol;
    b->gol = temp;	
}

void sorting(list& First){
     int swapped, i;
     pointer ptr1;
     pointer lptr = NULL;

     if (First == NULL)
         return;

     do{
         swapped = 0;
         ptr1 = First;

         while(ptr1->next!=lptr){
             if (ptr1->gol > ptr1->next->gol){
                 swap(ptr1,ptr1->next);
                 swapped = 1;
             }
             ptr1 = ptr1->next;
         }
         lptr = ptr1;
     } while(swapped);
 }

main(){
  pointer pb;
  list q;
  int n;
  cout<<"Masukan Banyak tim :"; cin>>n;
  createlist(q);
  for(int i=0;i<n;i++){
    createElmt(pb);
    insertFirst(q,pb);
  }
  traversal(q);
  update(q);
  cout<<"\nupdate setelah gol"<<endl;
  sorting(q);
  traversalBaru(q);
}
