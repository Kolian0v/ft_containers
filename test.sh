cp StackTest.cpp ./main_std.cpp
sed -i '' 's/ft::stack/std::stack/g' main_std.cpp
clang++ main_std.cpp -Wall -Wextra -Werror -std=c++98 -o std_stack
echo "***************************************************"
echo "* * * * * * * S T L * * S T A C K * * * * * * * * *"
time ./std_stack > std_output
clang++ StackTest.cpp -Wall -Wextra -Werror -std=c++98 -o ft_stack
echo "***************************************************"
echo "* * * * * * * * M Y * * S T A C K * * * * * * * * *"
time ./ft_stack > ft_output
echo "diff: "
diff std_output ft_output
rm -rf main_std.cpp ft_output std_output ft_stack std_stack

cp VectorTest.cpp ./main_std.cpp
sed -i '' 's/ft::vector/std::vector/g' main_std.cpp
clang++ main_std.cpp -Wall -Wextra -Werror -std=c++98 -o std_vector
echo "***************************************************"
echo "* * * * * * * * S T L * * V E C T O R * * * * * * *"
time ./std_vector > std_output
clang++ VectorTest.cpp -Wall -Wextra -Werror -std=c++98 -o ft_vector
echo "***************************************************"
echo "* * * * * * * * M Y * * V E C T O R * * * * * * * *"
time ./ft_vector > ft_output
echo "diff: "
diff std_output ft_output
rm -rf main_std.cpp ft_output std_output std_vector ft_vector

cp MapTest.cpp ./main_std.cpp
sed -i '' 's/ft::map/std::map/g' main_std.cpp
sed -i '' 's/ft::pair/std::pair/g' main_std.cpp
sed -i '' 's/ft::make_pair/std::make_pair/g' main_std.cpp
clang++ main_std.cpp -Wall -Wextra -Werror -std=c++98 -o std_map
echo "***************************************************"
echo "* * * * * * * S T L * * M A P * * * * * * * * * * *"
time ./std_map > std_output
clang++ MapTest.cpp -Wall -Wextra -Werror -std=c++98 -o ft_map
echo "***************************************************"
echo "* * * * * * * * M Y * * M A P * * * * * * * * * * *"
time ./ft_map > ft_output
echo "diff: "
diff std_output ft_output
rm -rf main_std.cpp ft_output std_output std_map ft_map

