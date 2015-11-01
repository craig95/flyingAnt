#ifndef RANDOMMAPGENERATOR_H
#define RANDOMMAPGENERATOR_H

#include<iostream>
#include<fstream>

using namespace std;

class Map;

const int SIZE = 16;
char name[SIZE] = "createdMap.txt";
char * file = name;

class RandomMapGenerator
{
	public:
		char *  GenerateMap(int x, int y)
		{
			int ran;
			
			ofstream createdMap;
			createdMap.open ("createdMap.txt");
			  
			createdMap << "#####################\n";
			    
			for(int row = 1; row < x; row++)
			{
				for(int col = 0; col < y; col++)
				{
					ran = rand() % 10;
					
					if(col == 0)
						createdMap << "#";
					else if(col == 20)
						createdMap << "#\n";
					else if(ran == 3)
						createdMap << "#";
					else if (row == 19)
						createdMap << "#";
					else
						createdMap << " ";
					    
				}
			}
			
			cout << name << endl;
			
			createdMap.close();
			return file;
		}
		
		
		
		
};

#endif