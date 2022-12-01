#!/usr/bin/env bash
set -euo pipefail

clang-format -i src/**/*.cc src/**/*.h test/**/*.cc test/**/*.h

echo "done!"
