#include <iostream>
#include <conio.h>

using namespace std;

/*
While processing a game loop, there are lots of statements to be checked, so in order to use those statements, variables
that will hold a certain value will be created. Example:
int GamePlay =1;
int PauseGame = 2;
int ExitGame = 3;

So in this way the statements can be checked, to see when the game should be paused, should run, or should exit. As you see
above, the variables that are used needs to have different values.

An ENUM is a way to enclose a bunch of constants, an ENUM guarantees that every variable inside it, will have different values.
Example: an ENUM with the variables above, can be created as follows:
enum GameStates {GamePlay, PauseGame, ExitGame};
So the synthax is:
enum <name> {states/members};
*/

//Creating a GLOBAL enum:
enum GameStates {GamePlay, PauseGame, ExitGame}; //the elements will take as constant value the position inside the enum;
//In this case: GamePlay = 0; PauseGame=1; ExitGame=2;

/*
ENUM Members cannot be initialized with values: Example GamePlay = 5, this will give compilation error.
Instead the ENUM can be initialized only as follows:
GameStates=ExitGame;
In this case the active value of the ENUM will be ExitGame;
SO the synthax is : <enum name> = <enum member>;

An ENUM Class is an ENUM that will use the scope resolution and an object of the ENUM class for assignments as above.
Example:
GameStates gameStates=GameStates::ExitGame;

An ENUM Class will make possible that you can have multiple ENUMS with the same MEMBERS. So we could have for example:
enum class GameState {Exit, MainMenu};
enum class SoftwareState (Exit, MainMenu);
Without using an ENUM Class this could not be possible because, the TWO MEMBERS will conflict to each other
(compilation error).

Synthax to create an ENUM Class:
enum class <name> { member1, member2...}
An ENUM cannot be forward declared, unless it's an ENUM Class. So only ENUM Classes can be forward declared.

To change the default value of an ENUM Member which consist in it's position on the ENUM, you can do as follows:

enum GameState {MainMenu=5, GamePlay=7, GameExit, GamePaused}; //the two uninitialized members follow gets the value of the
previous member+1; so GameExit will be 8, GamePause will be 9;
*/

int main()
{
    cout << "GamePlay value: " << GamePlay << endl; // this is 0;
    cout << "PauseGame value: " << PauseGame << endl; // this is 1;
    cout << "ExitGame value: " << ExitGame << endl; // this is 2;
    getch();
    return 0;
}
