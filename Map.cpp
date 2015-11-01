#include "Map.h"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstdlib>

using namespace std;

Map :: Map()
{

}
Map::Map(char* fileName)
{
    FileLocation = fileName;
    mapSizeX = 20;
    mapSizeY = 21;
    setMap();
}

Map::~Map()
{
	for(int row =0; row < mapSizeX; row++)
		delete [] MapContents[row];

	delete [] MapContents;
}

void Map::setMap()
{
    MapContents = new char*[mapSizeX];
    for(int i=0;i<mapSizeX;i++)
    {
        MapContents[i] = new char[mapSizeY];
    }
    ifstream myReadFile;
    myReadFile.open(FileLocation);
    string output;
    int count = 0;
    if (myReadFile.is_open())
    {
        while (getline(myReadFile, output))
        {
            strcpy(MapContents[count], output.c_str());
            count++;
        }
    }
    myReadFile.close();
}
void Map::printMap()
{
  std::ofstream mapFile;
  mapFile.open("TempMap.txt", std::ofstream::out | std::ofstream::trunc);

  mapFile << mapSizeX << endl;
  for(int i = 0; i < mapSizeX;i++)
  {
      mapFile << MapContents[i] << endl;
      cout << MapContents[i] << endl;
  }
  mapFile.close();
}

bool Map :: Move (int one, int two, int three, int four)
{
	int initial_x = one;
	int initial_y = two;
	int new_x = three;
	int new_y = four;

	if (new_x>=mapSizeX || new_x<=0 || new_y>=mapSizeY || new_y<=0)
		return false;
        else if (MapContents[new_x][new_y]==' ' )
		return true;
	else
		return false;

}

int Map :: getXLength()
{
	return mapSizeX;
}

int Map :: getYLength()
{
	return mapSizeY;
}

void Map :: setCell(int x, int y, int x2, int y2,char c)
{
	if (c == '@')
	{

		char temp = MapContents[x][y];
		MapContents[x][y] = MapContents[x2][y2];
		MapContents[x2][y2] = temp;

	} else {

		if(MapContents[x][y] == '#')
			MapContents[x][y] = '#';
		else
			MapContents[x][y] = ' ';

		MapContents[x2][y2] = c;

	}
}

void Map:: notify(Subject *map)
{
	Subject::notify(map);
}

char Map :: getCell(int x, int y)
{
	return MapContents[x][y];
}

char Map :: testCell(int x, int y)
{
	char tempC;

	tempC = getCell(x-1,y);

	if(tempC == 'E' || tempC == 'O' || tempC == 'G' || tempC == 'M' || tempC == 'S' || tempC == 'T')
		return 'a';

	tempC = getCell(x,y-1);
	if(tempC == 'E' || tempC == 'O' || tempC == 'G' || tempC == 'M' || tempC == 'S' || tempC == 'T')
		return 'l';

	tempC = getCell(x+1,y);
	if(tempC == 'E' || tempC == 'O' || tempC == 'G' || tempC == 'M' || tempC == 'S' || tempC == 'T')
		return 'b';

	tempC = getCell(x,y+1);
	if(tempC == 'E' || tempC == 'O' || tempC == 'G' || tempC == 'M' || tempC == 'S' || tempC == 'T')
		return 'r';

	else
		return 'c';
}

void Map :: clear(int x, int y)
{
  MapContents[x][y] = ' ';
}
