
OBJS = bind_tests.o FastPimplScoped.o scoped_ptr_tests.o boost_test.o \
 function_tests.o shared_ptr_tests.o Customer.o intrusive_ptr_tests.o \
 signals_test.o CustomerRepository.o lambda_tests.o thread_tests.o \
 CustomerTest.o Money.o timer_test.o FastPimpl.o MoneyTest.o weak_ptr_tests.o

CC = g++ 
DEBUG = -g 
CFLAGS = -Wall -c $(DEBUG) -DDEBUG
LFLAGS = -Wall $(DEBUG)
BOOST_LIB_DIR = /usr/lib
BOOST_LIBS = $(BOOST_LIB_DIR)/libboost_system.a \
 $(BOOST_LIB_DIR)/libboost_unit_test_framework.a \
 $(BOOST_LIB_DIR)/libboost_signals.a \
 $(BOOST_LIB_DIR)/libboost_thread.a

.cpp.o:
	$(CC) $(CFLAGS) -c $<

boost_presentation : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o boost_presentation -lpthread $(BOOST_LIBS)

Customer.o CustomerTest.o : Customer.hpp

CustomerRepository.o : CustomerRepository.hpp Customer.hpp

FastPimpl.o : FastPimpl.hpp

FastPimplScoped.o : FastPimplScoped.hpp

intrusive_ptr_tests.o : CustomerRepository.hpp

Money.o MoneyTest.o : Money.hpp

scoped_ptr_tests.o : Money.hpp FastPimpl.hpp FastPimplScoped.hpp

shared_ptr_tests.o : Customer.hpp CustomerRepository.hpp

thread_tests.o : BlockingQueue.hpp

weak_ptr_tests.o : Customer.hpp

clean:
	\rm *.o boost_presentation
