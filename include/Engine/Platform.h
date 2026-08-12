#pragma once
#include <SFML/Graphics.hpp>


class Platform
{
    static constexpr int DEFAULT_WIDTH = 68;
    static constexpr int DEFAULT_HEIGHT = 14;
    static constexpr int DEFAULT_X = 0;
    static constexpr int DEFAULT_Y = 0;
    
    int m_x, m_y; //координаты позиции платформы
    int m_width, m_height; // размеры 
    sf::Sprite m_spritePlatform;
    sf::Texture m_texturePlatform;
    bool m_textureLoaded;

    public:
        Platform(); //default construct

        void loadTexture(const char* filename); //подгрузка .png для спрайта
        void setPosition(int x, int y); // задаем конкретную позицию платформе
        void setRandomPosition(); //задаем случайную позицию для платформы
        void move(float dy); // задаем скорость для скроллинга окна
        void reset(); //сброс позиции на рандомные координаты
        sf::FloatRect getBounds() const; //определение касания
        void draw(sf::RenderWindow& window); //отрисовка платформы
        bool isOffScreen() const; //проверка на окно
        void update();
        bool isTextureLoaded();

        void showPosition() const;
};
