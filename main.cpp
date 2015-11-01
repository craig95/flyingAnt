#include <iostream>
#include<cstdlib>

#include "magicfactory.h"
#include "bludgeoningfactory.h"
#include "piercingfactory.h"
#include "Map.h"
#include "adapter.h"
#include "singlePlayerGame.h"

#include <vector>
#include <cctype>
#include <cstring>

#define RED "\033[31m"
#define RESET "\033[0m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\035[31m"
#define CYAN "\036[36m"
#define WHITE "\033[37m"

using namespace std;

int main()
{
	cout << RESET << endl;
	cout << "***********************************************************************" << endl;
	cout << "********|||||||||||||||||||||||||||||||||||||||||||||||||||||||********"  << endl;
	cout << "********|||||||||||||||||||||||||||||||||||||||||||||||||||||||********"  << endl;
	cout << "********|||||||||||||||||||||||||||||||||||||||||||||||||||||||********" << endl;
	cout << "▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬" << endl;
	cout << "|||||||                       BATTLEGROUND                      |||||||" << endl;
	cout << "▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬" << endl;

	SinglePlayerGame* game = new SinglePlayerGame();
	game->setupSinglePlayerGame();
	game->startGame();
	cout << "Game Over!" << RESET << endl;
}
