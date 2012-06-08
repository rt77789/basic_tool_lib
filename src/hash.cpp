
#include "hash.h"

namespace eoaix {

	TEMP_KEY_VALUE 
		void HashMap<Key, Value>::insert(const Key& key, const Value& val) {
			size_t hval = hash_func(key);

			if(hval >= HASH_TABLE_SIZE) {
				throw ;
			}

			_Node* node = new _Node(key, val);

			if(_blocks[hval] == NULL) {
				_blocks[hval] = node;
			}
			else {
				node->next = _blocks[hval]->next;
				_blocks[hval]->next = node;
			}
		}

	TEMP_KEY_VALUE
		Value* HashMap<Key, Value>::find_val(const Key& key) const {
			
			_Node* ptr = find_node(key);	

			return ptr ? &ptr->_val : NULL;
		}

	TEMP_KEY_VALUE
		HashNode<Key, Value>* HashMap<Key, Value>::find_node(const Key& key) const {
			size_t hval = hash_func(key);

			_Node* ptr = _blocks[hval];

			while(ptr) {
				if(ptr->_key == key) {
					break;
				}
				ptr = ptr->next;
			}

			return ptr;
		}

	TEMP_KEY_VALUE
		void HashMap<Key, Value>::remove(const Key& key) {
			_Node* ptr = find_node(key);
			if(ptr) {
				_Node* ans = ptr->next;
				free(ptr);
				ptr = ans;
			}
		}

	/**
	  * 
	  Free the memory that malloc in insert function. 
	  */
	TEMP_KEY_VALUE 
		void HashMap<Key, Value>::delloc() {
			
			for(size_t i = 0; i < HASH_TABLE_SIZE; ++i) {
				delloc_list(i);				
			}
		}

	/* Free the memory of a list, index indicates which list. */
	TEMP_KEY_VALUE
		inline void HashMap<Key, Value>::delloc_list(size_t index) {
			_Node* ptr = _blocks[index];
			while(ptr) {
				_Node* ans = ptr->next;

				free(ptr);
				ptr = ans;
			}
		}

	TEMP_KEY_VALUE
		HashMap<Key, Value>::HashMap() {
			/* Set the _blocks as NULL at the beginning. */
			memset(_blocks, 0, sizeof(_blocks) * HASH_TABLE_SIZE);
		}

	/* Don't forget to free the memories that we allocated. */
	TEMP_KEY_VALUE
		HashMap<Key, Value>::~HashMap() {
			delloc();
		}

	/* Calculate Hash value by this function. Key must override a funtion named toString(). */
	TEMP_KEY_VALUE
		size_t HashMap<Key, Value>::hash_func(const Key& key) {
			std::string str = key.toString();
			size_t mask = 0;
			for(size_t i = 0; i < str.size(); ++i) {
				mask += str[i];	
			}
			return mask % HASH_TABLE_SIZE;
		}
}
