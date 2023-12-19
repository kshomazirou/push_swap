#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


// void	r_search(int *s_a, int *s_b, int *pos, int count)
// {
// 	int judge;
// 	int judge2;

// 	judge = r_or_s(s_a, count, position[0], standard);
// 	judge2 = r_or_s(stack_b, count, position[1], standard);
// 	if (judge && judge2)
// 	{
// 		rr(s_a, s_b, pos, count);
// 		pos[0] += 1;
// 		pos[1] += 1;
// 	}
// 	else if (s_a[pos[0]] > s_a[count])
// 	{
// 		ra(s_a, count, pos);
// 		pos[0] += 1;
// 	}
// 	else if(s_b[pos[1]] > s_b[count])
// 	{
// 		rb(s_b, count, pos);
// 		pos[1] += 1;
// 	}
// }

// void	rr_search(int *s_a, int *s_b, int *pos, int count)
// {
// 	if (s_a[pos[count]] > s_a[0] && s_b[pos[count]] > s_b[1])//here is chekck
// 	{
// 		rrr(s_a, s_b, pos, count);
// 		*position[0] += 1;
// 		*position[1] += 1;
// 	}
// 	else if (s_a[pos[count]] > s_a[0])
// 	{
// 		rra(s_a, count, pos);
// 		*position[0] += 1;
// 	}
// 	else if(s_b[pos[count]] > s_b[1])
// 	{
// 		rrb(s_b, count, pos);
// 		*position[1] += 1;
// 	}
// }

//sa sb , ra rb , rra , rrb
//sa sb <- a[i] > a[i + 1]
//ra rb <- a[i] > a[max] //chech_r<- ra and rb 
//rra rrb <- a[i] < a[max] //check_rr <- rra and rrb
//基準値を設定するこ

static int	judge(int s, long int n, int now)
{
	if (s == 1 && ((LONG_MAX / 10 < n) || (LONG_MAX - n * 10 - now <= 0)))
		return (1);
	if (s == -1 && ((LONG_MIN / 10 > n) || (LONG_MIN + n * 10 + now >= 0)))
		return (-1);
	return (0);
}

int	ft_atoi(const char *str, int *error)
{
	long int	result;
	int			num;
	int			sign;

	result = 0;
	num = 0;
	sign = 1;
	while ((str[num] >= '\t' && str[num] <= '\r') || str[num] == ' ')
		num++;
	if (str[num] == '-' || str[num] == '+')
	{
		if (str[num] == '-')
			sign = -1;
		num++;
	}
	if (str[num] < '0' || str[num] > '9')
	{
		*error = 1;
		return (0);
	}
	while (str[num] >= '0' && str[num] <= '9')
	{
		if (judge(sign, result, str[num] - '0') == 1)
			return ((int)LONG_MAX);
		if (judge(sign, result, str[num] - '0') == -1)
			return ((int)LONG_MIN);
		result = result * 10 + (str[num] - '0');
		num++;
	}
	return ((int)result * sign);
}

//英文字が含まれていないかの確認
int	judge_only_number(char *c)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	while (c[max])
		max++;
	while (c[i])
	{
		if ((c[i] >= '\t' && c[i] <= '\r') || c[i] == ' ')
			count++;
		if ((c[i] >= '0' && c[i] <= '9') || (c[i] == '+' || c[i] == '-'))
			count++;
		i++;
	}
	if (max == count)
		return (0);
	else
		return (1);
}

//数値化＋文字なし確認
int	atoi_jon(char *argv)
{
	long	num;
	int		error;

	num = 0;
	error = 0;
	num = ft_atoi(argv, &error);
	if (judge_only_number(argv))
		return (1);
	if (num > INT_MAX || num < INT_MIN || error == 1)
		return (2);
	return (0);
}

//数の重複がないかの確認
int	num_duplicate(int *num_col, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = 0;
		while (j < count)
		{
			if (i != j && num_col[i] == num_col[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	sort_checking(int *num_col, int max)
{
	int	count;
	int	i;

	count = 1;
	i = 0;
	while (i < max)
	{
		if (num_col[i] < num_col[i + 1])
			count++;
		i++;
	}
	if (max == count)
		return (1);
	else
		return (0);
}

void	push_b(int *stack_a, int *stack_b, int count)
{
	int	i;

	i = count;
	while (0 < i)
	{
		stack_b[i - 1] = stack_a[count - i];
		write(1,"pb\n",3);
		i--;
	}
}

void	push_a(int *stack_a, int *stack_b, int count)
{
	int	i;

	i = count;
	while (i > 0)
	{
		stack_a[i - 1] = stack_b[count - i];
		stack_b[count - i] = 0;
		write(1,"pa\n",3);
		i--;
	}
}

void	ft_swap(int *element1, int *element2)
{
	int temp;

	temp = *element1;
	*element1 = *element2;
	*element2 = temp;
}

void	ss(int *s_a, int *s_b, int *pos)
{
	ft_swap(&s_a[pos[0]], &s_a[pos[0] + 1]);
	ft_swap(&s_b[pos[1]], &s_b[pos[1] + 1]);
	pos[0] += 1;
	pos[1] += 1;
	write(1, "ss\n", 3);
}

void	sa(int *s_a, int *pos)
{
	ft_swap(&s_a[pos[0]], &s_a[pos[0] + 1]);
	pos[0] += 1;
	write(1, "sa\n", 3);
}

void	sb(int *s_b, int *pos)
{
	ft_swap(&s_b[pos[1]], &s_b[pos[1] + 1]);
	pos[1] += 1;
	write(1, "sb\n", 3);
}

void	s_search(int *s_a, int *s_b, int *pos)
{
	int	a_1;
	int	a_2;
	int	b_1;
	int	b_2;

	a_1 = s_a[pos[0]];
	a_2 = s_a[pos[0] + 1];
	b_1 = s_b[pos[1]];
	b_2 = s_b[pos[1] + 1];
	if (a_1 > a_2 && b_1 > b_2)
		ss(s_a, s_b, pos);
	else if (a_1 > a_2)
		sa(s_a, pos);
	else if (b_1 > b_2)
		sb(s_b, pos);
}

// ra（aを回転させる）： スタックaの全要素を1ずつシフトアップする。最初の要素が最後の要素になる。
//隙間がある箇所も一緒にシフトされてしまう！例)００，１２４→40012



void	ra(int *s_a, int count, int *pos, int sign)
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
	pos[0] += 1;
	if (!sign)
		write(1, "ra\n", 3);
}

void	rb(int *s_b, int count, int *pos, int sign)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = s_b[i];
	while (i < count / 2)
	{
		ft_swap(&s_b[i], &s_b[i + 1]);
		i++;
	}
	ft_swap(&s_b[count/2], &tmp);
	pos[1] += 1;
	if (!sign)
		write(1, "rb\n", 3);
	else
		write(1, "rr\n", 3);
}

void	rr(int *s_a, int *s_b, int *pos, int count)
{
	ra(s_a, count, pos, 1);
	rb(s_b, count, pos, 1);
}
//r_search, rr_search
//a_and_b , only_a
// ・各関数でのテストを行うこと
//rra (reverse rotate a)： スタック a のすべての要素を 1 だけシフトダウンする。最後の要素が最初の要素になる。
void	rra(int *s_a, int count, int *pos, int sign)
{
	int	i;
	int	tmp;

	if (sign)
		i = count / 2;
	else
		i = count;
	tmp = s_a[count - 1];
	while (i > 0)
	{
		ft_swap(&s_a[i], &s_a[i - 1]);
		i--;
	}
	ft_swap(&s_a[0], &tmp);
	pos[0] += 1;
	if (!sign)
		write(1, "rra\n", 4);
}

void	rrb(int *s_b, int count, int *pos, int sign)
{
	int	i;
	int	tmp;

	i = count / 2;
	tmp = s_b[i];
	while (i > 0)
	{
		ft_swap(&s_b[i], &s_b[i - 1]);
		i--;
	}
	ft_swap(&s_b[0], &tmp);
	pos[1] += 1;
	if (!sign)
		write(1, "rrb\n", 4);
	else
		write(1, "rrr\n", 4);
}

void	rrr(int *s_a, int *s_b, int count, int *pos)
{
	rra(s_a, count, pos, 1);
	rrb(s_b, count, pos, 1);
}

int	zero_check(int *stack_b, int count)
{
	int	i;
	int	z_c;

	i = 0;
	z_c = 0;
	while (i < count)
	{
		if (stack_b[i] == 0)
			z_c++;
		i++;
	}
	if (z_c == count - 1)
		return (0);
	else
		return (1);
}

int	r_or_s(int *stack, int count, int position, int standard)
{
	int	i;

	i = 0;
	while (stack[i] != standard)
		i++;
	while (i < count)
	{
		if (stack[position] > stack[i])
			return (1);
		i++;
	}
	return (0);
}

int	rr_or_s(int *stack, int position, int standard)
{
	int	i;

	i = 0;
	while (stack[i] != standard)
	{
		if (stack[position] < stack[i])
			return (1);
		i++;
	}
	return (0);
}

void copy_s(int *stack,int *stack2, int count)
{
	while (count >= 0)
	{
		stack2[count - 1] = stack[count -1];
		count--;
	}
}

void	only_a(int *stack_a, int count, int *position)
{
	int	standard;
	int	*copy;
	int	i;

	i = 0;
	standard = stack_a[count / 2];
	copy = (int *)malloc(count * sizeof(int));
	copy_s(stack_a, copy, count);
	while (i < count / 2)
	{
		if (copy[position[0]] > standard)
		{
			if (r_or_s(copy, count, position[0], standard))
				ra(stack_a, count, position, 0);
			else
				sa(stack_a, position);
		}
		else
			position[0] += 1;
		i++;
	}
	// standard = stack_a[count / 2];
	printf("chenge!!\n");
	while (i < count)
	{
		printf("\n%d:%d\n", copy[position[0]], standard);
		for (int i = 0;i<5;i++)
		printf("%d  ", stack_a[i]);	
		if (copy[position[0]] < standard)
		{
			if (rr_or_s(copy, position[0], standard) && count - position[0]  < 2)
				rra(stack_a, count, position, 0);
			else
				sa(stack_a, position);
		}
		else
			position[0] += 1;
		i++;
	}
	free(copy);
}

void	a_and_b(int *stack_a, int *stack_b, int count, int *position)
{
	int	standard[2];

	standard[0] = stack_a[count / 4 + position[0]];
	standard[1] = stack_b[count / 4];
	while (stack_a[position[0]] != standard[0] || stack_b[position[1]] != standard[1])
		if (stack_a[position[0]] > standard[0] || stack_b[position[1]] > standard[1])
		{
			if (r_or_s(stack_a, count, position[0], standard[0]) && r_or_s(stack_b, count, position[1], standard[1]))
				rr(stack_a, stack_b, position, count);
			else if (r_or_s(stack_a, count, position[0], standard[0]))
				ra(stack_a, count, position, 1);
			else if (r_or_s(stack_b, count, position[1], standard[1]))
				rb(stack_b, count, position, 0);
				s_search(stack_a, stack_b, position);
		}
	while (stack_a[position[0]] != stack_a[count] || stack_b[position[1]] != stack_b[count / 2])
		if (stack_a[position[0]] < standard[0] || stack_b[position[1]] < standard[1])
		{
			if (rr_or_s(stack_a, position[0], standard[0]) && rr_or_s(stack_b, position[1], standard[1]))
				rrr(stack_a, stack_b, count, position);
			else if (rr_or_s(stack_a, position[0], standard[0]))
				rra(stack_a, count, position, 1);
			else if (rr_or_s(stack_b, position[1], standard[1]))
				rrb(stack_b, count, position, 0);
			s_search(stack_a, stack_b, position);
		}
}
// void	rrr(int *s_a, int *s_b, int count, int *pos)

void	sorting(int *stack_a, int *stack_b, int count, int *position)
{
	if (zero_check(stack_b, count) && sort_checking(stack_b, count))
	{
		push_a(stack_a, stack_b, count / 2);
		position[0] = 0;
		position[1] = 0;
		if (!sort_checking(stack_a, count) && count > 6)
		{
			position[0] = count / 2;
			push_b(stack_a, stack_b, count / 2);
		}
	}
	if (zero_check(stack_b, count) == 0)
		only_a(stack_a, count, position);
	else
		a_and_b(stack_a, stack_b, count, position);
	if (sort_checking(stack_a, count) && !zero_check(stack_b, count))
		return (free(stack_b));
	else
		sorting(stack_a, stack_b, count, position);
}

void	quick_sorting(int *stack_a, int count)
{
	int	*stack_b;
	int	position[2];

	stack_b = (int *)malloc((count) * sizeof(int));
	if (stack_b == NULL)
	{
		free(stack_a);
		write(1, "Error\n", 6);
		return ;
	}
	if (sort_checking(stack_a, count))
		return ;
	if (count > 6)
	{
		position[0] = count / 2;
		push_b(stack_a, stack_b, count / 2);
	}
	sorting(stack_a, stack_b, count, position);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	error;
	int	*num_col;

	error = 0;
	i = 1;
	while (i < argc)
		if (atoi_jon(argv[i++]))
			return (write(1, "Error\n", 6), 2);
	num_col = (int *)malloc((argc - 1) * sizeof(int));
	if (num_col == NULL)
		return (write(1, "Error\n", 6), 2);
	i = 0;
	while (i < argc - 1)
	{
		num_col[i] = ft_atoi(argv[i + 1], &error);
		if (error)
			return (free(num_col), 2);
		i++;
	}
	if (num_duplicate(num_col, argc - 1) == 0)
		quick_sorting(num_col, argc - 1);
	else
		write(1, "Error\n", 6);
	free(num_col);
	return (0);
}
