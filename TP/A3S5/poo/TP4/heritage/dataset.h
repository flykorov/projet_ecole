#ifndef DATASET_H
#define DATASET_H

#include "data.h"
#include "cercle.h"
#include "rectangle.h"
#include <vector>
using namespace std;

class Dataset
{
public:
	Dataset();
	~Dataset();

	void ajouterData(Data* d);
	void printData();

private:
	vector<Data*> vecData;

};

#endif