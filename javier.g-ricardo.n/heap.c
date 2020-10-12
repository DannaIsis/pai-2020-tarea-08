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
void    topDownHeapify(int * arr, int k, int n, char ord);

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

void topDownHeapify(int * arr, int k, int n, char ord){
	if(ord == 0){
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
	else{
		while(3*k-1 <= n){
			int j = 3*k - 1;//primer nodo hijo
			//Compara con los nodos hijos
			if(j<n && arr[j]>arr[j+1]){// j<n para j++
				j++;
			}
			else if(j<n-1 && arr[j]>arr[j+2]){//j<n-1 para j = j+2
				j += 2;
			}
			
			//Si el nodo padre es menor que el nodo hijo mayor, se detiene
			if(arr[k] <= arr[j]) break;
			//Si el nodo padre es mayor, los intercambia.
			swap(arr, k, j);
			//Actualiza k con el nodo hijo que acaba de cambiar
			k = j;
		}
	}
}

#endif
