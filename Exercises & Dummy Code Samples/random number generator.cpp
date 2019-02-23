#include <iostream>
#include <conio.h>
#include <ctime> // for the time(0) function;
#include <random> //for uniform_int_distribution, default_random_engine, mt19937
using namespace std;
int main()
{
    default_random_engine RandomNumberGenerator; //creating an UNSEEDED random number generating engine
    uniform_int_distribution<int> RollingDice (1,6); // setting the boundaries, of the random number generator;
    //uniform_real_distribution<float> -> for floating numbers;

    for(int i=0;i<5;i++)
    {
        cout << "Unseeded Random generator:  " << RollingDice(RandomNumberGenerator) << endl;
        /*
        - function is called like this: RollingDice(RandomNumberGenerator); the only argument is the random engine;
        - there can be multiple random generators in a software.

        IMPORTANT: the way that an UNSEEDED random number generator works, is that a random number is generated, only once,
        and that is when the program runs for the very first time.
        */
    }

    //Creating a SEEDED RANDOM GENERATOR;
    //a seeded random generator - is a random number generator that depends on a variable that changes all the time
    //as an example: time is changing every second.
    cout << endl;
    default_random_engine RandNumGen(time(0));
    for (int i=0; i<5; i++)
    {
        //this will generate a random number each time.
        cout << "Seeded Random Generator: " << RollingDice(RandNumGen) << endl;
    }

    //Another random engine generator MT:
    cout << endl;

    mt19937 randomEngine(time(0)); // the seed is time(0);
    uniform_int_distribution<int> mtSeed(1,6);

    for (int i=0; i<5; i++)
    {
        //this will generate a random number each time.
        cout << "Seeded MT Random Generator with time(0): " << mtSeed(randomEngine) << endl;
    }
    cout << endl;
    //MT random_engine seeded with random_device rd;
    random_device rd; //creating an object;
    mt19937 randomEngineSRD(rd()); // the seed is rd();
    uniform_int_distribution<int> mtSeedRandDevice(1,6);

    for (int i=0; i<5; i++)
    {
        //this will generate a random number each time.
        cout << "Seeded MT Random Generator with random_device: " << mtSeedRandDevice(randomEngineSRD) << endl;
    }

    getch();
    return 0;
}
