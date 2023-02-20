#include <stdio.h>
#include <stdlib.h>

int com = 0; int cop = 0;

void merge (int *a, int n) {
    if (n < 2) return;
    int mid = n / 2;

    merge(a, mid);
    merge(a + mid, n - mid);

 
    int *c = (int*)malloc (n * sizeof(int));
    
    int i = 0;
    int j = mid;
    int k = 0;
    for (i = 0, j = mid; i < mid && j < n; k++){
      if (a[i] < a[j]) c[k] = a[i++];
      else c[k] = a[j++];
     com++;
     cop++;
}
    while (i < mid) {c[k++] = a[i++];
    cop++;
    }
    while (j < n) {c[k++] = a[j++];
    cop++;
    }
         for (int i = 0; i<n; i++)
          {a[i] = c[i];
              cop++;}

}
    int main(){
        int N = 0;
        int p;
        int i;
        int* a = NULL;
        
        printf("Enter N:");
        scanf("%d", &N);
        
        a = (int*)malloc (N * sizeof(int));
  
        printf("1-best case, 2-middle case, 3-worst case");
        scanf("%d", &p);
        
        if(p==1){
            for(i=0; i<N; i++)
            a[i]=i+1;
            }
        if(p==2){
            for (int i = 0; i<N; i++)
              a[i] = rand() % 1000;
            }
        if(p==3){
            for(i=0; i<N; i++)
            a[i]=N-i;
            }
        
  
  merge(a, N);
        
        
        printf("\n");
        printf("number of comparisons %d and copies %d", com, cop);
      printf("\n");
      getchar();
      return 0;
}
