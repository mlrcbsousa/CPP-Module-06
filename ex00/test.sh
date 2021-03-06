#!/bin/bash

echo "====== 0 ======"
./convert 0
# char: Non displayable
# int: 0
# float: 0.0f
# double: 0.0
echo
echo "====== nan ======"
./convert nan
# char: impossible
# int: impossible
# float: nanf
# double: nan
echo
echo "====== nanf ======"
./convert nanf
# char: impossible
# int: impossible
# float: nanf
# double: nan
echo
echo "====== +inf ======"
./convert +inf
# char: impossible
# int: impossible
# float: +inff
# double: +inf
echo
echo "====== +inff ======"
./convert +inff
# char: impossible
# int: impossible
# float: +inff
# double: +inf
echo
echo "====== -inf ======"
./convert -inf
# char: impossible
# int: impossible
# float: -inff
# double: -inf
echo
echo "====== -inff ======"
./convert -inff
# char: impossible
# int: impossible
# float: -inff
# double: -inf
echo
echo "====== 42.0f ======"
./convert 42.0f
# char: '*'
# int: 42
# float: 42.0f
# double: 42.0
echo
echo "====== 3f ======"
./convert 3f
# char: '*'
# int: 42
# float: 42.0f
# double: 42.0
