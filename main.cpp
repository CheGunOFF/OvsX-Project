#include "header.h"

using namespace sf;
using namespace std;

int menu();
void boxSelect();
void drawBG();
void showSlot();
void resetSlot();
bool vectorTest(bool arg);
void tempCrossCircle();
void selectAndWrite(int slotNum);
sf::RenderWindow window(VideoMode(320, 350), L"OvsX", Style::Default);

sf::RectangleShape rect;
sf::RectangleShape rect2;
sf::RectangleShape rect3;
sf::RectangleShape cross;
sf::RectangleShape cross2;
sf::CircleShape circle;

sf::RectangleShape rectTest; // test

sf::Font font;
sf::Vector2i mousePos;
sf::String playerInput;
sf::Text playerText;

char slot[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
string rating[10][2] = {};
bool playerSlot[] = {false, false};
bool boolMenu = false;


bool playerTester = false;

const int SIZE = 9;

// pos.x, pos.y of boxes
int selectPos[][SIZE] = {
    {10, 10},
    {110, 10},
    {210, 10},
    {10,  110},
    {110, 110},
    {210, 110},
    {10,  210},
    {110, 210},
    {210, 210}
};
int main()
{
    font.loadFromFile("Arial.ttf");
    Clock clock;
    
    sf::Text text("RATING:         POS:", font);
    sf::String playerInput;
    sf::Text playerText(' ', font, 10);
    sf::Text strTime(' ', font, 10);

    text.setCharacterSize(10);
    text.setFillColor(sf::Color::White);
    text.setPosition(Vector2f(10, 315));
    
    strTime.setPosition(Vector2f(10, 325));

    rectTest.setSize(Vector2f(40, 40)); // test
    rectTest.setOrigin(Vector2f()); // test
    rectTest.setPosition(Vector2f(11, 11)); // test
    rectTest.setFillColor(Color(255, 10, 10));

    
    rect3.setSize(Vector2f(100, 100));
    //rect3.setOrigin(Vector2f(20, 20));
    rect3.setFillColor(Color(190, 190, 190));
    rect3.setPosition(Vector2f(-110, 10));
    rect3.setOutlineThickness(-1.0);
    rect3.setOutlineColor(Color(90, 90, 90));

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;

        bool testBool = false;

        //std::cout << time << "\n";
        strTime.setString(to_string(time));
        
        Event event;

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) window.close();
        }

        mousePos = sf::Mouse::getPosition(window);

        if (playerSlot[0] != true && playerSlot[1] != true) {
            menu();
            tempCrossCircle();
        }
        else {
            drawBG();
            boxSelect();
            
            showSlot();
            window.draw(text);
            window.draw(strTime);
            window.draw(playerText);
        }
        window.display();
    }
    return 0;
}
void tempCrossCircle() {
    cross.setSize(Vector2f(2, 90));
    cross.setFillColor(Color(50, 50, 50));
    cross.setOrigin(cross.getSize() / 2.f);
    cross.setRotation(-45);
    cross.setPosition(Vector2f(rect2.getPosition().x - 50, rect2.getPosition().y + 50)); // pos

    cross2.setSize(Vector2f(2, 90));
    cross2.setFillColor(Color(50, 50, 50));
    cross2.setOrigin(cross2.getSize() / 2.f);
    cross2.setRotation(45);
    cross2.setPosition(Vector2f(rect2.getPosition().x - 50, rect2.getPosition().y + 50)); // pos

    circle.setPosition(Vector2f(rect2.getPosition().x + 50, rect2.getPosition().y + 50));
    circle.setRadius(32);
    circle.setFillColor(Color(50, 50, 50, 0));
    circle.setOutlineThickness(2);
    circle.setOutlineColor(Color(50, 50, 50));
    circle.setOrigin(Vector2f(32, 32));
}
int menu()
{
    boolMenu = true;
    int mPosx;
    int mPosy;

    rect2.setPosition(Vector2f(50, 110));
    rect2.setSize(Vector2f(100, 100));
    rect2.setFillColor(Color(190, 190, 190, 10));
    rect2.setOutlineThickness(-1.0);
    rect2.setOutlineColor(Color(90, 90, 90));

    int a = 600; 
    // BG
    rect.setSize(Vector2f(a / 2.f, a / 2.f));
    rect.setOrigin(Vector2f(a / 2.f, a / 2.f));
    //rect.setRotation(80.0);
    rect.setFillColor(Color(90, 90, 90));
    rect.setPosition(Vector2f(310, 310));
    rect.setOutlineThickness(5.0);
    rect.setOutlineColor(Color(50, 50, 50));
    
   

    window.draw(rect);
    window.draw(rect2);

    rect2.setPosition(Vector2f(150, 110));
    window.draw(rect2);
    window.draw(rect3);

    window.draw(cross);
    window.draw(cross2);
    window.draw(circle);
    
    
    
    /*
    если выбрано и нажато - то выбор.

    */
    
    
    if (mousePos.x > 50 && mousePos.y > 110 && mousePos.x < 150 && mousePos.y < 210) {
        rect3.setPosition(Vector2f(50, 110));


        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            playerSlot[0] = true;

            //choise(Player, 0);
        }  
    } else if (mousePos.x > 150 && mousePos.y > 110 && mousePos.x < 250 && mousePos.y < 210) {
        rect3.setPosition(Vector2f(150, 110));

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            playerSlot[1] = true;

            //choise(Player, 0);
        }
    }
    else {
        rect3.setPosition(Vector2f(-110, 10)); // hide if not 

    }
    boolMenu = false;

    sleep(milliseconds(50));
    return 0;
}
bool vectorTest(bool arg) {
    return !arg;
}
void boxSelect()
{
    int a;
    int b;
    int mPosx;
    int mPosy;


    if (mousePos.x > 10 && mousePos.y > 10 && mousePos.x < 110 && mousePos.y < 110) {
        a = selectPos[0][0];
        b = selectPos[0][1];
        rect3.setPosition(Vector2f(a, b));
        selectAndWrite(0);

    } else if (mousePos.x > 110 && mousePos.y > 10 && mousePos.x < 210 && mousePos.y < 110) {
        a = selectPos[1][0];
        b = selectPos[1][1];
        rect3.setPosition(Vector2f(a, b));
        selectAndWrite(1);
        
    }
    else if (mousePos.x > 210 && mousePos.y > 10 && mousePos.x < 310 && mousePos.y < 110) {
        a = selectPos[2][0];
        b = selectPos[2][1];
        rect3.setPosition(Vector2f(a, b));
        selectAndWrite(2);
        
        

    }
    else if (mousePos.x > 10 && mousePos.y > 110 && mousePos.x < 110 && mousePos.y < 210) {
        a = selectPos[3][0];
        b = selectPos[3][1];
        rect3.setPosition(Vector2f(a, b));
        selectAndWrite(3);
       

    }
    else if (mousePos.x > 110 && mousePos.y > 110 && mousePos.x < 210 && mousePos.y < 210) {
        b = selectPos[4][1];
        a = selectPos[4][0];
        rect3.setPosition(Vector2f(a, b));
        selectAndWrite(4);
    

    }
    else if (mousePos.x > 210 && mousePos.y > 110 && mousePos.x < 310 && mousePos.y < 210) {
        a = selectPos[5][0];
        b = selectPos[5][1];
        rect3.setPosition(Vector2f(a, b));
        selectAndWrite(5);

    }
    else if (mousePos.x > 10 && mousePos.y > 210 && mousePos.x < 110 && mousePos.y < 310) {
        a = selectPos[6][0];
        b = selectPos[6][1];
        rect3.setPosition(Vector2f(a, b));
        selectAndWrite(6);
      

    }
    else if (mousePos.x > 110 && mousePos.y > 210 && mousePos.x < 210 && mousePos.y < 310) {
        a = selectPos[7][0];
        b = selectPos[7][1];
        rect3.setPosition(Vector2f(a, b));
        selectAndWrite(7);
        


    }
    else if (mousePos.x > 210 && mousePos.y > 210 && mousePos.x < 310 && mousePos.y < 310) {
        a = selectPos[8][0];
        b = selectPos[8][1];
        rect3.setPosition(Vector2f(a, b));
        selectAndWrite(8);

      
    }


    window.draw(rect3);
}
void drawBG()
{

    int a = 600;
    
    rect.setSize(Vector2f(a / 2.f, a / 2.f));
    rect.setOrigin(Vector2f(a / 2.f, a / 2.f));
    //rect.setRotation(80.0);
    rect.setFillColor(Color(100, 100, 100));
    rect.setPosition(Vector2f(310, 310));
    rect.setOutlineThickness(5.0);
    rect.setOutlineColor(Color(50, 50, 50));

    rect2.setSize(Vector2f(100, 100));
    rect2.setFillColor(Color(150, 150, 150));
    rect2.setPosition(Vector2f(210, 10));
    rect2.setOutlineThickness(-1.0);
    rect2.setOutlineColor(Color(90, 90, 90));

    rect3.setSize(Vector2f(100, 100));
    rect3.setFillColor(Color(190, 190, 190));
    rect3.setPosition(Vector2f(-110, 10));
    rect3.setOutlineThickness(-1.0);
    rect3.setOutlineColor(Color(90, 90, 90));

    cross.setSize(Vector2f(2, 90));
    cross.setFillColor(Color(90, 90, 90));
    cross.setOrigin(cross.getSize() / 2.f);
    cross.setRotation(-45);
    cross.setPosition(Vector2f((10 + 110) / 2.f, (10 + 110) / 2.f)); // center pos
    cross.setPosition(Vector2f(-110, -10)); // hiden pos

    cross2.setSize(Vector2f(2, 90));
    cross2.setFillColor(Color(90, 90, 90));
    cross2.setOrigin(cross2.getSize() / 2.f);
    cross2.setRotation(45);
    //cross2.setPosition(Vector2f((10 + 110) / 2.f, (10 + 110) / 2.f)); // center pos
    cross2.setPosition(Vector2f(-110, -10)); // hiden pos

    circle.setPosition(Vector2f(-110, -110));
    circle.setRadius(32);
    circle.setFillColor(Color(90, 90, 90, 0));
    circle.setOutlineThickness(2);
    circle.setOutlineColor(Color(90, 90, 90));
    circle.setOrigin(Vector2f(32, 32));

    window.clear(Color(20, 20, 20));
    window.draw(rect);
    rect2.setPosition(Vector2f(10, 10));
    window.draw(rect2);
    rect2.setPosition(Vector2f(210, 10));
    window.draw(rect2);
    rect2.setPosition(Vector2f(110, 10));
    window.draw(rect2);
    rect2.setPosition(Vector2f(10, 110));
    window.draw(rect2);
    rect2.setPosition(Vector2f(110, 110));
    window.draw(rect2);
    rect2.setPosition(Vector2f(210, 110));
    window.draw(rect2);
    rect2.setPosition(Vector2f(10, 210));
    window.draw(rect2);
    rect2.setPosition(Vector2f(110, 210));
    window.draw(rect2);
    rect2.setPosition(Vector2f(210, 210));
    window.draw(rect2);
}
void showSlot() 
{
        if (slot[0] == 'x') {
            cross.setPosition(Vector2f((selectPos[0][0] + selectPos[1][0]) / 2.f, (selectPos[0][1] + selectPos[3][1]) / 2.f)); // - get cross position from selectPos (manualy)
            cross2.setPosition(Vector2f((selectPos[0][0] + selectPos[1][0]) / 2.f, (selectPos[0][1] + selectPos[3][1]) / 2.f));
            window.draw(cross);
            window.draw(cross2);
        }
        else if (slot[0] == 'o') {
            circle.setPosition(Vector2f((selectPos[0][0] + selectPos[1][0]) / 2.f, (selectPos[0][1] + selectPos[3][1]) / 2.f)); // - get cross position from selectPos (manualy) 
            window.draw(circle);
        }
        else {
                
        }

        if (slot[1] == 'x') {
            cross.setPosition(Vector2f((selectPos[1][0] + selectPos[2][0]) / 2.f, (selectPos[0][1] + selectPos[3][1]) / 2.f));
            cross2.setPosition(Vector2f((selectPos[1][0] + selectPos[2][0]) / 2.f, (selectPos[0][1] + selectPos[3][1]) / 2.f));
            window.draw(cross);
            window.draw(cross2);
        }
        else if (slot[1] == 'o') {
            circle.setPosition(Vector2f((selectPos[1][0] + selectPos[2][0]) / 2.f, (selectPos[0][1] + selectPos[3][1]) / 2.f));
            window.draw(circle);
        }
        else {

        }

        if (slot[2] == 'x') {
            cross.setPosition(Vector2f((selectPos[2][0] + 310) / 2.f, (selectPos[0][1] + selectPos[3][1]) / 2.f));
            cross2.setPosition(Vector2f((selectPos[2][0] + 310) / 2.f, (selectPos[0][1] + selectPos[3][1]) / 2.f));
            window.draw(cross);
            window.draw(cross2);
        }
        else if (slot[2] == 'o') {
            circle.setPosition(Vector2f((selectPos[2][0] + 310) / 2.f, (selectPos[0][1] + selectPos[3][1]) / 2.f));
            window.draw(circle);
        }
        else {

        }

        if (slot[3] == 'x') {
            cross.setPosition(Vector2f((selectPos[0][0] + selectPos[1][0]) / 2.f, (selectPos[3][1] + selectPos[6][1]) / 2.f));
            cross2.setPosition(Vector2f((selectPos[0][0] + selectPos[1][0]) / 2.f, (selectPos[3][1] + selectPos[6][1]) / 2.f));
            window.draw(cross);
            window.draw(cross2);
        }
        else if (slot[3] == 'o') {
            circle.setPosition(Vector2f((selectPos[0][0] + selectPos[1][0]) / 2.f, (selectPos[3][1] + selectPos[6][1]) / 2.f));
            window.draw(circle);

        }
        else {

        }
        if (slot[4] == 'x') {
            cross.setPosition(Vector2f((selectPos[1][0] + selectPos[2][0]) / 2.f, (selectPos[3][1] + selectPos[6][1]) / 2.f));
            cross2.setPosition(Vector2f((selectPos[1][0] + selectPos[2][0]) / 2.f, (selectPos[3][1] + selectPos[6][1]) / 2.f));
            window.draw(cross);
            window.draw(cross2);
        }
        else if (slot[4] == 'o') {
            circle.setPosition(Vector2f((selectPos[1][0] + selectPos[2][0]) / 2.f, (selectPos[3][1] + selectPos[6][1]) / 2.f));
            window.draw(circle);

        }
        else {

        }
        if (slot[5] == 'x') {
            cross.setPosition(Vector2f((selectPos[2][0] + 300) / 2.f, (selectPos[3][1] + selectPos[6][1]) / 2.f));
            cross2.setPosition(Vector2f((selectPos[2][0] + 300) / 2.f, (selectPos[3][1] + selectPos[6][1]) / 2.f));
            window.draw(cross);
            window.draw(cross2);
        }
        else if (slot[5] == 'o') {
            circle.setPosition(Vector2f((selectPos[2][0] + 300) / 2.f, (selectPos[3][1] + selectPos[6][1]) / 2.f));
            window.draw(circle);

        }
        else {

        }

        if (slot[6] == 'x') {
            cross.setPosition(Vector2f((selectPos[0][0] + selectPos[1][0]) / 2.f, (selectPos[6][1] + 310) / 2.f));
            cross2.setPosition(Vector2f((selectPos[0][0] + selectPos[1][0]) / 2.f, (selectPos[6][1] + 310) / 2.f));
            window.draw(cross);
            window.draw(cross2);
        }
        else if (slot[6] == 'o') {
            circle.setPosition(Vector2f((selectPos[0][0] + selectPos[1][0]) / 2.f, (selectPos[6][1] + 310) / 2.f));
            window.draw(circle);

        }
        else {

        }


        if (slot[7] == 'x') {
            cross.setPosition(Vector2f((selectPos[1][0] + selectPos[2][0]) / 2.f, (selectPos[6][1] + 310) / 2.f));
            cross2.setPosition(Vector2f((selectPos[1][0] + selectPos[2][0]) / 2.f, (selectPos[6][1] + 310) / 2.f));
            window.draw(cross);
            window.draw(cross2);
        }
        else if (slot[7] == 'o') {
            circle.setPosition(Vector2f((selectPos[1][0] + selectPos[2][0]) / 2.f, (selectPos[6][1] + 310) / 2.f));
            window.draw(circle);
        }
        else {

        }


        if (slot[8] == 'x') {
            cross.setPosition(Vector2f((selectPos[2][0] + 310) / 2.f, (selectPos[6][1] + 310) / 2.f));
            cross2.setPosition(Vector2f((selectPos[2][0] + 310) / 2.f, (selectPos[6][1] + 310) / 2.f));
            window.draw(cross);
            window.draw(cross2);
        }
        else if (slot[8] == 'o') {
            circle.setPosition(Vector2f((selectPos[2][0] + 310) / 2.f, (selectPos[6][1] + 310) / 2.f));
            window.draw(circle);

        }
        else {

        }
}
void resetSlot()
{
    for (int i = 0; i < 9; ++i) {
        slot[i] = ' ';

        // anim or text of reseting slots
    }
}
void selectAndWrite(int slotNum)
{
    if (slot[slotNum] == ' ' && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (playerSlot[0] == true) {
                slot[slotNum] = 'x';
                playerSlot[1] = true;
                playerSlot[0] = false;
                //slotSwitcher(0);
                //winnerCheck(0, slotNum,'x');
            }
            else if (playerSlot[1] == true) {
                slot[slotNum] = 'o';
                playerSlot[0] = true;
                playerSlot[1] = false;
                //slotSwitcher(1);
                //winnerCheck(1, slotNum,'o');

            }
        }
    else {
        if (boolMenu == false && playerTester == true && sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
            slot[slotNum] = ' ';
        }
        // error message
    }
}

void winnerCheck(int playerSlotNum, int slotNum, char ch)
{
   // if ()
}
