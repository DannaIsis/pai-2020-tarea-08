#ifndef HEAP_T08
#define HEAP_T08

// Prototipos =================================================================

typedef struct _THeap{
 	unsigned int capacity;
	int n;
	int *data;
}THeap;

THeap * THeap_new(unsigned int cpt);
void    free_THeap(THeap ** hptr);

void    insert(THeap *h, int data);
int     removeMax(THeap *h);
int     getMax(THeap *h);

void    bottomUpHeapify(int *arr, int k);
void    topDownHeapify(int * arr, int k, int n);

// Definiciones ===============================================================

THeap * THeap_new(unsigned int cpt){
    THeap *new=NULL;
    new=(THeap *)calloc(1,sizeof(THeap));
    if(new!=NULL){
        new->capacity=cpt;
        new->n=0;
        new->data=(int *)calloc(cpt+1,sizeof(int));
    }
    else{
        printf("No se pudo reservar memoria");
    }
    return new;
}

void insert(THeap *h, int data){
  if (h->n==h->capacity-1)
		return;
	h->data[++h->n]=data;
	bottomUpHeapify(h->data,h->n);
  return;
}

int removeMax(THeap *h){
  if (h->n<1)
		return -1;
	int tmp = h->data[1];
	h->data[1]= h->data[h->n--];
	topDownHeapify(h->data,1,h->n);
	return tmp;
}

int getMax(THeap *h){
  if (h->n<1)
    return -1;
  return h->data[1];
}

void bottomUpHeapify(int *arr, int k){
  while (k > 0 && arr[(k+1)/3]<arr[k]) {
		swap(arr ,k, (k+1)/3);
		k=(k+1)/3;
	}
  return;
}

void topDownHeapify(int * arr, int k, int n){
  while(3*k-1 <= n){
		int j = 3*k - 1;//primer nodo hijo
		//Compara con los nodos hijos
		if(j<n && arr[j]<arr[j+1]){// j<n para j++
			j++;
		}
		else if(j<n-1 && arr[j]<arr[j+2]){//j<n-1 para j = j+2
			j += 2;
		}

		//Si el nodo padre es mayor que el nodo hijo mayor, se detiene
		if(arr[k] >= arr[j]) break;
		//Si el nodo padre es menor, los intercambia.
		swap(arr, k, j);
		//Actualiza k con el nodo hijo que acaba de cambiar
		k = j;
	}
}

#endif
