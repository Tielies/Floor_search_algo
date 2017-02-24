// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include <iostream>

int solcounter = 0;
class Floorsearch
{
public:
	Floorsearch(int number_of_floors, const int maxfloors);
	~Floorsearch();
	void Seachfloors();
private:
	int _floors;
	int _maxfloors;
};

Floorsearch::Floorsearch(int number_of_floors, const int maxfloors) :_floors(number_of_floors), _maxfloors(maxfloors)
{
}

Floorsearch::~Floorsearch()
{
}
void Floorsearch::Seachfloors()
{
	for (int i = 1; i < 3; i++)
	{
		int temp = _floors + i;
		if (temp == _maxfloors)
		{
			solcounter++;
		}
		else if (temp < _maxfloors)
		{
			Floorsearch* nextfloor = new Floorsearch(temp, _maxfloors);
			nextfloor->Seachfloors();
			delete nextfloor;
		}
	}
}

int main()
{
	Floorsearch search(0, 10);
	search.Seachfloors();
	std::cout << solcounter << std::endl;
    return 0;
}

