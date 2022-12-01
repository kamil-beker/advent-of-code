Day 1
+++++
https://adventofcode.com/2022/day/1

In today's puzzle we're given the number of calories each Elf is carrying.

For example: ::

      1000
      2000
      3000

      4000

      5000
      6000

      7000
      8000
      9000

      10000

Where each blank line separates the Elf inventories: ::

      1000 <-- First Elf
      2000
      3000

      4000 <-- Second Elf

      5000 <-- Third Elf
      6000

      7000 <-- Fourth Elf
      8000
      9000

      10000 <- Fifth Elf

Part 1
++++++

Our task for first part is pretty simple, we need to find Elf, which inventory contains the most calories.

For this problem our algorithm needs to do three things: ::

      Iterate over inventories.
      Sum its elements.
      Keep track of maximum element.

Which translates to the following code:

.. code-block:: cpp

  // data is stored in two dimensional array in form of vector of vectors.
  std::int64_t Part01(std::vector<std::vector<std::int32_t>> data) {
    std::int64_t max = 0;

    for (const auto& i : data) {                              // iterate over inventories
      auto current = std::accumulate(i.begin(), i.end(), 0);  // sum elements
      if (current > max) {                                    // keep track of maximum element
        max = current;
      }
    }

    return max;                                               // answer
  }

Part 2
++++++

Similary to first part, our task for second part, is to find top three Elves carrying the most calories.

This part can be probably achieved in many other ways, however I've decided to go with simple vector of sums,
that we will later sort in descending order, and pick three top-most elements.

Pseudo code: ::

      Iterate over inventories.
      Sum its elements.
      Push sum to array.
      Sort array of sums in descending order.
      Sum three top-most elements.
      
Which translates to following code:

.. code-block:: cpp

  // data is stored in two dimensional array in form of vector of vectors.
  std::int64_t Part02(std::vector<std::vector<std::int32_t>> data) {
    std::int64_t max = 0;
    std::vector<std::int32_t> sums;                                     // vector of sums

    for (const auto& i : data) {
      auto sum = std::accumulate(i.begin(), i.end(), 0);                // sum elements
      sums.push_back(sum);
    }

    std::sort(sums.begin(), sums.end(), std::greater<std::int32_t>());  // sort in descending order
    max = std::accumulate(sums.begin(), sums.begin() + 3, 0);           // sum three top-most elements

    return max;                                                         // answer
  }

