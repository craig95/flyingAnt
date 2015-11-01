#include "singlePlayerGame.h"

int SinglePlayerGame :: amountDamage(int &damage,char ch1, char ch2)
{
	switch (ch1)
	{
		case 'M' : if( ch2 == 'E')
				{
					cout << YELLOW << "MAGE attacks ELEMENTAL!" << RESET << endl;
					damage = 5;
					return 4;
					break;
				}
				else if(ch2 == 'O')
				{
					cout << YELLOW << "MAGE attacks OGRE!" << RESET << endl;
					damage = 5*2;
					return 5/2;
					break;
				}
				else if(ch2 == 'G')
				{
					cout << YELLOW << "MAGE attacks GOBLIN!" << RESET << endl;
					damage = 5/2;
					return 12;
					break;
				}
		case 'S' :if( ch2 == 'E')
				{
					cout << RED << "SOLDIER attacks ELEMENTAL!" << RESET << endl;
					damage = 8/2;
					return 4;
					break;
				}
				else if(ch2 == 'O')
				{
					cout << RED << "SOLDIER attacks OGRE!" << RESET << endl;
					damage = 8;
					return 5;
					break;
				}
				else if(ch2 == 'G')
				{
					cout << RED << "SOLDIER attacks GOBLIN!" << RESET << endl;
					damage = 8;
					return 12/2;
					break;
				}

		case 'T': if( ch2 == 'E')
				{
					cout << BLUE << "THIEF attacks ELEMENTAL!" << RESET << endl;
					damage = 10*2;
					return 4/2;
					break;
				}
				else if(ch2 == 'O')
				{
					cout << BLUE << "THIEF attacks OGRE!" << RESET << endl;
					damage = 10/2;
					return 5;
					break;
				}
				else if(ch2 == 'G')
				{
					cout << BLUE << "THIEF attacks GOBLIN!" << RESET << endl;
					damage = 10;
					return 12;
					break;
				}
	}
	return 0;
}

void SinglePlayerGame :: setupSinglePlayerGame()
{
	bool validChoice = false;
	int force;
  srand (time(NULL));
	//Creating the player character. The player is a single unit moving on the map.

	//Asks the user which force he would like to be
	cout << endl;
	cout << RED << "You are the master of light who needs to defend the world from darkness! \nChoose your character type: \n1. Mage \n2. Thief \n3. Soldier\n";
	cin >> force;
	
	cout << RESET ;

	while(!validChoice)
	{

		if (force == 1) //The player will be a mage (Creates a mage)
		{
			UnitFactory * troop= new MagicFactory;
			Unit * player = troop-> createPlayer();
			persons.push_back(player);

			cout << YELLOW << "\nYour Character: ";
			cout << YELLOW <<  player->getDescription()<< RESET << endl;
			validChoice = true;
		}else if(force == 2)//The player will be a soldier (Creates a theif)
		{
			UnitFactory * troop= new PiercingFactory;
			Unit * player = troop-> createPlayer();
			persons.push_back(player);

			cout << RED << "\nOYour Character: ";
			cout << RED << player->getDescription()<< RESET << endl;
			validChoice = true;
		}else if(force == 3)//The player will be a thief (Creates a soldier)
		{
			UnitFactory * troop = new BludgeoningFactory;
			Unit * player = troop-> createPlayer();
			persons.push_back(player);

			cout << BLUE << "\nYour Character: ";
			cout << BLUE << player->getDescription()<< RESET << endl;
			validChoice = true;
		}else {
			cout << CYAN << "\nInvalid choice! \n\nChoose an option: \n1. Mage \n2. Thief\n3. Soldier \n" << endl;
			cin >> force;
			cout << RESET;
		}

	}

	int random;
	int track = 0;


	//Creates the enemy

	//Generates a number to randomly choose a enemy type
	srand (time(NULL));
	random = rand() % 3 + 1;

	if(random == 1)// Creates elementals
	{
		//Generates a number to determine the amount of enemys
		srand (time(NULL));
		numberOfEnemys = rand() % 4 + 1;

		//Tell the user the type and ammount of enemies
		cout << BLUE << "\nThe master of dark forces senses your presence! He will summon " << numberOfEnemys << " elemental(s)" << endl;
		//creates the factory
		UnitFactory * evil= new MagicFactory;

		//creaates the first enemy
		Unit * monster = evil-> createMob();
		monsters.push_back(monster);

		//cout the enemy description
		cout << RED << "The Enemy: ";
		cout << monster->getDescription()<< RESET << endl;

		//clones the first to make the other enemy
		for(int num = 1; num < numberOfEnemys; num++)
		{
			monsters.push_back(monster->clone());
		}
	}


	 if(random == 2)//creates goblins
	 {
		//Generates a number to determine the amount of enemys
		srand (time(NULL));
		numberOfEnemys = rand() % 4 +1;

		//Tell the user the type and ammount of enemies
		cout << MAGENTA << "\n\nThe master of dark forces senses your presence! He will summon " << numberOfEnemys << " goblin(s)" << endl;
		//creates the factory
		UnitFactory * evil= new PiercingFactory;

		//creaates the first enemy
		Unit * monster = evil-> createMob();
		monsters.push_back(monster);

		//cout the enemy description
		cout << MAGENTA << "\nThe Enemy: ";
		cout << monster->getDescription()<< RESET << endl;

		//clones the first to make the other enemy
		for(int num = 1; num < numberOfEnemys; num++)
		{
			monsters.push_back(monster->clone());
		}
	}

	if(random == 3)//creates ogres
	{
		//Generates a number to determine the amount of enemys
		srand (time(NULL));
		numberOfEnemys = rand() % 4 +1;

		//Tell the user the type and ammount of enemies
		cout << CYAN << "\n\nThe master of dark forces senses your presence! He will summon " << numberOfEnemys << " ogre(s)" << endl;
		//creates the factory
		UnitFactory * evil= new BludgeoningFactory;

		//creaates the first enemy
		Unit * monster = evil-> createMob();
		monsters.push_back(monster);

		//cout the enemy description
		cout << CYAN <<  "\nThe Enemy: ";
		cout << monster->getDescription()<< RESET << endl;

		//clones the first to make the other enemy
		for(int num = 1; num < numberOfEnemys; num++)
		{
			monsters.push_back(monster->clone());
		}
	}

	//All the units have now been created
	//The map will now be loaded in
	const int SIZE = 20;
	char name[SIZE];
	char * filename= name;

	cout << GREEN <<  "\nEnter the file name of the map you wish to load \nOR type 'r' to generate a random map:";
	cin >> name;

	//creates the map
	map = new Map(filename);

	//attaches the units to the map
	map->attach(persons[0]);
	for (int i=0;i<numberOfEnemys;i++)
	map->attach(monsters[i]);

	adapterA = new Adapter(map,persons[0]);

	cout<< GREEN << "\nMap Loading..." << endl;

	int ran, ran2,ran3, ran4;
	bool set = false;
	srand (time(NULL));
	ran = rand() %  map->getXLength();
	ran2 = rand() % map->getYLength();
	ran3 = rand() %  map->getXLength();
	ran4 =  rand() % map->getYLength();

	
	while(!set)
	{
		//cout << ran3 << " " << ran4  <<endl;
		ran3 = rand() %  map->getXLength();
		ran4 =  rand() % map->getYLength();
		set = adapterA->Move(0,0,ran3,ran4);
	}

	
	adapterA->setCell(0,0,ran3,ran4,persons[0]->getDescription());

	persons[0]->yourPosition(ran3,ran4);

	bool validCell;
	for (int i = 0; i < monsters.size(); i++) {

		validCell = false;

		srand (time(NULL));
		ran3 = rand() %  map->getXLength();
		ran4 =  rand() % map->getYLength();
		while(!validCell)
		{
			//cout << "Here" << endl;
			srand (time(NULL));
			ran3 = rand() %  map->getXLength();
			ran4 =  rand() % map->getYLength();
			//cout << ran3 << " " << ran4 << endl;
			if (map->Move(0,0,ran3,ran4)){
				map->setCell(0,0,ran3,ran4,monsters[i]->getDescription());
				monsters[i]->yourPosition(ran3,ran4);
				validCell = true;
			}
		}
	}
	
	
	map->printMap();

}

void SinglePlayerGame :: startGame()
{
	char direction;
	bool validDirection = false;

	while (persons[0]->getHealth() > 0 && monsters.size()>0)//While the player is alive the game will continue
	{
		validDirection = false;

		while (validDirection==false){
			cout << GREEN << "Use W A S or D to move: ";//Ask the user which direction he would like to move to
			cin >> direction;
			direction = tolower(direction);

			//Tries to move the player one space in that direction
			switch (direction) {
				case 'w': if (map->Move(persons[0]->getX(),persons[0]->getY(),persons[0]->getX()-1,persons[0]->getY())){
										map->setCell(persons[0]->getX(),persons[0]->getY(),persons[0]->getX()-1,persons[0]->getY(),'@');
										persons[0]->yourPosition(persons[0]->getX()-1,persons[0]->getY());
										validDirection = true;
									}
									break;

				case 'a':	if (map->Move(persons[0]->getX(),persons[0]->getY(),persons[0]->getX(),persons[0]->getY()-1)){
										map->setCell(persons[0]->getX(),persons[0]->getY(),persons[0]->getX(),persons[0]->getY()-1,'@');
										persons[0]->yourPosition(persons[0]->getX(),persons[0]->getY()-1);
										validDirection = true;
									}
									break;

				case 's':	if (map->Move(persons[0]->getX(),persons[0]->getY(),persons[0]->getX()+1,persons[0]->getY())){
										map->setCell(persons[0]->getX(),persons[0]->getY(),persons[0]->getX()+1,persons[0]->getY(),'@');
										persons[0]->yourPosition(persons[0]->getX()+1,persons[0]->getY());
										validDirection = true;
									}
									break;

				case 'd': if (map->Move(persons[0]->getX(),persons[0]->getY(),persons[0]->getX(),persons[0]->getY()+1)){
										map->setCell(persons[0]->getX(),persons[0]->getY(),persons[0]->getX(),persons[0]->getY()+1,'@');
										persons[0]->yourPosition(persons[0]->getX(),persons[0]->getY()+1);
										validDirection = true;
									}
									break;

				default:	break;
			}
			map->printMap();
			cout << RESET;

			//Test if the player is next to another unit, if it is it will attempt to attack it.
			char tempCell = map->testCell(persons[0]->getX(),persons[0]->getY());
			Unit * unitToAttack;
			if (tempCell!='c') {
				cout << RED << "Enemy is in sight! Attacking!" << RESET <<  endl;
				switch (tempCell) {
					case 'a':	unitToAttack = findUnitAtCords(persons[0]->getX()-1,persons[0]->getY());
										break;
					case 'b':	unitToAttack = findUnitAtCords(persons[0]->getX()+1,persons[0]->getY());
										break;
					case 'l':	unitToAttack = findUnitAtCords(persons[0]->getX(),persons[0]->getY()-1);
										break;
					case 'r':	unitToAttack = findUnitAtCords(persons[0]->getX(),persons[0]->getY()+1);
										break;
				}


				//Setup the chain of responsibility
				Unit * previous;
				int count = 0;
				while (count < monsters.size()) {
					if (count==0 && monsters[count]!=unitToAttack) {
						unitToAttack->setNextInChain(monsters[0]);
						previous = monsters[0];
					} else if (monsters[count]!=unitToAttack){
						previous->setNextInChain(monsters[count]);
						previous = monsters[count];
					} else if (monsters[0]==unitToAttack)
						previous = unitToAttack;
					++count;
				}
				previous->setNextInChain(0);
				int damageToEnemy=0;
				int damageToPlayer = amountDamage(damageToEnemy,persons[0]->getDescription(),unitToAttack->getDescription());

				cout << WHITE << "You deal " << damageToEnemy << " damage. Remaining Enemy Health: ";
				if (unitToAttack->getHealth()-damageToEnemy>0) {
					cout << unitToAttack->getHealth()-damageToEnemy << endl;
				}
				unitToAttack->takeDamage(damageToEnemy);
				for (int i = 0; i < monsters.size(); i++) {
					if (monsters[i]->getHealth()==0){
						map->clear(monsters[i]->getX(),monsters[i]->getY());
						monsters.erase (monsters.begin()+i);
					}
				}

				persons[0]->setNextInChain(0);
				persons[0]->takeDamage(damageToPlayer);
				cout << RED << "You take " << damageToPlayer << " damage. Remaining Health: " << persons[0]->getHealth() << RESET << endl;

			}

			cout << BLUE << "The dark forces are moving are moving!" << RESET <<  endl;
			map->notify(map);
			map->printMap();

		}
	}

	if (persons[0]->getHealth()<1){
		cout << RED << "\nYou were sadly defeated. The dark forces are taking over." << RESET << endl;
	} else {
		cout << YELLOW <<  "You Win! The darkness has been defeated!" << RESET << endl;
	}
}

Unit* SinglePlayerGame :: findUnitAtCords(int x, int y)
{
	int count=0;

	while (count < monsters.size())
	{
		if (monsters[count]->getX()==x && monsters[count]->getY()==y)
			return monsters[count];
		++count;
	}
	return 0;
}
