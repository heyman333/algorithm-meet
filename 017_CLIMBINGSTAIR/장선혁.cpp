#include<stdio.h>
#include<algorithm>

int main()
{
	int stair[301] = { 0 };
	int cache[301] = { 0 };
	int N;

	scanf("%d", &N);

	for (int i = 1; i <= N;i++)
		scanf("%d", &stair[i]);
	
	cache[0] = 0;
	cache[1] = stair[1];
	cache[2] = cache[1] + stair[2];
	
	for (int i = 3; i <= N; i++)
		cache[i] = std::max(cache[i - 2] + stair[i], cache[i - 3] + stair[i - 1] + stair[i]);

	printf("%d\n", cache[N]);

	return 0;
}
