/*
 * Boosting your C++ Development with Boost
 */
#pragma once
/*
 * Boosting your C++ Development with Boost
 */
#include "stdafx.h"
#include <boost/test/unit_test.hpp>

#if defined(_MSC_VER)

#ifdef _DEBUG

	#define MEMORY_CHECKPOINT \
		CMemoryState memStateStart, memStateEnd, memStateDiff; \
		memStateStart.Checkpoint(); \
		{

	#define ASSERT_MEMORY_LEAK \
		} \
		memStateEnd.Checkpoint(); \
		if (!memStateDiff.Difference(memStateStart, memStateEnd)) \
		{ \
			BOOST_FAIL("A memory leak was expected"); \
		}

	#define ASSERT_NO_MEMORY_LEAK \
		} \
		memStateEnd.Checkpoint(); \
		if (memStateDiff.Difference(memStateStart, memStateEnd)) \
		{ \
			BOOST_FAIL("A memory leak exists"); \
		}

#else

	#define MEMORY_CHECKPOINT

	#define ASSERT_MEMORY_LEAK 

	#define ASSERT_NO_MEMORY_LEAK

#endif

#elif defined(__GNUC__)

#ifdef DEBUG

	#include <malloc.h>

	#define MEMORY_CHECKPOINT \
		struct mallinfo memStart; \
		struct mallinfo memEnd; \
		memStart = mallinfo(); \
		{

	#define ASSERT_MEMORY_LEAK \
		} \
		memEnd = mallinfo(); \
		if (memStart.uordblks == memEnd.uordblks) \
		{ \
			BOOST_FAIL("A memory leak was expected"); \
		}

	#define ASSERT_NO_MEMORY_LEAK \
		} \
		memEnd = mallinfo(); \
		if (memStart.uordblks != memEnd.uordblks) \
		{ \
			BOOST_FAIL("A memory leak exists"); \
		}

#else

	#define MEMORY_CHECKPOINT

	#define ASSERT_MEMORY_LEAK 

	#define ASSERT_NO_MEMORY_LEAK

#endif

#endif

