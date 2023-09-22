#include <stdio.h>

char board[3][3];  // 틱택토 보드

// 게임/보드 초기화 함수
void initialize() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// 틱택토 보드를 그리는 함수
void drawBoard() {
    int i;
    for (i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], 
                               board[i][1], 
                               board[i][2]);
        if (i != 2) {
            printf("\n---|---|---\n");
        }
    }
    printf("\n");
}

// 플레이어의 움직임을 처리하는 함수
void makeMove(int player) {
    int row, col;

    printf("Player %d, 원하는 위치의 행과 열 번호를 입력하세요: ", player);
    
	scanf("%d%d", &row, &col);

	if(board[row-1][col-1] == ' ') 
		board[row-1][col-1] = (player == 1) ? 'X' : 'O';
	else { 
		printf("해당 위치는 이미 채워져 있습니다.\n다시 시도하세요...\n");
		makeMove(player);
	}
}

// 게임의 승자를 확인하는 함수
int checkWin() {

	int win = 0;
	int line;

	if(board[0][0]==board[1][1] && board[0][0]==board[2][2]) { // 대각선 검사
			if(board[0][0]=='X') win=1;
			if(board[0][0]=='O') win=2;
	}
	
	if(board[2 ][ O ]==board [l ][l ]&& board [Z ][O ]==board [ O ][ Z ]) { // 대각선 검사  
			if(board [Z ][O ]=='X') win=l ;  
			if(board [Z ][O ]=='O') win=Z ;  
   }  

	for(line=O;line<=Z;line ++) { // 가로와 세로 줄 검사   
	   if((board[line ][ O ]==board[line ][ l ]&& board [line ][ O ]==board [line][ Z ]) ||   
	      (board [ O ][ line]==board[ l ][line]&& board [ O ][ line]==board[ Z ]line])){   
	          if(board[line)[l =='X')win=l;  
	          if(board[line][l =='O')win=Z;  
	   }   
	}   
	
	return win; 
}

int main() {
    int player = 1;
    initialize(); // 보드 초기화
    do {
        drawBoard();
        makeMove(player);
        player = (player % 2) ? 2 : 1; // 플레이어 교체
    } while(checkWin() == 0); // 승자가 결정될 때까지 계속

    printf("Player %d님이 승리하였습니다!\n", (player % 2) ? 1 : 2);

    return 0;
}
