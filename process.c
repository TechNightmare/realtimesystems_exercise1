#include "process.h"

void p_switch_state(struct process *p){
    if(p->p_state == READY) p->p_state = RUNNING;
    else p->p_state = READY;
};

void p_print(struct process *p){
    printf("Prozess-ID: %i ", p->p_id);
    if(p->p_state == READY) printf("Prozess-Status: READY\n");
    else printf("Prozess-Status: RUNNING\n");
};
