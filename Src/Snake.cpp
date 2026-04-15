#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <chrono>
#include <vector>

using namespace sf;
using namespace std;

// Making the textures and sprites global
Texture appleTexture;
Sprite* appleSprite;

Texture snakeTexture;
Sprite* snakeSprite;

Texture backgroundTexture;
Sprite* backgroundSprite;

bool ifappleeaten = false;

// Adding a movement clock for the snake
Clock movementClock;
float moveDelay = 0.25f; // For GitHub forkers lower the delay = faster the snake starts
Vector2f direction = {20.0f, 0.0f};

// Starting player score
int player_score = 0;
Font font;
Text scoreText(font, "", 30);

void ImportAssets()
{
    cout << "Loading assets" << std::endl;

    // Load the Apple texture
    if (!appleTexture.loadFromFile("../Assets/Apple.png"))
    {    
        cout << "Apple could not be found" << std::endl;
    }
    
    // Load the snake texture
    if (!snakeTexture.loadFromFile("../Assets/Snake.png"))
    {    
        cout << "Snake could not be found" << std::endl;
    }
    
    // Load the background texture
    if (!backgroundTexture.loadFromFile("../Assets/Background.png"))
    {    
        cout << "Background could not be found" << std::endl;
    }
    
    // Create Sprites after the textures are created
    backgroundSprite = new Sprite(backgroundTexture);
    appleSprite = new Sprite(appleTexture);
    snakeSprite = new Sprite(snakeTexture);

    // Set default head texture when game starts
    backgroundSprite->setTexture(backgroundTexture);
    appleSprite->setTexture(appleTexture);
    snakeSprite->setTexture(snakeTexture);

    cout << "All assets loaded successfully!" << std::endl;
}

void Possision()
{
    // Set positions so we can actually see the textures
    snakeSprite->setPosition(Vector2f{290.f, 200.f}); // Starting position for snake head
    
    // Randomizing apple possision
    int appleX = 100.0f + (rand() % 300); // x possision
    int appleY = 100.0f + (rand() % 200); // y possision

    appleSprite->setPosition(Vector2f(appleX, appleY));

    cout << "apple possision is " << appleX << " and " << appleY << std::endl;
}

void AddKeys()
{   
    // AWSD and Arrow Movement
    if (Keyboard::isKeyPressed(Keyboard::Key::D) ||  Keyboard::isKeyPressed(Keyboard::Key::Right)) // Right
    {
        direction = {20.0f, 0.0f};
    }

    else if (Keyboard::isKeyPressed(Keyboard::Key::A) ||  Keyboard::isKeyPressed(Keyboard::Key::Left)) // Left
    {
        direction = {-20.0f, 0.0f};
    }
    
    else if (Keyboard::isKeyPressed(Keyboard::Key::W) || Keyboard::isKeyPressed(Keyboard::Key::Up)) // Forward
    {
        direction = {0.0f, -20.0f};
    }
    
    else if (Keyboard::isKeyPressed(Keyboard::Key::S) || Keyboard::isKeyPressed(Keyboard::Key::Down)) // Backward
    {
        direction = {0.0f, 20.0f};
    }
    
    if (movementClock.getElapsedTime().asSeconds() >= moveDelay)
    {
        snakeSprite->move(direction);
    }
}

void Hitboxes()
{
    // Getting the full boxxes of the snake and the apple
    FloatRect snakeBox = snakeSprite->getGlobalBounds();
    FloatRect appleBox = appleSprite->getGlobalBounds();

    // Adding a centered hitbox that follow the apple because my image is uneven
    FloatRect applehitbox;
    
    applehitbox.position.x = appleBox.position.x + (appleBox.size.x / 2) - 15; // Adding the hit box at center at half width
    applehitbox.position.y = appleBox.position.y + (appleBox.size.y / 2) - 15; // Adding the hit box at center at half right
    
    // Adding a 30x30 box in the middle of the apple 
    applehitbox.size.x = 30;
    applehitbox.size.y = 30;

    // As upper adding a centered hitbox at the head of the snake
    FloatRect snakehitbox;

    snakehitbox.position.x = snakeBox.position.x + (snakeBox.size.x / 2) - 10;
    snakehitbox.position.y = snakeBox.position.y + (snakeBox.size.y / 2) - 10;
    snakehitbox.size.x = 20;
    snakehitbox.size.y = 20;

    // Appling the apple hit box (EDIT: Wanted to add a score board and this 
    // if statement is perfect for adding a score board too i am to lazy to make a new one)
    if (!ifappleeaten && snakehitbox.findIntersection(applehitbox).has_value())
    {
        player_score++;
        cout << "Player's score is: " << player_score << std::endl;
        
        int appleX = 100.0f + (rand() % 300);
        int appleY = 100.0f + (rand() % 300);
        
        appleSprite->setPosition(Vector2f(appleX, appleY));
        
        cout << "apple possision is " << appleX << " and " << appleY << std::endl;
        
        ifappleeaten = true;
    }

    else if (ifappleeaten && !snakehitbox.findIntersection(applehitbox).has_value())
    {
        ifappleeaten = false;
    }

    // Adding wall hit boxes (its broken idk why please help)
    else if (snakeBox.position.x < -150 ||
        snakeBox.position.y < -150 ||
        snakeBox.position.x + snakeBox.size.x > 980 ||
        snakeBox.position.y + snakeBox.size.y > 800)
    {
        cout << "you hitted the wall" << std::endl;
    }
}

void ScoreBoard()
{
    // Load the arial font
    if (!font.openFromFile("../Assets/arial.ttf"))
    {    
        cout << "Could not find arial font" << std::endl;
    }

    scoreText = Text(font, "Score: 0", 30);
    scoreText.setFillColor(Color::Black);
    scoreText.setPosition(sf::Vector2f(10.f, 10.f));
}

void CreateWindow()
{
    RenderWindow window(VideoMode({800, 600}), "Game"); // Create A Renderable Window
    
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(15); // Set at 60 FPS for great performance while not cooking the CPU 

    while (window.isOpen()) // Create a loop for the window to run
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        
        AddKeys();
        Hitboxes();

        window.clear(); // Clearing The window
        
        // Drawing the Apple Textures
        window.draw(*backgroundSprite);
        window.draw(*appleSprite);
        window.draw(*snakeSprite);
        
        // Deawing the score
        window.draw(scoreText);
        
        // Display the Window
        window.display();
        
    }
}

int main()
{
    ImportAssets();
    Possision();
    ScoreBoard();
    CreateWindow();

    // Clear memory
    delete backgroundSprite;
    delete appleSprite;
    delete snakeSprite;

    return 0;
}
