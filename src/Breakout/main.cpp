#include "pch.h"
#include "main.h"

#include "Game/Ball.h"
#include "Game/Level.h"
#include "Game/Menu.h"

#define LEVEL_NUMBER 6

int main()
{

	std::srand(static_cast<unsigned>(std::time(nullptr)));
	
	// Nouveau System de Niveaux
	Menu menu;
	Level* level;

	menu.Display();
	Game::getScoreManager().LoadText();
	Game::SetLife(3);
	while (Game::getWindow().isOpen())
	{
		level = new Level();
		level->Load( (rand()%LEVEL_NUMBER)+1 );
		//level->Load(10);
		delete level;
	} 
  
	return 0;
	
}
