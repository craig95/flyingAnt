#include "adapter.h"
#include "subject.h"
#include "singlePlayerGame.h"

void Subject :: attach(Unit* observer)
{
	mObservers.push_back(observer);
}

void Subject :: detach(Unit* observer)
{
	for(int i = 0; i < mObservers.size(); i++)
	{
		if(observer == mObservers[i])
			mObservers.erase(mObservers.begin() +i);
	}
}

void Subject :: notify(Subject* map)
{
	bool validMove= false;
		int ran;
	SinglePlayerGame * game = new SinglePlayerGame();

	for(int i= 1; i < mObservers.size(); i++)
	{
		validMove= false;
		while(!validMove)
		{
			srand (time(NULL));
			ran = rand() % 3;
			//cout << mObservers[i]->getX() << " " << mObservers[i]->getY() << map->Move(mObservers[i]->getX(),mObservers[i]->getY(),mObservers[i]->getX()-1,mObservers[i]->getY()) << endl;
			switch (ran) {
				case 0: if (map->Move(mObservers[i]->getX(),mObservers[i]->getY(),mObservers[i]->getX()-1,mObservers[i]->getY())){
										map->setCell(mObservers[i]->getX(),mObservers[i]->getY(),mObservers[i]->getX()-1,mObservers[i]->getY(),'@');
										mObservers[i]->yourPosition(mObservers[i]->getX()-1,mObservers[i]->getY());
										validMove = true;
									}
									break;

				case 1:	if (map->Move(mObservers[i]->getX(),mObservers[i]->getY(),mObservers[i]->getX(),mObservers[i]->getY()-1)){
										map->setCell(mObservers[i]->getX(),mObservers[i]->getY(),mObservers[i]->getX(),mObservers[i]->getY()-1,'@');
										mObservers[i]->yourPosition(mObservers[i]->getX(),mObservers[i]->getY()-1);
										validMove = true;
									}
									break;

				case 2:	if (map->Move(mObservers[i]->getX(),mObservers[i]->getY(),mObservers[i]->getX()+1,mObservers[i]->getY())){
										map->setCell(mObservers[i]->getX(),mObservers[i]->getY(),mObservers[i]->getX()+1,mObservers[i]->getY(),'@');
										mObservers[i]->yourPosition(mObservers[i]->getX()+1,mObservers[i]->getY());
										validMove = true;
									}
									break;

				case 3: if (map->Move(mObservers[i]->getX(),mObservers[i]->getY(),mObservers[i]->getX(),mObservers[i]->getY()+1)){
										map->setCell(mObservers[i]->getX(),mObservers[i]->getY(),mObservers[i]->getX(),mObservers[i]->getY()+1,'@');
										mObservers[i]->yourPosition(mObservers[i]->getX(),mObservers[i]->getY()+1);
										validMove = true;
									}
									break;

				default:	break;
			}

		}

		char cellTest = map->testCell(mObservers[i]->getX(),mObservers[i]->getY());

		/*if(cellTest != "no")
		{
			healthE = mObservers[i]->getHealth() -( game->takeDamage(healthE ,mObservers[i]->getDescription(),mObservers[0]->getDescription()));
			mObservers[0]->setHealth(healthA);
			mObservers[i]->setHealth(healthE);
		}
		mObservers[i]->yourPosition(ran,ran2);*/
	}


}
