//
//  SLL.h
//  fun_with_primes
//
//  Created by Mark Quigley on 13/11/2020.
//

#include <iostream>
#include <math.h>
using namespace std;

class SLL_NODE{
private:
    int item;
    SLL_NODE * next;
    
public:
    SLL_NODE(int a,SLL_NODE* n){    //constructer
        item=a;
        next=n;
    }
    
    void change_item(int a){
        item=a;
    }
    
    void change_next(SLL_NODE *n){
        next=n;
    }
    
    bool item_comp(int a){
        if(item==a){
            return 1;
        }
        return 0;
    }
    
    int item_NODE(){
        return item;
    }
    
    SLL_NODE *next_NODE(){
        return next;
    }
};


class S_LIST{
private:
    SLL_NODE *first, *last;
    int size;

public:
    S_LIST(){                       //constructer
        first=NULL;
        last=NULL;
        size=0;
    }
    
    SLL_NODE *first_LIST(){
        return first;
    }
    
    SLL_NODE *last_LIST(){
        return last;
    }
    
    int size_LIST(){
        return size;
    }
    
    void add_first(int a){
        SLL_NODE *new_node=new SLL_NODE(a,NULL);
        if(first==NULL){
            //SLL_NODE new_node=SLL_NODE(a,NULL);
            first=new_node;
            last=new_node;
        }
        else{
            //SLL_NODE new_node=SLL_NODE(a,first);
            new_node->change_next(first);
            //new_node.next=first;
            first=new_node;
        }
        size++;
    }
    
    void add_last(int a){
        SLL_NODE *new_node=new SLL_NODE(a,NULL);
        if(first==NULL){
            //SLL_NODE new_node=SLL_NODE(a,NULL);
            first=new_node;
            last=new_node;
        }
        else{
            //SLL_NODE new_node=SLL_NODE(a,NULL);
            last->change_next(new_node);
            last=new_node;
        }
        size++;
    }
    
    void add_at_node(SLL_NODE *p, int n){
        SLL_NODE *q=p->next_NODE();
        SLL_NODE *new_node=new SLL_NODE(n,q);
        p->change_next(new_node);
        size++;
    }
    
    void delete_NODE(int a){
        SLL_NODE *p=first;
        SLL_NODE *q=NULL;
        bool found=0;
        
        while(p!=NULL && !found){
            found=p->item_comp(a);
            if(!found){
                q=p;
                p=p->next_NODE();
            }
        }
        if(found){
            if(q==NULL){                //when node is first
                first=p->next_NODE();
            }
            else{
                q->change_next( p->next_NODE() );
            }
            delete p;
            size--;
        }
        else{
            printf("ERROR: delete item %d not there\n", a);
        }
    }
    
    void print_list(){
        SLL_NODE *p=first;
        printf("print_list: ");
        if(first==NULL){
            printf("list is empty!");
        }
        while(p!=NULL){
            printf("%d,\t",p->item_NODE());
            p=p->next_NODE();
        }
        printf("\n");
    }
};

#ifndef SLL_h
#define SLL_h


#endif /* SLL_h */
