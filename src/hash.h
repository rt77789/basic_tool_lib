
#ifndef __BASIC_HASH_EOAIX__
#define __BASIC_HASH_EOAIX__

#include <cstdio>
#include <iostream>

namespace eoaix {

#ifndef TEMP_KEY_VALUE
	#define TEMP_KEY_VALUE template<class Key, class Value> 
#else
	#error TEMP_KEY_VALUE defined ever.
#endif

	TEMP_KEY_VALUE
		class HashNode {
			HashNode(const Key& key, const Value& val):_key(key), _val(val) {
			}
			~HashNode() {
			}

			Key _key;
			Value _val;
			HashNode<Key, Value>* next;
		};


	TEMP_KEY_VALUE class HashMap {

		typedef HashNode<Key, Value> _Node;
		typedef HashMap<Key, Value> _Map;

#define HASH_TABLE_SIZE 1<<10
		public:

		/* Insert a new <key, value> pair. */
		void insert(const Key& key, const Value& val);

		/* Find the pointer of value corresponding to key, if not exist returns a NULL. */
		Value* find_val(const Key& key) const;

		/* Remove the *first* key appeared in list. */
		void remove(const Key& key);

		HashMap();
		~HashMap();

		private:

		/* Find the HashNode corresponding to key. */
		_Node* find_node(const Key& key) const;

		/* Calculate Hash value by this function. Key must override a funtion named toString(). */
		size_t hash_func(const Key& key);

		/* Free the memory that malloc in insert function. */
		void delloc();

		/* Free the memory of a list, index indicates which list. */
		inline void delloc_list(size_t index);

		HashNode<Key, Value>* _blocks[HASH_TABLE_SIZE];
	};

}

#endif
