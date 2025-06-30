# given from and to tests, and start, convert all school.XX.in and .sol to session.XX.in and sol with the new numbering from start
# Usage: python refactor.py from to start
# Example: python refactor.py 1 2 3

import os
import sys

from shutil import copyfile

def refactor(from_test: int, to_test: int, start: int):
    for i in range(from_test, to_test + 1):
        # with two digits
        from_file = f'school.{i:02}.in'
        to_file = f'session.{start:02}.in'
        print(f'{from_file:02} -> {to_file:02}')
        copyfile(from_file, to_file)

        from_file = f'school.{i:02}.sol'
        to_file = f'session.{start:02}.sol'
        copyfile(from_file, to_file)

        start += 1

def main():
    if len(sys.argv) != 4:
        print('Usage: python refactor.py from to start')
        print('Example: python refactor.py 1 2 3')
        return

    from_test = int(sys.argv[1])
    to_test = int(sys.argv[2])
    start = int(sys.argv[3])

    refactor(from_test, to_test, start)

if __name__ == '__main__':
    main()