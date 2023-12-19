#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_swap(int *element1, int *element2)
{
	int	temp;

	temp = *element1;
	*element1 = *element2;
	*element2 = temp;
}

void	sa(int *s_a)
{
	ft_swap(&s_a[0], &s_a[1]);
	write(1, "sa\n", 3);
}

void	ra(int *s_a, int count, int sign)
{
	int	i;
	int	tmp;

	if (sign)
		i = count / 2;
	else
		i = 0;
	tmp = s_a[i];
	while (i < count - 1)
	{
		ft_swap(&s_a[i], &s_a[i + 1]);
		i++;
	}
	ft_swap(&s_a[count - 1], &tmp);
	if (!sign)
		write(1, "ra\n", 3);
}
//	int stack_[5] = {4, 2 ,3, 1 ,5};

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

void copy_s(int *stack, int *stack2, int count)
{
	while (count >= 0)
	{
		stack2[count - 1] = stack[count -1];
		count--;
	}
}

int	rr_or_s(int *stack, int count, int standard)
{
	int	i;

	i = 0;
	while (stack[i] != standard)
		i++;
	while (i < count)
	{
		if ((stack[count / 2] < stack[i]))
			return (1);
		i++;
	}
	// if ((stack[count - 1] < standard && stack[0] < standard))
	// 	return (1);
	// else
	return (0);
}

int	r_or_s(int *stack, int count, int standard)
{
	// if (stack[0] > standard)
	// 	return (1);
	// else
	// 	return (0);
	int	i;

	i = 0;

	while (stack[i] != standard)
	{
		if (stack[count / 2] < stack[i])
			return (1);
		i++;
	}
	return (0);
}

void	only_a(int *stack_a, int count)
{
	int	standard;
	int	i;
	int	*copy;

	i = 0;
	standard = 3;
	//here is check	
		if (stack_a[0] > stack_a[1])
			sa(stack_a);
		else if (rr_or_s(stack_a, count, standard))
			rra(stack_a, count, 0);
		else if (r_or_s(stack_a, count, standard))
			ra(stack_a, count, 0);
		else
			ra(stack_a, count, 0);
}

//pa, pbに分けて考える。<- a_and_b
//count/2をbにPUSH<- a_and_b
//sa,sb,ssが可能か？
//できないなら、真ん中の値から、ra,rraを行うかを選択
//真ん中から左側の捜索　ra
//真ん中から右側の捜索　rra
//基準値が移動したら、基準変更
int	sort_checking(int *num_col, int max)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < max - 1)
	{
		if (num_col[i] < num_col[i + 1])
			count++;
		i++;
	}
	if (max - 1 == count)
		return (1);
	else
		return (0);
}

int main(void)
{
//5,1,2,4,3
//4,5,3,2,1
//3,2,5,4,1
//2,4,3,5,1
//4,5,1,3,2
//2,1,4,3,5

	int stack_a[5] = {3,4,2,1,5};
	int count = 5;
	int position[2] = {0,0};
	// while (sort_checking(stack_a, count) == 0)//3,2,5,4,1
	// {only_a(stack_a, count);
	// }
	only_a(stack_a, count);
	only_a(stack_a, count);
	only_a(stack_a, count);
	only_a(stack_a, count);
	only_a(stack_a, count);
	only_a(stack_a, count);
	only_a(stack_a, count);
	only_a(stack_a, count);
	only_a(stack_a, count);
	only_a(stack_a, count);
	// only_a(stack_a, count);
	// only_a(stack_a, count);
	// only_a(stack_a, count);
	// only_a(stack_a, count);
	// only_a(stack_a, count);
	// only_a(stack_a, count);
	// only_a(stack_a, count);
	// only_a(stack_a, count);
	// only_a(stack_a, count);
	// only_a(stack_a, count);
	// only_a(stack_a, count);
	// only_a(stack_a, count);


		for (int i = 0;i< 5;i++)
		printf("%d  ", stack_a[i]);	
}
// 2 4 3 5 1


//4, 2 ,3, 1 ,5
//2 3 1 5 4
//3
// 2 4 3 
//3 4 2 
//4 3 2 
//3 4 2 
//
//2 4 3 1 
//4 3 1 2 
//3 4 1 2 
//4 1 2 3 
//