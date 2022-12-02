Day 2
+++++
https://adventofcode.com/2022/day/2

In today's puzzle we're given list of Rock Paper Scissor game rounds,
each round consists of your opponent move - A for rock, B for paper, and C for scissors,
and what you should play in response (aka encrypted strategy guide that one of the Elves recommended us) in which: :: 
  
    X stands for rock,
    Y for paper,
    Z for scissors.

The main goal is to count the total score - since we are not sure if Elf actually wanted to help us.
Total score is sum of all scores of game rounds. Game round score is based on outcome, and the shape we played. 
Rock gives us 1 point, paper gives us 2 points, scissors gives us 3 points.
Besides that, we got 6 points for winning, 3 for draw, and 0 for loose.

Example series of game rounds: ::

    A Y <-- rock     vs. paper
    B X <-- paper    vs. rock
    C Z <-- scissors vs. scissors

Part 1
++++++

Our task for first part is to count a total score if everything goes exactly according to the strategy guide.

Therefore, summary of points for our previous example would be as follows: ::

    A Y <-- rock     vs. paper    (8 points)
    B X <-- paper    vs. rock     (1 point)
    C Z <-- scissors vs. scissors (6 points)

    Total: 15 points

We could translate this to the following algorithm: ::

    For each game round:
        Check for result of the game
        Calculate points based on:
            - game result
            - used shape.
        Sum calculated points
    Sum all

Which translates to the following code:

.. code-block:: cpp

    // winning lookup table
    const std::map<std::string, std::string> win_map = {
        {"A", "Y"},
        {"B", "Z"},
        {"C", "X"},
    };

    // draw lookup table
    const std::map<std::string, std::string> draw_map = {
        {"A", "X"},
        {"B", "Y"},
        {"C", "Z"},
    };

    // value lookup table
    const std::map<std::string, std::int32_t> figure_value_map = {
        {{"X", kRockValue}, {"Y", kPaperValue}, {"Z", kScissorsValue}}};

    // Function used to calculate value from given game round.3
    std::int64_t EvaluateStrategy(std::string player_a, std::string player_b) {
        std::int64_t value = kLooseValue;       // If none of moves is draw or win, we loose.


        if (win_map.at(player_a) == player_b) { // Check if player_b has winning move
            value = kWinValue;
        }

        if (draw_map.at(player_a) == player_b) { // Check if player_b has draw move
            value = kDrawValue;
        }

        return value;
    }

    // ...

    // Data is stored in an array of pairs of strings.
    std::int64_t Part01(
      const std::vector<std::pair<std::string, std::string>>& data) {
    const auto total_points = std::accumulate(                               // Iterate and sum each of the elements
        data.begin(), data.end(), 0,
        [](std::int64_t acc, std::pair<std::string, std::string> strategy) { // Pass each element through anonymous function.
          const auto strategy_value =
              EvaluateStrategy(strategy.first, strategy.second);             // Calculate result of the game
          const auto shape_value = figure_value_map.at(strategy.second);     // Calculate points of used shape
          return acc + strategy_value + shape_value;
        });

    return total_points;
  }


Part 2
++++++

Plot twist, our Elf wasn't telling us what figure should we play.
Rather it told us how the round needs to end. Now, X stands for loosing, Y for drawing, and Z for winning.

Our example series of game rounds would now look like this: ::

    A Y <-- rock     vs. rock (Y -> draw)
    B X <-- paper    vs. rock (X -> losing)
    C Z <-- scissors vs. rock (Z -> winning)

With following summary of points:

    A Y <-- rock     vs. rock (4 points)
    B X <-- paper    vs. rock (1 points)
    C Z <-- scissors vs. rock (7 points)

    Total: 12 points

Our goal for this part, is to find which figure we should play in order to obtain 
suggested game outcome.

Pseudo code: ::

    For each game round:
        Find for which figure we could obtain suggested outcome
        Calculate points based on:
            - game result
            - used shape.
        Sum calculated points
    Sum all

Which translates to the following code:

.. code-block:: cpp
    // Function used to calculate value from suggested outcome
    std::int64_t EvaluateStrategyAsIndicated(std::string player_a,
                                            std::string player_b_outcome) {
      const std::vector<std::string> player_move_set = {"X", "Y", "Z"};
      std::int64_t value = 0;

      const auto find_indicated_value =
          [&](std::int64_t indicated_value) -> std::int64_t {
        std::int64_t result = 0;

        for (const auto& player_move : player_move_set) {                 // Iterate over possible moves
          auto evaluated_value = EvaluateStrategy(player_a, player_move);

          if (evaluated_value == indicated_value) {                       // Check if any of the player moves gives us expected outcome
            result = indicated_value + figure_value_map.at(player_move);
            break;
          }
        }

        return result;
      };

      // we also check for loss in this example, cause we don't yet know
      // what figure would be used.
      if (player_b_outcome == "X" /* loose */) {                          // check for loos
        value = find_indicated_value(kLooseValue);
      }

      if (player_b_outcome == "Y" /* draw */) {                           // check for draw
        value = find_indicated_value(kDrawValue);
      }

      if (player_b_outcome == "Z" /* win */) {                            // Check for win
        value = find_indicated_value(kWinValue);
      }

      return value;
    }

    // ...

    // data is also stored in an array of pairs of strings.
    std::int64_t Part02(
        const std::vector<std::pair<std::string, std::string>>& data) {
      const auto total_points = std::accumulate(
        data.begin(), data.end(), 0,
        [](std::int64_t acc, std::pair<std::string, std::string> strategy) {
            const auto strategy_value =
                EvaluateStrategyAsIndicated(strategy.first, strategy.second); // Calculate result of the game (includes points for used shape)
            return acc + strategy_value;
        });

      return total_points;
    }
