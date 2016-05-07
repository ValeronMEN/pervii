#include <SFML/Graphics.hpp>

int main()
{
    // ������� ������� ���� ����������
    sf::RenderWindow window(sf::VideoMode(1366, 768), "Pong");

    // ������� ���� ����������
    while(window.isOpen())
    {
        // ������������ ������� � �����
        sf::Event event;
        while(window.pollEvent(event))
        {
            // ����� �������� ������� ���� ���� ����� ����������� �� ������� �� Escape
            if(event.type == sf::Event::Closed ||
              (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                window.close();
        }

        // �������
        window.clear();
        // ��� ����� ���������� ������� ���������� � ��������� ��������
        // ���������
        window.display();
    }

    return 0;
}
