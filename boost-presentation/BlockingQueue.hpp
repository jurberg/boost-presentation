/*
 * Boosting your C++ Development with Boost
 */
#pragma once

#include <list>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition.hpp>

template <typename T>
class BlockingQueue
{
public:
	BlockingQueue() : queue(), mutex(), cond() {}
	~BlockingQueue() {}

public:
	
	void Put(T obj)
	{
		boost::mutex::scoped_lock lock(mutex);
		queue.push_back(obj);
		cond.notify_all();		
	}
	
	T Take()
	{
		boost::mutex::scoped_lock lock(mutex);
		while (queue.size() == 0)
		{
			cond.wait(lock);
		}
		
		T value = queue.front();
		queue.pop_front();
		
		return value;
	}

private:
	std::list<T> queue;
	boost::mutex mutex;
	boost::condition cond;

};
