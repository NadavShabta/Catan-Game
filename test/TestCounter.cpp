#ifndef TESTCOUNTER_HPP
#define TESTCOUNTER_HPP

#include <iostream>

class TestCounter {
private:
    int totalTests = 0;
    int passedTests = 0;

public:
    void incrementTotal() { ++totalTests; }
    void incrementPassed() { ++passedTests; }

    void reportResults() const {
        std::cout << "Total tests run: " << totalTests << std::endl;
        std::cout << "Tests passed: " << passedTests << std::endl;
        std::cout << "Tests failed: " << totalTests - passedTests << std::endl;
    }
};

#endif // TESTCOUNTER_HPP
