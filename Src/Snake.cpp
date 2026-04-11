#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

Texture appleTexture;
Sprite* appleSprite;

Texture headUpTexture, headDownTexture, headLeftTexture, headRightTexture;
Texture bodyUpTexture, bodyDownTexture, bodyLeftTexture, bodyRightTexture;

Sprite* snakeHeadSprite;
Sprite* snakeBodySprite;   // Will be used for body parts later

void ImportAssets()
{
    cout << "Loading all game assets...\n";

    // Load Apple
    if (!appleTexture.loadFromFile("../Assets/Apple.png"))
    cout << "ERROR: Could not load Assets/Apple.png\n";

    // Load Head textures
    if (!headUpTexture.loadFromFile("../Assets/Up.png"))
        cout << "ERROR: Could not load Assets/Up.png\n";
    
    if (!headDownTexture.loadFromFile("../Assets/Down.png"))
        cout << "ERROR: Could not load Assets/Down.png\n";
    
    if (!headLeftTexture.loadFromFile("../Assets/Left.png"))
        cout << "ERROR: Could not load Assets/Left.png\n";
    
    if (!headRightTexture.loadFromFile("../Assets/Right.png"))
        cout << "ERROR: Could not load Assets/Right.png\n";

    // Load Body textures
    if (!bodyUpTexture.loadFromFile("../Assets/UpBody.png"))
        cout << "ERROR: Could not load Assets/UpBody.png\n";
    
    if (!bodyDownTexture.loadFromFile("../Assets/DownBody.png"))
        cout << "ERROR: Could not load Assets/DownBody.png\n";
    
    if (!bodyLeftTexture.loadFromFile("../Assets/LeftBody.png"))
        cout << "ERROR: Could not load Assets/LeftBody.png\n";
    
    if (!bodyRightTexture.loadFromFile("../Assets/RightBody.png"))
        cout << "ERROR: Could not load Assets/RightBody.png\n";

    // Create Sprites AFTER textures are loaded (SFML 3 fix)
    appleSprite = new Sprite(appleTexture);
    snakeHeadSprite = new Sprite(headUpTexture);
    snakeBodySprite = new Sprite(bodyUpTexture);

    // Set default head texture when game starts
    snakeHeadSprite->setTexture(headUpTexture);

    cout << "All assets loaded successfully!\n";
}

void Possision()
{
    // Set positions so we can actually see the textures
    appleSprite->setPosition({400.f, 250.f});     // Place apple somewhere visible

    snakeHeadSprite->setPosition({200.f, 300.f}); // Starting position for snake head
}

void AddKeys()
{
    if (Keyboard::isKeyPressed(Keyboard::Key::D))
    {
        // Move Right
    }
    else if (Keyboard::isKeyPressed(Keyboard::Key::A))
    {
        // Move Left
    }
}

void CreateWindow()
{
    RenderWindow window(VideoMode({800, 600}), "Game"); // Create A Renderable Window
    
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60); // Limit Framerate to 60 FPS
    
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
        window.draw(*appleSprite);
        window.draw(*snakeHeadSprite);
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