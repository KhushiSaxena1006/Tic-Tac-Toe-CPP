#include<iostream>
#include<string>
using namespace std ;

//function to print the board
void board(char box[3][3]){
    cout<<endl;
    for(int i=0 ; i<3 ; i++){
        cout<<"         ";
        for(int j=0 ; j<3 ; j++){
            if(box[i][j]=='X' || box[i][j]=='0'){
                cout<<" "<<box[i][j]<<" ";
            }else{
                cout<<"   ";
            }
            if(j!=2){
                cout<<"|";
            }
        }
        cout<<endl;
        if(i!=2){
            cout<<"         ";
            cout<<"-----------";
            cout<<endl;
        }
    }
}

//function to check winning conditions
bool condWin(char box[3][3]){
    if((box[0][0]==box[0][1]) && (box[0][0]==box[0][2])){  //0th row
        return true ;
    }else if ((box[1][0]==box[1][1]) && (box[1][0]==box[1][2]) ){  //1st row
        return true ;
    }else if ((box[2][0]==box[2][1]) && (box[2][0]==box[2][2]) ){  //2nd row
        return true ;
    }else if ((box[0][0]==box[1][0]) && (box[0][0]==box[2][0]) ){  //0th column
        return true ;
    }else if ((box[0][1]==box[1][1]) && (box[0][1]==box[2][1]) ){  //1st column
        return true ;
    }else if ((box[0][2]==box[1][2]) && (box[0][2]==box[2][2]) ){  //2nd column
        return true ;
    }else if ((box[0][0]==box[1][1]) && (box[0][0]==box[2][2]) ){  // '\'diagonal
        return true ;
    }else if ((box[0][2]==box[1][1]) && (box[0][2]==box[2][0]) ){  // '/'diagonal
        return true ;
    }else{
        return false ;
    }
}

//function to check tie condition
bool condTie(char box[3][3]){
    for(int r=0 ; r<3 ; r++){
        for(int c=0 ; c<3 ; c++){
            if ( box[r][c]!='X' && box[r][c]!='0'){
                return false;
            }
        }
    }
    return true ;
}

//tic-tac-toe function
int ticTacToe(){
    int r,c;
    char box[3][3] = {{'a','b','c'},{'d','e','f'},{'g','h','i'}};
    bool win = false ;
    string player_1 ;
    string player_2 ;
    cout<<"\n***** WELCOME *****\n"<<endl;
    cout<<"------>>>   ''TIC - TAC - TOE''\n Entering the world of X and 0 :) \n"<<endl;
    cout<<"Lets start :-"<<endl;
    cout<<"PLAYER I (0) ? ";
    getline(cin,player_1);
    cout<<"PLAYER II (X) ? ";
    getline(cin,player_2); 
    cout<<endl;
    cout<<"   C0 C1 C2"<<endl;
    cout<<"R0 __|__|__"<<endl;
    cout<<"R1 __|__|__"<<endl;
    cout<<"R2   |  |  "<<endl; 
    cout<<"\n";  
    while(win == false){
        cout<<">>>>> PLAYER I : Enter position for '0' ;"<<endl;
        bool fill=false ;
        while (fill== false){
            bool valid = false ;
            while (valid ==false) {
                cout<<"Row : (in range :- 0,1,2) -----> ";
                cin>>r;
                cout<<"Column : (in range :- 0,1,2) -----> ";
                cin>>c;
                if( r>=0 && r<3 && c>=0 && c<3 ){
                    valid = true ;
                    if( box[r][c]!='X' && box[r][c]!='0' ){
                        box[r][c] = '0';
                        fill = true;
                    }else{
                        cout<<"* Already Filled ....Please re-enter ;\n";
                    }
                }else{
                    cout<<"* Invalid Address.... Please re-enter ;\n";
                }
            }
        }
        board(box);
        cout<<endl;
        if (condWin(box) == true){
            win = true;
            cout<<" \n-----x-----x-----x-----x-----x-----x-----x-----\n";
            cout<<"-->> CONGRATULATIONS....You won the game :)"<<endl;
            cout<<"  WINNER : "<< player_1<<endl;
            cout<<"  Better luck next  time "<<player_2<<endl;
            break;
        }
        if(condTie(box) == true){
            cout<<" \n-----x-----x-----x-----x-----x-----x-----x-----\n ";
            cout<<"Hey !! It's a tie....";
            break;
        }

        cout<<">>>>> PLAYER II : Enter position for 'X' ;"<<endl;
        fill = false;
        while(fill == false){
            bool valid = false;
            while(valid == false){
                cout<<"Row : (in range :- 0,1,2) -----> ";
                cin>>r;
                cout<<"Column : (in range :- 0,1,2) -----> ";
                cin>>c;
                if( r>=0 && r<3 && c>=0 && c<3 ){
                    valid=true;
                    if( box[r][c]!='X' && box[r][c]!='0' ){
                        box[r][c] = 'X';
                        fill = true;
                    }else{
                        cout<<"* Already Filled ....Please re-enter ;\n";
                    }
                }else{
                    cout<<"Invalid Address.... Please re-enter ";
                }
            }
        }
        board(box);
        if (condWin(box)  == true){
            win = true;
            cout<<" \n-----x-----x-----x-----x-----x-----x-----x-----\n ";
            cout<<"-->> CONGRATULATIONS....You won the game :)"<<endl;
            cout<<"  WINNER :" << player_2<<endl;
            cout<<"  Better luck next  time "<<player_1<<endl;
            break;
        }
        cout<<" \n-----x-----x-----x-----x-----x-----x-----x-----\n ";
    }
}

//main function
int main(){
    bool play=true;
    string check;
    while(play==true){
        ticTacToe();
        cout<<"Do you want to play again ? (YES/NO)";
        cin>>check;
        if(check=="NO"){
            play = false;
            cout<<"Hope you liked it ....\n   (:Thanks for playing :)";
        }
    }
    return 0 ;
}