void error_handler(char **parsed_input, int errorFlag)
{
	/**
	 * use global var instead of static int num
	 * num should incremeant on every call not just error
	 */
	static int num = 0;
	char *err_msg;
	char str;
	int temp;
	int i = 0;

	num++;
/* handles less than 10 subsequent calls */
	str = num + '0';

/*if (num < 10)
  str[0] = num + '0';
  else
  {
  while (num != 0)
  {
  temp = num % 10;
  str[i++] = temp + '0';
  num = num / 10;
  }
  }
*/
	switch(errorFlag)
	{
	case 1:
		write(1, "sh: ", 4);
		write(1, &str, 1);
		write(1, ": ", 2);
		write(1, parsed_input[0], sizeof(parsed_input[0]));
		write(1, ": not found", 11);
		break;
	}
}
