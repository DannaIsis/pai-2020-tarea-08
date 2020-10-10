#ifndef HEAP_T08
#define HEAP_T08

// Prototipos =================================================================

typedef struct _THeap{
  int size;
}THeap;

THeap * THeap_new(void);
void    free_THeap(THeap ** hptr);

void    insert(THeap *h, int data);
int     removeMax(THeap *h);
int     getMax(THeap *h);

void    bottomUpHeapify(int *arr, int k);
void    topDownHeapify(int * arr, int k, int n);

// Definiciones ===============================================================

void insert(THeap *h, int data){ 
  return;
} 

int removeMax(THeap *h){ 
  return -1;
} 

int getMax(THeap *h){ 
  return -1;
} 

void bottomUpHeapify(int *arr, int k){ 
  return;
} 

void topDownHeapify(int * arr, int k, int n){
  return;
} 

#endif
