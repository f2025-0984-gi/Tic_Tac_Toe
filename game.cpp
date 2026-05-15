#include <iostream>
#include <windows.h>
#include <cctype>
using namespace std;

class TicTacToe {
private:
    char board[4][4];
    char player;
    int turns;

public:
    // Constructor
    TicTacToe() {
        char temp[4][4] = {
            {'1','2','3','4'},
            {'5','6','7','8'},
            {'9','A','B','C'},
            {'D','E','F','G'}
        };

        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                board[i][j] = temp[i][j];

        player = 'X';
        turns = 0;
    }

    // ===== COLORS =====
    void setColor(int color) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    }

    // ===== CENTER TEXT =====
    void centerText(string text) {
        int width = 100;
        int spaces = (width - text.length()) / 2;

        for(int i = 0; i < spaces; i++)
            cout << " ";

        cout << text;
    }

    // ===== CLEAR SCREEN =====
    void clearScreen() {
        system("cls");
    }

    // ===== DRAW BOARD =====
    void drawBoard() {

        setColor(11);

        cout << "\n\n";
        centerText("=================================");
        cout << "\n";
        centerText("     TIC TAC TOE 4 x 4");
        cout << "\n";
        centerText("=================================\n\n");

        for(int i = 0; i < 4; i++) {

            int spaces = 40;
            for(int k = 0; k < spaces; k++)
                cout << " ";

            for(int j = 0; j < 4; j++) {

                if(board[i][j] == 'X')
                    setColor(12);
                else if(board[i][j] == 'O')
                    setColor(10);
                else
                    setColor(14);

                cout << " " << board[i][j] << " ";

                setColor(11);

                if(j < 3)
                    cout << "|";
            }

            cout << "\n";

            if(i < 3) {
                for(int k = 0; k < spaces; k++)
                    cout << " ";
                cout << "---|---|---|---\n";
            }
        }

        cout << "\n";
    }

    // ===== MARK BOARD =====
    bool markBoard(char choice) {
        choice = toupper(choice);

        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                if(board[i][j] == choice) {
                    board[i][j] = player;
                    return true;
                }
            }
        }
        return false;
    }

    // ===== CHECK WIN =====
    bool checkWin() {

        // Rows
        for(int i = 0; i < 4; i++) {
            if(board[i][0] == player &&
               board[i][1] == player &&
               board[i][2] == player &&
               board[i][3] == player)
                return true;
        }

        // Columns
        for(int i = 0; i < 4; i++) {
            if(board[0][i] == player &&
               board[1][i] == player &&
               board[2][i] == player &&
               board[3][i] == player)
                return true;
        }

        // Diagonals
        if(board[0][0] == player &&
           board[1][1] == player &&
           board[2][2] == player &&
           board[3][3] == player)
            return true;

        if(board[0][3] == player &&
           board[1][2] == player &&
           board[2][1] == player &&
           board[3][0] == player)
            return true;

        return false;
    }

    // ===== SWITCH PLAYER =====
    void switchPlayer() {
        player = (player == 'X') ? 'O' : 'X';
    }

    // ===== GAME LOOP =====
    void play() {
        char choice;

        while(true) {
            clearScreen();
            drawBoard();

            setColor(13);
            cout << "\n";
            centerText("Player ");
            cout << player << " Turn : ";

            cin >> choice;

            if(!markBoard(choice)) {
                setColor(12);
                cout << "\n\n";
                centerText("Invalid Move!");
                Sleep(1200);
                continue;
            }

            turns++;

            if(checkWin()) {
                clearScreen();
                drawBoard();

                setColor(10);
                cout << "\n";
                centerText("Congratulations!\n\n");

                centerText("Player ");
                cout << player << " Wins!\n\n";
                break;
            }

            if(turns == 16) {
                clearScreen();
                drawBoard();

                setColor(14);
                cout << "\n";
                centerText("Match Draw!\n\n");
                break;
            }

            switchPlayer();
        }

        setColor(7);
        cout << "\n";
        system("pause");
    }
};

// ===== MAIN =====
int main() {
    TicTacToe game;
    game.play();
    return 0;
}