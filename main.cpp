//
//  main.cpp
//  fun_with_primes
//
//  Created by Mark Quigley on 12/11/2020.
//

#include <iostream>
#include <math.h>
#include "SLL.h"

using namespace std;



//*
int find_primes(int n,S_LIST *P){   //finds all the primes <= n
    int count=0;    //stores the number of primes;
    
    if(n<2){
        printf("ERROR: %d < 2 and has no prime factors\n", n);
        return count;
    }
    
    P->add_last(2);
    count++;

    int i,j;
    for(i=3;i<=n;i+=2){      //test for primes and add to list
        for(j=3; j<(i/2+1); j++){
            if(i%j==0){
                j=i;
            }
        }
        if(j!=i+1){
            P->add_last(i);
            count++;
        }
    }
    
    return count;
}//*/

S_LIST * find_prime_factors(int n,S_LIST *primes){  //finds prime factors of n
    int p_item;
    S_LIST *factors=new S_LIST();
    SLL_NODE *p=primes->first_LIST();
    while( p->item_NODE() <= n ){
        p_item=p->item_NODE();
        if( (n%p_item)==0 ){
            factors->add_last(p_item);
            n=n/p_item;
            if(n==1){
                return factors;
            }
        }
        else{
            p=p->next_NODE();
        }
    }
    
    printf("ERROR: find_prime_factors failed with n=%d\n",n);
    factors->print_list();
    return factors;
    
}


int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    
    int N,K,S;
    scanf("%d %d %d",&N,&K,&S);
    
    int *data=(int *)calloc(N,sizeof(int));
    int largest=0;
    int sum=0;
    for(int i=0;i<N;i++){
        scanf("%d",(data+i));
        sum+=*(data+i);
        if(*(data+i)>largest){
            largest=*(data+i);
        }
    }
    
    S_LIST primes;
    find_primes(largest,&primes);
    primes.print_list();
        
    S_LIST factors;
    S_LIST *hold;
    SLL_NODE *p,*q,*r;           
    
    for(int i=0;i<N;i++){
        hold=find_prime_factors(*(data+i), &primes);
        q=hold->first_LIST();
        
        bool done=0;
        r=NULL;
        p=factors.first_LIST();
        while(!done){
            if(q==NULL){
                done=1;
            }
            else if(r==NULL && p==NULL){
                factors.add_first(q->item_NODE());
                p=factors.first_LIST();
                q=q->next_NODE();
            }
            else if(r==NULL && p->item_NODE()>q->item_NODE()){
                factors.add_first(q->item_NODE());
                p=factors.first_LIST();
                q=p->next_NODE();
            }
            else if(p==NULL){
                if(r->item_NODE() < q->item_NODE()){
                    factors.add_last(q->item_NODE());
                    q=q->next_NODE();
                    r=factors.last_LIST();
                }
                else{
                    done=1;
                }
            }
            else{
                if(p->item_NODE() == q->item_NODE()){
                    q=q->next_NODE();
                }
                else if(p->item_NODE() < q->item_NODE()){
                    r=p;
                    p=p->next_NODE();
                }
                else{
                    factors.add_at_node(r, q->item_NODE());
                    q=q->next_NODE();
                    r=r->next_NODE();
                }
            }
        }
        delete hold;
    }
    
    factors.print_list();
    
    int output=K-(factors.size_LIST() * S);
    //cout<<"sum="<<sum<<"\tout="<<output<<endl;
    output=sum*output;
    
    cout<<output<<endl;
    
    return output;
}
