#ifndef HUFFMANTRIE_H
#define HUFFMANTRIE_H

#include "freqanalysis.h"
#include "pqueue.h"
#include <assert.h>

/**
 * @defgroup         huffmantrie_h Huffman Trie
 * 
 * @brief            Creation of the Huffman trie by using greedy algorithm.      
 * 
 *                   Huffman Trie is a special variant of the binary tree. Therefore, each
 *                   node can have a maximum of two children. Then we will create trie nodes for
 *                   each values that can appear in a byte with its frequency value.
 *                   Afterwards, all of nodes will be inserted in the priority queue.
 *                   The lesser value will get the highest priority.It begins to build the trie 
 *                   from the bottom up, starting with two least probable bytes from the priority 
 *                   queue. A whole trie will be created by adding those sub-trees into a trie.
 *                    
 * 
 * @author           Gazi Md Rakibul Hasan 
 * @since            2022-02-28
 * 
 * @{
 * 
 */

// type of the trie node.
struct TrieNode{
   int symbol;
   int value;
   struct TrieNode* left_child;
   struct TrieNode* right_child;
};

typedef struct TrieNode TrieNode;

//it fills priority queue with frequency table
/**
 * @brief            Insetion of the frequency value of the each byte in the priority queue.
 *
 *                   That function uses priority queue to insert each byte corresponding to
 *                   each byte's frequency from the frequency table. A byte with the lower
 *                   frequency value will have the highest priority. The user is responsible
 *                   to deallocate the memories since we will use heap memory section. 
 *
 * @param tb         The frequency table.
 * @return           The priority queue will be filled.
 */
pqueue* fill_priority_queue (frequency_table* tb);

// deallocates all nodes in the tree
/**
 * @brief            Deallocation of the dynamic memories.
 *
 *                   That function deallocates all memories that had been
 *                   dynamically allocated.
 *
 * @param huff_trie  The Huffman trie.
 * @return           Deallocation of the dynamic memories.
 */
void destroy_huff_tree (TrieNode* huff_trie);

// get the right child
/**
 * @brief            Insertion of the right child.
 *
 *                   That function inserts a right child to a given node.
 *
 * @param node1      The node which will get a right child.
 * @param node2      a node of the trie.
 * @return           node1 will get node2 as its right child.
 */
TrieNode* insert_right_child (TrieNode* node1, TrieNode* node2);

//get the left child
/**
 * @brief            Insertion of the left child.
 *
 *                   That function inserts a left child to a given node.
 *
 * @param node1      The node which will get a left child.
 * @param node2      a node of the trie.
 * @return           node1 will get node2 as its left child.
 */
TrieNode* insert_left_child (TrieNode* node1, TrieNode* node2);

//make a huffman trie from the priority queue
/**
 * @brief            Build a trie from the the priority queue.
 *
 * 
 *                   That function uses the priority queue to build a trie. The Huffman
 *                   method will be applicable here to build the Huffman trie. By that 
 *                   means we will dequeue two nodes that have less frequency value in 
 *                   the priority queue. 
 *                   The user is responsible to deallocate the memories since we will
 *                   use heap memory section to allocate the Huffman trie.
 *                   
 *
 * @param pq         The priority queue.
 * @return           The trie will be builded according to Huffman's method.
 */
TrieNode* priority_queue_to_trie(pqueue* pq);

// check if that is a leaf node
/**
 * @brief            It checks if a node is a leaf node in the trie.
 *
 *                   A leaf contains neither right or left child. So, it checks if
 *                   the given node is a leaf node or not.
 *
 * @param node       The node of the trie.
 * @return           true, if the node is a leaf node. On the other hands, it returns
 *                   false.
 */
bool is_leaf_node(TrieNode* node);

#endif
/**
 * @}
 * 
 */