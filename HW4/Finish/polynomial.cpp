#include <iostream>
#include "polynomial.hpp"
using namespace std;

void Polynomial::add(CoeffType c, int e){
    NodePointer start = head;
    NodePointer temp;
    //traverse until right position(decreasing order)
    while(start->next != NULL){
        if(start->next->data.expo == e){
            start->next->data.coef += c;
            return;
        }//same exponent
        else if(start->next->data.expo < e){
            temp = new Node(c,e);
            temp->next = start->next;
            start->next = temp;
            return;
        }
        start = start->next;
    }
    //smallest expon in current list
    temp = new Node(c,e);
    start->next = temp;
}
Polynomial::Polynomial (CoeffType* c, int* e, int num){
    NodePointer poly = new Node();
    head = poly;//initialize a empty node for head to point to
    for(int i = 0; i < num; i++){
        add(c[i],e[i]);
    }//add terms
    cout << "constructor" << endl;
}
Polynomial::~Polynomial(){
    NodePointer temp = head;
    NodePointer d_temp = head;
    while(temp!=NULL){
        d_temp = temp;
        temp = temp->next;
        delete d_temp;
    }
}
void Polynomial::differentiate(){
    NodePointer start = head;
    while(start->next!=NULL){
        if(start->next->data.expo == 0){
            NodePointer temp = start->next;
            start->next = NULL;//points to NULL
            delete temp;//when there is constant
        }
        else{
            start->next->data.coef *= start->next->data.expo;
            --(start->next->data.expo);
        }
        start = start->next;
    }
    return;
}
void Polynomial::display(){
    NodePointer start = head;
    while(start != NULL){
        cout << start->next->data.coef << "^" << start->next->data.expo;
        start = start->next;
        if(start->next == NULL)
            break;//when we meet the end of list
        cout << " + ";
    }
    cout << endl;
    return;
}