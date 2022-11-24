#include <iostream>

class Object
{
	
};

class BoxOffice
{
	private:
	bool isAvailable;
	
	public:
	BoxOffice() { this->isAvailable = true; }
	bool GetIsAvailable() { return this->isAvailable; }
	void changeAvailable() { this->isAvailable = ~this->isAvailable; }
	
	
};

class Supermarket
{
	private:
	int BoxOffices;
	BoxOffice* objBoxOffice; // = new BoxOffice[7];
	
	
	public:
	Supermarket(int BoxOffices = 1)
	{
		this->BoxOffices = BoxOffices;
		BoxOffice* objBoxOffice = new BoxOffice[BoxOffices];
	}
	int HowMuchBoxOfficesIsAvailable()
	{
		int result = 0;
		for (int i = 0; i < this->BoxOffices; i++)
		{
			//std::cout << i << std::endl;
			if (this->objBoxOffice[i].GetIsAvailable()) result++;
		}
		return result;
	}
};

int main()
{
	std::cout << "Supermarket test" << std::endl;
	Supermarket supermarket(5);
	//std::cout << "It is " << supermarket.HowMuchBoxOfficesIsAvailable() << " are available" << std::endl; // segmentation fault
    
	try
	{
		std::cout << "It is " << supermarket.HowMuchBoxOfficesIsAvailable() << " are available" << std::endl; // in try catch construction it works
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
	
}