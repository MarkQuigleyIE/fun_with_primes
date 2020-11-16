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
int find_primes(int n,S_LIST *P){
    int count=0;    //stores the number of primes;
    
    if(n<2){
        printf("ERROR: %d < 2 and has no prime factors\n", n);
        return count;
    }
    
    P->add_last(2);
    count++;

    int i,j;
    for(i=3;i<n;i+=2){      //test for primes and add to list
        //cout<<"\ti="<<i<<":";
        for(j=3; j<(i/2+1); j++){
            //cout<<"\tj="<<j;
            if(i%j==0){
                j=i;
                //cout<<"fail";
            }
        }
        //cout<<endl;
        if(j!=i+1){
            P->add_last(i);
            count++;
        }
    }
    
    return count;
}//*/

S_LIST * find_prime_factors(int n,S_LIST *primes){
    int p_item;
    S_LIST *factors=new S_LIST();
    SLL_NODE *p=primes->first_LIST();
    while( p->item_NODE() <= n ){
        p_item=p->item_NODE();
        //cout<<"n= "<<n<<"\tp="<<p_item;
        if( (n%p_item)==0 ){
            //cout<<"\tn%p==0";
            factors->add_last(p_item);
            n=n/p_item;
            if(n==1){
                //cout<<"\tn=1"<<endl;
                return factors;
            }
        }
        else{
            //cout<<"\tn%p!=0";
            p=p->next_NODE();
        }
        //cout<<endl;
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
    //primes.print_list();
    
    //S_LIST *factors=find_prime_factors(45, &primes);
    //factors->print_list();
    
    S_LIST factors;
    S_LIST *hold;
    SLL_NODE *p,*q,*r;           
    
    for(int i=0;i<N;i++){
        hold=find_prime_factors(*(data+i), &primes);
        //hold->print_list();
        q=hold->first_LIST();
        //p=factors.first_LIST();
        
        bool done=0;
        r=NULL;
        p=factors.first_LIST();
        while(!done){
            //cout<<"\tq="<<q->item_NODE()<<endl;
            if(q==NULL){
                //cout<<"\tq=NULL\n";
                done=1;
            }
            else if(r==NULL && p==NULL){
                //cout<<"\tr=NULL\tp=NULL\tq="<<q->item_NODE()<<endl;
                factors.add_first(q->item_NODE());
                p=factors.first_LIST();
                q=q->next_NODE();
                //cout<<"\t\tp="<<p->item_NODE()<<endl;
                //cout<<"\t\tq="<<q->item_NODE()<<endl;
            }
            else if(r==NULL && p->item_NODE()>q->item_NODE()){
                //cout<<"\t\tr=NULL\t"<<q->item_NODE()<<"\tp>q"<<endl;
                factors.add_first(q->item_NODE());
                p=factors.first_LIST();
                q=p->next_NODE();
            }
            /*
            if(r==NULL && ( p->item_NODE()>q->item_NODE() || p==NULL )){
                cout<<"\t\tr=NULL\n";
                if(p==NULL){
                    cout<<"\t\t\tp=NULL\n";
                    factors.add_first(q->item_NODE());
                    p=factors.first_LIST();
                    q=q->next_NODE();
                    cout<<"\t\t\tp="<<p->item_NODE()<<endl;
                    cout<<"\t\t\tq="<<q->item_NODE()<<endl;
                }
                else if(p->item_NODE()>q->item_NODE()){
                    cout<<"\t\t\tp>q\n";
                    factors.add_first(q->item_NODE());
                    p=factors.first_LIST();
                    q=p->next_NODE();
                }
                cout<<"\t\tFAIL1\n";
                cout<<"\t\tp="<<p->item_NODE()<<endl;
            }//*/
            else if(p==NULL){
                //cout<<"\tp=NULL\tq="<<q->item_NODE()<<endl;
                if(r->item_NODE() < q->item_NODE()){
                    //cout<<"\t\tr<q\n";
                    factors.add_last(q->item_NODE());
                    q=q->next_NODE();
                    r=factors.last_LIST();
                }
                else{
                    //cout<<"\t\telse\n";
                    done=1;
                }
            }
            else{
                //cout<<"\telse\tp="<<p->item_NODE()<<"\tq="<<q->item_NODE()<<endl;
                if(p->item_NODE() == q->item_NODE()){
                    //cout<<"\t\tp=q\n";
                    q=q->next_NODE();
                }
                else if(p->item_NODE() < q->item_NODE()){
                    //cout<<"\t\tp<q\n";
                    r=p;
                    p=p->next_NODE();
                }
                else{
                    //cout<<"\t\telse\tr="<<r->item_NODE()<<endl;
                    factors.add_at_node(r, q->item_NODE());
                    q=q->next_NODE();
                    r=r->next_NODE();
                }
            }
        }
        delete hold;
    }
    
    //factors.print_list();
    //cout<<"size="<<factors.size_LIST()<<endl;
    
    int output=K-(factors.size_LIST() * S);
    //cout<<"sum="<<sum<<"\tout="<<output<<endl;
    output=sum*output;
    
    cout<<output<<endl;
    
    return output;
}
