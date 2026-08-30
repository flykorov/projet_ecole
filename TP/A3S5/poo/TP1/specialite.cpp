#include <iostream>
#include <string>
#include "specialite.h"
using namespace std;

Specialite::Specialite()
{
	speci = "not define";
	level = 1;
}

Specialite::Specialite(string s, int l)
{
	speci = s;
	level = l;
}

Specialite::~Specialite()
{

}

void Specialite::setSpe(string spe)
{
	speci = spe;
}

void Specialite::setLevelSpe(int lvl)
{
	level = lvl;
}

string Specialite:: getSpe()
{
	return speci;
}

int Specialite::getLevelSpe()
{
	return level;
}