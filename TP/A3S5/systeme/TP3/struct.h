// TP 3 systeme
// Victor Bouvier d'Acher
// Geoffroy Rodriguez
// Mohamed Arezki Meriane

#include <vector>

struct adresse_logique
{
	std::vector<int> page;
	std::vector<int> offset;
};

struct frame
{
	std::vector<int> page;
	bool charge;
};

struct memoire
{
	int virtuelle;
	int physique;
	int valeur;
};

struct TLB
{
	std::vector<int> page;
	int lru;
};