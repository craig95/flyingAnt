#include "singlePlayerGame.h"

int SinglePlayerGame :: amountDamage(int &damage,char ch1, char ch2)
{
	switch (ch1)
	{
		case 'M' : if( ch2 == 'E')
				{
					cout << "MAGE attacks ELEMENTAL!" << endl;
					damage = 5;
					return 4;
					break;
				}
				else if(ch2 == 'O')
				{
					cout << "MAGE attacks OGRE!" << endl;
					damage = 5*2;
					return 5/2;
					break;
				}
				else if(ch2 == 'G')
				{
					cout << "MAGE attacks GOBLIN!" << endl;
					damage = 5/2;
					return 12;
					break;
				}
		case 'S' :if( ch2 == 'E')
				{
					cout << "SOLDIER attacks ELEMENTAL!" << endl;
					damage = 8/2;
					return 4;
					break;
				}
				else if(ch2 == 'O')
				{
					cout << "MSOLDIER attacks OGRE!" << endl;
					damage = 8;
					return 5;
					break;
				}
				else if(ch2 == 'G')
				{
					cout << "SOLDIER attacks GOBLIN!" << endl;
					damage = 8;
					return 12/2;
					break;
				}

		case 'T': if( ch2 == 'E')
				{
					cout << "THIEF attacks ELEMENTAL!" << endl;
					damage = 10*2;
					return 4/2;
					break;
				}
				else if(ch2 == 'O')
				{
					cout << "THIEF attacks OGRE!" << endl;
					damage = 10/2;
					return 5;
					break;
				}
				else if(ch2 == 'G')
				{
					cout << "THIEF attacks GOBLIN!" << endl;
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

	while(!validChoice)
	{

		if (force == 1) //The player will be a mage (Creates a mage)
		{
			UnitFactory * troop= new MagicFactory;
			Unit * player = troop-> createPlayer();
			persons.push_back(player);

			cout << "\nYour Character: ";
			cout << player->getDescription()<< endl;
			validChoice = true;
		}else if(force == 2)//The player will be a soldier (Creates a theif)
		{
			UnitFactory * troop= new PiercingFactory;
			Unit * player = troop-> createPlayer();
			persons.push_back(player);

			cout << "\nOYour Character: ";
			cout << player->getDescription()<< endl;
			validChoice = true;
		}else if(force == 3)//The player will be a thief (Creates a soldier)
		{
			UnitFactory * troop = new BludgeoningFactory;
			Unit * player = troop-> createPlayer();
			persons.push_back(player);

			cout << "\nYour Character: ";
			cout << player->getDescription()<< endl;
			validChoice = true;
		}else {
			cout << "\nInvalid choice! \n\nChoose an option: \n1. Mage \n2. Thief\n3. Soldier \n" << endl;
			cin >> force;
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
		cout << "\nThe master of dark forces senses your presence! He will summon " << numberOfEnemys << " elemental(s)" << endl;
		//creates the factory
		UnitFactory * evil= new MagicFactory;

		//creaates the first enemy
		Unit * monster = evil-> createMob();
		monsters.push_back(monster);

		//cout the enemy description
		cout << "The Enemy: ";
		cout << monster->getDescription()<< endl;

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
		cout << "\n\nThe master of dark forces senses your presence! He will summon " << numberOfEnemys << " goblin(s)" << endl;
		//creates the factory
		UnitFactory * evil= new PiercingFactory;

		//creaates the first enemy
		Unit * monster = evil-> createMob();
		monsters.push_back(monster);

		//cout the enemy description
		cout << "\nThe Enemy: ";
		cout << monster->getDescription()<< endl;

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
		cout << "\n\nThe master of dark forces senses your presence! He will summon " << numberOfEnemys << " ogre(s)" << endl;
		//creates the factory
		UnitFactory * evil= new BludgeoningFactory;

		//creaates the first enemy
		Unit * monster = evil-> createMob();
		monsters.push_back(monster);

		//cout the enemy description
		cout << "\nThe Enemy: ";
		cout << monster->getDescription()<< endl;

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

	cout << "\nEnter the file name of the map you wish to load: ";
	cin >> name;

	//creates the map
	map = new Map(filename);

	//attaches the units to the map
	map->attach(persons[0]);
	for (int i=0;i<numberOfEnemys;i++)
	map->attach(monsters[i]);

	adapterA = new Adapter(map,persons[0]);

	cout<< "\nMap Loading..." << endl;

	int ran, ran2,ran3, ran4;
	bool set = false;
	srand (time(NULL));
	ran = rand() %  map->getXLength();
	ran2 = rand() % map->getYLength();
	ran3 = rand() %  map->getXLength();
	ran4 =  rand() % map->getYLength();

	while(!set)
	{

		ran3 = rand() %  map->getXLength();
		ran4 =  rand() % map->getYLength();
		set = adapterA->Move(ran,ran2,ran3,ran4);
	}

	adapterA->setCell(ran,ran2,ran3,ran4,persons[0]->getDescription());

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
			cout << "Use W A S or D to move: ";//Ask the user which direction he would like to move to
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

			//Test if the player is next to another unit, if it is it will attempt to attack it.
			char tempCell = map->testCell(persons[0]->getX(),persons[0]->getY());
			Unit * unitToAttack;
			if (tempCell!='c') {
				cout << "Enemy is in sight! Attacking!" << endl;
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

				cout << "You deal " << damageToEnemy << " damage. Remaining Enemy Health: ";
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
				cout << "You take " << damageToPlayer << " damage. Remaining Health: " << persons[0]->getHealth() << endl;

			}

			cout << "The dark forces are moving are moving!" << endl;
			map->notify(map);
			map->printMap();

		}
	}

	if (persons[0]->getHealth()<1){
		cout << "\nYou were sadly defeated. The dark forces are taking over." << endl;
	} else {
		cout << "You Win! The darkness has been defeated!" << endl;
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
