#include <iostream>
#include <windows.h>
#include <cctype>
#include <fstream>
using namespace std;

class TicTacToe {
private:
    char board[4][4];
    char player;
    int turns;
    string playerOName, playerXName;  // playerOName = O, playerXName = X

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

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
        cout << "\n\n";
        cout << "  Enter Player 1 name (O): ";
        cin >> playerOName;
        cout << "  Enter Player 2 name (X): ";
        cin >> playerXName;
    }

    // ===== COLORS =====
    void setColor(int color) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    }

    // ===== CENTER TEXT =====
    void centerText(string text, int offset = 0) {
        int width = 100;
        int spaces = (width - text.length()) / 2 + offset;

        for(int i = 0; i < spaces; i++)
            cout << " ";

        cout << text;
    }

    // ===== CLEAR SCREEN =====
    void clearScreen() {
        system("cls");
    }

    // ===== LOAD STATS =====
    void loadStats(int &totalGames, int &playerOWins, int &playerXWins, int &totalDraws) {
        ifstream fin("stats.txt");
        if(fin) fin >> totalGames >> playerOWins >> playerXWins >> totalDraws;
        else totalGames = playerOWins = playerXWins = totalDraws = 0;
    }

    void saveStats(int totalGames, int playerOWins, int playerXWins, int totalDraws) {
        ofstream fout("stats.txt");
        fout << totalGames << " " << playerOWins << " " << playerXWins << " " << totalDraws;
    }

    // ===== DRAW BOARD =====
    void drawBoard() {

        setColor(11);

        cout << "\n\n";
        centerText("=================================");
        cout << "\n";
        centerText("     TIC TAC TOE 4 x 4");
        cout << "\n";
        centerText(" =================================\n\n");

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

    // ===== RESET BOARD =====
    void resetBoard() {
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

    // ===== GAME LOOP =====
    void play() {
        char choice, again;

        do {
            resetBoard();

            while(true) {
                clearScreen();
                drawBoard();

                setColor(13);
                cout << "\n";
                string currentPlayerName = (player == 'O') ? playerOName : playerXName;
                centerText(currentPlayerName + " (" + player + ") Turn : ", -1);

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

                    int totalGames, playerOWins, playerXWins, totalDraws;
                    loadStats(totalGames, playerOWins, playerXWins, totalDraws);
                    totalGames++;
                    if(player == 'O') playerOWins++; else playerXWins++;
                    saveStats(totalGames, playerOWins, playerXWins, totalDraws);

                    string winnerName = (player == 'O') ? playerOName : playerXName;
                    setColor(10);
                    centerText(winnerName + " (" + player + ") Wins!");
                    cout << "\n";
                    break;
                }

                if(turns == 16) {
                    clearScreen();
                    drawBoard();

                    int totalGames, playerOWins, playerXWins, totalDraws;
                    loadStats(totalGames, playerOWins, playerXWins, totalDraws);
                    totalGames++; totalDraws++;
                    saveStats(totalGames, playerOWins, playerXWins, totalDraws);

                    setColor(14);
                    centerText("It's a Draw!");
                    cout << "\n";
                    break;
                }

                switchPlayer();
            }

            int totalGames, playerOWins, playerXWins, totalDraws;
            loadStats(totalGames, playerOWins, playerXWins, totalDraws);

            setColor(11);
            cout << "\n";
            centerText("--- Stats ---");
            cout << "\n";
            centerText("Games: " + to_string(totalGames) + "  " + playerOName + " Wins: " + to_string(playerOWins) + "  " + playerXName + " Wins: " + to_string(playerXWins) + "  Draws: " + to_string(totalDraws));
            cout << "\n\n";

            setColor(13);
            centerText("Play again? (y/n) : ");
            cin >> again;

        } while(again == 'y' || again == 'Y');

        setColor(7);
    }
};

// ===== MAIN =====
int main() {
    TicTacToe game;
    game.play();
    return 0;
}