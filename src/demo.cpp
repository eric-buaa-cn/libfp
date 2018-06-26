#include <iostream>
#include <libfp/retry_me.h>

bool func_success() {
    return true;
}

bool func_fail() {
    return false;
}

int32_t ok() {
    return 0;
}

int32_t not_ok() {
    return 1;
}

int main() {
    libfp::RetryMe retry;

    bool suceeded = retry.ExpectTrue(func_success);
    std::cout << "func_success result=" << suceeded << std::endl;

    bool failed = retry.ExpectTrue(func_fail);
    std::cout << "func_fail result=" << failed << std::endl;

    bool lambda_succeed = retry.ExpectTrue([]() { return 2 == 2; });
    std::cout << "lambda_success result=" << lambda_succeed << std::endl;

    bool lambda_failed = retry.ExpectTrue([]() { return 2 != 2; });
    std::cout << "lambda_fail result=" << lambda_failed << std::endl;

    bool ok_result = retry.ExpectZero(ok);
    std::cout << "ok_result=" << ok_result << std::endl;

    bool not_ok_result = retry.ExpectZero(not_ok);
    std::cout << "not_ok_result=" << not_ok_result << std::endl;
    return 0;
}
