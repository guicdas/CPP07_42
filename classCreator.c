#include "stdio.h"
#include "io.h"
#include "fcntl.h"
#include "stdlib.h"
#include "string.h"

static void	write_to_file(char *s, int fd)
{
	int i;

	i = write(fd, s, strlen(s));
	if (i < 0)
		printf("%d", errno);
	//printf("i->%d\n", i);
}

static void	write_hpp(int fd, char *name)
{
	write_to_file("#pragma once\n\n#include <iostream>\n\nclass ", fd);
	write_to_file(name, fd);
	write_to_file("{\n\tprivate:\n\n\tpublic:\n\t\t", fd);
	//default
	write_to_file(name, fd);
	write_to_file("( void );\n\t\t", fd);
	//copy
	write_to_file(name, fd);
	write_to_file("( const ", fd);
	write_to_file(name, fd);
	write_to_file(" &", fd);
	write(fd, name, 1);
	write_to_file(" );\n\t\t", fd);
	//=
	write_to_file(name, fd);
	write_to_file("& operator=( const ", fd);
	write_to_file(name, fd);
	write_to_file(" &", fd);
	write(fd, name, 1);
	write_to_file(" );\n\t\t~", fd);
	//destructor
	write_to_file(name, fd);
	write_to_file("( void );\n\n};", fd);
}

void	write_cpp(int fd, char *name, char *include)
{
	write_to_file("#include \"", fd);
	write_to_file(include, fd);
	write_to_file("\"\n\n",fd);
	//default constructor
	write_to_file(name, fd);
	write_to_file("::",fd);
	write_to_file(name, fd);
	write_to_file("( void ){\n\tstd::cout << \"", fd);
	write_to_file(name, fd);
	write_to_file(" created by default!\\n\";\n}\n\n", fd);
	//copy
	write_to_file(name, fd);
	write_to_file("::",fd);
	write_to_file(name, fd);
	write_to_file("( const ",fd);
	write_to_file(name, fd);
	write_to_file(" &", fd);
	write(fd, name, 1);
	write_to_file(" ){\n\tstd::cout << \"", fd);
	write_to_file(name, fd);
	write_to_file(" Copy created!\\n\";\n\t*this = ", fd);
	write(fd, name, 1);	
	write_to_file(";\n}\n\n", fd);
	//=
	write_to_file(name, fd);
	write_to_file("& ",fd);
	write_to_file(name, fd);
	write_to_file("::operator=( const ", fd);
	write_to_file(name, fd);
	write_to_file(" &", fd);
	write(fd, name, 1);
	write_to_file(" ){\n\tstd::cout << \"", fd);
	write_to_file(name, fd);
	write_to_file(" Copy created!\\n\";\n\tif (this != &", fd);
	write(fd, name, 1);
	write_to_file(")\n\n\treturn (*this);\n}\n\n", fd);
	//Destructor
	write_to_file(name, fd);
	write_to_file("::~",fd);
	write_to_file(name, fd);
	write_to_file("( void ){\n\tstd::cout << \"", fd);
	write_to_file(name, fd);
	write_to_file(" destroyed!\\n\";\n}\n\n", fd);
}

static char	*getName(char *s, char option)
{
	char *strReturn = malloc(sizeof(char) * strlen(s) + 5);
	int i = 0;

	while(s[i])
	{
		strReturn[i] = s[i];
		i++;
	}
	strReturn[i++] = '.';
	if (option == 'h')
		strReturn[i++] = 'h';
	else if (option == 'c')
		strReturn[i++] = 'c';
	strReturn[i++] = 'p';
	strReturn[i++] = 'p';
	strReturn[i] = '\0';
	return (strReturn);
}

int	main(int ac, char **argv){
	int fd_hpp, fd_cpp;
	char *n1, *n2;

	if (ac != 2)
	{
		write(2, "Wrong number of arguments!\n", 27);
		exit(1);
	}
	else
	{
		n1 = getName(argv[1], 'h');
		n2 = getName(argv[1], 'c');

		fd_hpp = open(n1, O_RDWR | O_CREAT, 0777);
		fd_cpp = open(n2, O_RDWR | O_CREAT, 0777);
		if (fd_cpp < 0 || fd_hpp <= 0)
			fprintf(stderr, "open() not executed correctly! errno:%d\n", errno);
		else
		{
			write_hpp(fd_hpp, argv[1]);
			write_cpp(fd_cpp, argv[1], n1);

			close(fd_hpp);
			close(fd_cpp);
			free(n1);
			free(n2);
		}
	}
}