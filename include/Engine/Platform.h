#pragma once
#include <SFML/Graphics.hpp>

class Platform
{
    int m_x, m_y; //координаты позиции платформы
    int m_width, m_height; // размеры 
    sf::Sprite m_spritePlatform;
    sf::Texture& m_texturePlatform;

    public:
        Platform(); //default constructor
        void loadTexture(const char* filename); //подгрузка .png для спрайта
        void setPosition(int x, int y); // задаем конкретную позицию платформе
        void setRandomPosition(int random_x, int random_y); //задаем случайную позицию для платформы
        void move(float dy); // задаем скорость для скроллинга окна
        void reset(int random_x, int random_y); //сброс позиции на рандомные координаты
        sf::FloatRect getBounds() const; //определение касания
        void draw(sf::RenderWindow& window); //отрисовка платформы
        bool isOffScreen(int windowHeight) const; //проверка на окно

};
