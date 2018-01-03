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
	BCSHashTable() : tempKey(NULL) { init(100); }
	BCSHashTable(int tableSize) : tempKey(NULL) { tableSize > 1 ? init(tableSize) : init(2); }
	~BCSHashTable() { delete[] list; }

	void init(int tableSize)
	{
		size = tableSize;
		list = new BCSLinkedList<K, V>[tableSize];
	}

	BCSHashTable<K,V> operator [](const K& key)
	{
		tempKey = key;
		return *this;
	}

	void operator =(const V& value)
	{
		if (tempKey != NULL)
		{
			list[convertIndex(tempKey)].Insert(tempKey, value);
			tempKey = NULL;
		}
	}

	void Remove(const K& key){ list[convertIndex(key)].Remove(key); }

	V Find(const K& key) { return list[convertIndex(key)].Find(key); }

	void ChangeValue(const K& key, const V& value) { list[convertIndex(key)].ChangeValue(key,value); }

	int convertIndex(const K& key) { return (key % size); }
};


template<typename  V>
class BCSHashTable<std::string, V>
{
private:
	std::string tempKey;
	int size;
	BCSLinkedList<std::string, V> *list;
public:
	BCSHashTable() : tempKey("") { init(100); }
	BCSHashTable(int tableSize) : tempKey("") { tableSize > 1 ? init(tableSize) : init(2); }

	void init(int tableSize)
	{
		size = tableSize;
		list = new BCSLinkedList<std::string, V>[tableSize];
	}

	~BCSHashTable() {}

	BCSHashTable<std::string, V> operator [](const std::string& key)
	{
		tempKey = key;
		return *this;
	}

	void operator =(const V& value)
	{
		if (tempKey != "")
		{
			list[convertIndex(tempKey)].Insert(tempKey, value);
			tempKey = "";
		}
	}

	void Remove(const std::string& key) { list[convertIndex(key)].Remove(key); }

	V Find(const std::string& key) { return list[convertIndex(key)].Find(key); }

	void ChangeValue(const std::string& key, const V& value) { list[convertIndex(key)].ChangeValue(key, value); }

	int convertIndex(const std::string& key)
	{
		int temp = 0;
		for (int i = 0; i < key.size(); i++)
			temp += key[i];
		return (temp % size);
	}
};