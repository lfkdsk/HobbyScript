import os
import argparse

from glob import glob
from graphviz import render

TEST_FILE_DIR = os.path.dirname(os.path.realpath(__file__)) + os.path.sep + 'tests' + os.path.sep + 'test_graph_gen'


def gen_graph(file_name):
    render('dot', 'png', file_name)


def main():
    parser = argparse.ArgumentParser()
    print(TEST_FILE_DIR)
    parser.add_argument('--dir', default=TEST_FILE_DIR, help='contains dot gv files dir.')
    args = parser.parse_args()
    result = [y for x in os.walk(args.dir) for y in glob(os.path.join(x[0], '*.gv'))]
    for gv in result:
        gen_graph(gv)


if __name__ == '__main__':
    main()
