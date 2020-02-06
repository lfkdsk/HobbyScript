import os
import argparse

from glob import glob
import subprocess

TEST_FILE_DIR = os.path.dirname(os.path.realpath(__file__)) + os.path.sep + 'src' + os.path.sep + 'plugins'


def main():
    parser = argparse.ArgumentParser()
    print(TEST_FILE_DIR)
    parser.add_argument('--dir', default=TEST_FILE_DIR, help='contains plugins files dir.')
    args = parser.parse_args()
    result = [os.path.join(x[0], y) for x in os.walk(args.dir) for y in x[2] if y.endswith('.c') or y.endswith('.cpp')]
    for gv in result:
        print(f'/usr/bin/clang -S -emit-llvm {gv} -o {gv.rsplit(".", 1)[0]}.ll')
        os.system(f'/usr/bin/clang -S -emit-llvm {gv} -o {gv.rsplit(".", 1)[0]}.ll')


if __name__ == '__main__':
    main()
