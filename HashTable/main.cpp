#include <iostream>
#include <type_traits>   
#include <list>
#include "BCSHashTable.h"
#include "Test2.h"
using namespace std;

void main()
{

	BCSHashTable<int, int> a(0);
	BCSLinkedList<int, int> b;

	//a["ab"] = 1;
	//a["ab"] = 2;
	//a["ab"] = 3;
	//a.Remove("ab");
	//cout << a.Find("ab") << endl;
	
	//a[1.5f] = 1;
	//a[1.7f] = 2;
	//a[1.0f] = 3;
	////a.Remove(1);
	//cout << a.Find(1.0f) << endl;

	//a[1] = 1;
	//a[1] = 2;
	//a[1] = 3;
	////a.Remove(1);
	//cout << a.Find(1) << endl;

}