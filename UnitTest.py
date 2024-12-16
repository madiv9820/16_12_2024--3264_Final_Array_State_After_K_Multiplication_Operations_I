from Solution import Solution
import unittest
from timeout_decorator import timeout

class UnitTest(unittest.TestCase):
    def setUp(self):
        self.__testCases = {1: ([2,1,3,5,6], 5, 2, [8,4,6,5,6]),
                            2: ([1,2], 3, 4, [16,8])}
        self.__obj = Solution()
        return super().setUp()
    
    @timeout(0.5)
    def test_case_1(self):
        nums, k, multiplier, output = self.__testCases[1]
        result = self.__obj.getFinalState(nums = nums, k = k, multiplier = multiplier)
        self.assertIsInstance(result, list)
        self.assertTrue(all(r == o for r, o in zip(result, output)))

    @timeout(0.5)
    def test_case_2(self):
        nums, k, multiplier, output = self.__testCases[2]
        result = self.__obj.getFinalState(nums = nums, k = k, multiplier = multiplier)
        self.assertIsInstance(result, list)
        self.assertTrue(all(r == o for r, o in zip(result, output)))

if __name__ == '__main__': unittest.main()