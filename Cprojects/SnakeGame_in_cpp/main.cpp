#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
using namespace std;
bool gameOver;
const int width = 45;
const int height = 20;
int x, y, fruitX, fruitY, score, barX, barY, barXX, barYY;
int tailX[100], tailY[100];
int lenTail;
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN, PAUSE, RESET};
eDirection dir;
int index = 0;
char letters[] = {'p','e','n','c','i','l'};
void Setup(){
    gameOver =  false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    barX = rand() % width;
    barY = rand() % height;
    barXX = rand() % width;
    barYY = rand() % height;
    score = 0;

}


void Draw(){
    system("cls");
    cout << " ";
    for (int i = 0; i < width; i++)
        cout << "#";
     cout << endl;

    for(int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            if (j == 0)
                cout << "#";

            if (i == y && j == x)
                cout << "O";

            else if (i == fruitY && j == fruitX)
                cout << letters[index];

            else if (i == barY && j == barX)
                cout << "*";

            else if (i == barYY && j == barXX)
                cout << "*";



            else{
                bool print = false;
                for (int k = 0; k < lenTail; k++){

                    if (tailX[k] == j && tailY[k] == i){
                        cout << "o";
                        print = true;
                    }
                }
                if(!print)
                    cout << " ";

            }



            if (j == width-1)
                cout << "#" << endl;
        }
    }
    cout << " ";
    for (int i = 0; i < width; i++)
        cout << "#";
    cout << endl;
    cout << "Your Score is: "<< score << endl;
    cout << "a button is Left." << endl;
    cout << "d button is Right." << endl;
    cout << "w button is Up." << endl;
    cout << "p button is Pause." << endl;
    cout << "r button is to teleport at the start point. (Your points will be lost.)" << endl;
    cout << "m button is Exit." << endl;


}

void Input(){
    if(_kbhit()){
        switch(_getch()){
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'p':
            dir = PAUSE;
            break;
        case 'r':
            dir = RESET;
            break;
        case 'm':
            gameOver = true;
            break;


          }

    }



}

void Logic(){
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for(int i = 1; i < lenTail; i++){
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch(dir){
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        case PAUSE:
            while(dir == LEFT || dir == RIGHT || dir == UP || dir == DOWN){
                x += 0;
                y += 0;
                break;
            }
            break;
        case RESET:
            gameOver = true;
            Setup();
            while(!gameOver){
                Draw();
                Input();
                Logic();
                break;
    }
        default:
            break;
    }
     if (x > width || x < 0 || height < y || y < 0)
        gameOver = true;
     //for (int i = 0; i < lenTail; i++)
     //if(tailX[i] == x && tailY[i] == y)
       //gameOver = true;
     if (x == fruitX && y == fruitY){
        score += 10;
        index++;
        fruitX = rand() % width;
        fruitY = rand() % height;
        lenTail++;

     } if ((x == barX && y == barY) || (x == barXX && y == barYY)){
          score -= 10;
          if (score < 0){
            gameOver = true;

        }
           barX = rand() % width;
           barY = rand() % height;
           barXX = rand() % width;
           barYY = rand() % width;
           lenTail--;

     }

}

int main(){
   cout << "Game is starting in: ";
   for (int timer = 3; timer >= 1; --timer){
        cout << " " << timer;
        Sleep(1200);
    }
    Setup();
    while(!gameOver){
        Draw();
        Input();
        Logic();
        //Sleep(10);



    }

    return 0;
}


