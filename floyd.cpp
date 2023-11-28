#include <stdio.h>
#include <limits.h>
#define V 4

void floydWarshall(int graph[V][V]) {
    int dist[V][V];
    int next[V][V];

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
            if (i == j) {
                next[i][j] = -1; // Không có đỉnh tiếp theo nếu là chính nó
            } else if (graph[i][j] != INT_MAX) {
                next[i][j] = j; // Đỉnh tiếp theo là j nếu có kết nối từ i đến j
            } else {
                next[i][j] = -1; // Không có đỉnh tiếp theo nếu không có kết nối từ i đến j
            }
        }
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) {
                    continue; // Tránh tràn số nếu có cạnh âm
                }

                int altDist = dist[i][k] + dist[k][j];
                if (altDist < dist[i][j]) {
                    dist[i][j] = altDist;
                    next[i][j] = next[i][k];
                }
            }
        }
    }

    // In ra ma trận khoảng cách và ma trận lưu trữ đỉnh tiếp theo nếu có
    printf("Ma tran khoang cach ngan nhat:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX) {
                printf("INF\t");
            } else {
                printf("%d\t", dist[i][j]);
            }
        }
        printf("\n");
    }

    printf("\nMa tran luu tru dinh tiep theo neu co:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (next[i][j] == -1) {
                printf("N/A\t");
            } else {
                printf("%d\t", next[i][j] + 1); // +1 vì đề bài đánh số đỉnh từ 1
            }
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V] = {
        {0, 9, 4, 1},
        {3, 0, INT_MAX, INT_MAX},
        {INT_MAX, 4, 0, INT_MAX},
        {2, INT_MAX, 2, 0}
    };

    floydWarshall(graph);

    return 0;
}

/*Lưu ý: Mã chuyển đổi này sử dụng INT_MAX để đại diện cho vô cùng (Infinity),
vì vậy bạn cần bao gồm thư viện #include <limits.h> để sử dụng INT_MAX.
Ngoài ra, trong đồ thị có hướng, ma trận lưu trữ đỉnh tiếp theo thường được sử dụng
để xác định đường đi ngắn nhất giữa các đỉnh.*/
