//
// Created by zhuxiliuyun on 11/10/18.
//

#include <iostream>
#include <cstdlib>
#include <cstdio>
#define MAX 100000

using namespace std;

typedef struct _node {
    int num;
    int next;
} Node;

Node a[MAX];
Node* reverse(Node *p, int k);

int main(int argc, char const * argv[])
{
    int head, n, k;
    cin >> head >> n >> k;
    int add;
    for ( int i=0; i<n; i++ ) {
        cin >> add;
        cin >> a[add].num >> a[add].next;
    }
    Node nodep;
    nodep.next = head;
    head = reverse(&nodep,k)->next;
    int flag = 1;
    do {
        printf("%05d %d ", head, a[head].num);
        if ( a[head].next == -1 ) {
            printf("-1");
            flag = 0;
        }
        else printf("%05d\n", a[head].next);
        head = a[head].next;
    } while ( flag );
    return 0;
}

Node* reverse(Node *p, int k)
{
    int now, old, temp;
    now = p->next;
    old = a[now].next;
    if ( old == -1 ) return p;
    temp= a[old].next;
    if ( temp== -1 ) {
        if ( k==2 ) {
            a[old].next = now;
            a[now].next = -1;
            p->next = old;
            return p;
        }
        else return p;
    }
    bool f = 0;
    for ( int cnt=1; cnt<k; cnt++ ) {
        if ( cnt==k-1 && a[old].next==-1 ) f=1;
        a[old].next = now;
        now = old;
        old = temp;
        temp= a[temp].next;
    }
    Node rep = {0, p->next};
    if ( f ) a[p->next].next = -1;
    else a[p->next].next = old;

    p->next = now;

    if ( f ) return p;

    int cnt = 0;
    temp = old;

    while ( a[old].next!=-1 ) {
        old = a[old].next;
        cnt++;
        if ( cnt==k-1 ) break;
    }
    if ( cnt==k-1 ) {
        //p.next = temp;
        reverse(&a[rep.next], k);
    }
    return p;
}