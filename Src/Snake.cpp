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
Sprite* snakeBodySprite;

Texture BackgroundTexture;
Sprite* BackgroundSprite;

void ImportAssets()
{
    cout << "Loading assets" << std::endl;

    // Load Apple
    if (!appleTexture.loadFromFile("../Assets/Apple.png", false, IntRect({100, 100}, {100, 100})))
    cout << "could not found Apple.png" << std::endl;

    // Load Head textures
    if (!headUpTexture.loadFromFile("../Assets/Up.png"))
        cout << "could not found Up.png" << std::endl;
    
    if (!headDownTexture.loadFromFile("../Assets/Down.png"))
        cout << "could not found Down.png" << std::endl;
    
    if (!headLeftTexture.loadFromFile("../Assets/Left.png"))
        cout << "could not found Left.png" << std::endl;
    
    if (!headRightTexture.loadFromFile("../Assets/Right.png"))
        cout << "could not found Right.png" << std::endl;

    // Load Body textures
    if (!bodyUpTexture.loadFromFile("../Assets/UpBody.png"))
        cout << "could not found UpBody.png" << std::endl;
    
    if (!bodyDownTexture.loadFromFile("../Assets/DownBody.png"))
        cout << "could not found DownBody.png" << std::endl;
    
    if (!bodyLeftTexture.loadFromFile("../Assets/LeftBody.png"))
        cout << "could not found LeftBody.png" << std::endl;
    
    if (!bodyRightTexture.loadFromFile("../Assets/RightBody.png"))
        cout << "could not found RightBody.png" << std::endl;
    
    if (!BackgroundTexture.loadFromFile("../Assets/Background.png"))
        cout << " could not found background.png" << std::endl;

    // Create Sprites after the textures are created
    appleSprite = new Sprite(appleTexture);
    snakeHeadSprite = new Sprite(headUpTexture);
    snakeBodySprite = new Sprite(bodyUpTexture);
    BackgroundSprite = new Sprite(BackgroundTexture);

    // Set default head texture when game starts
    snakeHeadSprite->setTexture(headUpTexture);
    BackgroundSprite->setTexture(BackgroundTexture);

    cout << "All assets loaded successfully!\n";
}

void Possision()
{
    // Set positions so we can actually see the textures
    appleSprite->setPosition({400.f, 250.f}); // Place apple somewhere visible

    snakeHeadSprite->setPosition({290.f, 200.f}); // Starting position for snake head
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
        window.draw(*BackgroundSprite);
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
