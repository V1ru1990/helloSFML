#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
#include "Engine/Platform.h"
#include "Engine/World.h"
#include <iostream>

Platform::Platform()
    : m_x(DEFAULT_X)
    , m_y(DEFAULT_Y)
    , m_width(DEFAULT_WIDTH)
    , m_height(DEFAULT_HEIGHT)
    , m_textureLoaded(false)
{

}

void Platform::loadTexture(const char* filename)
 //подгрузка .png для спрайта
 {
    m_texturePlatform.loadFromFile(filename);
    m_textureLoaded = true;
    m_spritePlatform.setTexture(m_texturePlatform);
 }

 void Platform::setPosition(int x, int y) 
 // задаем конкретную позицию платформе
 {
    m_x = x;
    m_y = y;
    m_spritePlatform.setPosition(m_x, m_y);
    
 }

 void Platform::setRandomPosition() 
 //задаем случайную позицию для платформы
 {
    std::srand(std::time(0));
    int random_x = rand() % WINDOW_WIDTH;
    int random_y = rand() % WINDOW_LENGTH;
    Platform::setPosition(random_x, random_y);
 }

 //////////////////////////////////////////////////////////////////////////////////////////
 // задаем скорость для скроллинга окна
 void Platform::move(float dy) 
 
 {
    m_y += dy;
    Platform::update(WINDOW_LENGTH);

    /*
    ///////////////////////////////////////////////////////////////////////////////////////
    if (m_y > WINDOW_LENGTH + BUFFER_ZONE)
    {
        std::srand(std::time(nullptr));
        m_y = TOP_POINT; // TOP_POINT = -50
        m_x = rand() % WINDOW_WIDTH; 
    }
    //проверяем, ушла ли платформа слишком далеко вниз за пределы экрана
    ///////////////////////////////////////////////////////////////////////////////////////

    m_spritePlatform.setPosition(m_x, m_y);
    */
 }
 ///////////////////////////////////////////////////////////////////////////////////////////

 void Platform::reset() 
 //сброс позиции на рандомные координаты
 {
    Platform::setPosition(rand() % WINDOW_WIDTH, TOP_POINT);
 }

 sf::FloatRect Platform::getBounds() const 
 //определение касания
 {
    return sf::FloatRect(m_x, m_y, m_width, m_height);
 }

 void Platform::draw(sf::RenderWindow& window)
 {
    if (m_textureLoaded)
    {
        window.draw(m_spritePlatform);
    }
 }

 bool Platform::isOffScreen(int windowHeight) const 
 //проверка на окно
 {
    return m_y > WINDOW_WIDTH + BUFFER_ZONE;
 }

 void Platform::update(int screenHeight)
 {
    if (isOffScreen(WINDOW_LENGTH))
    {
        Platform::reset();
    }
    m_spritePlatform.setPosition(m_x, m_y);
 }

 bool Platform::isTextureLoaded()
 {
    return m_textureLoaded;
 }

 void Platform::showPosition() const
 {
    std::cerr << m_x << " " << m_y << std::endl;
 }