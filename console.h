#ifndef CONSOLE_H
#define CONSOLE_H
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;
using std::getline;
using std::ifstream;
using std::vector;
using std::set;
class console
{
protected:
	int x2;
	int y2;
public:
	
	console();
	~console();
	void Move(int Vert, int Hori);
	string Level_Name();
};
class Map: public console
{
public:
	Map();
	~Map();
	void loadmap(string pav);
	void Maps();
};
class Items: public console
{
public:
	Items();
	~Items();
	void Item(int Vert, int Hori);
};
class Trees
{
public:
	int n;
	Trees(int temp) : n(temp) {}
	void operator ++()
	{
		n++;
	}
};
extern int Ilgis;
extern char map[70][70];
extern int x;
extern int y;
extern int gold;
extern bool pickaxe;
extern bool key;
extern int Ilgis;
extern string level;
extern bool allow_level;
extern bool trees_sold;
extern bool treasure_taken;
extern bool gamerunning;
extern vector < char > Daiktai;
extern vector < char > Shop_Items;
extern set < char > Collected_Items;
#endif