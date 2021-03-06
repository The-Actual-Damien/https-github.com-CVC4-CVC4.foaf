#!/usr/bin/env python
#
# genkinds.py
# Top contributors (to current version):
#   Mudathir Mohamed
# This file is part of the CVC4 project.
# Copyright (c) 2009-2021 by the authors listed in the file AUTHORS
# in the top-level source directory and their institutional affiliations.
# All rights reserved.  See the file COPYING in the top-level source
# directory for licensing information.
#

"""
This script reads CVC4/src/api/cvc4cppkind.h and generates
cvc/Kind.java file which declare all the CVC4 kinds.
"""

import argparse
import os
import sys

# the following command in CVC4/build/src/api/java/CMakeFiles/gen-java-kinds.dir/build.make
# cd CVC4/build/src/api/java && /usr/bin/python3 CVC4/src/api/java/genkinds.py ...
# indicates we are in directory CVC4/build/src/api/java
# so we use ../../../../src/api to access CVC4/src/api/parsekinds.py
sys.path.insert(0, os.path.abspath('../../../../src/api'))

from parsekinds import *

# Default Filenames
DEFAULT_PREFIX = 'Kind'

# Code Blocks

KINDS_JAVA_TOP = \
    r"""package cvc;

import java.util.HashMap;
import java.util.Map;

public enum Kind 
{
"""

KINDS_JAVA_BOTTOM = \
    r""";

  /* the int value of the kind */
  private int value;
  private static Map<Integer, Kind> kindMap = new HashMap<>();
  private Kind(int value)
  {
    this.value = value;
  }

  static
  {
    for (Kind kind : Kind.values())
    {
      kindMap.put(kind.getValue(), kind);
    }
  }

  public static Kind fromInt(int value) throws CVCApiException
  {
    if (value < INTERNAL_KIND.value || value > LAST_KIND.value)
    {
      throw new CVCApiException("Kind value " + value + " is outside the valid range ["
          + INTERNAL_KIND.value + "," + LAST_KIND.value + "]");
    }
    return kindMap.get(value);
  }

  public int getValue()
  {
    return value;
  }
}
"""


# Files generation

def gen_java(parser: KindsParser, filename):
    f = open(filename, "w")
    code = KINDS_JAVA_TOP
    enum_value = -2  # initial enum value
    for kind, name in parser.kinds.items():
        code += "  {name}({enum_value}),\n".format(name=kind, enum_value=enum_value)
        enum_value = enum_value + 1
    code += KINDS_JAVA_BOTTOM
    f.write(code)
    f.close()


if __name__ == "__main__":
    parser = argparse.ArgumentParser('Read a kinds header file and generate a '
                                     'corresponding java file')
    parser.add_argument('--kinds-header', metavar='<KINDS_HEADER>',
                        help='The header file to read kinds from',
                        default=DEFAULT_HEADER)
    parser.add_argument('--kinds-file-prefix', metavar='<KIND_FILE_PREFIX>',
                        help='The prefix for the generated .java file',
                        default=DEFAULT_PREFIX)

    args = parser.parse_args()
    kinds_header = args.kinds_header
    kinds_file_prefix = args.kinds_file_prefix

    kp = KindsParser()
    kp.parse(kinds_header)

    gen_java(kp, kinds_file_prefix + ".java")
