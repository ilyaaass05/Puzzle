#include <stdio.h>

#include <stdlib.h>

#include <time.h>


void show(int array[]);

void changer(int array[]);

int get_index(int array[], int value);

void play(int array[]);

int is_won(int array[]);


int main() {

    int array[16] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };

        changer(array);

        do {

                system("cls");

                show(array);

                play(array);

        } while (is_won(array) != 1);

        printf("\nyou won the game");

    return 0;

}


void show(int array[]) {

        for (int i = 0; i < 16; i++)

        {

                if (i % 4 == 0) {

                        printf("\n");

                }

                if (array[i] == 0) {

                        printf("%c\t", 223);

                }

                else {

                        printf("%d\t", array[i]);

                }

        }

}

void changer(int array[]) {

        srand(time(NULL));

        int temp,index_1,index_2;

        for (int i = 0; i < 18; i++)

        {

                index_1 = rand() % 16;

                index_2 = rand() % 16;

                temp = array[index_1];

                array[index_1] = array[index_2];

                array[index_2] = temp;

        }

}


int get_index(int array[],int value) {

        for (int  i = 0; i < 16; i++)

        {

                if (array[i] == value) {

                        return i;

                }

        }

        return -1;

}


void play(int array[]) {

        int number, index_n, index_0,temp;

        printf("\nenter the number you want to transfer: ");

        scanf("%d", &number);

        index_n = get_index(array, number);

        index_0 = get_index(array, 0);

        if (index_0 + 1 == index_n || index_0 - 1 == index_n || index_0 + 4 == index_n || index_0 - 4 == index_n) {

                temp = array[index_0];

                array[index_0] = array[index_n];

                array[index_n] = temp;

        }

}


int is_won(int array[]) {

        for (int i = 0; i < 15; i++)

        {

                if (i != array[i]) {

                        return 0;

                }

        }

        return 1;

}


