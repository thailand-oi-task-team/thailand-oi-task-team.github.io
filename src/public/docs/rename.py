# Author: Sirawit
# For: testcases from CODEFORCES POLYGON
# Note: Change `groups` to number of testcases in each group

import os

groups = [7, 6, 6, 5, 6, 12]

c = 1
for i in range(len(groups)):
    for j in range(groups[i]):
        print(f'tests/{str(c).zfill(2)}',
              f'tests/{str(i+1).zfill(2)}-{str(j+1).zfill(2)}.in')
        os.rename(
            f'tests/{str(c).zfill(2)}', f'tests/{str(i+1).zfill(2)}-{str(j+1).zfill(2)}.in')
        print(f'tests/{str(c).zfill(2)}.a',
              f'tests/{str(i+1).zfill(2)}-{str(j+1).zfill(2)}.sol')
        os.rename(
            f'tests/{str(c).zfill(2)}.a', f'tests/{str(i+1).zfill(2)}-{str(j+1).zfill(2)}.sol')
        c += 1
