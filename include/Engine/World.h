#pragma once 
#include <vector>
#include "SFML/Graphics.hpp"
#include "Engine/Platform.h"

class World
{
    std::vector<Platform> m_platforms; //веквторы для хранения объектов класса Platform
    int m_platformCount; //несет информацию о количестве платформ
    int m_worldWidth, m_worldHeight; //информация об игровом поле
    int m_scrollThreshold; //порог для скроллинга, если игрок вверх - мир вниз

    sf::Texture m_platformTexture; //текстура для всех платформ

    public:
        World(); //default constructor
        World(int width, int height, int count); //конструктор

        void loadPlatforms(const char* filename); //загрузка текстуры для всех платформ
        void update(float dy, int windowHeight); //обновление состояния мира
        void scroll(float dy); // преместить платформы при скроллинге

        void render(sf::RenderWindow& window); // отрисовка всех платформ

        std::vector<Platform>& getPlatforms(); //возвращает список платформ

        void generateInitialPlatforms(); //создание начальных платформ
        void respawnPlatform(Platform& platform); //пересоздать платформу сверху

};