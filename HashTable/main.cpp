#include <iostream>
#include <type_traits>   
#include <list>
#include "BCSHashTable.h"
#include "Test2.h"
using namespace std;

void main()
{

	BCSHashTable<int, int> a(1);
	BCSHashTable<string, int> b(10);

	
	b["ab"] = 5;
	b["abc"] = 2;
	b["ad"] = 3;
	b.Remove("abc");
	cout << b.Find("ab") << endl;
	
	//a[1.5f] = 1;
	//a[1.7f] = 2;
	//a[1.0f] = 3;
	////a.Remove(1);
	//cout << a.Find(1.0f) << endl;

	//a[1] = 1;
	//a[2] = 2;
	//a[3] = 3;
	//a[4] = 4;
	//a[5] = 5;
	//a[6] = 6;
	//a[7] = 7;
	////a.Remove(1);
	//cout << a.Find(7) << endl;

}