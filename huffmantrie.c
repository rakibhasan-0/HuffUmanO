#include "huffmantrie.h"

/*-----------------------internalfunction----------------------------------*/

/**
 * @brief            It creates a trie node.
 *
 *                   It creates an empty node with the given value. Thus, it contains
 *                   neither left or right child.
 *
 * @param val        The value.
 * @return           Creation of a new node.
 */

TrieNode* make_new_node (int val){

   TrieNode* node = (TrieNode*) malloc(sizeof(TrieNode));

   node->value = val;
   node->left_child = NULL;
   node->right_child = NULL;

   return node;

}

/**
 * @brief            A compare function. 
 * 
 *                   That function compares two nodes value.
 * 
 * @param node1      A node of a trie.
 * @param node2      A node of a trie.
 * @return           > 0   if node1 > node2
 *                   < 0   if node1 < node2
 *                    0    if node1 = node2
 */
int less_then(void* node1, void* node2){

   int val = ((TrieNode*) node1)->value - ((TrieNode*) node2)->value;
   return val;

}


/*-------------------------------externalfunction----------------------------*/


pqueue* fill_priority_queue (frequency_table* tb){

   pqueue* pq = pqueue_empty(less_then);

   for (int i = 0; i < MAX_CHAR; i++){

      TrieNode* node = (TrieNode*) malloc (sizeof(TrieNode));

      node->symbol = tb[i].symbol;
      node->value = tb[i].number_of_char;
//      printf("\n%d  == %c",node->value, node->symbol);
      node->left_child = NULL;
      node->right_child = NULL;

      pqueue_insert (pq, node);
   }

   return pq;
}


TrieNode* insert_left_child (TrieNode* node1, TrieNode* node2){

   node1->left_child = node2;
   return node1;

}

TrieNode* insert_right_child (TrieNode* node1, TrieNode* node2){

   node1->right_child = node2;
   return node1;

}

TrieNode* priority_queue_to_trie (pqueue* pq){

   TrieNode* node1, *node2, *root_node;

   while(!pqueue_is_empty(pq)){

      node1 = (TrieNode*) pqueue_inspect_first(pq);
      pqueue_delete_first(pq);
     // printf("(%c , %d)", node1->symbol, node1->value);
      if (pqueue_is_empty(pq)){

         /*int val = node1->value;
         root_node = make_new_node(val, -1);
         root_node = insert_left_child(root_node, node1);*/
         return root_node;

      }

      node2 = (TrieNode*) pqueue_inspect_first(pq);
      //printf("(%c , %d)", node2->symbol, node2->value);
      pqueue_delete_first(pq);

      int new_value = node1->value + node2->value;
      root_node = make_new_node(new_value);

      root_node = insert_left_child(root_node, node1);
      root_node = insert_right_child(root_node, node2);
   //  printf(" (root == (%c, %d), root_left_child == (%c, %d), root_right_child == (%c , %d)\n",root_node->symbol, root_node->value,root_node->left_child->symbol, root_node->left_child->value, root_node->right_child->symbol, root_node->right_child->value);

      pqueue_insert (pq, root_node);

   }

   return root_node;
}



bool is_leaf_node (TrieNode* node){

   if (node->left_child == NULL && node->right_child == NULL){
      return true;
   }
   else{
      return false;
   }

}


void destroy_huff_tree (TrieNode* huff_trie){

   if (huff_trie == NULL){
      return;
   }
   else{
      destroy_huff_tree(huff_trie->left_child);
      destroy_huff_tree(huff_trie->right_child);
      free(huff_trie);
   }
}
