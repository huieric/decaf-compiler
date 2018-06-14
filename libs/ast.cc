/* File: ast.cc
 * ------------
 */

#include "ast.h"
#include "ast_type.h"
#include "ast_decl.h"
#include <string.h> // strdup
#include <stdio.h>  // printf

Node::Node(yyltype loc) {
    location = new yyltype(loc);    
    parent = NULL;    
    children = new List<Node *>;
}

Node::Node(const char *node_name) {
    location = NULL;    
    parent = NULL;  
    children = new List<Node *>;
    this->node_name = strdup(node_name);
}
Node::Node() {
    location = NULL;    
    parent = NULL;
    children = new List<Node *>;
}
	 
Identifier::Identifier(yyltype loc, const char *n) : Node(loc) {
    name = strdup(n);
} 

