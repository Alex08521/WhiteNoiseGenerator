#include "MInterface.h"

MInterface::MInterface()
{
    if (!font.loadFromFile("19168.ttf"))
    {
        exit(1);
    }
}

void MInterface::MainProces()
{
    window.create(VideoMode(800, 600), "Cryptograph", Style::Default);
    window.setFramerateLimit(60);

    int XcoordOfCircle1 = 100;
    int XcoordOfCircle2 = 100;
    int sizeHorizontal = XcoordOfCircle1 - 95;
    bool generate = false;
    //Цикл интерфейса
    while (window.isOpen())
    {
        //Инициализация необходимых элементов
        Vector2i pixelPos = mouse.getPosition(window);
        text.setString("");
        text.setFont(font);
        text.setCharacterSize(30);
        text.setStyle(Text::Bold);
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed || keyboard.isKeyPressed(keyboard.Escape))
            {
                window.close();
            }

            if (event.type == Event::MouseButtonPressed)
            {
                //Копка Generate
                if (mouse.isButtonPressed(mouse.Left) && pixelPos.x > 280 && pixelPos.x < 405 && pixelPos.y > 400 && pixelPos.y < 445)
                {
                    if (generate == false)
                    {
                        generate = true;
                    }
                }
            }
        }

        window.clear();

        //Инициализация текста в окне
        text.setFillColor(Color(220, 220, 220));
        text.setCharacterSize(40);
        text.setString(L"Enter message on this field:");
        text.setPosition(105, 10);
        window.draw(text);
        text.setFillColor(Color(220, 220, 220));
        text.setCharacterSize(20);
        text.setString(L"Press 'Escape' to close programm");
        text.setPosition(10, 570);
        window.draw(text);

        rectangle.setFillColor(Color(0, 0, 0));
        rectangle.setOutlineThickness(4);
        rectangle.setOutlineColor(Color(220, 220, 220));
        rectangle.setPosition(Vector2f(20, 60));
        rectangle.setSize(Vector2f(760, 300));
        window.draw(rectangle);

        rectangle.setOutlineColor(Color(0, 0, 0));

        /*
        short sizeHbuf = sizeHorizontal;

        wchar_t a[] = L"0000";

        if (sizeHorizontal > 999)
        {
            a[0] = a[0] + (sizeHorizontal / 1000);
            sizeHorizontal = sizeHorizontal - (sizeHorizontal / 1000 * 1000);
        }
        else
        {
            a[0] = 48;
        }
        if (sizeHorizontal > 99)
        {
            a[1] = a[1] + (sizeHorizontal / 100);
            sizeHorizontal = sizeHorizontal - (sizeHorizontal / 100 * 100);
        }
        else
        {
            a[1] = 48;
        }
        if (sizeHorizontal > 9)
        {
            a[2] = a[2] + (sizeHorizontal / 10);
            sizeHorizontal = sizeHorizontal - (sizeHorizontal / 10 * 10);
        }
        else
        {
            a[2] = 48;
        }
        if (sizeHorizontal >= 0)
        {
            a[3] = a[3] + sizeHorizontal;
        }
        else
        {
            a[3] = 48;
        }
        //std::wcout << "Size = " << sizeHbuf << std::endl;

        /*sizeHorizontal = sizeHbuf;

        text.setString(a);
        text.setPosition(500, 10);
        window.draw(text);
        //Ползунок 1

        rectangle.setFillColor(Color(180, 180, 180));
        rectangle.setSize(Vector2f(519, 10));
        rectangle.setPosition(Vector2f(100, 100));
        window.draw(rectangle);

        if (pixelPos.x > XcoordOfCircle1 && pixelPos.x < XcoordOfCircle1 + 20 && pixelPos.y > 40 && pixelPos.y < 150)
        {
            circle.setFillColor(Color(250, 250, 250));
            circle.setRadius(10);
            if (mouse.isButtonPressed(mouse.Left) && pixelPos.x > 70 && pixelPos.x < 700)
            {
                XcoordOfCircle1 = pixelPos.x - 10;
                if (XcoordOfCircle1 < 96)
                {
                    XcoordOfCircle1 = 96;
                }
                if (XcoordOfCircle1 > 608)
                {
                    XcoordOfCircle1 = 608;
                }
                sizeHorizontal = XcoordOfCircle1 * 4 - 384;
            }
            circle.setPosition(Vector2f(XcoordOfCircle1, 95));
            window.draw(circle);
        }
        else
        {
            circle.setFillColor(Color(200, 200, 200));
            circle.setRadius(10);
            if (mouse.isButtonPressed(mouse.Left) && pixelPos.x > 70 && pixelPos.x < 700 && pixelPos.y > 40 && pixelPos.y < 150)
            {
                XcoordOfCircle1 = pixelPos.x - 10;
                if (XcoordOfCircle1 < 96)
                {
                    XcoordOfCircle1 = 96;
                }
                if (XcoordOfCircle1 > 608)
                {
                    XcoordOfCircle1 = 608;
                }
                sizeHorizontal = XcoordOfCircle1 * 4 - 384;
            }
            circle.setPosition(Vector2f(XcoordOfCircle1, 95));
            window.draw(circle);
        }
        short reX = sizeHorizontal;
        short reY = sizeHorizontal;
        //Демонстрация соотношения сторон поля
        if (square == false)
        {
            rectangle.setSize(Vector2f(sizeHorizontal / 10, (sizeHorizontal / 10) / 16 * 9));
            rectangle.setPosition(Vector2f(370 - (sizeHorizontal / 20), 224 - (sizeHorizontal / 40)));
            window.draw(rectangle);
            reY = sizeHorizontal / 16 * 9;
        }
        else
        {
            rectangle.setSize(Vector2f(sizeHorizontal / 10, sizeHorizontal / 10));
            rectangle.setPosition(Vector2f(370 - (sizeHorizontal / 20), 274 - (sizeHorizontal / 20)));
            window.draw(rectangle);
        }

        //Кнопка 16*9
        if (square == false)
        {
            rectangle.setSize(Vector2f(40, 20));
            rectangle.setPosition(Vector2f(350, 150));
            rectangle.setFillColor(Color(180, 80, 80));
            window.draw(rectangle);
        }
        else
        {
            rectangle.setFillColor(Color(180, 180, 180));
            rectangle.setSize(Vector2f(40, 20));
            rectangle.setPosition(Vector2f(350, 150));
            window.draw(rectangle);
        }
        text.setFillColor(Color(20, 20, 20));
        text.setCharacterSize(14);
        text.setString(L"16*9");
        text.setPosition(350, 150);
        window.draw(text);
/*
        //Ползунок 2

        rectangle.setFillColor(Color(180, 180, 180));
        rectangle.setSize(Vector2f(500, 10));
        rectangle.setPosition(Vector2f(100, 150));
        window.draw(rectangle);

        if (pixelPos.x > XcoordOfCircle2 && pixelPos.x < XcoordOfCircle2 + 20 && pixelPos.y > 145 && pixelPos.y < 165)
        {
            circle.setFillColor(Color(250, 250, 250));
            circle.setRadius(10);
            if (mouse.isButtonPressed(mouse.Left) && pixelPos.x > 105 && pixelPos.x < 600)
            {
                XcoordOfCircle2 = pixelPos.x - 10;
            }
            circle.setPosition(Vector2f(XcoordOfCircle2, 145));
            window.draw(circle);
        }
        else
        {
            circle.setFillColor(Color(200, 200, 200));
            circle.setRadius(10);
            if (mouse.isButtonPressed(mouse.Left) && pixelPos.x > 105 && pixelPos.x < 600 && pixelPos.y > 140 && pixelPos.y < 230)
            {
                XcoordOfCircle2 = pixelPos.x - 10;
            }
            circle.setPosition(Vector2f(XcoordOfCircle2, 145));
            window.draw(circle);
        }
*/
        //Кнопка запуска генерации
        if (generate == true)
        {
            rectangle.setFillColor(Color(0, 0, 0));
            rectangle.setPosition(Vector2f(0, 395));
            rectangle.setSize(Vector2f(800, 205));
            window.draw(rectangle);

            text.setFillColor(Color(250, 50, 50));
            text.setCharacterSize(40);
            text.setString(L"crypting...");
            text.setPosition(260, 400);
            window.draw(text);
            window.display();

            mapGen.resize(256, 256);

            for (int i = 0; i < 1; i++)
            {
                mapGen.generate();
            }

            rectangle.setFillColor(Color(0, 0, 0));
            rectangle.setPosition(Vector2f(0, 395));
            rectangle.setSize(Vector2f(800, 205));
            window.draw(rectangle);

            text.setFillColor(Color(250, 250, 250));
            text.setCharacterSize(40);
            text.setString(L"crypted!");
            text.setPosition(260, 400);
            window.draw(text);
            window.display();

            
            if (!mapGen.save("Messages"))
            {

                rectangle.setFillColor(Color(0, 0, 0));
                rectangle.setPosition(Vector2f(0, 395));
                rectangle.setSize(Vector2f(800, 205));
                window.draw(rectangle);

                text.setFillColor(Color(250, 50, 50));
                text.setCharacterSize(40);
                text.setString(L"Saving failed");
                text.setPosition(260, 400);
                window.draw(text);
                text.setCharacterSize(20);
                text.setString(L"press 'Enter' to continue");
                text.setPosition(260, 450);
                window.draw(text);
                window.display();
            }
            else
            {
                rectangle.setFillColor(Color(0, 0, 0));
                rectangle.setPosition(Vector2f(0, 395));
                rectangle.setSize(Vector2f(800, 205));
                window.draw(rectangle);

                text.setFillColor(Color(250, 50, 50));
                text.setCharacterSize(40);
                text.setString(L"Saving complete");
                text.setPosition(260, 400);
                window.draw(text);
                text.setCharacterSize(20);
                text.setString(L"press 'Enter' to continue");
                text.setPosition(260, 450);
                window.draw(text);
                window.display();
            }

            while (window.waitEvent(event))
            {
                if (event.type == Event::KeyPressed)
                {
                    break;
                }
            }

            generate = false;
        }

        if (pixelPos.x > 280 && pixelPos.x < 405 && pixelPos.y > 400 && pixelPos.y < 445)
        {
            text.setFillColor(Color(250, 250, 250));
            text.setCharacterSize(40);
            text.setString(L"Send");
            text.setPosition(280, 400);
            window.draw(text);
        }
        else
        {
            text.setFillColor(Color(220, 220, 220));
            text.setCharacterSize(40);
            text.setString(L"Send");
            text.setPosition(280, 400);
            window.draw(text);
        }
       
/*
        //Кнопка выбора соотношения сторон 4:3
        if (pixelPos.x > 150 && pixelPos.x < 207 && pixelPos.y > 400 && pixelPos.y < 445)
        {
            text.setFillColor(Color(250, 250, 250));
            text.setCharacterSize(40);
            text.setString(L"4:3");
            text.setPosition(150, 400);
            window.draw(text);
        }
        else
        {
            text.setFillColor(Color(220, 220, 220));
            text.setCharacterSize(40);
            text.setString(L"4:3");
            text.setPosition(150, 400);
            window.draw(text);
        }

        //Кнопка выбора соотношения сторон 16:9
        if (pixelPos.x > 550 && pixelPos.x < 607 && pixelPos.y > 400 && pixelPos.y < 445)
        {
            text.setFillColor(Color(250, 250, 250));
            text.setCharacterSize(40);
            text.setString(L"16:9");
            text.setPosition(550, 400);
            window.draw(text);
        }
        else
        {
            text.setFillColor(Color(220, 220, 220));
            text.setCharacterSize(40);
            text.setString(L"16:9");
            text.setPosition(550, 400);
            window.draw(text);
        }
*/
        //std::cout << "X = " << pixelPos.x << ", Y = " << pixelPos.y << std::endl;
        window.display();
    }
}
