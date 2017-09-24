#include <stdio.h>
#include <string.h>

// Sample Input:
// 3
// CS301111 15:30:28 17:00:10
// SC3021234 08:00:00 11:25:25
// CS301133 21:45:00 21:58:40
// Sample Output:
// SC3021234 CS301133

int main(int argc, char const *argv[])
{
	int m;
	char id[16], in_id[16], out_id[16];
	char in_time[9], out_time[9];
	char min_time[9] = "99:99:99";
	char max_time[9] = "00:00:00";

	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		scanf("%s%s%s", id, in_time, out_time);
		if (strcmp(in_time, min_time) < 0) {
			strcpy(min_time, in_time);
			strcpy(in_id, id);
		}
		if (strcmp(out_time, max_time) > 0) {
			strcpy(max_time, out_time);
			strcpy(out_id, id);
		}
	}
	printf("%s %s", in_id, out_id);
	return 0;
}
