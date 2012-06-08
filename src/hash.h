
#ifndef __BASIC_HASH_EOAIX__
#define __BASIC_HASH_EOAIX__

#include <cstdio>
#include <iostream>
#include <cstring>
//#define DEBUG

namespace eoaix {

#ifndef TEMP_KEY_VALUE
#define TEMP_KEY_VALUE template<class Key, class Value> 
#else
#error TEMP_KEY_VALUE defined ever.
#endif

	TEMP_KEY_VALUE
		class HashNode {
			public:
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

#define HASH_TABLE_SIZE (1<<5)
		public:

		/* Insert a new <key, value> pair. */
		void insert(const Key& key, const Value& val) {

			size_t hval = hash_func(key);
#ifdef DEBUG
			std::cout << "key.toString()=" << key.toString() << " ,hash func returns: " << hval << std::endl;
#endif

			if(hval >= HASH_TABLE_SIZE) {
				throw ;
			}

			_Node* node = new _Node(key, val);

			node->next = _blocks[hval];
			_blocks[hval] = node;
		}



		/* Find the pointer of value corresponding to key, if not exist returns a NULL. */
		Value* find_val(const Key& key) const {

			_Node* ptr = find_node(key);	

			return ptr ? &ptr->_val : NULL;
		}


		/* Remove the *first* key appeared in list. */
		void remove(const Key& key) {
			_Node* ptr = find_node(key);
			if(ptr) {
				_Node* ans = ptr;
				ptr = ptr->next;
				delete ans;
			}
		}



		HashMap() {
			/* Set the _blocks as NULL at the beginning. */
			//memset(_blocks, NULL, sizeof(HashNode<Key, Value>*) * HASH_TABLE_SIZE);
			for(size_t i = 0; i < HASH_TABLE_SIZE; ++i)
				_blocks[i] = NULL;
		}


	/* Don't forget to free the memories that we allocated. */
		~HashMap() {
			delloc();
		}


		private:

		/* Find the HashNode corresponding to key. */
		_Node* find_node(const Key& key) const {
			size_t hval = hash_func(key);

			_Node* ptr = _blocks[hval];

			while(ptr) {
				if(ptr->_key.toString() == key.toString()) {
					break;
				}
				ptr = ptr->next;
			}

			return ptr;
		}



		/* Calculate Hash value by this function. Key must override a funtion named toString(). */
		size_t hash_func(const Key& key) const {
			std::string str = key.toString();
			size_t mask = 0;
			for(size_t i = 0; i < str.size(); ++i) {
				mask += str[i];	
#ifdef DEBUG
				std::cout << "mask=" << mask << " , str[" << i << "]=" << str[i] << std::endl;
#endif
			}
#ifdef DEBUG
			std::cout << "mask=" << mask << " ,HASH_TABLE_SIZE=" << HASH_TABLE_SIZE << " , mask % HASH_TABLE_SIZE = " << mask % HASH_TABLE_SIZE << std::endl;
#endif
			return mask % HASH_TABLE_SIZE;
		}


		/* Free the memory that malloc in insert function. */
		void delloc() {
			/**
			 * 
			 Free the memory that malloc in insert function. 
			 */

			for(size_t i = 0; i < HASH_TABLE_SIZE; ++i) {
				delloc_list(i);				
			}
		}



		/* Free the memory of a list, index indicates which list. */
		inline void delloc_list(size_t index) {
			_Node* ptr = _blocks[index];

			while(ptr != NULL) {
				_Node* ans = ptr;
#ifdef DEBUG
				std::cout << "index: " << index << " , key:" << ptr->_key.toString() << " , val:" << ptr->_val.toString()
					<< " ,ptr->next:" << ptr->next << std::endl;
#endif

				ptr = ptr->next;
				delete ans;
			}
		}

		HashNode<Key, Value>* _blocks[HASH_TABLE_SIZE];
	};
}

#endif
