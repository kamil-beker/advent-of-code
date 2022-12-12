#!/usr/bin/env bash
set -euo pipefail 

day_number="${1}"

cc_file="src/cpp/day_${day_number}.cc"
cc_test_file="test/cpp/test_day_${day_number}.cc"
h_file="src/cpp/day_${day_number}.h"
data_test_file="data/${day_number}-test.txt"
data_file="data/${day_number}.txt"

cp src/cpp/day_template.cc "${cc_file}"
cp src/cpp/day_template.h "${h_file}"
cp test/cpp/test_day_template.cc "${cc_test_file}"

perl -pi -e "s/Template|template|TEMPLATE/${day_number}/g" "${cc_file}"
perl -pi -e "s/Template|template|TEMPLATE/${day_number}/g" "${h_file}"
perl -pi -e "s/Template|template|TEMPLATE/${day_number}/g" "${cc_test_file}"

touch "${data_test_file}"
touch "${data_file}"

echo 0 > "${data_test_file}"
echo 0 > "${data_file}"
