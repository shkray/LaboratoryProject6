#include <stdio.h>

void vvod(int *n, int *m, int B[20][20]) {
    scanf_s("%d %d", n, m);
    int N = *n;
    int M = *m;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf_s("%d", &B[i][j]);
        }
    }
}

int indexIfBeenBefore(int A[20], int *n, int *element) {
    for (int i = 0; i < *n; i++) {
        if (*element == A[i]) return i;
    }
    return -1;
}

void fillingUpElementsCounterArray(int elementsFromStrokaCounter[20][2], int A[20], int *M) {
    int index;
    for (int j = 0; j < *M; j++) {
        int arrayLength = j;
        index = indexIfBeenBefore(A, &arrayLength, &A[j]);
        elementsFromStrokaCounter[j][0] = A[j];
        elementsFromStrokaCounter[j][1] = 1;
        if (index != -1) {
            elementsFromStrokaCounter[index][1] += elementsFromStrokaCounter[j][1];
            //printf_s("%d %d \n", elementsFromStrokaCounter[index][0], elementsFromStrokaCounter[j][0]);
        }
    }
    for (int i = 0; i < *M; i++) {
        for (int j = i + 1; j < *M; j++) {
            if (elementsFromStrokaCounter[i][0] == elementsFromStrokaCounter[j][0]) elementsFromStrokaCounter[j][1] = elementsFromStrokaCounter[i][1];
        }
    }
}

void vivodElementsCounterArray(int elementsCounterArray[20][2], int *m) {
    for (int i = 0; i < *m; i++) {
        printf_s("element: %d ", elementsCounterArray[i][0]);
        printf_s("counter: %d \n", elementsCounterArray[i][1]);
    }
}

void sortingStroki(int elementsFromStrokaCounter[20][2], int newArray[20], int* M) {
    bool flag = false;
    for (int j = 0; j < *M; j++) {
        if (elementsFromStrokaCounter[j][1] >= 3) {
            flag = true;
            break;
        }
    }
    if (flag == true)
        for (int j = 0; j < *M; j++) {
            for (int j1 = j+1; j1 < *M; j1++) {
                if (elementsFromStrokaCounter[j][1] > elementsFromStrokaCounter[j1][1]) {
                    int temp0 = elementsFromStrokaCounter[j][0];
                    int temp1 = elementsFromStrokaCounter[j][1];
                    elementsFromStrokaCounter[j][1] = elementsFromStrokaCounter[j1][1];
                    elementsFromStrokaCounter[j][0] = elementsFromStrokaCounter[j1][0];
                    elementsFromStrokaCounter[j1][0] = temp0;
                    elementsFromStrokaCounter[j1][1] = temp1;
                }
                //if (j == 1) printf_s("element: %d counter: %d\n", elementsFromStrokaCounter[j][0], elementsFromStrokaCounter[j][1]);
            }
        }
    for (int j = 0; j < *M; j++) {
        newArray[j] = elementsFromStrokaCounter[j][0];
    }
}

void obrabotka(int *n, int *m, int A[20][20], int B[20][20]) {
    int N = *n;
    int M = *m;
    int elementsFromStrokaCounter[20][2];
    for (int i = 0; i < N; i++) {
        fillingUpElementsCounterArray(elementsFromStrokaCounter, A[i], &M);
        vivodElementsCounterArray(elementsFromStrokaCounter, m);
        //printf_s("1: %d 4: %d \n", elementsFromStrokaCounter[0][1], elementsFromStrokaCounter[3][1]);
        sortingStroki(elementsFromStrokaCounter, B[i], m);
    }
}
 
void vivod(int B[20][20],int *n,int *m) {
    printf_s("\n");
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *m; j++) {
            printf_s("%d ", B[i][j]);
        }
        printf_s("\n");
    }
}

int main()
{
    int n, m, A[20][20], B[20][20];
    vvod(&n, &m, A);
    obrabotka(&n, &m, A, B);
    vivod(B, &n, &m);
}
