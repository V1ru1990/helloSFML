#pragma once
#include <SFML/Graphics.hpp>


class Player
{
    static constexpr int DEFAULT_PLAYER_X = 400;
    static constexpr int DEFAULT_PLAYER_Y = 300;
    static constexpr int DEFAULT_PLAYER_WIDTH = 80;
    static constexpr int DEFAULT_PLAYER_HEIGHT = 70;

    int m_x, m_y; //координаты объекта
    float m_dx, m_dy; // скорость объекта по осям x и y
    int m_width, m_height; //ширина и высота для коллизии
    sf::Sprite m_spritePlayer; //спрайт объекта
    sf::Texture m_texturePlayer; //текстура в память
    bool m_textureLoaded;
    
    public:
        Player(); //конструктор по умолчанию
        void loadTexture(const char* filename); //загрузка текстуры 
        //с последующей подгрузкой спрайта
        void update(float gravity, int windowHeight); //перемещние по оси ординат
        void moveLeft(); //перемещение влево по оси абсцисс
        void moveRight(); //перемещение вправо по оси абсцисс
        void jump(float jumpPower); //прыжок +
        void setPosition(int x, int y); //задание координат объекту
        sf::Vector2f getPosition() const; //получение координат
        sf::FloatRect getBounds() const; //получение прямоугольника для коллизии
        void draw(sf::RenderWindow& window); //отрисока в окне 
        bool isFalling() const; //проверка на падение
        float getDY() const; //геттер скорости по ординате
        float setDY(float newDY); //сеттре скорость по ординате
};