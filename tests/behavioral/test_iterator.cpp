#include <NTest.h>
#include <gofpp/behavioral/iterator.hpp>
#include <vector>

using namespace gofpp;

TEST(Iterator_SequentialAccess) {
    std::vector<int> nums = {1,2,3};
    Iterator<std::vector<int>> it(nums);

    int sum = 0;
    while(it.hasNext()) sum += it.next();

    ASSERT_EQ(sum, 6);
}

int main() { return NTest::run_all(); }
