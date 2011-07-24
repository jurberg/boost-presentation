/*
 * Boosting your C++ Development with Boost
 */
#include "stdafx.h"
#include <boost/test/unit_test.hpp>
#include <boost/thread.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/lambda/loops.hpp>
#include "BlockingQueue.hpp"
#include <vector>

using namespace boost::lambda;

class MyThreadFunc 
{
public:
	MyThreadFunc() : count(0) {}
	void operator()() 
	{
		for (int i = 0; i < 100; i++)
		{
			count++;
		}
	}
	int count;
};


BOOST_AUTO_TEST_CASE(ThreadTest)
{
	MyThreadFunc f;
	boost::thread thread(boost::ref(f));

	int value = 0;
	var_type<int>::type counter(var(value));
	boost::thread thread2(for_loop(counter = 0, counter < constant(50), counter++));

	thread.join();
	thread2.join();

	BOOST_CHECK(f.count == 100);
	BOOST_CHECK(value == 50);

}

template <typename T>
class PutThreadFunc
{
public:
	PutThreadFunc(T& queue, int count, std::vector<int>& output) 
		: queue(queue)
		, count(count) 
		, output(output) 
	{
	}

	void operator()()
	{
		for (int i = 0; i < count; i++)
		{
			output.push_back(i);
			queue.Put(i);
			try
			{
				boost::this_thread::sleep(boost::posix_time::milliseconds(1000));
			}
			catch (boost::thread_interrupted&)
			{
				break;
			}
		}
	}

private:
	T& queue;
	int count;
	std::vector<int>& output;

};

template <typename T>
class TakeThreadFunc
{
public:
	TakeThreadFunc(T& queue, int count, std::vector<int>& output) 
		: queue(queue)
		, count(count)
		, output(output) 
	{
	}

	void operator()()
	{
		while (true)
		{
			int value = queue.Take();
			output.push_back(value);
			if (value >= (count - 1)) break;
			try
			{
				boost::this_thread::sleep(boost::posix_time::milliseconds(500));
			}
			catch (boost::thread_interrupted&)
			{
				break;
			}
		}
	}

private:
	T& queue;
	int count;
	std::vector<int>& output;

};

BOOST_AUTO_TEST_CASE(BlockingQueueTest)
{
	typedef BlockingQueue<int> IntQueue;
	
	IntQueue queue;
	int count = 10;
	std::vector<int> output;

	PutThreadFunc<IntQueue> put(queue, count, output);
	TakeThreadFunc<IntQueue> take(queue, count, output);

	boost::thread t1(boost::ref(put));
	boost::thread t2(boost::ref(take));

	t1.join();
	t2.join();
	
	int idx = 0;
	for (int i = 0; i < count; i++)
	{
		BOOST_REQUIRE(output[idx] == i);
		idx++;
		BOOST_REQUIRE(output[idx] == i);
		idx++;
	}

}

