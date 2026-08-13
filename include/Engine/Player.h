#pragma once
#include <SFML/Graphics.hpp>


class Player
{
    static constexpr int DEFAULT_PLAYER_X = 400;
    static constexpr int DEFAULT_PLAYER_Y = 300;
    static constexpr int DEFAULT_PLAYER_WIDTH = 80;
    static constexpr int DEFAULT_PLAYER_HEIGHT = 70;
    static constexpr float DEFAULT_GRAVITY = 0.2f; 
    static constexpr float DEFAULT_PLAYER_SPEED = 0.0f;
    static constexpr float DEFAULT_MOVE_SPEED = 5.0f;
    static constexpr float DEFAULT_JUMP_POWER = -10.0f;


    float m_x, m_y; //координаты объекта
    float m_dx, m_dy; // скорость объекта по осям x и y
    int m_width, m_height; //ширина и высота для коллизии
    int gravity; //гравитация для игрока (отрицательно - падение, положительно - прыжок)
    sf::Sprite m_spritePlayer; //спрайт объекта
    sf::Texture m_texturePlayer; //текстура в память
    bool m_textureLoaded; //булевая на проверку загрузки текстуры, ПОХЖЕ СДЕЛАТЬ ОТДЕЛЬНЫЙ КЛАСС

    bool m_isOnGround; //булевая на состояние (положительная - на земле, отрицательная - в воздухе)
    
    public:
        Player(); //конструктор по умолчанию
        void loadTexture(const char* filename); //загрузка текстуры 
        //с последующей подгрузкой спрайта
        void update(float gravity); //перемещние по оси ординат
        void handleInput(); //проверяем нажатие клавиши 


        void moveLeft(); //перемещение влево по оси абсцисс
        void moveRight(); //перемещение вправо по оси абсцисс
        void jump(float jumpPower); //прыжок +
        void stopHorizontal();


        void setPosition(float x, float y); //задание координат объекту
        sf::Vector2f getPosition() const; //получение координат
        sf::FloatRect getBounds() const; //получение прямоугольника для коллизии
        void draw(sf::RenderWindow& window); //отрисока в окне 

        bool isOnGround() const; //возвращение значения
        bool isFalling() const; //проверка на падение  

        float getX() const; //геттер на абсциссу
        float getY() const; //геттер на ординату
        float getDX() const; //геттер на скорость по абсциссе
        float getDY() const; //геттер на скорость по ординате

        void setX(float newX); //сеттер на абсциссу
        void setY(float newY); //сеттер на ординату
        void setDX(float newDX); //сеттер на скорость по абсциссе
        void setDY(float newDY); //сеттер скорости по ординате
};