CC = g++
STD := -std=c++17 -g
CFLAGS := -Wall -Werror -Wextra
LIBS := -lgtest
REPORTDIR := report
GCOV := --coverage 

all: test leaks

############################## -> LIBRARY <- ############################
s21_matrix_oop.a:
	$(CC) $(STD) -c s21_matrix_oop.cpp -o s21_matrix_oop.o
	ar rcs s21_matrix_oop.a s21_matrix_oop.o


############################## -> TESTS <- ##############################
test: 
	$(CC) $(CFLAGS) $(STD) $(GCOV) -c s21_matrix_oop.cpp $(LIBS)
	$(CC) $(CFLAGS) $(STD) -c s21_matrix_test.cpp $(LIBS)
	$(CC) $(CFLAGS) $(STD) $(GCOV) -o s21_matrix_test s21_matrix_test.o s21_matrix_oop.o $(LIBS)
	./s21_matrix_test


############################## -> LEAKS <- ##############################
leaks: test
	leaks -atExit -- ./s21_matrix_test


############################## -> REPORT <- ##############################
gcov_report:
	lcov -t "Unit-tests of s21_matrix_oop" -o s21_matrix_oop.info -c -d .
	genhtml -o $(REPORTDIR) s21_matrix_oop.info
	open -a "Google Chrome" $(REPORTDIR)/index.html


##############################  -> CHECK <- ##############################
check:
	@cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	@python3 ../materials/linters/cpplint.py --extension=cpp *.cpp
	@cppcheck *.cpp
	@python3 ../materials/linters/cpplint.py --extension=h *.h
	@rm -rf CPPLINT.cfg


##############################  -> CLEAN <- ##############################
clean:
	@rm -f *.o *.a *.gcno *.gcda *.info *.out 
	@rm -rf ./report
	@rm s21_matrix_test
