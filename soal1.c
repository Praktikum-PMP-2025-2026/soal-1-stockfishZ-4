//RAFA SATRIA PRATAMA
//SOAL 1- 21 APRIL 2026
//MANUSKRIP RETAK

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char nama[100];
    char kategori[100];
    int tahun;
    int nilai;
    int check;
    struct Node* next;
} Node;

void getN(char order[], int* N, int* start_idx){
    char N_s[10];
    for (int i = 0; i < strlen(order); i++){
        if (order[i] != ' '){
            N_s[i] = order[i];
        }else{
            *start_idx = i;
            break;
        }
    }
    *N = atoi(N_s);
}

void SeeandStore(Node* head, int N, char order[], int start_idx){
    Node* current = head;
    int segini = 0;
    char netral[100];
    char stemp[100];
    int count = 0; int ktemp = 0;
    for (int i = start_idx+1; i < strlen(order); i++){
        if (count == 0){
            if (order[i] != ' '){
                stemp[ktemp] = order[i];
                segini++;
                ktemp++;
            }else{
                stemp[segini] = '\0';
                strcpy(current->nama, stemp);
                strcpy(stemp, netral);
                stemp[0] = '\0';
                ktemp = 0;
                count++;
            }
        }else if (count == 1){
            if (order[i] != ' '){
                stemp[ktemp] = order[i];
                ktemp++;
            }else{
                strcpy(current->kategori, stemp);
                strcpy(stemp, netral);
                stemp[0] = '\0';
                ktemp = 0;
                count++;
            }
        }else if (count == 2){
            if (order[i] != ' '){
                stemp[ktemp] = order[i];
                ktemp++;
            }else{
                current->tahun = atoi(stemp);
                strcpy(stemp, netral);
                stemp[0] = '\0';
                segini = 0;
                ktemp = 0;
                count++;
            }
        }else if (count == 3){
            if (order[i] != ' '){
                stemp[ktemp] = order[i];
                segini++;
                ktemp++;
            }else{
                stemp[segini] = '\0';
                current->nilai = atoi(stemp);
                strcpy(stemp, netral);
                ktemp = 0;
                segini = 0;
                count++;
            }
        }else{
            Node* newNode = (Node*)malloc(sizeof(Node));
            current->next = newNode;
            newNode->next = NULL;
            segini = 0;
            current = newNode;
            count = 0;
            stemp[0] = '\0';
            i--;
        }
    }
}

void printAll(Node* head){
    Node* current = head;

    while (current->next != NULL){
        printf("%s %s %d %d\n", current->nama, current->kategori, current->tahun, current->nilai);
        current = current->next;
    }
}



int main(){
    int N; int start_idx;
    Node* head = (Node*)malloc(sizeof(Node)); 
    head->check = 67;
    head->next = NULL;
    char order[640];

    fgets(order, 640, stdin);

    getN(order, &N, &start_idx);
    SeeandStore(head, N, order, start_idx);
    //sort(head);
    printAll(head);
}
