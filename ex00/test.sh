#!/bin/bash

function header () {
    echo
    echo "[ " $1 " ]"
    echo
}

function test () {
    echo $1
    ./convert $1
    echo
}

make

header "special float"

test -inff
test +inff
test inff
test nanf

header "special double"

test -inf
test +inf
test inf
test nan

header "int"

test 0
test 1
test 42
test -42

header "float"

test 0.0f
test -4.2f
test 4.2f
test -42.0f
test 42.0f

header "basic double"

test 0.0
test -4.2
test 4.2
test -42.0
test 42.0
test 1.1
test 1.2
test 1.3
test 1.5

header "overflow"

test 2147483647
test 2147483648
test -2147483648
test -2147483649

header "large"

test 340282346638528859811704183484516925440
test 3402823466385288598117041834845169254400
test -340282346638528859811704183484516925440
test -3402823466385288598117041834845169254400
test 0.000000000000000000000000000000000000011754943508222875079687365372222456778186655567720875215087517062784172594547271728515625000000000000000000000000

header "char"

test +
test -
test a
test f

header "error"

test +f
test -f
test na
test "in"
test +in
test 0x4
test 0xf
