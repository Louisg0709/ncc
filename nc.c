/*
A simple noughts and crosses program
*/

#include <stdio.h>
#include <math.h>

void Convert1dTo2d(int val, int *output[2]){
    int y = trunc((float)val/3.0);
    int x = val - y*3;
    *output[0] = x;
    *output[1] = y;
}

int Convert2dTo1d(int val[2]){
    return val[1]*3+val[0];
}

int FollowsPattern(int coord1[2], int coord2[2], int coord3[3]){
    if ((coord3[0]-coord2[0] == coord2[0]-coord1[0]) && (coord3[1]-coord2[1] == coord2[1]-coord1[1])){
            return 1;
        }    
}

int CheckForWin(int CheckBoard[9], int Start){
    for(int i = 0; i < 9; i++){
        if ((Start + i)<9 && (Start-i)>0){
            if (CheckBoard[Start] == CheckBoard[Start+i] && CheckBoard[Start] == CheckBoard[Start-i]){
                int coord1[2];
                int coord2[2];
                int coord3[3];
                Convert1dTo2d(Start - i, &coord1);
                Convert1dTo2d(Start, &coord2);
                Convert1dTo2d(Start + i, &coord3);
                if(FollowsPattern(coord1,coord2,coord3)){return 1;}
                }
        }
        if ((Start + i)<9 && (Start + i * 2)<9){
            if (CheckBoard[Start] == CheckBoard[Start+i] && CheckBoard[Start] == CheckBoard[Start+i*2]){
                int coord1[2];
                int coord2[2];
                int coord3[3];
                Convert1dTo2d(Start, &coord1);
                Convert1dTo2d(Start + i, &coord2);
                Convert1dTo2d(Start + i*2, &coord3);
                if(FollowsPattern(coord1,coord2,coord3)){return 1;}
                }
        }
        if ((Start - i)>0 && (Start - i * 2)>0){
            if (CheckBoard[Start] == CheckBoard[Start-i] && CheckBoard[Start] == CheckBoard[Start-i*2]){
                int coord1[2];
                int coord2[2];
                int coord3[3];
                Convert1dTo2d(Start, &coord1);
                Convert1dTo2d(Start - i, &coord2);
                Convert1dTo2d(Start - i*2, &coord3);
                if(FollowsPattern(coord1,coord2,coord3)){return 1;}
                }
        }
    }
}

//Play game
int main(){
    int playing = 1;
    int board[9] = {0,0,0,0,0,0,0,0,0};
    while(playing){
        printf("Player 1 input your coordinates");
        int coords[2] = {0,0};
        scanf("%d,%d", &coords[0], &coords[1]);
        int val = Convert2dTo1d(coords);
        if (board[val] == 0){board[val = 1];}
        else {
            printf("Invalid move player 1 loses!");
            playing = 0;
        }

        if(CheckForWin(board,val)){
            printf("Player 1 wins!");
            playing = 0;
        }

        printf("Player 2 input your coordinates");
        scanf("%d,%d", &coords[0], &coords[1]);
        val = Convert2dTo1d(coords);
        if (board[val] == 0){board[val = 1];}
        else {
            printf("Invalid move player 2 loses!");
            playing = 0;
        }

        if(CheckForWin(board,val)){
            printf("Player 2 wins!");
            playing = 0;
        }
    }
}