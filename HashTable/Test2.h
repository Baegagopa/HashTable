#pragma once

template  <typename  K, typename  V>
class Test3
{
public:
	Test3() {}
	~Test3() {}

	int return3()
	{
		return 3;
	}
};


template  <typename  K, typename  V>
class Test2
{
	Test3<K,V> *test3;
public:
	Test2() 
	{
		test3 = new Test3<K,V>[3];
	}
	~Test2() {}

	int return3()
	{
		return test3[1].return3();
	}
};

//template  <>
//class Test2<void*,void*>
//{
//private:
//	Test3<void*, void*> *test3;
//public:
//	Test2()
//	{
//		test3 = new Test3<void*, void*>[2];
//
//	}
//	~Test2() {}
//
//	int return3()
//	{
//		return test3[0].return3;
//	}
//};


