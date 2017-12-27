#pragma once
#include <iostream>
#include "BCSLinkedList.h"


template  <typename  K, typename  V>
class BCSHashTable
{
private:
	K tempKey;
	int size;
	BCSLinkedList<K,V> *list;
public:
	BCSHashTable() { init(100); }
	BCSHashTable(int tableSize) { tableSize > 1 ? init(tableSize) : init(2); }
	~BCSHashTable() {}

	void init(int tableSize)
	{
		tempKey = NULL;
		size = tableSize;
		list = new BCSLinkedList<K, V>[tableSize];
	}

	BCSHashTable<K,V> operator [](K key)
	{
		tempKey = key;
		return *this;
	}

	void operator =(V value)
	{
		if (tempKey != NULL)
		{
			list[convertIndex(tempKey)].Insert(tempKey, value);
			tempKey = NULL;
		}
	}

	void Remove(K key){ list[convertIndex(key)].Remove(key); }

	V Find(K key) { return list[convertIndex(key)].Find(key); }

	void ChangeValue(K key, V value) { list[convertIndex(key)].ChangeValue(key,value); }

	int convertIndex(K key) { cout << (key % (size - 1)) << endl;  return (key % (size - 1)); }
};


template<typename  V>
class BCSHashTable<std::string, V>
{
private:
	std::string tempKey;
	int size;
	BCSLinkedList<std::string, V> *list;
public:
	BCSHashTable() {}
	BCSHashTable(int tableSize)
	{
		tempKey = "";
		size = tableSize;
		list = new BCSLinkedList<std::string, V>[tableSize];
	}
	~BCSHashTable() {}

	BCSHashTable<std::string, V> operator [](std::string key)
	{
		tempKey = key;
		return *this;
	}

	void operator =(V value)
	{
		if (tempKey != "")
		{
			list[convertIndex(tempKey)].Insert(tempKey, value);
			tempKey = "";
		}
	}

	void Remove(std::string key) { list[convertIndex(key)].Remove(key); }

	V Find(std::string key) { return list[convertIndex(key)].Find(key); }

	void ChangeValue(std::string key, V value) { list[convertIndex(key)].ChangeValue(key, value); }

	int convertIndex(std::string key)
	{
		int temp = 0;
		for (int i = 0; i < key.size(); i++)
			temp += key[i];
		return (temp % (size - 1));
	}
};