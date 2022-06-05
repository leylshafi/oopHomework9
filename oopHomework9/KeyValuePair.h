#pragma once
template<class TPairKey, class TPairValue>
struct KeyValuePair {
	TPairKey key;
	TPairValue value;
	KeyValuePair() : key(), value() {}

	KeyValuePair(TPairKey key, TPairValue value)
	{
		this->key = key;
		this->value = value;
	}
};