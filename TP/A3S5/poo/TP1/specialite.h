#ifndef SPECIALITE_H
#define SPECIALITE_H
using namespace std;

class Specialite
{
public:
	Specialite();
	Specialite(string s, int l);// : speci(s), level(l) {}
	~Specialite();

	void setSpe(string spe);
	void setLevelSpe(int lvl);

	string getSpe();
	int getLevelSpe();

private:
	string speci = "not define";
	int level = 1;
};

#endif