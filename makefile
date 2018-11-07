CFLAGS = -W -Wall -Wextra -Werror -std=c11
OBJS = processmodel_demo.o process.o queue.o processmodel.o

demo: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.c
	$(CC) %(CFLAGS) -c $<

clean:
	$(RM) *~ *.o demo
