..
   Why RST? Cause it's learning time!

==============
Advent of Code
==============

-------------------------------------
Solutions to the Advent of Code 2022.
-------------------------------------

.. contents:: Table Of Contents
   :depth: 2

Getting Started
---------------
This repository is a collection of solutions for this years (2022) Advent of Code. 
Entire project is based on bazel and therefore requires it - Just in case you would ever would like to run those solutions on your machine.
You can read more about bazel build system, and how to set it up there: `bazel.build <https://bazel.build/>`_.

Solutions are written in C++14, and Haskell.

Compiling
+++++++++

.. code-block:: bash

  bazel buld //src:all

  bazel build //src/cpp:main
  bazel build //src/hs:main

  bazel build //src/cpp:day_<number>
  bazel build //src/hs:day_<number>

Running
+++++++

.. code-block:: bash

  bazel run //src/cpp:main
  bazel run //src/hs:main

Testing
+++++++

.. code-block:: bash

  bazel test //test:unittests

  bazel test //test/cpp:unittests
  bazel test //test/hs:unittests

  bazel test //test/cpp:day_<number>
  bazel test //test/hs:day_<number>

Benchmarks
++++++++++

.. code-block:: bash

  bazel run //utils:benchmarks

Performance
-----------
CPU: Apple M1 Pro.

.. code-block:: bash

  C++
  +---------+---------+--------+--------+-------+
  | Day     | Parsing | Part 1 | Part 2 | Total |
  +---------+---------+--------+--------+-------+
  | Day 01  |         |        |        |       |
  +---------+---------+--------+--------+-------+
  | Summary |         |        |        |       |
  +---------+---------+--------+--------+-------+

  Haskell
  +---------+---------+--------+--------+-------+
  | Day     | Parsing | Part 1 | Part 2 | Total |
  +---------+---------+--------+--------+-------+
  | Day 01  |         |        |        |       |
  +---------+---------+--------+--------+-------+
  | Summary |         |        |        |       |
  +---------+---------+--------+--------+-------+

Meditations
-----------

Meditations are daily-updated reflections about todays puzzle, `<meditations/README.rst>`_.

Resources
---------

Below you can find some of the resources that I've found helpful during this project.

- `<https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines>`_
- `<https://www.autosar.org/fileadmin/user_upload/standards/adaptive/17-03/AUTOSAR_RS_CPP14Guidelines.pdf>`_
- `<https://www.simplehaskell.org/>`_
- `<https://math.berkeley.edu/~gmelvin/polya.pdf>`_

License
-------

This project is licensed under the GNU General Public License - see the `<LICENSE>`_ file for details.