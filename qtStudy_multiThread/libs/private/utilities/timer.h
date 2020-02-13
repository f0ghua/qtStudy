#pragma once

#include <chrono>

typedef unsigned long u64;

class ChronoElapsedTimer
{
private:
	bool m_stopped;
	std::chrono::steady_clock::time_point m_start;
	std::chrono::steady_clock::time_point m_end;

public:
    ChronoElapsedTimer()
        : m_stopped(false)
	{
	}

    void start()
	{
		m_stopped = false;
		m_start = std::chrono::steady_clock::now();
	}

    void stop()
	{
		m_stopped = true;
		m_end = std::chrono::steady_clock::now();
	}

    double elapsed() const
    {
        return getElapsedTimeInMilliSec();
    }

    u64 nsecsElapsed() const
    {
        return getElapsedTimeInNanoSec();
    }

    double getElapsedTimeInSec() const
	{
        return double(getElapsedTimeInMicroSec()) / 1000000.0;
	}

    double getElapsedTimeInMilliSec() const
	{
        return double(getElapsedTimeInMicroSec()) / 1000.0;
	}

    u64 getElapsedTimeInMicroSec() const
	{
		std::chrono::steady_clock::time_point now = m_stopped ? m_end : std::chrono::steady_clock::now();

		return std::chrono::duration_cast<std::chrono::microseconds>(now - m_start).count();
	}

    u64 getElapsedTimeInNanoSec() const
	{
		std::chrono::steady_clock::time_point now = m_stopped ? m_end : std::chrono::steady_clock::now();

		return std::chrono::duration_cast<std::chrono::nanoseconds>(now - m_start).count();
	}

    u64 getMsSince(std::chrono::steady_clock::time_point timestamp)
	{
		std::chrono::steady_clock::time_point now = m_stopped ? m_end : std::chrono::steady_clock::now();

		return std::chrono::duration_cast<std::chrono::milliseconds>(now - timestamp).count();
	}
};
