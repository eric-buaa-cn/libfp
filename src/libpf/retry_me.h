#ifndef RETRY_ME_H
#define RETRY_ME_H

#include <thread>
#include <chrono>

namespace libfp {

class RetryMe final {
public:
    RetryMe() :
        _internal_ms(100),
        _max_retry_count(1) {
    }

    RetryMe& SetIntervalMs(int32_t internal_ms) {
        _internal_ms = internal_ms;
        return *this;
    }

    RetryMe& SetMaxRetryCount(int32_t max_retry_count) {
        _max_retry_count = max_retry_count;
        return *this;
    }

    template <typename F, typename... Args>
    bool ExpectTrue(F func, Args&&... args) {
        int32_t try_count{0};
        while (try_count < _max_retry_count) {
            if (func(std::forward<Args>(args)...)) {
                return true;
            }

            std::this_thread::sleep_for(
                    std::chrono::milliseconds(_internal_ms));
            ++try_count;
        }
        return false;
    }

    template <typename F, typename... Args>
    bool ExpectZero(F func, Args&&... args) {
        int32_t try_count{0};
        while (try_count < _max_retry_count) {
            if (func(std::forward<Args>(args)...) == 0) {
                return true;
            }

            std::this_thread::sleep_for(
                    std::chrono::milliseconds(_internal_ms));
            ++try_count;
        }
        return false;
    }

private:
    int32_t _internal_ms;
    int32_t _max_retry_count;
};

}

#endif
