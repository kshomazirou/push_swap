#include <unistd.h>
#include <stdio.h>


void	ft_swap(int *element1, int *element2)
{
	int	temp;

	temp = *element1;
	*element1 = *element2;
	*element2 = temp;
}

void	rra(int *s_a, int count, int sign)
{
	int	i;
	int	tmp;

	if (sign)
		i = count / 2;//here is check
	else
		i = count - 1;
	tmp = s_a[count - 1];
	while (i >= 0)
	{
		ft_swap(&s_a[i], &s_a[i - 1]);
		i--;
	}
	ft_swap(&s_a[0], &tmp);
	if (!sign)
		write(1, "rra\n", 4);
}

int main(void)
{
	int stack_a[5] = {1,2,3,4,5};
	int count = 5;
	int standard = 3;
	while (stack_a[count / 2] == standard)
	{
		printf("%d", stack_a[count / 2]);
		rra(stack_a, count, 0);
	}
}