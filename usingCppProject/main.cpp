#include <iostream>
#include <fstream>
#include "using.hpp"
using namespace std;


class fileWithUsing : public ofstream, public IInsertableInUsing
{
public:
	string fileName;

	fileWithUsing(const string& fileName)
	{
		this->fileName = fileName;
	}

	void onStart()
	{
		open(fileName);
	}

	void onEnd()
	{
		close();
	}
};


int main()
{
	using(fileWithUsing, example, ("helloFile.txt"),
	{
		example << "Hello, using!";
	});

	return 0;
}