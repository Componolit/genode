/*
 * \brief  POSIX readers/writer lock (rwlock) implementation
 * \author Alexander Senier
 * \date   2018-01-25
 *
 */

/* Genode includes */
#include <base/log.h>
#include <base/lock.h>
#include <base/lock_guard.h>

/* Libc includes */
#include <pthread.h>

/*
 * A reader-preferring implementation of a readers-writer lock as described
 * in Michael Raynal, "Concurrent Programming: Algorithms, Principles, and
 * Foundations", ISBN 978-3-642-32026-2, page 75
 */

extern "C" {

	/*
	 * This class is named 'struct pthread_rwlock' because the 'pthread_rwlock_t'
	 * type is defined as 'struct rwlock*' in 'sys/_pthreadtypes.h'
	 */
	struct pthread_rwlock
	{
	private:

		typedef enum { RWLOCK_UNLOCKED, RWLOCK_READ, RWLOCK_WRITE } State;

		/*
		 * As POSIX defines only a single unlock operation, we need to track
		 * the state of the lock to either perform an unlock operation for
		 * a reader lock or a writer lock.
		 */
		State _state = RWLOCK_UNLOCKED;
		Genode::Lock _nbr_mutex {};
		Genode::Lock _global_mutex {};
		int _nbr = 0;

		void _begin_read()
		{
			Genode::Lock_guard<Genode::Lock> guard(_nbr_mutex);
			++_nbr;
			if (_nbr == 1) {
				_global_mutex.lock();
			}
		}

		void _end_read()
		{
			Genode::Lock_guard<Genode::Lock> guard(_nbr_mutex);
			_nbr--;
			if (_nbr == 0) {
				_global_mutex.unlock();
			}
		}

		void _begin_write() { _global_mutex.lock(); }

		void _end_write() { _global_mutex.unlock(); }

		public:
			int rdlock()
			{
				if (_state != RWLOCK_UNLOCKED) {
					Genode::warning("Read lock on locked rwlock (state=", int(_state), ")");
					return -1;
				}

				_state = RWLOCK_READ;
				_begin_read();
				return 0;
			}

			int wrlock()
			{
				if (_state != RWLOCK_UNLOCKED) {
					Genode::warning("Write lock on locked rwlock (state=", int(_state), ")");
					return -1;
				}
				_state = RWLOCK_WRITE;
				_begin_write();
				return 0;
			}

			int unlock()
			{
				switch (_state) {
				case RWLOCK_UNLOCKED:
					Genode::warning("Unlock on unlocked rwlock (state=", int(_state), ")");
					return -1;
				case RWLOCK_WRITE:
					_end_write();
					break;
				case RWLOCK_READ:
					_end_read();
					break;
				default:
					Genode::error("Invalid lock state (state=", int(_state), ")");
					return -1;
				}

				_state = RWLOCK_UNLOCKED;
				return 0;
			}
	};

	int pthread_rwlock_init(pthread_rwlock_t *rwlock, const pthread_rwlockattr_t *attr)
	{
		/* We do not support attributes */
		if (attr != nullptr) {
			Genode::error(__func__, " attr was not NULL");
			return -1;
		}

		*rwlock = new struct pthread_rwlock();
		          return 0;
	          }

	          int pthread_rwlock_destroy(pthread_rwlock_t *rwlock)
	          {
		          delete *rwlock;
		          return 0;
	          }

	          int pthread_rwlock_rdlock(pthread_rwlock_t * rwlock)
	          {
		          return (*rwlock)->rdlock();
	          }

	          int pthread_rwlock_wrlock(pthread_rwlock_t *rwlock)
	          {
		          return (*rwlock)->wrlock();
	          }

	          int pthread_rwlock_unlock(pthread_rwlock_t *rwlock)
	          {
		          return (*rwlock)->unlock();
	          }

	/*
	 * Unimplemented functions:
	 *  int pthread_rwlock_timedrdlock(pthread_rwlock_t *, const struct timespec *);
	 *  int pthread_rwlock_timedwrlock(pthread_rwlock_t *, const struct timespec *);
	 *  int pthread_rwlock_tryrdlock(pthread_rwlock_t *);
	 *  int pthread_rwlock_trywrlock(pthread_rwlock_t *);
	 *  int pthread_rwlockattr_init(pthread_rwlockattr_t *);
	 *  int pthread_rwlockattr_getpshared(const pthread_rwlockattr_t *, int *);
	 *  int pthread_rwlockattr_setpshared(pthread_rwlockattr_t *, int);
	 *  int pthread_rwlockattr_destroy(pthread_rwlockattr_t *);
	 */
}
