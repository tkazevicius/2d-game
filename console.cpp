#include "console.h"
#include "Windows.h"
int x = 1;
int y = 1;
int gold;
int Ilgis;
int trees = 0;
bool gamerunning = true;
string level = "Start";
bool allow_level = true;
char map[70][70];
vector < char > Daiktai{ ' ','.','%','T','D','Q'};
vector < char > Shop_Items{'$','+','~'};
set < char > Collected_Items;
bool pickaxe = false;
bool key = false;
bool trees_sold = false;
bool treasure_taken = false;
Trees tres(trees);
console::console()
{
}
console::~console()
{

}
Map::Map()
{
}
Map::~Map()
{
}
Items::Items()
{

};
Items::~Items()
{

};
void console::Move(int Vert, int Hori)
{
	y2 = y + Vert;
	x2 = x + Hori;
	if (map[y2][x2] == '>' && level == "Start" && tres.n == 3)
	{
		allow_level = true;
		level = "Main";
		x = 5;
		y = 6;
	}
	if (map[y2][x2] == '^' && level == "Main" && x != 16)
	{
		allow_level = true;
		level = "Shop";
		x = 2;
		y = 3;
	}
	if (map[y2][x2] == 'v' && level == "Main")
	{
		allow_level = true;
		level = "Dungeon";
		x = 1;
		y = 1;
	}
	if (map[y2][x2] == 'v' && level == "Shop")
	{
		allow_level = true;
		level = "Main";
		x = 5;
		y = 6;
	}
	if (map[y2][x2] == 'O' && level == "Dungeon" && !treasure_taken)
	{
		allow_level = true;
		level = "Cave";
		x = 1;
		y = 2;
	}
	if (x == 11 && y == 3 && level == "Cave")
	{
		allow_level = true;
		level = "Dungeon";
		treasure_taken = true;
		gold += 25;
		x = 63;
		y = 13;
		Collected_Items.insert('D');
	}
	if (x == 11 && y == 6 && level == "Cave")
	{
		allow_level = true;
		level = "Dungeon";
		treasure_taken = true;
		x = 1;
		y = 1;
		Collected_Items.insert('D');
	}
	if (x == 11 && y == 9 && level == "Cave")
	{
		allow_level = true;
		level = "Dungeon";
		treasure_taken = true;
		x = 1;
		y = 1;
		Collected_Items.insert('D');
	}
	if (map[y2][x2] == '>' && level == "Dungeon" && gold > 24)
	{
		allow_level = true;
		level = "Dungeon - 2";
		x = 3;
		y = 21;
	}
	if (level == "Dungeon - 2" && (x2 == 2 && y2 == 0))
	{
		allow_level = true;
		level = "Main";
		x = 5;
		y = 6;
	}
	if (level == "Main - 2" && (x2 == 17))
	{
		allow_level = true;
		level = "Prison";
		x = 1;
		y = 1;
	}
	if (level == "Main - 2" && (x == 4 && y2 == 8))
	{
		map[y][x] = ' ';
		y += Vert;
		map[y][x] = '?';
	}
	if (level == "Dungeon - 2")
	{
		if (map[y2][x] == '^' && ((x != 5 && y2 == 18) ||
			(x != 5 && y2 == 15) ||
			(x != 11 && y2 == 12) ||
			(x != 8 && y2 == 9) ||
			(x != 11 && y2 == 6) ||
			(x != 5 && y2 == 3))) // Neteisingos durys (Dungeon - 2)
		{
			allow_level = true;
			level = "Dungeon - 2";
			x = 3;
			y = 21;

		}
		if (map[y2][x] == '^' && ((x == 5 && y2 == 18) ||
			(x == 5 && y2 == 15) ||
			(x == 11 && y2 == 12) ||
			(x == 8 && y2 == 9) ||
			(x == 11 && y2 == 6) ||
			(x == 5 && y2 == 3))) // Teisingos durys (Dungeon - 2)
		{
			map[y][x] = ' ';
			y += Vert;
			map[y][x] = '?';
		}
	}
	if (map[y][x2] == ']' && level == "Main" && key)
	{
		map[y][x] = ' ';
		x += Hori;
		map[y][x] = '?';
	}
	if (map[y2][x2] == '>' && level == "Main" && key)
	{
		allow_level = true;
		level = "Main - 2";
		x = 4;
		y = 4;
	}
}
string console::Level_Name()
{
	return level;
}
void Map::loadmap(string pav)
{
	Ilgis = 0;
	string Eilute;
	ifstream openfile(pav.c_str());
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	if (openfile.is_open())
	{
		while (!openfile.eof())
		{
			getline(openfile, Eilute);
			strcpy_s(map[Ilgis], Eilute.c_str());
			Ilgis++;
		}
	}
}
void Map::Maps()
{
	if (level == "Start" && allow_level)
	{
		allow_level = false;
		loadmap("start.txt");
	}
	if (level == "Shop" && allow_level)
	{
		allow_level = false;
		loadmap("shop.txt");
	}
	if (level == "Main" && allow_level)
	{
		allow_level = false;
		loadmap("mapas.txt");
	}
	if (level == "Dungeon" && allow_level)
	{
		allow_level = false;
		loadmap("dungeon.txt");
	}
	if (level == "Cave" && allow_level)
	{
		allow_level = false;
		loadmap("cave.txt");
	}
	if (level == "Dungeon - 2" && allow_level)
	{
		allow_level = false;
		loadmap("dungeon2.txt");
	}
	if (level == "Main - 2" && allow_level)
	{
		allow_level = false;
		loadmap("mapas2.txt");
	}
	if (level == "Prison" && allow_level)
	{
		allow_level = false;
		loadmap("mapas3.txt");
	}
}
void Items::Item(int Vert, int Hori)
{
	y2 = y + Vert;
	x2 = x + Hori;
	if (map[y2][x2] == '.')
	{
		gold++;
		Collected_Items.insert('.');
	}
	if (map[y2][x2] == '$' && tres.n == 3 && !trees_sold)
	{
		trees_sold = true;
		gold += 5;
	}
	if (pickaxe && map[y2][x2] == 'Q')
	{
		gold += 5;
		Collected_Items.insert('Q');
	}
	if (map[y2][x2] == 'T')
	{
		++tres;
		Collected_Items.insert('T');
	}
	if (level == "Shop")
	{
		if (!pickaxe)
			map[1][3] = '+';
		if (!key)
			map[1][5] = '~';
		if (!trees_sold)
			map[4][7] = '$';
	}
	for (int i = 0;i < 6;i++)
	{
		if (Daiktai[i] == '%' && !pickaxe)
			break;
		if (gold > 4 && map[y2][x2] == '+' && !pickaxe)
		{
			map[y2][x2] = ' ';
			pickaxe = true;
			gold -= 5;
			Collected_Items.insert('+');
		}
		if (gold > 24 && map[y2][x2] == '~' && !key)
		{
			map[y2][x2] = ' ';
			key = true;
			gold -= 25;
			Collected_Items.insert('~');
		}
		if (map[y][x2] == Daiktai[i] || map[y][x2] == 'T')
		{
			map[y][x] = ' ';
			x += Hori;
			map[y][x] = '?';
		}
		else if (map[y2][x] == Daiktai[i] || map[y2][x] == 'T')
		{
			map[y][x] = ' ';
			y += Vert;
			map[y][x] = '?';
		}
	}
}