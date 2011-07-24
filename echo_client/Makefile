
OBJS = echo_client.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
BOOST_LIB = /usr/local/lib

echo_client : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o echo_client -lpthread \
	 $(BOOST_LIB)/libboost_system.a

clean:
	\rm *.o  echo_client
