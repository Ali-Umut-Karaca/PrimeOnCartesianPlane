#include <stdio.h>
#include <stdlib.h>


enum boolean {False = 0, True = 1};
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"


void emptyFunction(){

int size = 10;
char arr [size][size];
for(int i = 0; i<size; i++){
    for(int j = 0;j<size;j++){
        if (i %2 == 0){
        arr[j][i] = 'a';
        printf("%c",arr[i][j]); 
        }
        else if(j%2 == 0){
        arr[i][j] = 'k';
        printf("%c",arr[i][j]); 
        }
        else
        arr[j][i] = 'b';
        printf("%c",arr[i][j]); 
     }
     printf("\n");
}       

}





enum boolean checkIfPrime(int num){
    int p = 2;
    if(num == 0 || num == 1)
    return False;

    while(p<=num){
    enum boolean determinant = (p<num);
    int en = num % p;
    if(en == 0 && determinant){
        return False;
        }
    else if(en == 0 && !determinant){
        return True;
    }
    else{
        p++;
    }
    }
}
typedef struct Origin{

    int X;
    int Y;

} Origin;

// Parameters: (origin, origin->y, 0)
Origin *primeReturner(Origin *origin, int i, int decider, int size){
    if(i<size){
        
    int SNAPSHOT = origin->Y;
        if(checkIfPrime(i) && decider == 0){
            printf("orX-> %d\n",i);
            origin->X = i;
            decider++;
        }
        else if(checkIfPrime(i) && decider== 1){
            printf("orY-> %d\n",i);
            origin ->Y = i;
            decider--;
        }
        i++;
        if(SNAPSHOT != origin->Y){
            return origin;
        }
        else{
            return origin = primeReturner(origin,i,decider,size);
        }
        
    }
    else{
       // printf("Out Of Bounds Exception Handling\n");
        return origin;
    }
}



void printGrid(int **arr, int size){
for(int i = 0; i<size;i++){
    for(int j = 0;j<size;j++){
        if(arr[i][j] != 0){
            printf(ANSI_COLOR_RED " %d " ANSI_COLOR_RESET,arr[i][j]);
        }
        else{
        printf(" %d ",(char) arr[i][j]);
        }   
    }
    printf("\n");
    }

}



void primeGridPlacer(Origin *origin, int **arr, int size){
// Initiailze the Double Array:     
//S:
    arr = (int**)malloc(size*sizeof(int*));
   for(int i = 0;i<size;i++){
    arr[i] = (int*) malloc(size * sizeof(int));
   }
    printf("BP1\n");
//E
// Populate the array using 0's: 
//S:
for(int i = 0; i<size;i++){
    for(int j = 0; j<size; j++){
        arr[i][j] = 0;
    }
}
// Insert the Prime numbers inside of the Cartesian plane:
//S:
for(int k = 0; k<size; k++){
    origin = primeReturner(origin,origin->Y,0, size);
        arr[origin->X][origin->Y] = 1; 
}
printGrid(arr,size);
//E
printf("BP4");
}


int primeCounter(int num){
    int cnt;
    int p = 2;
    if(num == 0 || num == 1)

    while(p<=num){
    enum boolean determinant = (p<num);
    int en = num % p;
    if(en == 0 && determinant){
        }
    else if(en == 0 && !determinant){
        cnt++;
    }
    else{
        p++;
    }
    }
    return cnt;
}

int main(void){
setbuf(stdout, NULL);
/*
int MAX_NUM;
printf("Enter the Number you would like to search to\n");
scanf("%d",&MAX_NUM);
for (int i = 0; i<MAX_NUM; i++){
    if((i%100) == 0){
        printf("\n");
        if(checkIfPrime(i)){
            printf("--> %d",i);
        }
    }
       // printf("ThisIsWhereNewLine");
    else{
        if(checkIfPrime(i)){
            printf("--> %d",i);
        }
    }
}
    
    //printf("\ni: %d --> %d",i, checkIfPrime(i));
*/
int **arr;
int size = 400;
Origin *origin = malloc(sizeof(Origin));
origin->X = 0;
origin->Y = 0;
/*for(int i = 0; i<size; i++){
origin = primeReturner(origin, origin->Y,0);
printf("i: %d --> origin X-> %d, Y-> %d\n",i,origin->X,origin->Y);
    }*/
primeGridPlacer(origin, arr, size);
printf("BP5");
return 0;

}
