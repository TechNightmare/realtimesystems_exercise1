#ifndef PROCESS_H
#define PROCESS_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdint.h>
   //#include <inttypes.h>

    typedef enum state{READY, RUNNING} state;

    struct process{
        uint32_t p_id;
        state p_state;
    };

    void p_switch_state(struct process *p);

    void p_print(struct process *p);

#endif