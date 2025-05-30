/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:38:23 by hyeonukim         #+#    #+#             */
/*   Updated: 2025/05/25 18:53:33 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

/*

process flow

1. check arguments
1-1. is the number of arguments correct?
1-2. do infile and outfile exist?

2. read from infile

3. make it stdin and run command 1

4. output of 3 should be input of command 2

5. run command 2 and save the stdout to outfile


required functions
1. arguments checking -> can be done in the main function

2. memory cleaning -> when a functions fails

3. actual piping function
.
4. parsing functions

*/


int	main(int argc, char **argv, )
{
	/*check the access of the input file*/
	int		fds[2];
	pid_t	pid;

	if (argc != 5)
	{
		//exit
	}
	if (pipe(fds) == -1)
	{
		//exit 
	}
	pid = fork();
	if (pid == -1)
	{
		//exit
	}
	
		

}

int child_read(int fd, char *path)
{
	
}