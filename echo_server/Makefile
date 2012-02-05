
OBJS = echo_server.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
BOOST_LIB = /usr/lib

echo_server : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o echo_server -lpthread \
	 $(BOOST_LIB)/libboost_system.a

clean:
	\rm *.o echo_server
