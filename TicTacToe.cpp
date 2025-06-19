#include <iostream>
#include <string>
using namespace std;

void board(char[][3]);
bool checkWinner(char[][3]);
int main() {
    char space[3][3] = {{' ',' ',' '},
                        {' ',' ',' '},
                        {' ',' ',' '}};

    const char PlayerX = 'X';
    const char PlayerO = 'O';
    char currentPlayer = 'X';
    int r = -1, c = -1;
    int rounds = 0;
    bool isWinner;

    for(int i = 0; i < 9; i++) {

        cout << "Player's " << currentPlayer << " turn:\n";
        

        while(true) {
            board(space);
            cout << "Enter a row and column: ";
            cin >> r >> c;
            if (r > 3 || r < 1 || c > 3 || c < 1)
                cout << "Invalid input! Try again.\n";
            else if (space[r-1][c-1] != ' ')
                cout << "Space already taken! Try again.\n";
            else
                break;

            r = -1;
            c = -1;

            cin.clear();
            cin.ignore(100000, '\n');
        }
        space[r-1][c-1] = currentPlayer;
        isWinner = checkWinner(space);

        if (isWinner)
            break;
        else 
            currentPlayer = (currentPlayer == PlayerX) ? PlayerO : PlayerX;

    }

    board(space);
    if(isWinner)
        cout << "Congratalations! Player " << currentPlayer << " has won!!!\n";
    else
        cout << "There is a draw! No one wins!\n";


    return 0;
}

void board(char s[][3]) {
    cout << "   |   |   \n";
    cout << " " << s[0][0] << " | " << s[0][1] << " | " << s[0][2] << endl;
    cout << "___|___|___\n";
    cout << "   |   |   \n";
    cout << " " << s[1][0] << " | " << s[1][1] << " | " << s[1][2] << endl;
    cout << "___|___|___\n";
    cout << "   |   |   \n";
    cout << " " << s[2][0] << " | " << s[2][1] << " | " << s[2][2] << endl;
    cout << "   |   |   \n";
}

bool checkWinner(char s[][3]) {
    bool win = false;
    for(int i = 0; i < 3; i++) {
        if (s[0][i] != ' ' && s[0][i] == s[1][i] && s[0][i] == s[2][i])
            win = true;
        
        if (s[i][0] != ' ' && s[i][0] == s[i][1] && s[i][1] == s[i][2])
            win = true;
    }
    if (s[0][0] != ' ' && s[0][0] == s[1][1] && s[1][1] == s[2][2])
        win = true;
    else if (s[0][2] != ' ' && s[0][2] == s[1][1] && s[0][2] == s[2][0])
        win = true;

    return win;
}