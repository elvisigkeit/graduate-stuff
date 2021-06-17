int foo(int a, int b, int *p)
{
	if (a==(*p) || a==b)
		return 0;
	else
		if (a<b && a>(*p))
			return ((a-b)-(a-(*p)));
	return ((b-a)*((*p)-a));
}
