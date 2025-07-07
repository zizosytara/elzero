#include<iostream>
#include<ctime>
#include<conio.h>
#include<Windows.h>
using namespace std;
void shift_right(int arr[],int size){
    for (int i=size-2;i>=0;i--){
       arr[i+1]=arr[i];
    }
}
//----------------------------------------------//
enum direction {Top=1,Down,Right,Left};
struct map {int width,height,fruitX,fruitY;};
struct snake{int headX ,headY,tailN,tailX[50],tailY[50]; direction dir;};
struct player {int score ; bool lose;};
//----------------------------------------------//
map map1 ; snake snake1; player player1;
void generateFruit();
void setup(){
    map1.width=40;
    map1.height=20;
    generateFruit();
//------------------------//
player1.score=0;
player1.lose =false;
//-----------------------//
snake1.headX=map1.width/2;
snake1.headY=map1.height/2;
snake1.tailN=0;
}
void generateFruit(){
    srand(time(NULL));
    map1.fruitX=rand()%(map1.width-2)+1;
    map1.fruitY=rand()%(map1.height-2)+1;
}
void draw(){
    system("cls");
for(int j=0;j<map1.height;j++){
    for(int i=0;i<map1.width;i++){
        if(j==0 || j==map1.height-1)
        cout<<'*';

        else if (i==0 || i==map1.width-1)
        cout<<'*';

        else if (j==snake1.headY && i==snake1.headX){
            cout<<"O";

        }
        

        else if (j==map1.fruitY && i==map1.fruitX)
        cout<<"$";
        
        else{
            bool printed=false;
            for(int z=0;z<snake1.tailN;z++){
                if(snake1.tailX[z]==i && snake1.tailY[z]==j){
                cout<<"o";
                printed=true;
                break;
                }


            }
            if(!printed){
                cout<<" ";
            }

        }
        
        
    }
    cout<<endl;
}
cout<<endl;

cout<<"Player Score :  "<<player1.score<<endl;

}
void input(){
if(_kbhit()){
char c=_getch();
switch(c){
    case 'w':
    snake1.dir=Top ;
    break;
    case 's':
    snake1.dir=Down ;  
    break;
    case 'd':
    snake1.dir=Right;
    break;
    case 'a':
    snake1.dir=Left;
    break;
    case 'x':
    exit(0);
    break;
    
}  
}
}
void move(){
    shift_right(snake1.tailX,50);
    shift_right(snake1.tailY,50);
    snake1.tailX[0]=snake1.headX;
    snake1.tailY[0]=snake1.headY;

    switch(snake1.dir){
    case Top  : --snake1.headY;
    break;
    case Down : ++snake1.headY;
    break;
    case Right: ++snake1.headX;
    break;
    case Left : --snake1.headX;
    break;
       }
    if(snake1.headX <=0 || snake1.headX>=map1.width-1 ||snake1.headY<=0 || snake1.headY>=map1.height-1){
         player1.lose=true;
     }
    if(snake1.headY==map1.fruitY && snake1.headX==map1.fruitX){
             generateFruit();
             player1.score+=1;
             snake1.tailN++;
               
  }

}
int main(){

setup();
while(!player1.lose){
    draw();
    input();
    move();
    Sleep(50);
    
}
    system("pause"); 
    return 0;
}