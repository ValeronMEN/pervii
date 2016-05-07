#include <SFML/Graphics.hpp>

int main()
{
    // Создаем главное окно приложения
    sf::RenderWindow window(sf::VideoMode(1366, 768), "Pong");

    // Главный цикл приложения
    while(window.isOpen())
    {
        // Обрабатываем события в цикле
        sf::Event event;
        while(window.pollEvent(event))
        {
            // Кроме обычного способа наше окно будет закрываться по нажатию на Escape
            if(event.type == sf::Event::Closed ||
              (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                window.close();
        }

        // Очистка
        window.clear();
        // Тут будут вызываться функции обновления и отрисовки объектов
        // Отрисовка
        window.display();
    }

    return 0;
}
