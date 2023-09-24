#include <stdio.h>

char board[3][3]; 

void initialize_board() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void print_board() {
    int i, j;
    printf("\n---보드 상태---\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j != 2) printf("|");
        }
        printf("\n");
        if (i != 2) printf("---|---|---\n");
    }
}

int check_win(char player) {
    int i;

    for (i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player))
            return 1;
    }

     for (i = 0; i < 3; ++i) 
     { 
         if ((board[0][i] == player && board[1][i] == player && board[2][i] == player)) 
             return 1;
     } 

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return 1;

    return 0;
}

int check_draw() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

void play_game() {
    int cell_number;
    char current_player = 'X';

    initialize_board();

    printf("틱택토 게임을 시작합니다.\n");

    while (1) {
        printf("\n현재 차례: %c (%s)\n", current_player, (current_player=='X') ? "준용" : "Player2");
        print_board();

        printf("칸 번호를 입력하세요. (예: 1~9): ");
        scanf("%d", &cell_number);

		int row = (cell_number - 1) / 3;
		int col = (cell_number - 1) % 3;

		if ((cell_number >= 1 && cell_number <=9 ) && (board[row][col]==' ')) {
			board[row][col]=current_player;

			if (check_win(current_player)) {
				printf("\n--- 게임 종료 ---\n");
				printf("승리자: %c (%s)\n", current_player, (current_player=='X') ? "준용" : "Player2");
				print_board();
				break;
			}

			if (check_draw()) {
				printf("\n--- 게임 종료 ---\n");
				printf("비겼습니다.\n");
				print_board();
				break;
			}

			current_player = (current_player == 'X') ? 'O' : 'X';
		} else {
			printf("잘못된 칸 번호입니다. 다시 입력하세요.\n");
        }
    }
}

int main() {
    printf("20230850 컴퓨터공학과 송준용\n");
    play_game();

    return 0;
}
