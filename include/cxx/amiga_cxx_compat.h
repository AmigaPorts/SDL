/* amiga_cxx_compat.h -- C++ standard library compatibility for AmigaOS 3.x
 * Include via -include amiga_cxx_compat.h in CXXFLAGS.
 *
 * Fixes:
 * - std::round/lround/hypot missing from std namespace in <cmath>
 * - std::mutex/condition_variable/thread not available (no gthreads)
 *   -> Wraps SDL2 threading primitives instead
 *
 * IMPORTANT: Each namespace std {} block must be self-contained.
 * Do NOT include system headers from inside namespace std. */

#ifndef AMIGA_CXX_COMPAT_H
#define AMIGA_CXX_COMPAT_H

/* --- Part 1: Fix math namespace (before anything else) --- */
#include <cmath>
#include <cstdlib>

namespace std {
    using ::round;
    using ::lround;
    using ::hypot;
    using ::llround;
}

/* --- Part 2: Include all needed system headers BEFORE our shims --- */
#include <SDL_mutex.h>
#include <SDL_thread.h>
#include <SDL_timer.h>
#include <chrono>
#include <functional>
#include <memory>

/* --- Part 3: Mutex shims (SDL2-backed) --- */
/* The system <mutex> exists but std::mutex is gated behind
 * _GLIBCXX_HAS_GTHREADS which is not defined on AmigaOS. */

namespace std {

class mutex {
    SDL_mutex *_m;
public:
    mutex() : _m(SDL_CreateMutex()) {}
    ~mutex() { if (_m) SDL_DestroyMutex(_m); }
    mutex(const mutex&) = delete;
    mutex& operator=(const mutex&) = delete;
    void lock() { SDL_LockMutex(_m); }
    void unlock() { SDL_UnlockMutex(_m); }
    bool try_lock() { return SDL_TryLockMutex(_m) == 0; }
    SDL_mutex *native_handle() { return _m; }
};

class recursive_mutex {
    SDL_mutex *_m;
public:
    recursive_mutex() : _m(SDL_CreateMutex()) {}
    ~recursive_mutex() { if (_m) SDL_DestroyMutex(_m); }
    recursive_mutex(const recursive_mutex&) = delete;
    recursive_mutex& operator=(const recursive_mutex&) = delete;
    void lock() { SDL_LockMutex(_m); }
    void unlock() { SDL_UnlockMutex(_m); }
    bool try_lock() { return SDL_TryLockMutex(_m) == 0; }
    SDL_mutex *native_handle() { return _m; }
};

template<typename M> class lock_guard {
    M &_m;
public:
    explicit lock_guard(M &m) : _m(m) { _m.lock(); }
    ~lock_guard() { _m.unlock(); }
    lock_guard(const lock_guard&) = delete;
    lock_guard& operator=(const lock_guard&) = delete;
};

template<typename M> class unique_lock {
    M *_m; bool _owns;
public:
    unique_lock() : _m(nullptr), _owns(false) {}
    explicit unique_lock(M &m) : _m(&m), _owns(true) { _m->lock(); }
    ~unique_lock() { if (_owns && _m) _m->unlock(); }
    unique_lock(const unique_lock&) = delete;
    unique_lock& operator=(const unique_lock&) = delete;
    unique_lock(unique_lock &&o) : _m(o._m), _owns(o._owns)
        { o._m = nullptr; o._owns = false; }
    unique_lock& operator=(unique_lock &&o) {
        if (_owns && _m) _m->unlock();
        _m = o._m; _owns = o._owns; o._m = nullptr; o._owns = false;
        return *this;
    }
    void lock() { _m->lock(); _owns = true; }
    void unlock() { _m->unlock(); _owns = false; }
    bool owns_lock() const { return _owns; }
    M *mutex() const { return _m; }
    SDL_mutex *native_handle() { return _m ? _m->native_handle() : nullptr; }
};

template<typename... Ms> class scoped_lock;
template<typename M> class scoped_lock<M> {
    M &_m;
public:
    explicit scoped_lock(M &m) : _m(m) { _m.lock(); }
    ~scoped_lock() { _m.unlock(); }
    scoped_lock(const scoped_lock&) = delete;
    scoped_lock& operator=(const scoped_lock&) = delete;
};

/* --- Part 4: condition_variable shim --- */

enum class cv_status { no_timeout, timeout };

class condition_variable {
    SDL_cond *_c;
public:
    condition_variable() : _c(SDL_CreateCond()) {}
    ~condition_variable() { if (_c) SDL_DestroyCond(_c); }
    condition_variable(const condition_variable&) = delete;
    condition_variable& operator=(const condition_variable&) = delete;
    void notify_one() { SDL_CondSignal(_c); }
    void notify_all() { SDL_CondBroadcast(_c); }
    void wait(unique_lock<mutex> &lk) { SDL_CondWait(_c, lk.native_handle()); }
    template<typename P>
    void wait(unique_lock<mutex> &lk, P pred) {
        while (!pred()) SDL_CondWait(_c, lk.native_handle());
    }
};

/* --- Part 5: thread shim --- */

class thread {
public:
    class id {
        SDL_threadID _id;
    public:
        id() : _id(0) {}
        explicit id(SDL_threadID t) : _id(t) {}
        bool operator==(const id &o) const { return _id == o._id; }
        bool operator!=(const id &o) const { return _id != o._id; }
    };
private:
    SDL_Thread *_t; id _id;
    struct TD { std::function<void()> fn; };
    static int SDLCALL _run(void *d) {
        auto *td = static_cast<TD*>(d); td->fn(); delete td; return 0;
    }
public:
    thread() : _t(nullptr) {}
    template<typename F, typename... A>
    explicit thread(F &&f, A&&... a) : _t(nullptr) {
        auto *td = new TD{std::bind(std::forward<F>(f), std::forward<A>(a)...)};
        _t = SDL_CreateThread(_run, "cxx", td);
        if (_t) _id = id(SDL_GetThreadID(_t)); else delete td;
    }
    ~thread() { if (joinable()) SDL_DetachThread(_t); }
    thread(const thread&) = delete;
    thread& operator=(const thread&) = delete;
    thread(thread &&o) : _t(o._t), _id(o._id) { o._t=nullptr; o._id=id(); }
    thread& operator=(thread &&o) {
        if (joinable()) SDL_DetachThread(_t);
        _t=o._t; _id=o._id; o._t=nullptr; o._id=id(); return *this;
    }
    bool joinable() const { return _t != nullptr; }
    void join() { if(_t){int s;SDL_WaitThread(_t,&s);_t=nullptr;_id=id();} }
    void detach() { if(_t){SDL_DetachThread(_t);_t=nullptr;_id=id();} }
    id get_id() const { return _id; }
};

namespace this_thread {
    inline thread::id get_id() { return thread::id(SDL_ThreadID()); }
    template<typename R, typename P>
    inline void sleep_for(const std::chrono::duration<R,P> &d) {
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(d);
        SDL_Delay(static_cast<Uint32>(ms.count()));
    }
}

/* 68k: int/long and unsigned int/unsigned long are same width but
 * different types. Provide mixed overloads for std algorithms. */
inline long clamp(long v, int lo, int hi) {
    return (v < lo) ? (long)lo : (v > hi) ? (long)hi : v;
}
inline unsigned long min(unsigned int a, unsigned long b) { return (a < b) ? a : b; }
inline unsigned long min(unsigned long a, unsigned int b) { return (a < b) ? a : b; }
inline unsigned long max(unsigned int a, unsigned long b) { return (a > b) ? a : b; }
inline unsigned long max(unsigned long a, unsigned int b) { return (a > b) ? a : b; }

} /* namespace std */

/* Guard against system headers redefining our shims.
 * These guards must match the system header include guards exactly. */
#define _GLIBCXX_MUTEX 1
#define _GLIBCXX_UNIQUE_LOCK_H 1
#define _GLIBCXX_THREAD 1
#define _GLIBCXX_CONDITION_VARIABLE 1
#define _GLIBCXX_THIS_THREAD_SLEEP_H 1

#endif /* AMIGA_CXX_COMPAT_H */
