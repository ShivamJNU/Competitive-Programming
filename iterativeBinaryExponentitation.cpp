
int M = 1e9 + 7;
int binaryExpIter(int a, int b)
{
	int ans = 1;

	while (b)
	{
		if (b & 1)
		{
			ans = (ans * 1LL * a) % M;
		}
		a = (a * 1LL * a) % M;
		b = (b >> 1);
	}

	return ans;
}
