#include "console.h"
#include "Windows.h"
console Console;
Map mapas;
Items items;
void Movement();
void Dialogue();
void Inventory();
int main()
{
    while (gamerunning)
    {
        system("cls");
        Movement();
        mapas.Maps();
        for (int i = 0;i < Ilgis;i++)
            cout << map[i] << endl;
        Inventory();
        for (int i = 0;i < 1;i++)
            cout << mapas.Level_Name() << endl;
        Dialogue();
        system("pause>nul");
    }
    return 0;
}
void Movement()
{
    if (GetAsyncKeyState(VK_UP))
    {
        
        Console.Move(-1, 0);
        items.Item(-1, 0);
    } 
    if (GetAsyncKeyState(VK_DOWN))
    { 
        Console.Move(1, 0);
        items.Item(1, 0);
        
    }
    if (GetAsyncKeyState(VK_RIGHT))
    {
        Console.Move(0, 1);
        items.Item(0, 1);
        
    }
    if (GetAsyncKeyState(VK_LEFT))
    {
        Console.Move(0, -1);
        items.Item(0, -1);
        
    }
}
void Dialogue()
{
    if (mapas.Level_Name() == "Shop")
    {
        for (int i = 0;i < 1;i++)
        {
            if (!pickaxe)
                cout << "+ - Pickaxe (5 gold)" << endl;
            if (!key)
                cout << "~ - Key (25 gold)" << endl;
            if (!trees_sold)
                cout << "$ - Sell 3 trees for 5 gold" << endl;
        }
    }
    if (mapas.Level_Name() == "Main")
    {
        for (int i = 0;i < 1;i++)
        {
            if (!pickaxe && ((x == 4 && y == 10) || (x == 5 && y == 11)))
            {
                cout << "------------" << endl;
                cout << "You need a pickaxe break these rocks" << endl;
            }
            if (!key && (x == 20 && y == 6))
                cout << "You need a key to open this door" << endl;
            if (x == 16 && y == 11)
                cout << "It's too dangerous to go there" << endl;
        }
    }
    if (mapas.Level_Name() == "Cave" && !treasure_taken)
    {
        for (int i = 0;i < 1;i++)
            cout << "Choose a treasure chest, 2 are rigged to teleport you back and 1 will give you a prize" << endl;
    }
    if (mapas.Level_Name() == "Dungeon" && ((x == 62 && y == 11) || (x == 63 && y == 12)) && treasure_taken)
    {
        for (int i = 0;i < 1;i++)
            cout << "The roof caved in and is blocking the way" << endl;
    }
    if (mapas.Level_Name() == "Dungeon")
    {
        for (int i = 0;i < 1;i++)
        {
            cout << ". - Gold " << endl;
            cout << "Q - Diamonds (5 gold)" << endl;
        }
    }
    if ((mapas.Level_Name() == "Dungeon" || mapas.Level_Name() == "Cave") && gold < 25)
    {
        for (int i = 0;i < 1;i++)
            cout << "Collect 25 gold before going to the next dungeon" << endl;
    }
    if (mapas.Level_Name() == "Dungeon - 2")
    {
        for (int i = 0;i < 1;i++)
            cout << "Choose the correct door" << endl;
    }
    if (mapas.Level_Name() == "Prison")
    {
        for (int i = 0;i < 1;i++)
            cout << "Game over" << endl;

    }
    if (mapas.Level_Name() == "Main - 2" && (x == 4 && y == 9))
    {
        gamerunning = false;
        system("cls");
        cout << "Thank you for playing, press any key to quit" << endl;
    }
}
void Inventory()
{
    stringstream ss;
    ss << gold;
    string items = "Gold: ";
    items += ss.str();
    cout << "------------" << endl;
    cout << "Inventory:" << endl;
    for (int i = 0;i < 1;i++)
        cout << items << endl;
    cout << "Axe" << endl;
    if (pickaxe)
        cout << "Pickaxe" << endl;
    if (key)
        cout << "Key" << endl;
    cout << "------------" << endl;
    for (int i = 0;i < 1;i++)
    cout << "Unique items collected: ";
    for (char const& Unique : Collected_Items)
    {
        cout << Unique << ' ';
    }
    cout << endl;
    if (level == "Start")
    for (int i = 0;i < 1;i++)    
        {
            cout << "------------" << endl;
            cout << "Chop 3 trees before going to the next map" << endl;
        }
}