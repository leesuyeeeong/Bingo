#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>                                
#include <time.h>                                   
#define SIZE 5
#define SIZE2 25

void initialize();                                
void set_rand(int *array);
void swap(int *x, int *y);
void erase_bingo(int arr[5][5], int number); 
void print_bingo(int arr[5][5]);
void print_winner(int winner);
int get_number(int from);                    
int checked[25];                                   
int count = 0;
int check_bingo(int arr[5][5]);            
int ubingo[5][5];                              
int cbingo[5][5];        
                         
void main() {
        int number, uwin, cwin;
        initialize();                            
        do {
			printf("========================================\n");
			printf("              BINGO GAME                \n");
			printf("****************************************\n");
			print_bingo(ubingo);                                                // ������� ������ ���
			printf("****************************************\n");
			printf("========================================\n");
               number = get_number(0);                                          // ������� ��ȣ ����
               erase_bingo(ubingo, number);
               erase_bingo(cbingo, number);
               number = get_number(1);                                          // ��ǻ���� ��ȣ ����
               erase_bingo(ubingo, number);
               erase_bingo(cbingo, number);
               uwin = check_bingo(ubingo);
               cwin = check_bingo(cbingo);
        } while ((uwin == 0) && (cwin == 0));                
        printf("               [user ���]        \n\n"); 
		print_bingo(ubingo); 
        printf("            [computer ���]       \n\n"); 
		print_bingo(cbingo); 
        print_winner(cwin * 2 + uwin);
                                                                
			}
			
void initialize() {                                         // ������ �ʱ�ȭ �Լ�
        srand((unsigned int)time(NULL));
        set_rand((int *)ubingo);
        set_rand((int *)cbingo);
}
void set_rand(int *array) {
        int i;
        for (i=0;i<SIZE2;i++) {
               array[i] = i+1;
        }
        for (i=0;i<SIZE2;i++) {
               swap(&array[i], &array[rand() % 25]);
        }
}
void swap(int *x, int *y) {
        int temp;
        temp = *x;
        *x = *y;
        *y = temp;
}

void erase_bingo(int arr[5][5], int number) {        // �Է¹��� number�� ���� ���� 0���� ����� �Լ�
        int x, y;
        for (y=0;y<SIZE;y++) {                                     
               for (x=0;x<SIZE;x++) {
                       if (arr[y][x] == number) {
                              arr[y][x] = 0;
                       }
               }
        }
}

void print_bingo(int arr[5][5]) {                    // ������ ����ϴ� �Լ�
        int x,y;
        for (y=0;y<SIZE;y++) {
               for (x=0;x<SIZE;x++) {
                       if (arr[y][x] != -1) {       
                              printf("%7d", arr[y][x]);
                       }
                       else {                                      
                              printf("XerrorX");
                       }
               }
               printf("\n\n");
        }
}

void print_winner(int winner) {                      // ���ڸ� ����ϴ� �Լ�
        switch (winner) {
        case 1:                                                    
               printf("~~~ CONGRATULATION!!!! YOU WIN ~~~ \n");
               break;
        case 2:                                                     
               printf("~~~ computer WIN ~~~.\n");
               break;
        case 3:                                                     
               printf("same score.\n");
               break;
        default:                                                    
               printf("err\n");
               break;
        }
}

int get_number(int frm) {                            // ���ڸ� �Է¹޴� �Լ�
        int number;
        int x, retry;
        do {
               retry = 0;
               if (frm == 0) {                            
                       printf(">>> 1~25 ������ ���ڸ� �Է��ϼ��� : ");
                       scanf("%d", &number);
                       if (number < 1 || number > 25) {
                              retry = 1;                            
                       }
               }
               else {                                              
                       number = rand() % 25 + 1;
               }
               if (retry == 0) {
                       for (x = 0; x<count;x++) {
                              if (checked[x] == number) {
                                      retry = 1;
                                      break;
                              }
                       }
               }
        } while (retry == 1);                        
        checked[count++] = number;
        if (frm == 0) {
               printf("> user�� '%d'�� �����߽��ϴ�. \n\n", number);
        }
        else {
               printf("> computer�� '%d'�� �����߽��ϴ�. \n\n", number);
        }
        return number;
}

int check_bingo(int arr[5][5]) {                             // ������ Ȯ���ϴ� �Լ�
        int x, y, sum;                                       //�� ���� ���� 0�� �Ǹ� �����̹Ƿ� sum ���� ����
        for (y=0;y<SIZE;y++) {                       
               sum = 0;                                            
               for (x=0;x<SIZE;x++) {
                       sum += arr[y][x];
               }
               if (sum == 0) {
                       return 1;
               }
        }
        for (x=0;x<SIZE;x++) {                      
               sum = 0;
               for (y=0;y<SIZE;y++) {
                       sum += arr[y][x];
               }
               if (sum == 0) {
                       return 1;
               }
        }
        sum = 0;                                                   
        for (x =0;x<SIZE;x++) {                           
               sum += arr[x][x];
        }
        if (sum == 0) {
               return 1;
        }
        sum = 0;
        for (x=0;x<SIZE;x++) {                       
               sum += arr[x][SIZE - x -1];
        }
        if (sum == 0) {
               return 1;
        }
        return 0;                                                   
}
 
