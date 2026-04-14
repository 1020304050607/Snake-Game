#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <chrono>

using namespace sf;
using namespace std;

// Making the textures and sprites global
Texture appleTexture;
Sprite* appleSprite;

Texture snakeTexture;
Sprite* snakeSprite;

Texture backgroundTexture;
Sprite* backgroundSprite;

// Adding a movement clock for the snake
Clock movementClock;
float moveDelay = 0.15f; // For GitHub forkers lower the delay = faster the snake
Vector2f direction = {20.0f, 0.0f};

void ImportAssets()
{
    cout << "Loading assets" << std::endl;

    // Load the Apple texture
    if (!appleTexture.loadFromFile("../Assets/Apple.png"))
    cout << "Apple could not be found" << std::endl;

    // Load the snake texture
    if (!snakeTexture.loadFromFile("../Assets/Snake.png"))
        cout << "Snake could not be found" << std::endl;

    // Load the background texture
    if (!backgroundTexture.loadFromFile("../Assets/Background.png"))
        cout << "Background could not be found" << std::endl;
    
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
    snakeSprite->setPosition({290.f, 200.f}); // Starting position for snake head
    
    // Randomizing apple possision
    int appleX = 100.0f + (rand() % 600);
    int appleY = 100.0f + (rand() % 400);

    appleSprite->setPosition(Vector2f(appleX, appleY));

    cout << "apple possision is " << appleX << " and " << appleY << std::endl;
}

void AddKeys()
{
    if (Keyboard::isKeyPressed(Keyboard::Key::D)) // Right
    {
        direction = {20.0f, 0.0f};
        movementClock.restart();
    }

    else if (Keyboard::isKeyPressed(Keyboard::Key::A)) // Left
    {
        direction = {-20.0f, 0.0f};
        movementClock.restart();
    }
    
    else if (Keyboard::isKeyPressed(Keyboard::Key::W)) // Forward
    {
        direction = {0.0f, -20.0f};
        movementClock.restart();
    }
    
    else if (Keyboard::isKeyPressed(Keyboard::Key::S)) // Backward
    {
        direction = {0.0f, 20.0f};
        movementClock.restart();
    }
    
    if (movementClock.getElapsedTime().asSeconds() >= moveDelay)
    {
        snakeSprite->move(direction);
        movementClock.restart();
    }
}

void CreateWindow()
{
    RenderWindow window(VideoMode({800, 600}), "Game"); // Create A Renderable Window
    
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60); // Limit Framerate to 60 FPS
    
    movementClock.restart(); // Restart the clock for movement
    
    while (window.isOpen()) // Create a loop for the window to run
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        
        AddKeys();
        
        window.clear(); // Clearing The window
        
        // Drawing the Apple Textures
        window.draw(*backgroundSprite);
        window.draw(*appleSprite);
        window.draw(*snakeSprite);

        // Display the Window
        window.display();
    }
}

int main()
{
    ImportAssets();
    Possision();
    CreateWindow();
    return 0;
}
