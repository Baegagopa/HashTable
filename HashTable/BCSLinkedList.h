#pragma once


template <typename  K, typename  V>
struct KeyValNode
{
	KeyValNode *nextNode;
	K key;
	V value;
};

template  <typename  K, typename  V>
class BCSLinkedList
{
private:
	KeyValNode<K, V> *head;
public:
	BCSLinkedList():head(NULL) { }
	~BCSLinkedList()
	{
		if (head != NULL)
		{
			KeyValNode<K, V> *deleteNode = head;
			while (head->nextNode != NULL)
			{
				head = head->nextNode;
				delete deleteNode;
				deleteNode = head;
			}
			delete deleteNode;
		}
	}

	void Insert(const K& key,const V& value)
	{
		KeyValNode<K, V> *newNode = new KeyValNode<K, V>;
		newNode->nextNode = NULL;
		newNode->key = key;
		newNode->value = value;

		if (head == NULL)
			head = newNode;
		else
		{
			KeyValNode<K, V> *temp = head;
			while (temp->nextNode != NULL && temp->key != key)
				temp = temp->nextNode;

			if (temp->key == key) { temp->value = value; return; }

			temp->nextNode = newNode;
		}		
	}

	void Remove(const K& key)
	{
		if (head == NULL)
			return;
		else
		{
			KeyValNode<K, V> *temp = head;
			KeyValNode<K, V> *deleteNode = NULL;

			if (head->key == key)
			{
				deleteNode = head;
				head = head->nextNode;
				delete deleteNode;
				return;
			}

			while (temp->nextNode != NULL)
			{
				if (temp->nextNode->key == key)
				{
					deleteNode = temp->nextNode;
					temp->nextNode = temp->nextNode->nextNode;
					delete deleteNode;
					break;
				}
				temp = temp->nextNode;
			}
		}
	}

	V Find(const K& key)
	{
		if (head == NULL)
			return -9998;

		KeyValNode<K, V> *temp = head;
		do
		{
			if (temp->key == key)
			{
				return temp->value;
			}
			temp = temp->nextNode;
		} while (temp != NULL);

		return -9999;
	}

	void ChangeValue(const K& key, const V& value)
	{
		KeyValNode<K, V> *temp = head;

		while (temp->nextNode != NULL)
		{
			if (temp->key == key)
			{
				temp->value = value;
			}
			temp = temp->nextNode;
		}
	}

};


