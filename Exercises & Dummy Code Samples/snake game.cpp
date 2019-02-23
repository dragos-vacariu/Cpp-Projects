#include <iostream> // library for cout
#include <conio.h> // library for _getch() and _kbhit()
#include <windows.h> // library for sleep function
#include <ctype.h> // library for tolower function

using namespace std; // for cout and cin functions;
bool gameOver; // global variable to check the game;
const int width = 20; //width of map
const int height = 20; //height of map
int x, y, fruitX, fruitY, score; // x and y - position of snake head; fruitx and fruity - position of the fruit; score - the score;
int tailX[100], tailY[100]; //arrays to store the coordinate of the previous moves/head position;
int nTail; //number of tail segments;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN}; // direction array 
eDirecton dir; // declaration of direction array
void Setup() // function to set the game up;
{
    gameOver = false; // the gameover is false... for the game to start
    dir = STOP; // no move at the starting point;
    x = width / 2; // start position of snake
    y = height / 2; // start position of snake
    fruitX = rand() % width; //random fruit position
    fruitY = rand() % height; // random fruit position
    score = 0; // starting score;
}
void Draw() // function to draw the map and snake;
{
    system("cls"); //system("clear") - for mac; clear the screen;
    for (int i = 0; i < width+2; i++) //draw the upper wall
        cout << "#"; // this is the simbol for the wall;
    cout << endl; // go to next line;
 
    for (int i = 0; i < height; i++) // getting into the matrix;
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0) // draw the left wall;
                cout << "#"; // this is the simbol for the wall;
            if (i == y && j == x) //draw the snake head;
                cout << "O"; // this is the simbol for the snake;
            else if (i == fruitY && j == fruitX) // draw the fruit
                cout << "F"; // this is the simbol for the fruit;
            else
            {
                bool print = false; //firt time declaration of the variable that checks if the tail was printed;
                for (int k = 0; k < nTail; k++) // getting into the array
                {
                    if (tailX[k] == j && tailY[k] == i)// if reached the coordinate of tale
                    {
                        cout << "o"; // print the next segment
                        print = true; //print the next segment
                    }
                }
                if (!print) // if nothing is printed
                    cout << " "; // let be free;
            }
                 
 
            if (j == width - 1) // printing the downside wall
                cout << "#";
        }
        cout << endl; // go to next line;
    }
 
    for (int i = 0; i < width+2; i++) //printing the rightside wall
        cout << "#";
    cout << endl;
    cout << "Score:" << score << endl; // draw the score;
}
void Input() // input function; for the controls;
{
    if (_kbhit()) // if kbhit - keyboard is pressed;
    {
        switch (tolower(_getch())) // switch the value of getch;
        {
        case 'a': // if a was pressed
            dir = LEFT;
            break; 
        case 'd': // if d was pressed
            dir = RIGHT;
            break; 
        case 'w': // if w was pressed
            dir = UP;
            break; 
        case 's': //if s was pressed
            dir = DOWN;
            break;
        case 'x': // if x was pressed
            gameOver = true;
            break;
        }
    }
}
void Logic() // logic function
{
    int prevX = tailX[0]; // declaration of variable that stores the previous position of snake head;
    int prevY = tailY[0]; // declaration of variable that stores the previous position of snake head;
    int prev2X, prev2Y; // declaration of variable that stores the previous position of snake head;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++)  //take a new segment for the snake if the fruit was eaten;
    {
        prev2X = tailX[i]; 
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir) //test the direction;
    {
    case LEFT: // if the direction is left, draw the animation; x--
        x--;
        break;
    case RIGHT: // if the direction is right, draw the animation; x++
        x++;
        break;
    case UP: // if the direction is up; draw the animation; y-- (y decrease because the 0 position is the first line above)
        y--;
        break;
    case DOWN: // if the direction is down, draw the animation y++; the distance to the first line above grows;
        y++; 
        break;
    default: // else do nothing;
        break;
    }
    //if (x > width || x < 0 || y > height || y < 0) //remove the backslashes for the wall to end the game
    //  gameOver = true;
    if (x >= width) x = 0; else if (x < 0) x = width - 1; // going throught walll
    if (y >= height) y = 0; else if (y < 0) y = height - 1; // going throught wall
 
    for (int i = 0; i < nTail; i++) // if you reach the tail, end the game;
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;
 
    if (x == fruitX && y == fruitY) // if you get the fruit;
    {
        score += 10; // increase the score;
        fruitX = rand() % width; // draw the next fruit position
        fruitY = rand() % height; // draw the next fruit position;
        nTail++; // increase the tail
    }
}
int main()
{
    Setup(); // set the game up;
    while (!gameOver) // enter here only if it's not gameover;
    {
        Draw(); // call the draw frunction
        Input(); // call the input function
        Logic(); // call the logic function;
        Sleep(10); //sleep(10); decrease the speed of the snake;
    }
    return 0; //return nothing back;
}
