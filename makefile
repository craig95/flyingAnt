main.out:    singlePlayerGame.h singlePlayerGame.cpp adapter.h Map.h Map.cpp subject.h subject.cpp player.cpp bludgeoningfactory.h bludgeoningfactory.cpp elemental.cpp elemental.h goblin.cpp goblin.h mage.cpp mage.h magicfactory.cpp magicfactory.h main.cpp monster.h ogre.cpp ogre.h piercingfactory.cpp piercingfactory.h player.h soldier.cpp soldier.h thief.cpp thief.h unit.cpp unit.h UnitImp.h RandomMapGenerator.h unitfactory.h
		g++ -g singlePlayerGame.cpp Map.cpp subject.cpp player.cpp bludgeoningfactory.cpp elemental.cpp goblin.cpp mage.cpp magicfactory.cpp main.cpp ogre.cpp piercingfactory.cpp soldier.cpp thief.cpp unit.cpp -o main.out

run: main.out
	./main.out
