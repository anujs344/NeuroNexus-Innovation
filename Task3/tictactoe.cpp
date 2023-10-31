#include<iostream>
#include<vector>
using namespace std;

struct Player{
    static int count;
    string name;
    int wins,totgames;
    Player(){
        cout << " Enter the Name of The Player "<< count++ <<endl;
        cin >> name;
        wins = 0;
        totgames = 0;
    }
};

int Player::count = 1;

class TicTacToe{
    public:
    Player O,X;
    vector<vector<int> > board;
    TicTacToe(){
        cout << " ----------------------------------------------------------------------------------"<<endl;
        cout<<"Welcome "<<O.name<<" and "<<X.name<<endl;
        cout << " ----------------------------------------------------------------------------------"<<endl;
        cout<<"You have beein assign the value O for "<<O.name<<" and X for "<<X.name<<endl; 
        cout << " ----------------------------------------------------------------------------------"<<endl;
        cout<<"Kindly enter the row and coloum number to enter your values "<<endl;
        cout << " ----------------------------------------------------------------------------------"<<endl;
    }

    void CreateGame(){
        board  = {{-1,-1,-1},{-1,-1,-1},{-1,-1,-1}};
    }

    void printBoard(){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j] == -1)
                    cout<<" - "<<" ";
                else if(board[i][j] == 1)
                    cout << " X "<< " ";
                else 
                    cout << " O "<< " ";
            }
            cout<<endl;
        }

    }

    int gameRes(int symbol){
        //checing row
        
        if(board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] == symbol)
            return true;
        if(board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] == symbol)
            return true;
        if(board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] == symbol)
            return true;
        //checking col
        if(board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] == symbol)
            return true;
        if(board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] == symbol)
            return true;
        if(board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] == symbol)
            return true;
        //checking firstdigonal
        if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == symbol)
            return true;
        //checking second diagonal
        if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == symbol)
            return true;
        cout<<"Hello"<<endl;
        return false;
    }
    void play(){
        CreateGame();
        // printBoard();
        bool turnOfX = false,gameEndedWithWinner = false;
        for(int i = 0;i< 9 ;i++){
            startGame: 
                int col,row;
                printBoard();
                string name ;
                if(turnOfX){
                    name = X.name;
                }else{
                    name = O.name;
                }
                cout<< " Enter the row and col number seprated by space "<< name<<endl;
                
                cin >> row >> col;
                if(turnOfX){
                    if(board[row-1][col-1] != -1){
                        cout << "Please Enter at the blank Space " << X.name<<endl;
                        goto startGame;
                    }
                    else   
                        board[row-1][col-1] = 1;
                    
                
                }else{
                    if(board[row-1][col-1] != -1){
                        cout << "Please Enter at the blank Space " << O.name<< endl;
                        goto startGame;
                    }
                    else   
                        board[row-1][col-1] = 0;
                    
                    
                }

                bool gameResult = turnOfX ? gameRes(1): gameRes(0);
                if(gameResult){
                    printBoard();
                    gameEndedWithWinner = true;
                    if(turnOfX){
                        cout << "Congratulations !! "<< X.name<< " You are Winner!"<<endl;
                    }
                    else{
                        cout << "Congratulations !! "<< O.name<< " You are Winner!"<<endl;
                    }
                    rematchChoice:
                        cout<<" ------------------------------------------   "<<endl;
                        cout<<" ------------------------------------------   "<<endl;
                        cout<<"So Wanna Play One More Game? "<<endl;
                        int choice;
                        cout<<"Press 1 for Rematch and 2 for quit"<<endl;
                        cin>> choice;
                        switch (choice)
                        {
                        case 1:
                            play();
                            break;
                        case 2:
                            cout<< "Thank you for Playing See You Soon!"<<endl;
                            break;
                        default:
                            cout<<" Please Enter the correct choice"<<endl;
                            goto rematchChoice;
                            break;
                        }
                    break;
                }
                turnOfX = !turnOfX;
        }
        if(gameEndedWithWinner == false)
            cout<<"Sorry Its a Draw"<<endl;
    }
    
};

int main(){
    TicTacToe game;
    game.play();
    return 0;
    
}