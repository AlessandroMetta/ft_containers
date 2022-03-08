#------------ VARIABLES ----------------
TEXT_COLOR_RED="\033[1;31m"
TEXT_COLOR_GREEN="\033[1;32m"
TEXT_COLOR_DEFAULT="\033[0m"
COMPILE_FLAGS="clang++ -Wall -Wextra -Werror -std=c++98 -pedantic"

TEST_NAME=(\
    # "constructors" \
    "= operator" \
    "at" \
    "[] operator" \
    # "assign" \
    "front/back" \
    "size, max_size and capacity" \
    "resize" \
    "reserve" \
    "push_back/pop_back" \
    "swap" \
    "clear" \
    )

how_many=${#TEST_NAME[@]}

STD_SRCS=(\
    # "std_test_constr.cpp" \
    "std_test_=.cpp" \
    "std_test_at.cpp" \
    "std_test_[].cpp" \
    # "std_test_assign.cpp" \
    "std_test_front_back.cpp" \
    "std_test_ms_s_c.cpp" \
    "std_test_resize.cpp" \
    "std_test_reserve.cpp" \
    "std_test_pb.cpp" \
    "std_test_swap.cpp" \
    "std_test_clear.cpp" \
    )

FT_SRCS=(\
    # "ft_test_constr.cpp" \
    "ft_test_=.cpp" \
    "ft_test_at.cpp" \
    "ft_test_[].cpp" \
    # "ft_test_assign.cpp" \
    "ft_test_front_back.cpp" \
    "ft_test_ms_s_c.cpp" \
    "ft_test_resize.cpp" \
    "ft_test_reserve.cpp" \
    "ft_test_pb.cpp" \
    "ft_test_swap.cpp" \
    "ft_test_clear.cpp" \
    )

#------------ PROGRAM START HERE ----------------

echo "-------------------------"
echo "|     VECTOR TESTER     |"
echo "-------------------------"

for (( i = 0; i < how_many; i++));
do
    printf "testing ${TEST_NAME[$i]}...\t"
    ${COMPILE_FLAGS} ${FT_SRCS[$i]} ; ./a.out > yours.o
    # leaks -atExit -- ./a.out | grep "total leaked bytes."
    ${COMPILE_FLAGS} ${STD_SRCS[$i]} ; ./a.out > std.o
    if cmp -s yours.o std.o; then
        echo "${TEXT_COLOR_GREEN}OK${TEXT_COLOR_DEFAULT}"
    else
       echo "${TEXT_COLOR_RED}KO${TEXT_COLOR_DEFAULT}"
    fi
done

rm a.out std.o yours.o