#include <SFML/Graphics.hpp>

int main()
{

    //Create display window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Gravity Simulation");

    //declare some variables
    float mass[5];
    int j = 10;
    float damping = 0.8;
    sf::Vector2f velocity[5];
    sf::Vector2f acceleration(0, 0.0005);

    //Create an array of balls
    sf::CircleShape ball[5];
    for (int i = 0, j = 10; i < 5; i++, j += 10)
    {
        ball[i].setRadius(10 + j);
        ball[i].setPosition(40 * i + j * 10, 30);
        ball[i].setFillColor(sf::Color::Red);
        mass[i] = i + 3;
    }
   
    //Main game loop
    while (window.isOpen())
    {
        //Event handler to close window
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed)
                window.close();
        }

        //Update the velocity and position of the ball

        for (int i = 0; i < 5; i++)
        {
            velocity[i].y += acceleration.y * mass[i];
            ball[i].move(velocity[i]);

            //Check if the ball hits the ground
            if (ball[i].getPosition().y + ball[i].getRadius() * 2 >= window.getSize().y)
            {

                //Apply damping effect to the velocity
                velocity[i].y = -velocity[i].y * damping;
                ball[i].setPosition(ball[i].getPosition().x, window.getSize().y - ball[i].getRadius() * 2);
            }
        }

        //Clear the window
        window.clear();
        for (int i = 0; i < 5; i++)
        {
            //Draw balls
            window.draw(ball[i]);
        }

        //Display the window
        window.display();
    }

    return 0;
}
