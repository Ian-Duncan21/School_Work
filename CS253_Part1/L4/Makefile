# This is a Makefile.  Its purpose is to create the program “small”.
#
# The rules, below, indicate what depends on what, and how to build
# things when they get out-of-date.  It is VERY important to know that
# what looks like eight leading spaces is really a leading tab
# character.  Leading spaces won’t work--it MUST be a tab character.
#
# For the following questions, do the command if there is one,
# and then answer the question.  If you need another line for you
# answer, continue it on the next line, indented.
#
# As an example, I’ve already answered (1), which has nothing to do
# with anything else in this lab.
#
# Question 1 is worth 0.09 points; questions 2–14 are worth 0.07
# points each.
#
#  1) Command:  date +%A
#     Question: Describe the output of that command.
#     Answer:   It’s today’s day of the week.
#
#  2) Command:  make
#     Question: Describe what happens.  Don’t just write the commands;
#     		describe what each command does.
#     Answer:   small creates an executable program called small out of the foo object file and main object file. Created with file names followed by -o.  
#		main.o is created with the foo header file and main.cc file and foo.o is created with the foo header file and foo.cc file by stringing them together with -c. 
#		Clean gets rid of the executable and object files. 
#		
#
#  3) Command:  ./small
#     Question: What is the output?  Reproduce the output exactly.
#     Answer:   Hi from main at main.cc:15
#		Hi from foo at foo.cc:14
#
#
#  4) Command:  make
#     Question: Why did nothing much happen?
#     Answer:   Because the compilation is up to date. Nothing has been changed since last compilation: "make: 'small' is up to date."

#
#  5) Command:  rm small; make
#     Question: What got remade, and why?
#     Answer:   small was remade because it was the only one in need of being remade. The others are already up to date and small was missing during compilation. 
#
#  6) Command:  rm foo.o; make
#     Question: What got remade, and why?
#     Answer:   foo.cc was remade because foo.o relies on foo.cc to be compiled in order for it to be compiled. It also remade small because small relies on foo.o and if foo.o must be remade small must also be remade or it won't be up to date. 
#
#  7) Command:  make clean
#     Question: What did that do?
#     Answer:   Removed the object files and executable (small). 
#
#  8) Command:  make
#     Question: What got remade, and why?
#     Answer:   Everything was remade because there were no object files for the compiler to read from and computers need object files in order to create an executable. 
#
#  9) Question: Why does main.o depend on foo.h?
#		I know that it’s because the Makefile says so.
#		Why was that dependency put into the Makefile?
#     Answer:   main calls foo and foo is defined in its header file foo.h. In order for main to have access to foo it must rely on its header file for that declaration. 
#
# 10) Command:  Create a new function bar() in bar.cc & bar.h,
# 		similar to foo.cc.  Change main.cc to call the new
# 		bar() function, make sure to #include the proper .h
# 		files everywhere, and type “make”.  Don’t alter Makefile.
#     Question: Why did it fail?
#     Answer:   There was an undefined reference to bar because bar is not in the Makefile.
#
# 11) Command:  Fix the Makefile; verify with “make” until it compiles.
#     Question: Describe your changes.  Don’t just show the changed
#     		lines--describe the purpose of each change.
#     Answer:   main.cc makes a reference to bar.cc so I changed the main.o in make to rely on bar.h as well so it was bars declarations. The executable small must also now rely on bar.o so I added that to the compilation for small. 
#		I also added the compilation for bar.o so that the computer has a bar object to read from in the first place. 
# 
# 12) Command:  Uncomment the CXXFLAGS= line, and type “make”.
#     Question: Why didn't anything happen?
#     Answer:   Because make is up to date and cannot remake until it has been changed.
#
# 13) Command:  Force a rebuild with: make clean; make
#     Question: What’s new about the commands executed?
#     Answer:   they are all run on every file within the makefile and present a lot longer of a compilation with more error checking. 
#
# 14) Command: 	make clean; ls -l clean
#     Question: The target is “clean”, but no file “clean” got created.
#     		Why not?
#     Answer:   Because we defined clean to only remove files. 
#
# For extra fame & glory (but no extra points):
#
# 15) Command:  Consult the make manual at
# 		https://www.gnu.org/software/make/manual/make.html
#		and improve this Makefile by using $@ in the rule
#		that creates “small” itself.

# The CXX variable contains the name of the C++ compiler.  You can’t
# have plus signs in a Make variable, so X is a rotated plus sign.
CXX=g++

CXXFLAGS=-std=c++17 -Wall -Wextra -Wpedantic -Werror -Wfatal-errors -Winit-self -Wshadow -Wlogical-op -Wcomment -Wctor-dtor-privacy -Wold-style-cast -D_GLIBCXX_DEBUG -fno-diagnostics-show-option

small: main.o foo.o bar.o
	$(CXX) $(CXXFLAGS) main.o foo.o bar.o -o small

main.o: main.cc foo.h bar.h
	$(CXX) $(CXXFLAGS) -c main.cc

foo.o: foo.cc foo.h 
	$(CXX) $(CXXFLAGS) -c foo.cc
	
bar.o: bar.cc bar.h 
	$(CXX) $(CXXFLAGS) -c bar.cc
	
clean:
	-rm -f small *.o
