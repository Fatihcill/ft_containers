#------------ VARIABLES ----------------
TEXT_COLOR_RED="\033[1;31m"
TEXT_COLOR_GREEN="\033[1;32m"
TEXT_COLOR_DEFAULT="\033[0m"
# COMPILE_FLAGS="c++ -Wall -Wextra -Werror -std=c++98"
COMPILE_FLAGS="c++ -Wall -Wextra -Werror -std=c++98 -fsanitize=address -static-libsan -g"

TEST_NAME=(\
    "constructors" \
    "= operator" \
    "at" \
    "[] operator" \
    "assign" \
    "front/back" \
    "size, max_size and capacity" \
    "resize" \
    "reserve" \
    "push_back/pop_back" \
    "swap" \
    "clear" \
    "relational operators" \
    "insert" \
    "erase" \
    )

how_many=${#TEST_NAME[@]}

STD_SRCS=(\
    "std_test_constr.cpp" \
    "std_test_=.cpp" \
    "std_test_at.cpp" \
    "std_test_[].cpp" \
    "std_test_assign.cpp" \
    "std_test_front_back.cpp" \
    "std_test_ms_s_c.cpp" \
    "std_test_resize.cpp" \
    "std_test_reserve.cpp" \
    "std_test_pb.cpp" \
    "std_test_swap.cpp" \
    "std_test_clear.cpp" \
    "std_test_rel_opr.cpp" \
    "std_test_insert.cpp" \
    "std_test_erase.cpp" \
    )

FT_SRCS=(\
    "ft_test_constr.cpp" \
    "ft_test_=.cpp" \
    "ft_test_at.cpp" \
    "ft_test_[].cpp" \
    "ft_test_assign.cpp" \
    "ft_test_front_back.cpp" \
    "ft_test_ms_s_c.cpp" \
    "ft_test_resize.cpp" \
    "ft_test_reserve.cpp" \
    "ft_test_pb.cpp" \
    "ft_test_swap.cpp" \
    "ft_test_clear.cpp" \
    "ft_test_rel_opr.cpp" \
    "ft_test_insert.cpp" \
    "ft_test_erase.cpp" \
    )

#------------ PROGRAM START HERE ----------------

echo "—————————————————————————"
echo "|     VECTOR TESTER     |"
echo "—————————————————————————"

for (( i = 0; i < how_many; i++));
do
    printf "testing ${TEST_NAME[$i]}...\t"
    ${COMPILE_FLAGS} tester/${FT_SRCS[$i]} ; ./a.out > yours.output
    # leaks -atExit -- ./a.out | grep "total leaked bytes."
    ${COMPILE_FLAGS} tester/${STD_SRCS[$i]} ; ./a.out > std.output
    if cmp -s yours.output std.output; then
        echo "OK"
    else
       echo "KO" ; mv yours.output "${TEST_NAME[$i]}"_yours.output ; mv std.output "${TEST_NAME[$i]}"_std.output
    fi
done
    rm -rf a.out* std.output yours.output
