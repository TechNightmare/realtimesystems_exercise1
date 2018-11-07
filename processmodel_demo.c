#include <unistd.h>

#include "processmodel_demo.h"
#include "process.h"
#include "queue.h"
#include "processmodel.h"

#define ANZ 10

int main(){
    struct queue q;
    struct pctx ctx;
    for(int i = 0; i < ANZ; i++) make_Queue(&q);

    ctx.qready = &q;

    for(;;){
        step(&ctx);
        print(&ctx);
        sleep(1);
    }

}

void make_Queue(struct queue *q){
    struct process *p;
    p = calloc(1,sizeof(struct process));
    p->p_id = rand() % (1001);
    p->p_state = READY;
    q_add(q, p);
}