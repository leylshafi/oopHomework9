#include <iostream>

using namespace std;
#include"KeyValuePair.h"
#include"Dictionary.h"


int main()
{
	Dictionary<int, string> map;
	KeyValuePair<int, string> pair1(30, "Hello");


	map.add(10, "Baku");
	map.add(20, "Gence");
	map.add(50, "Sumqayit");

	map.add(pair1);

	// cout << map[20] << endl;
	// cout << map[50] << endl;

	// cout << map.count() << endl;



	// Dictionary<int, string>::KeyCollection<int> keyCollection = map.keys();
	auto keyCollection = map.keys();

	for (size_t i = 0; i < keyCollection.count; i++) {
		auto key = keyCollection.keys[i];
		cout << "Key: " << key << "  -  Value: " << map[key] << endl;
	}

	cout << endl;
	cout << map[20] << endl;;

	//// Exception handle

	//	try
	//	{
	//		// map.add(20, "Kirovabad");	// Exception
	//		cout << map[75] << endl;		// Exception
	//	}
	//	catch (const char* ex)
	//	{
	//		cout << "Error occured! " << ex << endl;
	//	}




	// KeyValuePair<int, string> pair(10, "Baku");
	// map.add(pair);
}