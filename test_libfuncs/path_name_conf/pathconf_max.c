#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(void)
{
	printf("start\n");
	fflush(fp);
	/* TODO: Investigate the seg fault that occures, likely due to the rb or
	 * the pathname, which is not good since its a library function, but
	 * library functions that are in the default C language really shouldnt
	 * segfault no matter what....
	 */
	//fp = fopen("~/git_repos/linux_script_cmd_things/scripts_progs/smile/smile.py", "rb");
	fp = fopen("./doc.txt", "rb");

	printf("fileno: %d\n", fileno(fp));
	long ret = fpathconf(fileno(fp), _PC_NAME_MAX);
	printf("NAME_MAX: %d\n", ret);
	ret = fpathconf(fileno(fp), _PC_PATH_MAX);
	printf("PATH_MAX: %d\n", ret);

}
