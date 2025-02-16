#include <pch.h>
#include <fstream>
#include <sstream>
#include "Level.h"
#include "Ball.h"
#include "Border.h"
#include "Brick.h"
#include "Image.h"
#include "Jukebox.h"
#include "Paddle.h"
#include "ScoreManager.h"
#include "Items/BrickItem.h"

class Image;

Level::Level(): m_ShouldClose(false),
				win(nullptr),
				restart(nullptr),
				fissure(nullptr),
				fissureBis(nullptr),
                gameOver(nullptr),
                titleScore(nullptr),
                bestScore(nullptr),
                jukebox(nullptr) {}

Level::~Level()
{
	
	for (Entity* _entity
		: Game::getUpdateSystem().GetAllEntityOfType<Entity>())
	{
		delete _entity;
	}
	delete win;
	delete finalScore;
	delete jukebox;
	delete gameOver;
	delete titleScore;
	delete bestScore;
	delete restart;
}


bool Level::loadLevelFromFile(const std::string& filename)
{
	std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Erreur: impossible d'ouvrir le fichier " << filename << std::endl;
        return false;
    }

	std::string line;
    int rowIndex = 0;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        std::cout << line << std::endl;

        std::stringstream ss(line);
        int colIndex = 0;

        char brickType; 
        while (ss >> brickType) {
            float x = 235.0f + (130 * colIndex);
            float y = 200.0f + (50 * rowIndex);

        	int brickTypeInt = brickType - '0'; 

        	Breakout::Brick* brick = nullptr;
        	switch (brickTypeInt)
        	{
        	case 1:
        		brick = new Breakout::Brick(1, sf::Color::White);
        		break;
        	case 2:
        		brick = new Breakout::Brick(2, sf::Color::Cyan);
        		break;
        	case 3:
        		brick = new Breakout::Brick(3, sf::Color::Yellow);
        		break;
        	case 4:
        		brick = new Breakout::Brick(4, sf::Color::Magenta);
        		break;
        	case 5:
        		brick = new Breakout::BrickItem(rand()%2+1, sf::Color::Green);
        		break;
        	default:
        		brick = new Breakout::Brick(1, sf::Color::White);
        		break;
        	}
        	if (brick != nullptr)
        	{
        		brick->setPosition(sf::Vector2f(x, y));
        	}
        	
            colIndex++;
        }
        rowIndex++;
    }
    
	file.close();
	return true;
}

void Level::Load(int levelIndex)
{
	std::cout << "Load " + std::to_string(levelIndex )<< std::endl;
	std::string levelFilename = Utils::getResourcesPath() + "levels/level" + std::to_string(levelIndex) + ".txt";
    
        if (!loadLevelFromFile(levelFilename)) {
            std::cerr << "Erreur lors du chargement du niveau " << levelIndex << std::endl;
            return;
        }
	
	Start();
}

void Level::Start()
{
	m_ShouldClose = false;
	bool m_WaitToReset = false;
	
    sf::RenderWindow& window = Game::getWindow();
    sf::Clock clock;
	sf::Clock startClock;
	
    Breakout::Ball* ball = new Breakout::Ball();
    ball->setPosition(WINDOW_WIDTH/2, WINDOW_HEIGHT/2 + 200);
	ball->attachTrail();

	Breakout::Paddle* paddle = new Breakout::Paddle();
	Breakout::Border* border = new Breakout::Border();

	jukebox = new Breakout::Jukebox( {&AssetLoader::musicTheme1, &AssetLoader::musicTheme2,
		&AssetLoader::musicTheme3, &AssetLoader::musicTheme4} );

	Image* heart1 = new Image(&AssetLoader::heart, WINDOW_WIDTH - 200, 70, 5, 5, .09);
	Image* heart2 = new Image(&AssetLoader::heart, WINDOW_WIDTH - 325, 70, 5, 5, .09);
	Image* heart3 = new Image(&AssetLoader::heart, WINDOW_WIDTH - 450, 70, 5, 5, .09);
	
	
    while (!m_ShouldClose)
    {
    	if (!window.isOpen())
    	{
    		m_ShouldClose = true;
    	}

    	if (Game::GetBrickNumber() <= 0 && !m_WaitToReset)
    	{
    		if (!m_WaitToReset)
    		{
    			Game::getTweeningSystem().Clear();
    			Win();
    			m_WaitToReset = true;
    		}
    		
    	}
    	
    	if (Game::GetCurrentLife() <= 0 && !m_WaitToReset)
    	{
    		if (!m_WaitToReset)
    		{
    			Game::getRenderSystem().SetColor(sf::Color::Black);
    			Game::getTweeningSystem().Clear();
    			Loose();
    			isLoose = true;

    			Game::SetLife(3);
    			Game::getScoreManager().EndLevel();
    			m_WaitToReset = true;
    		}
    	}
    	
		if (heart2 != nullptr && Game::GetCurrentLife() == 1)
    	{
    		delete heart2;
			heart2=nullptr;
    	}
		if (heart3 != nullptr && Game::GetCurrentLife() <= 2)
    	{
    		delete heart3;
			heart3=nullptr;
    	}
    	
		
        sf::Event event;
        while (window.pollEvent(event))
        {
            Game::getInputSystem().ProcessKey(event.type, event.key.code);
            Game::getInputSystem().ProcessMousseButton(event.type, event.mouseButton.button);

        	if (event.type == sf::Event::Closed)
        	{
        		m_ShouldClose = true;
        		window.close();
        	}

        	if (Game::getInputSystem().GetKeyPressed(sf::Keyboard::Escape))
        	{
        		m_ShouldClose = true;
        		window.close();
        	}

        	if (m_WaitToReset && Game::getInputSystem().GetKeyPressed(sf::Keyboard::Enter))
        	{
        		if (Game::GetBrickNumber() <= 0)
        		{
        			return;
        		}
        		if (Game::GetCurrentLife() <= 0)
        		{
        			return;
        		}
        	}
        }
		
        float dT = clock.restart().asSeconds();

    	sf::View view =  Game::getWindowView();
    	float time = startClock.getElapsedTime().asSeconds();
    	float factor = 0.002 * std::sin((time +5)/0.8)+1;
    	if(!m_WaitToReset) Game::getRenderSystem().SetColor(sf::Color(abs(cos(time/20.0)) * 72,abs(cos(time/15.0)) * 72,abs(cos(time/24.0)) * 72,255));
    	view.setSize(WINDOW_WIDTH * factor, WINDOW_HEIGHT * factor);
    	window.setView(view);

    	jukebox->Update(dT);
    	
        //systems update
        Game::getParticleSystem().Update(dT);
        Game::getTweeningSystem().Tween(dT);
    	Game::getCameraSystem().Update(dT);
        Game::getUpdateSystem().Update(dT);
        Game::getPhysicSystem().Update();
    	Game::getScoreManager().Update(dT);
    	Game::getRenderSystem().Render();
		
        window.display();
    }
	
}

void Level::Win()
{

	for (Entity* _entity
		: Game::getUpdateSystem().GetAllEntityOfType<Entity>())
	{
		delete _entity;
	}
	new Breakout::Border();
	jukebox->PlaySound(&AssetLoader::victorySound);

	finalScore = new Breakout::Text(&AssetLoader::textFont, "Start With " + std::to_string(Game::getScoreManager().GetScore()));
	finalScore->setCharacterSize(80);
	finalScore->setFillColor(sf::Color::Cyan);
	finalScore->setPosition(WINDOW_WIDTH/2-finalScore->getLocalBounds().width/2, WINDOW_HEIGHT/2-finalScore->getLocalBounds().height/2-500);
	
	win = new Breakout::Text(&AssetLoader::textFont, "Level Cleared");
	win->setCharacterSize(80);
	win->setFillColor(sf::Color::Cyan);
	win->setPosition(WINDOW_WIDTH/2-win->getLocalBounds().width/2, WINDOW_HEIGHT/2-win->getLocalBounds().height/2-150);
	
	restart = new Breakout::Text(&AssetLoader::textFont, "[ENTER] Continue");
	restart->setCharacterSize(60);
	restart->setFillColor(sf::Color::Green);
	restart->setPosition(WINDOW_WIDTH/2-restart->getLocalBounds().width/2, WINDOW_HEIGHT/2-restart->getLocalBounds().height/2);
}

void Level::Loose()
{
	for (Entity* _entity
		: Game::getUpdateSystem().GetAllEntityOfType<Entity>())
	{
		delete _entity;
	}
	new Breakout::Border();
	jukebox->PlaySound(&AssetLoader::gameOverSound);
	jukebox->PlayMusic(&AssetLoader::musicDeath);
	
	float posX = rand() % WINDOW_WIDTH - 200;
	float posY = rand() % WINDOW_HEIGHT - 200;
	float rotate = rand() % 360 + 1;
	
	fissure = new Image(&AssetLoader::fissureGameOver, posX - 992/2, posY, 1, 1);
	fissureBis = new Image(&AssetLoader::fissureGameOver, WINDOW_WIDTH/2 + (rand()%WINDOW_WIDTH), (rand()%WINDOW_HEIGHT), 1, 1);
	
	fissureBis->rotate(rotate);
	fissureBis->scale(1.5, 1.5);

	finalScore = new Breakout::Text(&AssetLoader::textFont, "YOUR " + std::to_string(Game::getScoreManager().GetScore()));
	finalScore->setCharacterSize(80);
	finalScore->setFillColor(sf::Color::Cyan);
	finalScore->setPosition(WINDOW_WIDTH/2-finalScore->getLocalBounds().width/2, WINDOW_HEIGHT/2-finalScore->getLocalBounds().height/2-500);
	
	gameOver = new Breakout::Text(&AssetLoader::textFont, "GAME OVER");
	gameOver->setCharacterSize(200);
	gameOver->setFillColor(sf::Color::Yellow);
	gameOver->setPosition(WINDOW_WIDTH/2 - gameOver->getLocalBounds().width/2, WINDOW_HEIGHT/2 - 425);

	titleScore = new Breakout::Text(&AssetLoader::textFont, "BEST SCORES");
	titleScore->setCharacterSize(100);
	titleScore->setFillColor(sf::Color::Green);
	titleScore->setPosition(WINDOW_WIDTH/2 - titleScore->getLocalBounds().width/2, WINDOW_HEIGHT/2 - 140);
	
	bestScore = new Breakout::Text(&AssetLoader::textFont, Game::getScoreManager().DisplayScores());  
	bestScore->setCharacterSize(70);
	bestScore->setFillColor(sf::Color::Green);
	bestScore->setPosition(WINDOW_WIDTH/2 - bestScore->getLocalBounds().width/2, WINDOW_HEIGHT/2 - 40);

	restart = new Breakout::Text(&AssetLoader::textFont, "[ENTER] Restart");
	restart->setCharacterSize(60);
	restart->setFillColor(sf::Color::Yellow);
	restart->setPosition(WINDOW_WIDTH/2-restart->getLocalBounds().width/2, WINDOW_HEIGHT/2-220);
}
