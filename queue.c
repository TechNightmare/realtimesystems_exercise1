#include "queue.h"
#include "process.h"

void q_add(struct queue *q, struct process *p){
    q_node *new_node;
    if(!q || !p){
        fprintf(stderr, "q_add: Keine Queue oder kein Prozess uebergeben!");
    }else if((new_node = calloc(1, sizeof(q_node)))){
        if(q->start == NULL){
            q->start = new_node;
            q->end = new_node;
        } 
        else{
            q->end->next = new_node;
            q->end = new_node;
        }
        new_node->p = p;
        new_node->next = NULL;
    }else fprintf(stderr, "q_add: Speicherreservierung fehlgeschlagen!");
}

struct process *q_remove(struct queue *q){
    if(q || !q->start){
        q_node *node = q->start;
        struct process *ret_p = node->p;
        q->start = node->next;
        if(!q->start) q->end = NULL; 
        free(node);
        return ret_p;
    }
    return NULL;
}

void q_print(struct queue *q){
    if(q){
        q_node *print = q->start;
        puts("Current Queue:");
        while(print){
            p_print(print->p);
            print = print->next;
            //puts("\n");
        }
    }else fprintf(stderr, "q_print: Keine Queue uebergeben!");
}