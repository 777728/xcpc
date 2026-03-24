#include <cstdio>
using namespace std;
#define lu dfs(x1, y1, x1+len-1, y1+len-1, x1+len-1, y1+len-1, len);
#define ru dfs(x1+len, y1, x2, y1+len-1, x1+len, y1+len-1, len);
#define ld dfs(x1, y1+len, x1+len-1, y2, x1+len-1, y1+len, len);
#define rd dfs(x1+len, y1+len, x2, y2, x1+len, y1+len, len);

void dfs(int x1, int y1, int x2, int y2, int x0, int y0, int len)
//x1.y1表示当前方格的左上角，x2,y2表示当前方格右下角，x0.y0表示特殊点，len表示方格边长
{
	if(x2-x1 == 1 && y2-y1 == 1) {//当方格长度为2时，不再分治，返回
		if(x1 == x0 && y1 == y0) {
			printf("%d %d 1\n", y2, x2);
		}
		else if(x2 == x0 && y1 == y0) {
			printf("%d %d 2\n", y2, x1);
		}
		else if(x1 == x0 && y2 == y0) {
			printf("%d %d 3\n", y1, x2);
		}
		else if(x2 == x0 && y2 == y0) {
			printf("%d %d 4\n", y1 , x1);
		}
		return;
	}
	len >>= 1;//边长减半
	if(x0 < x1+len && y0 < y1+len) {//解决左上角方格
		printf("%d %d 1\n", y1+len, x1+len);
		dfs(x1, y1, x1+len-1, y1+len-1, x0, y0, len);
		ru
		ld
		rd
	}
	if(x0 >= x1+len && y0 < y1+len) {//右上角
		printf("%d %d 2\n", y1+len, x1+len-1);
		lu
		dfs(x1+len, y1, x2, y1+len-1, x0, y0, len);
		ld
		rd
	}
	if(x0 < x1+len && y0 >= y1+len) {//左下角
		printf("%d %d 3\n", y1+len-1, x1+len);
		lu
		ru
		dfs(x1, y1+len, x1+len-1, y2, x0, y0, len);
		rd
	}
	if(x0 >= x1+len && y0 >= y1+len) {//右下角
		printf("%d %d 4\n", y1+len-1, x1+len-1);
		lu
		ru
		ld
		dfs(x1+len, y1+len, x2, y2, x0, y0, len);
	}
}

int main(void)
{
	int k, x, y;
	scanf("%d%d%d", &k, &y, &x);
	dfs(1, 1, 1 << k, 1 << k, x, y, 1 << k);
	return 0;
}
