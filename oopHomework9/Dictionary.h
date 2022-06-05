#pragma once
template<class TKey, class TValue, size_t CAPACITY = 5>
class Dictionary
{
	KeyValuePair<TKey, TValue>* _pairs = nullptr;
	size_t _count = 0;
	size_t _capacity = CAPACITY;

public:

	void add(KeyValuePair<TKey, TValue>& item) {
		if (containsKey(item.key))
			throw "An item with the same key has already been added.";


		auto temp = new KeyValuePair<TKey, TValue>[++_count];

		for (size_t i = 0; i < _count - 1; i++)
			temp[i] = _pairs[i];

		temp[_count - 1] = item;


		delete[] _pairs;
		_pairs = temp;
	}

	void add(TKey key, TValue value)
	{
		if (containsKey(key))
			throw "An item with the same key has already been added.";


		auto temp = new KeyValuePair<TKey, TValue>[++_count];

		for (size_t i = 0; i < _count - 1; i++)
			temp[i] = _pairs[i];

		temp[_count - 1] = KeyValuePair<TKey, TValue>(key, value);
		// temp[_count - 1] = { key, value };


		delete[] _pairs;
		_pairs = temp;
	}


	bool containsKey(const TKey& key) const
	{
		for (size_t i = 0; i < _count; i++)
			if (_pairs[i].key == key)
				return true;

		return false;
	}

	bool containsValues(const TValue& value) const
	{
		for (size_t i = 0; i < _count; i++)
			if (_pairs[i].value == value)
				return true;

		return false;
	}


	TValue& operator[](TKey key)
	{
		for (size_t i = 0; i < _count; i++)
			if (_pairs[i].key == key)
				return _pairs[i].value;

		throw "key not found";
	}


	size_t count() const
	{
		return _count;
	};

	size_t capacity() const { return _capacity; }

	void clear() {
		delete[]_pairs;
		_pairs = nullptr;
		_count = 0;
	}


	template<class TKey>
	struct KeyCollection {
		TKey* keys;
		size_t count;

		KeyCollection() :keys(), count() {}

		KeyCollection(size_t count)
		{
			this->count = count;
			keys = new TKey[count];
		}

		KeyCollection(KeyCollection<TKey>&& other) noexcept
		{
			// Move Constructor
			count = other.count;
			keys = other.keys;

			other.keys = nullptr;
		};

		~KeyCollection()
		{
			delete[] keys;
		}
	};


	template<class TValue>
	struct ValueCollection
	{
		TValue* values;
		size_t count;
		ValueCollection() :values(), count() {}

		ValueCollection(size_t count)
		{
			this->count = count;
			values = new TValue[count];
		}

		ValueCollection(ValueCollection<TValue>&& other) noexcept
		{
			// Move Constructor
			count = other.count;
			values = other.values;

			other.values = nullptr;
		};

		~ValueCollection()
		{
			delete[] values;
		}
	};



	KeyCollection<TKey> keys() {
		KeyCollection<TKey> keyCollection(_count);

		for (size_t i = 0; i < _count; i++)
			keyCollection.keys[i] = _pairs[i].key;


		return keyCollection;
	}

	ValueCollection<TValue> values() {
		ValueCollection<TValue> valueCollection(_count);

		for (size_t i = 0; i < _count; i++)
			valueCollection.values[i] = _pairs[i].value;


		return valueCollection;
	}
};