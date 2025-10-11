#include <stdio.h>

typedef struct {
    int x, y;
} Point;

// Function to find orientation of triplet (p, q, r)
// Returns >0 for counter-clockwise, <0 for clockwise, 0 for collinear
int orientation(Point p, Point q, Point r) {
    return (q.y - p.y)*(r.x - q.x) - (q.x - p.x)*(r.y - q.y);
}

// Jarvis March to compute convex hull
void jarvisMarch(Point points[], int n) {
    if (n < 3) {
        printf("Convex hull not possible\n");
        return;
    }

    int l = 0;
	int i =0; // leftmost point
    for ( i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;

    int p = l, q;
    printf("Convex Hull points:\n");
    do {
        printf("(%d, %d)\n", points[p].x, points[p].y);
        q = (p + 1) % n;
        for ( i = 0; i < n; i++) {
            if (orientation(points[p], points[i], points[q]) < 0) // choose most counter-clockwise
                q = i;
        }
        p = q;
    } while (p != l); // until we come back to the first point
}

int main() {
    int n;
    int i =0;
    printf("Enter number of points: ");
    scanf("%d", &n);

    Point points[n];
    printf("Enter coordinates (x y) of each point:\n");
    for ( i = 0; i < n; i++)
        scanf("%d %d", &points[i].x, &points[i].y);

    jarvisMarch(points, n);
    return 0;
}

