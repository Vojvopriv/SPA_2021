#include "Stack.h"
#include "Graph.h"







void push(Node** tos, const Graph* g, int node)
{
    Node* new_node = new Node(g->getNodeName(node), *tos);
    *tos = new_node;
}

int pop(Node** tos)
{
    if (*tos == nullptr) return 0;
    Node* temp = *tos;
    *tos = temp->next;

    temp->~Node();

    return 1;
}

