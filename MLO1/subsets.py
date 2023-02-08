def backtrack(powerSet, tempSet, nums, start):
    # append current tempSet to powerSet
    powerSet.append(tempSet.copy())

    # iterate through each remaining num
    for i in range(start, len(nums)):
        # current element is on
        tempSet.append(nums[i])

        # backtrack subset
        backtrack(powerSet, tempSet, nums, i + 1)

        # current element is off
        tempSet.pop()

def subsets(nums):
    powerSet = []
    tempSet = []

    backtrack(powerSet, tempSet, nums, 0)

    return powerSet

if __name__ == "__main__":
    nums1 = [3 , 4, 5, 6]
    nums2 = [1, 3, 5]
    nums3 = [1, 5]

    print("Powerset for subset: " + str(nums1))
    print(subsets(nums1))
    print()
    print("Powerset for subset: " + str(nums2))
    print(subsets(nums2))
    print()
    print("Powerset for subset: " + str(nums3))
    print(subsets(nums3))
    print()

